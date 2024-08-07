#include "../includes/so_long_utils.h"
#include "../includes/so_long.h"

void    start_map(data_t *data, char *map_path)
{
        int     fd;

        fd = open_map_file(map_path);
        read_map_file(data, fd);
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
        while (1)
        {
                data->grid.line_read = get_next_line(fd);
                if (data->grid.line_read == NULL)
                        break;
                str = reconstruct_map(str, data->grid.line_read);
                data->grid.height++;
        }
        object_counter(data, str);
        ft_printf("read_map_file: %s\n", str);
        data->grid.map = ft_split(str, '\n');
        // for (int i = 0 ; data->grid.map[i]; i++)
        //         ft_printf("Map: '%s'", data->grid.map[i]);
        // ft_printf("Map: NULL\n");
        if ((height_equals_lines_check(data)) != 0)
        {
                ft_printf("Error while reading map file. Please try again or provide a different map");
                free(str);
                return ;
        }
        data->grid.width = ft_strlen(data->grid.map[0]);
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
        len1 = ft_strlen(s1);
        len2 = ft_strlen(s2);
        new_len = len1 + len2;
        new_str = ft_calloc(new_len + 1, sizeof(char));
        if (new_str == NULL)
                return (NULL);
        // ft_printf("reconstruct_map - s1: '%s'\n", s1);     
        // ft_printf("reconstruct_map - s2: '%s'\n", s2);    
        new_str = ft_strcpy(new_str, s1);
        ft_strlcat(new_str, s2, new_len + 1);
        free(s1);
        free(s2);
        // ft_printf("reconstruct_map: %s\n", new_str);
        return (new_str);
}

void     object_counter(data_t *data, char *map_string)
{
        int     i;

        i = 0;
        if (data->grid.height <= 2)
        {
                free(map_string);
                ft_printf("Invalid map type. Make sure it has at least 3 lines!\n");
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
                        data->i.player_start++;
        }
        check_counter_values(data, map_string); //Verify the ammount of objects in the map. We pass "map_string" as an argument to free it in case of an error!
}

void    check_counter_values(data_t *data, char *map_string)
{
        if (data->i.collectible <= 0 && data->i.exit != 1 &&
                data->i.player_start != 1)
        {
                free(map_string);
                //end_game_handler(data, INVALID_MAP);
        }
}

int     height_equals_lines_check(data_t *data)
{
        int     i;

        i = 0;
        while (data->grid.map[i] != NULL)
        {
                ft_printf("height_equals_lines_check: '%s'\n", data->grid.map[i]);
                i++;
        }
        ft_printf("height_equals_lines_check - height: '%d'\n", data->grid.height);
        if (data->grid.height != i)
        {
                return (ERROR);
        }
        return(0);
}