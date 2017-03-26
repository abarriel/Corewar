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

void	get_the_champ(char *str, t_core *c)
{
	int fd;
	t_header	header;
	t_player	*new;

	new = (t_player *)malloc(sizeof(t_player));
	init_player(new);
	new->next = NULL;
	if ((fd = open(str, O_RDONLY)) < 0)
		ft_exit("Can't open source file");
	if ((read(fd, &header, sizeof(t_header)) < (long)sizeof(t_header)))
		ft_exit("Can't read source file");
	new->magic = header.magic;
	new->name = ft_strnew(PROG_NAME_LENGTH + 1);
	ft_memcpy(new->name, header.prog_name, PROG_NAME_LENGTH + 1);
	new->weight = header.prog_size;
	new->comment = ft_strnew(COMMENT_LENGTH + 1);
	ft_memcpy(new->comment, header.comment, COMMENT_LENGTH + 1);
	close(fd);
	if (c->player == NULL)
	{
		c->player = new;
		c->player->next = NULL;
		return ;
	}
	new->next = c->player;
	c->player = new;
}

void	ft_get_flag(t_core *c, char *str)
{
	if (ft_strequ(str, "-f"))
		c->visu = 1;
	else
		ft_exit("Cannot find the flag");
}

t_core	*parcing(int argc, char **argv, t_core *c)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-')
			ft_get_flag(c, argv[i]);
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
