/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:44:12 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 21:49:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_INTERNAL_H
# define CHARACTER_INTERNAL_H

# include <stddef.h>
# include <wchar.h>

# include "ft_printf/pf_types.h"

# ifdef __APPLE__
#  define PF_REC2279 6
#  define PF_UTF8_SIZE PF_REC2279
# else
#  define PF_REC3629 4
#  define PF_UTF8_SIZE PF_REC3629
# endif

void	pf_print_null(t_ctx *ctx, t_conv *conv);
bool	pf_validate_codepoint(wchar_t wc);
size_t	pf_calc_utf8_len(wchar_t wc);
void	pf_encode_utf8(wchar_t wc, unsigned char *utf8);
void	pf_print_utf8(t_ctx *ctx, const unsigned char *utf8_str, size_t len);

#endif
