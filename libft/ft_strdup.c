/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eightimerkan <eightimerkan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:15:48 by eightimerka       #+#    #+#             */
/*   Updated: 2023/07/17 21:15:49 by eightimerka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*p;

	len = ft_strlen(str) + 1;
	p = (char *)malloc(sizeof(char) * len);
	if (!p)
		return (NULL);
	p = ft_memcpy(p, str, len);
	return (p);
}
