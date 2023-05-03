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

CC = clang
CFLAGS = -g3 -Wall -Wextra -Werror -I$(INCLUDES) -I$(INCLUDESFT)
CDFLAGS = -MMD -MP

 #=============================================================================#
#									MAKEFILE									#
 #=============================================================================#

NAME = miniRT

all : $(NAME)

$(NAME) : $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(CLFLAGS) libft/libft.a -o $(NAME)

$(OBJS_DIR) :
	mkdir -p $(OBJS_DIR)/$(PARSE_DIR)
	mkdir -p $(OBJS_DIR)/$(PTR_ARRAY_DIR)
	mkdir -p $(OBJS_DIR)/$(CONTENT_FILE_DIR)

$(OBJS) : $(OBJS_DIR)/%.o : %.c
	$(CC) $(CFLAGS) $(CDFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re : fclean all

-include $(DEPS)

.PHONY: all clean fclean re

#.SILENT: