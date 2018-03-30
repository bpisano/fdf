/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 18:29:35 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/30 15:13:39 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_env *env, t_coord *c1, t_coord *c2)
{
	double	x;
	double	y;
	double	e;
	double	to_x;
	int		inc;

	x = c1->x > c2->x ? c2->x - 1 : c1->x - 1;
	y = c1->x > c2->x ? c2->y : c1->y;
	e = 0;
	to_x = c1->x > c2->x ? c1->x : c2->x;
	inc	= (c2->y - c1->y) / (c2->x - c1->x) < 0 ? -1 : 1;
	while (++x < to_x)
	{
		mlx_pixel_put(env->mlx, env->wdw, x, y, RGB(255, 255, 255));
		e += fabs((c2->y - c1->y) / (c2->x - c1->x));
		if (e > 0.5)
		{
			e--;
			y += inc;
		}
	}
}

void	draw(t_env *env)
{
	(void)env;
	t_coord *c1 = set_coord(100, 0, 0);
	t_coord *c2 = set_coord(0, 100, 0);
	draw_line(env, c1, c2);
}
