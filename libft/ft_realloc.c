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

void				*ft_realloc(void *str, size_t size)
{
	char			*ret;

	if (!str || !size || !(ret = ft_strnew(size + 1)))
		return (NULL);
	ft_strncpy(ret, str, size);
	free(str);
	return (ret);
}
