/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:52:13 by gbohm             #+#    #+#             */
/*   Updated: 2022/11/24 16:24:08 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "include/ft_printf.h"
#include "libft/libft.h"

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

	tag->parts.str = NULL;
	tag->parts.prefix = PREFIX_EMPTY;
	tag->parts.size_virtual = 0;
	tag->parts.size_actual = 0;

	tag->construct.str = NULL;
	tag->construct.size_virtual = 0;
	tag->construct.size_actual = 0;
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	can_use_precision(char c)
{
	return (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X');
}

int	prepare_str(t_tag *tag)
{
	size_t	length;

	length = ft_strlen(tag->parts.str);
	if (tag->properties.specifier == 's' && tag->properties.precision != -1
		&& tag->properties.precision < length)
		length = tag->properties.precision;
	if (can_use_precision(tag->properties.precision))
		length = max(length, tag->properties.precision);
	length += ft_strlen(tag->parts.prefix);
	length = max(length, tag->properties.padding);
	if (malloc2(length + 1, &tag->construct.str))
		return (1);
	tag->construct.str[length] = 0;
	// tag->construct.length = length;
	return (0);
}

int	padstr2(int padding, int right, int zeroes, char **str)
{
	size_t	i;
	size_t	length;
	int		offset;
	char	*new;
	char	c;

	length = ft_strlen(*str);
	offset = padding - length;
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
		if (i >= offset && i < offset + length)
			new[i] = (*str)[i - offset];
		else
			new[i] = c;
		i++;
	}
	strass2(new, str);
	return (0);
}

int apply_precision(t_tag *tag)
{
	if (strdup2(tag->parts.str, &tag->construct.str))
		return (1);
	if (tag->properties.precision == -1)
		return (0);
	if (tag->properties.specifier == 's')
	{
		if (substr2(0, tag->properties.precision, &tag->construct.str))
			return (2);
		return (0);
	}
	if (padstr2(tag->properties.precision, 0, 1, &tag->construct.str))
		return (2);
	return (0);
}

// int	run(t_buffer *buffer, va_list args)
// {
// 	t_tag	tag;

// 	while (1)
// 	{
// 		if (advance_cursor(buffer))
// 			return (0);
// 		if (parse_tag(&tag, buffer))
// 			return (1);
// 		if (evaluate(&tag, args))
// 			return (2);
// 		if (prepare_str(&tag))
// 			return (3);
// 		if (apply_precision(&tag))
// 			return (4);
// 		if (apply_prefix(&tag))
// 			return (5);
// 		if (apply_padding(&tag))
// 			return (6);
// 		if (substitute(&tag, buffer))
// 			return (7);
// 	}
// 	return (0);
// }

// int	ft_printf(const char *format, ...)
// {
// 	va_list		args;
// 	t_buffer	buffer;

// 	va_start(args, format);
// 	if (init_buffer(&buffer, format))
// 		return (-1);
// 	if (run(&buffer, args))
// 		return (-1);
// 	write(1, buffer.str, buffer.size_actual);
// 	free(buffer.str);
// 	return (buffer.size_virtual);
// }
