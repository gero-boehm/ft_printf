/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:08:12 by gbohm             #+#    #+#             */
/*   Updated: 2023/03/12 19:42:16 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int	advance_cursor(t_buffer *buffer)
{
	char	c;

	c = buffer->str[buffer->cursor];
	while (c && c != '%')
		c = buffer->str[++buffer->cursor];
	return (!c);
}

int	evaluate(va_list args, t_tag *tag)
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
	return (100);
}

int	substitute(t_tag *tag, t_buffer *buffer)
{
	if (strsub(tag, buffer))
		return (1);
	free_tag(tag);
	modify_buffer_size_and_cursor(tag, buffer);
	return (0);
}
