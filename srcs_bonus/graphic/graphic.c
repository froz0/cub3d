/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 22:24:09 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/04 12:31:42 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include <errno.h>

void		ft_clear_memory(t_game *game)
{
	ft_free_scene(game->scene);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}

int			ft_clear_frame(t_game *game)
{
	if (game->frame.img)
		mlx_destroy_image(game->mlx, game->frame.img);
	if (game->we_text.frame.img)
		mlx_destroy_image(game->mlx, game->we_text.frame.img);
	if (game->no_text.frame.img)
		mlx_destroy_image(game->mlx, game->no_text.frame.img);
	if (game->ea_text.frame.img)
		mlx_destroy_image(game->mlx, game->ea_text.frame.img);
	if (game->so_text.frame.img)
		mlx_destroy_image(game->mlx, game->so_text.frame.img);
	if (game->sprite.frame.img)
		mlx_destroy_image(game->mlx, game->sprite.frame.img);
	if (game->f_text.frame.img)
		mlx_destroy_image(game->mlx, game->f_text.frame.img);
	if (game->c_text.frame.img)
		mlx_destroy_image(game->mlx, game->c_text.frame.img);
	if (game->zbuffer)
		free(game->zbuffer);
	if (game->spriteorder)
		free(game->spriteorder);
	if (game->spritedist)
		free(game->spritedist);
	ft_clear_memory(game);
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

t_game		ft_getfirst_frame(t_scene *scene)
{
	t_game		game;

	ft_init_game(&game, scene);
	game.mlx = mlx_init();
	if (!game.mlx)
		ft_exit_str("Failed to connect to X server", scene, 5);
	ft_load_textures(&game);
	game.frame = ft_init_frame(&game);
	ft_render_frame(&game);
	return (game);
}

void		ft_graphic_handle(t_scene *scene)
{
	t_game		game;

	ft_init_game(&game, scene);
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
	ft_load_textures(&game);
	game.frame = ft_init_frame(&game);
	mlx_hook(game.win, 33, 0, ft_clear_frame, &game);
	mlx_hook(game.win, 2, 1L, ft_event_key, &game);
	mlx_hook(game.win, 3, 1L << 1, ft_event_key_release, &game);
	mlx_loop_hook(game.mlx, ft_next_frame, &game);
	mlx_loop(game.mlx);
}
