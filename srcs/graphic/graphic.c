/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:08:32 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/26 19:15:11 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include <errno.h>

void	ft_clear_memory(t_game *game)
{
	ft_free_scene(game->scene);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

static	int	ft_nextframe(t_game *game)
{
	t_frame frame;

	frame = ft_render_frame(*game);
    mlx_put_image_to_window(game->mlx, game->win, frame.img, 0, 0);
	mlx_destroy_image(game->mlx, frame.img);
	return (0);
}

t_game	ft_init_game(t_scene *scene)
{
	t_game	game;

	game.player_x = scene->player.x;
	game.player_y = scene->player.y;
	game.mlx = NULL;
	game.win = NULL;
	game.dir_x = -1;
	game.dir_y = 0;
	game.plane_x = 0;
	game.plane_y = 0.66;
	return (game);
}

void	ft_graphic_handle(t_scene *scene)
{
	t_game	game;

	game = ft_init_game(scene);
	game.mlx = mlx_init();
	if (!game.mlx)
		ft_exit_str("Failed to connect to X server", scene, 5);
	game.win = mlx_new_window(game.mlx, scene->x_scr,
			scene->y_scr, "Cub3d");
	if (!game.win)
	{
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		ft_exit_str("Failed to create the window", scene, 6);
	}
	game.scene = scene;
	mlx_hook(game.win, 33, 0, ft_event_exit, &game);
	mlx_hook(game.win, 2, 1L, ft_event_key, &game);
    mlx_loop_hook(game.mlx, ft_nextframe, &game);
	mlx_loop(game.mlx);
}
