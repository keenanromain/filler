# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kromain <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/17 15:05:07 by kromain           #+#    #+#              #
#    Updated: 2017/11/12 14:09:00 by kromain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = kromain.filler

SRC = src/*.c

SRCO = $(SRC:.c=.0)

FLAGS = -Wall -Werror -Wextra -o

all: $(NAME)

$(NAME):
	@echo "                              "
	@echo "\033[01;36mCompiling..."
	@echo "  _____.__.__  .__                "
	@echo "_/ ____\__|  | |  |   ___________ "
	@echo "\   __\|  |  | |  | _/ __ \_  __ \ "
	@echo " |  |  |  |  |_|  |_\  ___/|  | \/"
	@echo " |__|  |__|____/____/\_____>__|   "
	@echo "						   \033[0m "
	make -C	libft/ fclean && make -C libft/
	clang $(FLAGS) $(NAME) $(SRC) libft/libft.a
	@echo "                              "
	@echo "\033[01;39mFinished making filler. Available Makefile commands:\033[0m"
	@echo "\033[01;39m - make\033[0m"
	@echo "\033[01;39m - make clean\033[0m"
	@echo "\033[01;39m - make fclean\033[0m"
	@echo "\033[01;39m - make re\033[0m"

clean:
	@echo "                              "
	@echo "\033[01;39mCleaning filler...\033[0m"
	make -C libft/ clean
	rm -f $(SRCO)

fclean: clean
	@echo "                              "
	@echo "\033[01;31mRemoved Compiled filler\033[0m"
	rm -f $(NAME)

re: fclean all
