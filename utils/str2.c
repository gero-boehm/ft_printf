/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:38:43 by gbohm             #+#    #+#             */
/*   Updated: 2022/12/01 13:15:26 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	strass2(char *src, char **dst)
{
	free(*dst);
	*dst = src;
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

void	strfll(char c, size_t length, char *dst, unsigned long start)
{
	unsigned long	i;

	i = 0;
	while (i < length)
	{
		dst[start + i] = c;
		i++;
	}
}
