/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_enrty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 05:41:30 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/25 05:41:34 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		is_a_champ(char *str, t_core *c)
{
	int i;

	i = 0;
	while (str[i] || str[i] != '.')
		i++;
	if (str[i] == '\0')
		return (1);
	if (!ft_strequ(str + i, ".cor"))
		return (1);
	return (0);
}

void	stock_name(char **str, t_core *c)
{
	int i;

	i = 0;
	if (!(c->player->name = (char *)malloc(sizeof(char) * PROG_NAME_LENGTH + 1)))
		ft_exit("Malloc error");
	while (i < PROG_NAME_LENGTH)
	{
		c->player->name[i] = **str;
		(*str)++;
		i++;
	}
	c->player->name[i] = '\0';
	str++;
}

void	stock_comment(char **str, t_core *c)
{
	int i;

	i = 0;
	if (!(c->player->comment = (char *)malloc(sizeof(char) * COMMENT_LENGTH + 1)))
		ft_exit("Malloc error");
	while (i < COMMENT_LENGTH)
	{
		c->player->comment[i] = **str;
		(*str)++;
		i++;
	}
	c->player->comment[i] = '\0';
	str++;
}

void	stock_prog(char **str, t_core *c)
{
	int i;

	i = 0;
	if (!(c->player->prog = (char *)malloc(sizeof(char) * ft_strlen(*str) + 1)))
		ft_exit("Malloc error");

	while (i < ft_strlen(*str))
	{
		c->player->prog[i] = **str;
		(*str)++;
		i++;
	}
	c->player->prog[i] = '\0';
	str++;
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
	int ret;
	char *line;

	if ((fd = open(str, O_WRONLY)) < 0)
		ft_exit("Can't read source file");
	get_next_line(fd, &line);
	str += 4;
	stock_name(&line, c);
	chatoli(&line);
	str += 8;
	stock_comment(&line, c);
	stock_prog(&line, c);
}

t_core	*parcing(int argc, char **argv, t_core *c)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-dump"))
		{

		}
		else if (ft_strequ(argv[i], "-n"))
		{

		}
		else if (ft_strequ(argv[i], "-v"))
			c->run = 0;
		else if (is_a_champ(argv[i], c) == 0)
		{
			get_the_champ(argv[i], c);
			c->nb_player += 1;
		}
		else
			error_executable();
		i++;
	}
	if (c->nb_player > 4)
		ft_error("Too many players!");
	return (c);
}
