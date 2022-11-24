/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:53:53 by gbohm             #+#    #+#             */
/*   Updated: 2022/11/24 15:38:12 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	init_buffer(t_buffer *buffer, const char *format)
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
