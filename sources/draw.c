/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 18:29:35 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/03 13:46:32 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

double	dx(t_coord *c1, t_coord *c2)
{
	return fabs(c2->x - c1->x);
}

double	dy(t_coord *c1, t_coord *c2)
{
	return fabs(c2->y - c1->y);
}

void	draw_line(t_env *env, t_coord *c1, t_coord *c2)
{
	int		y;
	int		x;
	double	err;
	double	err_cpy;

	y = floor(c1->y);
	x = floor(c1->x);
	err = (dx(c1, c2) > dy(c1, c2) ? dx(c1, c2) : -dy(c1, c2)) / 2;
	while (x != floor(c2->x) || y != floor(c2->y))
	{
		mlx_pixel_put(env->mlx, env->wdw, x, y, RGB(255, 255, 255));
		err_cpy = err;
		printf("%d, %d, %f, %f, %f, %f\n", x, y, c1->x, c1->y, c2->x, c2->y);
		if (err_cpy > -dx(c1, c2))
		{
			err -= dy(c1, c2);
			if (x != floor(c2->x))
				x += c1->x < c2->x ? 1 : -1;
		}
		if (err_cpy < dy(c1, c2))
		{
			err += dx(c1, c2);
			if (y != floor(c2->y))
				y += c1->y < c2->y ? 1 : -1;
		}
	}
	mlx_pixel_put(env->mlx, env->wdw, x, y, RGB(255, 255, 255));	
}

void	draw(t_env *env)
{
	int		y;
	int		x;
	t_coord	*coord;
	t_coord	*last_coord_x;
	t_coord *last_coord_y;

	y = -1;
	while (env->coords[++y])
	{
		x = -1;
		while (((t_array)env->coords[y])[++x])
		{
			coord = (t_coord *)((t_array)env->coords[y])[x];
			if (x > 0)
			{
				last_coord_x = (t_coord *)((t_array)env->coords[y])[x - 1];
				draw_line(env, coord, last_coord_x);
			}
			if (y > 0)
			{
				last_coord_y = (t_coord *)((t_array)env->coords[y - 1])[x];
				draw_line(env, coord, last_coord_y);
			}
		}
	}	
}
