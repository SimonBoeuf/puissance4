#include "./includes/puissance4.h"

int	abs(int n)
{
	return (n > 0 ? n : -n);
}

int	getval(int row, int col, int player)
{
	return (max(row, col, player, 1));
}

int	max(int row, int col, int player, int depth)
{
	int	op;

	op = player == 1 ? 2 : 1;
	if (game_is_on() && depth < get_map()->diff)
		return (min(row, col, op, depth + 1));
	return (1);
}

int	min(int row, int col, int player, int depth)
{
	int	op;

	op = player == 1 ? 2 : 1;
	if (game_is_on() && depth < get_map()->diff)
		return (max(row, col, op, depth + 1));
	return (1);
}
