/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 14:52:20 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/04 12:38:40 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void			ft_frame_pixel(t_frame f, int x, int y, int color)
{
	char	*dst;

	dst = f.addr + (y * f.line_length + x * (f.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned	int	ft_get_pixel(t_frame f, int x, int y)
{
	char	*dst;

	dst = f.addr + (y * f.line_length + x * (f.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

t_texture		ft_load_texture(char *path, t_game *game)
{
	t_frame		frame;
	t_texture	text;

	frame.img = mlx_xpm_file_to_image(game->mlx,
			path, &text.width, &text.height);
	if (!frame.img)
	{
		ft_log_error("Failed to load texture");
		ft_dprintf(2, "Path: %s\n", path);
		ft_clear_frame(game);
	}
	frame.addr = mlx_get_data_addr(frame.img, &frame.bits_per_pixel,
			&frame.line_length, &frame.endian);
	text.frame = frame;
	return (text);
}

void			ft_load_textures(t_game *game)
{
	game->no_text = ft_load_texture(game->scene->no, game);
	game->we_text = ft_load_texture(game->scene->we, game);
	game->ea_text = ft_load_texture(game->scene->ea, game);
	game->so_text = ft_load_texture(game->scene->so, game);
	game->sprite = ft_load_texture(game->scene->s, game);
	game->c_text = ft_load_texture("./texture/cell.xpm", game);
	game->f_text = ft_load_texture("./texture/floor.xpm", game);
}
