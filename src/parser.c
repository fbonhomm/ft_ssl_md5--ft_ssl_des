/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:04:02 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/23 21:38:52 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>
#include <ft_ssl_cmd.h>

static void		handling_option(
	t_parser *ps, t_option *opt, char **tab, size_t *i)
{
	size_t		boolean;

	boolean = FALSE;
	while (opt)
	{
		if (!ft_strcmp(opt->str, tab[*i]))
		{
			if (opt->used)
				break ;
			else
			{
				boolean = TRUE;
				opt->used = TRUE;
				if (opt->after)
				{
					opt->content = (!tab[*i + 1])
						? ft_strdup("")
						: ft_strdup(tab[*i += 1]);
				}
			}
		}
		opt = opt->next;
	}
	if (!boolean)
		error(ps, tab[*i], "No such file or directory");
}

static int		handling_cmd(t_parser *ps, char *cmd)
{
	if (ft_arrfind(g_cmd_digest, cmd) != -1)
		ps->type = ft_strdup("digest");
	else if (ft_arrfind(g_cmd_cipher, cmd) != -1)
		ps->type = ft_strdup("cipher");
	else
	{
		ft_print_str(3, "ft_ssl: Error: ", cmd, " is an invalid command.\n\n");
		usage();
		return (0);
	}
	ps->cmd = ft_strdup(cmd);
	return (1);
}

int				parser(t_parser *ps, char **tab)
{
	size_t		i;

	i = 0;
	while (tab[i])
	{
		if (!ps->cmd)
		{
			if (!handling_cmd(ps, tab[i]))
				return (0);
		}
		else if (!ft_strcmp(ps->type, "digest") && tab[i][0] == '-')
			handling_option(ps, ps->opt_digest, tab, &i);
		else if (!ft_strcmp(ps->type, "cipher") && tab[i][0] == '-')
			handling_option(ps, ps->opt_cipher, tab, &i);
		else
			break ;
		i++;
	}
	set_function(ps);
	return (i);
}
