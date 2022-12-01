/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:34:58 by gbohm             #+#    #+#             */
/*   Updated: 2022/12/01 13:35:11 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	has_padding(t_tag *tag)
{
	return (tag->properties.padding > 0);
}

int	has_precision(t_tag *tag)
{
	return (tag->properties.precision >= 0);
}
