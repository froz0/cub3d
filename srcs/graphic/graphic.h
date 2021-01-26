/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:03:53 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/26 16:13:57 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H

# define GRAPHIC_H
# include "../cub3d.h"

void	ft_graphic_handle(t_scene *scene);
t_frame	ft_render_frame(t_game_state game_state);
int		ft_trgb(int t, int r, int g, int b);
#endif
