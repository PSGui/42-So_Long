#include "../includes/so_long_utils.h"
#include "../includes/so_long.h"

void    start_map(data_t *data, char *map_path)
{
        int     fd;

        fd = open_map_file(map_path);
        read_map_file(data, fd);
        data->dim.width = val_map_lenght(data->grid.map, data);
        close(fd);
        return ;
}

int     open_map_file(char *map_path)
{
        int     fd;

        fd = open(map_path, O_RDONLY);
        if (fd < 0)
        {
                ft_printf("Error while opening the map.");
                exit(1);
        }
        return (fd);
}

void    read_map_file(data_t *data, int fd)
{
        char    *str;

        str = ft_strdup("");
        data->dim.height = 0;
        while (fd)
        {
                data->dim.line_read = get_next_line(fd);
                if (data->dim.height == NULL)
                        break ;
                str = reconstruct_map(str, data->dim.line_read);
                free(data->dim.line_read);
                data->dim.height++;
        }
        object_counter(data, str);
        data->grid.map = ft_split(str, '\n');
        if ((height_equals_lines_check(data)) != 0)
        {
                ft_printf("Error while reading map file. Please try again or provide a different map");
                free(str);
                return ;
        }
        free(str);
        return ;
}

char    *reconstruct_map(char *s1, char *s2)
{
        char    *new_str;
        size_t len1;
        size_t len2;
        size_t new_len;

        if (s1 == NULL || s2 == NULL)
                return NULL;
        len1 = strlen(s1);
        len2 = strlen(s2);
        new_len = len1 + len2;
        new_str = malloc(new_len + 1);
        if (new_str == NULL)
                return (NULL);
        strcpy(new_str, s1);
        strcat(new_str, s2);
        free(s1);
        free(s2);
        return (new_str);
}

void     object_counter(data_t *data, char *map_string)
{
        int     i;

        i = 0;
        if (data->dim.height <= 2)
        {
                free(map_string);
                ft_printf("Invalid map type. Make sure it has at least 3 lines!");
                end_game_handler(data, INVALID_MAP);
        }
        while(map_string[i] != '\0')
        {
                if (map_string[i++] == 'C')
                        data->i.collectible++;
                else if (map_string[i++] == '0')
                        data->i.free_space++;
                else if (map_string[i++] == 'E')
                        data->i.exit++;
                else if (map_string[i++] == 'P')
                        data->i.player_start;
        }
        check_counter_values(data, map_string); //Verify the ammount of objects in the map. We pass "map_string" as an argument to free it in case of an error!
}

void    check_counter_values(data_t *data, char *map_string)
{
        if (!(data->i.collectible > 0 && data->i.exit == 1 &&
        data->i.player_start == 1 && data->i.free_space > 0))
        {
                free(map_string);
                end_game_handler(data, INVALID_MAP);
        }
}

int     height_equals_lines_check(data_t *data)
{
        int     i;

        i = 0;
        while (data->dim.map[i] != NULL)
        {
                i++;
        }
        if (data->dim.height != i - 1)
        {
                return (ERROR);
        }
        return(0);
}