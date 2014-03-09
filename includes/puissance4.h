#ifndef PUISSANCE_4_h
# define PUISSANCE_4_h

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <time.h>
# include "../libft/libft.h"

#define MAXINT 2147483647

typedef struct	s_map
{
	int		width;
	int		height;
	int		diff;
	int		min;
	int		max;
	char	**map;
}				t_map;

void	puissance4(int width, int height, int diff);
void	print_rslt(int rslt);
int		game_is_on(void);

void	player_play(int player);
void	comp_play(int player);
int		is_playable(int col);
void	play(int row, int col, int player);
void	unplay(int row, int col);

char	get_player(int player);
int		get_player_number(char player);
int		wins(int row, int col);

int		get_horizontal_number(int row, int col);
int		get_vertical_number(int row, int col);
int		get_diagonal_numbers(int row, int col);
int		get_diagonal_number1(int row, int col);
int		get_diagonal_number2(int row, int col);
int		get_diagonal_number3(int row, int col);
int		get_diagonal_number4(int row, int col);

int		is_valid(int width, int height);
t_map	*init_map(int width, int height, int diff);
t_map	*get_map(void);
void	print_map(void);
int		get_map_value(void);

int		getval(int col, int player);
int		max(int col, int player, int depth);
int		min(int col, int player, int depth);
int		get_cell_value(int row, int col);

int		get_next_line(int const fd, char **line);

#endif
