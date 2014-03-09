/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 20:30:11 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/09 21:06:45 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/puissance4.h"

t_map		*init_map(int width, int height, int diff)
{
	int				i;
	static t_map	*map = NULL;

	if (map == NULL)
	{
		map = (t_map*)malloc(sizeof(t_map));
		map->diff = diff;
		map->width = width;
		map->height = height;
		map->map = (char**)malloc(height * sizeof(char*));
		i = -1;
		while (++i < height)
		{
			map->map[i] = ft_strnew(width + 1);
			ft_memset(map->map[i], '-', width);
		}
	}
	return (map);
}

t_map		*get_map(void)
{
	return (init_map(0, 0, 0));
}

static void	print_char(char c)
{
	if (c == '-')
		ft_putstr("\033[1;30m◉\033[0m");
	if (c == 'R')
		ft_putstr("\033[31m◉\033[0m");
	if (c == 'Y')
		ft_putstr("\033[33m◉\033[0m");
	ft_putchar('\t');
}

void		print_map(void)
{
	int		i;
	int		j;
	t_map	*map;

	map = get_map();
	i = -1;
	while (++i < map->height)
	{
		ft_putstr(ft_itoa(map->height - i - 1));
		ft_putchar('\t');
		j = -1;
		while (++j < map->width)
			print_char(map->map[i][j]);
		ft_putstr("\n\n");
	}
	ft_putchar('\t');
	j = -1;
	while (++j < map->width)
	{
		ft_putstr(ft_itoa(j));
		ft_putchar('\t');
	}
	ft_putstr("\n\n");
}

int			is_valid(int width, int height)
{
	return (!(width < 0 || height < 0 || (width < 4 && height < 4)));
}
