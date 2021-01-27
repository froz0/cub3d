/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:01:23 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/26 19:06:01 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

int	ft_event_key(unsigned int key, t_game *game)
{
	ft_printf("key pressed: %#x\n", key);
	if (key == 0xff1b)
		ft_clear_memory(game);
	return (0);
}

int	ft_event_exit(t_game *game)
{
	ft_clear_memory(game);
	return (0);
}
