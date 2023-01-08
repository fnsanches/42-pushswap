/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:56:47 by fsanches          #+#    #+#             */
/*   Updated: 2022/12/06 18:56:47 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	ch;

	ch = (unsigned char)c;
	len = ft_strlen((char *)s);
	if (ch == '\0')
		return ((char *)(&s[len]));
	while (--len >= 0)
	{
		if (s[len] == ch)
			return ((char *)(&s[len]));
	}
	return (NULL);
}
