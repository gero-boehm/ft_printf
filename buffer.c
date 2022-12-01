/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:53:53 by gbohm             #+#    #+#             */
/*   Updated: 2022/11/30 13:58:58 by gbohm            ###   ########.fr       */
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

void	modify_buffer_size_and_cursor(t_tag *tag, t_buffer *buffer)
{
	buffer->size += tag->result.size - tag->range.length;
	buffer->cursor += tag->result.size;
}

void	free_buffer(t_buffer *buffer)
{
	free(buffer->str);
}
