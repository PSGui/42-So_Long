#include "../includes/so_long_utils.h"
#include "../includes/so_long.h"

void    start_window(data_t *data)
{
        data->mlx_connection = mlx_init();
        if (data->mlx_connection == NULL)
                //end_game_handler(data, CONNECTION_ERROR);
        /*if (invalid_game_plot(data))
        {
                free_map(data);
                mlx_destroy_display(data->mlx_connection);
                free(data->mlx_connection);
                //end_game_handler(data, INVALID_MAP);
        }
        else*/
        //{
                data->xy.x = data->grid.width * SPRITES;
                data->xy.y = data->grid.height * SPRITES;
                data->mlx_window = mlx_new_window(data->mlx_connection,
                data->xy.x, data->xy.y, WINDOW_NAME);
                //if ((!data->mlx_window) == NULL)
                        //end_game_handler(data, WINDOW_ERROR);
       // }
}

bool	invalid_game_plot(data_t *data)
{
	axis_t	screen_dim;

	mlx_get_screen_size(data->mlx_connection, &screen_dim.x, &screen_dim.y);
	return (((data->dim.width * SPRITES) > screen_dim.x)
		|| ((data->dim.height * SPRITES) > screen_dim.y));
}

sprite_t        load_sprite(void *ptr, char *path)
{
        sprite_t        sprite;

        sprite.ptr = mlx_xpm_file_to_image(ptr, path, &sprite.x, &sprite.y);
        return (sprite);
}