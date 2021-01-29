/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:37:21 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/29 19:34:05 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include <math.h>

void	ft_render_raycast(t_game *game)
{
	double	posx = game->posx;
	double	posy = game->posy;
	double	dirx = game->dirx;
	double	diry = game->diry;
	double	planex = game->planex;
	double	planey = game->planey;
	int		w = game->scene->x_scr;
	int		h = game->scene->y_scr;
	int		x;
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		color;
	int		y;
	double	wallx;
	double	texx;
	int		texwidth = game->we_text.width;
	int		texheight = game->we_text.height;
	double	step;
	double	texpos;
	double	texy;

	x = 0;
	while (x < w)
	{
		camerax = 2 * x / (double)w - 1;
		raydirx = dirx + planex * camerax;
		raydiry = diry + planey * camerax;
		mapx = (int)posx;
		mapy = (int)posy;
		deltadistx = fabs(1 / raydirx);
		deltadisty = fabs(1 / raydiry);
		if (raydirx < 0)
		{
			stepx = -1;
			sidedistx = (posx - mapx) * deltadistx;
		}
		else
	    {
			stepx = 1;
			sidedistx = (mapx + 1.0 - posx) * deltadistx;
	    }
		if (raydiry < 0)
		{
			stepy = -1;
			sidedisty = (posy - mapy) * deltadisty;
		}
		else
		{
			stepy = 1;
			sidedisty = (mapy + 1.0 - posy) * deltadisty;
		}
		hit = 0;
		while (hit == 0)
		{
			if (sidedistx < sidedisty)
			{
				sidedistx += deltadistx;
				mapx += stepx;
				side = 0;
			}
			else
			{
				sidedisty += deltadisty;
				mapy += stepy;
				side = 1;
			}
			if (game->scene->map[mapy][mapx] == '1')
				hit = 1;
		}
		if (side == 0)
			perpwalldist = (mapx - posx + (1 - stepx) / 2) / raydirx;
		else
			perpwalldist = (mapy - posy + (1 - stepy) / 2) / raydiry;
		lineheight = (int)(h / perpwalldist);
		drawstart = -lineheight / 2 + h / 2;
		if (drawstart < 0)
			drawstart = 0;
		drawend = lineheight / 2 + h / 2;
		if (drawend >= h)
			drawend = h - 1;
		/*if (side == 1)
			color = ft_trgb(0 , 100, 100, 100);
		else
			color = ft_trgb(0 , 130, 130, 130);
		i = drawstart;
		while (i < drawend)
			ft_frame_pixel(game->frame, x, i++, color);
			*/
		if (side == 0)
			wallx = posy + perpwalldist * raydiry;
		else
			wallx = posx + perpwalldist * raydirx;
		wallx -= floor((wallx));
		texx = (int)(wallx * (double)texwidth);
		if (side == 0 && raydirx > 0)
			texx = texwidth - texx;
		if (side == 1 && raydiry < 0)
			texx = texwidth - texx;
		step = 1.0 * texheight / lineheight;
		texpos = (drawstart - h / 2 + lineheight / 2) * step;
		y = drawstart;
		while (y < drawend)
		{
			texy = (int)texpos & (texheight - 1);
			texpos += step;
			color = ft_get_pixel(game->we_text.frame, texx, texy);
			ft_frame_pixel(game->frame, x, y, color);
			y++;
		}
		x++;
	}
}
