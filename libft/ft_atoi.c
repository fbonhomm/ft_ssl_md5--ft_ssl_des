/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 16:45:37 by fbonhomm          #+#    #+#             */
/*   Updated: 2014/12/01 17:55:26 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(char *str)
{
	int	i;
	int	value;
	int	is_neg;

	i = 0;
	value = 0;
	is_neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == 45)
	{
		is_neg = -1;
		i++;
	}
	else if (str[i] == 43)
		i++;
	while (str[i] <= 57 && str[i] >= 48)
		value = (value * 10) + (str[i++] - 48);
	value = value * is_neg;
	return (value);
}
