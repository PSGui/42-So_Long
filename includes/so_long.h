#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"
#include "../libft/libft.h"

#include <stdbool.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

# define ERROR 1

# define WALL_PATH		"./game_assets/wall_sprite.xpm"
# define FLOOR_PATH		"./game_assets/floor_sprite.xpm"
# define COLLECTIBLE_PATH	"./game_assets/collectible_sprite.xpm"
# define EXIT_PATH	"./game_assets/exit_sprite.xpm"
# define PLAYER_PATH		"./game_assets/player_spritee.xpm"

// All function prototypes are organized by the order that they appear in the "start_game" function located on the so_long.c file

// So_long

void    start_game(data_t *data, char *map_path);

// Start_map

void            start_map(data_t *data, char *map_path);
int                     open_map_file(char *map_path);
void            read_map_file(data_t *data, int fd);
char            *reconstruct_map(char *s1, char *s2);
void            object_counter(data_t *data, char *map_string);
void            check_counter_values(data_t *data, char *map_string);
int                     height_equals_lines_check(data_t *data);

// Start_window

void            start_window(data_t *data);
bool	        invalid_game_plot(data_t *data);
sprite_t        load_sprite(void *ptr, char *path);

// Load_images

void            load_images(data_t *data);
sprite_t        load_sprite(void *ptr, char *path);

// Check_map

void            check_map(data_t *data);
void            check_map_errors(data_t *data, int y, int x);
bool	        walls(data_t *data, int y, int x);
bool	        rectangular(data_t *data);
bool	        valid_game_element(data_t *data, int y, int x);

// Place_sprite

void    place_sprites(data_t *data, int y, int x);

// Hook_handler

void            hook(data_t *data, int action, int mask, int (*f)());
void            key_pressed(int key_numeral, data_t *data);
void            close_it(data_t *data);
void            retore_game(data_t *data);

// Movements

void    go_up(data_t *data);
void    go_down(data_t *data);
void    go_left(data_t *data);
void    go_right(data_t *data);

// Stop_game

void            end_game_handler(data_t *data, int cause);
void            destroy_images(data_t *data);
void	        free_map(data_t	*data);

#endif
