/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eightimerkan <eightimerkan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:18:20 by eightimerka       #+#    #+#             */
/*   Updated: 2023/07/23 00:20:56 by eightimerka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_string(char c)
{
	if (c != ' ' && c != '\n' && c != '\t')
		return (1);
	return (0);
}

void	parse_values(int *i, t_data *data, char **param)
{
	int	pos;

	pos = 0;
	if (*param)
	{
		write(1, "Error: parameter already exists\n", 32);
		exit(1);
	}
	while (data->file[*i] && (data->file[*i] == ' ' || data->file[*i] == '\t'))
		(*i)++;
	pos = *i;
	while (data->file[*i] && data->file[*i] != ' ' && data->file[*i] != '\n'
		&& data->file[*i] != '\t')
		(*i)++;
	if (pos == (*i))
	{
		write(1, "Error: parameter is blank\n", 26);
		exit(1);
	}
	*param = ft_substr(data->file, pos, (*i) - pos);
}

int	map_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
			{
				if (!(data->map[i][j + 1] && data->map[i + 1][j] &&
						data->map[i - 1][j] && data->map[i][j - 1]))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	init_data_proces(t_data **data, char **argv)
{
	init_data(*data);
	read_file(*data, argv[1]);
	parse_data(*data);
	init_player(*data);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	t_raycast	rc;

	if (argc != 2 || ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4))
	{
		write(2, "Error: try ./cub3d <map_file.cub>\n", 34);
		return (1);
	}
	else
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
			check_data_error();
		init_data_proces(&data, argv);
		if (map_check(data))
		{
			printf("MAP ERROR\n");
			return (1);
		}
		ft_init(&rc, data);
		ft_count_lines(&rc);
		ft_mlx(&rc);
	}
}
