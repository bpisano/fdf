/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 18:07:20 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/03 14:54:47 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	start_loop(t_env *env)
{
	mlx_loop(env->mlx);
}

void	clear_window(t_env *env)
{
	mlx_clear_window(env->mlx, env->wdw);
}

void	init_env(t_env *env)
{
	env->mlx = mlx_init();
	env->wdw = mlx_new_window(env->mlx, 500, 400, "fdf");
	ar_init(&(env->coords), 0);
}
