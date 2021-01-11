/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_head.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:10:12 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/11 19:17:19 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <errno.h>

static void	ft_parse_r(char *line, t_scene *scene)
{
	while (ft_isspace(*line))
		line++;
	scene->x_scr = ft_atoi(line);
	while (ft_isnum(*line))
		line++;
	while (ft_isspace(*line))
		line++;
	scene->y_scr = ft_atoi(line);
}

static	int	ft_skip(char **line)
{
	int	vir;

	vir = 0;
	while (ft_isnum(**line))
		(*line)++;
	if (**line == ',' && ++vir)
		(*line)++;
	while (ft_isspace(**line))
		(*line)++;
	if (**line == ',' && !vir)
		(*line)++;
	if (!ft_isnum(**line))
		return (1);
	return (0);
}

static	t_rgb	ft_parse_rgb(char *line)
{
	int		r;
	int		g;
	int		b;
	int		error;

	error = 0;
	while (ft_isspace(*line))
		line++;
	if (!ft_isnum(*line))
		error += 1;
	r = ft_atoi(line);
	error += ft_skip(&line);
	g = ft_atoi(line);
	error += ft_skip(&line);
	b = ft_atoi(line);
	if (error)
		return (ft_init_rgb(-2, -2, -2));
	else
		return (ft_init_rgb(r, g, b));
}

void	ft_parse_line(char *line, t_scene *scene)
{
	while (ft_isspace(*line))
		line++;
	if (ft_strncmp(line, "R", 1) == 0)
		ft_parse_r(line + 1, scene);
	else if (ft_strncmp(line, "NO", 1) == 0)
		scene->no = ft_strtrim(line + 2, " \t\v");
	else if (ft_strncmp(line, "SO", 1) == 0)
		scene->so = ft_strtrim(line + 2, " \t\v");
	else if (ft_strncmp(line, "WE", 1) == 0)
		scene->we = ft_strtrim(line + 2, " \t\v");
	else if (ft_strncmp(line, "EA", 1) == 0)
		scene->ea = ft_strtrim(line + 2, " \t\v");
	else if (ft_strncmp(line, "S", 1) == 0)
		scene->s = ft_strtrim(line + 1, " \t\v");
	else if (ft_strncmp(line, "F", 1) == 0)
		scene->f = ft_parse_rgb(line + 1);
	else if (ft_strncmp(line, "C", 1) == 0)
		scene->c = ft_parse_rgb(line + 1);
	else
		scene->err = 1;
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
			if (!scene->err)
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
