/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alignments.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 20:29:51 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/09 21:01:52 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	get_diagonal_numbers(int row, int col)
{
	int	rslt;
	int	first;
	int	second;
	int	third;
	int	fourth;

	rslt = 0;
	first = get_diagonal_number1(row, col);
	rslt = first > rslt ? first : rslt;
	second = get_diagonal_number2(row, col);
	rslt = second > rslt ? second : rslt;
	third = get_diagonal_number3(row, col);
	rslt = third > rslt ? third : rslt;
	fourth = get_diagonal_number4(row, col);
	rslt = fourth > rslt ? fourth : rslt;
	return (rslt);
}
