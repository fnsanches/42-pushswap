/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:50:49 by fsanches          #+#    #+#             */
/*   Updated: 2022/12/06 18:50:50 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_abs(int number)
{
	if (number >= 0)
		return (number);
	else
		return (-number);
}

int	ft_atoi_mod(t_data *data, int position)
{
	size_t	i;
	int		sign;
	long	total;

	i = 0;
	sign = 1;
	total = 0;
	if (data->args[position][i] == '+' || data->args[position][i] == '-')
		if (data->args[position][i++] == '-')
			sign *= (-1);
	if (!ft_isdigit(data->args[position][i]))
		ft_end_program(data, 6);
	while (data->args[position][i] >= '0' && data->args[position][i] <= '9')
	{
		if (sign == -1)
			total = total * 10 - (data->args[position][i] - '0');
		else
			total = total * 10 + (data->args[position][i] - '0');
		if (total < -2147483648 || total > 2147483647)
			ft_end_program(data, 6);
		i++;
	}
	if (!ft_isdigit(data->args[position][i]) && data->args[position][i] != 0)
		ft_end_program(data, 6);
	return ((int)total);
}

char	**ft_args_copy(char **args, int size)
{
	char	**copied;
	int		i;

	copied = (char **)malloc(sizeof(char *) * (size + 1));
	if (!copied)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copied[i] = (char *)malloc(sizeof(char) * (ft_strlen(args[i]) + 1));
		if (!copied[i])
		{
			while (--i >= 0)
				free(copied[i]);
			free(copied);
			return (NULL);
		}
		ft_strlcpy(copied[i], args[i], ft_strlen(args[i]) + 1);
		i++;
	}
	copied[i] = NULL;
	return (copied);
}
