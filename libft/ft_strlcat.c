/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osericol <osericol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:51:54 by osericol          #+#    #+#             */
/*   Updated: 2023/04/11 14:45:39 by osericol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*dst_ptr;
	const char	*src_ptr;
	size_t		dst_len;
	size_t		len;

	dst_ptr = dst;
	src_ptr = src;
	len = dstsize;
	while (len-- && *dst_ptr)
		dst_ptr++;
	dst_len = dst_ptr - dst;
	len = dstsize - dst_len;
	if (len == 0)
		return (dst_len + ft_strlen(src_ptr));
	while (*src_ptr)
	{
		if (len != 1)
		{
			*dst_ptr++ = *src_ptr;
			len--;
		}
		src_ptr++;
	}
	*dst_ptr = '\0';
	return (dst_len + (src_ptr - src));
}
