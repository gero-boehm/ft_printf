/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:53:53 by gbohm             #+#    #+#             */
/*   Updated: 2022/12/01 13:06:36 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

int	init_buffer(const char *format, t_buffer *buffer)
{
	if (strdup2(format, &buffer->str))
		return (1);
	buffer->size = ft_strlen(buffer->str);
	buffer->cursor = 0;
	return (0);
}

char	get_char(t_tag *tag, t_buffer *buffer)
{
	unsigned long	i;

	i = tag->range.start + tag->range.length;
	return (buffer->str[i]);
}

void	modify_buffer_size_and_cursor(t_tag *tag, t_buffer *buffer)
{
	buffer->size += tag->result.size - tag->range.length;
	buffer->cursor += tag->result.size;
}

void	free_buffer(t_buffer *buffer)
{
	free(buffer->str);
}
