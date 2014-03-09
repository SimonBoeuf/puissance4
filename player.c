#include "./includes/puissance4.h"

char	get_player(int player)
{
	return (player == 1 ? 'R' : 'Y');
}

int		get_player_number(char player)
{
	return (player == 'R' ? 1 : 2);
}

int		wins(int row, int col)
{
	int	player;

	player = get_player_number(get_map()->map[row][col]);
	if (get_horizontal_number(row, col) == 4)
		return (player);
	if (get_vertical_number(row, col) == 4)
		return (player);
	if (get_diagonal_numbers(row, col) == 4)
		return (player);
	return (0);
}
