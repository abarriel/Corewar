/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations__.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 23:35:14 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/25 23:35:16 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	handles_space(char **s, t_cmd *c)
{
	size_t	i;
	size_t	n_sp;
	int		len;

	i = 0;
	n_sp = 0;
	while ((*s)[i] != '\0' && (*s)[i] != ' ' && (*s)[i] != '\t')
		i++;
	if (i == ft_strlen(*s))
		return ;
	n_sp = i + 1;
	while ((*s)[n_sp] != '\0' && ((*s)[n_sp] == ' ' || (*s)[n_sp] == '\t'))
		n_sp++;
	if ((i + (n_sp - i)) != ft_strlen(*s))
	{
		syntax_error(*s, c->colon, c->line);
		return ;
	}
	len = ft_strlen((*s) + i);
	ft_bzero((*s) + i, len);
}

int		handles_ind_dir(char *arg, short type)
{
	int		i;
	int		len;

	i = -1;
	if (*arg == '-' && *(arg) + 1 != '\0')
		arg++;
	while (ft_isdigit(arg[++i]))
		;
	len = ft_strlen(arg);
	arg = arg + i;
	len -= skip_space_len(&arg);
	if (i != len)
		return (0);
	if (type == 1)
		return (T_DIR);
	if (type == 2)
		return (T_IND);
	return (0);
}

int		handles_dir(t_asm *a, char *arg, t_cmd *c)
{
	int		i;

	i = -1;
	if (*arg != '%')
		return (0);
	if (*arg == '%')
		arg++;
	if (*arg == LABEL_CHAR)
	{
		arg++;
		handles_space(&arg, c);
		while (++i < a->nb_label)
		{
			if (!ft_strcmp(arg, a->label[i]))
				break ;
		}
		if (i == a->nb_label)
			return (0);
		return (T_DIR);
	}
	else
		return (handles_ind_dir(arg, 1));
}

int		handles_ind(t_asm *a, char *arg, t_cmd *c)
{
	char	*str;
	int		i;

	i = -1;
	str = arg;
	if (*arg == LABEL_CHAR)
	{
		arg++;
		handles_space(&arg, c);
		while (++i < a->nb_label)
		{
			if (!ft_strcmp(arg, a->label[i]))
				break ;
		}
		if (i == a->nb_label)
			no_label_error(arg, str, c->colon, c->line - (ft_strlen(str) - 1));
		return (T_IND);
	}
	else
		return (handles_ind_dir(arg, 2));
}
