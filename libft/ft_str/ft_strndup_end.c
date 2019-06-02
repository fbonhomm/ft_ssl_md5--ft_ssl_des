/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:33:52 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/09/29 16:01:34 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup_end(const char *s1, size_t size)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (ft_strlen(s1) <= size || !s1[size])
		return (NULL);
	s2 = ft_strnew(sizeof(char) * ((ft_strlen(s1) - size) + 1));
	if (s2 == NULL)
		return (NULL);
	while (s1[size])
		s2[i++] = s1[size++];
	s2[i] = '\0';
	return (s2);
}
