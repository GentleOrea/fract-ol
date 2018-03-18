/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:12:33 by ygarrot           #+#    #+#             */
/*   Updated: 2018/03/16 10:45:52 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	refresh(t_global *g)
{
	mlx_clear_window(g->win.mlx_ptr, g->win.win_ptr);
	mlx_destroy_image(g->win.mlx_ptr, g->pic.ptr);
	init_images(g, g->win.max_len, g->win.max_height);
	g->coo.ax[X] = 0;
	g->coo.ax[Y] = 0;
	frac_base(g, &g->coo);
	mlx_put_image_to_window(g->win.mlx_ptr, g->win.win_ptr, g->pic.ptr, 0, 0);
}

int		shortcut(int key, t_global *g)
{
	if (key == 53)
	{
		mlx_destroy_image(g->win.mlx_ptr, g->pic.ptr);
		mlx_destroy_window(g->win.mlx_ptr, g->win.win_ptr);
		ft_memdel((void**)&g);
		exit(1);
	}
	key == 49 ? define_value(g) : 0;
	if ((key == 69 && (g->coo.iteration + 10) < 142)
			|| (key == 78 && (g->coo.iteration - 10) > 10))
		g->coo.iteration += (key == 78) ? -10 : 10;
	if (key == 18 || key == 19)
		g->pic.col_base += (key == 18) ? 2 : -2;
	if (key >= 82 && key < 85)
	{
		g->coo.num = key - 82;
		define_value(g);
	}
	if (key == 126 || key == 125)
		g->coo.r[Y] += 0.0003 * g->coo.zoom * ((key == 125) ? 1 : -1);
	if (key == 123 || key == 124)
		g->coo.r[X] += 0.0003 * g->coo.zoom * ((key == 124) ? 1 : -1);
	refresh(g);
	return (0);
}

int		hook(int x, int y, t_global *g)
{
	g->coo.cons[I] = (float)g->win.max_len / (float)x / 2.0;
	g->coo.cons[R] = -(float)g->win.max_height / (float)y / 2.0;
	refresh(g);
	return (0);
}

int		mouse(int button, int x, int y, t_global *g)
{
	(void)x;
	(void)y;
	if (button == 4 || button == 5)
	{
		g->coo.zoom += (button == 5) ? 10 : -10;
		refresh(g);
	}
	return (0);
}
