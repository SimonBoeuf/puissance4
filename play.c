/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 20:30:26 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/09 20:47:39 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/puissance4.h"

int		is_playable(int col)
{
	t_map	*map;
	int		i;

	map = get_map();
	if (col < 0 || col > map->height)
		return (0);
	i = 0;
	while (i < map->height && map->map[i][col] == '-')
		i++;
	return (i);
}

void	play(int row, int col, int player)
{
	get_map()->map[row][col] = get_player(player);
}

void	unplay(int row, int col)
{
	get_map()->map[row][col] = '-';
}

void	comp_play(int player)
{
	int		i;
	int		val;
	int		bestval;
	int		besti;
	int		bestj;

	val = 0;
	bestval = -100000;
	i = -1;
	while (++i < get_map()->width)
	{
		if ((is_playable(i)))
		{
			val = getval(i, player);
			if (val > bestval)
			{
				bestval = val;
				besti = i;
				bestj = is_playable(i);
			}
		}
	}
	play(bestj - 1, besti, player);
}

void	player_play(int player)
{
	int		row;
	char	*line;

	get_next_line(1, &line);
	while (!(row = is_playable(ft_atoi(line))))
	{
		ft_putendl("Please enter a valid column to play");
		get_next_line(1, &line);
	}
	play(row - 1, ft_atoi(line), player);
}
