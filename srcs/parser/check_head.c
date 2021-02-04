/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_head.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:30:43 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/04 13:30:15 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	ft_check_r(t_scene *scene)
{
	if (scene->x_scr == -1)
	{
		ft_log_error("R is not set");
		scene->err = 1;
	}
	if (scene->x_scr < 2)
		ft_log_error("R x is < 2, error");
	if (scene->y_scr < 2)
		ft_log_error("R y is < 2, error");
	if (scene->x_scr == -2)
	{
		ft_log_error("Problem with R");
		scene->err = 1;
	}
	if (scene->x_scr < 2 || scene->y_scr < 2)
		scene->err = 1;
}

static void	ft_check_texture(t_scene *scene)
{
	if (!scene->no)
		ft_log_warn("Texture [NO] is not set, fall back to default.");
	if (!scene->so)
		ft_log_warn("Texture [SO] is not set, fall back to default.");
	if (!scene->we)
		ft_log_warn("Texture [WE] is not set, fall back to default.");
	if (!scene->ea)
		ft_log_warn("Texture [EA] is not set, fall back to default.");
	if (!scene->s)
		ft_log_warn("Texture [S] is not set, fall back to default.");
}

static void	ft_check_rgb_value(t_rgb rgb, t_scene *scene)
{
	if (rgb.r < 0 || rgb.g < 0 || rgb.b < 0)
	{
		ft_log_error("Invalid value < 0 [RGB]");
		scene->err = 1;
	}
	if (rgb.r > 255 || rgb.g > 255 || rgb.b > 255)
	{
		ft_log_error("Invalid value > 255 [RGB]");
		scene->err = 1;
	}
}

static void	ft_check_rgb(t_scene *scene)
{
	if (scene->f.r == -1)
	{
		ft_log_warn("RGB [F] is not set");
		scene->err = 1;
	}
	if (scene->c.r == -1)
	{
		ft_log_warn("RGB [C] is not set");
		scene->err = 1;
	}
	if (scene->c.r == -2)
		ft_log_error("Error while parsing [C]");
	if (scene->f.r == -2)
		ft_log_error("Error while parsing [F]");
	if (scene->f.r == -2 || scene->c.r == -2)
		scene->err = 1;
	ft_check_rgb_value(scene->f, scene);
	ft_check_rgb_value(scene->c, scene);
}

void		ft_check_head(t_scene *scene)
{
	ft_check_r(scene);
	ft_check_texture(scene);
	ft_check_rgb(scene);
	ft_log_task("Checking the head's info: ");
	if (scene->err)
	{
		ft_log_ok(false);
		ft_dprintf(2, "Error\n");
		ft_log_error("Some infos are invalid, exiting...");
		ft_free_scene(scene);
		exit(1);
	}
	else
		ft_log_ok(true);
}
