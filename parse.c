/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:42:32 by gbohm             #+#    #+#             */
/*   Updated: 2022/11/17 13:27:17 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "libft/libft.h"

#include <stdio.h>

int	is_flag(char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0');
}

static char	get_char(t_tag *tag, t_buffer *buffer)
{
	unsigned int	i;

	i = buffer->size_actual + tag->range.start + tag->range.length;
	return (buffer->str[i]);
}

static int	parse_flags(t_tag *tag, t_buffer *buffer)
{
	char	c;

	c = get_char(tag, buffer);
	while (is_flag(c))
	{
		if (c == '-')
			tag->properties.left_justify = 1;
		if (c == '+')
			tag->properties.plus = 1;
		if (c == ' ')
			tag->properties.space = 1;
		if (c == '#')
			tag->properties.prefix = 1;
		if (c == '0')
			tag->properties.zeroes = 1;
		tag->range.length++;
		c = get_char(tag, buffer);
	}
	return (0);
}

static int	parse_padding(t_tag *tag, t_buffer *buffer)
{
	char	c;
	int		padding;

	c = get_char(tag, buffer);
	if (c < '1' || c > '9')
		return (0);
	padding = 0;
	while (ft_isdigit(c))
	{
		padding = padding * 10 + (int) c - '0';
		tag->range.length++;
		c = get_char(tag, buffer);
	}
	tag->properties.padding = padding;
	return (0);
}

static int	parse_precision(t_tag *tag, t_buffer *buffer)
{
	char	c;
	int		precision;

	c = get_char(tag, buffer);
	if (c != '.')
		return (0);
	tag->range.length++;
	c = get_char(tag, buffer);
	precision = 0;
	while (ft_isdigit(c))
	{
		precision = precision * 10 + (int) c - '0';
		tag->range.length++;
		c = get_char(tag, buffer);
	}
	tag->properties.precision = precision;
	return (0);
}

int	is_specifier(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

static int	parse_specifier(t_tag *tag, t_buffer *buffer)
{
	char	c;

	c = get_char(tag, buffer);
	printf("%c\n", c);
	if (!is_specifier(c))
		return (1);
	tag->properties.specifier = c;
	tag->range.length++;
	return (0);
}

int	parse_tag(t_tag *tag, t_buffer *buffer)
{
	init_tag(tag);
	tag->range.start = buffer->size_actual;
	tag->range.length = 1;
	parse_flags(tag, buffer);
	parse_padding(tag, buffer);
	parse_precision(tag, buffer);
	if (parse_specifier(tag, buffer))
		return (1);
	return (0);
}