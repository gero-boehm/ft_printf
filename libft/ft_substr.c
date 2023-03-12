/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:50:18 by gbohm             #+#    #+#             */
/*   Updated: 2022/10/20 16:05:57 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	length;
	char	*sub;

	if (s == NULL)
		return (NULL);
	length = ft_strlen(s);
	if (len > length)
		len = length;
	if (start > length)
		return (ft_calloc(1, 1));
	sub = malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	sub[len] = 0;
	while (len-- > 0)
		sub[len] = s[start + len];
	return (sub);
}
