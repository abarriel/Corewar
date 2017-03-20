/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:48:55 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/19 19:56:53 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"
# define PURPLE	"\033[0;35m"
# define CYAN	"\033[0;36m"
# define AZUR	"\e[38;5;6m"
# define PEACH "\e[38;5;9m"
# define APPLE	"\e[38;5;10m"
# define OR	"\e[38;5;94m"
# define GREY	"\033[0;37m"
# define RESET	"\033[0;m"

typedef struct		s_stock
{
	char			*str;
	char			*tmp;
	size_t			f_len;
	char			color_nfun;
	char			color_def;
	va_list			aps;
	int				fd;
}					t_stock;

typedef struct		s_flag
{
	char			conv;
	size_t			final_len;
	char			signe;
	char			has;
	char			zero;
	char			left;
	char			aq;
	char			preci;
	char			l;
	char			ll;
	char			h;
	char			hh;
	char			jz;
	char			neg;
	char			plus;
	int				pre_len;
	int				champs;
	int				slen;
	int				sta;
	int				b_sta;
	char			color_nfun;
	int				fd;
}					t_flag;

typedef struct		s_conv
{
	char			*s;
	char			*sp;
	char			*aq;
	char			*tmp;
	char			*x;
	wchar_t			wch;
	wchar_t			*wst;
	wchar_t			*wtmp;
	size_t			final_len;
	int				len_aq;
	int				len_zero;
	int				tlen;
	long long int	i;
}					t_conv;
/*
** SETUP && MALLOC FUNCTION FREE
*/
int					ft_vdprintf(t_stock *s);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_printf(const char *format, ...);
t_conv				*start_conv(void);
t_stock				*set_stock(const char *format, int fd);
t_flag				*set_flags(int fd);
void				free_c(t_conv *f);
void				*ft_strsetc(char *s, int c, int n);
char				*ft_strjoin_three(char *s1, char *s2, char *s3);
char				*ft_strjoin_four(char *s1, char *s2, char *s3, char *s4);
/*
** CONV
*/
void				conv_c(t_stock *s, t_flag *f);
void				conv_s(t_stock *s, t_flag *f);
void				conv_d(t_stock *s, t_flag *f);
void				conv_u(t_stock *s, t_flag *f);
void				conv_base(t_stock *s, t_flag *f, char i);
void				handles_conv(t_flag *f, t_stock *s);
/*
** MODIF (WARNING)
*/
void				mod_d(t_flag *f, t_conv *c);
void				mod_base(t_flag *f, t_conv *c);
/*
** GET FLAGS/CONV  AND GET STRING O AND CHAMPS
*/
int					get_conv(char *n_arg, t_flag *f);
void				get_flags(char *s, t_flag *f);
void				string_sp_c(t_flag *f, t_conv *c);
void				string_zero_c(t_flag *f, t_conv *c);
void				string_zero(t_flag *f, t_conv *c);
void				string_sp(t_flag *f, t_conv *c);
void				string_sp_s(t_flag *f, t_conv *c);
/*
** ALL PRINTING FUNCTION
*/
void				print_s(t_flag *f, t_conv *c);
void				print_c(t_flag *f, t_conv *c);
void				print_d(t_flag *f, t_conv *c);
void				print_base(t_flag *f, t_conv *c);
int					putstr_per(char *str, int fd);
void				ft_putnwstr(t_conv *c, t_flag *f);
int					ft_putnwchar(t_conv *c, t_flag *f);
/*
** TOOLS
*/
size_t				ft_strnwlen(t_conv *c, t_flag *f);
int					if_so(char conv, char *symb);
/*
** FUN
*/
void				get_bonus(t_stock *t, t_flag *f);
void				color_fun(t_stock *s);
void				put_color(int fd, char color_nfun);

#endif
