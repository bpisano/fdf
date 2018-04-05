/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env_manager.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/05 14:09:28 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/05 18:56:37 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	set_env_size(t_env *env, int x, int y)
{
	int		min_x;
	int		min_y;
	int		max_x;
	int		max_y;
	t_coord *coord;

	min_x = 9999999;
	min_y = 9999999;
	max_x = -9999999;
	max_y = -9999999;
	y = -1;
	while (env->coords[++y])
	{
		x = -1;
		while (((t_array)env->coords[y])[++x])
		{
			coord = (t_coord *)((t_array)env->coords[y])[x];
			min_x = coord->x < min_x ? x : min_x;
			min_y = coord->y < min_y ? y : min_y;
			max_x = coord->x > max_x ? x : max_x;
			max_y = coord->y > max_y ? y : max_y;
		}
	}
	env->width = max_x - min_x;
	env->height = max_y - min_y;
}

void	set_env_offset(t_env *env)
{
	int		y;
	int		x;
	t_coord *coord;

	y = -1;
	while (env->coords[++y] && (x = -1))
		while (((t_array)env->coords[y])[++x])
		{
			coord = (t_coord *)((t_array)env->coords[y])[x];
			coord->x = coord->x * 10 + (W_WIDTH / 2) - (env->width * 10 / 2);
			coord->y = coord->y * 10 + (W_HEIGHT / 2) - (env->height * 10 / 2);
			coord->z = coord->z;	
		}
}

void	init_env(t_env *env)
{
	env->mlx = mlx_init();
	env->wdw = mlx_new_window(env->mlx, W_WIDTH, W_HEIGHT, "fdf");
	ar_init(&(env->coords), 0);
	env->width = 0;
	env->height = 0;
}
