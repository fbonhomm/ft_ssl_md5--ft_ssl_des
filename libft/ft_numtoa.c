/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 16:47:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/15 17:37:56 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_numtoa_size(long long n)
{
	int		size;

	size = 0;
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n > 9)
	{
		n = n / 10;
		size++;
	}
	size++;
	return (size);
}

char			*limit_len(long long n)
{
	char		*str;

	str = NULL;
	if (n <= LLONG_MIN)
		str = ft_strdup("-9223372036854775808");
	if (n >= LLONG_MAX)
		str = ft_strdup("9223372036854775807");
	return (str);
}

char			*nbr_zero_numtoa(void)
{
	char		*str;

	str = ft_strnew(sizeof(char) * 2);
	str[0] = '0';
	return (str);
}

char			*ft_numtoa(long long n, int base)
{
	int			i;
	int			is_neg;
	long long	rem;
	char		*str;

	if (n == 0)
		return (nbr_zero_numtoa());
	if ((str = limit_len(n)) != NULL)
		return (str);
	str = (char*)malloc(sizeof(char) * (ft_numtoa_size(n) + 1));
	i = 0;
	is_neg = 0;
	if (n < 0 && base == 10 && (is_neg = 1))
		n = -n;
	while (n != 0)
	{
		rem = n % base;
		str[i++] = (rem > 9) ? (rem - 10) + 97 : rem + 48;
		n = n / base;
	}
	if (is_neg)
		str[i++] = 45;
	str[i] = 0;
	ft_strrev(&str);
	return (str);
}
