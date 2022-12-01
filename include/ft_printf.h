/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:31:09 by gbohm             #+#    #+#             */
/*   Updated: 2022/11/30 13:58:40 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>

// typedef int	t_bool;
// # define true 1;
// # define false 0;

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

int		ft_printf(const char *format, ...);
int		advance_cursor(t_buffer *buffer);
int		apply_precision(t_tag *tag);
int		apply_prefix(t_tag *tag);
int		init_buffer(const char *format, t_buffer *buffer);
void	init_tag(t_tag *tag);
int		parse_tag(t_buffer *buffer, t_tag *tag);
int		evaluate(va_list args, t_tag *tag);

int		is_char_specifier(t_tag *tag);
int		is_str_specifier(t_tag *tag);
int		is_ptr_specifier(t_tag *tag);
int		is_hex_lower_specifier(t_tag *tag);
int		is_hex_upper_specifier(t_tag *tag);
int		is_hex_specifier(t_tag *tag);
int		is_int_specifier(t_tag *tag);
int		is_unsigned_specifier(t_tag *tag);
int		is_percent_specifier(t_tag *tag);

int		eval_char(int value, t_tag *tag);
int		eval_str(char *value, t_tag *tag);
int		eval_hex(unsigned long value, t_tag *tag);
int		eval_int(int value, t_tag *tag);
int		eval_unsigned(unsigned int value, t_tag *tag);

void	increment_buffer_size(t_buffer *buffer);
int		strdup2(const char *src, char **dst);
int		substr2(unsigned int start, size_t length, char **str);
int		padstr2(int padding, int right, int zeroes, t_result *result);
// int		padstr2(int padding, int right, int zeroes, char **str);
int		malloc2(size_t count, char **str);
int		itoa_base2(unsigned long value, char *base, char **str);
void	set_result_str(char *str, t_tag *tag);

int		get_str_for_prefix2(t_prefix prefix, char **str);
int		get_prefix_length(t_prefix prefix);

void	init_tag(t_tag *tag);
void	free_tag(t_tag *tag);
int		has_left_justify_flag(t_tag *tag);
int		has_plus_flag(t_tag *tag);
int		has_space_flag(t_tag *tag);
int		has_prefix_flag(t_tag *tag);
int		has_zeroes_flag(t_tag *tag);
int		has_padding(t_tag *tag);
int		has_precision(t_tag *tag);

void	modify_buffer_size_and_cursor(t_tag *tag, t_buffer *buffer);
void	free_buffer(t_buffer *buffer);

int		min(int a, int b);
int		max(int a, int b);

#endif