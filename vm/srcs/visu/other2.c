/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:14:47 by lcharvol          #+#    #+#             */
/*   Updated: 2017/02/23 16:15:52 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		check_button_hit2(int button, int x, int y, t_env *p)
{
	if (button == 1)
	{
		if ((x <= (HEIGHT) + 405) && (x >= (HEIGHT) + 335) && (y <=
			(HEIGHT) - 50) && (y >= (HEIGHT) - 120))
		{
			p->but->btn3_s = 80;
			p->but->btn3_px = (HEIGHT) + 330;
			p->but->btn3_py = (HEIGHT) - 125;
			if (p->core->cycle_sec - 5 > 0)
				p->core->cycle_sec -= 5;
		}
		if ((x <= (HEIGHT) + 565) && (x >= (HEIGHT) + 485) && (y <=
			(HEIGHT) - 50) && (y >= (HEIGHT) - 120))
		{
			p->but->btn4_s = 80;
			p->but->btn4_px = (HEIGHT) + 480;
			p->but->btn4_py = (HEIGHT) - 125;
			p->core->cycle_sec += 5;
		}
	}
}
