#include "../includes/so_long_utils.h"
#include "../includes/so_long.h"

void    check_map(data_t *data)
{
        axis_t  axis;

        axis.y = 0;
	while (data->grid.map[axis.y])
	{
		axis.x = 0;
		while (data->grid.map[axis.y][axis.x])
		{
			check_map_errors(data, axis.y, axis.x);
	                axis.x++;
		}
		axis.y++;
	}
	return ;
}

void    check_map_errors(data_t *data, int y, int x)
{
	if (!walls(data, y, x))
	{
		end_game_handler(data, INVALID_MAP);
	}
	else if (!rectangular(data))
	{
		end_game_handler(data, INVALID_MAP);
	}
	else if (!valid_game_element(data, y, x))
	{
		end_game_handler(data, INVALID_ELEMENT);
	}
	place_sprites(data, y, x);
	return ;
}

bool	walls(data_t *data, int y, int x)
{
	int	max_h;
	int	max_w;

	max_h = data->grid.height - 1;
	max_w = data->grid.width - 1;
	if (data->grid.map[max_h][x] != '1' || data->grid.map[0][x] != '1' ||
	data->grid.map[y][max_w] != '1' || data->grid.map[0][max_w] != '1')
	{
		return (false);
	}
	return (true);
}

bool	rectangular(data_t *data)
{
	if (data->grid.height == data->grid.width)
	{
		return (false);
	}
	return (true);
}

bool	valid_game_element(data_t *data, int y, int x)
{
	if (!ft_strrchr("ECP01", data->grid.map[y][x]))
	{
		return (false);
	}
	return (true);
}