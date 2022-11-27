/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:53:53 by gbohm             #+#    #+#             */
/*   Updated: 2022/11/27 13:52:14 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	init_buffer(const char *format, t_buffer *buffer)
{
	if (strdup2(format, &buffer->str))
		return (1);
	buffer->size_virtual = 0;
	buffer->size_actual = 0;
	return (0);
}

void	increment_buffer_size(t_buffer *buffer)
{
	buffer->size_actual++;
	buffer->size_virtual++;
}
