/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:31:37 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/23 22:32:37 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_arrfind(const char **arr, const char *find)
{
	int		idx;
	int		found;

	idx = 0;
	found = -1;
	while (arr[idx])
	{
		if (!ft_strcmp(arr[idx], find))
		{
			found = idx;
			break ;
		}
		idx++;
	}
	return (found);
}
