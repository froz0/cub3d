/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:09:56 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/03 17:11:03 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include <math.h>

void	ft_calc_sidedist(t_game *game, t_ray *ray)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (game->posx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - game->posx) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (game->posy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - game->posy) * ray->deltadisty;
	}
}

void	ft_calc_raydir(t_game *game, t_ray *ray, int x)
{
	double	camerax;

	camerax = 2 * x / (double)game->scene->x_scr - 1;
	ray->raydirx = game->dirx + game->planex * camerax;
	ray->raydiry = game->diry + game->planey * camerax;
	ray->mapx = (int)game->posx;
	ray->mapy = (int)game->posy;
	ray->deltadistx = fabs(1 / ray->raydirx);
	ray->deltadisty = fabs(1 / ray->raydiry);
}

void	ft_calc_side(t_game *game, t_ray *ray)
{
	if (ray->sidedistx < ray->sidedisty)
	{
		if (ray->stepx == 1)
			ray->walln = 0;
		else if (ray->stepx == -1)
			ray->walln = 1;
	}
	else
	{
		if (ray->stepy == 1)
			ray->walln = 2;
		else if (ray->stepy == -1)
			ray->walln = 3;
	}
	if (ray->walln == 0)
		ray->tex = game->so_text;
	else if (ray->walln == 1)
		ray->tex = game->no_text;
	else if (ray->walln == 2)
		ray->tex = game->we_text;
	else if (ray->walln == 3)
		ray->tex = game->ea_text;
}

double	ft_calc_dist(t_game *game, t_ray *ray)
{
	t_bool	hit;

	hit = 0;
	while (!hit)
	{
		ft_calc_side(game, ray);
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
		}
		if (ray->mapx >= game->scene->sizey || ray->mapy >= game->scene->sizex
			|| ray->mapy < 0 || ray->mapx < 0)
			hit = true;
		else if (game->scene->map[ray->mapx][ray->mapy] == '1')
			hit = true;
	}
	if (ray->walln < 2)
		return ((ray->mapx - game->posx + (1 - ray->stepx) / 2) / ray->raydirx);
	return ((ray->mapy - game->posy + (1 - ray->stepy) / 2) / ray->raydiry);
}

void	ft_calc_draw(t_game *game, t_ray *ray)
{
	ray->lineheight = (int)(game->scene->y_scr / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + game->scene->y_scr / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + game->scene->y_scr / 2;
	if (ray->drawend >= game->scene->y_scr)
		ray->drawend = game->scene->y_scr - 1;
	if (ray->walln < 2)
		ray->wallx = game->posy + ray->perpwalldist * ray->raydiry;
	else
		ray->wallx = game->posx + ray->perpwalldist * ray->raydirx;
	ray->wallx -= floor((ray->wallx));
	ray->texx = (int)(ray->wallx * (double)ray->tex.width);
	if (ray->walln < 2 && ray->raydirx > 0)
		ray->texx = ray->tex.width - ray->texx - 1;
	if (ray->walln > 1 && ray->raydiry < 0)
		ray->texx = ray->tex.width - ray->texx - 1;
	ray->step = 1.0 * ray->tex.height / ray->lineheight;
	ray->texpos = (ray->drawstart - game->scene->y_scr / 2
			+ ray->lineheight / 2) * ray->step;
}
