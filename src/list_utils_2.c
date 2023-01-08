/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:52:33 by fsanches          #+#    #+#             */
/*   Updated: 2022/12/06 18:52:39 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_clear_list(t_list **list)
{
	t_list	*temp;

	while (*list)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp);
	}
}

size_t	ft_list_len(t_list *list)
{
	size_t	size;

	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}

int	ft_is_sorted(t_list *list, int id)
{
	t_list	*aux;
	t_list	*next;

	aux = list;
	next = list->next;
	while (next)
	{
		if (aux->number >= next->number && id == ASCENDING)
			return (0);
		if (aux->number <= next->number && id == DESCENDING)
			return (0);
		aux = aux->next;
		next = next->next;
	}
	return (1);
}
