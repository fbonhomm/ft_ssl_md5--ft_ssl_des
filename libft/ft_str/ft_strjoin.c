/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:35:00 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/23 22:13:25 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;
	int		i;

	if ((!s1) || (!s2))
		return (NULL);
	i = -1;
	str = ft_strnew(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	while (s1 && s1[++i])
		str[i] = s1[i];
	len = i;
	i = -1;
	while (s2 && s2[++i])
		str[len + i] = s2[i];
	str[len + i] = 0;
	return (str);
}
