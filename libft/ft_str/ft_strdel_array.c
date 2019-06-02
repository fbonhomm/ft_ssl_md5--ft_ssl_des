/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 18:26:36 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/26 14:15:07 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_strdel_array(char ***str)
{
	int			i;

	i = 0;
	if (str && *str && **str)
	{
		while (((*str)[i]))
		{
			free((*str)[i]);
			(*str)[i++] = NULL;
		}
		free(*str);
		*str = NULL;
	}
}
