/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eightimerkan <eightimerkan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:13:44 by eightimerka       #+#    #+#             */
/*   Updated: 2023/07/17 21:13:45 by eightimerka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
					size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			count;

	count = 0;
	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	while (count < n)
	{
		if (p2[count] == (unsigned char ) c)
		{
			p1[count] = p2[count];
			count++;
			return ((void *)p1 + count);
		}
		p1[count] = p2[count];
		count++;
	}
	return (NULL);
}
