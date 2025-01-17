/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:09:41 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/10 19:04:44 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <math.h>
# include "structs_bonus.h"
# include "../libft/includes/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define PI 3.1415926535
# define WIDTH 1920
# define HEIGHT 1080
# define MIN_MAP_SIZE 300
# define MAX_MAP_SIZE 1000
# define PIXEL_PER_CELL 15

# define MAPSIZE 64
# define FPOV 66

# define ROTATIONSPEED 3
# define MOVESPEED 0.05
# define STOP 2

# define PATH1 "./images/guns/1.png"
# define PATH2 "./images/guns/2.png"

//check args
t_check	check_args(int argc, char **argv);
void	check_map(char *map, t_check *temp_cube);
void	check_map_perimeter(t_cube *cube);
void	multiple_start_pos(t_cube *cube);
int		check_multiple_details(t_check *temp_cube);
void	check_details(t_check *temp_cube, char *line);
t_type	get_state_begin(char *line);
void	check_correct_detail_arg(char *line, int i);
void	check_invalid_chars(t_check *temp_cube, char *line);
int		check_empty_line(t_check *cube, char *line);

//get map details
void	find_map_width(char *line, t_check *temp_cube);
void	convert_floor(t_cube *cube);
void	convert_ceiling(t_cube *cube);
int		count_double(char **rgb);
int		check_numbers(int *rgb, int count);
void	convert_to_rgb(t_cube *cube, int flag, int count);
int		check_invalid_integers(char **rgb);

//rays
void	draw_ray(t_cube *cube);
t_ray	init_ray(t_player player);
void	set_ray(t_ray *ray);
void	setup_ray(t_ray *ray);
int		is_done(t_cube *cube, int x, int y);
int		is_done_bonus_v(t_cube *cube, t_ray *ray, int x, int y);
int		is_done_bonus_h(t_cube *cube, t_ray *ray, int x, int y);
double	find_dist(t_ray *ray, t_player player);

//hooks
void	user_input(mlx_key_data_t keys, void *param);
void	user_input_two(void *param);
void	mouse_hook(mouse_key_t button, action_t action,
			modifier_key_t mods, void *param);
void	cursour_hook(double xpos, double ypos, void *param);
void	read_keys(t_cube *cube);
void	key_up(t_cube *cube);
void	key_down(t_cube *cube);
void	key_left(t_cube *cube);
void	key_right(t_cube *cube);
void	key_a(t_cube *cube);
void	key_d(t_cube *cube);
void	key_pause(t_cube *cube);
void	close_mini_map(t_cube *cube);
void	handle_fire(t_cube *cube);
void	handle_fire_two(t_cube *cube);

//map parsing
t_cube	parse_map(t_cube *cube, char *map);
void	new_map(t_cube *cube, int index);
void	get_west_east(t_cube *cube, char *line, int index);
void	get_north_south(t_cube *cube, char *line, int index);
void	get_floor_ceiling(t_cube *cube, char *line, int index);
void	flood_fill(t_cube *cube, int x, int y);
t_point	get_point(int x, int y);
int		get_details(t_cube *cube, char *line);
t_type	get_state(char *line);
int		check_empty_line_parse(t_cube *cube, char *line);

//initialization
int32_t	init_mlx(t_cube *cube);
void	init_cube(t_cube **cube, t_check temp_cube);
void	init_map(t_cube *cube);
void	init_player(t_cube *cube);
void	init_textures(t_cube *cube);
t_line	init_line(double beginx, double beginy, double endx, double endy);
void	init_default_player(t_cube *cube);
void	reset_players_values(t_cube *cube);
int32_t	init_2d_map(t_cube *cube);
void	delete_instructs_images(t_cube *cube);
void	init_instructions(t_cube *cube);

//drawing processes
int		draw_line(mlx_image_t *image, t_line line, int color);
void	draw_pixel(t_cube *cube);
void	find_pl_pos(t_cube *cube);
int		find_pos(t_cube *cube, char c);
void	two_d_map(void *param);
void	draw_door(t_cube *cube, t_ray ray, int i);
void	draw_3d(t_cube *cube, t_ray ray, int i);
int32_t	pixel(int32_t r, int32_t g, int32_t b, int32_t a);

//textures
void	init_textures(t_cube *cube);
void	draw_images_xpm42(t_cube *cube, mlx_texture_t tex);
void	init_guns(t_cube *cube);
void	init_door(t_cube *cube);

//gameplay
int		is_wall_collision(t_cube *cube, int x, int y);
void	put_instructions(t_cube *cube);

//utils
void	check_if_details(t_check *temp_cube);
void	print_map(t_cube *cube);
double	degtorad(double a);
double	fixang(double a);
void	check_defines(void);
int		whitespace_skip(char c);

//free and messages
void	print_error_exit(int flag);
void	free_print_exit(t_cube *cube, int flag, int i);
void	free_print_exit_two(t_cube *cube, t_point *stack, int flag);
void	free_print_exit_three(t_cube *cube, int flag);
void	final_free(t_cube *cube);
void	free_rgb(char **rgb);

//char checkers
int		correct_chars(char c);
int		map_valid_chars(char c);
int		edge_conditions(char c);

#endif
