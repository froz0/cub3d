/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:03:53 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/29 15:20:33 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H

# define GRAPHIC_H
# include "../cub3d.h"
# define WS 0.05
# define SP 0.05
# define RS 0.03

void		ft_clear_memory(t_game *game);
void		ft_frame_pixel(t_frame *frame, int x, int y, int color);
UINT		ft_get_pixel(t_frame *f, int x, int y);
t_texture	ft_load_texture(char *path, t_game *game);
int			ft_event_exit(t_game *game);
int			ft_event_key(unsigned int key, t_game *game);
void		ft_graphic_handle(t_scene *scene);
t_frame		ft_render_frame(t_game *game);
void		ft_render_raycast(t_frame *frame, t_game *game);
int			ft_trgb(int t, int r, int g, int b);
int			ft_event_key_release(unsigned int key, t_game *game);
void		ft_walk(t_game *g);
void		ft_straft(t_game *g);
void		ft_rotate(t_game *g);
#endif
