/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:08:32 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/25 22:07:26 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include <errno.h>

static	int	ft_event_show(int key, t_to_free *to_free)
{
	ft_printf("key pressed: %#x\n", key);
	if (key == 0xff1b)
	{
		ft_free_scene(to_free->scene);
		mlx_destroy_window(to_free->mlx, to_free->win);
		mlx_destroy_display(to_free->mlx);
		free(to_free->mlx);
		exit(0);
	}
	return (0);
}

void	ft_graphic_handle(t_scene *scene)
{
	void		*mlx;
	void		*win;
	t_to_free	to_free;

	mlx = mlx_init();
	if (!mlx)
		ft_exit_str("Failed to connect to X server", scene, 5);
	win = mlx_new_window(mlx, scene->x_scr, scene->y_scr, "Cub3d");
	if (!win)
	{
		mlx_destroy_display(mlx);
		ft_exit_str("Failed to create the window", scene, 6);
	}
	to_free.win = win;
	to_free.mlx = mlx;
	to_free.scene = scene;
	mlx_key_hook(win, ft_event_show, &to_free);
	mlx_loop(mlx);
}
