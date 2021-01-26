/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:08:32 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/26 16:08:01 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include <errno.h>

void	ft_clear_memory(t_game_state *game_state)
{
	ft_free_scene(game_state->scene);
	mlx_destroy_window(game_state->mlx, game_state->win);
	mlx_destroy_display(game_state->mlx);
	free(game_state->mlx);
	exit(0);
}

static	int	ft_event_key(unsigned int key, t_game_state *game_state)
{
	ft_printf("key pressed: %#x\n", key);
	if (key == 0xff1b)
		ft_clear_memory(game_state);
	return (0);
}

static int	ft_event_exit(t_game_state *game_state)
{
	ft_clear_memory(game_state);
	return (0);
}

static	int	ft_nextframe(t_game_state *game_state)
{
	t_frame frame;

	frame = ft_render_frame(*game_state);
    mlx_put_image_to_window(game_state->mlx, game_state->win, frame.img, 0, 0);
	mlx_destroy_image(game_state->mlx, frame.img);
	return (0);
}

void	ft_graphic_handle(t_scene *scene)
{
	t_game_state	game_state;

	game_state.mlx = mlx_init();
	if (!game_state.mlx)
		ft_exit_str("Failed to connect to X server", scene, 5);
	game_state.win = mlx_new_window(game_state.mlx, scene->x_scr,
			scene->y_scr, "Cub3d");
	if (!game_state.win)
	{
		mlx_destroy_display(game_state.mlx);
		free(game_state.mlx);
		ft_exit_str("Failed to create the window", scene, 6);
	}
	game_state.scene = scene;
	mlx_hook(game_state.win, 33, 0, ft_event_exit, &game_state);
	mlx_hook(game_state.win, 2, 1L, ft_event_key, &game_state);
    mlx_loop_hook(game_state.mlx, ft_nextframe, &game_state);
	mlx_loop(game_state.mlx);
}
