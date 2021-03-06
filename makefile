# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/30 15:31:26 by ariard            #+#    #+#              #
#    Updated: 2017/01/07 16:45:35 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
NAME= minishell
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I ./inc/
LIB= freelib.a

SRC = src/minishell.c \
	  src/lex_analyzer.c \
	  src/lexer.c \
	  src/lexicon.c \
	  src/sym_tab.c \
	  src/syntax_analyze.c \
	  src/gen_ast.c \
	  src/sem_executer.c \
	  src/execution.c \
	  src/error.c \
	  src/macro.c \
	  src/read.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	  $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) 
	  make -C ./libft fclean
	  make -C ./libft	
	  $(CC) $(OBJS) $(LIB) -o $(NAME)

clean :
	@ rm -rf $(OBJS) $(LIB)

fclean : clean
	@ rm -rf $(NAME)

re: fclean all
