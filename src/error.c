/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eightimerkan <eightimerkan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:17:50 by eightimerka       #+#    #+#             */
/*   Updated: 2023/06/23 17:01:10 by eightimerka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_exit(t_raycast *rc)
{
	if (rc->data.img)
		mlx_destroy_image(rc->data.mlx_ptr, rc->data.img);
	if (rc->texture[0].img)
		mlx_destroy_image(rc->data.mlx_ptr, rc->texture[0].img);
	if (rc->texture[1].img)
		mlx_destroy_image(rc->data.mlx_ptr, rc->texture[1].img);
	if (rc->texture[2].img)
		mlx_destroy_image(rc->data.mlx_ptr, rc->texture[2].img);
	if (rc->texture[3].img)
		mlx_destroy_image(rc->data.mlx_ptr, rc->texture[3].img);
	if (rc->data.mlx_win)
		mlx_destroy_window(rc->data.mlx_ptr, rc->data.mlx_win);
	exit(0);
}

void	ft_error(t_raycast *rc, char *str)
{
	rc->error = 1;
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	ft_exit(rc);
}
