#ifndef SO_LONG_UTILS_H
# define SO_LONG_UTILS_H

// Defines that represent multiple actions that can be taken by the user

# define UP		119
# define DOWN	115
# define LEFT	97
# define RIGHT	100
# define ESC	65307

# define KEY_RELEASE	3
# define DESTROY_NOTIFY	17
# define EXPOSE		12

# define KEY_RELEASE_MASK	2
# define NO_EVENT_MASK		0
# define EXPOSURE_MASK		32768

// Defining game ending events to make life easier when closing the game

# define INVALID_MAP 10
# define CONNECTION_ERROR 20
# define WINDOW_ERROR 30
# define INVALID_ELEMENT 40
# define ESC_PRESSED 50

// Defining the window name and the size of the sprites (32x32)

# define WINDOW_NAME	"./so_long"
# define SPRITES	32

// Structure to keep count of the amount of each "object"

typedef struct
{
	int		free_space;
	int		collectible;
	int		exit;
	int		player_start;
	int		move_count;
}       objcount_t;

// Structure responsible for the map, including its height and width and the
// line that is being read

typedef struct
{
        int             height;
        int             width;
        char    **map;
        char    *line_read;
}       drawmap_t;

// Structure that helps with the sprite placement using its location in the axis

typedef struct
{
	void	*ptr;
	int		*pix;
	int		line_s; // size of the line
	int		mem;
	int		x;
	int		y;
	int		movements;
}	sprite_t;

// Structure keeping track of where we are in the 2D dimension

typedef struct
{
        int     x;
        int     y;
}       axis_t;

// Main structure that is used in almost every function, nesting other structures

typedef struct
{
	void		*mlx_connection; // MLX pointer
	void		*mlx_window; // MLX window pointer
        drawmap_t       dim;
        drawmap_t       grid;
        objcount_t      i;
        axis_t          xy;
        sprite_t	player;
        sprite_t	floor;
        sprite_t	wall;
        sprite_t	collectible;
        sprite_t	exit;
}       data_t;

#endif