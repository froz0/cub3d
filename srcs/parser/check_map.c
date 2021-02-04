/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:30:52 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/04 15:47:13 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static	void	ft_displaymap_error(int posx, int posy, t_scene *scene)
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

static t_bool	ft_check_arround(int posx, int posy, t_scene *scene)
{
	if (posx == 0 || posy == 0 || posy + 1 == scene->sizey
		|| posx + 1 == scene->sizex)
		return (false);
	if (!ft_ischarok(scene->map[posy - 1][posx]))
		return (false);
	if (!ft_ischarok(scene->map[posy + 1][posx]))
		return (false);
	if (!ft_ischarok(scene->map[posy][posx - 1]))
		return (false);
	if (!ft_ischarok(scene->map[posy][posx + 1]))
		return (false);
	return (true);
}

static	void	ft_maperr(int posx, int posy, t_scene *scene, char *reason)
{
	ft_log_ok(false);
	ft_dprintf(2, "Error\n");
	ft_log_error(reason);
	ft_displaymap_error(posx, posy, scene);
	ft_free_scene(scene);
	exit(2);
}

/*
** TODO: PLayer orientation
*/

static	t_bool	ft_player_pos(int posx, int posy, t_scene *scene)
{
	char			c;

	c = scene->map[posy][posx];
	if ((c == 'W' || c == 'N' || c == 'S' || c == 'E'))
	{
		if (scene->player.x == -1)
		{
			scene->player.x = posy;
			scene->player.y = posx;
			scene->dir = c;
			return (true);
		}
		return (false);
	}
	else
		return (true);
}

void			ft_check_map(t_scene *scene)
{
	int	y;
	int	x;

	y = -1;
	while (++y < scene->sizey)
	{
		x = -1;
		while (++x < scene->sizex)
		{
			if (ft_ismapchar(scene->map[y][x]))
			{
				if (ft_should_surround(scene->map[y][x])
					&& !ft_check_arround(x, y, scene))
					ft_maperr(x, y, scene, "open here or invallid char arround:");
				if (!ft_player_pos(x, y, scene))
					ft_maperr(x, y, scene, "More than one player:");
				if (scene->map[y][x] == '2')
					ft_parse_sprite(x, y, scene);
			}
			else
				ft_maperr(x, y, scene, "Unknow char in map.");
		}
	}
	if (scene->player.x == -1)
		ft_maperr(1, 1, scene, "No player in map");
}
