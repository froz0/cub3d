/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:10:12 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/03 13:02:33 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

t_frame	ft_init_frame(t_game *game)
{
	t_frame	frame;

	frame.img = mlx_new_image(game->mlx, game->scene->x_scr,
			game->scene->y_scr);
	if (!frame.img)
	{
		ft_log_error("Unable to create frame");
		ft_clear_memory(game);
	}
	frame.addr = mlx_get_data_addr(frame.img, &frame.bits_per_pixel,
			&frame.line_length, &frame.endian);
	return (frame);
}

static	void	ft_init_sprites(t_game *game)
{
	game->zbuffer = malloc(game->scene->x_scr * sizeof (double));
	if (!game->zbuffer)
	{
		ft_log_error("zbuffer malloc has failed");
		ft_clear_frame(game);
	}
	game->spriteorder = malloc(game->scene->numsprite * sizeof (int));
	if (!game->zbuffer)
	{
		ft_log_error("spriteorder malloc has failed");
		ft_clear_frame(game);
	}
	game->spritedist = malloc(game->scene->numsprite * sizeof (double));
	if (!game->spritedist)
	{
		ft_log_error("spriteorder malloc has failed");
		ft_clear_frame(game);
	}
}

static	void	ft_init_dir(t_game *game)
{
	if (game->scene->dir == 'N')
	{
		game->dirx = -1.0;
		game->planey = 0.66;
	}
	else if (game->scene->dir == 'S')
	{
		game->dirx = 1.0;
		game->planey = -0.66;
	}
	else if (game->scene->dir == 'W')
	{
		game->diry = -1.0;
		game->planex = -0.66;
	}
	else
	{
		game->diry = 1.0;
		game->planex = 0.66;
	}
}

static	void	ft_init_key(t_game *game)
{
	game->w = false;
	game->a = false;
	game->s = false;
	game->d = false;
	game->right = false;
	game->left = false;
}

void	ft_init_game(t_game *game, t_scene *scene)
{
	game->scene = scene;
	game->posx = scene->player.x + 0.5;
	game->posy = scene->player.y + 0.5;
	game->mlx = NULL;
	game->win = NULL;
	game->dirx = 0;
	game->diry = 0;
	game->planey = 0;
	game->planex = 0;
	game->we_text.frame.img = NULL;
	game->ea_text.frame.img = NULL;
	game->so_text.frame.img = NULL;
	game->no_text.frame.img = NULL;
	game->sprite.frame.img = NULL;
	game->frame.img = NULL;
	game->zbuffer = NULL;
	game->spriteorder = NULL;
	game->spritedist = NULL;
	ft_init_key(game);
	ft_init_dir(game);
	ft_init_sprites(game);
}
