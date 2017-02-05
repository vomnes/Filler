# include "filler.h"

void ft_print_strtab(char **tab)
{
    int i;

    i = 0;
    while (tab[i] != NULL)
        ft_putendl(tab[i++]);
}

static void ft_get_xy(char *input, int *stock)
{
    int i;
    int next;

    i = 0;
    next = 0;
    stock[0] = 0;
    stock[1] = 0;
    while (input[i] != '\0')
    {
        while (ft_isdigit(input[i]))
            stock[next] = stock[next] * 10 + (input[i++] - '0');
        if (ft_isdigit(input[i - 1]) && input[i] != ':')
            next++;
        i++;
    }
}

static void ft_get_number_player(t_data *data, char *line)
{
    int i;

    i = 0;
    if (line[0] == '$')
        if (ft_strstr(line, "vomnes.filler"))
            while (line[i++])
                if (line[i] == 'p' && ft_isdigit(line[i + 1]))
                    data->num_player = line[i + 1] - '0';
}

static int ft_get_plateau(t_data *data, char *line)
{
    int i;
    char *str;

    i = 0;
    str = NULL;
    if ((ft_strstr(line, "Plateau")))
    {
        data->final_pos_y = 0;
        data->final_pos_x = 0;
        ft_get_xy(line, data->xy_plateau);
        if (!(data->plateau = (char**)ft_memalloc(sizeof(*data->plateau)
        * (data->xy_plateau[0] + 1))))
            return (-1);
        get_next_line(0, &str);
        while (i < data->xy_plateau[0])
        {
            get_next_line(0, &str);
            if (ft_strchr(str, data->player_shape) && data->ok_min_y == 0)
            {
                data->min_y = i;
                data->ok_min_y = 1;
            }
            data->plateau[i] = ft_strdup(ft_strchr(str, ' ') + 1);
            i++;
        }
        free(str);
        data->plateau[i] = NULL;
    }
    return (0);
}

void ft_count_coord(char *line, t_data *data)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] == '*')
            data->nb_coord++;
        i++;
    }
}

static int ft_get_piece(t_data *data, char *line)
{
    int i;
    char *str;

    i = 0;
    str = NULL;
    if ((ft_strstr(line, "Piece")))
    {
        ft_get_xy(line, data->xy_piece);
        if (!(data->piece = (char**)ft_memalloc(sizeof(*data->piece)
        * (data->xy_piece[0] + 1))))
            return (-1);
        ft_printf("\nmy_line__ --> %s\n", line);
        while (i < data->xy_piece[0])
        {
            get_next_line(0, &str);
            ft_printf("%d < %d", i, data->xy_piece[0]);
            ft_printf("\nmy_line --> %s\n", str);
            data->piece[i] = ft_strdup(str);
            ft_printf("my_data --> %s\n", data->piece[i]);
            i++;
            ft_count_coord(str, data);
        }
        free(str);
        data->piece[i] = NULL;
        ft_get_coord_piece(data);
        ft_get_best_position(data);
        ft_printf("%d %d\n", data->final_pos_y, data->final_pos_x);
        ft_print_strtab(data->piece);
    }
    return (0);
}

int ft_get_data(t_data *data)
{
    char *line;

    line = NULL;
    while (get_next_line(0, &line) > 0)
    {
        ft_get_number_player(data, line);
        ft_get_plateau(data, line);
    //    ft_printf("x : %d # y : %d\n", data->final_pos_x, data->final_pos_y);
        ft_get_piece(data, line);
    }
    free(line);
    return (0);
}
