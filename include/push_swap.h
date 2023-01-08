/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:59:45 by fsanches          #+#    #+#             */
/*   Updated: 2022/12/06 19:01:15 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libft/libft.h"
# include <stdio.h>

# define A		0
# define B		1
# define R		2

enum e_order{
	ASCENDING,
	DESCENDING
};

enum e_operation{
	ROTATE,
	REVERSE_ROTATE,
	SWAP,
	PUSH
};

typedef struct s_list
{
	int				number;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*list;
	size_t	size;
	size_t	range;
	int		order;
}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	float	coef[2];
	int		*pos;
	int		*tmp;
	int		operate;
	int		counter;
	void	(*ft[2])(struct s_data *, int, int);
}	t_data;

typedef struct s_move
{
	char			*command;
	struct s_move	*next;
}	t_move;

# define ERROR_MSG	"Error\n"
# define BONUS_OK	"OK\n"
# define BONUS_KO	"KO\n"

t_data	*ft_init_data(int argc, char **argv);
void	ft_init_stacks(t_data *data);
int		ft_check_args(t_data *data);
void	ft_get_stack_list(t_data *data);
void	ft_stack_range(t_stack **stack);
void	ft_end_program(t_data *data, int exit_number);
void	ft_free_stack(t_stack *stack);
void	ft_free_args(char **args);
t_list	*ft_list_new(int number);
t_list	*ft_list_last(t_list *list);
void	ft_list_add_back(t_list **list, t_list *new);
void	ft_list_add_front(t_list **list, t_list *new);
void	ft_clear_list(t_list **list);
size_t	ft_list_len(t_list *list);
int		ft_list_at(t_stack *stack, size_t index);
int		ft_is_sorted(t_list *list, int id);
void	ft_stack_swap(t_stack **stack);
void	ft_stack_push(t_data *data, int id);
void	ft_stack_rotate(t_stack **stack);
void	ft_stack_reverse_rotate(t_stack **stack);
void	ft_swap(t_data *data, int id, int is_print);
void	ft_push(t_data *data, int id, int is_print);
void	ft_rotate(t_data *data, int id, int is_print);
void	ft_reverse_rotate(t_data *data, int id, int is_print);
void	ft_sort_stack(t_data *data);
void	ft_push_away(t_data *data);
void	ft_push_back(t_data *data);
void	ft_align(t_data *data);
void	ft_sort_five(t_data *data);
void	ft_calculate_best_movement(t_data *data);
void	ft_move(t_data *data);
int		ft_abs(int number);
int		ft_atoi_mod(t_data *data, int position);
char	**ft_args_copy(char **args, int size);
size_t	ft_count_lowers(t_stack *stack);
size_t	ft_count_moves(int *position);
void	ft_find_coef(t_data	*data);
void	ft_print_movement(int operation, int stack_id);
void	ft_print_stack(char *name, t_list *list);
int		ft_get_push_away_id(t_data *data);
int		ft_get_sort_five_rotate_id(t_data *data);
int		ft_get_sort_five_swap_id(t_data *data);
int		ft_get_position(t_stack *stack, int nb);
t_move	*ft_instruction_new(char *command);
t_move	*ft_instruction_last(t_move *list);
void	ft_instruction_add_back(t_move **list, t_move *new);
void	ft_clear_instruction_list(t_move **list);
size_t	ft_instruction_list_len(t_move *list);
t_move	*ft_read_commands(void);
void	ft_run_all(t_data *data, t_move	**commands);
int		ft_execute_commands(t_data *data, char *command);

#endif