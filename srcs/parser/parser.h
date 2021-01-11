/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 23:39:38 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/11 19:01:21 by tmatis           ###   ########.fr       */
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

void	ft_parse_head(int fd, t_scene *scene);
t_scene	ft_parse_scene(int fd);
t_rgb	ft_init_rgb(int r, int g, int b);
#endif
