#include "./includes/puissance4.h"

int	abs(int n)
{
	return (n > 0 ? n : -n);
}

int	getval(int row, int col, int player)
{
	(void)player;
	(void)row;
	return (get_map()->width - (abs(get_map()->width / 2 - col)));
}
