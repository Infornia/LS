# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/19 15:21:15 by mwilk             #+#    #+#              #
#    Updated: 2015/03/22 17:51:18 by mwilk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ls

SRCS_NAME = main.c\
			ls_data_params.c\
			ls_R_cmp.c\
			ls_prints.c\
			ls.c\

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS_PATH = ./objs/

SRCS = $(addprefix $(SRCS_PATH),$(SRCS_NAME))

OBJS = $(addprefix $(OBJS_PATH),$(OBJS_NAME))

FLAGS = -Wall -Wextra -Werror

LIBFT_H = -I libft/includes/

LIBFT = -Llibft -lft

LS_H = -I includes/

all: $(NAME)

$(NAME):
	@make -C libft/ fclean
	@make -C libft/
	@gcc -g $(FLAGS) $(LIBFT_H) $(LS_H) -c $(SRCS)
	@mkdir $(OBJS_PATH)
	@mv $(OBJS_NAME) $(OBJS_PATH)
	@gcc -o $(NAME) $(OBJS) $(LIBFT)
	@echo "\033[35m <(^.^<) WOW ! Such LS Library ! Amaze ! (>^o^)> \033[0m"

norm:
	@echo "\033[35mnorminette MAGGLE\033[0m"
	@norminette **/*.[ch]

clean:
	@rm -rf $(OBJS_PATH)
	@echo "\033[30mT.T Miss you LS files T.T \033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[30m X.x Bye Bye compiled LS files >_< \033[0m"

re: fclean all

.PHONY: all norm clean fclean re
