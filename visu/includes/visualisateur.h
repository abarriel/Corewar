/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisateur.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 10:13:57 by lcharvol          #+#    #+#             */
/*   Updated: 2017/02/04 10:13:59 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALISATEUR_H
# define VISUALISATEUR_H

# include "../../includes/asm.h"
# include "mlx/mlx.h"
# define WIDTH 2000
# define HEIGHT 1250
# define ECHAP	53

typedef struct		s_env
{
	int				h;
	int				l;
	int				r;
	int				v;
	int				b;
	int				map_size_x;
	int				map_size_y;
	char			*ret;
	void			*ret2;
	void			*win;
	void			*mlx;
	void			*img;
	void			*img2;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				pause;
}					t_env;

void				ft_modif_color(int r, int v, int b, t_env *p);
void				ft_draw(t_env *p);
void				ft_modif_color(int r, int v, int b, t_env *p);
void				ft_draw_square(int start_x, int start_y,
	int size, t_env *p);
void				ft_draw_background(t_env *p);
void				ft_draw_map(t_env *p);

#endif
