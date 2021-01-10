/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 14:04:16 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/10 14:53:29 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/printf.h"

void	ft_log_info(char *log)
{
	ft_printf("[\033[0;32mINFO\x1b[0m] %s\n", log);
}

void	ft_log_error(char *log)
{
	ft_printf("[\033[0;31mERROR\x1b[0m] %s\n", log);
}

void	ft_log_warn(char *log)
{
	ft_printf("[\033[0;33mWARN\x1b[0m] %s\n", log);
}
