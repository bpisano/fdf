/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 13:38:02 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 16:04:55 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "math.h"
# include "ft_array.h"

# define PI 3.1415926535

typedef struct	s_coord
{
	double		x;
	double		y;
	double		z;
}				t_coord;

typedef struct	s_env
{
	void		*mlx;
	void		*wdw;
	t_array		coords;
	t_coord		rot;
}				t_env;

int				parse(char *file_name, t_env *env);
void			init_env(t_env *env);

t_coord			*set_coord(double x, double y, double z);
t_array			to_2d(t_array td_ar, t_coord *rot);

#endif
