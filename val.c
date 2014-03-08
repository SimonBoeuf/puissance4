#include "./includes/puissance4.h"

int	abs(int n)
{
	return (n > 0 ? n : -n);
}

int	getval(int col, int player)
{
	return (max(col, player, 1));
}

int	max(int col, int player, int depth)
{
	int	i;
	int	bestval;
	int	val;
	int	row;
	int	rtn;

	row = is_playable(col) - 1;
	play (row, col, player);
	bestval = -MAXINT;
	if (game_is_on() && depth < get_map()->diff)
	{
		i = -1;
		while (++i < get_map()->width)
		{
			if (is_playable(i))
			{
				if (bestval < (val = min(i, player == 1 ? 2 : 1, depth + 1)))
					bestval = val;
			}
		}
		return (bestval);
	}
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
	bestval = MAXINT;
	if (game_is_on() && depth < get_map()->diff)
	{
		i = -1;
		while (++i < get_map()->width)
		{
			if (is_playable(i))
			{
				if (bestval > (val = max(i, player == 1 ? 2 : 1, depth + 1)))
					bestval = val;
			}
		}
		return (bestval);
	}
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
	rslt = get_map()->width - abs(get_map()->width / 2 - col);
	rslt *= coeff;
	return (rslt);
}
