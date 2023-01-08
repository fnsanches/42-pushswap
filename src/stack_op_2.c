/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:51:33 by fsanches          #+#    #+#             */
/*   Updated: 2022/12/06 18:51:35 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_data *data, int id, int is_print)
{
	if (id == A)
		ft_stack_swap(&data->a);
	else if (id == B)
		ft_stack_swap(&data->b);
	else if (id == R)
	{
		ft_stack_swap(&data->a);
		ft_stack_swap(&data->b);
	}
	if (is_print)
		ft_print_movement(SWAP, id);
}

void	ft_push(t_data *data, int id, int is_print)
{
	if (id == R)
		return ;
	ft_stack_push(data, id);
	if (is_print)
		ft_print_movement(PUSH, id);
}

void	ft_rotate(t_data *data, int id, int is_print)
{
	if (id == A)
		ft_stack_rotate(&data->a);
	else if (id == B)
		ft_stack_rotate(&data->b);
	else if (id == R)
	{
		ft_stack_rotate(&data->a);
		ft_stack_rotate(&data->b);
	}
	if (is_print)
		ft_print_movement(ROTATE, id);
}

void	ft_reverse_rotate(t_data *data, int id, int is_print)
{
	if (id == A)
		ft_stack_reverse_rotate(&data->a);
	else if (id == B)
		ft_stack_reverse_rotate(&data->b);
	else if (id == R)
	{
		ft_stack_reverse_rotate(&data->a);
		ft_stack_reverse_rotate(&data->b);
	}
	if (is_print)
		ft_print_movement(REVERSE_ROTATE, id);
}
