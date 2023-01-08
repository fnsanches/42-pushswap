/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:57:38 by fsanches          #+#    #+#             */
/*   Updated: 2022/12/06 18:57:38 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	ch = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *)(&s[i]));
		i++;
	}
	if (ch == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
