/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:35:22 by gbohm             #+#    #+#             */
/*   Updated: 2022/12/01 13:20:39 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	strdup2(const char *src, char **dst)
{
	*dst = ft_strdup(src);
	return (*dst == NULL);
}

int	substr2(unsigned int start, size_t length, char **str)
{
	char	*sub;

	sub = ft_substr(*str, start, length);
	strass2(sub, str);
	return (*str == NULL);
}

int	strapp2(char *src, char **dst)
{
	char	*new;

	new = ft_strjoin(src, *dst);
	strass2(new, dst);
	return (*dst == NULL);
}

int	padstr2(int padding, int right, int zeroes, t_result *result)
{
	int		offset;
	char	*new;
	char	c;

	offset = padding - result->size;
	if (offset <= 0)
		return (0);
	if (right)
		offset = 0;
	if (malloc2(padding + 1, &new))
		return (1);
	new[padding] = 0;
	c = ' ';
	if (zeroes)
		c = '0';
	strfll(c, padding, new, 0);
	strins(result->str, result->size, new, offset);
	strass2(new, &result->str);
	result->size = padding;
	return (0);
}

int	strsub(t_tag *tag, t_buffer *buffer)
{
	unsigned long	total_length;
	unsigned long	range_end;
	char			*str;

	if (tag->range.start > buffer->size)
		return (1);
	total_length = buffer->size - tag->range.length + tag->result.size;
	if (malloc2(total_length + 1, &str))
		return (2);
	str[total_length] = 0;
	range_end = tag->range.start + tag->range.length;
	strins(buffer->str, tag->range.start, str, 0);
	strins(tag->result.str, tag->result.size, str, tag->range.start);
	strins(buffer->str + range_end, buffer->size - range_end,
		str, tag->range.start + tag->result.size);
	strass2(str, &buffer->str);
	return (0);
}
