/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 23:39:38 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/02 19:20:46 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H

# define PARSER_H

# include "../cub3d.h"

t_scene	ft_parse_scene(int fd);
t_rgb	ft_init_rgb(int r, int g, int b);
void	ft_free_scene(t_scene *scene);
void	ft_parse_r(char *line, t_scene *scene);
t_rgb	ft_parse_rgb(char *line);
void	ft_parse_texture(char **path, char *line);
void	ft_check_head(t_scene *scene);
t_bool	ft_parse_file(int fd, t_scene *scene);
void	ft_exit_str(char *strerror, t_scene *scene, int errno);
void	ft_parse_map_line(char *line, t_scene *scene);
void	ft_balance_map(t_scene *scene);
void	ft_check_map(t_scene *scene);
t_bool	ft_ismapchar(int c);
t_bool	ft_should_surround(int c);
void	ft_parse_sprite(int	x, int y, t_scene *scene);
t_bool	ft_ischarok(char c);
void	ft_parse_sprite(int	x, int y, t_scene *scene);
#endif
