#include "fdf.h"


int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (1);
//	init_fdf();
	if (parse_map(argv[1], &map) == 0)
		return (1);
}