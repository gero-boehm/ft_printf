/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:08:12 by gbohm             #+#    #+#             */
/*   Updated: 2022/11/24 16:48:39 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "libft/libft.h"

int	eval_char(int value, t_tag *tag)
{
	char	*str;

	if (malloc2(2, &str))
		return (1);
	str[0] = (char) value;
	str[1] = 0;
	tag->parts.str = str;
	tag->parts.size_virtual = 1;
	tag->parts.size_actual = ft_isprint(value);
	return (0);
}

int	ft_eval_str(t_tag *tag, char *value)
{
	char	*str;
	size_t	length;

	if (strdup2(value, &str))
		return (1);
	length = ft_strlen(str);
	tag->parts.str = str;
	tag->parts.size_virtual = length;
	tag->parts.size_actual = length;
	return (0);
}