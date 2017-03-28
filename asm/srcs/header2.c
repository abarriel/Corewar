/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 22:27:52 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/22 22:27:54 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_full_space_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' || str[i] != '\0')
			return (1);
		i++;
	}
	return (0);
}

void	header_verif_name_comment(char *line, t_asm *a)
{
	while (*(line++) && *line != '"')
		;
	line++;
	while (*(line++))
	{
		if (*line != ' ' && *line != '\0')
			return (lexical_error(a->count_line, a->len_line -
				ft_strlen(line)));
	}
	return ;
}
