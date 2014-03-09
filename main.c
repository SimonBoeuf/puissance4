/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 20:29:56 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/09 22:52:15 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/puissance4.h"

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 3)
		puissance4(ft_atoi(argv[1]), ft_atoi(argv[2]), 1);
	else if (argc == 4)
		puissance4(ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]));
	else
		ft_putendl("invalid parameters");
	i = -1;
	while (++i < get_map()->height)
		free(get_map()->map[i]);
	free(get_map()->map);
	free(get_map());
	return (0);
}
