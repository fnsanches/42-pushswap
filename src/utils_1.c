/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:51:18 by fsanches          #+#    #+#             */
/*   Updated: 2022/12/06 18:51:21 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	ft_count_lowers(t_stack *stack)
{
	t_list	*aux;
	int		first;
	size_t	lowers;

	if (!stack->list)
		return (0);
	aux = stack->list;
	first = aux->number;
	lowers = 0;
	while (aux)
	{
		if (first < aux->number)
			lowers++;
		aux = aux->next;
	}
	return (lowers);
}

size_t	ft_count_moves(int *position)
{
	if (position[A] * position[B] > 0)
	{
		if (position[A] > 0)
		{
			if (position[A] > position[B])
				return (position[A]);
			return (position[B]);
		}
		else if (position[A] < position[B])
			return (-position[A]);
		else
			return (-position[B]);
	}
	else
		return (ft_abs(position[A]) + ft_abs(position[B]));
}

void	ft_find_coef(t_data	*data)
{
	if (data->a->size >= 50)
	{
		data->coef[A] = 0.67;
		data->coef[B] = 0.2;
	}
	else
	{
		data->coef[A] = 0.33;
		data->coef[B] = 0.5;
	}
}

void	ft_print_movement(int operation, int stack_id)
{
	if (operation == SWAP)
		write(1, "s", 1);
	else if (operation == PUSH)
		write(1, "p", 1);
	else if (operation == ROTATE)
		write(1, "r", 1);
	else if (operation == REVERSE_ROTATE)
		write(1, "rr", 2);
	if (stack_id == A)
		write(1, "a\n", 2);
	else if (stack_id == B)
		write(1, "b\n", 2);
	else if (stack_id == R && operation != SWAP)
		write(1, "r\n", 2);
	else
		write(1, "s\n", 2);
}
