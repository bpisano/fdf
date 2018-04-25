/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color_manager.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/24 19:24:28 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 19:25:34 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

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
	return (RGB(255 - (height * 150), 255, 255 - (height * 200)));
}
