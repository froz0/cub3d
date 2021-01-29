/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20.05/01/24 14:08:32 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/29 16:38:30 by tmatis           ###   ########.fr       */
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

int		ft_clear_frame(t_game *game)
{
	mlx_destroy_image(game->mlx, game->frame.img);
	ft_clear_texture(game);
	return (0);
}

static	int	ft_next_frame(t_game *game)
{
	ft_walk(game);
	ft_straft(game);
	ft_rotate(game);
	ft_render_frame(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
	return (0);
}

t_game	ft_init_game(t_scene *scene)
{
	t_game	game;

	game.posx = scene->player.x + 0.5;
	game.posy = scene->player.y + 0.5;
	game.mlx = NULL;
	game.win = NULL;
	game.dirx = -1;
	game.diry = 0;
	game.planex = 0;
	game.planey = 0.66;
	game.w = false;
	game.a = false;
	game.s = false;
	game.d = false;
	game.right = false;
	game.left = false;
	return (game);
}

void	ft_graphic_handle(t_scene *scene)
{
	t_game		game;

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
	game.we_text = ft_load_texture(scene->we, &game);
	game.frame = ft_init_frame(&game);
	mlx_hook(game.win, 33, 0, ft_clear_frame, &game);
	mlx_hook(game.win, 2, 1L, ft_event_key, &game);
	mlx_hook(game.win, 3, 1L<<1, ft_event_key_release, &game);
    mlx_loop_hook(game.mlx, ft_next_frame, &game);
	mlx_loop(game.mlx);
}
