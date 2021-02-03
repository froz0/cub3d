/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 22:22:51 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/03 12:47:55 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

static	void	ft_sort_sprite(double *dist, int *order, int size)
{
	int		i;
	int		y;
	double	temp;
	int		temp2;

	i = 0;
	while (i < size)
	{
		y = i + 1;
		while (y < size)
		{
			if (dist[i] < dist[y])
			{
				temp = dist[i];
				temp2 = order[i];
				dist[i] = dist[y];
				dist[y] = temp;
				order[i] = order[y];
				order[y] = temp2;
			}
			y++;
		}
		i++;
	}
}

void	ft_render_sprite(t_game *g)
{
	int			i;
	t_sprite	sprite;
	i = 0;
	while (i < g->scene->numsprite)
	{
		sprite = g->scene->sprites[i];
		g->spriteorder[i] = i;
		g->spritedist[i] = ((g->posx - sprite.x) * (g->posx - sprite.x)
				+ (g->posy - sprite.y) * (g->posy - sprite.y));
		i++;
	}
	ft_sort_sprite(g->spritedist, g->spriteorder, g->scene->numsprite);
	i = 0;
	while (i < g->scene->numsprite)
	{
		double spritex = g->scene->sprites[g->spriteorder[i]].x - (g->posx - 0.5);
		double spritey = g->scene->sprites[g->spriteorder[i]].y - (g->posy - 0.5);
		double invdet = 1.0 / (g->planex * g->diry - g->dirx * g->planey);

		double	transformx = invdet * (g->diry * spritex - g->dirx * spritey);
		double	transformy = invdet * (- g->planey * spritex + g->planex * spritey);

		int	spritescreenx = (int)((g->scene->x_scr / 2) * (1 + transformx / transformy));
		
		int spriteheight = abs((int)(g->scene->y_scr / (transformy)));
		int drawstarty = -spriteheight / 2 + g->scene->y_scr / 2;
		if (drawstarty < 0)
			drawstarty = 0;
		int drawendy = spriteheight / 2 + g->scene->y_scr / 2;
		if (drawendy >= g->scene->y_scr)
			drawendy = g->scene->y_scr - 1;

		int spritewidth = abs((int)(g->scene->y_scr / (transformy)));
		int drawstartx = -spritewidth / 2 + spritescreenx;
		if (drawstartx < 0)
			drawstartx = 0;
		int drawendx = spritewidth / 2 + spritescreenx;
		if (drawendx >= g->scene->x_scr)
			drawendx = g->scene->x_scr - 1;
		int	stripe = drawstartx;
		while (stripe < drawendx)
		{
			int texx = (int)(256 * (stripe - (-spritewidth / 2 + spritescreenx)) * g->sprite.width/ spritewidth) / 256;
			if(transformy > 0 && stripe > 0 && stripe < g->scene->x_scr && transformy < g->zbuffer[stripe])
			{
				int	y = drawstarty;
				while (y < drawendy)
				{
					int d = (y) * 256 - g->scene->y_scr * 128 + spriteheight * 128;
					int texy = ((d * g->sprite.height) / spriteheight) / 256;
					UINT color = ft_get_pixel(g->sprite.frame, texx, texy);
					if ((color & 0x00FFFFFF) != 0)
						ft_frame_pixel(g->frame, stripe, y, color);
					y++;
				}
			}
			stripe++;
		}
		i++;
	}
}
