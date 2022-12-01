/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:31:09 by gbohm             #+#    #+#             */
/*   Updated: 2022/12/01 13:52:20 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>

typedef enum e_padding_space {
	LEAVE_SPACE,
	LEAVE_NO_SPACE
}	t_padding_space;

typedef enum e_prefix {
	PREFIX_EMPTY,
	PREFIX_MINUS,
	PREFIX_PLUS,
	PREFIX_SPACE,
	PREFIX_0X_LOWER,
	PREFIX_0X_UPPER
}	t_prefix;

typedef struct s_buffer {
	char			*str;
	size_t			size;
	unsigned long	cursor;
}	t_buffer;

typedef struct s_properties {
	int		left_justify;
	int		plus;
	int		space;
	int		prefix;
	int		zeroes;
	int		padding;
	int		precision;
	char	specifier;
}	t_properties;

typedef struct s_range {
	unsigned long	start;
	size_t			length;
}	t_range;

typedef struct s_result {
	char		*str;
	t_prefix	prefix;
	size_t		size;
}	t_result;

typedef struct s_tag {
	t_properties	properties;
	t_range			range;
	t_result		result;
}	t_tag;

// eval.char
int		eval_char(int value, t_tag *tag);
// eval.str
int		eval_str(char *value, t_tag *tag);
// eval.hex
int		eval_hex(unsigned long value, t_tag *tag);
// eval.int
int		eval_int(int value, t_tag *tag);
// eval.unsigned
int		eval_unsigned(unsigned int value, t_tag *tag);

// process.apply
int		apply_flags(t_tag *tag);
// process.parse
int		parse_tag(t_buffer *buffer, t_tag *tag);
// process.run
int		advance_cursor(t_buffer *buffer);
int		evaluate(va_list args, t_tag *tag);
int		substitute(t_tag *tag, t_buffer *buffer);

// src.ft_printf
int		ft_printf(const char *format, ...);

// utils.buffer
int		init_buffer(const char *format, t_buffer *buffer);
char	get_char(t_tag *tag, t_buffer *buffer);
void	modify_buffer_size_and_cursor(t_tag *tag, t_buffer *buffer);
void	free_buffer(t_buffer *buffer);

// utils.checks
int		is_char_specifier(t_tag *tag);
int		is_percent_specifier(t_tag *tag);
int		is_str_specifier(t_tag *tag);
int		is_int_specifier(t_tag *tag);
int		is_unsigned_specifier(t_tag *tag);
// utils.checks2
int		is_hex_lower_specifier(t_tag *tag);
int		is_hex_upper_specifier(t_tag *tag);
int		is_hex_specifier(t_tag *tag);
int		is_ptr_specifier(t_tag *tag);
int		is_num_specifier(t_tag *tag);
// utils.checks3
int		is_specifier(char c);
int		is_flag(char c);
// utils.eval
int		itoa_base2(unsigned long value, char *base, char **str);
void	set_result_str(char *str, t_tag *tag);
// utils.flags
int		has_left_justify_flag(t_tag *tag);
int		has_plus_flag(t_tag *tag);
int		has_space_flag(t_tag *tag);
int		has_prefix_flag(t_tag *tag);
int		has_zeroes_flag(t_tag *tag);
// utils.flags2
int		has_padding(t_tag *tag);
int		has_precision(t_tag *tag);
// utils.malloc
int		malloc2(size_t count, char **str);
// utils.math
int		min(int a, int b);
int		max(int a, int b);
// utils.prefix
int		get_str_for_prefix2(t_prefix prefix, char **str);
int		get_prefix_length(t_prefix prefix);
// utils.str
int		strdup2(const char *src, char **dst);
int		substr2(unsigned int start, size_t length, char **str);
int		strapp2(char *src, char **dst);
int		padstr2(int padding, int right, int zeroes, t_result *result);
int		strsub(t_tag *tag, t_buffer *buffer);
// utils.str2
void	strass2(char *src, char **dst);
void	strins(char *src, size_t length, char *dst, unsigned long start);
void	strfll(char c, size_t length, char *dst, unsigned long start);
// utils.tag
void	init_tag(t_tag *tag);
void	free_tag(t_tag *tag);

#endif