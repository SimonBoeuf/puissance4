#include "./includes/puissance4.h"

int	abs(int n)
{
	return (n > 0 ? n : -n);
}

int	getval(int col, int player)
{
	return (max(col, player, 0));
}

#include <stdio.h>
int	max(int col, int player, int depth)
{
	int	i;
	int	bestval;
	int	val;
	int	row;
	int	rtn;

	row = is_playable(col) - 1;
	play (row, col, player);
	bestval = 100000;
	if ((!game_is_on()) && depth < get_map()->diff)
	{
		i = -1;
		while (++i < get_map()->width)
		{
			if (is_playable(i))
			{
				val = min(i, player == 1 ? 2 : 1, depth + 1);
				bestval = val < bestval ? val : bestval;
			}
		}
		//printf("max. depth : %d, col : %d, player : %d, bestval : %d\n", depth, col, player, bestval);
		unplay(row, col);
		return (bestval);
	}
	//printf("max. depth : %d, col : %d, player : %d, val : %d\n", depth, col, player, get_map_value());
	rtn = get_map_value();
	unplay(row, col);
	return (rtn);
}

int	min(int col, int player, int depth)
{
	int	i;
	int	bestval;
	int	val;
	int	row;
	int	rtn;

	row = is_playable(col) - 1;
	play (row, col, player);
	bestval = -100000;
	if ((!game_is_on()) && depth < get_map()->diff)
	{
		i = -1;
		while (++i < get_map()->width)
		{
			if (is_playable(i))
			{
				val = max(i, player == 1 ? 2 : 1, depth + 1);
				bestval = val > bestval ? val : bestval;
			}
		}
		//printf("min. depth : %d, col : %d, player : %d, bestval : %d\n", depth, col, player, bestval);
		unplay(row, col);
		return (bestval);
	}
	//printf("min. depth : %d, col : %d, player : %d, val : %d\n", depth, col, player, get_map_value());
	rtn = get_map_value();
	unplay(row, col);
	return (rtn);
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
	rslt = get_map()->width - abs(get_map()->width / 2 - col);
	rslt += get_horizontal_number(row, col) * get_map()->width;
	rslt += get_vertical_number(row, col) * get_map()->width;
	rslt += get_diagonal_numbers(row, col) * get_map()->width;
	rslt *= coeff;
	return (rslt);
}
