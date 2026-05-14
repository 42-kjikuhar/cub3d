/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_float.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 16:16:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/02 16:22:01 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_FLOAT_H
# define PF_FLOAT_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
// # include <float.h>
/*
#include <unicode/utypes.h> is workaround for #include <float.h>
due to norminette=3.3.55 bug.
*/
# include <unicode/utypes.h>

# include "ft_printf/pf_types.h"

// IEEE754 binary64
# define BINARY64_SIZE 64
# define BINARY64_SIGN 1
# define BINARY64_EXPONENT 11
# define BINARY64_FRACTION 52
# define BINARY64_EMAX 1023
# define BINARY64_NAN_INF 2047

// PF_BINARY64_INT: BINARY64_MAX = 1.80×10^308
# define PF_BINARY64_INT 309
// PF_BINARY64_FRAC: -(52 + 1) + (-1022 + 1) = -1074
# define PF_BINARY64_FRAC 1074
// PF_BINARY64_FRAC_HEX: 1bit -> 0 or 1
# define PF_BINARY64_INT_HEX 1
// PF_BINARY64_FRAC_HEX: 52bit / 4bit = 13
# define PF_BINARY64_FRAC_HEX 13

// binary80
# define BINARY80_SIZE 80
# define BINARY80_SIGN 1
# define BINARY80_EXPONENT 15
# define BINARY80_FRACTION 63
# define BINARY80_EMAX 16383
# define BINARY80_NAN_INF 32767

// PF_BINARY80_INT: BINARY80_MAX = 1.19×10^4932
# define PF_BINARY80_INT 4933

// PF_BINARY80_FRAC: -64 + (-16382 + 1) = -16445
# define PF_BINARY80_FRAC 16445

// PF_BINARY80_FRAC_HEX: 63bit / 4bit = 15.75
# define PF_BINARY80_FRAC_HEX 16
# if LBINARY64_MANT_DIG == 113
#  error "binary128 has not been implemented."
// binary128
#  define BINARY128_SIZE 128
#  define BINARY128_SIGN 1
#  define BINARY128_EXPONENT 15
#  define BINARY128_FRACTION 112
#  define BINARY128_EMAX 16383
#  define BINARY128_NAN_INF 32767

// PF_BINARY128_INT: BINARY128_MAX = 1.19×10^4932
#  define PF_BINARY128_INT 4933

// PF_BINARY128_FRAC: -(112 + 1) + (-16382 + 1) = -16494
#  define PF_BINARY128_FRAC 16494

// PF_BINARY128_FRAC_HEX: 112bit / 4bit = 28
#  define PF_BINARY128_FRAC_HEX 28
# endif

enum e_pf_float_value_type
{
	PF_ZERO,
	PF_NORMAL,
	PF_SUBNORMAL,
	PF_INF,
	PF_NAN,
};

/*
binary64 or binary80

print_buf layout: [int_part: print_int_size][frac_part: print_frac_size]
radix_point = print_buf + print_int_size
  radix_point[n]  (n >= 0): n-th digit after the decimal point
  radix_point[-n] (n >  0): n-th digit before the decimal point (integer part)
This layout allows carry to propagate across the decimal point without branching.
*/
typedef struct s_floating_point
{
	// bit
	uint8_t						sign;
	int16_t						exponent;
	uint64_t					fraction;
	uint64_t					significand;
	uint64_t					int_binary;
	uint64_t					frac_binary;
	// print
	int8_t						*print_buf;
	int8_t						*radix_point;
	// metadata
	uint8_t						base;
	uint8_t						type_bit_size;
	uint8_t						sign_size;
	uint8_t						exponent_size;
	uint8_t						fraction_size;
	uint16_t					emax;
	uint16_t					nan_inf_exponent;
	enum e_pf_float_value_type	value_type;
	uint16_t					print_buf_size;
	uint16_t					print_int_size;
	uint16_t					print_frac_size;
}	t_pf_float;

void	pf_conv_a_binary64(va_list *ap, t_ctx *ctx, t_conv *conv);
void	pf_conv_e_binary64(va_list *ap, t_ctx *ctx, t_conv *conv);
void	pf_conv_e_binary80(va_list *ap, t_ctx *ctx, t_conv *conv);
void	pf_conv_f_binary64(va_list *ap, t_ctx *ctx, t_conv *conv);
void	pf_conv_f_binary80(va_list *ap, t_ctx *ctx, t_conv *conv);
void	pf_conv_g_binary64(va_list *ap, t_ctx *ctx, t_conv *conv);
void	pf_conv_g_binary80(va_list *ap, t_ctx *ctx, t_conv *conv);
bool	pf_convert_to_decimal(t_pf_float *fp);
void	pf_convert_to_hex(t_pf_float *fp);
void	pf_decode_binary64(double num, t_pf_float *fp);
void	pf_decode_binary80(long double num, t_pf_float *fp);
void	pf_print_conv_a(t_ctx *ctx, t_conv *conv, t_pf_float *fp);
void	pf_print_conv_e(t_ctx *ctx, t_conv *conv, t_pf_float *fp);
void	pf_print_conv_f(t_ctx *ctx, t_conv *conv, t_pf_float *fp);
void	pf_print_conv_g_exp_notation(
			t_ctx *ctx, t_conv *conv, t_pf_float *fp, int decimal_exp);
void	pf_print_conv_g_fixed_point(
			t_ctx *ctx, t_conv *conv, t_pf_float *fp, int decimal_exp);
void	pf_round_to_nearest_even(t_pf_float *fp, int precision);

// utils
void	pf_array_add(int8_t *augend, int8_t *addend, int array_size);
void	pf_array_half(int8_t *dividend, int array_size);
void	pf_array_double(int8_t *multiplicand, int array_size);
void	pf_array_double_hex(int8_t *multiplicand, int array_size);
int		pf_get_decimal_exponent(t_pf_float *fp);
void	pf_print_decimal_exponent(t_ctx *ctx, t_conv *conv, int decimal_exp);
void	pf_print_binary_exponent(t_ctx *ctx, t_conv *conv, int binary_exp);
void	pf_print_inf(t_ctx *ctx, t_conv *conv, t_pf_float *fp);
void	pf_print_nan(t_ctx *ctx, t_conv *conv, t_pf_float *fp);
bool	pf_float_init(t_pf_float *fp, uint16_t type_bit_size, uint8_t base);
void	pf_float_destroy(t_pf_float *fp);

#endif
