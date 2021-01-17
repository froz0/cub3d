/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:11:24 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/17 13:01:17 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "errno.h"

int	ft_ismapchar(int c)
{
	char	*charset;

	charset = "102";
	if (ft_christr(charset, c) == -1)
		return (0);
	else
		return (1);
}

static	void	ft_add_line(t_scene *scene)
{
	char	**temp;
	int		i;

	temp = malloc((scene->sizey + 1) * sizeof(char **));
	if (!temp)
	{
		ft_log_error(strerror(errno));
		ft_free_scene(scene);
		exit(errno);
	}
	i = 0;
	while (i < scene->sizey)
	{
		temp[i] = scene->map[i];
		i++;
	}
	free(scene->map);
	scene->map = temp;
}

void	ft_parse_map_line(char *line, t_scene *scene)
{
	static t_bool	used_once = false;

	if (!used_once)
	{
		used_once = true;
		ft_log_info("Parsing the map..");
	}
	ft_add_line(scene);
	(scene->map)[scene->sizey++] = line;
}
