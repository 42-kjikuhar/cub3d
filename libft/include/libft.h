/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:58:34 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/19 16:51:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

// libft
# include "libft/ft_ctype.h"
# include "libft/ft_lst.h"
# include "libft/ft_math.h"
# include "libft/ft_stdio.h"
# include "libft/ft_stdlib.h"
# include "libft/ft_string.h"

// ft_printf
int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_sprintf(char *str, const char *format, ...);
int		ft_snprintf(char *str, size_t size, const char *format, ...);

// get_next_line
char	*get_next_line(int fd);

#endif
