# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 21:27:03 by stanaka2          #+#    #+#              #
#    Updated: 2026/05/13 01:09:52 by stanaka2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------- #
#       Phony Targets        #
# -------------------------- #

.PHONY: all clean fclean re asan debug

# -------------------------- #
#      Makefile Setting      #
# -------------------------- #

OS		=	$(shell uname -s)

SHELL   =  	bash

MAKEFLAGS += --no-print-directory

RM = rm -f

# -------------------------- #
# 　　    　 Target           #
# -------------------------- #

NAME =	libft.a

# -------------------------- #
# 　　　Compiler Flags        #
# -------------------------- #

CFLAGS  =	-Wall -Wextra -Werror

ifeq ($(MAKECMDGOALS), asan)
CFLAGS +=	-g -fsanitize=address
endif

ifeq ($(MAKECMDGOALS), debug)
CFLAGS +=	-g
endif

# -------------------------- #
#          Include           #
# -------------------------- #

INCLUDE_DIR	=	include
INCLUDE  	=	-I $(INCLUDE_DIR)

# -------------------------- #
#     Source Directories     #
# -------------------------- #

SRC_DIR  =	src
SRC_DIRS =	$(addprefix $(SRC_DIR)/, ctype stdio stdlib string lst math)
SRC_DIRS +=	$(addprefix $(SRC_DIR)/, get_next_line)
SRC_DIRS +=	$(addprefix $(SRC_DIR)/, ft_printf \
				$(addprefix ft_printf/, \
					print_utils print_utils/utils\
					read_conversion read_conversion/utils \
					print_conversion \
					print_conversion/character print_conversion/character/utils\
					print_conversion/float print_conversion/float/utils \
					print_conversion/integer \
					print_conversion/special \
				)\
			)

# -------------------------- #
#        Source Files        #
# -------------------------- #

# ctype
SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isblank.c \
	   ft_iscntrl.c ft_isdigit.c ft_isgraph.c ft_islower.c \
	   ft_isprint.c ft_ispunct.c ft_isspace.c ft_isupper.c \
	   ft_isxdigit.c ft_tolower.c ft_toupper.c

# stdio
SRCS += ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		ft_putchar_fd_bytes.c ft_putendl_fd_bytes.c ft_putnbr_fd_bytes.c ft_putstr_fd_bytes.c

# stdlib
SRCS += ft_abs_uint.c ft_abs_ulong.c ft_atof.c ft_atoi.c ft_calloc.c ft_itoa.c ft_reallocf.c

# string
SRCS += ft_bzero.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_split.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c \
		ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
		ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strndup.c ft_strnlen.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_split_set.c

# lst
SRCS += ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
		ft_lst_push_back.c ft_lst_push_front.c ft_lst_pop_back.c ft_lst_pop_front.c

# math
SRCS += ft_fabs.c ft_round.c ft_sqrt.c ft_rand_r.c  ft_xorshift.c

# get_next_line
SRCS += get_next_line.c

# ft_printf
ifeq ($(OS), Darwin)
SRCS += ft_dprintf_darwin.c ft_printf_darwin.c ft_snprintf_darwin.c \
		ft_sprintf_darwin.c
else
SRCS += ft_dprintf.c ft_printf.c ft_snprintf.c ft_sprintf.c
endif

ifeq ($(OS), Darwin)
SRCS += pf_xprintf_darwin.c
else
SRCS += pf_xprintf.c
endif

# ft_printf/print_utils
SRCS += pf_print_char.c  pf_print_hexa_preffix.c  pf_print_padding.c \
		pf_print_sign.c  pf_print_space_width.c  pf_print_strn.c pf_print_zero_width.c \
		pf_print_repeated_char.c

# ft_printf/read_conversion
ifeq ($(OS), Darwin)
SRCS += pf_read_conversion_darwin.c
else
SRCS += pf_read_conversion.c
endif
SRCS += pf_check_int_overflow.c pf_precision_atoi.c

# ft_printf/print_conversion
SRCS += pf_print_conversion.c

# ft_printf/print_conversion/character
ifeq ($(OS), Darwin)
SRCS += pf_conv_c_darwin.c pf_conv_s_darwin.c pf_print_null_darwin.c pf_conv_lc_darwin.c 	pf_conv_ls_darwin.c \
		pf_calc_utf8_len_darwin.c pf_encode_utf8_darwin.c pf_validate_codepoint_darwin.c
else
SRCS += pf_conv_c.c pf_conv_s.c pf_print_null.c pf_conv_lc.c pf_conv_ls.c \
		pf_calc_utf8_len.c pf_encode_utf8.c pf_validate_codepoint.c
endif
SRCS += pf_print_utf8.c

# ft_printf/print_conversion/integer
SRCS += pf_conv_d_i.c pf_conv_o.c pf_conv_u.c pf_conv_x.c

# ft_printf/print_conversion/special
SRCS += pf_conv_n.c
ifeq ($(OS), Darwin)
SRCS += pf_conv_p_darwin.c pf_conv_percent_darwin.c
else
SRCS += pf_conv_p.c pf_conv_percent.c
endif

# ft_printf/print_conversion/float
SRCS += pf_conv_e.c pf_convert_to_decimal.c pf_convert_to_hex.c \
		pf_conv_f.c pf_conv_g.c \
		pf_decode_binary64.c pf_decode_binary80.c \
		pf_print_conv_e.c pf_print_conv_f.c \
		pf_print_conv_g_exp_notation.c pf_print_conv_g_fixed_point_notation.c \
		pf_round_to_nearest_even.c
ifeq ($(OS), Darwin)
SRCS += pf_conv_a_darwin.c pf_print_conv_a_darwin.c
else
SRCS += pf_conv_a.c pf_print_conv_a.c
endif

# ft_printf/print_conversion/float/utils
SRCS += pf_calc_array.c pf_get_decimal_exponent.c pf_print_exponent.c pf_t_float_utils.c
ifeq ($(OS), Darwin)
SRCS += pf_print_inf_darwin.c pf_print_nan_darwin.c
else
SRCS += pf_print_inf.c pf_print_nan.c
endif

# -------------------------- #
#    ANSI Escape Sequence    #
# -------------------------- #

DEF_COLOR	= \033[0;39m
GRAY 		= \033[0;90m
RED 		= \033[0;91m
GREEN 		= \033[0;92m
YELLOW 		= \033[0;93m
BLUE 		= \033[0;94m
MAGENTA 	= \033[0;95m
CYAN 		= \033[0;96m
WHITE 		= \033[0;97m

# -------------------------- #
#        VPATH Setup         #
# -------------------------- #

$(foreach dir,$(SRC_DIRS), $(eval vpath %.c $(dir)))

# -------------------------- #
#     Object & Dependency    #
# -------------------------- #

OBJ_DIR		=	.obj
OBJS		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))

DEP_DIR		=	.dep
DEPFLAGS	=	-MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
DEPS		=	$(patsubst %.c, $(DEP_DIR)/%.d, $(notdir $(SRCS)))

# -------------------------- #
#         Main Targets       #
# -------------------------- #

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) rcs $@ $?
	@echo -e "[LIBFT] $(GREEN)Build Complete:$(DEF_COLOR) $@"

# -------------------------- #
#         Debug Rules        #
# -------------------------- #

asan: $(NAME)
debug:  $(NAME)

# -------------------------- #
#        Build Rules         #
# -------------------------- #

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR) $(DEP_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) $(DEPFLAGS) -c $< -o $@

$(OBJ_DIR):
	@-mkdir -p $@

$(DEP_DIR):
	@-mkdir -p $@

# -------------------------- #
#       Cleanup Rules        #
# -------------------------- #

clean:
	@$(RM) $(OBJS) $(DEPS)
	@echo -e "[LIBFT] $(BLUE)Deleted Compiled Files$(DEF_COLOR): *.o *.d"

fclean:
	@$(RM) $(OBJS) $(DEPS)
	@echo -e "[LIBFT] $(BLUE)Deleted Compiled Files$(DEF_COLOR): *.o *.d"
	@$(RM) -r $(NAME) $(OBJ_DIR) $(DEP_DIR)
	@echo -e "[LIBFT] $(BLUE)Deleted Target File and Object File Dir$(DEF_COLOR): $(NAME) $(OBJ_DIR) $(DEP_DIR)"

re: fclean all

# -------------------------- #
#  Include Dependency Files  #
# -------------------------- #

-include $(DEPS)
