/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_head.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:10:12 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/13 14:50:21 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <errno.h>

t_bool	ft_parse_line(char *line, t_scene *scene)
{
	while (ft_isspace(*line))
		line++;
	if (ft_strncmp(line, "R", 1) == 0)
		ft_parse_r(line + 1, scene);
	else if (ft_strncmp(line, "NO", 2) == 0)
		ft_parse_texture(&scene->no, line);
	else if (ft_strncmp(line, "SO", 2) == 0)
		ft_parse_texture(&scene->so, line);
	else if (ft_strncmp(line, "WE", 2) == 0)
		ft_parse_texture(&scene->we, line);
	else if (ft_strncmp(line, "EA", 2) == 0)
		ft_parse_texture(&scene->ea, line);
	else if (ft_strncmp(line, "S", 1) == 0)
		ft_parse_texture(&scene->s, line);
	else if (ft_strncmp(line, "F", 1) == 0)
		scene->f = ft_parse_rgb(line + 1);
	else if (ft_strncmp(line, "C", 1) == 0)
		scene->c = ft_parse_rgb(line + 1);
	else if (ft_ismapchar(*line))
		return (true);
	else if (*line != 0)
		scene->err = 1;
	return (false);
}

t_bool	ft_parse_head(int fd, t_scene *scene)
{
	char	*line;
	int		r;
	int		mapfound;

	mapfound = 0;
	r = 2;
	while (r > 0)
	{
		if (r != 2)
		{
			if (!scene->err)
				mapfound = ft_parse_line(line, scene);
			free(line);
		}
		r = ft_gnl(fd, &line);
	}
	if (r == 0)
		free(line);
	else if (r == -1)
	{
		ft_free_head(scene);
		ft_log_error(strerror(errno));
		exit(errno);
	}
	return (mapfound);
}
