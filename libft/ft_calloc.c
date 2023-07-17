/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eightimerkan <eightimerkan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:12:44 by eightimerka       #+#    #+#             */
/*   Updated: 2023/07/17 21:12:45 by eightimerka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*arr;
	size_t	i;

	i = 0;
	arr = malloc(size * num);
	if (!arr)
		return (NULL);
	while (i < (num * size))
	{
		arr[i] = '\0';
		i++;
	}
	return ((void *) arr);
}
