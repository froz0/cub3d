/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:59:14 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/04 14:21:20 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

static void		ft_calc_pos(t_game *g, t_cf *cf, int y)
{
	cf->raydirx0 = g->dirx - g->planex;
	cf->raydiry0 = g->diry - g->planey;
	cf->raydirx1 = g->dirx + g->planex;
	cf->raydiry1 = g->diry + g->planey;
	cf->p = y - g->scene->y_scr / 2;
	cf->posz = 0.5 * g->scene->y_scr;
	cf->rowdistance = cf->posz / cf->p;
	cf->floorstepx =
		cf->rowdistance * (cf->raydirx1 - cf->raydirx0) / g->scene->x_scr;
	cf->floorstepy =
		cf->rowdistance * (cf->raydiry1 - cf->raydiry0) / g->scene->x_scr;
	cf->floorx_f = g->posx + cf->rowdistance * cf->raydirx0;
	cf->floory_f = g->posy + cf->rowdistance * cf->raydiry0;
	cf->floorx_c = cf->rowdistance * cf->raydirx0;
	cf->floory_c = cf->rowdistance * cf->raydiry0;
}

static	void	ft_calc_texture(t_game *g, t_cf *cf)
{
	cf->cellx_c = (int)(cf->floorx_c);
	cf->celly_c = (int)(cf->floory_c);
	cf->cellx_f = (int)(cf->floorx_f);
	cf->celly_f = (int)(cf->floory_f);
	cf->tx_c = (int)(g->c_text.width
			* (cf->floorx_c - cf->cellx_c)) & (g->c_text.width - 1);
	cf->ty_c = (int)(g->c_text.height
			* (cf->floory_c - cf->celly_c)) & (g->c_text.height - 1);
	cf->tx_f = (int)(g->f_text.width
			* (cf->floorx_f - cf->cellx_f)) & (g->f_text.width - 1);
	cf->ty_f = (int)(g->f_text.height
			* (cf->floory_f - cf->celly_f)) & (g->f_text.height - 1);
}

void			ft_render_cf(t_game *g)
{
	int		y;
	int		x;
	int		color;
	t_cf	cf;

	y = 0;
	while (y < g->scene->y_scr)
	{
		ft_calc_pos(g, &cf, y);
		x = 0;
		while (x < g->scene->x_scr)
		{
			ft_calc_texture(g, &cf);
			cf.floorx_c += cf.floorstepx;
			cf.floory_c += cf.floorstepy;
			cf.floorx_f += cf.floorstepx;
			cf.floory_f += cf.floorstepy;
			color = ft_get_pixel(g->f_text.frame, cf.tx_f, cf.ty_f);
			ft_frame_pixel(g->frame, x, y, color);
			color = ft_get_pixel(g->c_text.frame, cf.tx_c, cf.ty_c);
			ft_frame_pixel(g->frame, x, g->scene->y_scr - y - 1, color);
			x++;
		}
		y++;
	}
}

void			ft_render_frame(t_game *game)
{
	ft_render_cf(game);
	ft_render_raycast(game);
	ft_render_sprite(game);
}
