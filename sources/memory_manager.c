/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   memory_manager.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/03 15:26:04 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/03 15:33:19 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	free_env(t_env *env)
{
	int		y;
	int		x;
	t_coord	*coord;

	y = -1;
	while (env->coords[++y])
	{
		x = -1;
		while (((t_array)env->coords[y])[++x])
		{
			coord = (t_coord *)((t_array)env->coords[y])[x];
			free(coord);
		}
		free(env->coords[y]);
	}
	free(env->coords);
	free(env->wdw);
	free(env->mlx);
}
