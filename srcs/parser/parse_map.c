/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:11:24 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/14 17:42:08 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "errno.h"

int	ft_ismapchar(int c)
{
	char	*charset;

	charset = "102 NSEW";
	if (ft_christr(charset, c) == -1)
		return (0);
	else
		return (1);
}

static	void	ft_addline(t_scene *scene)
{
	char	**temp;
	char	**map;
	int		i;

	map = scene->map;
	temp = malloc((scene->sizey + 1) * sizeof (char *));
	if (!temp)
	{
		ft_free_scene(scene);
		ft_log_error(strerror(errno));
	}
	i = 0;
	while (i < scene->sizex)
	{
		temp[i] = map[i];
		i++;
	}
	free(scene->map);
	scene->map = temp;
	scene->sizey++;
}

static	void	ft_add_map_line(char **line, t_scene *scene)
{
	int		x;

	(scene->map)[scene->sizey] = *line;
	x = ft_strlen(*line);
	if (x > scene->sizex)
		scene->sizex = x;
	ft_addline(scene);
}

static	void	ft_fill_space(char **line, t_scene *scene)
{
	char	*temp;
	int		i;

	temp = malloc((scene->sizex + 1) * sizeof (char));
	if (!temp)
	{
		ft_free_scene(scene);
		ft_log_error(strerror(errno));
	}
	i = 0;
	while (line[i])
	{
		temp[i] = (*line)[i];
		i++;
	}
	while (i < scene->sizex)
		temp[i++] = ' ';
	temp[i] = '\0';
	*line = temp;
}

t_bool	ft_parse_map(char **line, t_scene *scene, int fd)
{
	int	r;
	int i = 0;

	scene->map = malloc(1 * sizeof (char **));
	ft_add_map_line(line, scene);
	r = 2;
	while (r > 0)
	{
		if (r != 2)
			ft_add_map_line(line, scene);
		r = ft_gnl(fd, line);
	}
	if (r == -1)
	{
		ft_free_scene(scene);
		ft_log_error(strerror(errno));
		exit(errno);
	}
	while (i < scene->sizey)
	{
		ft_fill_space(&(scene->map)[i], scene);
		i++;
	}
	i = 0;
	while (i < scene->sizey)
	{
		ft_printf("|%s|\n", (scene->map)[i]);
		i++;
	}
	ft_printf("max x: %i\n", scene->sizex);
	return (true);
}

