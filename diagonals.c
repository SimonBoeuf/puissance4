/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diagonals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 21:01:55 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/09 21:02:12 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/puissance4.h"

int	get_diagonal_number1(int row, int col)
{
	t_map	*map;
	int		i;
	int		j;
	int		rslt;
	char	player;

	rslt = 0;
	i = row;
	j = col;
	map = get_map();
	player = map->map[row][col];
	while (map->map[i][j] == player && i > 0 && j > 0)
	{
		i--;
		j--;
		rslt++;
	}
	if (map->map[i][j] == player)
		rslt++;
	return (rslt);
}

int	get_diagonal_number2(int row, int col)
{
	t_map	*map;
	int		i;
	int		j;
	int		rslt;
	char	player;

	rslt = 0;
	i = row;
	j = col;
	map = get_map();
	player = map->map[row][col];
	while (map->map[i][j] == player && i < map->height - 1 && j > 0)
	{
		i++;
		j--;
		rslt++;
	}
	if (map->map[i][j] == player)
		rslt++;
	return (rslt);
}

int	get_diagonal_number3(int row, int col)
{
	t_map	*map;
	int		i;
	int		j;
	int		rslt;
	char	player;

	rslt = 0;
	i = row;
	j = col;
	map = get_map();
	player = map->map[row][col];
	while (map->map[i][j] == player && i > 0 && j < map->width - 1)
	{
		i--;
		j++;
		rslt++;
	}
	if (map->map[i][j] == player)
		rslt++;
	return (rslt);
}

int	get_diagonal_number4(int row, int col)
{
	t_map	*map;
	int		i;
	int		j;
	int		rslt;
	char	player;

	rslt = 0;
	i = row;
	j = col;
	map = get_map();
	player = map->map[row][col];
	while (map->map[i][j] == player &&
			i < map->height - 1 && j < map->width - 1)
	{
		i++;
		j++;
		rslt++;
	}
	if (map->map[i][j] == player)
		rslt++;
	return (rslt);
}
