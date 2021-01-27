/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typecub.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:21:25 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/27 13:18:40 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPECUB_H

# define TYPECUB_H

# include "cub3d.h"
/*
** t_args is used to store information about the args
** fd: store the fd returned from the open() -1 if error
** save: 0 if --save is absent 1 if it is here
*/

typedef struct s_frame {
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}	t_frame;


typedef struct s_args
{
	int	fd;
	int	save;
}	t_args;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_player
{
	int		x;
	int		y;
	int		dir;
}	t_player;

typedef struct s_scene
{
	int			err;
	int			x_scr;
	int			y_scr;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	t_rgb		f;
	t_rgb		c;
	int			sizex;
	int			sizey;
	char		**map;
	t_player	player;
}			t_scene;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	t_bool	w;
	t_bool	a;
	t_bool	s;
	t_bool	d;
	t_scene	*scene;
}		t_game;

#endif
