# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 13:25:37 by kjikuhar          #+#    #+#              #
#    Updated: 2026/05/21 20:06:38 by stanaka2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------- #
#       Phony Targets        #
# -------------------------- #

.PHONY: all bonus clean fclean re install uninstall norm san debug test help

# -------------------------- #
#      Makefile Setting      #
# -------------------------- #

OS	:= $(shell uname -s)

override MAKEFLAGS		+= --no-print-directory

override .DEFAULT_GOAL	:= all

.DEFAULT:
	@printf "$(RED)make: *** No rule to make target '$@'.  Stop.$(DEF_COLOR)\n"
	@$(MAKE) help;
	@exit 2

.DELETE_ON_ERROR:

help:
	@printf "$(CYAN)Usage:$(DEF_COLOR)\n"
	@printf "$(GREEN)all$(DEF_COLOR)        Build $(NAME)\n"
	@printf "$(GREEN)clean$(DEF_COLOR)      Remove object files, dependency files\n"
	@printf "$(GREEN)fclean$(DEF_COLOR)     Remove all generated files\n"
	@printf "$(GREEN)re$(DEF_COLOR)         Rebuild from scratch\n"
	@printf "$(BLUE)install$(DEF_COLOR)    Install minilibx\n"
	@printf "$(BLUE)uninstall$(DEF_COLOR)  Remove minilibx\n"
	@printf "$(YELLOW)san$(DEF_COLOR)        Build with Sanitizer=Address,Undefine\n"
	@printf "$(YELLOW)debug$(DEF_COLOR)      Build with debug symbols\n"
	@printf "$(YELLOW)norm$(DEF_COLOR)       Run norminette\n"
	@printf "$(GRAY)help$(DEF_COLOR)       Show make rules\n"

# -------------------------- #
#         Extra Flags        #
# -------------------------- #

EXTRA_CFLAGS	:= $(CFLAGS)
EXTRA_CPPFLAGS	:= $(CPPFLAGS)

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
override CFLAGS	+= -Wconversion -Wno-sign-conversion -Wshadow

# -------------------------- #
#          Include           #
# -------------------------- #

INCLUDE_DIRS		:= include

override CPPFLAGS	+= $(foreach dir, $(INCLUDE_DIRS), -I$(dir))

# -------------------------- #
#     Source Directories     #
# -------------------------- #

SRC_DIRS	:= src
SRC_DIRS	+= $(addprefix src/, \
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

OBJ_DIR	:= .obj

$(OBJ_DIR):
	@-mkdir -p $@

OBJS	:= $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# -------------------------- #
#      Dependency Files      #
# -------------------------- #

DEP_DIR	:= .dep

$(DEP_DIR):
	@-mkdir -p $@

DEPS	:= $(patsubst %.c, $(DEP_DIR)/%.d, $(SRCS))
DEPFLAGS	= -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d

-include $(DEPS)
$(DEP_DIR)/%.d: ;

# -------------------------- #
#         LIBFT Rule         #
# -------------------------- #

LIBFT_DIR	:= libft

LIBFT		:= $(LIBFT_DIR)/libft.a

$(LIBFT):
	@printf "[$(NAME)] $(YELLOW)Build:$(DEF_COLOR) $@\n"
	@$(MAKE) -C $(LIBFT_DIR) CFLAGS='$(EXTRA_CFLAGS)' CPPFLAGS='$(EXTRA_CPPFLAGS)'

override CPPFLAGS	+= -I$(LIBFT_DIR)/include
override LDFLAGS	+= -L$(LIBFT_DIR)
override LDLIBS		+= -lft

# -------------------------- #
#       LIBMLX Rule          #
# -------------------------- #

LIBMLX_DIR	:= minilibx

install:
	@$(MAKE) uninstall
	@git clone https://github.com/42Paris/minilibx-linux.git $(LIBMLX_DIR)
	@printf "[cub3D] $(GREEN)Install Complete:$(DEF_COLOR) $(LIBMLX_DIR)\n"

uninstall:
	@$(RM) -r $(LIBMLX_DIR)
	@printf "[cub3D] $(GREEN)Uninstall Complete:$(DEF_COLOR) $(LIBMLX_DIR)\n"

$(LIBMLX_DIR):
	@$(MAKE) install

LIBMLX		:= $(LIBMLX_DIR)/libmlx.a

$(LIBMLX): | $(LIBMLX_DIR)
	@$(MAKE) -s -C $(LIBMLX_DIR) > /dev/null 2>&1
	@printf "[$(NAME)] $(GREEN)Build Complete:$(DEF_COLOR) $@\n"

override CPPFLAGS	+= -I$(LIBMLX_DIR)
override LDFLAGS	+= -L$(LIBMLX_DIR)
ifeq ($(OS), Darwin)
override CPPFLAGS	+= -I/usr/X11/include
override LDFLAGS	+= -L/usr/X11/lib
endif
override LDLIBS	+= -lmlx -lXext -lX11

# -------------------------- #
#       Library Rules        #
# -------------------------- #

LDLIBS	+= -lm

# -------------------------- #
#        Build Rules         #
# -------------------------- #

all: $(NAME)

$(NAME): $(OBJS) | $(LIBFT) $(LIBMLX)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)
	@printf "[$(NAME)] $(GREEN)Build Complete:$(DEF_COLOR) $@\n"

$(OBJ_DIR)/%.o: %.c | $(LIBMLX_DIR) $(OBJ_DIR) $(DEP_DIR)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c $< -o $@

# -------------------------- #
#        Cleanup Rules       #
# -------------------------- #

# Remove object and dependency files only
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@-$(MAKE) -s -C $(LIBMLX_DIR) clean > /dev/null 2>&1
	@$(RM) $(OBJS) $(DEPS)
	@printf "[$(NAME)] $(BLUE)Deleted Complete$(DEF_COLOR): *.o *.d\n"

# Remove everything
fclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@-$(MAKE) -s -C $(LIBMLX_DIR) clean > /dev/null 2>&1
	@printf "[$(NAME)] $(BLUE)Delete Complete$(DEF_COLOR): $(LIBMLX) $(LIBMLX_DIR)/obj\n"
	@$(RM) $(OBJS) $(DEPS)
	@printf "[$(NAME)] $(BLUE)Delete Complete$(DEF_COLOR): *.o *.d\n"
	@$(RM) -r $(NAME) $(OBJ_DIR) $(DEP_DIR)
	@printf "[$(NAME)] $(BLUE)Delete Complete$(DEF_COLOR): $(NAME) $(OBJ_DIR) $(DEP_DIR)\n"

# Full rebuild: clean everything and rebuild
re:
	@$(MAKE) fclean
	@$(MAKE) all CFLAGS='$(EXTRA_CFLAGS)' CPPFLAGS='$(EXTRA_CPPFLAGS)'

# -------------------------- #
#        Debug Rules         #
# -------------------------- #

san:
	@$(MAKE) re CPPFLAGS='$(EXTRA_CPPFLAGS) -g -fsanitize=address,undefined'

debug:
	@$(MAKE) re CPPFLAGS='$(EXTRA_CPPFLAGS) -g'

test:
	@bash TEST/test.sh

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
