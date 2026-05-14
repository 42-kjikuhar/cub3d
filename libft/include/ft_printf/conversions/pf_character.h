/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_character.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 01:07:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/01 19:19:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_CHARACTER_H
# define PF_CHARACTER_H

# ifdef __APPLE__
#  define PF_REC2279 6
#  define PF_UTF8_SIZE PF_REC2279
# else
#  define PF_REC3629 4
#  define PF_UTF8_SIZE PF_REC3629
# endif

# include <stdarg.h>
# include <wchar.h>
# include <stddef.h>
# include <stdbool.h>

# include "ft_printf/pf_types.h"

void	pf_conv_c(va_list *ap, t_ctx *ctx, t_conv *conv);
void	pf_conv_s(va_list *ap, t_ctx *ctx, t_conv *conv);
void	pf_conv_lc(va_list *ap, t_ctx *ctx, t_conv *conv);
void	pf_conv_ls(va_list *ap, t_ctx *ctx, t_conv *conv);
void	pf_print_null(t_ctx *ctx, t_conv *conv);
bool	pf_validate_codepoint(wchar_t wc);
size_t	pf_calc_utf8_len(wchar_t wc);
void	pf_encode_utf8(wchar_t wc, unsigned char *utf8);
void	pf_print_utf8(t_ctx *ctx, const unsigned char *utf8_str, size_t len);

#endif
