/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 22:22:51 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/03 18:44:18 by tmatis           ###   ########.fr       */
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

static	void	ft_init_sprites(t_game *g)
{
	t_sprite	sprite;
	int			i;

	i = 0;
	while (i < g->scene->numsprite)
	{
		sprite = g->scene->sprites[i];
		g->spriteorder[i] = i;
		g->spritedist[i] = ((g->posx - sprite.x)
				*(g->posx - sprite.x) + (g->posy - sprite.y) * (g->posy - sprite.y));
		i++;
	}
}

static	void	ft_calc_sprite(t_game *g, t_sp *s, int i)
{
	s->spritex = g->scene->sprites[g->spriteorder[i]].x - (g->posx - 0.5);
	s->spritey = g->scene->sprites[g->spriteorder[i]].y - (g->posy - 0.5);
	s->invdet = 1.0 / (g->planex * g->diry - g->dirx * g->planey);
	s->transformx = s->invdet * (g->diry * s->spritex - g->dirx * s->spritey);
	s->transformy = s->invdet * (-g->planey * s->spritex + g->planex * s->spritey);
	s->spritescreenx = (int)((g->scene->x_scr / 2) *(1 + s->transformx / s->transformy));
	s->spriteheight = ft_abs((int)(g->scene->y_scr / (s->transformy)));
	s->drawstarty = -s->spriteheight / 2 + g->scene->y_scr / 2;
	if (s->drawstarty < 0)
		s->drawstarty = 0;
	s->drawendy = s->spriteheight / 2 + g->scene->y_scr / 2;
	if (s->drawendy >= g->scene->y_scr)
		s->drawendy = g->scene->y_scr - 1;
	s->spritewidth = ft_abs((int)(g->scene->y_scr / (s->transformy)));
	s->drawstartx = -s->spritewidth / 2 + s->spritescreenx;
	if (s->drawstartx < 0)
		s->drawstartx = 0;
	s->drawendx = s->spritewidth / 2 + s->spritescreenx;
	if (s->drawendx >= g->scene->x_scr)
		s->drawendx = g->scene->x_scr - 1;
}

void	ft_draw_stripe(t_game *g, t_sp *s, int stripe)
{
	UINT	color;
	int		y;

	s->texx = (int)(256 * (stripe
				- (-s->spritewidth / 2 + s->spritescreenx))
			* g->sprite.width / s->spritewidth) / 256;
	if (s->transformy > 0
		&& stripe > 0 && stripe < g->scene->x_scr && s->transformy < g->zbuffer[stripe])
	{
		y = s->drawstarty;
		while (y < s->drawendy)
		{
			s->d = (y) * 256 - g->scene->y_scr * 128 + s->spriteheight * 128;
			s->texy = ((s->d * g->sprite.height) / s->spriteheight) / 256;
			color = ft_get_pixel(g->sprite.frame, s->texx, s->texy);
			if ((color & 0x00FFFFFF) != 0)
				ft_frame_pixel(g->frame, stripe, y, color);
			y++;
		}
	}
}

void	ft_render_sprite(t_game *g)
{
	t_sp	sp;
	int		i;
	int		stripe;

	ft_init_sprites(g);
	ft_sort_sprite(g->spritedist, g->spriteorder, g->scene->numsprite);
	i = 0;
	while (i < g->scene->numsprite)
	{
		ft_calc_sprite(g, &sp, i);
		stripe = sp.drawstartx;
		while (stripe < sp.drawendx)
		{
			ft_draw_stripe(g, &sp, stripe);
			stripe++;
		}
		i++;
	}
}
