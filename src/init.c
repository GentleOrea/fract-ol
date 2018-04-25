/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:31:40 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/25 19:27:21 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	init_images(t_global *g, int len, int height)
{
	g->pic.ptr = mlx_new_image(g->win.mlx_ptr, len, height);
	g->pic.str = (int *)mlx_get_data_addr(g->pic.ptr,
			&(g->pic.bpp), &(g->pic.s_l), &(g->pic.endian));
}

void	init_global(t_global *g)
{
	g->win.max_len = 700;
	g->win.max_height = 700;
	g->win.mlx_ptr = mlx_init();
	g->win.win_ptr = mlx_new_window(g->win.mlx_ptr,
			g->win.max_len, g->win.max_height, "fractol");
	init_images(g, g->win.max_len, g->win.max_height);
}
