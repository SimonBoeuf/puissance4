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
	int		j;
	int		bestval;
	int		besti;
	int		bestj;

	bestval = 0;
	i = 0;
	while (i < get_map()->width)
	{
		if ((j = is_playable(i)))
		{
			if (getval(j - 1, i, player) > bestval)
			{
				bestval = getval(j - 1, i, player);
				besti = i;
				bestj = j;
			}
		}
		i++;
	}
	if (bestval)
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
	ft_putnbr(row);
	ft_putnbr(ft_atoi(line));
	play(row - 1, ft_atoi(line), player);
}
