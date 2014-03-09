/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 20:29:56 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/09 20:29:58 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/puissance4.h"

int	main(int argc, char **argv)
{
	if (argc == 3)
		puissance4(ft_atoi(argv[1]), ft_atoi(argv[2]), 1);
	else if (argc == 4)
		puissance4(ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]));
	else
		ft_putendl("invalid parameters");
	return (0);
}
