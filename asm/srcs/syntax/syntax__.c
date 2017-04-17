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
	// ft_printf("{8}charactere = %d - nb of space = %d - strlen = %d\n",i,n_sp - i,ft_strlen(*s));
	if((i + (n_sp - i)) != ft_strlen(*s))
	{
		syntax_error(*s, c->colon, c->line);
		return ;
	}
	len = ft_strlen((*s) + i);
	ft_bzero((*s) + i, len);
}

int		handles_dir(t_asm *a, char *arg, t_cmd *c)
{
	char	*str;
	int		i;
	int		len;

	i = -1;
	str = arg;
	if (*arg != '%')
		return (0);
	if (*arg == '%')
		arg++;
	if (*arg == LABEL_CHAR)
	{
		arg++;
		handles_space(&arg, c);
		while ((++i < a->nb_label))
		{
			if (!ft_strcmp(arg, a->label[i]))
				break ;
		}
		if (i == a->nb_label)
			return (0);
		return (T_DIR);
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
		return (T_DIR);
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
		// ft_printf("{7}{%s}\n",arg);
		handles_space(&arg, c);
		// ft_printf("{7}{%s}\n\n",arg);
// 
		while (++i < a->nb_label)
		{
			if (!ft_strcmp(arg, a->label[i]))
				break ;
		}
		if (i == a->nb_label)
		{
			no_label_error(arg, str, c->colon, c->line - (ft_strlen(str) - 1));
		}
		return (T_IND);
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
		return (T_IND);
	}
}
