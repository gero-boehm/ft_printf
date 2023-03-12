/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:18:10 by gbohm             #+#    #+#             */
/*   Updated: 2022/10/19 16:27:11 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	n;
	char	*dup;

	n = ft_strlen(s1) + 1;
	dup = malloc(n);
	if (dup == NULL)
		return (NULL);
	return ((char *) ft_memcpy((void *) dup, (const void *) s1, n));
}
