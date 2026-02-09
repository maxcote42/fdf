#include "minilibx-linux/mlx.h"

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;
	int		j;

	mlx_ptr = mlx_init();
	if(!mlx_ptr)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx_test");
	if(!win_ptr)
		return (1);
	i = 0;
	j = 244;
	while (i <= 444)
	{	mlx_pixel_put(mlx_ptr, win_ptr, j--, i++, 0xff66ff);}
	i = 0;
	j = 445;
	while (j >= 222)
	{	mlx_pixel_put(mlx_ptr, win_ptr, j--, i++, 0x000455);}
	mlx_loop(mlx_ptr);
	return (0);
}