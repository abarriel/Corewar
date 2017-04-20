/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <lcharvol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 20:31:16 by lcharvol          #+#    #+#             */
/*   Updated: 2017/04/20 01:01:06 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_draw_title(t_env *p)
{
	int		n;
	int		r;

	if (open("../includes/mlx/title2.xpm", O_RDWR) < 0)
	{
		ft_putstr("Image xpm introuvable\n");
		exit(0);
	}
	p->img2 = mlx_xpm_file_to_image(p->mlx,
		"../includes/mlx/title2.xpm", &n, &r);
	p->ret2 = mlx_get_data_addr(p->img, &(p->bits_per_pixel),
		&(p->size_line), &(p->endian));
}

void		ft_draw_button(t_env *p)
{
	ft_modif_color(25, 25, 25, p);
	ft_draw_square((HEIGHT) + 20, (HEIGHT) - 135, 100, p);
	ft_modif_color(35, 35, 35, p);
	ft_draw_square(p->but->btn1_px, p->but->btn1_py, p->but->btn1_s, p);
	ft_modif_color(25, 25, 25, p);
	ft_draw_square((HEIGHT) + 170, (HEIGHT) - 135, 100, p);
	ft_modif_color(35, 35, 35, p);
	ft_draw_square(p->but->btn2_px, p->but->btn2_py, p->but->btn2_s, p);
	ft_modif_color(25, 25, 25, p);
	ft_draw_square((HEIGHT) + 320, (HEIGHT) - 135, 100, p);
	ft_modif_color(35, 35, 35, p);
	ft_draw_square(p->but->btn3_px, p->but->btn3_py, p->but->btn3_s, p);
	ft_modif_color(25, 25, 25, p);
	ft_draw_square((HEIGHT) + 470, (HEIGHT) - 135, 100, p);
	ft_modif_color(35, 35, 35, p);
	ft_draw_square(p->but->btn4_px, p->but->btn4_py, p->but->btn4_s, p);
	ft_modif_color(25, 25, 25, p);
	ft_draw_square((HEIGHT) + 620, (HEIGHT) - 135, 100, p);
	ft_modif_color(35, 35, 35, p);
	ft_draw_square(p->but->btn5_px, p->but->btn5_py, p->but->btn5_s, p);
}

void		ft_draw_player_info2(t_env *p)
{
	print_player_name(p);
}

void		ft_draw_player_info(t_env *p)
{
	p->l = 335;
	p->h = 200;
	ft_modif_color(35, 35, 35, p);
	ft_draw_rectangle((HEIGHT) + 32, 675, p);
	p->l = 335;
	p->h = 200;
	ft_modif_color(35, 35, 35, p);
	ft_draw_rectangle((HEIGHT) + 32, 880, p);
	p->l = 335;
	p->h = 200;
	ft_modif_color(35, 35, 35, p);
	ft_draw_rectangle((HEIGHT) + 372, 675, p);
	p->l = 335;
	p->h = 200;
	ft_modif_color(35, 35, 35, p);
	ft_draw_rectangle((HEIGHT) + 372, 880, p);
	ft_draw_player_info2(p);
}

void		ft_draw(t_env *p)
{
	ft_draw_background(p);
	ft_draw_arena(p);
	ft_draw_menu(p);
	ft_draw_title(p);
	ft_draw_player_info(p);
	ft_draw_button(p);
	p->h = 20;
	ft_draw_score(p);
}
