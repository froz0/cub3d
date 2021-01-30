/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 01:23:51 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/30 20:14:35 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"graphic.h"
#include	"math.h"

void	ft_walk(t_game *g)
{
	if (g->w)
	{
		if (g->scene->map[(int)(g->posx + g->dirx * (WS * 2))][(int)g->posy]
				!= '1')
			g->posx += g->dirx * WS;
		if (g->scene->map[(int)g->posx][(int)(g->posy + g->diry * WS)]
				!= '1')
			g->posy += g->diry * WS;
	}
	else if (g->s)
	{
		if (g->scene->map[(int)(g->posx - g->dirx * (WS * 2))][(int)g->posy]
				!= '1')
			g->posx -= g->dirx * WS;
		if (g->scene->map[(int)g->posx][(int)(g->posy - g->diry * WS)]
				!= '1')
			g->posy -= g->diry * WS;
	}
}

void	ft_straft(t_game *g)
{
	if (g->d)
	{
		if (g->scene->map[(int)(g->posx + g->diry * (SP * 2))][(int)g->posy]
				!= '1')
			g->posx += g->diry * SP;
		if (g->scene->map[(int)g->posx][(int)(g->posy - g->dirx * (SP * 2))]				!= '1')
			g->posy -= g->dirx * SP;
	}
	else if (g->a)
	{
		if (g->scene->map[(int)(g->posx - g->diry * (SP * 2))][(int)g->posy]
				!= '1')
			g->posx -= g->diry * SP;
		if (g->scene->map[(int)g->posx][(int)(g->posy + g->dirx * (SP * 2))]				!= '1')
			g->posy += g->dirx * SP;
	}
}

void	ft_rotate(t_game *g)
{
	double	olddirx;
	double	oldplanex;

	if (g->right)
	{
		olddirx = g->dirx;
		g->dirx = g->dirx * cos(-RS) - g->diry * sin(-RS);
		g->diry = olddirx * sin (-RS) + g->diry * cos(-RS);
		oldplanex = g->planex;
		g->planex = g->planex * cos(-RS) - g->planey * sin(-RS);
		g->planey = oldplanex * sin(-RS) + g->planey * cos(-RS);
	}
	else if (g->left)
	{
		olddirx = g->dirx;
		g->dirx = g->dirx * cos(RS) - g->diry * sin (RS);
		g->diry = olddirx * sin (RS) + g->diry * cos(RS);
		oldplanex = g->planex;
		g->planex = g->planex * cos(RS) - g->planey * sin(RS);
		g->planey = oldplanex * sin(RS) + g->planey * cos(RS);
	}
}

void	ft_set_dir(t_game *game)
{
	if (game->scene->dir == 'N')
	{
		game->dirx = -1.0;
		game->planey = 0.66;
	}
	else if (game->scene->dir == 'S')
	{
		game->dirx = 1.0;
		game->planey = -0.66;
	}
	else if (game->scene->dir == 'W')
	{
		game->diry = -1.0;
		game->planex = -0.66;
	}
	else
	{
		game->diry = 1.0;
		game->planex = 0.66;
	}
	ft_init_zbuffer(game);
}
