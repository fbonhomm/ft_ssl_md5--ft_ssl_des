/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 23:01:49 by fbonhomm          #+#    #+#             */
/*   Updated: 2017/08/13 23:01:52 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strnew_array(size_t size)
{
	char	**tab;
	size_t	i;

	if (!size || !(tab = (char**)malloc(sizeof(char*) * (size))))
		return (NULL);
	i = 0;
	while (i < size)
		tab[i++] = NULL;
	return (tab);
}
