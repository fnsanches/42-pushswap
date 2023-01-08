/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:51:51 by fsanches          #+#    #+#             */
/*   Updated: 2022/12/06 18:51:55 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"	

void	ft_sort_stack(t_data *data)
{
	ft_push_away(data);
	ft_push_back(data);
	ft_align(data);
}
