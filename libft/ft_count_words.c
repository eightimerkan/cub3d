/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eightimerkan <eightimerkan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:12:51 by eightimerka       #+#    #+#             */
/*   Updated: 2023/07/17 21:12:52 by eightimerka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(const char *s, char c)
{
	int		len;
	size_t	j;

	j = 0;
	len = 0;
	while (s[len])
	{
		while (s[len] == c && s[len] != '\0')
			len++;
		if (s[len] != c && s[len])
			j++;
		while (s[len] != c && s[len])
			len++;
	}
	return (j);
}
