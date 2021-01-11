/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 23:41:50 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/11 18:15:09 by tmatis           ###   ########.fr       */
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
	s.x_scr = 0;
	s.y_scr = 0;
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

t_scene	ft_parse_scene(int fd)
{
	t_scene	scene;

	scene = ft_init_scene();
	ft_log_task("Parsing scene's head.. ");
	ft_parse_head(fd, &scene);
	if (scene.err)
	{
		ft_log_ok(0);
		ft_dprintf(2, "Error\n");
		ft_log_error("Unknow char encountered, exiting...");
	}
	else
		ft_log_ok(1);
	return (scene);
}
