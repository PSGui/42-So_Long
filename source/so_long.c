#include "so_long_utils.h"
#include "so_long.h"

int     main(int argc, char *argv[])
{
        data_t data;

        if (argc != 2)
        {
                ft_printf("Error! Make sure the input looks like this: ./so_long <map_name>.ber");
                return (1);
        }
        if (argc == 2)
        {
                if (check_ber_file(argv[1]))
                {
                        start_game(&data, argv[1]);
                }
                else
                {
                        ft_printf("Wrong file format! Make sure it ends with .ber");
                        return (1);
                }
        }
        return (0);
}

static bool	check_ber_file(const char *map_name)
{
	char	*string;

	string = ft_strrchr(map_name, '.');
	if (string)
		return (ft_strcmp(string, ".ber") == 0);
	return (false);
}

void    start_game(data_t *data, char *map_path)
{
        start_map(data, map_path);
        start_window(data);
        load_images(data);
        check_map(data);
        hook(data, KEY_RELEASE, KEY_RELEASE_MASK, key_pressed);
        hook(data, DESTROY_NOTIFY, NO_EVENT_MASK, close_it);
        hook(data, EXPOSE, EXPOSURE_MASK, restore_game);
        mlx_loop(data->mlx_connection);
        free(data);
}