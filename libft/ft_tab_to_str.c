/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 15:35:42 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/05/25 23:02:48 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				count_character_tab(char **tabl)
{
	int			i;
	int			j;
	int			count;

	i = 0;
	count = 0;
	if (!tabl)
		return (0);
	while (tabl[i])
	{
		j = 0;
		while (tabl[i][j])
			j++;
		count += (j + 1);
		i++;
	}
	return (count + 1);
}

char			*ft_tab_to_str(char **tabl, char separator)
{
	int			i;
	int			j;
	int			c;
	char		*str;

	c = 0;
	i = -1;
	str = ft_strnew(sizeof(char) * (count_character_tab(tabl)));
	while (tabl[++i])
	{
		j = 0;
		while (tabl[i][j])
			str[c++] = tabl[i][j++];
		if (separator && tabl[i + 1])
			str[c++] = separator;
	}
	str[c] = 0;
	return (str);
}
