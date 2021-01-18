/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:30:52 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/18 13:00:26 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_displaymap_error(int posx, int posy, t_scene *scene)
{
	int	y;

	y = 0;
	while (y < scene->sizey)
	{
		if (y == posy)
		{
			write(2, scene->map[y], posx);
			ft_putstr_fd("\033[0;31m", 2);
			write(2, scene->map[y] + posx, 1);
			ft_putstr_fd("\033[0m", 2);
			ft_putstr_fd(scene->map[y] + posx + 1, 2);
			ft_putchar_fd('\n', 2);
		}
		else
			ft_dprintf(2, "%s\n", scene->map[y]);
		y++;
	}
}
