/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   point_manager.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 14:10:37 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/03 16:05:55 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_coord		*set_coord(double x, double y, double z)
{
	t_coord	*point;

	if (!(point = (t_coord *)malloc(sizeof(t_coord))))
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	point->oz = z;
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

t_array		rotate(t_array td_ar, t_coord *rot)
{
	int		y;
	int		x;
	t_coord *td;
	t_array	dd_ar;

	dd_ar = td_ar;
	y = -1;
	while (dd_ar[++y])
	{
		x = -1;
		while ((td = (t_coord *)((t_array)dd_ar[y])[++x]))
		{
			x_rotation(td, rot->x);
			y_rotation(td, rot->y);
			z_rotation(td, rot->z);
		}
	}
	return (dd_ar);
}
