/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:52:13 by gbohm             #+#    #+#             */
/*   Updated: 2022/11/29 11:44:27 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"


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

	c = buffer->str[buffer->cursor];
	while (c && c != '%')
		c = buffer->str[++buffer->cursor];
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
	tag->result.size = 0;
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ignores_precision(char c)
{
	return (c == 'c' || c == '%');
}

int evaluate(va_list args, t_tag *tag)
{
	if (is_char_specifier(tag))
		return (eval_char(va_arg(args, int), tag));
	if (is_str_specifier(tag))
		return (eval_str(va_arg(args, char *), tag));
	if (is_ptr_specifier(tag))
		return (eval_hex(va_arg(args, unsigned long), tag));
	if (is_hex_specifier(tag))
		return (eval_hex(va_arg(args, unsigned int), tag));
	if (is_int_specifier(tag))
		return (eval_int(va_arg(args, int), tag));
	if (is_unsigned_specifier(tag))
		return (eval_unsigned(va_arg(args, unsigned int), tag));
	if (is_percent_specifier(tag))
		return (eval_char('%', tag));
	return (1);
}

int	padstr2(int padding, int right, int zeroes, t_result *result)
{
	int		i;
	size_t	length;
	int		offset;
	char	*new;
	char	c;

	// printf("%zu\n", result->size_virtual);
	length = result->size;
	offset = padding - length;
	if (offset <= 0)
		return (0);
	result->size += offset;
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
		if (i >= offset && i < (int) (offset + length))
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
	int	difference;

	if (tag->properties.precision == -1)
		return (0);
	if (tag->properties.specifier == 's')
	{
		// difference = ft_strlen(tag->result.str) - tag->properties.precision;
		difference = tag->result.size - tag->properties.precision;
		if (difference > 0)
			tag->result.size -= difference;
		if (substr2(0, tag->properties.precision, &tag->result.str))
			return (2);
		return (0);
	}
	if (is_char_specifier(tag) || is_percent_specifier(tag))
		return (0);
	// printf("%c\n", tag->properties.specifier);
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
	char	*prefix;
	int		length;

	if (tag->result.prefix == PREFIX_EMPTY)
		return (0);
	if (get_str_for_prefix2(tag->result.prefix, &prefix))
		return (1);
	if (strapp2(prefix, &tag->result.str))
		return (free(prefix), 2);
	free(prefix);
	length = get_prefix_length(tag->result.prefix);
	tag->result.size += length;
	return (0);
}

int	is_num_specifier(t_tag *tag)
{
	if (is_int_specifier(tag))
		return (1);
	if (is_unsigned_specifier(tag))
		return (1);
	if (is_hex_specifier(tag))
		return (1);
	return (0);
}

int	apply_padding(t_padding_space leave_space, t_tag *tag)
{
	int	zeroes;
	int	space;

	zeroes = tag->properties.zeroes;
	if (tag->properties.left_justify
		|| (is_num_specifier(tag) && tag->properties.precision != -1))
		zeroes = 0;
	space = 0;
	if (leave_space == LEAVE_SPACE)
		space = get_prefix_length(tag->result.prefix);
	if (padstr2(tag->properties.padding - space, tag->properties.left_justify,
			zeroes, &tag->result))
		return (1);
	return (0);
}

// int	strsub2(unsigned long position, size_t length, char *sub, char **str)
// {
// 	unsigned long	i;
// 	size_t			str_length;
// 	size_t			sub_length;
// 	size_t			total_length;
// 	char			*result;
// 	char			*cursor;
// 	char			*cursor_sub;

// 	str_length = ft_strlen(*str);
// 	if (position > str_length)
// 		return (1);
// 	if (str_length - position < length)
// 		length = str_length - position;
// 	sub_length = ft_strlen(sub);
// 	total_length = str_length - length + sub_length;
// 	if (malloc2(total_length + 1, &result))
// 		return (2);
// 	result[total_length] = 0;
// 	cursor = *str;
// 	i = 0;
// 	while (i < position)
// 		result[i++] = *cursor++;
// 	cursor_sub = sub;
// 	printf("AAAAA %zu %zu %zu\n", i, position, length);
// 	while (i - position < length)
// 	{
// 		result[i] = sub[i - position];
// 		i++;
// 	}
// 	free(sub);
// 	cursor += length;
// 	while (i < total_length)
// 		result[i++] = *cursor++;
// 	strass2(result, str);
// 	return (0);
// }

void	strins(char *src, size_t length, char *dst, unsigned long start)
{
	unsigned long	i;

	i = 0;
	while (i < length)
	{
		dst[start + i] = src[i];
		i++;
	}
}

int	strsub(t_tag *tag, t_buffer *buffer)
{
	unsigned long	total_length;
	char			*str;

	if (tag->range.start > buffer->size)
		return (1);
	total_length = buffer->size - tag->range.length + tag->result.size;
	if (malloc2(total_length + 1, &str))
		return (2);
	str[total_length] = 0;
	strins(buffer->str, tag->range.start, str, 0);
	strins(tag->result.str, tag->result.size, str, tag->range.start);
	strins(buffer->str + tag->range.start + tag->range.length, buffer->size - tag->range.start - tag->range.length, str, tag->range.start + tag->result.size);
	strass2(str, &buffer->str);
	return (0);
}

int	substitute(t_tag *tag, t_buffer *buffer)
{
	if (strsub(tag, buffer))
		return (free(tag->result.str), 1);
	free(tag->result.str);
	buffer->size += tag->result.size - tag->range.length;
	buffer->cursor += tag->result.size;
	// printf("== %zu '%s'\n", tag->result.size, buffer->str);
	return (0);
}

// int	get_length_after_precision(t_tag *tag)
// {
// 	if (is_str_specifier(tag))
// 		return (min(tag->result.size_virtual, tag->properties.precision));
// 	return (max(tag->result.size_virtual, tag->properties.precision));
// }

// int	get_length_after_prefix(t_tag *tag, size_t length)
// {
// 	return (length + get_prefix_length(tag->result.prefix));
// }

// int	get_length_after_padding(t_tag *tag, size_t length)
// {
// 	return (max(length, tag->properties.padding));
// }

// int	prepare_str(t_tag *tag)
// {
// 	size_t	length;

// 	length = get_length_after_precision(tag);
// 	length = get_length_after_length(tag, length);
// 	length = get_length_after_padding(tag, length);
// 	if (malloc2(length + 1, &tag->result.str))
// 		return (1);
// 	return (0);
// }

// int	strins2(char *src, unsigned int start, size_t length, char **dst)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < length && src[i] && (*dst)[i + start])
// 	{
// 		(*dst)[i + start] = src[i];
// 		i++;
// 	}
// 	return (0);
// }

// int	insert_str(t_tag *tag)
// {
// 	size_t length;

// 	length = tag->result.size_virtual;
// 	if (is_str_specifier(tag))
// 		length = get_length_after_precision(tag);

// }

int	is_padding_between_prefix_and_str(t_tag *tag)
{
	return (tag->properties.precision == -1 && tag->properties.zeroes
		&& !tag->properties.left_justify);
}

int	apply_flags(t_tag *tag)
{
	if (apply_precision(tag))
		return (1);
	if (is_padding_between_prefix_and_str(tag))
	{
		if (apply_padding(LEAVE_SPACE, tag))
			return (2);
		if (apply_prefix(tag))
			return (3);
	}
	else
	{
		if (apply_prefix(tag))
			return (4);
		if (apply_padding(LEAVE_NO_SPACE, tag))
			return (5);
	}
	return (0);
}

int	run(va_list args, t_buffer *buffer)
{
	t_tag	tag;

	while (1)
	{
		// printf("ya-0\n");
		if (advance_cursor(buffer))
			return (0);
		// printf("ya-1 %d\n", parse_tag(buffer, &tag));
		if (parse_tag(buffer, &tag))
			return (1);
		// printf("ya-2\n");
		if (evaluate(args, &tag))
			return (2);
		// printf("ya0\n");
		if (apply_flags(&tag))
			return (3);
		// printf("ya1\n");
		if (substitute(&tag, buffer))
			return (4);
		// printf("ya2\n");
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
	// printf("after %zu\n", buffer.size);
	write(1, buffer.str, buffer.size);

	// printf("%s\n", buffer.str);

	// for (size_t i = 0; i <= buffer.size; i++)
	// {
	// 	printf("%03d ", buffer.str[i]);
	// }

	// printf("\n");

	free(buffer.str);
	return (buffer.size);
}
