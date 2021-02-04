/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:03:53 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/04 13:09:05 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H

# define GRAPHIC_H
# include "../cub3d.h"
# define WS 0.05
# define SP 0.05
# define RS 0.03

typedef	struct	s_cf
{
	double		raydirx0;
	double		raydiry0;
	double		raydirx1;
	double		raydiry1;
	int			p;
	double		posz;
	double		rowdistance;
	double		floorstepx;
	double		floorstepy;
	double		floorx_c;
	double		floory_c;
	double		floorx_f;
	double		floory_f;
	int			cellx_c;
	int			celly_c;
	int			cellx_f;
	int			celly_f;
	int			tx_c;
	int			ty_c;
	int			tx_f;
	int			ty_f;
}				t_cf;

typedef	struct	s_ray
{
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		deltadistx;
	double		deltadisty;
	double		sidedistx;
	double		sidedisty;
	int			stepx;
	int			stepy;
	int			walln;
	double		perpwalldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		wallx;
	double		texx;
	double		step;
	double		texpos;
	t_texture	tex;
}				t_ray;

typedef	struct	s_sp
{
	double	spritex;
	double	spritey;
	double	invdet;
	double	transformx;
	double	transformy;
	int		spritescreenx;
	int		spriteheight;
	int		drawstarty;
	int		drawendy;
	int		spritewidth;
	int		drawstartx;
	int		drawendx;
	int		texx;
	int		texy;
	int		d;
}				t_sp;

void			ft_calc_sidedist(t_game *game, t_ray *ray);
void			ft_calc_raydir(t_game *game, t_ray *ray, int x);
void			ft_calc_draw(t_game *game, t_ray *ray);
double			ft_calc_dist(t_game *game, t_ray *ray);
void			ft_calc_side(t_game *game, t_ray *ray);
void			ft_clear_memory(t_game *game);
int				ft_clear_frame(t_game *game);
void			ft_frame_pixel(t_frame f, int x, int y, int color);
unsigned	int	ft_get_pixel(t_frame f, int x, int y);
t_texture		ft_load_texture(char *path, t_game *game);
int				ft_event_exit(t_game *game);
int				ft_event_key(unsigned int key, t_game *game);
void			ft_graphic_handle(t_scene *scene);
t_frame			ft_init_frame(t_game *game);
void			ft_render_frame(t_game *game);
void			ft_render_raycast(t_game *game);
void			ft_render_sprite(t_game *g);
int				ft_trgb(int t, int r, int g, int b);
int				ft_event_key_release(unsigned int key, t_game *game);
void			ft_walk(t_game *g);
void			ft_straft(t_game *g);
void			ft_rotate(t_game *g);
void			ft_set_dir(t_game *game);
void			ft_init_game(t_game *game, t_scene *scene);
t_game			ft_getfirst_frame(t_scene *scene);
void			ft_load_textures(t_game *game);
#endif
