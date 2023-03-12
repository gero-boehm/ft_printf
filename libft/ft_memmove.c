/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:26:32 by gbohm             #+#    #+#             */
/*   Updated: 2022/10/18 13:03:41 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	size_t	offset;
	size_t	direction;
	size_t	index;

	if (len == 0)
		return (dst);
	if (src == dst)
		return (dst);
	if (src < dst)
		direction = -1;
	else
		direction = 1;
	if (direction == (size_t) -1)
		offset = len - 1;
	else
		offset = 0;
	i = 0;
	while (i < len)
	{
		index = offset + i * direction;
		((char *) dst)[index] = ((char *) src)[index];
		i++;
	}
	return (dst);
}
