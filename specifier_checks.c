/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 09:49:14 by gbohm             #+#    #+#             */
/*   Updated: 2022/11/30 11:51:30 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_char_specifier(t_tag *tag)
{
	return (tag->properties.specifier == 'c');
}

int	is_str_specifier(t_tag *tag)
{
	return (tag->properties.specifier == 's');
}

int	is_ptr_specifier(t_tag *tag)
{
	return (tag->properties.specifier == 'p');
}

int	is_hex_lower_specifier(t_tag *tag)
{
	return (tag->properties.specifier == 'x');
}

int	is_hex_upper_specifier(t_tag *tag)
{
	return (tag->properties.specifier == 'X');
}

int	is_hex_specifier(t_tag *tag)
{
	return (is_hex_lower_specifier(tag) || is_hex_upper_specifier(tag));
}

int	is_int_specifier(t_tag *tag)
{
	return (tag->properties.specifier == 'd'
		|| tag->properties.specifier == 'i');
}

int	is_unsigned_specifier(t_tag *tag)
{
	return (tag->properties.specifier == 'u');
}

int	is_percent_specifier(t_tag *tag)
{
	return (tag->properties.specifier == '%');
}
