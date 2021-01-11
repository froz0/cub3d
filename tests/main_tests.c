/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:26:31 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/11 19:32:37 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	t_tests	tests;
	int		log;

	log = 0;
	if (argc > 1)
		log = ft_atoi(argv[1]);
	tests = ft_init_tester("Cub3D tests", log);
	ft_tests_header(&tests);
	ft_tests_result(&tests);
	if (tests.tests_failed)
		return (1);
	return (0);
}
