/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_head.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:10:12 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/03 22:33:15 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <errno.h>

static	t_bool	ft_handle_line(char *line, t_scene *s)
{
	if (ft_strncmp(line, "R", 1) == 0)
		ft_parse_r(line + 1, s);
	else if (ft_strncmp(line, "NO", 2) == 0)
		ft_parse_texture(&s->no, line);
	else if (ft_strncmp(line, "SO", 2) == 0)
		ft_parse_texture(&s->so, line);
	else if (ft_strncmp(line, "WE", 2) == 0)
		ft_parse_texture(&s->we, line);
	else if (ft_strncmp(line, "EA", 2) == 0)
		ft_parse_texture(&s->ea, line);
	else if (ft_strncmp(line, "S", 1) == 0)
		ft_parse_texture(&s->s, line);
	else if (ft_strncmp(line, "F", 1) == 0)
		s->f = ft_parse_rgb(line + 1);
	else if (ft_strncmp(line, "C", 1) == 0)
		s->c = ft_parse_rgb(line + 1);
	else
		return (false);
	return (true);
}

t_bool			ft_parse_line(char *line, t_scene *scene, t_bool is_map)
{
	size_t	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (is_map || !ft_handle_line(line + i, scene))
	{
		if (is_map || ft_ismapchar(line[i]))
		{
			ft_parse_map_line(line, scene);
			return (true);
		}
		else if (line[i] != 0)
		{
			ft_dprintf(2, "Unknow char -> %s\n", line);
			scene->err = 1;
		}
	}
	return (false);
}

t_bool			ft_parse_file(int fd, t_scene *scene)
{
	char	*line;
	int		r;
	t_bool	map_found;

	map_found = false;
	r = 2;
	while (r > 0)
	{
		if (r != 2)
		{
			if (!scene->err)
				map_found = ft_parse_line(line, scene, map_found);
			if (!map_found)
				free(line);
		}
		r = ft_gnl(fd, &line);
	}
	if (r == -1)
	{
		ft_free_scene(scene);
		ft_log_error(strerror(errno));
		exit(errno);
	}
	return (map_found);
}
