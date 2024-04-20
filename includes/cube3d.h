/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:22:05 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/20 13:13:37 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# define WIDTH 1920
# define HEIGHT 1080

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include "structs.h"
# include "../libft/includes/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

//check args
t_cube	check_args(int argc, char **argv);
t_cube	check_map(char *map, t_cube *temp_cube);
void	check_invalid_chars(char *line);
void	check_map_perimeter(t_cube *cube);

//get map details
void	find_map_width(char *line, t_cube *cube);

//map parsing
t_cube	fill_map(t_cube *cube, char *map);
void	add_map_conditions(t_cube *cube, char *line, int row);

//initialization
int32_t	init_mlx(t_cube *cube);
void	init_cube(t_cube **cube, t_cube *temp_cube);
void	init_map(t_cube *cube);
void	hook(void *param);

//drawing processes
void	draw_pixel(t_cube *cube);
int32_t	pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void	draw_grid_basic(t_cube *cube);
void	user_input(void *param);

//utils
void	print_error_exit(int flag);
void	free_print_exit(t_cube *cube, int flag, int i);
void	final_free(t_cube *cube);
void	print_map(t_cube *cube);




void	background(void *param);



#endif
