/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:07:36 by abenkaro          #+#    #+#             */
/*   Updated: 2024/10/30 20:38:48 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_char_ptr;

	last_char_ptr = (char *)s + ft_strlen(s);
	while (last_char_ptr >= (char *)s)
	{
		if (*last_char_ptr == (char)c)
			return (last_char_ptr);
		last_char_ptr--;
	}
	return (NULL);
}
