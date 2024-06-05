#include "so_long_utils.h"
#include "so_long.h"

void    get_sprite_image(data_t *data)
{
        data->player = load_sprite(data->mlx_connection, PLAYER_PATH);
        data->collectible = load_sprite(data->mlx_connection, COLLECTIBLE_PATH);
        data->wall = load_sprite(data->mlx_connection, WALL_PATH);
        data->floor = load_sprite(data->mlx_connection, FLOOR_PATH);
        data->exit = load_sprite(data->mlx_connection, EXIT_PATH);
        return ;
}

sprite_t        load_sprite(void *ptr, char *path)
{
        sprite_t        sprite;

        sprite.ptr = mlx_xpm_file_to_image(ptr, path, &sprite.x, &sprite.y);
        return (sprite);
}