/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 18:29:35 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 19:25:43 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

double	dx(t_coord *c1, t_coord *c2)
{
	return (fabs(c2->x - c1->x));
}

double	dy(t_coord *c1, t_coord *c2)
{
	return (fabs(c2->y - c1->y));
}

double	init_draw(int *x, int *y, t_coord *c1, t_coord *c2)
{
	*y = floor(c1->y);
	*x = floor(c1->x);
	return ((dx(c1, c2) > dy(c1, c2) ? dx(c1, c2) : -dy(c1, c2)) / 2);
}

void	draw_line(t_env *env, t_coord *c1, t_coord *c2)
{
	int		y;
	int		x;
	double	err;
	double	err_cpy;

	err = init_draw(&x, &y, c1, c2);
	while ((x != floor(c2->x) || y != floor(c2->y)) && (err_cpy = err))
	{
		mlx_pixel_put(env->mlx, env->wdw, x, y, color(c1, c2, x, y));
		if (err_cpy > -dx(c1, c2) && dx(c1, c2) != 0)
		{
			err -= dy(c1, c2);
			if (x != floor(c2->x))
				x += c1->x < c2->x ? 1 : -1;
		}
		if (err_cpy < dy(c1, c2) && dy(c1, c2) != 0)
		{
			err += dx(c1, c2);
			if (y != floor(c2->y))
				y += c1->y < c2->y ? 1 : -1;
		}
		x = floor(dx(c1, c2)) == 0 ? floor(c2->x) : x;
		y = floor(dy(c1, c2)) == 0 ? floor(c2->y) : y;
	}
	mlx_pixel_put(env->mlx, env->wdw, x, y, color(c1, c2, x, y));
}

void	draw(t_env *env)
{
	int		y;
	int		x;
	t_coord	*coord;
	t_coord	*last_coord_x;
	t_coord *last_coord_y;

	clear_window(env);
	set_env_size(env, 0, 0);
	set_env_offset(env);
	y = -1;
	while (env->coords[++y] && (x = -1))
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
