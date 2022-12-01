/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:00:52 by gbohm             #+#    #+#             */
/*   Updated: 2022/12/01 11:02:12 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_char_specifier(t_tag *tag)
{
	return (tag->properties.specifier == 'c');
}

int	is_percent_specifier(t_tag *tag)
{
	return (tag->properties.specifier == '%');
}

int	is_str_specifier(t_tag *tag)
{
	return (tag->properties.specifier == 's');
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
