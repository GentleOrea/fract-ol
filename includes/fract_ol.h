/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:45:18 by ygarrot           #+#    #+#             */
/*   Updated: 2018/03/16 10:53:44 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include "../libft/includes/libft.h"
# include "mlx.h"
# include <math.h>

# define R 0
# define I 1
# define X 0
# define Y 1

typedef struct	s_coord
{
	int		iteration;
	int		ax[2];
	int		beg[2];
	float	cons[2];
	float	r[2];
	float	c[2];
	float	z[2];
	float	ratio[2];
	float	zoom;
	int		num;
}				t_coord;

typedef struct	s_picture
{
	int		*str;
	void	*ptr;
	int		bpp;
	int		endian;
	int		s_l;
	int		color;
	int		col_base;
}				t_picture;

struct			s_col_name
{
	char	*name;
	int		color;
};

typedef struct	s_window
{
	int			len;
	int			height;
	int			max_len;
	int			max_height;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_window;

typedef struct	s_global
{
	int				num;
	t_picture		pic;
	t_coord			coo;
	t_window		win;
}				t_global;

void			set_value(t_global *g, t_coord *c);
void			define_value(t_global *g);
void			frac_base(t_global *g, t_coord *c);
void			init_images(t_global *g, int len, int height);
void			refresh(t_global *g);
void			init_global(t_global *g);
void			scope(t_global *g, int zoom, int x, int y);
int				shortcut(int key, t_global *g);
int				mouse(int button, int x, int y, t_global *g);
int				hook(int x, int y, t_global *g);
extern struct s_col_name mlx_col_name[];

#endif
