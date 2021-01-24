/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:08:32 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/24 14:35:02 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include <errno.h>

void	ft_graphic_handle(t_scene scene)
{
	void	*mlx;
	void	*windows;

	mlx = mlx_init();
	if (!mlx)
		ft_exit_str("Failed to connect to X server", &scene, 5);
	windows = mlx_new_window(mlx, scene.x_scr, scene.y_scr, "Cub3d");
	if (!windows)
	{
		free(mlx);
		ft_exit_str("Failed to create the window", &scene, 6);
	}
	mlx_loop(mlx);
}
