/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:52:50 by fsanches          #+#    #+#             */
/*   Updated: 2022/12/06 18:52:54 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*ft_list_new(int number)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->number = number;
	new->next = NULL;
	return (new);
}

t_list	*ft_list_last(t_list *list)
{
	t_list	*last;

	if (!list)
		return (NULL);
	last = list;
	while (last->next)
		last = last->next;
	return (last);
}

int	ft_list_at(t_stack *stack, size_t index)
{
	t_list	*elem;
	size_t	i;

	i = 0;
	elem = stack->list;
	while (i != index)
	{
		i++;
		elem = elem->next;
	}
	return (elem->number);
}

void	ft_list_add_back(t_list **list, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!(*list))
		*list = new;
	else
	{
		temp = ft_list_last(*list);
		temp->next = new;
	}
}

void	ft_list_add_front(t_list **list, t_list *new)
{
	t_list	*elem;

	if (*list == NULL)
		*list = new;
	else
	{
		elem = new;
		elem->next = *list;
		*list = elem;
	}
}
