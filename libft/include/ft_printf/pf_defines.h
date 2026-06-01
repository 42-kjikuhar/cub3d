/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_defines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:16:10 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 21:18:52 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_DEFINES_H
# define PF_DEFINES_H

# include <limits.h>

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

#endif
