/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:44:08 by gbohm             #+#    #+#             */
/*   Updated: 2022/12/01 10:17:24 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static int	get_base(t_tag *tag, char **str)
{
	if (is_hex_upper_specifier(tag))
	{
		if (strdup2("0123456789ABCDEF", str))
			return (1);
	}
	else
	{
		if (strdup2("0123456789abcdef", str))
			return (2);
	}
	return (0);
}

static void	set_prefix(t_prefix prefix, t_tag *tag)
{
	tag->result.prefix = prefix;
}

static int	has_zero_value(unsigned long value)
{
	return (value == 0);
}

static void	determine_prefix(unsigned long value, t_tag *tag)
{
	if (is_ptr_specifier(tag))
		set_prefix(PREFIX_0X_LOWER, tag);
	else if (!has_prefix_flag(tag))
		return ;
	else if (has_zero_value(value))
		return ;
	else if (is_hex_lower_specifier(tag))
		set_prefix(PREFIX_0X_LOWER, tag);
	else
		set_prefix(PREFIX_0X_UPPER, tag);
}

int	eval_hex(unsigned long value, t_tag *tag)
{
	char	*str;
	char	*base;

	if (get_base(tag, &base))
		return (1);
	if (has_zero_value(value) && tag->properties.precision == 0)
	{
		if (strdup2("", &str))
			return (free(base), 2);
	}
	else
	{
		if (itoa_base2(value, base, &str))
			return (free(base), 3);
	}
	determine_prefix(value, tag);
	set_result_str(str, tag);
	free(base);
	return (0);
}
