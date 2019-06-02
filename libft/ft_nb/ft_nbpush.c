/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbpush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:14:03 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/23 22:15:48 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_nblen(int *ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}

int			*ft_nbpush(int *ptr, int elem)
{
	int		*tab;
	size_t	i;

	if (!ptr)
	{
		tab = (int*)malloc(sizeof(int) * 2);
		tab[0] = elem;
		tab[1] = 0;
	}
	else
	{
		tab = (int*)malloc((sizeof(int) * ft_nblen(ptr)) + 2);
		i = 0;
		while (ptr[i])
		{
			tab[i] = ptr[i];
			i++;
		}
		tab[i] = elem;
		tab[i + 1] = 0;
		free(ptr);
	}
	return (tab);
}
