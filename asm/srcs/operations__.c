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

int		handles_dir(t_asm *a, char *arg, t_cmd *c)
{
	char	*str;
	int		i;
	int		len;

	i = -1;
	str = arg;
	if (*arg != '%')
	{
		return (0);
		// syntax_error(arg,c->colon, c->line);
	}
	if (*arg == '%')
		arg++;
	if (*arg == LABEL_CHAR)
	{
		arg++;
		while (++i < a->nb_label)
		{
			if (!ft_strcmp(arg, a->label[i]))
				break ;
		}
		if (i == a->nb_label)
		{
			return (0);
			// no_label_error(arg,str,c->colon,c->line - (ft_strlen(str) - 1));
		}
		return (1);
	}
	else
	{
		if (*arg == '-' && *(arg) + 1 != '\0')
			arg++;
		while (ft_isdigit(arg[++i]))
			;
		len = ft_strlen(arg);
		arg = arg + i;
		len -= skip_space_len(&arg);
		if (i != len)
			return (0);
		return (1);
	}
}

int		handles_ind(t_asm *a, char *arg, t_cmd *c)
{
	char	*str;
	int		i;
	int		len;

	i = -1;
	str = arg;
	if (*arg == LABEL_CHAR)
	{
		arg++;
		while (++i < a->nb_label)
		{
			if (!ft_strcmp(arg, a->label[i]))
				break ;
		}
		if (i == a->nb_label)
			no_label_error(arg, str, c->colon, c->line - (ft_strlen(str) - 1));
		return (1);
	}
	else
	{
		if (*arg == '-' && *(arg) + 1 != '\0')
			arg++;
		while (ft_isdigit(arg[++i]))
			;
		len = ft_strlen(arg);
		arg = arg + i;
		len -= skip_space_len(&arg);
		if (i != len)
		{
			return (0);
			// syntax_error(arg,c->colon, c->line - i);
		}
		return (1);
	}
}
