/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:37:21 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/03 23:23:55 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include <math.h>

void		ft_render_raycast(t_game *game)
{
	t_ray		ray;
	int			x;
	int			color;
	int			y;
	double		texy;

	x = 0;
	while (x < game->scene->x_scr)
	{
		ft_calc_raydir(game, &ray, x);
		ft_calc_sidedist(game, &ray);
		ray.perpwalldist = ft_calc_dist(game, &ray);
		ft_calc_draw(game, &ray);
		y = ray.drawstart;
		while (y < ray.drawend)
		{
			texy = (int)ray.texpos & (ray.tex.height - 1);
			ray.texpos += ray.step;
			color = ft_get_pixel(ray.tex.frame, ray.texx, texy);
			ft_frame_pixel(game->frame, x, y, color);
			y++;
		}
		game->zbuffer[x++] = ray.perpwalldist;
	}
}
