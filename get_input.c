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

static int ft_size_tab(char *line, t_data *data)
{
    if ((ft_strstr(line, "Plateau")))
    {
        ft_get_xy(line, data->xy_plateau);
        if (!(data->plateau = (char**)ft_memalloc(sizeof(*data->plateau) * (data->xy_plateau[0] + 1))))
            return (-1);
    }
    if ((ft_strstr(line, "Piece")))
    {
        ft_get_xy(line, data->xy_piece);
        if (!(data->piece = (char**)ft_memalloc(sizeof(*data->piece) * (data->xy_piece[0] + 1))))
            return (-1);
    }
    if (!data->xy_plateau[0] && !data->piece[0])
        return (-1);
    return (0);
}

int    ft_get_input(t_data *data)
{
    int y;
    int k;
    char *line;

    y = 0;
    k = 0;
    line = NULL;
    while (get_next_line(0, &line) > 0)
    {
        if (ft_get_size_tab(line, data) == -1)
            return (-1);
        if (*line != 'P' && *line != ' ' && !ft_isdigit(*line) && *line != '.')
            break ;
        if (ft_isdigit(line[0]))
            data->plateau[y++] = ft_strdup(ft_strchr(line, ' ') + 1);
        if (line[0] == '.' || line[0] == '*')
            data->piece[k++] = ft_strdup(line);
        free(line);
    }
    data->plateau[y] = NULL;
    data->piece[k] = NULL;
    return (0);
}
