/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:52:13 by gbohm             #+#    #+#             */
/*   Updated: 2022/11/25 17:38:16 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "include/ft_printf.h"
#include "libft/libft.h"

#include <stdio.h>


void	strass2(char *src, char **dst)
{
	free(*dst);
	*dst = src;
}

int	strdup2(const char *src, char **dst)
{
	*dst = ft_strdup(src);
	return (*dst == NULL);
}

int	substr2(unsigned int start, size_t length, char **str)
{
	char	*sub;

	sub = ft_substr(*str, start, length);
	strass2(sub, str);
	return (*str == NULL);
}

int	malloc2(size_t count, char **str)
{
	*str = malloc(count);
	return (*str == NULL);
}

int	advance_cursor(t_buffer *buffer)
{
	char	c;

	c = buffer->str[buffer->size_actual];
	while (c && c != '%')
	{
		increment_buffer_size(buffer);
		c = buffer->str[buffer->size_actual];
	}
	return (!c);
}

void	init_tag(t_tag *tag)
{
	tag->properties.left_justify = 0;
	tag->properties.plus = 0;
	tag->properties.space = 0;
	tag->properties.prefix = 0;
	tag->properties.zeroes = 0;
	tag->properties.padding = 0;
	tag->properties.precision = -1;
	tag->properties.specifier = 0;
	tag->range.start = 0;
	tag->range.length = 0;
	tag->result.str = NULL;
	tag->result.prefix = PREFIX_EMPTY;
	tag->result.size_virtual = 0;
	tag->result.size_actual = 0;
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ignores_precision(char c)
{
	return (c == 'c' || c == 'p' || c == '%');
}

int evaluate(va_list args, t_tag *tag)
{
	if (tag->properties.specifier == 'c')
		return (eval_char(va_arg(args, int), tag));
	if (tag->properties.specifier == 's')
		return (eval_str(va_arg(args, char *), tag));
	if (tag->properties.specifier == 'p')
		return (eval_hex(va_arg(args, unsigned long), tag));
	if (tag->properties.specifier == 'd')
		return (eval_int(va_arg(args, int), tag));
	if (tag->properties.specifier == 'i')
		return (eval_int(va_arg(args, int), tag));
	if (tag->properties.specifier == 'u')
		return (eval_unsigned(va_arg(args, unsigned int), tag));
	if (tag->properties.specifier == 'x')
		return (eval_hex(va_arg(args, unsigned long), tag));
	if (tag->properties.specifier == 'X')
		return (eval_hex(va_arg(args, unsigned long), tag));
	if (tag->properties.specifier == '%')
		return (eval_char('%', tag));
	return (1);
}

// int	prepare_str(t_tag *tag)
// {
// 	size_t	length;

// 	length = ft_strlen(tag->parts.str);
// 	if (tag->properties.specifier == 's' && tag->properties.precision != -1
// 		&& tag->properties.precision < length)
// 		length = tag->properties.precision;
// 	if (ignores_precision(tag->properties.precision))
// 		length = max(length, tag->properties.precision);
// 	length += ft_strlen(tag->parts.prefix);
// 	length = max(length, tag->properties.padding);
// 	if (malloc2(length + 1, &tag->construct.str))
// 		return (1);
// 	tag->construct.str[length] = 0;
// 	// tag->construct.length = length;
// 	return (0);
// }

// int	padstr3(int padding, int right, int zeroes, char **str)
// {
// 	size_t	i;
// 	size_t	length;
// 	int		offset;
// 	char	*new;
// 	char	c;

// 	length = ft_strlen(*str);
// 	offset = padding - length;
// 	if (offset <= 0)
// 		return (0);
// 	if (right)
// 		offset = 0;
// 	if (malloc2(padding + 1, &new))
// 		return (1);
// 	new[padding] = 0;
// 	c = ' ';
// 	if (zeroes)
// 		c = '0';
// 	i = 0;
// 	while (i < padding)
// 	{
// 		if (i >= offset && i < offset + length)
// 			new[i] = (*str)[i - offset];
// 		else
// 			new[i] = c;
// 		i++;
// 	}
// 	strass2(new, str);
// 	return (0);
// }

int	padstr2(int padding, int right, int zeroes, t_result *result)
{
	size_t	i;
	size_t	length;
	int		offset;
	char	*new;
	char	c;

	// printf("%zu\n", result->size_virtual);
	offset = padding - result->size_virtual;
	if (offset <= 0)
		return (0);
	if (right)
		offset = 0;
	if (malloc2(padding + 1, &new))
		return (1);
	new[padding] = 0;
	c = ' ';
	if (zeroes)
		c = '0';
	i = 0;
	while (i < padding)
	{
		if (i >= offset && i < offset + result->size_virtual)
			new[i] = result->str[i - offset];
		else
			new[i] = c;
		i++;
	}
	strass2(new, &result->str);
	return (0);
}

int apply_precision(t_tag *tag)
{
	if (tag->properties.precision == -1)
		return (0);
	if (tag->properties.specifier == 's')
	{
		if (substr2(0, tag->properties.precision, &tag->result.str))
			return (2);
		return (0);
	}
	if (ignores_precision(tag->properties.specifier))
		return (0);
	if (padstr2(tag->properties.precision, 0, 1, &tag->result))
		return (2);
	return (0);
}

int	strapp2(char *src, char **dst)
{
	char	*new;

	new = ft_strjoin(src, *dst);
	strass2(new, dst);
	return (*dst == NULL);
}

int	apply_prefix(t_tag *tag)
{
	const char	*prefixes[] = {"", "-", "+", " ", "0x", "0X"};
	size_t		length;

	if (strapp2(prefixes[tag->result.prefix], &tag->result.str))
		return (1);
	length = ft_strlen(prefixes[tag->result.prefix]);
	tag->result.size_virtual = length;
	tag->result.size_actual = length;
	return (0);
}

int	apply_padding(t_tag *tag)
{
	if (padstr2(tag->properties.padding, tag->properties.left_justify,
			tag->properties.zeroes, &tag->result))
		return (1);
	return (0);
}

int	strsub2(unsigned int position, size_t length, char *sub, char **str)
{
	unsigned int	i;
	size_t			str_length;
	size_t			sub_length;
	size_t			total_length;
	char			*result;
	char			*cursor;
	char			*cursor_sub;

	str_length = ft_strlen(*str);
	if (position > str_length)
		return (1);
	if (str_length - position < length)
		length = str_length - position;
	sub_length = ft_strlen(sub);
	total_length = str_length - length + sub_length;
	if (malloc2(total_length + 1, &result))
		return (2);
	result[total_length] = 0;
	cursor = *str;
	i = 0;
	while (i < position)
		result[i++] = *cursor++;
	cursor_sub = sub;
	while (*cursor_sub)
		result[i++] = *cursor_sub++;
	// free(sub);
	cursor += length;
	while (i < total_length)
		result[i++] = *cursor++;
	strass2(result, str);
	return (0);
}

int	substitute(t_tag *tag, t_buffer *buffer)
{
	if (strsub2(tag->range.start, tag->range.length,
			tag->result.str, &buffer->str))
		return (1);
	buffer->size_virtual += tag->result.size_virtual;
	buffer->size_actual += tag->result.size_actual;
	return (0);
}

int	run(va_list args, t_buffer *buffer)
{
	t_tag	tag;

	while (1)
	{
		if (advance_cursor(buffer))
			return (0);
		if (parse_tag(buffer, &tag))
			return (1);
		if (evaluate(args, &tag))
			return (2);
		if (apply_precision(&tag))
			return (3);
		if (apply_prefix(&tag))
			return (4);
		if (apply_padding(&tag))
			return (5);
		if (substitute(&tag, buffer))
			return (6);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_buffer	buffer;

	va_start(args, format);
	if (init_buffer(format, &buffer))
		return (-1);
	if (run(args, &buffer))
		return (-1);
	write(1, buffer.str, buffer.size_actual);
	free(buffer.str);
	return (buffer.size_virtual);
}
