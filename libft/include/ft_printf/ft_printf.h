/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 02:16:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 22:10:23 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdbool.h>
# include <stdarg.h>

# include "ft_printf/pf_types.h"

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
