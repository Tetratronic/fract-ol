/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:27:33 by abenkaro          #+#    #+#             */
/*   Updated: 2024/10/28 18:54:24 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int		result;
	long	num;

	num = (long)n;
	if (num == 0)
		return (1);
	result = 0;
	if (num < 0)
	{
		num *= -1;
		result++;
	}
	while (num > 0)
	{
		result++;
		num /= 10;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		numlen;
	long	num;

	numlen = num_len(n);
	num = (long)n;
	result = (char *)malloc(numlen + 1);
	if (!result)
		return (NULL);
	if (num < 0)
	{
		*result = '-';
		num *= -1;
	}
	*(result + numlen) = '\0';
	while ((num / 10) > 0)
	{
		*(result + --numlen) = (num % 10) + 48;
		num /= 10;
	}
	*(result + --numlen) = (num % 10) + 48;
	return (result);
}
