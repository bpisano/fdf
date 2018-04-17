/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 18:07:20 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 12:44:12 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		handle_key(int key, t_env *env)
{
	if (key == ESC)
		exit (0);
	else if (key == ARROW_UP)
		rotate(env, env->rx + ROT_SPEED, env->ry, env->rz);
	else if (key == ARROW_DOWN)
		rotate(env, env->rx - ROT_SPEED, env->ry, env->rz);
	else if (key == ARROW_LEFT)
		rotate(env, env->rx, env->ry + ROT_SPEED, env->rz);
	else if (key == ARROW_RIGHT)
		rotate(env, env->rx, env->ry - ROT_SPEED, env->rz);
	else if (key == ZOOM_IN)
		env->zoom += 1;
	else if (key == ZOOM_OUT)
		env->zoom -= 1;
	if (key == ZOOM_IN || key == ZOOM_OUT)
		rotate(env, env->rx, env->ry, env->rz);
	if (key == ARROW_UP || key == ARROW_DOWN || key == ARROW_LEFT
			|| key == ARROW_RIGHT || key == ZOOM_IN || key == ZOOM_OUT)
		draw(env);
	return (0);
}

void	start_loop(t_env *env)
{
	mlx_key_hook(env->wdw, handle_key, env);
	mlx_loop(env->mlx);
}

void	clear_window(t_env *env)
{
	int		y;
	int		x;

	y = -1;
	while (++y < W_HEIGHT && (x = -1))
		while (++x < W_WIDTH)
			mlx_pixel_put(env->mlx, env->wdw, x, y, RGB(0, 0, 0));
}
