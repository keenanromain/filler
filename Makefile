# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kromain <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/17 15:05:07 by kromain           #+#    #+#              #
#    Updated: 2017/09/29 15:40:16 by kromain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler.a

FLAGS = -Wall -Wextra -Werror

PROJECT = \
		filler.c			\
		allocate.c 			\
		deallocate.c		\
		validate.c			\
		place.c

LIB = \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c	\
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c		\
		ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c	\
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c	\
		ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c	\
		ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_itoa.c	\
		ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c	\
		ft_striteri.c ft_strmap.c ft_strmapi.c 	ft_strequ.c ft_strsub.c	\
		ft_strnequ.c ft_strjoin.c ft_strtrim.c 	ft_strsplit.c ft_abs.c	\
		ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_revsign.c	\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c	\
		ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstnew.c	\
		ft_lstmap.c ft_strndup.c ft_atol.c 	ft_strclen.c ft_lstsize.c	\
		ft_isspace.c ft_atoi_array.c ft_numcount.c ft_sqrt.c ft_exp.c	\
		ft_isprime.c ft_numlen.c ft_strcdup.c ft_swap.c ft_strccpy.c	\
		ft_pow.c ft_strcjoin.c ft_downcase.c ft_upcase.c ft_strnchr.c	\
		ft_putnstr.c get_next_line.c


P_SRC = $(addprefix src/,$(PROJECT))

L_SRC = $(addprefix src/libft/,$(LIB))

SRC = $(P_SRC) $(L_SRC)

OBJ = $(PROJECT:.c=.o) $(LIB:.c=.o)

IN = -I./inc

.PHONY: all clean fclean re lib

all: $(NAME)

$(NAME):
	@echo "                              "
	@echo "\033[01;36mCompiling..."
	@echo "  _____.__.__  .__                "
	@echo "_/ ____\__|  | |  |   ___________ "
	@echo "\   __\|  |  | |  | _/ __ \_  __ \ "
	@echo " |  |  |  |  |_|  |_\  ___/|  | \/"
	@echo " |__|  |__|____/____/\___  >__|   "
	@echo "						    \/ \033[0m "
	gcc $(FlAGS) $(IN) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	@echo "                              "
	@echo "\033[01;39mFinished making filler. Available Makefile commands:\033[0m"
	@echo "\033[01;39m - make\033[0m"
	@echo "\033[01;39m - make clean\033[0m"
	@echo "\033[01;39m - make fclean\033[0m"
	@echo "\033[01;39m - make re\033[0m"

clean:
	@echo "                              "
	@echo "\033[01;39mCleaning filler...\033[0m"
	/bin/rm -f $(OBJ)

fclean: clean
	@echo "                              "
	@echo "\033[01;31mRemoved Compiled filler\033[0m"
	/bin/rm -f $(NAME)

re: fclean all

lib:
	gcc $(FLAGS) $(HDR) -c $(L_SRC)
	ar rc $(LIB:.c=.o)
	@rm -f $(OBJ)
