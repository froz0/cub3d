/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:01:23 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/04 13:25:08 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include <stdio.h>

int	ft_event_key(unsigned int key, t_game *game)
{
	if (key == 0xff1b)
		ft_clear_frame(game);
	else if (key == 0x77)
		game->w = true;
	else if (key == 0x73)
		game->s = true;
	else if (key == 0x61)
		game->a = true;
	else if (key == 0x64)
		game->d = true;
	else if (key == 0xff53)
		game->right = true;
	else if (key == 0xff51)
		game->left = true;
	return (0);
}

int	ft_event_key_release(unsigned int key, t_game *game)
{
	if (key == 0x77)
		game->w = false;
	else if (key == 0x73)
		game->s = false;
	else if (key == 0x61)
		game->a = false;
	else if (key == 0x64)
		game->d = false;
	else if (key == 0xff53)
		game->right = false;
	else if (key == 0xff51)
		game->left = false;
	return (0);
}
