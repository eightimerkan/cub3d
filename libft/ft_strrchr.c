/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eightimerkan <eightimerkan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:17:15 by eightimerka       #+#    #+#             */
/*   Updated: 2023/07/17 21:17:15 by eightimerka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	i;

	i = (size_t) ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == ch)
			return ((char *)str + i);
		i--;
	}
	if (str[i] == ch)
		return ((char *)str + i);
	return (NULL);
}
