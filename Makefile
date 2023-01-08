# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 11:04:11 by fsanches          #+#    #+#              #
#    Updated: 2023/01/07 11:04:14 by fsanches         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= push_swap
NAME_BONUS		= checker
LIBFT			= libft.a

LIBFT_PATH 		= ./libft/
SRC_PATH 		= ./src/
OBJ_PATH		= ./obj/
INCLUDE 		= ./include/

CC 				= gcc
CF 				= -Wall -Wextra -Werror
CFI 			= -I $(INCLUDE)

SRC 			= main.c \
				args.c \
				init.c \
				error.c \
				list_utils_1.c \
				list_utils_2.c \
				stack_op_1.c \
				stack_op_2.c \
				utils_1.c \
				utils_2.c \
				utils_3.c \
				sort.c \
				sort_utils_1.c \
				sort_utils_2.c \
				
SRC_BONUS		= checker.c	\
				utils_bonus.c \
				args.c \
				init.c \
				error.c \
				list_utils_1.c \
				list_utils_2.c \
				stack_op_1.c \
				stack_op_2.c \
				utils_1.c \
				utils_2.c \
				utils_3.c \
				sort.c \
				sort_utils_1.c \
				sort_utils_2.c \

OBJ				= $(addprefix $(OBJ_PATH), $(notdir $(SRC:.c=.o)))
OBJ_BONUS		= $(addprefix $(OBJ_PATH), $(notdir $(SRC_BONUS:.c=.o)))
RM 				= rm -rf

$(OBJ_PATH)%.o: 	$(SRC_PATH)%.c
				mkdir -p $(OBJ_PATH)
				$(CC) $(CF) $(CFI) -c $< -o $@

$(NAME):		$(OBJ)
				make -C $(LIBFT_PATH) $(LIBFT)
				$(CC) $(CF) -I $(INCLUDE) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -lft

all:			$(NAME)

re:				fclean all

$(NAME_BONUS):	$(OBJ_BONUS)
				make -C $(LIBFT_PATH) $(LIBFT)
				$(CC) $(CF) -I $(INCLUDE) -o $(NAME_BONUS) $(OBJ_BONUS) -L $(LIBFT_PATH) -lft

bonus:			$(NAME_BONUS)

rebonus:		fclean bonus

clean:
				make -C $(LIBFT_PATH) clean
				$(RM) $(OBJ) $(OBJ_BONUS) $(OBJDIR)

fclean:			clean
				make -C $(LIBFT_PATH) fclean
				$(RM) $(NAME) $(NAME_BONUS)

.PHONY:			all clean fclean re bonus rebonus