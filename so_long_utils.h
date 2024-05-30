#ifndef SO_LONG_UTILS_H
# define SO_LONG_UTILS_H

# define UP		119
# define DOWN	115
# define LEFT	97
# define RIGHT	100
# define ESC	65307
# define WINDOW_NAME	"./so_long"
# define SPRITE_SIZE	32

typedef struct
{
	int		free_space;
	int		collectible;
	int		exit;
	int		player_start;
	int		move_count;
}       objcount_t;

typedef struct
{
        int             height;
        int             width;
        char    **map;
        char    *line_read;
}       drawmap_t;


typedef struct
{
	void		*mlx_connection; // MLX pointer
	void		*mlx_window; // MLX window pointer
        drawmap_t       dim;
        drawmap_t       grid;
        objcount_t      i;

}       data_t;

#endif