# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/28 17:57:47 by ariard            #+#    #+#              #
#    Updated: 2016/12/29 20:30:59 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CP = cp
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I ./inc/

SRC_DIR = src

SRCS_STRING = $(SRC_DIR)/string/ft_isalnum.c \
			$(SRC_DIR)/string/ft_isalpha.c \
			$(SRC_DIR)/string/ft_isascii.c \
			$(SRC_DIR)/string/ft_isdigit.c \
			$(SRC_DIR)/string/ft_isprint.c \
			$(SRC_DIR)/string/ft_strcat.c \
			$(SRC_DIR)/string/ft_strchr.c \
			$(SRC_DIR)/string/ft_strchrcpy.c \
			$(SRC_DIR)/string/ft_strclr.c \
			$(SRC_DIR)/string/ft_strcmp.c \
			$(SRC_DIR)/string/ft_strcpy.c \
			$(SRC_DIR)/string/ft_strdel.c \
			$(SRC_DIR)/string/ft_strdup.c \
			$(SRC_DIR)/string/ft_striter.c \
			$(SRC_DIR)/string/ft_striteri.c \
			$(SRC_DIR)/string/ft_strjoin.c \
			$(SRC_DIR)/string/ft_strlcat.c \
			$(SRC_DIR)/string/ft_strlen.c \
			$(SRC_DIR)/string/ft_strlenchr.c \
			$(SRC_DIR)/string/ft_strmap.c \
			$(SRC_DIR)/string/ft_strmapi.c \
			$(SRC_DIR)/string/ft_strncat.c \
			$(SRC_DIR)/string/ft_strncmp.c \
			$(SRC_DIR)/string/ft_strncpy.c \
			$(SRC_DIR)/string/ft_strnew.c \
			$(SRC_DIR)/string/ft_strnstr.c \
			$(SRC_DIR)/string/ft_strrchr.c \
			$(SRC_DIR)/string/ft_strrev.c \
			$(SRC_DIR)/string/ft_strsplit.c \
			$(SRC_DIR)/string/ft_strstr.c \
			$(SRC_DIR)/string/ft_strsub.c \
			$(SRC_DIR)/string/ft_strtrim.c \
			$(SRC_DIR)/string/ft_tolower.c \
			$(SRC_DIR)/string/ft_toupper.c \
			$(SRC_DIR)/string/ft_sizewchar.c 

SRCS_MEM=	$(SRC_DIR)/mem/ft_bzero.c \
			$(SRC_DIR)/mem/ft_memalloc.c \
			$(SRC_DIR)/mem/ft_memchr.c \
			$(SRC_DIR)/mem/ft_memccpy.c \
			$(SRC_DIR)/mem/ft_memcmp.c \
			$(SRC_DIR)/mem/ft_memcpy.c \
			$(SRC_DIR)/mem/ft_memdel.c \
			$(SRC_DIR)/mem/ft_memmove.c \
			$(SRC_DIR)/mem/ft_memset.c \

SRCS_PRINT=	$(SRC_DIR)/print/ft_putchar.c \
			$(SRC_DIR)/print/ft_putchar_fd.c \
			$(SRC_DIR)/print/ft_putendl.c \
			$(SRC_DIR)/print/ft_putendl_fd.c \
			$(SRC_DIR)/print/ft_putnbr.c \
			$(SRC_DIR)/print/ft_putnbr_fd.c \
			$(SRC_DIR)/print/ft_putstr.c \
			$(SRC_DIR)/print/ft_putstr_fd.c \
			$(SRC_DIR)/print/ft_putstrn.c \
			$(SRC_DIR)/print/ft_putwchar.c \
			$(SRC_DIR)/print/ft_putwstr.c

SRCS_INT=	$(SRC_DIR)/int/ft_intlen.c \
			$(SRC_DIR)/int/ft_unsintlen.c \
			$(SRC_DIR)/int/ft_atoi.c \
			$(SRC_DIR)/int/ft_atoi_base.c \
			$(SRC_DIR)/int/ft_itoa.c \
			$(SRC_DIR)/int/ft_itoa_base.c \
			$(SRC_DIR)/int/ft_recursive_power.c \

SRCS_DLIST= $(SRC_DIR)/dlist/ft_create_elem.c \
			$(SRC_DIR)/dlist/ft_list_clear.c \
			$(SRC_DIR)/dlist/ft_list_cycle.c \
			$(SRC_DIR)/dlist/ft_list_find.c \
			$(SRC_DIR)/dlist/ft_list_foreach.c \
			$(SRC_DIR)/dlist/ft_list_ins.c \
			$(SRC_DIR)/dlist/ft_list_last.c \
			$(SRC_DIR)/dlist/ft_list_push_back.c \
			$(SRC_DIR)/dlist/ft_list_push_front.c \
			$(SRC_DIR)/dlist/ft_list_push_params.c \
			$(SRC_DIR)/dlist/ft_list_rem.c \
			$(SRC_DIR)/dlist/ft_list_rem_front.c \
			$(SRC_DIR)/dlist/ft_list_reverse.c \
			$(SRC_DIR)/dlist/ft_list_size.c \
			$(SRC_DIR)/dlist/ft_list_swap.c \

SRCS_STACK= $(SRC_DIR)/stack/ft_stack_push.c \
			$(SRC_DIR)/stack/ft_stack_pop.c \
			$(SRC_DIR)/stack/ft_stack_peek.c \

SRCS_SORT=	$(SRC_ALGO)/sort/ft_stralphcmp.c \
			$(SRC_ALGO)/sort/insert_sort.c \
			$(SRC_ALGO)/sort/bubble_sort.c \

SRCS += $(SRCS_STRING)
SRCS += $(SRCS_MEM)
SRCS += $(SRCS_PRINT)
SRCS += $(SRCS_INT)
SRCS += $(SRCS_DLIST)


OBJS = $(SRCS:.c=.o)

NAME = freelib

all: link
	$(MAKE) ranlib
	$(MAKE) copylib

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

link: $(OBJS)
	ar rc $(NAME).a $(OBJS)

ranlib: 
	ranlib $(NAME).a

copylib:
	$(CP) $(NAME).a ../$(NAME).a

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME).a

re: fclean
	$(MAKE) -j all

