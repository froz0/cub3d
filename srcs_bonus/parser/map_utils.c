/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:03:43 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/18 16:06:00 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_bool	ft_ismapchar(int c)
{
	char	*charset;

	charset = "102 SWEN";
	if (ft_christr(charset, c) == -1)
		return (false);
	else
		return (true);
}

t_bool	ft_should_surround(int c)
{
	char	*charset;

	charset = "02SWEN";
	if (ft_christr(charset, c) == -1)
		return (false);
	else
		return (true);
}

t_bool	ft_ischarok(char c)
{
	char	*charset;

	charset = "102SWEN";
	if (ft_christr(charset, c) == -1)
		return (false);
	else
		return (true);
}
