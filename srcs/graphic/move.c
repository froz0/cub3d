/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 01:23:51 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/02 17:19:38 by tmatis           ###   ########.fr       */
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


