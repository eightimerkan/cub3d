/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eightimerkan <eightimerkan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:19:37 by eightimerka       #+#    #+#             */
/*   Updated: 2023/06/22 18:19:38 by eightimerka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	to_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	ft_count(const char *s, char c)
{
	size_t	i;
	int		counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			counter++;
		while ((s[i]) && (s[i] != c))
			i++;
	}
	if (counter != 3 || s[i - 1] == c)
	{
		write(1, "Error: problems with parameters\n", 32);
		exit(1);
	}
	return (counter);
}

void	free_param(char **param)
{
	int	i;

	i = 0;
	while (param[i])
	{
		free(param[i]);
		i++;
	}
	free(param);
}

bool	check_s_t(char a, int check)
{
	if (check)
		return (a != ' ' && a != '\t');
	return (a == ' ' || a == '\t');
}

void	check_map_error(void)
{
	write(1, "Error: map error\n", 17);
	exit(1);
}
