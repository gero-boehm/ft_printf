/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:53:53 by gbohm             #+#    #+#             */
/*   Updated: 2022/11/29 10:38:49 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	increment_buffer_size(t_buffer *buffer)
{
	buffer->size++;
}
