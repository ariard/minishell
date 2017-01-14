# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/30 15:31:26 by ariard            #+#    #+#              #
#    Updated: 2017/01/14 16:26:06 by ariard           ###   ########.fr        #
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
	  src/syntax_analyzer.c \
	  src/gen_ast.c \
	  src/semantic_analyzer.c \
	  src/execution.c \
	  src/execution_redir.c \
	  src/builtin.c \
	  src/echo.c \
	  src/cd.c \
	  src/env.c \
	  src/tty.c \
	  src/term.c \
	  src/termcap.c \
	  src/termcap2.c \
	  src/termcap3.c \
	  src/termwrap1.c \
	  src/termwrap2.c \
	  src/error.c \
	  src/macro_node.c \
	  src/macro_operator.c \
	  src/macro_env.c \
	  src/macro_read.c \
	  src/macro_read2.c \
	  src/read.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@  $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) 
	@  make -C ./libft fclean
	@  make -C ./libft	
	@  $(CC) $(OBJS) $(LIB) -ltermcap -o $(NAME)
	@ rm -rf $(OBJS) $(LIB)
  
clean :
	@ rm -rf $(OBJS) $(LIB)

fclean : clean
	@ rm -rf $(NAME)

re: fclean all
