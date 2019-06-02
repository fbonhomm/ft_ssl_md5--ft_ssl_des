/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 16:47:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/15 17:37:55 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_size(int n)
{
	int		size;

	size = 0;
	if (n == -2147483648)
		return (11);
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

char		*nbr_zero(void)
{
	char	*str;

	str = ft_strnew(sizeof(char) * 2);
	str[0] = '0';
	return (str);
}

char		*ft_itoa(int n, int base)
{
	int		i;
	int		rem;
	int		is_neg;
	char	*str;

	if (n == 0)
		return (nbr_zero());
	i = ft_itoa_size(n);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
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
