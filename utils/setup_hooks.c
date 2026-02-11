#include "../fdf.h"

static int handle_close(t_app *app)
{
	mlx_destroy_window(app->mlx, app->win);
	exit(0);
	return (0);
}

static int handle_esc(int keycode, t_app *app)
{
	if (keycode == 65307 || keycode == 53) 
	{
		mlx_destroy_window(app->mlx, app->win);
		exit(0);
	}
	return (0);
}

void setup_hooks(t_app *app)
{
	// Key press
	mlx_key_hook(app->win, handle_esc, app);

	// Window close (croix)
	mlx_hook(app->win, 17, 0L, handle_close, app); 
}