/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 14:00:57 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/17 23:47:02 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>  

static	int	ft_verify_cub(char *filename)
{
	char	*find;

	find = ft_strrchr(filename, '.');
	if (!find || ft_strcmp(find, ".cub"))
	{
		ft_log_error("Map is not a *.cub, exiting...");
		exit(1);
	}
	ft_log_info("Opening scene...");
	return (open(filename, O_RDONLY));
}

static t_args	ft_parseargs(int argc, char **argv)
{
	t_args	args;

	args.save = 0;
	if (argc > 2)
	{
		ft_log_error("Too mutch parameters, exiting...");
		ft_log_info("Usage: ./cub3d <path/map.cub> [--save]");
		exit(1);
	}
	else if (argc < 1)
	{
		ft_log_error("Too less parameters, exiting...");
		ft_log_info("Usage: ./cub3d <path/map.cub> [--save]");
		exit(1);
	}
	if (argc > 1 && (ft_strcmp(argv[1], "--save")))
	{
		ft_log_warn("Unknow 2nd parameter, ignoring...");
		ft_log_info("Usage: ./cub3d <path/map.cub> [--save]");
	}
	else if (argc > 1)
		args.save = 1;
	args.fd = ft_verify_cub(argv[0]);
	return (args);
}

int	main(int argc, char **argv)
{
	t_args	args;
	t_scene	scene;

	args = ft_parseargs(argc - 1, argv + 1);
	if (args.fd < 0)
	{
		ft_log_error(strerror(errno));
		exit(errno);
	}
	ft_log_info("Parsing the scene...");
	scene = ft_parse_scene(args.fd);
	ft_free_scene(&scene);
	close(args.fd);
}
