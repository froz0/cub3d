/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 01:23:51 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/03 22:25:38 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "math.h"

void	ft_walk(t_game *g)
{
	if (g->w)
	{
		g->posx += g->dirx * WS;
		g->posy += g->diry * WS;
	}
	else if (g->s)
	{
		g->posx -= g->dirx * WS;
		g->posy -= g->diry * WS;
	}
}

void	ft_straft(t_game *g)
{
	if (g->d)
	{
		g->posx += g->diry * SP;
		g->posy -= g->dirx * SP;
	}
	else if (g->a)
	{
		g->posx -= g->diry * SP;
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
		g->diry = olddirx * sin(-RS) + g->diry * cos(-RS);
		oldplanex = g->planex;
		g->planex = g->planex * cos(-RS) - g->planey * sin(-RS);
		g->planey = oldplanex * sin(-RS) + g->planey * cos(-RS);
	}
	else if (g->left)
	{
		olddirx = g->dirx;
		g->dirx = g->dirx * cos(RS) - g->diry * sin(RS);
		g->diry = olddirx * sin(RS) + g->diry * cos(RS);
		oldplanex = g->planex;
		g->planex = g->planex * cos(RS) - g->planey * sin(RS);
		g->planey = oldplanex * sin(RS) + g->planey * cos(RS);
	}
}
