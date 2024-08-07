#include "../includes/so_long_utils.h"
#include "../includes/so_long.h"

void    place_sprites(data_t *data, int y, int x)
{
        if (data->grid.map[y][x] == 'E')
	{
		data->exit.x = x * SPRITES; // We save the EXIT coordenates so we are able to
		data->exit.y = y * SPRITES; // place it when the player gets all collectibles
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->exit.ptr, (x * SPRITES), (y * SPRITES));
	}
	else if (data->grid.map[y][x] == '1')
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window, \
			data->wall.ptr, (x * SPRITES), (y * SPRITES));
	else if (data->grid.map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window, \
			data->collectible.ptr, (x * SPRITES), (y * SPRITES));
	else if (data->grid.map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window, \
			data->player.ptr, (x * SPRITES), (y * SPRITES));
	else
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window, \
		data->floor.ptr, (x * SPRITES), (y * SPRITES));
}