/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:08:58 by ygarrot           #+#    #+#             */
/*   Updated: 2018/03/16 10:45:19 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		main(int ac, char **av)
{
	t_global*g;

	if (ac != 2 || !ft_str_isdigit(av[1])
			|| ft_atoi(av[1]) < 0 || ft_atoi(av[1]) > 2)
	{
		ft_printf("Usage : ./fractol N (< 3)\n" "0 -> Mandelbrot \n1 -> Julia"
				"\n2 -> Burningship\n");
		return (0);
	}
	g = (t_global*)ft_memalloc(sizeof(t_global));
	g->coo.num = ft_atoi(av[1]);
	init_global(g);
	define_value(g);
	frac_base(g, &g->coo);
	mlx_put_image_to_window(g->win.mlx_ptr, g->win.win_ptr, g->pic.ptr, 0, 0);
	mlx_key_hook(g->win.win_ptr, shortcut, g);
	mlx_mouse_hook(g->win.win_ptr, mouse, g);
	mlx_hook(g->win.win_ptr, 6, 0, hook, g);
	mlx_loop(g->win.mlx_ptr);
	ft_memdel((void**)&g);
	return (0);
}
