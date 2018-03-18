/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:34:32 by ygarrot           #+#    #+#             */
/*   Updated: 2018/03/16 10:45:37 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	define_value(t_global *g)
{
	g->coo.zoom = 200;
	g->coo.iteration = 100;
	g->coo.r[X] = g->coo.num ? -1.5 : -3.5;
	g->coo.r[Y] = g->coo.num ? -1.5 : -1.5;
	g->coo.cons[R] = -0.7;
	g->coo.cons[I] = 0.2701;
}

void	set_value(t_global *g, t_coord *c)
{
	int		i;
	float	tmp;

	i = 0;
	while ((c->z[R] * c->z[R] + c->z[I] * c->z[I]) < 4 && i < c->iteration)
	{
		tmp = (c->num != 2) ? c->z[R] :
			(c->z[R] * c->z[R] - c->z[I] * c->z[I]) + c->c[R];
		if (c->num != 2)
		{
			c->z[R] = 1 + c->z[R] * c->z[R] - c->z[I] * c->z[I] + c->c[R];
			c->z[I] = 2 * c->z[I] * tmp + c->c[I];
		}
		else
		{
			c->z[I] = fabs(2 * c->z[R] * c->z[I] + c->c[I]);
			c->z[R] = fabs(tmp);
		}
		++i;
	}
	g->pic.color =
		mlx_col_name[(i * abs(g->pic.col_base | 1) * 10) % 700].color;
	if (i != c->iteration || c->num != 2)
		g->pic.str[c->ax[X] + (c->ax[Y] * g->win.max_len)] += g->pic.color;
}

void	frac_base(t_global *g, t_coord *c)
{
	while (++c->ax[Y] < g->win.max_height)
	{
		c->ax[X] = 0;
		while (++c->ax[X] < g->win.max_len)
		{
			c->c[R] = (c->num == 1) ? c->cons[R] : c->ax[X] / c->zoom + c->r[X];
			c->c[I] = (c->num == 1) ? c->cons[I] : c->ax[Y] / c->zoom + c->r[Y];
			c->z[R] = (c->num == 1) ? c->ax[X] / c->zoom + c->r[X] : 0;
			c->z[I] = (c->num == 1) ? c->ax[Y] / c->zoom + c->r[Y] : 0;
			set_value(g, c);
		}
	}
}
