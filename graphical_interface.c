
# include "filler.h"

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

int ft_graphics(t_data *data)
{
  int color;
	int y;
  int x;

	data->img.img = mlx_new_image(data->img.mlx, 1000, 1000);
	data->img.mlx_data = mlx_get_data_addr(data->img.img,
	&data->img.bits_per_pixel, &data->img.size_line, &data->img.endian);
	y = 0;
	x = 0;
	color = 0;
	while (data->plateau[y])
	{
		x = 0;
		while (data->plateau[y][x])
		{
			ft_color(&color, data->plateau, &x, &y);
			ft_draw_rectangle(x * 5, y * 5, x * 5 + 5, y * 5 + 5,
			data->img.mlx_data, &data->img.size_line, color);
			x++;
		}
		y++;
	}
	mlx_clear_window(data->img.mlx, data->img.win); // Expose hook ??
	mlx_put_image_to_window(data->img.mlx, data->img.win, data->img.img, 0, 0);
	mlx_destroy_image(data->img.mlx, data->img.img);
  return (0);
}
