/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_head.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:30:43 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/18 00:02:20 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	ft_check_r(t_scene *scene)
{
	if (scene->x_scr == -1)
	{
		ft_log_warn("R is not set, back to 200x200");
		scene->x_scr = 200;
		scene->y_scr = 200;
	}
	if (scene->x_scr < 2)
		ft_log_error("R x is < 2, error");
	if (scene->x_scr < 2)
		ft_log_error("R y is < 2, error");
	if (scene->x_scr < 2 || scene->x_scr < 2)
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

static void	ft_check_rgb(t_scene *scene)
{
	if (scene->f.r == -1)
	{
		ft_log_warn("RGB [F] is not set fall back to default value 255,0,0");
		scene->f.r = 255;
		scene->f.g = 0;
		scene->f.b = 0;
	}
	if (scene->c.r == -1)
	{
		ft_log_warn("RGB [C] is not set fall back to default value 0,0,255");
		scene->f.r = 0;
		scene->f.g = 0;
		scene->f.b = 255;
	}
	if (scene->c.r == -2)
		ft_log_error("Error while parsing [C]");
	if (scene->f.r == -2)
		ft_log_error("Error while parsing [F]");
	if (scene->f.r == -2 || scene->c.r == -2)
		scene->err = 1;
}

void	ft_check_head(t_scene *scene)
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