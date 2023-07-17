/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eightimerkan <eightimerkan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:15:22 by eightimerka       #+#    #+#             */
/*   Updated: 2023/07/17 21:15:22 by eightimerka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_quote(const char *str, int ch)
{
	char	*p;
	char	*end;

	p = (char *)str;
	if (!p)
		return (p);
	while (*p && *p != ch)
	{
		if (*p == '"' || *p == '\'')
		{
			end = ft_strchr(p + 1, *p);
			p += end - p + 1;
		}
		else
			p++;
	}
	if (*p == ch)
		return (p);
	return (NULL);
}
