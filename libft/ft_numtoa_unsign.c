/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numtoa_unsign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 16:47:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/15 17:37:58 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				ft_numtoa_unsign_size(unsigned long long n)
{
	unsigned int		size;

	size = 0;
	while (n > 9)
	{
		n = n / 10;
		size++;
	}
	size++;
	return (size);
}

char					*nbr_zero_numtoa_unsign(void)
{
	char				*str;

	str = ft_strnew(sizeof(char) * 2);
	str[0] = '0';
	return (str);
}

char					*ft_numtoa_unsign(unsigned long long n, int base)
{
	int					i;
	unsigned long long	rem;
	char				*str;

	if (n == 0)
		return (nbr_zero_numtoa_unsign());
	i = ft_numtoa_unsign_size(n);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (n != 0)
	{
		rem = n % base;
		str[i++] = (rem > 9) ? (rem - 10) + 97 : rem + 48;
		n = n / base;
	}
	str[i] = 0;
	ft_strrev(&str);
	return (str);
}
