/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:50:54 by fsanches          #+#    #+#             */
/*   Updated: 2022/12/06 18:51:06 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static size_t	ft_position_by_max(t_stack *stack, size_t max_i);

int	ft_get_push_away_id(t_data *data)
{
	int	is_a;
	int	is_b;

	is_a = !(ft_count_lowers(data->a) > data->a->size * data->coef[A]);
	is_b = ft_count_lowers(data->b) > data->b->size * data->coef[B];
	if (is_a && is_b)
		return (R);
	else if (is_a)
		return (A);
	else if (is_b)
		return (B);
	return (-1);
}

int	ft_get_sort_five_rotate_id(t_data *data)
{
	int	number;
	int	last;
	int	is_a;
	int	is_b;

	number = data->a->list->number;
	last = ft_list_last(data->a->list)->number;
	is_a = number > last;
	if (data->b->size < 2)
	{
		if (is_a)
			return (A);
		else
			return (-1);
	}
	number = data->b->list->number;
	last = ft_list_last(data->b->list)->number;
	is_b = number < last;
	if (is_a && is_b)
		return (R);
	else if (is_a)
		return (A);
	return (-1);
}

int	ft_get_sort_five_swap_id(t_data *data)
{
	int	number;
	int	next;
	int	is_a;
	int	is_b;

	number = data->a->list->number;
	next = data->a->list->next->number;
	is_a = number > next;
	if (data->b->size < 2)
	{
		if (is_a)
			return (A);
		else
			return (-1);
	}
	number = data->b->list->number;
	next = data->b->list->next->number;
	is_b = number < next;
	if (is_a && is_b)
		return (R);
	else if (is_a)
		return (A);
	return (-1);
}

int	ft_get_position(t_stack *stack, int nb)
{
	size_t	i;
	size_t	max_i;
	t_list	*curr;
	t_list	*last;

	i = 0;
	max_i = 0;
	curr = stack->list;
	last = ft_list_last(stack->list);
	while (curr)
	{
		if (nb < curr->number && nb > last->number)
		{
			if (i <= stack->size - i)
				return (i);
			return (-(stack->size - i));
		}
		if (curr->number > ft_list_at(stack, max_i))
			max_i = i;
		last = curr;
		curr = curr->next;
		i++;
	}
	return (ft_position_by_max(stack, ++max_i));
}

static size_t	ft_position_by_max(t_stack *stack, size_t max_i)
{
	if (max_i > stack->size / 2)
		return (-(stack->size - max_i));
	return (max_i);
}
