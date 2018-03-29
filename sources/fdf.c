/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 16:15:51 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 18:27:24 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

double	to_rad(double deg)
{
	return (deg * PI / 180);
}

int		main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
		return (0);
	init_env(&env);
	if (!parse(av[1], &env))
		return (0);

	env.coords = to_2d(env.coords, set_coord(0, 0, 0));

	int		y;
	int		x;

	y = -1;
	while (env.coords[++y])
	{
		x = -1;
		while (((t_array)env.coords[y])[++x])
		{
			t_coord *coord;

			coord = (t_coord *)((t_array)env.coords[y])[x];
			printf("%f, %f, %f\n", coord->x, coord->y, coord->z);
		}
		printf("\n");
	}
	return (0);
}
