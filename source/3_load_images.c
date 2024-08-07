#include "../includes/so_long_utils.h"
#include "../includes/so_long.h"

void    load_images(data_t *data)
{
        data->player = load_sprite(data->mlx_connection, PLAYER_PATH);
        data->collectible = load_sprite(data->mlx_connection, COLLECTIBLE_PATH);
        data->wall = load_sprite(data->mlx_connection, WALL_PATH);
        data->floor = load_sprite(data->mlx_connection, FLOOR_PATH);
        data->exit = load_sprite(data->mlx_connection, EXIT_PATH);

        return ;
}