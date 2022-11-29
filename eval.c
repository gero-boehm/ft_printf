/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:08:12 by gbohm             #+#    #+#             */
/*   Updated: 2022/11/29 13:12:38 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	eval_char(int value, t_tag *tag)
{
	char	*str;

	if (malloc2(2, &str))
		return (1);
	str[0] = (char) value;
	str[1] = 0;
	tag->result.str = str;
	tag->result.size = 1;
	return (0);
}

int	eval_str(char *value, t_tag *tag)
{
	char	*str;

	if (value == NULL)
	{
		if (strdup2("(null)", &str))
			return (1);
	}
	else
	{
		if (strdup2(value, &str))
			return (2);
	}
	set_result_str(str, tag);
	return (0);
}

int	eval_hex(unsigned long value, t_tag *tag)
{
	char	*str;
	char	*base;

	base = "0123456789abcdef";
	if (tag->properties.specifier == 'X')
		base = "0123456789ABCDEF";
	if (value == 0 && tag->properties.precision == 0)
	{
		if (strdup2("", &str))
			return (1);
	}
	else
	{
		if (itoa_base2(value, base, &str))
			return (2);
	}
	if (tag->properties.specifier == 'p')
		tag->result.prefix = PREFIX_0X_LOWER;
	else if (tag->properties.prefix)
	{
		if (value)
		{
			tag->result.prefix = PREFIX_0X_LOWER;
			if (tag->properties.specifier == 'X')
				tag->result.prefix = PREFIX_0X_UPPER;
		}
	}
	set_result_str(str, tag);
	return (0);
}

int	eval_int(int value, t_tag *tag)
{
	unsigned int	uval;

	uval = value;
	if (value < 0)
	{
		uval = ~uval + 1;
		tag->result.prefix = PREFIX_MINUS;
	}
	else if (tag->properties.plus)
		tag->result.prefix = PREFIX_PLUS;
	else if (tag->properties.space)
		tag->result.prefix = PREFIX_SPACE;
	return (eval_unsigned(uval, tag));
}

int	eval_unsigned(unsigned int value, t_tag *tag)
{
	char	*str;

	if (value == 0 && tag->properties.precision == 0)
	{
		if (strdup2("", &str))
			return (1);
	}
	else
	{
		if (itoa_base2(value, "0123456789", &str))
			return (2);
	}
	set_result_str(str, tag);
	return (0);
}
