#ifndef PUISSANCE_4_h
# define PUISSANCE_4_h

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <time.h>
# include "../libft/libft.h"

typedef struct	s_map
{
	int		width;
	int		height;
	char	**map;
}				t_map;

void	puissance4(int width, int height);

t_map	*init_map(int width, int height);
void	print_map(void);

#endif
