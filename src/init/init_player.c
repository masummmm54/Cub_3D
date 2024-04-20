/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:50:28 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/20 13:11:02 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

int32_t	pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_pixel(t_cube *cube)
{
	int	x;
	int	y;

	x = 80;
	while (++x < 100)
	{
		y = 80;
		while (++y < 100)
			mlx_put_pixel(cube->image, cube->player.px + x, cube->player.py + y,
				pixel(255, 2555, 255, 255));
	}
}

void	init_player(t_cube *cube)
{
	cube->player.py = cube->max_height / 2;
	cube->player.px = cube->max_width / 2;
}
