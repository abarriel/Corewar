/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_entry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <lcharvol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 05:41:30 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/25 09:23:00 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		is_a_champ(char *str, t_core *c)
{
	if ((ft_strrncmp(str, "roc.", 4)) || ft_strlen(str) == 4)
		return (1);
	return (0);
}

unsigned long int		chatoli(char **str)
{
	unsigned long int final;

	final = 0;
	final |= ((unsigned long)(*str)[0] << 56);
	final |= ((unsigned long)(*str)[1] << 48);
	final |= ((unsigned long)(*str)[2] <<  40);
	final |= ((unsigned long)(*str)[3] << 32);
	final |= ((unsigned long)(*str)[4] << 24 );
	final |= ((unsigned long)(*str)[5] << 16 );
	final |= ((unsigned long)(*str)[6] <<  8 );
	final |= ((unsigned long)(*str)[7]);
	return (final);
}

size_t	ft_endian(size_t n)
{
	size_t	r;

	r = 0;
	r += ((n & 0xff000000) / 0x1000000);
	r += ((n & 0xff0000) / 0x100);
	r += ((n & 0xff00) * 0x100);
	r += ((n & 0xff) * 0x10000);
	return (r);
}

t_player	*get_the_prog(int fd, char *str, t_core *c, t_player *new)
{
	unsigned char buff[new->weight];

	if ((read(fd, &buff, new->weight) < new->weight))
		ft_exit("Can't read source file");
	new->prog = (unsigned char *)malloc(sizeof(unsigned char) * new->weight);
	ft_memcpy(new->prog, buff, new->weight + 1);
	return (new);
}

void	get_the_champ(char *str, t_core *c)
{
	int fd;
	t_header	header;
	t_player	*new;

	if (!(new = (t_player *)malloc(sizeof(t_player))))
		ft_exit("Malloc Error");
	init_player(new, c);
	if ((fd = open(str, O_RDONLY)) < 0)
		ft_exit("Can't open source file");
	if ((read(fd, &header, sizeof(t_header)) < (long)sizeof(t_header)))
		ft_exit("Can't read source file");
	new->magic = ft_endian(header.magic);
	ft_memcpy(new->name, header.prog_name, PROG_NAME_LENGTH + 1);
	new->weight = ft_endian(header.prog_size);
	if (new->weight > CHAMP_MAX_SIZE)
		ft_exit("Wrong prog size");
	ft_memcpy(new->comment, header.comment, COMMENT_LENGTH + 1);
	new = get_the_prog(fd, str, c, new);
	if (c->player == NULL)
	{
		c->player = new;
		c->player->next = NULL;
		return ;
	}
	new->next = c->player;
	c->player = new;
	close(fd);
}

void	print_usage(void)
{
	ft_printf("Usage: ./corewar [-dump N -n N -v] <champion1.cor> <...>\n\n");
	ft_printf("    -dump nbr_cycles : Au bout de nbr_cycles cycles ");
	ft_printf("d’exécution, dump la mémoire sur la sortie standard,");
	ft_printf(" puis quitte la partie.\n");
	ft_printf("    -n numer         : Fixe le numéro du prochain joueur.\n");
	ft_printf("    -v               : interface graphique mlx\n");
	exit(0);
}

int	ft_get_flag(t_core *c, char **argv, int i)
{
	if (ft_strequ(argv[i], "-f"))
		c->visu = 1;
	else if (ft_strequ(argv[i], "-n"))
	{
		if (ft_sdigit(argv[i + 1]) == 1)
			ft_exit("Flag error");
		c->tmp_id = ft_atoi(argv[i + 1]);
		return (i + 1);
	}
	else
		ft_exit("Cannot find the flag");
	return (i);
}

t_core	*parcing(int argc, char **argv, t_core *c)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-')
			i = ft_get_flag(c, argv, i);
		else if (is_a_champ(argv[i], c) == 0)
		{
			get_the_champ(argv[i], c);
			c->nb_player += 1;
		}
		else
			error_executable();
	}
	if (c->nb_player > 4)
		ft_exit("Too many players!");
	return (c);
}
