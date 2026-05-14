/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_defines.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:22:17 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/19 15:52:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_DEFINES_H
# define LIBFT_DEFINES_H

# ifdef __APPLE__
#  ifndef PAGE_SIZE
#   define PAGE_SIZE 16384
#  endif
#  ifndef WRITE_BLOCK_SIZE
#   define WRITE_BLOCK_SIZE PAGE_SIZE
#  endif
# else
#  ifndef PAGE_SIZE
#   define PAGE_SIZE 4096
#  endif
#  ifndef WRITE_BLOCK_SIZE
#   define WRITE_BLOCK_SIZE 16384
#  endif
# endif

#endif
