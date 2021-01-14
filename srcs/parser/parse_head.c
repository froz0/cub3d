/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_head.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:10:12 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/14 17:33:53 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <errno.h>

t_bool	ft_parse_line(char **line, t_scene *scene, int fd)
{
	size_t	i;

	i = 0;
	while (ft_isspace((*line)[i]))
		i++;
	if (ft_strncmp(*line + i, "R", 1) == 0)
		ft_parse_r(*line + i + 1, scene);
	else if (ft_strncmp(*line + i, "NO", 2) == 0)
		ft_parse_texture(&scene->no, *line + i);
	else if (ft_strncmp(*line + i, "SO", 2) == 0)
		ft_parse_texture(&scene->so, *line + i);
	else if (ft_strncmp(*line + i, "WE", 2) == 0)
		ft_parse_texture(&scene->we, *line + i);
	else if (ft_strncmp(*line + i, "EA", 2) == 0)
		ft_parse_texture(&scene->ea, *line + i);
	else if (ft_strncmp(*line + i, "S", 1) == 0)
		ft_parse_texture(&scene->s, *line + i);
	else if (ft_strncmp(*line + i, "F", 1) == 0)
		scene->f = ft_parse_rgb(*line + 1 + i);
	else if (ft_strncmp(*line + i, "C", 1) == 0)
		scene->c = ft_parse_rgb(*line + 1 + i);
	else if (ft_ismapchar((*line)[i]))
		return (ft_parse_map(line, scene, fd));
	else if (*line != 0)
		scene->err = 1;
	return (false);
}

t_bool	ft_parse_head(int fd, t_scene *scene)
{
	char	*line;
	int		r;
	int		result;

	r = 2;
	while (r > 0)
	{
		if (r != 2)
		{
			if (!scene->err)
				result = ft_parse_line(&line, scene, fd);
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
	return (result);
}
