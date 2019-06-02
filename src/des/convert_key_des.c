/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_key_des.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 11:50:02 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/23 17:15:10 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

const uint8_t g_convert[16] = {
	0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7,
	0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF
};

void				convert_des(char *str, uint64_t *key)
{
	char			c;
	size_t			i;
	size_t			len;

	i = 0;
	*key = 0;
	len = ft_strlen(str);
	while (i < 16)
	{
		if (i >= len)
			c = 0;
		else if (ft_toupper(str[i]) >= 48 && ft_toupper(str[i]) <= 57)
			c = g_convert[(ft_toupper(str[i]) - 48)];
		else if (ft_toupper(str[i]) >= 65 && ft_toupper(str[i]) <= 70)
			c = g_convert[(ft_toupper(str[i]) - 55)];
		*key = (*key << 4) | c;
		i++;
	}
}

static void			convert_des3(char *str, uint64_t *subkey)
{
	char			c;
	size_t			i;
	size_t			j;
	size_t			len;

	j = 0;
	len = ft_strlen(str);
	while (j < 3)
	{
		i = (16 * j);
		subkey[j] = 0;
		while (i < (16 * (j + 1)))
		{
			if (i >= len)
				c = 0;
			else if (ft_toupper(str[i]) >= 48 && ft_toupper(str[i]) <= 57)
				c = g_convert[(ft_toupper(str[i]) - 48)];
			else if (ft_toupper(str[i]) >= 65 && ft_toupper(str[i]) <= 70)
				c = g_convert[(ft_toupper(str[i]) - 55)];
			subkey[j] = (subkey[j] << 4) | c;
			i++;
		}
		j++;
	}
}

void				convert_key_des(t_des *s, char *str, int des_mode)
{
	if ((des_mode == ECB_MODE) || (des_mode == CBC_MODE)
			|| (des_mode == PCBC_MODE))
		convert_des(str, &s->key);
	if ((des_mode == ECB3_MODE) || (des_mode == CBC3_MODE)
			|| (des_mode == PCBC3_MODE))
		convert_des3(str, s->subkey);
}
