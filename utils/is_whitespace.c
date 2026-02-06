#include "../fdf.h"

int	iswhitespace(char c)
{
	if ((c == 32) || ((c >= 9) && (c <= 12)))
		return (1);
	return (0);
}