#include "f2f.h"


int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		return (1);
	init_fdf();
	if (parse_map(argv[1], fdf) == 0)
		return (1);
}