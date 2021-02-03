/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:59:14 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/03 12:24:29 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

static	void	ft_render_line(t_frame frame, int x, int y, int color)
{
	int	i;

	i = 0;
	while (i < x)
		ft_frame_pixel(frame, i++, y, color);
}

void	ft_render_cf(t_game *game)
{
	int color_c;
	int color_f;
	int	y;

	color_c = ft_trgb(0, game->scene->c.r, game->scene->c.g, game->scene->c.b);
	color_f = ft_trgb(0, game->scene->f.r, game->scene->f.g, game->scene->f.b);
	y = 0;
	while (y < (game->scene->y_scr / 2))
		ft_render_line(game->frame, game->scene->x_scr, y++, color_c);
	while (y < game->scene->y_scr)
		ft_render_line(game->frame, game->scene->x_scr, y++, color_f);
}

void	ft_render_frame(t_game *game)
{
	ft_render_cf(game);
	ft_render_raycast(game);
	ft_render_sprite(game);
}
