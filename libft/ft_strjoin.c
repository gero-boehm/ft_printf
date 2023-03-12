/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:16:02 by gbohm             #+#    #+#             */
/*   Updated: 2022/10/19 16:27:26 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	length_s1;
	size_t	length_s2;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	length_s1 = ft_strlen(s1);
	length_s2 = ft_strlen(s2);
	str = malloc(length_s1 + length_s2 + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, length_s1 + 1);
	ft_strlcpy(str + length_s1, s2, length_s2 + 1);
	str[length_s1 + length_s2] = 0;
	return (str);
}
