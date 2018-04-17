/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env_manager.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/05 14:09:28 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 12:26:27 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	set_env_size(t_env *env, double x, double y)
{
	double	min_x;
	double	min_y;
	double	max_x;
	double	max_y;
	t_coord *coord;

	min_x = 9999999;
	min_y = 9999999;
	max_x = -9999999;
	max_y = -9999999;
	y = -1;
	while (env->coords[(int)++y])
	{
		x = -1;
		while (((t_array)env->coords[(int)y])[(int)++x])
		{
			coord = (t_coord *)((t_array)env->coords[(int)y])[(int)x];
			min_x = coord->x < min_x ? fabs(coord->x) : min_x;
			min_y = coord->y < min_y ? fabs(coord->y) : min_y;
			max_x = coord->x > max_x ? fabs(coord->x) : max_x;
			max_y = coord->y > max_y ? fabs(coord->y) : max_y;
		}
	}
	env->width = (max_x - min_x) * env->zoom;
	env->height = (max_y - min_y) * env->zoom;
}

void	set_env_offset(t_env *env)
{
	int		y;
	int		x;
	int		zo;
	t_coord *coord;

	zo = env->zoom;
	y = -1;
	while (env->coords[++y] && (x = -1))
		while (((t_array)env->coords[y])[++x])
		{
			coord = (t_coord *)((t_array)env->coords[y])[x];
			coord->x = coord->x * zo + (W_WIDTH / 2) - (env->width / 2);
			coord->y = coord->y * zo + (W_HEIGHT / 2) - (env->height / 2);
		}
}

void	init_env(t_env *env)
{
	env->mlx = mlx_init();
	env->wdw = mlx_new_window(env->mlx, W_WIDTH, W_HEIGHT, "fdf");
	ar_init(&(env->coords), 0);
	env->width = 0;
	env->height = 0;
	env->zoom = 10;
	env->rx = 0;
	env->ry = 0;
	env->rz = 0;
}
