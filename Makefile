# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 13:25:37 by kjikuhar          #+#    #+#              #
#    Updated: 2026/05/19 23:34:29 by kjikuhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# phony
.PHONY: all clean fclean re bonus norm san debug

# makefile settings
OS		:= $(shell uname -s)
override MAKEFLAGS += -j --no-print-directory
override .DEFAULT_GOAL := all

.DEFAULT:
	@printf "No match. We want to write help here.\n"

.DELETE_ON_ERROR:

# target
NAME	:= cub3D

# compiler flags
CC				:= cc
override CFLAGS	+= -Wall -Wextra -Werror
# when submit, it should change -W3
override CFLAGS	+= -Wconversion -Wno-sign-conversion

ifeq ($(MAKECMDGOALS), san)
override CFALGS += -g -fsanitize=address,undefined
endif

ifeq ($(MAKECMDGOALS), debug)
override CFALGS += -g
endif

# include
INCLUDE_DIRS		:= include
override CPPFLAGS	+= $(foreach dir, $(INCLUDE_DIRS), -I$(dir))

# src directory
SRC_DIRS			:= src
SRS_DIRS			+= $(addprefix src/, \
							cleanup \
							error \
							validate_argument \
							parse_file parse_file/utils
							$(addprefix parse_file/, \
								parse_settings parse_settings/utils \
								parse_map \
							) \
						)


# --- srcs ---
SRCS	:= 	main.c

# cleanup
SRCS 	+=	cleanup_settings.c \
			cleanup_map.c
# error
SRCS 	+=	print_error.c
# validate_argument
SRCS 	+=	validate_argument.c
# parse_file
SRCS 	+=	parse_file.c \
			read_next_line.c \
			is_blank_line.c \
			replace_char.c
# parse_file/parse_settings
SRCS 	+=	parse_settings.c \
			parse_settings_line.c \
			is_incomplete_settings.c \
			set_texture.c \
			set_color.c \
			free_splitted.c
# parse_file/parse_map
SRCS 	+=	parse_map.c \
			read_map.c \
			parse_map_data.c \
			parse_map_cell.c

# --- vpath setup ---
# vpath %.c <dir>
$(foreach dir, $(SRCS_DIRS), $(eval vpath %.c $(dir)))

# ---obj dir ---
OBJ_DIR		:= .obj
OBJS		:= $(patsubst %.c $(OBJ_DIR)/%.o, $(SRCS))

DEP_DIR		:= .dep
DEPS		:= $(patsubst %.c $(DEP_DIR)/%.o, $(SRCS))
override CPPFLAGS += -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d

# default target
all: $(NAME)

$(NAME): $(OBJS) | $(LIBFT)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LIBFT) $^ -o $@

# -Ilibft/include -Iinclude -Ivec_library

# SRC_DIR := src
# OBJ_DIR := obj
# LIBFT_DIR := libft


# OBJS	:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# LIBFT_A	:= $(LIBFT_DIR)/libft.a

# all: $(NAME)

# $(NAME): $(LIBFT_A) $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_A)

# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
# 	mkdir -p $(OBJ_DIR) $(OBJ_DIR)/cleanup \
# $(OBJ_DIR)/error $(OBJ_DIR)/validate_argument $(OBJ_DIR)/parse_file \
# $(OBJ_DIR)/parse_file/utils $(OBJ_DIR)/parse_file/parse_settings $(OBJ_DIR)/parse_file/parse_settings/utils $(OBJ_DIR)/parse_file/parse_map

# 	$(CC) $(CFLAGS) -c -o $@ $^

# $(LIBFT_A):
# 	$(MAKE) -C $(LIBFT_DIR)
