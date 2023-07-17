/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eightimerkan <eightimerkan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:16:27 by eightimerka       #+#    #+#             */
/*   Updated: 2023/07/17 21:16:28 by eightimerka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *c, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*arr;
	size_t			len_c;

	i = 0;
	if (!c || !f)
		return (NULL);
	len_c = ft_strlen(c);
	arr = (char *)malloc(sizeof(char) * (len_c + 1));
	if (!arr)
		return (NULL);
	while (c[i])
	{
		arr[i] = (*f)(i, c[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
