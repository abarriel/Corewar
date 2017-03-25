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

int		is_a_champ(char *str)
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

void	stock_name(char **str)
{
	int i;

	i = 0;
	if (!(c->name = (char *)malloc(sizeof(char) * PROG_NAME_LENGTH + 1)))
		ft_exit("Malloc error");
	while (i < PROG_NAME_LENGTH)
	{
		c->name[i] == **str;
		(*str)++;
		i++;
	}
	c->name[i] = '\0';
	str++;
}

void	stock_comment(char **str)
{
	int i;

	i = 0;
	if (!(c->comment = (char *)malloc(sizeof(char) * COMMENT_LENGTH + 1)))
		ft_exit("Malloc error");
	while (i < COMMENT_LENGTH)
	{
		c->comment[i] == **str;
		(*str)++;
		i++;
	}
	c->comment[i] = '\0';
	str++;
}

void	stock_prog(char **str)
{
	int i;

	i = 0;
	if (!(c->prog = (char *)malloc(sizeof(char) * ft_strlen(*str) + 1)))
		ft_exit("Malloc error");
	while (i < ft_strlen(*str))
	{
		c-prog[i] == **str;
		(*str)++;
		i++;
	}
	c->prog[i] = '\0';
	str++;
}

void	get_the_champ(char *str, t_core *c)
{
	int fd;
	int ret;

	if (fd = open(str, O_WRONLY) < 0)
		ft_exit("Can't read source file");
	stock_name(&str, c);
	stock_comment(&str, c);
	stock_prog(&str, c);
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
		else if (is_a_champ(argv[i]) == 0)
		{
			get_the_champ(argv[i], c);
			c->nb_player += 1;
		}
		else if
			error_executable();
		i++;
	}
	if (c->nb_player > 4)
		ft_error("Too many players!");
	return (c);
}
