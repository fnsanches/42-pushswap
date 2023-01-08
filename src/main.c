/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:52:25 by fsanches          #+#    #+#             */
/*   Updated: 2022/12/06 18:52:28 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc - 1 == 0)
		exit(1);
	data = ft_init_data(argc, argv);
	if (!ft_is_sorted(data->a->list, data->a->order))
		ft_sort_stack(data);
	ft_end_program(data, 0);
}
