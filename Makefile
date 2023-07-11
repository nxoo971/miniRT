# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 12:49:01 by mparisse          #+#    #+#              #
#    Updated: 2023/07/11 14:42:34 by mparisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 #===============================================================================#
#								SOURCES											  #
 #===============================================================================#

MAIN_DIR			= ./
PARSE_DIR			= ./parse/
PTR_ARRAY_DIR		= ./ptr_array/
CONTENT_FILE_DIR	= ./content_file/

INCLUDES		= includes
INCLUDESFT		= ./libft/${INCLUDES}

SRC_FILES = $(addprefix $(MAIN_DIR), main.c) \
			$(addprefix $(PARSE_DIR), parse.c parse_line.c) \
			$(addprefix $(PTR_ARRAY_DIR), ptr_array.c) \
			$(addprefix $(CONTENT_FILE_DIR), content_file.c)

 #=============================================================================#
#									OBJETS										#
 #=============================================================================#

OBJS_DIR = objects
OBJS = $(SRC_FILES:%.c=$(OBJS_DIR)/%.o)
DEPS = $(SRC_FILES:%.c=$(OBJS_DIR)/%.d)

 #=============================================================================#
#									COMPILATION									#
 #=============================================================================#

CC = cc
CFLAGS = -g3 -I$(INCLUDES) -I$(INCLUDESFT) -Wall -Wextra #-Werror
CDFLAGS = -MMD -MP

 #=============================================================================#
#									MAKEFILE									#
 #=============================================================================#

NAME = miniRT

all : $(NAME)

$(NAME) : $(OBJS_DIR) $(OBJS)
	make -C libft/
	make -C maxou_math
	$(CC) $(CFLAGS) $(OBJS) $(CLFLAGS) libft/libft.a maxou_math/maxou_math.a -lm -o $(NAME)

$(OBJS_DIR) :
	mkdir -p $(OBJS_DIR)/$(PARSE_DIR)
	mkdir -p $(OBJS_DIR)/$(PTR_ARRAY_DIR)
	mkdir -p $(OBJS_DIR)/$(CONTENT_FILE_DIR)

$(OBJS) : $(OBJS_DIR)/%.o : %.c
	$(CC) $(CFLAGS) $(CDFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)
	make -C maxou_math/ clean
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	make -C maxou_math/ fclean
	make -C libft/ fclean

re : fclean all

-include $(DEPS)

.PHONY: all clean fclean re

#.SILENT: