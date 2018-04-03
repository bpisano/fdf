/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 18:29:35 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/03 19:10:56 by bpisano     ###    #+. /#+    ###.fr     */
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

int		color(t_coord *c1, t_coord *c2, int x, int y)
{
	double	px;
	double	py;
	double	pz;
	double	height;

	if (((int)c2->x - (int)c1->x) != 0)
		px = (double)(x - (int)c1->x) / ((int)c2->x - (int)c1->x);
	else
		px = 1;
	if (((int)c2->y - (int)c1->y) != 0)
		py = (double)(y - (int)c1->y) / ((int)c2->y - (int)c1->y);
	else
		py = 1;
	pz = (px + py) / 2;
	if (c1->oz < c2->oz)
		height = c1->oz + (fabs(c1->oz - c2->oz) * pz);
	else
		height = c1->oz - (fabs(c1->oz - c2->oz) * pz);
	printf("%d, %d,   %d, %d,   %d, %d - %f, %f, %f, %f\n", x, y,
			(int)c1->x, (int)c1->y,
			(int)c2->x, (int)c2->y,
			px, py, pz, height);
	return (RGB(255 - (height * 10), 255 - (height * 10), 255));
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
	while ((x != floor(c2->x) || y != floor(c2->y)) && (err_cpy = err))
	{
		mlx_pixel_put(env->mlx, env->wdw, x, y, color(c1, c2, x, y));
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
	mlx_pixel_put(env->mlx, env->wdw, x, y, color(c1, c2, x, y));
	printf("\n");
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
