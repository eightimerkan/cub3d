/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_create_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eightimerkan <eightimerkan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:19:08 by eightimerka       #+#    #+#             */
/*   Updated: 2023/07/22 23:14:10 by eightimerka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_size_map(int i, t_data *data)
{
	int	size;
	int	save;

	size = 0;
	save = 1;
	while (i < ft_strlen(data->file))
	{
		if (data->file[i] == '\n' || i == ft_strlen(data->file) - 1)
			++size;
		++i;
	}
	--i;
	while (i >= 0 && (data->file[i] == ' ' || data->file[i] == '\n'
			|| data->file[i] == '\t'))
	{
		--i;
		if (data->file[i] == '\n')
			++save;
	}
	return (size - save);
}

void	check_first_last_string(int j, t_data *data)
{
	int	i;

	i = 0;
	while (data->map[j][i])
	{
		if (data->map[j][i] != '1' && check_s_t(data->map[j][i], 1))
		{
			write(1, "Error: parameters problem\n", 26);
			exit(1);
		}
		i++;
	}
}

void	make_array_map(int i, t_data *data)
{
	int	save_i;
	int	size;
	int	j;

	j = 0;
	save_i = i;
	size = check_size_map(i, data);
	i = save_i;
	data->map = (char **)malloc(sizeof(char *) * (size + 2));
	if (!data->map)
		exit(1);
	while (i > 0 && data->file[i - 1] != '\n')
		--i;
	while (j < size + 1)
	{
		i = check_n(i, data, &data->map[j]);
		++j;
	}
	data->map[j] = NULL;
}

static void	create_error(int i)
{
	if (i == 1)
	{
		write(1, "Error: parameters problem\n", 26);
		exit(1);
	}
	if (i == 2)
	{
		write(1, "Error: map is open\n", 19);
		exit(1);
	}
	if (i == 3)
	{
		write(1, "Error: map error\n", 17);
		exit(1);
	}
}

void	map_error(t_data *data)
{
	int	i;
	int	j;

	j = 1;
	check_first_last_string(0, data);
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i] && check_s_t(data->map[j][i], 0))
			i++;
		if (i == 0 && data->map[j][i] == '\0')
			create_error(1);
		if (data->map[j][i] && data->map[j][i] != '1')
			create_error(2);
		check_error(data, j, i);
		j++;
		if (!data->map[j + 1])
		{
			check_first_last_string(j, data);
			break ;
		}
	}
	if (!data->plr_ch)
		create_error(3);
}
