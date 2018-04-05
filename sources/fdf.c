/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 16:15:51 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/05 19:13:27 by bpisano     ###    #+. /#+    ###.fr     */
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
	rotate(&env, 45, 45, 0);
	draw(&env);
	rotate(&env, 0, 0, 0);
	draw(&env);
	mlx_clear_window(env.mlx, env.wdw);
	start_loop(&env);
	free_env(&env);
	return (0);
}
