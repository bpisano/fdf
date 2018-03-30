/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 13:38:02 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/30 14:05:37 by bpisano     ###    #+. /#+    ###.fr     */
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
#define RGB(r, g, b) (256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

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

void			init_env(t_env *env);
void			start_loop(t_env *env);

int				parse(char *file_name, t_env *env);

t_coord			*set_coord(double x, double y, double z);
t_array			rotate(t_array td_ar, t_coord *rot);

void			draw(t_env *env);

#endif
