/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 00:43:54 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/19 01:43:52 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1024
# define MAX_SIZE_FD 2560
# include "libft.h"
# include <fcntl.h>

typedef struct		s_stocks
{
	int				fd;
	int				read;
	char			*data;
	struct s_stocks	*next;
}					t_stocks;

int					get_next_line(int fd, char **line);

#endif
