/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 23:39:38 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/14 17:31:34 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H

# define PARSER_H

# include "../cub3d.h"

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_scene
{
	int		err;
	int		x_scr;
	int		y_scr;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	t_rgb	f;
	t_rgb	c;
	int		sizex;
	int		sizey;
	char	**map;
}	t_scene;

t_scene	ft_parse_scene(int fd);
t_rgb	ft_init_rgb(int r, int g, int b);
int		ft_ismapchar(int c);
void	ft_free_head(t_scene *scene);
void	ft_free_scene(t_scene *scene);
void	ft_parse_r(char *line, t_scene *scene);
t_rgb	ft_parse_rgb(char *line);
void	ft_parse_texture(char **path, char *line);
void	ft_check_head(t_scene *scene);
t_bool	ft_parse_head(int fd, t_scene *scene);
t_bool	ft_parse_map(char **line, t_scene *scene, int fd);
#endif
