/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bufferiser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 15:33:50 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/21 18:50:03 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			flush_buffer(char buffer[MAX_BUF], int *index)
{
	buffer[*index] = 0;
	ft_putstr(buffer);
	*index = 0;
}

void			stock_buffer(int i, int j, va_list ap, int nb)
{
	char		*str;
	static char	buffer[MAX_BUF];
	static int	index;

	if (!nb)
		flush_buffer(buffer, &index);
	else
	{
		while (i < nb)
		{
			j = 0;
			str = va_arg(ap, char*);
			while (str[j])
			{
				if (index >= (MAX_BUF - 1))
					flush_buffer(buffer, &index);
				buffer[index++] = str[j++];
			}
			i++;
		}
	}
}

void			bufferiser(int nb, ...)
{
	va_list		ap;

	va_start(ap, nb);
	stock_buffer(0, 0, ap, nb);
	va_end(ap);
}
