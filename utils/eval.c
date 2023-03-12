/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:13:42 by gbohm             #+#    #+#             */
/*   Updated: 2023/03/12 21:39:50 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	recurse_base(unsigned long value, char *base,
	size_t base_size, char *buffer)
{
	int	depth;

	if (value)
	{
		depth = recurse_base(value / base_size, base, base_size, buffer);
		buffer[depth] = base[value % base_size];
		return (depth + 1);
	}
	return (0);
}

static int	recurse_setup(unsigned long value, char *base, char *buffer)
{
	if (value == 0)
	{
		buffer[0] = base[0];
		return (1);
	}
	return (recurse_base(value, base, ft_strlen(base), buffer));
}

int	itoa_base2(unsigned long value, char *base, char **str)
{
	int		depth;

	if (malloc2(21, str))
		return (1);
	depth = recurse_setup(value, base, *str);
	(*str)[depth] = 0;
	if (substr2(0, depth, str))
		return (2);
	return (0);
}

void	set_result_str(char *str, t_tag *tag)
{
	tag->result.str = str;
	tag->result.size = ft_strlen(str);
}
