/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_argument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 13:49:04 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/07 14:22:13 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

char			**g_opt_name = (char *[]) {
	"-k", "-v", "-s"
};

static int		verify_argument_digest(t_parser *ps, t_option *opt)
{
	t_option	*o;

	o = search_option(opt, "-s");
	if (o)
	{
		if (ft_strlen(o->content) > 10000)
		{
			error(ps, "-s", "Content so big, Use stdin or -i [file]");
			return (0);
		}
	}
	return (1);
}

static int		verify_argument_cipher(t_parser *ps, t_option *opt)
{
	size_t		i;
	t_option	*o;

	i = 0;
	while (i < 3)
	{
		if ((o = search_option(opt, g_opt_name[i])) != NULL)
		{
			if (!is_hex(o->content))
			{
				error(ps, g_opt_name[i], "non-hex digit");
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int				verify_argument(t_parser *ps)
{
	return ((!verify_argument_digest(ps, ps->opt_digest))
		|| (!verify_argument_cipher(ps, ps->opt_cipher))) ? 0 : 1;
}
