/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:52:13 by gbohm             #+#    #+#             */
/*   Updated: 2022/11/30 14:11:52 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

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

int	ignores_precision(char c)
{
	return (c == 'c' || c == '%');
}

int	padstr2(int padding, int right, int zeroes, t_result *result)
{
	int		i;
	size_t	length;
	int		offset;
	char	*new;
	char	c;

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
		difference = tag->result.size - tag->properties.precision;
		if (difference > 0)
			tag->result.size -= difference;
		if (substr2(0, tag->properties.precision, &tag->result.str))
			return (2);
		return (0);
	}
	if (is_char_specifier(tag) || is_percent_specifier(tag))
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
	free_tag(tag);
	modify_buffer_size_and_cursor(tag, buffer);
	return (0);
}

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
		if (advance_cursor(buffer))
			return (0);
		if (parse_tag(buffer, &tag))
			return (1);
		if (evaluate(args, &tag))
			return (2);
		if (apply_flags(&tag))
			return (free_tag(&tag), 3);
		if (substitute(&tag, buffer))
			return (free_tag(&tag), 4);
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
		return (free_buffer(&buffer), -1);
	va_end(args);
	write(1, buffer.str, buffer.size);
	free_buffer(&buffer);
	return (buffer.size);
}
