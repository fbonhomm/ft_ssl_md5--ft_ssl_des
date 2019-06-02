/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_str_nocasse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 23:46:50 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 23:46:53 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strsort_nocase(char *s1, char *s2)
{
	int		i;
	int		len;

	i = 0;
	if (ft_strlen(s1) > ft_strlen(s2))
		len = ft_strlen(s2);
	else
		len = ft_strlen(s1);
	while (len-- >= 0)
	{
		if (ft_tolower(s1[i]) > ft_tolower(s2[i]))
			return (1);
		if (ft_tolower(s1[i]) < ft_tolower(s2[i]))
			return (2);
		i++;
	}
	if (ft_strlen(s1) > ft_strlen(s2))
		return (1);
	return (2);
}
