
# include "filler.h"

static int		ft_exit(int keycode)
{
	if (keycode == KEY_ESCAPE || keycode == KEY_Q)
		exit(0);
  return (0);
}

void	ft_mem_pixel_img(char *mlx_data, int *size_line, unsigned int x, unsigned int y, int color)
{
	unsigned int *index;
	unsigned int y_line;

	index = (unsigned int*)mlx_data;
	y_line = y * *size_line / 4;
	*(index + y_line + x) = color;
}

int ft_draw_rectangle(int x1, int y1, int x2, int y2, char *mlx_data, int *size_line, int color)
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
				if (y == y1 || y == y2 || x == x1 || x == x2)
					ft_mem_pixel_img(mlx_data, size_line, x, y, 0x001A535C);
				else
        	ft_mem_pixel_img(mlx_data, size_line, x, y, color);
        x++;
      }
      y++;
    }
    return (0);
}

/*
void			ftl_draw_pixel_img(t_point *point, t_env *e, int color)
{
	int i;

	i = ((int)point->x * 4) + ((int)point->y * e->s_line);
	e->pixel_img[i] = color;
	e->pixel_img[++i] = color >> 8;
	e->pixel_img[++i] = color >> 16;
}
*/
static void ft_color(int *color, char **tab, int *i, int *k)
{
	if (tab[*k][*i] == '.')
		*color = 0x00F7FFF7;
	else if (tab[*k][*i] == 'O')
		*color = 0x00FF6B6B;
	else if (tab[*k][*i] == 'X')
		*color = 0x00FFE66D;
	else
		*color = 0x001A535C;
}

int main()
{
  int color;
	void *mlx;
	void *win;
	char *mlx_data;
	void *img;
	int bits_per_pixel;
	int size_line;
	int endian;
	int y;
  int x;

	char **tab = ft_strsplit("..XXOOXX..XXOOXX\n..XXOOXX..XXOOXX\n..XXOOXX..XXOOXX\n..XXOOXX..XXOOXX\n", '\n');
	mlx = mlx_init();
	win = mlx_new_window(mlx, 600, 600, "Filler");

	img = mlx_new_image(mlx, 600, 600);
	mlx_data = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
//	mlx_clear_window(mlx, win);
	y = 0;
	x = 0;
	color = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			ft_color(&color, tab, &x, &y);
			ft_draw_rectangle(x * 20, y * 20, x * 20 + 20, y * 20 + 20,
			mlx_data, &size_line, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_key_hook(win, ft_exit, 0);
	mlx_loop(mlx);
  return (0);
}
