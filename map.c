#include "./includes/puissance4.h"

t_map	*init_map(int width, int height)
{
	int				i;
	int				j;
	static t_map	*map = NULL;

	if (map == NULL)
	{
		map = (t_map*)malloc(sizeof(t_map));
		map->width = width;
		map->height = height;
		map->map = (char**)malloc(height);
		i = -1;
		while (++i < width)
		{
			map->map[i] = (char*)ft_strnew(width);
		}
	}
	return (map);
}

t_map	*get_map(void)
{
	return (init_map(0, 0));
}

void	print_map(void)
{
	int		i;
	t_map	*map;

	map = get_map();
	i = -1;
	while (++i < map->height)
		ft_putendl(map->map[i]);
}
