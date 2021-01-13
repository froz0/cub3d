/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:11:24 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/13 14:15:27 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_ismapchar(int c)
{
	char	*charset;

	charset = "102 NSEW";
	if (ft_christr(charset, c) == -1)
		return (0);
	else
		return (1);
}
