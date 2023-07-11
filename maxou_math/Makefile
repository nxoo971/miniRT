# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 17:44:55 by mparisse          #+#    #+#              #
#    Updated: 2023/07/10 18:21:41 by mparisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = maxou_math.a 

################################################################################
#                                  COMPILATION                                 #
################################################################################

CC = clang

CFLAGS = -Wall -Werror -Wextra -fenable-matrix

# INCLUDES		=	-Iinclude -Iinclude/structs -I/usr/X11/include
# LIBS			=	-L/usr/X11/lib -lX11 -lXext -Lmlx -lmlx tests_and_tools/tools2.a
# FRAMEWORKS		=	-framework OpenGL -framework AppKit


################################################################################
#                                  DIRECTORIES                                 #
################################################################################


MATRIX_DIR = matrix
TUPLES_DIR = tuples

SRCS_FILES = $(addprefix matrix/, \
				determinants.c  ops_matrix.c prints.c subs_matrix.c) \
				\
				$(addprefix tuples/, \
				ops_tuples.c utils.c) 
OBJS_DIR = .objets

OBJS = $(SRCS_FILES:%.c=$(OBJS_DIR)/%.o)


################################################################################
#                                  RULES                                       #
################################################################################

all :	$(NAME)

$(NAME):	$(OBJS_DIR) $(OBJS)
	ar rcs $(NAME) ${OBJS}

$(OBJS_DIR):
	mkdir	$(OBJS_DIR)
	mkdir	$(OBJS_DIR)/$(MATRIX_DIR)
	mkdir	$(OBJS_DIR)/$(TUPLES_DIR)

# $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJS) : $(OBJS_DIR)/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY = all fclean re clean
