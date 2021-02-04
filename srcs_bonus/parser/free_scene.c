/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:48:41 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/03 22:33:37 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static	void	ft_free_head(t_scene *scene)
{
	if (scene->no)
		free(scene->no);
	if (scene->so)
		free(scene->so);
	if (scene->we)
		free(scene->we);
	if (scene->ea)
		free(scene->ea);
	if (scene->s)
		free(scene->s);
}

static	void	ft_free_map(t_scene *scene)
{
	int		i;

	i = 0;
	while (i < scene->sizey)
	{
		free(scene->map[i]);
		i++;
	}
	scene->sizey = 0;
	if (scene->map)
		free(scene->map);
	scene->map = NULL;
}

static	void	ft_free_sprite(t_scene *scene)
{
	scene->numsprite = 0;
	if (scene->sprites)
		free(scene->sprites);
	scene->sprites = NULL;
}

void			ft_free_scene(t_scene *scene)
{
	ft_free_head(scene);
	ft_free_map(scene);
	ft_free_sprite(scene);
}

void			ft_exit_str(char *strerror, t_scene *scene, int errno)
{
	ft_log_error(strerror);
	ft_free_scene(scene);
	exit(errno);
}
