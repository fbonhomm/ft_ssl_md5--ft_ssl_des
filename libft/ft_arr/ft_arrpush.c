/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:32:41 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/23 22:34:01 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_arrpush(char **ptr, void *elem)
{
	char	**tab;
	size_t	i;

	if (!ptr)
	{
		tab = ft_strnew_array(2);
		tab[0] = elem;
	}
	else
	{
		i = 0;
		tab = ft_strnew_array(ft_strlen_array(ptr) + 2);
		while (ptr[i])
		{
			tab[i] = ptr[i];
			i++;
		}
		tab[i] = elem;
		free(ptr);
	}
	return (tab);
}
