#include "./includes/puissance4.h"

int	main(int argc, char **argv)
{
	if (argc == 3)
		puissance4(ft_atoi(argv[1]), ft_atoi(argv[2]));
	else
		ft_putendl("invalid parameters");
	return (0);
}
