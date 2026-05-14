/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 02:16:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/01 18:39:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdbool.h>
# include <stdarg.h>
# include <limits.h>

# include "libft.h"

# include "ft_printf/pf_types.h"
# include "ft_printf/pf_read_conversion.h"
# include "ft_printf/pf_print_utils.h"
# include "ft_printf/pf_print_conversion.h"

# ifdef __APPLE__
#  ifndef PRINTF_RESULT_LIMIT
#   define PRINTF_RESULT_LIMIT 2147483646
#  endif
#  ifndef PAGE_SIZE
#   define PAGE_SIZE 16384
#  endif
#  ifndef WRITE_BLOCK_SIZE
#   define WRITE_BLOCK_SIZE PAGE_SIZE
#  endif
#  ifndef PIPE_BUF
#   define PIPE_BUF 4096
#  endif
# else
#  define PRINTF_RESULT_LIMIT INT_MAX
#  ifndef PAGE_SIZE
#   define PAGE_SIZE 4096
#  endif
#  ifndef WRITE_BLOCK_SIZE
#   define WRITE_BLOCK_SIZE 16384
#  endif
#  ifndef PIPE_BUF
#   define PIPE_BUF 4096
#  endif
# endif

# define PF_ERROR -1
# define PF_CONV "cspdiuxX%onfFeEgGaA"
# define PF_FLAGS "-+ #0"
# define PF_LENGTH "hljztL"

enum e_dst_type
{
	PRINT_TO_FD,
	PRINT_TO_STR,
};

union u_dst
{
	int		fd;
	char	*str;
};

struct s_ctx
{
	enum e_dst_type	dst_type;
	union u_dst		dst;
	size_t			dst_size;
	size_t			count;
	bool			has_error;
};

struct s_conversion
{
	char		identifier;
	char		hash_flag;
	char		sign_flags;
	char		width_flags;
	int			width;
	bool		has_prec;
	int			precision;
	char		length[3];
};

void	pf_xprintf(t_ctx *ctx, va_list *ap, const char *format);

#endif
