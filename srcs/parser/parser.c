/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 23:41:50 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/18 13:03:44 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_rgb	ft_init_rgb(int r, int g, int b)
{
	t_rgb	rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}

t_scene	ft_init_scene(void)
{
	t_scene	s;

	s.err = 0;
	s.x_scr = -1;
	s.y_scr = -1;
	s.no = 0;
	s.so = 0;
	s.we = 0;
	s.ea = 0;
	s.s = 0;
	s.f = ft_init_rgb(-1, -1, -1);
	s.c = ft_init_rgb(-1, -1, -1);
	s.sizex = 0;
	s.sizey = 0;
	s.map = 0;
	return (s);
}

static void	ft_parse_file_handle(int fd, t_scene *scene)
{
	int		result;

	ft_log_info("Reading scene's file..");
	result = ft_parse_file(fd, scene);
	ft_log_task("Reading scene's file: ");
	if (scene->err)
	{
		ft_free_scene(scene);
		ft_log_ok(0);
		ft_dprintf(2, "Error\n");
		ft_log_error("Unknow char encountered, exiting...");
		exit(1);
	}
	else
	{
		if (!result)
		{
			ft_log_ok(0);
			ft_free_scene(scene);
			ft_dprintf(2, "Error\n");
			ft_log_error("No map found");
			exit(1);
		}
		ft_log_ok(1);
	}
}

t_scene	ft_parse_scene(int fd)
{
	t_scene	scene;

	scene = ft_init_scene();
	ft_parse_file_handle(fd, &scene);
	ft_check_head(&scene);
	ft_log_info("Balancing map..");
	ft_balance_map(&scene);
	ft_log_task("Balancing map: ");
	ft_log_ok(true);
	ft_displaymap_error(15, 3, &scene);
	return (scene);
}
