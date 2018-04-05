/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 13:38:02 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/05 18:35:25 by bpisano     ###    #+. /#+    ###.fr     */
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
# define RGB(r, g, b) (256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
# define W_WIDTH 500
# define W_HEIGHT 400

typedef struct	s_coord
{
	double		ox;
	double		oy;
	double		oz;
	double		x;
	double		y;
	double		z;
}				t_coord;

typedef struct	s_env
{
	void		*mlx;
	void		*wdw;
	t_array		coords;
	int			width;
	int			height;
}				t_env;

void			init_env(t_env *env);
void			set_env_size(t_env *env, int x, int y);
void			set_env_offset(t_env *env);
void			free_env(t_env *env);
void			clear_window(t_env *env);
void			start_loop(t_env *env);

int				parse(char *file_name, t_env *env);

double			to_rad(double deg);
t_coord			*set_coord(double x, double y, double z);
void			rotate(t_env *env, double rx, double ry, double rz);

void			draw(t_env *env);

#endif
