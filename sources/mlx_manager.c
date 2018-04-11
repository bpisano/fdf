/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 18:07:20 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/11 12:28:49 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		handle_key(int key, t_env *env)
{
	if (key == ARROW_UP)
		rotate(env, env->rx + ROT_SPEED, env->ry, env->rz);
	else if (key == ARROW_DOWN)
		rotate(env, env->rx - ROT_SPEED, env->ry, env->rz);
	else if (key == ARROW_LEFT)
		rotate(env, env->rx, env->ry + ROT_SPEED, env->rz);
	else if (key == ARROW_RIGHT)
		rotate(env, env->rx, env->ry - ROT_SPEED, env->rz);
	if (key == ARROW_UP || key == ARROW_DOWN || key == ARROW_LEFT
			|| key == ARROW_RIGHT)
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
	//mlx_clear_window(env->mlx, env->wdw);
}

void	new_image(t_env *env)
{
	int		bpp;
	int		sl;
	int		e;
	
	env->img = mlx_new_image(env->mlx, W_WIDTH, W_HEIGHT);
	env->img_data = mlx_get_data_addr(env->img, &bpp, &sl, &e);
}

void	fill_pixel(t_env *env, int x, int y, int color)
{
	((int *)env->img)[x + y * W_WIDTH] = color;
}

void	display(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->wdw, env->img, 0, 0);
}
