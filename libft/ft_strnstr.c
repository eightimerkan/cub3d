/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eightimerkan <eightimerkan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:16:57 by eightimerka       #+#    #+#             */
/*   Updated: 2023/07/17 21:17:07 by eightimerka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dst, const char *src, size_t n)
{
	size_t	len_2;

	len_2 = ft_strlen(src);
	if (src[0] == '\0')
		return ((char *) dst);
	while (*dst != '\0' && n-- >= len_2)
	{
		if (*dst == *src && ft_memcmp(dst, src, len_2) == 0)
			return ((char *) dst);
		dst++;
	}
	return (NULL);
}
