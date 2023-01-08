/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:51:39 by fsanches          #+#    #+#             */
/*   Updated: 2023/01/08 17:25:16 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_stack_swap(t_stack **stack)
{
	t_list	*a;
	t_list	*b;

	a = (*stack)->list;
	b = a->next;
	if (!b)
		return ;
	a->next = b->next;
	b->next = a;
	(*stack)->list = b;
}

void	ft_stack_push(t_data *data, int id)
{
	t_stack	*from;
	t_stack	*to;
	t_list	*moved;

	if (id == A)
	{
		from = data->b;
		to = data->a;
	}
	else
	{
		from = data->a;
		to = data->b;
	}
	moved = from->list;
	from->list = from->list->next;
	moved->next = NULL;
	ft_list_add_front(&(to->list), moved);
	ft_stack_range(&from);
	ft_stack_range(&to);
}

void	ft_stack_rotate(t_stack **stack)
{
	t_list	*moved;
	t_list	**list;

	moved = (*stack)->list;
	(*stack)->list = (*stack)->list->next;
	moved->next = NULL;
	list = &(*stack)->list;
	ft_list_add_back(list, moved);
}

void	ft_stack_reverse_rotate(t_stack **stack)
{
	t_list	*moved;
	t_list	*temp;
	size_t	list_size;
	size_t	i;

	list_size = ft_list_len((*stack)->list);
	moved = ft_list_last((*stack)->list);
	moved->next = (*stack)->list;
	(*stack)->list = moved;
	temp = (*stack)->list;
	i = 0;
	while (++i < list_size)
		temp = temp->next;
	temp->next = NULL;
}
