/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eightimerkan <eightimerkan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:16:52 by eightimerka       #+#    #+#             */
/*   Updated: 2023/07/17 21:16:53 by eightimerka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char const *s, size_t n)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * n + 1);
	if (!str)
		return (NULL);
	str = ft_mystrncpy(str, s, n);
	return (str);
}
