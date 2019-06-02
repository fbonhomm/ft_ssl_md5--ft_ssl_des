/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:12:08 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/23 22:13:56 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strpush(char *ptr, char *elem)
{
	char	*tab;

	if (!ptr)
		tab = ft_strdup(elem);
	else
	{
		tab = ft_strjoin(ptr, elem);
		free(ptr);
	}
	return (tab);
}
