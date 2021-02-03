/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:05:03 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/03 22:32:56 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "errno.h"

void	ft_parse_sprite(int x, int y, t_scene *scene)
{
	t_sprite	*dest;
	int			i;

	dest = malloc((scene->numsprite + 1) * sizeof(t_sprite));
	if (!dest)
		ft_exit_str(strerror(errno), scene, errno);
	i = 0;
	while (i < scene->numsprite)
	{
		dest[i] = scene->sprites[i];
		i++;
	}
	if (scene->sprites)
		free(scene->sprites);
	dest[i].x = y;
	dest[i].y = x;
	scene->sprites = dest;
	scene->numsprite++;
}
