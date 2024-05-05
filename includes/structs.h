/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/05/05 14:48:02 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"

enum e_keycode
{
	KEY_UP = 87,
	KEY_DOWN = 83,
	KEY_LEFT = 65,
	KEY_RIGHT = 68,
	RESET = 15,
	ESC = 256,
	KEY_P = 80,
	KEY_M = 77,
	KEY_A = 65,
	KEY_D = 68,
	KEY_S = 83,
	KEY_W = 87
};

typedef enum s_type
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	FLOOR,
	CEILING,
	END
}	t_type;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_default
{
	double	px;
	double	py;
	double	pdx;
	double	pdy;
	double	pa;
}	t_default;

typedef struct s_line
{
	double	begin_x;
	double	begin_y;
	double	end_x;
	double	end_y;
}	t_line;

typedef struct s_ray
{
	double	rx;
	double	ry;
	double	ra;
	double	xo;
	double	yo;
	double	vx;
	double	vy;
	double	disth;
	double	distv;
	double	dist;
	int		mx;
	int		my;
}	t_ray;

typedef struct s_player
{
	double			px;
	double			py;
	double			opx;
	double			opy;
	double			pdx;
	double			pdy;
	double			pa;
	double			color;
	char			d;
	mlx_image_t		*p_img;
}	t_player;

typedef struct s_details
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	int		*gen_rgb;
	int32_t	floor_rgb;
	int32_t	ceiling_rgb;
}	t_details;

typedef struct s_map
{
	char	**map;
	int		mini_width;
	int		mini_height;
	int		scale_width;
	int		scale_height;
	int		scale;
	int		pixel_scale;
	int		draw_width;
	int		draw_height;
	bool	show_map;
}	t_map;

typedef struct s_cube
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	mlx_image_t	*mini;
	t_map		*map;
	t_player	player;
	t_line		line;
	t_default	player_default;
	t_details	*details;
	bool		map_start;
	int			details_found;
	int			max_width;
	int			max_height;
}	t_cube;

#endif
