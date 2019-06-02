/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 16:49:31 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/23 22:17:00 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	size_t	*str;
	size_t	i;

	if (!(str = malloc(sizeof(size_t) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
		str[i++] = 0;
	return ((void *)str);
}
