/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:31:09 by gbohm             #+#    #+#             */
/*   Updated: 2022/11/24 16:29:29 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>

// typedef int	t_bool;
// # define true 1;
// # define false 0;

enum e_prefix {
	PREFIX_EMPTY = 0,
	PREFIX_MINUS = 1,
	PREFIX_PLUS = 2,
	PREFIX_SPACE = 3,
	PREFIX_0X = 4
};

typedef struct s_buffer {
	char	*str;
	int		size_virtual;
	int		size_actual;
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
	unsigned int	start;
	size_t			length;
}	t_range;

typedef struct s_parts {
	char			*str;
	enum e_prefix	prefix;
	size_t			size_virtual;
	size_t			size_actual;
}	t_parts;

typedef struct s_construct {
	char	*str;
	size_t	size_virtual;
	size_t	size_actual;
}	t_construct;

typedef struct s_tag {
	t_properties	properties;
	t_range			range;
	t_parts			parts;
	t_construct		construct;
}	t_tag;

int		ft_printf(const char *format, ...);
int		advance_cursor(t_buffer *buffer);
int		apply_precision(t_tag *tag);
int		init_buffer(t_buffer *buffer, const char *format);
void	init_tag(t_tag *tag);
int		parse_tag(t_tag *tag, t_buffer *buffer);

void	increment_buffer_size(t_buffer *buffer);
int		strdup2(const char *src, char **dst);
int		padstr2(int padding, int right, int zeroes, char **str);
int		malloc2(size_t count, char **str);


// char	*ft_eval_char(t_tag *tag, int value);
// char	*ft_eval_str(t_tag *tag, char *value);
// char	*ft_eval_hex(t_tag *tag, unsigned long value);
// char	*ft_eval_int(t_tag *tag, int value);
// char	*ft_eval_unsigned(t_tag *tag, unsigned int value);
// char	*zero_str(char *value, t_tag *tag);
// char	*pad_str(char *value, t_tag *tag);
// char	*build_str(char *value, char *prefix, t_tag *tag);
// char	*eval_num(unsigned long long value, char *base);

// int		parse_tag(char *str, t_tag *tag, int *length);

// int		strsub(char **str, unsigned int position, size_t length, char *sub);

// // remove later
// void	initialize_tag(t_tag *tag);
// int		is_flag(char c);

#endif