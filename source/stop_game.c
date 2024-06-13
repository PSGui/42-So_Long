#include "../includes/so_long_utils.h"
#include "../includes/so_long.h"

void    end_game_handler(data_t *data, int cause)
{
        if (cause == INVALID_MAP || cause == WINDOW_ERROR)
        {
                ft_printf("Invalid map / Error creating the window!");
                free_map(data);
                mlx_destroy_window(data->mlx_connection, data->mlx_window);
        }
        else if (cause == CONNECTION_ERROR)
        {
                ft_printf("An error has occured while trying to start mlx");
                free(data);
        }
        else if (cause == INVALID_ELEMENT)
        {
                ft_printf("The map contains invalid elements");
                free_map(data);
        }
        else if (cause == ESC_PRESSED)
        {
                free_map(data);
                destroy_images(data);
        }
        exit (0);
}
void    destroy_images(data_t *data)
{
        mlx_destroy_image(data->mlx_connection, data->wall.ptr);
        mlx_destroy_image(data->mlx_connection, data->floor.ptr);
        mlx_destroy_image(data->mlx_connection, data->collectible.ptr);
        mlx_destroy_image(data->mlx_connection, data->player.ptr);
        mlx_destroy_image(data->mlx_connection, data->exit.ptr);
        mlx_destroy_window(data->mlx_connection, data->mlx_window);
        mlx_destroy_display(data->mlx_connection);
        free(data);
}
void	free_map(data_t	*data)
{
	while (data->grid.height > 0)
	{
		free(data->grid.map[data->grid.height - 1]);
		data->grid.height--;
	}
	free(data->grid.map);
        free(data);
	return ;
}