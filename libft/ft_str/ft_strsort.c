/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 23:46:36 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 23:46:40 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strsort(char *s1, char *s2)
{
	int		i;
	int		len;

	i = 0;
	if ((ft_strlen(s1)) > (ft_strlen(s2)))
		len = ft_strlen(s2);
	else
		len = ft_strlen(s1);
	while (len-- >= 0)
	{
		if (s1[i] > s2[i])
			return (1);
		if (s1[i] < s2[i])
			return (2);
		i++;
	}
	if ((ft_strlen(s1)) > (ft_strlen(s2)))
		return (1);
	return (2);
}
