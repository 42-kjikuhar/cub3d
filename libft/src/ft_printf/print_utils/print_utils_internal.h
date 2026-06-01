/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:33:06 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 21:46:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_UTILS_INTERNAL_H
# define PRINT_UTILS_INTERNAL_H

# include <stddef.h>

# include "ft_printf/pf_types.h"

void	pf_print_repeated_char(t_ctx *ctx, char c, size_t count);

#endif
