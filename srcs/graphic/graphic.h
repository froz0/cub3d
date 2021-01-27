/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:03:53 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/26 23:04:08 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H

# define GRAPHIC_H
# include "../cub3d.h"

void	ft_clear_memory(t_game *game);
void	ft_frame_pixel(t_frame *frame, int x, int y, int color);
int		ft_event_exit(t_game *game);
int		ft_event_key(unsigned int key, t_game *game);
void	ft_graphic_handle(t_scene *scene);
t_frame	ft_render_frame(t_game game);
void	ft_render_raycast(t_frame *frame, t_game *game);
int		ft_trgb(int t, int r, int g, int b);
#endif
