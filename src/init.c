/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcosar <mcosar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:18:07 by eightimerka       #+#    #+#             */
/*   Updated: 2023/07/18 00:39:33 by mcosar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_init_ray_sub(t_raycast *rc)
{
	if (rc->config->plr_ch == 'N')
		rc->ray.dirx = -1;
	if (rc->config->plr_ch == 'S')
		rc->ray.dirx = 1;
	if (rc->config->plr_ch == 'E')
		rc->ray.diry = 1;
	if (rc->config->plr_ch == 'W')
		rc->ray.diry = -1;
	if (rc->config->plr_ch == 'N')
		rc->ray.plany = 0.66;
	if (rc->config->plr_ch == 'S')
		rc->ray.plany = -0.66;
	if (rc->config->plr_ch == 'E')
		rc->ray.planx = 0.66;
	if (rc->config->plr_ch == 'W')
		rc->ray.planx = -0.66;
}

void	ft_init_ray(t_raycast *rc)
{
	rc->data.forward = 0;
	rc->data.back = 0;
	rc->data.left = 0;
	rc->data.right = 0;
	rc->data.rotate_right = 0;
	rc->data.rotate_left = 0;
	rc->ray.posx = (double)rc->config->plr_x + 0.5;
	rc->ray.posy = (double)rc->config->plr_y + 0.5;
	rc->ray.dirx = 0;
	rc->ray.diry = 0;
	rc->ray.planx = 0;
	rc->ray.plany = 0;
	ft_init_ray_sub(rc);
}

void	ft_init_sub(t_raycast *rc)
{
	rc->error = 0;
	rc->data.img = NULL;
	rc->texture[0].img = NULL;
	rc->texture[1].img = NULL;
	rc->texture[2].img = NULL;
	rc->texture[3].img = NULL;
	rc->data.mlx_win = NULL;
}

void	ft_init(t_raycast *rc, t_data *data)
{
	data->map[data->plr_x][data->plr_y] = '0';
	rc->config = data;
	rc->nblines = 0;
	rc->count = 0;
	rc->screenx = 960;
	rc->screeny = 540;
	ft_init_sub(rc);
}

void	check_data_error(void)
{
	write(1, "Error: unable to allocate memory\n", 33);
	exit(1);
}
