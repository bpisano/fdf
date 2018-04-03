/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 15:53:10 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/03 16:05:33 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_array	point_array(char **split, int y)
{
	int		x;
	int		z;
	t_array	new;

	x = -1;
	ar_init(&new, 1);
	while (split[++x])
	{
		z = ft_atoi(split[x]);
		ar_append(&new, set_coord(x * 20 + 100, y * 20 + 100, z));
	}
	return (new);
}

int		parse(char *file_name, t_env *env)
{
	int		fd;
	int		y;
	char	*line;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (0);
	y = -1;
	while (get_next_line(fd, &line) > 0)
		ar_append(&(env->coords), point_array(ft_strsplit(line, ' '), ++y));
	return (1);
}
