# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 13:25:37 by kjikuhar          #+#    #+#              #
#    Updated: 2026/05/20 10:31:23 by stanaka2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------- #
#       Phony Targets        #
# -------------------------- #

.PHONY: all bonus clean fclean re install norm san debug

# -------------------------- #
#      Makefile Setting      #
# -------------------------- #

OS		:= $(shell uname -s)
override MAKEFLAGS += --no-print-directory
override .DEFAULT_GOAL := all

.DEFAULT:
	@printf "No match. We want to write help here.\n"

.DELETE_ON_ERROR:

# -------------------------- #
#           Target           #
# -------------------------- #

NAME	:= cub3D

# -------------------------- #
#       Compiler Flags       #
# -------------------------- #

CC				:= cc
override CFLAGS	+= -Wall -Wextra -Werror
# when submit, it should change -W3
override CFLAGS	+= -Wconversion -Wno-sign-conversion

ifeq ($(MAKECMDGOALS), san)
override CFLAGS += -g -fsanitize=address,undefined
endif

ifeq ($(MAKECMDGOALS), debug)
override CFLAGS += -g
endif

# -------------------------- #
#          Include           #
# -------------------------- #

INCLUDE_DIRS		:= include
override CPPFLAGS	+= $(foreach dir, $(INCLUDE_DIRS), -I$(dir))

# -------------------------- #
#     Source Directories     #
# -------------------------- #

SRC_DIRS			:= src
SRC_DIRS			+= $(addprefix src/, \
							cleanup \
							error \
							validate_argument \
							parse_file parse_file/utils \
							$(addprefix parse_file/, \
								parse_settings parse_settings/utils \
								parse_map \
							) \
							$(addprefix vec2/, \
								ivec2 \
								dvec2 \
							) \
						)

$(foreach dir, $(SRC_DIRS), $(eval vpath %.c $(dir)))

# -------------------------- #
#        Source Files        #
# -------------------------- #

SRCS	:= 	main.c

# cleanup
SRCS	+=	cleanup_settings.c \
			cleanup_map.c
# error
SRCS	+=	print_error.c
# validate_argument
SRCS	+=	validate_argument.c
# parse_file
SRCS	+=	parse_file.c \
			read_next_line.c \
			is_blank_line.c \
			replace_char.c
# parse_file/parse_settings
SRCS	+=	parse_settings.c \
			parse_settings_line.c \
			is_incomplete_settings.c \
			set_texture.c \
			set_color.c \
			free_splitted.c
# parse_file/parse_map
SRCS	+=	parse_map.c \
			read_map.c \
			parse_map_data.c \
			parse_map_cell.c
# vec2/ivec2
SRCS	+=	ivec2_add.c \
			ivec2_sub.c
# vec2/dvec2
SRCS	+=	dvec2_add.c

# -------------------------- #
#        Object Files        #
# -------------------------- #

OBJ_DIR		:= .obj

$(OBJ_DIR):
	@-mkdir -p $@

OBJS		:= $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# -------------------------- #
#      Dependency Files      #
# -------------------------- #

DEP_DIR		:= .dep

$(DEP_DIR):
	@-mkdir -p $@

DEPS		:= $(patsubst %.c, $(DEP_DIR)/%.d, $(SRCS))
override DEPFLAGS	+= -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d

-include $(DEPS)
$(DEP_DIR)/%.d: ;

# -------------------------- #
#         LIBFT Rule         #
# -------------------------- #

LIBFT_DIR := libft

LIBFT := $(LIBFT_DIR)/libft.a

$(LIBFT):
	@printf "[$(NAME)] $(YELLOW)Build:$(DEF_COLOR) $@\n"
	@$(MAKE) -C $(LIBFT_DIR)

override CPPFLAGS += -I$(LIBFT_DIR)/include
override LDFLAGS += -L$(LIBFT_DIR)
override LDLIBS += -lft

# -------------------------- #
#       MINILIBX Rule        #
# -------------------------- #

MINILIBX_DIR := minilibx

install: | ${MINILIBX_DIR}

${MINILIBX_DIR}:
	@git clone https://github.com/42Paris/minilibx-linux.git ${MINILIBX_DIR}
	@printf "[cub3D] $(GREEN)Install Complete:$(DEF_COLOR) $@\n"

LIBMLX := ${MINILIBX_DIR}/libmlx.a

${LIBMLX}: | ${MINILIBX_DIR}
	@make -s -C ${MINILIBX_DIR} > /dev/null 2>&1

override LDFLAGS += -L${MINILIBX_DIR}
ifeq ($(OS), Darwin)
override LDFLAGS += -L/usr/X11/lib
endif
override LDLIBS	+= -lmlx -lXext -lX11

# -------------------------- #
#       Library Rules        #
# -------------------------- #

override LDLIBS	+= -lm

# -------------------------- #
#        Build Rules         #
# -------------------------- #

all: $(NAME)

$(NAME): $(OBJS) | $(LIBFT) ${LIBMLX}
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@printf "[$(NAME)] $(GREEN)Build Complete:$(DEF_COLOR) $@\n"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR) $(DEP_DIR)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c $< -o $@

# -------------------------- #
#        Cleanup Rules       #
# -------------------------- #

# Remove object and dependency files only
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@-$(MAKE) -s -C ${MINILIBX_DIR} clean > /dev/null
	@$(RM) $(OBJS) $(DEPS)
	@printf "[$(NAME)] $(BLUE)Deleted Compiled Files$(DEF_COLOR): *.o *.d\n"

# Remove everything
fclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@-$(MAKE) -s -C ${MINILIBX_DIR} clean > /dev/null
	@$(RM) $(OBJS) $(DEPS)
	@printf "[$(NAME)] $(BLUE)Deleted Compiled Files$(DEF_COLOR): *.o *.d\n"
	@$(RM) -r $(NAME) $(OBJ_DIR) $(DEP_DIR)
	@printf "[$(NAME)] $(BLUE)Deleted Target File and Object File Dir$(DEF_COLOR): $(NAME) $(OBJ_DIR) $(DEP_DIR)\n"

# Full rebuild: clean everything and rebuild
re:
	@$(MAKE) fclean
	@$(MAKE) all

# -------------------------- #
#        Debug Rules         #
# -------------------------- #

san debug: $(NAME)

norm:
	@norminette -o src include $(LIBFT_DIR) | grep Error || true

# -------------------------- #
#    ANSI Escape Sequence    #
# -------------------------- #

DEF_COLOR := \033[0;39m
GRAY := \033[0;90m
RED := \033[0;91m
GREEN := \033[0;92m
YELLOW := \033[0;93m
BLUE := \033[0;94m
MAGENTA := \033[0;95m
CYAN := \033[0;96m
WHITE := \033[0;97m
