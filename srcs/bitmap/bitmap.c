/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 19:12:31 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/03 20:58:27 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <fcntl.h>

void	ft_write_header(t_game *game, int fd)
{
	int	tmp;

	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * game->scene->x_scr * game->scene->y_scr;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &game->scene->x_scr, 4);
	write(fd, &game->scene->y_scr, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &game->frame.bits_per_pixel, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

void	ft_write_img(int fd, t_game game)
{
	int	y;
	int	x;
	int	color;

	y = game.scene->y_scr - 1;
	while (y)
	{
		x = 0;
		while (x < game.scene->x_scr)
		{
			color = ft_get_pixel(game.frame, x, y);
			write(fd, &color, 4);
			x++;
		}
		y--;
	}
}

void	ft_save_bmp(t_scene *scene)
{
	int		fd;
	t_game	game;

	ft_log_task("Saving first frame.. ");
	game = ft_getfirst_frame(scene);
	fd = open("./save.bmp", O_CREAT | O_RDWR, 0777);
	if (fd < 0)
	{
		ft_log_ok(false);
		ft_log_error("Can't open file ./save.bmp");
		ft_clear_frame(&game);
	}
	ft_write_header(&game, fd);
	ft_write_img(fd, game);
	close(fd);
	ft_log_ok(true);
	ft_clear_frame(&game);
}
