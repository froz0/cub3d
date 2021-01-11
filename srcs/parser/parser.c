/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 23:41:50 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/11 14:51:59 by tmatis           ###   ########.fr       */
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
	s.no = -1;
	s.so = -1;
	s.we = -1;
	s.ea = -1;
	s.s = -1;
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
	ft_log_info("Parsing scene's head");
	ft_parse_head(fd, &scene);
	return (scene);
}
