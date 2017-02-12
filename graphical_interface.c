
# include "filler.h"
# include <mlx.h>

# define KEY_Q 12
# define KEY_ESCAPE 53

static int		ft_exit(int keycode)
{
	if (keycode == KEY_ESCAPE || keycode == KEY_Q)
		exit(0);
  return (0);
}

int ft_draw_rectangle(int x1, int y1, int x2, int y2, void *mlx, void *win, int color)
{
    int x;
    int y;

    x = x1;
    y = y1;
    while (y < y2)
    {
      x = x1;
      while (x < x2)
      {
        mlx_pixel_put(mlx, win, x, y, color);
        x++;
      }
      y++;
    }
    return (0);
}

int main()
{
  void *mlx;
  void *win;
  int color;

  char tab[17] = ".O.X......XXOOOOO";

  mlx = mlx_init();
  win = mlx_new_window(mlx, 600, 600, "Filler");

  int i = 0;
  color = 0;
  while (tab[i])
  {
    if (tab[i] == '.')
      color = 0x00F7FFF7;
    else if (tab[i] == 'O')
      color = 0x00FF6B6B;
    else if (tab[i] == 'X')
      color = 0x00FFE66D;
    ft_draw_rectangle(i * 20, 0, i * 20 + 20, 20, mlx, win, color);
    ft_putchar(tab[i]);
    i++;
  }
  mlx_key_hook(win, ft_exit, 0);
  mlx_loop(mlx);
  return (0);
}
