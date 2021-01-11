/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_head.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:10:12 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/11 14:48:40 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <errno.h>

static void	ft_parse_r(char *line, t_scene *scene)
{
	ft_log_info("R found, parsing...");
	while (ft_isspace(*line))
		line++;
	scene->x_scr = ft_atoi(line);
	while (ft_isspace(*line))
		line++;
	scene->y_scr = ft_atoi(line);
}

void	ft_parse_line(char *line, t_scene *scene)
{
	while (ft_isspace(*line))
		line++;
	if (ft_strncmp(line, "R", 1) == 0)
		ft_parse_r(line, scene);
	else
	{
		ft_log_error("Scene head is invalid, exiting...");
		exit(1);
	}
}

void	ft_parse_head(int fd, t_scene *scene)
{
	char	*line;
	int		r;

	r = 2;
	while (r > 0)
	{
		if (r != 2)
		{
			ft_parse_line(line, scene);
			free(line);
		}
		r = ft_gnl(fd, &line);
	}
	if (r == 0)
		free(line);
	else if (r == -1)
	{
		ft_dprintf(2, "Error\n");
		ft_log_error("Error while reading the scene, exiting...");
		ft_log_error(strerror(errno));
		exit(errno);
	}
}
