/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:08:32 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/26 14:57:09 by tmatis           ###   ########.fr       */
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
void	ft_graphic_handle(t_scene *scene)
{
	void		*mlx;
	void		*win;
	t_game_state	game_state;

	mlx = mlx_init();
	if (!mlx)
		ft_exit_str("Failed to connect to X server", scene, 5);
	win = mlx_new_window(mlx, scene->x_scr, scene->y_scr, "Cub3d");
	if (!win)
	{
		mlx_destroy_display(mlx);
		ft_exit_str("Failed to create the window", scene, 6);
	}
	game_state.win = win;
	game_state.mlx = mlx;
	game_state.scene = scene;
	mlx_hook(win, 33, 0, ft_event_exit, &game_state);
	mlx_hook(win, 2, 1L, ft_event_key, &game_state);
	mlx_loop(mlx);
}
