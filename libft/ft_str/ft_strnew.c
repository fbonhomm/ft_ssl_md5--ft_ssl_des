/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:41:30 by fbonhomm          #+#    #+#             */
/*   Updated: 2017/08/05 23:15:10 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	if (!size || !(str = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	i = 0;
	while (i < size)
		str[i++] = 0;
	return (str);
}
