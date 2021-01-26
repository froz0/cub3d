/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:59:14 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/26 16:33:57 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	ft_frame_pixel(t_frame *frame, int x, int y, int color)
{
	char	*dst;

    dst = frame->addr + (y * frame->line_length + x * (frame->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

static	void	ft_render_line(t_frame *frame, int x, int y, int color)
{
	int	i;

	i = 0;
	while (i < x)
	{
		ft_frame_pixel(frame, i, y, color);
		i++;
	}
}

void	ft_render_cf(t_game_state gs, t_frame *frame)
{
	int color_c;
	int color_f;
	int	y;

	color_c = ft_trgb(0, gs.scene->c.r, gs.scene->c.g, gs.scene->c.b);
	color_f = ft_trgb(0, gs.scene->f.r, gs.scene->f.g, gs.scene->f.b);
	y = 0;
	while (y < (gs.scene->y_scr / 2))
		ft_render_line(frame, gs.scene->x_scr, y++, color_c);
	while (y < gs.scene->y_scr)
		ft_render_line(frame, gs.scene->x_scr, y++, color_f);
}

t_frame	ft_render_frame(t_game_state game_state)
{
	t_frame	frame;

	frame.img = mlx_new_image(game_state.mlx, game_state.scene->x_scr,
			game_state.scene->y_scr);
	frame.addr = mlx_get_data_addr(frame.img, &frame.bits_per_pixel, &frame.line_length,
			&frame.endian);
	ft_render_cf(game_state, &frame);
	return (frame);
}
