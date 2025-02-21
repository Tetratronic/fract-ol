/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:01:34 by abenkaro          #+#    #+#             */
/*   Updated: 2024/11/05 18:15:31 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;
	size_t	j;

	i = -1;
	j = dstsize;
	dst_len = 0;
	src_len = ft_strlen(src);
	while (j-- && dst[++i] != 0)
		dst_len++;
	j = dstsize - dst_len;
	if (j == 0)
		return (dst_len + src_len);
	return (dst_len + ft_strlcpy(&dst[dst_len], src, j));
}
