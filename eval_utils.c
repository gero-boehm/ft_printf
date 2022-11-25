/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:13:42 by gbohm             #+#    #+#             */
/*   Updated: 2022/11/25 10:26:31 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "libft/libft.h"

static int	recurse_base(unsigned long long value, char *base,
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

static int	recurse_setup(unsigned long long value, char *base, char *buffer)
{
	if (value == 0)
	{
		buffer[0] = base[0];
		return (1);
	}
	return (recurse_base(value, base, ft_strlen(base), buffer));
}

int	itoa_base2(unsigned long long value, char *base, char **str)
{
	int		depth;

	if (malloc2(20, str))
		return (1);
	depth = recurse_setup(value, base, *str);
	if (substr2(0, depth, str))
		return (2);
	return (0);
}

void	set_result_str(char *str, t_tag *tag)
{
	size_t	length;

	length = ft_strlen(str);
	tag->result.str = str;
	tag->result.size_virtual = length;
	tag->result.size_actual = length;
}
