/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 16:38:54 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/17 23:38:36 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "../libft/libft.h"
# include "./parser/parser.h"

/*
** t_args is used to store information about the args
** fd: store the fd returned from the open() -1 if error
** save: 0 if --save is absent 1 if it is here
*/
typedef struct s_args
{
	int	fd;
	int	save;
}	t_args;

#endif
