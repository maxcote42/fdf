#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <math.h>

// Fermeture de la fenêtre avec ESC
int key_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == 65307) // ESC
		exit(0);
	return 0;
}

// Projection isométrique avec facteur d'échelle
void isometric(int *x, int *y, int z, int scale)
{
	int tmp = *x;
	*x = (tmp - *y) * 0.866 * scale;   // cos(30°)
	*y = (tmp + *y) * 0.5 * scale - z; // sin(30°)
}

// Ligne simple (Bresenham simplifié)
void draw_line(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1, int color)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
	float x_inc = dx / (float)steps;
	float y_inc = dy / (float)steps;
	float x = x0;
	float y = y0;
	for (int i = 0; i <= steps; i++)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, (int)x, (int)y, color);
		x += x_inc;
		y += y_inc;
	}
}

// Grille 4x4 isométrique
void draw_grid_4x4(void *mlx_ptr, void *win_ptr, int offset_x, int offset_y, int scale)
{
	int i, j;
	int x, y, x2, y2;
	int z = 0; // plan plat

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			// Projection du point (j,i)
			x = j;
			y = i;
			isometric(&x, &y, z, scale);
			x += offset_x;
			y += offset_y;

			// Ligne horizontale (vers droite)
			if (j < 3)
			{
				x2 = j + 1;
				y2 = i;
				isometric(&x2, &y2, z, scale);
				x2 += offset_x;
				y2 += offset_y;
				draw_line(mlx_ptr, win_ptr, x, y, x2, y2, 0x00FF00);
			}

			// Ligne verticale (vers bas)
			if (i < 3)
			{
				x2 = j;
				y2 = i + 1;
				isometric(&x2, &y2, z, scale);
				x2 += offset_x;
				y2 += offset_y;
				draw_line(mlx_ptr, win_ptr, x, y, x2, y2, 0x00FF00);
			}
		}
	}
}

int main()
{
	void *mlx_ptr;
	void *win_ptr;
	int scale = 80; // facteur d'agrandissement

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return 1;
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "mlx_test");
	if (!win_ptr)
		return 1;

	// Dessine la grille 4x4 beaucoup plus grande
	draw_grid_4x4(mlx_ptr, win_ptr, 200, 100, scale); // offset pour centrer

	// Hook clavier pour ESC
	mlx_key_hook(win_ptr, key_hook, NULL);

	mlx_loop(mlx_ptr);
	return 0;
}
