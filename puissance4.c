#include "./includes/puissance4.h"

void	puissance4(int width, int height, int diff)
{
	int		rslt;
	int		player;

	if (!is_valid(width, height))
		ft_putendl("invalid map size");
	else
	{
		init_map(width, height, diff);
		rslt = 0;
		player = 2;
		while (!rslt)
		{
			print_map();
			if (!(rslt = game_is_on()))
			{
				player = player == 1 ? 2 : 1;
				if (player == 2)
					comp_play(player);
				else
					player_play(player);
			}
			ft_putendl("");
		}
		print_rslt(rslt);
	}
}
	
void	print_rslt(int rslt)
{
	if (rslt == 3)
		ft_putendl("It's a draw !");
	else if (rslt == 1)
		ft_putendl("Player wins");
	else if (rslt == 2)
		ft_putendl("Computer wins");
}

int		game_is_on(void)
{
	int		i;
	int		j;
	int		free;
	int		rslt;
	t_map	*map;

	map = get_map();
	i = -1;
	free = 0;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map[i][j] == '-')
				free = 1;
			if (map->map[i][j] != '-' && (rslt = wins(i, j)))
				return (rslt);
		}
	}
	return (free == 0 ? 3 : 0);
}
