/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:54:12 by fsanches          #+#    #+#             */
/*   Updated: 2022/12/06 18:54:17 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"		

int	ft_check_args(t_data *data)
{
	t_list	*tmp;
	t_list	*iterator;

	tmp = data->a->list;
	while (tmp)
	{
		iterator = tmp->next;
		while (iterator)
		{
			if (tmp->number == iterator->number)
				return (0);
			iterator = iterator->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

void	ft_get_stack_list(t_data *data)
{
	t_list	*new;
	int		i;

	data->a->list = NULL;
	i = 0;
	while (data->args[i])
	{
		new = ft_list_new(ft_atoi_mod(data, i));
		if (!new && data->a->list)
		{
			ft_clear_list(&data->a->list);
			break ;
		}
		ft_list_add_back(&data->a->list, new);
		i++;
	}
}

void	ft_stack_range(t_stack **stack)
{
	t_list	*list;
	int		min;
	int		max;

	list = (*stack)->list;
	(*stack)->size = 0;
	if (list)
	{
		min = (*stack)->list->number;
		max = (*stack)->list->number;
		while (list)
		{
			(*stack)->size++;
			if (list->number > max)
				max = list->number;
			if (list->number < min)
				min = list->number;
			list = list->next;
		}
		(*stack)->range = (size_t)(max - min);
	}
	else
		(*stack)->range = 0;
}
