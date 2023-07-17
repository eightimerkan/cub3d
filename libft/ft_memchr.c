/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eightimerkan <eightimerkan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:14:02 by eightimerka       #+#    #+#             */
/*   Updated: 2023/07/17 21:14:03 by eightimerka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)arr;
	while (n-- != 0)
	{
		if (*p == (unsigned char) c)
			return (p);
		p++;
	}
	return (NULL);
}
