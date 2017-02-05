# include "filler.h"

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
        ft_get_xy(line, data->xy_plateau);
        if (!(data->plateau = (char**)ft_memalloc(sizeof(*data->plateau)
        * (data->xy_plateau[0] + 1))))
            return (-1);
//        ft_printf("--->1\n");
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
//        ft_printf("--->2\n");
//        ft_printf("---> %s\n", data->plateau[0]);
//        ft_printf("XXx : %d # y : %d\n", data->final_pos_x, data->final_pos_y);
        free(str);
        data->plateau[i] = NULL;
    }
//    ft_printf("XXx : %d # y : %d\n", data->final_pos_x, data->final_pos_y);
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
//    ft_printf("\n--->Piece\n");
//    ft_putchar('|');
//    ft_putendl(line);
//    ft_putchar('|');
    if ((ft_strstr(line, "Piece")))
    {
//        ft_printf("--->3\n");
        ft_get_xy(line, data->xy_piece);
//        ft_printf("--->5\n");
        if (!(data->piece = (char**)ft_memalloc(sizeof(*data->piece)
        * (data->xy_piece[0] + 1))))
            return (-1);
//        ft_printf("--->6\n");
        while (i < data->xy_piece[0] - 1)
        {
            get_next_line(0, &str);
//            ft_printf("--::: %s\n", str);
            data->piece[i] = ft_strdup(str);
            i++;
            ft_count_coord(str, data);
        }
//        ft_printf("--->4\n");
        free(str);
        data->piece[i] = NULL;
        ft_get_coord_piece(data);
        ft_get_best_position(data);
        ft_printf("%d %d\n", data->final_pos_y, data->final_pos_x);
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
