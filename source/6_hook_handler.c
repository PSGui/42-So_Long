#include "../includes/so_long_utils.h"
#include "../includes/so_long.h"

void    hook(data_t *data, int action, int mask, int (*f)())
{
        mlx_hook(data->mlx_window, action, mask, f, data);
}

void    key_pressed(int key_numeral, data_t *data)
{
        data->player.mem = 0;
        if (key_numeral == ESC)
		end_game_handler(data, ESC_PRESSED);
	else if (key_numeral == UP)
		go_up(data);
	else if (key_numeral == DOWN)
		go_down(data);
	else if (key_numeral == LEFT)
		go_left(data);
	else if (key_numeral == RIGHT)
		go_right(data);
	return (0);
}

void    close_it(data_t *data)
{
        if (data)
	{
		if (data->mlx_connection && data->mlx_window)
			mlx_destroy_window(data->mlx_connection, data->mlx_window);
		free(data); 
	}
	exit (0);
}

void    restore_game(data_t *data)
{
        if (data)
	{
		
	}
}