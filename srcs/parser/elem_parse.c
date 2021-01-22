/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:12:59 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/22 15:49:48 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "limits.h"

static int	ft_basic_atoi(char *str)
{
	unsigned int i;

	i = 0;
	while (*str && ft_isnum(*str))
		i = i * 10 + (*str++) + 48;
	if (i > INT_MAX)
		return (-2);
	return ((int)i);
}

void	ft_parse_r(char *line, t_scene *scene)
{
	while (ft_isspace(*line))
		line++;
	scene->x_scr = ft_basic_atoi(line);
	while (ft_isnum(*line))
		line++;
	while (ft_isspace(*line))
		line++;
	scene->y_scr = ft_basic_atoi(line);
}

static	int	ft_skip(char **line)
{
	int	vir;

	vir = 0;
	while (ft_isnum(**line))
		(*line)++;
	while (ft_isspace(**line))
		(*line)++;
	if (**line == ',' && ++vir)
		(*line)++;
	while (ft_isspace(**line))
		(*line)++;
	if (**line == ',' && !vir)
		(*line)++;
	while (ft_isspace(**line))
		(*line)++;
	if (!ft_isnum(**line))
		return (1);
	return (0);
}

t_rgb	ft_parse_rgb(char *line)
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

void	ft_parse_texture(char **path, char *line)
{
	int	i;

	if (ft_strncmp(line, "NO", 2)
		|| ft_strncmp(line, "SO", 2)
		|| ft_strncmp(line, "WE", 2)
		|| ft_strncmp(line, "EA", 2))
		i = 1;
	else
		i = 0;
	if (!*path)
		*path = ft_strtrim(&line[i], " \t\v");
	else
	{
		ft_putstr_fd("\n[\033[0;33mWARN\x1b[0m]", 2);
		ft_putstr_fd(" Redefinition of texture [", 2);
		ft_putchar_fd(line[0], 2);
		if (i == 1)
			ft_putchar_fd(line[1], 2);
		ft_putstr_fd("], ignoring...\n", 2);
	}
}
