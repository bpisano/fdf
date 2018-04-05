/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   point_manager.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 14:10:37 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/05 19:13:46 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_coord		*set_coord(double x, double y, double z)
{
	t_coord	*point;

	if (!(point = (t_coord *)malloc(sizeof(t_coord))))
		return (NULL);
	point->ox = x;
	point->oy = y;
	point->oz = z;
	point->x = x;
	point->y = y;
	point->z = z;
	return (point);
}

void		x_rotation(t_coord *coord, double rot)
{
	double	y;
	double	z;

	y = coord->y;
	z = coord->z;
	coord->y = cos(rot) * y + (-sin(rot)) * z;
	coord->z = sin(rot) * y + cos(rot) * z;
}

void		y_rotation(t_coord *coord, double rot)
{
	double	x;
	double	z;

	x = coord->x;
	z = coord->z;
	coord->x = cos(rot) * x + sin(rot) * z;
	coord->z = (-sin(rot)) * x + cos(rot) * z;
}

void		z_rotation(t_coord *coord, double rot)
{
	double	x;
	double	y;

	x = coord->x;
	y = coord->y;
	coord->x = cos(rot) * x + (-sin(rot)) * y;
	coord->y = -(sin(rot)) * x + cos(rot) * y;
}

void		rotate(t_env *env, double rx, double ry, double rz)
{
	int		y;
	int		x;
	t_coord	*coord;

	y = -1;
	while (env->coords[++y])
	{
		x = -1;
		while ((coord = (t_coord *)((t_array)env->coords[y])[++x]))
		{
			coord->x = coord->ox;
			coord->y = coord->oy;
			coord->z = coord->oz;
			x_rotation(coord, to_rad(rx));
			y_rotation(coord, to_rad(ry));
			z_rotation(coord, to_rad(rz));
		}
	}
}
