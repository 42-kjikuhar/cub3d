/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 01:14:17 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/01 12:38:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_PRINT_UTILS_H
# define PF_PRINT_UTILS_H

# include <stdarg.h>
# include <stddef.h>

# include "ft_printf/pf_types.h"

void	pf_print_char(t_ctx *ctx, char c);
void	pf_print_strn(t_ctx *ctx, const char *s, size_t len);
void	pf_print_hexa_preffix(t_ctx *ctx, t_conv *conv);
void	pf_print_zero_width(t_ctx *ctx, t_conv *conv, size_t len);
void	pf_print_space_width(t_ctx *ctx, t_conv *conv, size_t len);
void	pf_print_sign(t_ctx *ctx, t_conv *conv, bool is_negative);
void	pf_print_padding(t_ctx *ctx, size_t padding);
void	pf_print_repeated_char(t_ctx *ctx, char c, size_t count);

#endif