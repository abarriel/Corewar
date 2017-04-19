/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_entry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <lcharvol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 05:41:30 by lcharvol          #+#    #+#             */
/*   Updated: 2017/04/17 18:54:21 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_player	*get_the_prog(int fd, t_player *new)
{
	unsigned char buff[new->weight];

	if (((size_t)read(fd, &buff, new->weight) < new->weight))
		ft_exit("Can't read source file");
	new->prog = (unsigned char *)malloc(sizeof(unsigned char) * new->weight);
	ft_memcpy(new->prog, buff, new->weight + 1);
	return (new);
}

void		get_the_champ(char *str, t_core *c)
{
	int			fd;
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
	new = get_the_prog(fd, new);
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

int			ft_get_flag(t_core *c, int argc, char **argv, int i)
{
	if (ft_strequ(argv[i], "-f"))
		c->visu = 1;
	else if (ft_strequ(argv[i], "-n"))
	{
		if (argc <= i + 1)
			print_usage();
		if (ft_sdigit(argv[i + 1]) == 1)
			ft_exit("Flag error");
		c->tmp_id = ft_atoi(argv[i + 1]);
		return (i + 1);
	}
	else if (ft_strequ(argv[i], "-dump"))
	{
		if (argc <= i + 1)
			print_usage();
		if (ft_sdigit(argv[i + 1]) == 1)
			ft_exit("Flag error");
		c->dump = ft_atoi(argv[i + 1]);
		return (i + 1);
	}
	else if (ft_strequ(argv[i], "-debug"))
		c->debug = 1;
	else
		ft_exit("Cannot find the flag");
	return (i);
}

t_core		*parcing(int argc, char **argv, t_core *c)
{
	int i;

	i = 0;
	if (argc <= 1)
		print_usage();
	while (++i < argc)
	{
		if (argv[i][0] == '-')
			i = ft_get_flag(c, argc, argv, i);
		else if (is_a_champ(argv[i]) == 0)
		{
			get_the_champ(argv[i], c);
			c->nb_player += 1;
		}
		else
			error_executable();
	}
	if (c->nb_player == 0)
		print_usage();
	if (c->nb_player > 4)
		ft_exit("Too many players!");
	return (c);
}
