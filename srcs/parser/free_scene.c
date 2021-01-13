/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:48:41 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/13 14:47:39 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_free_head(t_scene *scene)
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

void	ft_free_scene(t_scene *scene)
{
	ft_free_head(scene);
}
