# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 13:25:37 by kjikuhar          #+#    #+#              #
#    Updated: 2026/05/19 22:12:27 by stanaka2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= cc
NAME	:= cub3D

SRC_DIR := src
OBJ_DIR := obj
LIBFT_DIR := libft
SRCS	:= 	src/main.c \
			src/cleanup/cleanup_settings.c \
			src/cleanup/cleanup_map.c \
			src/error/print_error.c \
			src/validate_argument/validate_argument.c \
			src/parse_file/parse_file.c \
			src/parse_file/utils/read_next_line.c \
			src/parse_file/utils/is_blank_line.c \
			src/parse_file/utils/replace_char.c \
			src/parse_file/parse_settings/parse_settings.c \
			src/parse_file/parse_settings/parse_settings_line.c \
			src/parse_file/parse_settings/is_incomplete_settings.c \
			src/parse_file/parse_settings/set_texture.c \
			src/parse_file/parse_settings/set_color.c \
			src/parse_file/parse_settings/utils/free_splitted.c \
			src/parse_file/parse_map/parse_map.c \
			src/parse_file/parse_map/read_map.c \
			src/parse_file/parse_map/parse_map_data.c \
			src/parse_file/parse_map/parse_map_cell.c \


OBJS	:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CFLAGS	:= -Wall -Wextra -Werror -Ilibft/include -Iinclude -Ivec_library

LIBFT_A	:= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_A)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR) $(OBJ_DIR)/cleanup \
$(OBJ_DIR)/error $(OBJ_DIR)/validate_argument $(OBJ_DIR)/parse_file \
$(OBJ_DIR)/parse_file/utils $(OBJ_DIR)/parse_file/parse_settings $(OBJ_DIR)/parse_file/parse_settings/utils $(OBJ_DIR)/parse_file/parse_map

	$(CC) $(CFLAGS) -c -o $@ $^

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)
