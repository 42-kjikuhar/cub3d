# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 13:25:37 by kjikuhar          #+#    #+#              #
#    Updated: 2026/05/14 17:04:11 by kjikuhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= cc
NAME	:= cub3D

SRC_DIR := src
OBJ_DIR := obj
LIBFT_DIR := libft
SRCS	:= src/main.c
OBJS	:= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)/%.o)
CFLAGS	:= -Wall -Wextra -Werror -Ilibft/include -Iinclude -Ivec_library

LIBFT_A	:= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_A)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $^

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)
