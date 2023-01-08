/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:50:30 by fsanches          #+#    #+#             */
/*   Updated: 2022/12/06 18:50:33 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_move	*ft_instruction_new(char *command)
{
	t_move	*new;

	new = malloc(sizeof(t_move));
	if (!new || !command)
		return (NULL);
	new->command = ft_strdup(command);
	new->next = NULL;
	return (new);
}

t_move	*ft_instruction_last(t_move *list)
{
	t_move	*last;

	if (!list)
		return (NULL);
	last = list;
	while (last->next)
		last = last->next;
	return (last);
}

void	ft_instruction_add_back(t_move **list, t_move *new)
{
	t_move	*temp;

	if (!new)
		return ;
	if (!(*list))
		*list = new;
	else
	{
		temp = ft_instruction_last(*list);
		temp->next = new;
	}
}

void	ft_clear_instruction_list(t_move **list)
{
	t_move	*temp;

	while (*list)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp->command);
		free(temp);
	}
}

size_t	ft_instruction_list_len(t_move *list)
{
	size_t	size;

	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}
