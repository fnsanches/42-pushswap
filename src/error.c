/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:53:16 by fsanches          #+#    #+#             */
/*   Updated: 2022/12/06 18:55:04 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_end_program(t_data *data, int exit_number)
{
	if (data)
	{
		if (data->a)
			ft_free_stack(data->a);
		if (data->b)
			ft_free_stack(data->b);
		if (data->pos)
			free(data->pos);
		if (data->tmp)
			free(data->tmp);
		if (data->args)
			ft_free_args(data->args);
		free(data);
	}
	if (exit_number > 0)
		ft_putstr_fd(ERROR_MSG, 2);
	else if (exit_number == -1)
		ft_putstr_fd(BONUS_OK, 1);
	else if (exit_number == -2)
		ft_putstr_fd(BONUS_KO, 1);
	exit(exit_number);
}

void	ft_free_stack(t_stack *stack)
{
	if (stack->list)
		ft_clear_list(&stack->list);
	free(stack);
}

void	ft_free_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
