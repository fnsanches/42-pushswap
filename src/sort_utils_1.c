/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:52:16 by fsanches          #+#    #+#             */
/*   Updated: 2022/12/06 18:52:22 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push_away(t_data *data)
{
	int	movement_id;

	while (data->a->size > 5)
	{
		ft_find_coef(data);
		movement_id = ft_get_push_away_id(data);
		if (movement_id > -1)
			ft_rotate(data, movement_id, 1);
		else
			ft_push(data, B, 1);
	}
	ft_sort_five(data);
}

void	ft_push_back(t_data *data)
{
	while (data->b->size)
	{
		ft_calculate_best_movement(data);
		ft_move(data);
	}
}

void	ft_align(t_data *data)
{
	int		operate;
	t_list	*temp;
	size_t	start_i;
	size_t	i;

	if (ft_is_sorted(data->a->list, data->a->order))
		return ;
	i = 0;
	start_i = 0;
	temp = data->a->list;
	while (temp)
	{
		if (temp->number > ft_list_at(data->a, start_i))
			start_i = i;
		temp = temp->next;
		i++;
	}
	operate = (++start_i > data->a->size / 2);
	if (start_i > data->a->size - start_i)
		start_i = data->a->size - start_i;
	while (start_i--)
		data->ft[operate](data, A, 1);
}
