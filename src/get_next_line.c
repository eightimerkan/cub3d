/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eightimerkan <eightimerkan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:18:00 by eightimerka       #+#    #+#             */
/*   Updated: 2023/06/22 18:18:02 by eightimerka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_atoi(const char *str)
{
	char		*s;
	int			result;
	int			i;
	short int	sign;

	i = 0;
	sign = 1;
	result = 0;
	s = (char *)str;
	while (s[i] == '\t' || s[i] == '\r' || s[i] == '\n' \
	|| s[i] == ' ' || s[i] == '\f' || s[i] == '\v')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{	
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = (result * 10) + (s[i] - '0');
		i++;
	}
	return (result * sign);
}

static void	ft_finish(char *tmp, char **line, char c, int i)
{
	tmp[i] = c;
	tmp[i + 1] = 0;
	free(*line);
	*line = tmp;
}

static int	ft_exit_m(char **line)
{
	free(*line);
	return (-1);
}

static void	ft_fill(char *tmp, char **line, int *i)
{
	tmp[*i] = (*line)[*i];
	(*i)++;
}

int	get_next_line(int fd, char **line)
{
	int		i;
	int		len;
	int		r;
	char	c;
	char	*tmp;

	r = 0;
	len = 1;
	*line = malloc(len);
	(*line)[0] = 0;
	if (!line)
		return (-1);
	r = read(fd, &c, 1);
	while (r && len++ && c != '\n')
	{
		tmp = malloc(len);
		if (!tmp)
			ft_exit_m(line);
		i = 0;
		while (i < len - 2)
			ft_fill(tmp, line, &i);
		ft_finish(tmp, line, c, i);
		r = read(fd, &c, 1);
	}
	return (r);
}
