/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:11:24 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/03 22:32:01 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "errno.h"

static	void	ft_add_line(t_scene *scene)
{
	char	**temp;
	int		i;

	temp = malloc((scene->sizey + 1) * sizeof(char **));
	if (!temp)
		ft_exit_str(strerror(errno), scene, errno);
	i = 0;
	while (i < scene->sizey)
	{
		temp[i] = scene->map[i];
		i++;
	}
	if (scene->map)
		free(scene->map);
	scene->map = temp;
}

void			ft_parse_map_line(char *line, t_scene *scene)
{
	static t_bool	used_once = false;
	int				strlen;

	if (!used_once)
	{
		used_once = true;
		ft_log_info("Parsing the map..");
	}
	ft_add_line(scene);
	strlen = ft_strlen(line);
	if (strlen > scene->sizex)
		scene->sizex = strlen;
	(scene->map)[scene->sizey++] = line;
}

void			ft_balance_map(t_scene *scene)
{
	int		x;
	int		y;
	char	*temp;

	y = -1;
	while (++y < scene->sizey)
	{
		if ((int)ft_strlen(scene->map[y]) < scene->sizex)
		{
			temp = malloc((scene->sizex + 1) * sizeof(char));
			if (!temp)
				ft_exit_str(strerror(errno), scene, errno);
			x = 0;
			while (scene->map[y][x])
			{
				temp[x] = scene->map[y][x];
				x++;
			}
			while (x < scene->sizex)
				temp[x++] = ' ';
			temp[x] = '\0';
			free(scene->map[y]);
			scene->map[y] = temp;
		}
	}
}
