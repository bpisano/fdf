/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 18:07:20 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/05 14:10:20 by bpisano     ###    #+. /#+    ###.fr     */
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
