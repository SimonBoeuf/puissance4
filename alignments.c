#include "./includes/puissance4.h"

int	get_horizontal_number(int row, int col)
{
	t_map	*map;
	int		i;
	int		rslt;
	char	player;

	i = col;
	map = get_map();
	player = map->map[row][col];
	while (i > 0 && map->map[row][i] == player)
		i--;
	if (map->map[row][i] != player)
		i++;
	rslt = 0;
	while (i < map->width && map->map[row][i] == player)
	{
		i++;
		rslt++;
	}
	return (rslt);
}

int	get_vertical_number(int row, int col)
{
	t_map	*map;
	int		i;
	int		rslt;
	char	player;

	i = row;
	map = get_map();
	player = map->map[row][col];
	while (i > 0 && map->map[i][col] == player)
		i--;
	if (map->map[i][col] != player)
		i++;
	rslt = 0;
	while (i < map->height && map->map[i][col] == player)
	{
		i++;
		rslt++;
	}
	return (rslt);
}

int	get_diagonal_number(int row, int col)
{
	t_map	*map;
	int		i;
	int		j;
	int		rslt;
	char	player;

	i = row;
	j = col;
	map = get_map();
	player = map->map[row][col];
	while (i > 0 && map->map[i--][j--] == player);
	if (map->map[i][j] != player)
	{
		i++;
		j++;
	}
	rslt = 0;
	while (i < map->height && j < map->width && map->map[i][j] == player)
	{
		i++;
		j++;
		rslt++;
	}
	return (rslt);
}
