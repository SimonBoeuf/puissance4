/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 20:30:40 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/09 22:27:52 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/puissance4.h"

int	getval(int col, int player)
{
	return (min(col, player, 0, -MAXINT));
}

int	min(int col, int player, int depth, int maxval)
{
	int	i;
	int	bestval;
	int	val;
	int	row;

	row = is_playable(col) - 1;
	play(row, col, player);
	bestval = 100000;
	if ((!game_is_on()) && depth < get_map()->diff)
	{
		i = -1;
		while (++i < get_map()->width && bestval > maxval)
		{
			if (is_playable(i))
			{
				val = max(i, player == 1 ? 2 : 1, depth + 1, bestval);
				bestval = val < bestval ? val : bestval;
			}
		}
		unplay(row, col);
		return (bestval);
	}
	val = get_map_value();
	unplay(row, col);
	return (val);
}

int	max(int col, int player, int depth, int minval)
{
	int	i;
	int	bestval;
	int	val;
	int	row;

	row = is_playable(col) - 1;
	play(row, col, player);
	bestval = -100000;
	if ((!game_is_on()) && depth < get_map()->diff)
	{
		i = -1;
		while (++i < get_map()->width && bestval < minval)
		{
			if (is_playable(i))
			{
				val = min(i, player == 1 ? 2 : 1, depth + 1, bestval);
				bestval = val > bestval ? val : bestval;
			}
		}
		unplay(row, col);
		return (bestval);
	}
	val = get_map_value();
	unplay(row, col);
	return (val);
}

int	get_cell_value(int row, int col)
{
	int	rslt;
	int	coeff;

	if (get_map()->map[row][col] == 'R')
		coeff = -1;
	if (get_map()->map[row][col] == 'Y')
		coeff = 1;
	if (get_map()->map[row][col] == '-')
		coeff = 0;
	if (coeff && wins(row, col))
		return (100000 / get_map()->width / get_map()->height * coeff);
	rslt = get_map()->width - ft_abs(get_map()->width / 2 - col);
	rslt += get_horizontal_number(row, col) * get_map()->width;
	rslt += get_vertical_number(row, col) * get_map()->width;
	rslt += get_diagonal_numbers(row, col) * get_map()->width;
	rslt *= coeff;
	return (rslt);
}

int	get_map_value(void)
{
	int		rslt;
	int		i;
	int		j;

	rslt = 0;
	i = -1;
	while (++i < get_map()->height)
	{
		j = -1;
		while (++j < get_map()->width)
		{
			rslt += get_cell_value(i, j);
		}
	}
	return (rslt);
}
