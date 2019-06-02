/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 17:06:28 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/09/29 17:20:28 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_realloc_array(char **tab, size_t size)
{
	size_t			i;
	char			**ret;

	i = 0;
	if (!tab || !size)
		return (NULL);
	if ((ret = (char**)ft_strnew_array(sizeof(char*) * (size + 1))))
	{
		while (tab[i])
		{
			ret[i] = tab[i];
			i++;
		}
	}
	ret[i] = NULL;
	free(tab);
	return (ret);
}
