/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 09:49:14 by gbohm             #+#    #+#             */
/*   Updated: 2022/11/27 14:52:03 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_char_specifier(t_tag *tag)
{
	char	c;

	c = tag->properties.specifier;
	return (c == 'c');
}

int	is_str_specifier(t_tag *tag)
{
	char	c;

	c = tag->properties.specifier;
	return (c == 's');
}

int	is_ptr_specifier(t_tag *tag)
{
	char	c;

	c = tag->properties.specifier;
	return (c == 'p');
}

int	is_hex_specifier(t_tag *tag)
{
	char	c;

	c = tag->properties.specifier;
	return (c == 'x' || c == 'X');
}

int	is_int_specifier(t_tag *tag)
{
	char	c;

	c = tag->properties.specifier;
	return (c == 'd' || c == 'i');
}

int	is_unsigned_specifier(t_tag *tag)
{
	char	c;

	c = tag->properties.specifier;
	return (c == 'u');
}

int	is_percent_specifier(t_tag *tag)
{
	char	c;

	c = tag->properties.specifier;
	return (c == '%');
}
