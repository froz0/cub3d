/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:59:14 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/03 23:52:29 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
/*
static	void	ft_render_line(t_frame frame, int x, int y, int color)
{
	int	i;

	i = 0;
	while (i < x)
		ft_frame_pixel(frame, i++, y, color);
}
*/
void			ft_render_cf(t_game *g)
{
	int	y;

	y = 0;
	while (y < g->scene->y_scr)
	{
		double	raydirx0 = g->dirx - g->planex;
		double	raydiry0 = g->diry - g->planey;
		double	raydirx1 = g->dirx + g->planex;
		double	raydiry1 = g->diry + g->planey;
		int p = y - g->scene->y_scr / 2;
		double	posz = 0.5 * g->scene->y_scr;
		double	rowdistance = posz / p;
		double floorstepx = rowdistance * (raydirx1 - raydirx0) / g->scene->x_scr;
		double floorstepy = rowdistance * (raydiry1 - raydiry0) / g->scene->x_scr;
		double floorx = g->posx + rowdistance * raydirx0;
		double floory = g->posy + rowdistance * raydiry0;
		int	x;
		int	color;

		x = 0;
		while (x < g->scene->x_scr)
		{
			int cellx = (int)(floorx);
			int celly = (int)(floory);
			int tx = (int)(g->no_text.width * (floorx - cellx)) & (g->no_text.width - 1);
			int ty = (int)(g->no_text.height  * (floory - celly)) & (g->no_text.height - 1);
			floorx += floorstepx;
			floory += floorstepy;
			color = ft_get_pixel(g->so_text.frame, tx, ty);
			ft_frame_pixel(g->frame, x, y, color);
			color = ft_get_pixel(g->no_text.frame, tx, ty);
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
