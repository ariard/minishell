# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/28 17:57:47 by ariard            #+#    #+#              #
#    Updated: 2017/02/14 13:52:31 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CP = cp
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I ./inc/

SRC_DIR = src
SRC_ALGO = src/algo

SRCS_STRING = $(SRC_DIR)/string/ft_isalnum.c \
			$(SRC_DIR)/string/ft_isalpha.c \
			$(SRC_DIR)/string/ft_isascii.c \
			$(SRC_DIR)/string/ft_isdigit.c \
			$(SRC_DIR)/string/ft_isprint.c \
			$(SRC_DIR)/string/ft_isspace.c \
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
			$(SRC_DIR)/string/ft_sizewchar.c \
			$(SRC_DIR)/string/ft_strsplitptr.c \
			$(SRC_DIR)/string/ft_count_words.c \
			$(SRC_DIR)/string/ft_strduptr.c \
			$(SRC_DIR)/string/ft_str_epure.c \
			$(SRC_DIR)/string/ft_str_copy.c \
			$(SRC_DIR)/string/ft_count_words_ptr.c \
			$(SRC_DIR)/string/ft_str_substitute.c \
			$(SRC_DIR)/string/ft_str_inschr.c \
			$(SRC_DIR)/string/ft_str_delchr.c \
			$(SRC_DIR)/string/ft_count_char.c \
			$(SRC_DIR)/string/ft_strcpyptr.c \
			$(SRC_DIR)/string/ft_tabdel.c

SRCS_ARRAY	= $(SRC_DIR)/array/ft_array_strdup.c \
			$(SRC_DIR)/array/ft_array_del.c \
			$(SRC_DIR)/array/ft_array_size.c \
			$(SRC_DIR)/array/ft_array_clean.c \
			$(SRC_DIR)/array/ft_array_add.c

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
			$(SRC_DIR)/print/ft_putwstr.c \
			$(SRC_DIR)/print/ft_putarray.c

SRCS_INT=	$(SRC_DIR)/int/ft_intlen.c \
			$(SRC_DIR)/int/ft_unsintlen.c \
			$(SRC_DIR)/int/ft_atoi.c \
			$(SRC_DIR)/int/ft_atoi_base.c \
			$(SRC_DIR)/int/ft_itoa.c \
			$(SRC_DIR)/int/ft_itoa_base.c \
			$(SRC_DIR)/int/ft_recursive_power.c \
			$(SRC_DIR)/int/ft_itoacmp.c

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
			$(SRC_DIR)/dlist/ft_list_init.c \
			$(SRC_DIR)/dlist/ft_list_next.c

SRCS_STACK= $(SRC_DIR)/stack/ft_stack_push.c \
			$(SRC_DIR)/stack/ft_stack_pop.c \
			$(SRC_DIR)/stack/ft_stack_peek.c \

SRCS_SORT=	$(SRC_ALGO)/sort/ft_stralphcmp.c \
			$(SRC_ALGO)/sort/insert_sort.c \
			$(SRC_ALGO)/sort/bubble_sort.c \

SRCS_GNL=	$(SRC_DIR)/get_next_line/get_next_line.c \
			$(SRC_DIR)/get_next_line/getchar.c

SRCS_HTB=	$(SRC_DIR)/htb/ft_cht_destroy.c \
			$(SRC_DIR)/htb/ft_cht_init.c \
			$(SRC_DIR)/htb/ft_cht_lookup.c \
		   	$(SRC_DIR)/htb/ft_cht_insert.c \
			$(SRC_DIR)/htb/ft_cht_remove.c \
			$(SRC_DIR)/htb/ft_hash_string.c

SRCS_BTREE= $(SRC_DIR)/btree/ft_btree_init.c \
			$(SRC_DIR)/btree/ft_btree_ins_left.c \
			$(SRC_DIR)/btree/ft_btree_ins_right.c \
			$(SRC_DIR)/btree/ft_btree_create_node.c \
			$(SRC_DIR)/btree/ft_btree_get_node.c \
			$(SRC_DIR)/btree/ft_btree_get_father.c \
			$(SRC_DIR)/btree/ft_rem_node.c \
			$(SRC_DIR)/btree/ft_btree_destroy.c \
			$(SRC_DIR)/btree/ft_display_prefix.c \
			$(SRC_DIR)/btree/ft_apply_postfix.c \
			$(SRC_DIR)/btree/ft_btree_sort_ins.c

SRCS += $(SRCS_STRING)
SRCS += $(SRCS_MEM)
SRCS += $(SRCS_PRINT)
SRCS += $(SRCS_INT)
SRCS += $(SRCS_DLIST)
SRCS += $(SRCS_GNL)
SRCS += $(SRCS_HTB)
SRCS += $(SRCS_BTREE)
SRCS += $(SRCS_ARRAY)
SRCS += $(SRCS_SORT)

OBJS = $(SRCS:.c=.o)

NAME = freelib

all: link
	@ $(MAKE) ranlib
	@ $(MAKE) copylib

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@

link: $(OBJS)
	@ ar rc $(NAME).a $(OBJS)

ranlib: 
	@ ranlib $(NAME).a

copylib:
	@ $(CP) $(NAME).a ../$(NAME).a

clean:
	@ $(RM) $(OBJS)

fclean: clean
	@ $(RM) $(NAME).a

re: fclean
	@ $(MAKE) -j all

