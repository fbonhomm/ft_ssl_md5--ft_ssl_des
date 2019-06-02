/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:07:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/23 20:28:34 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

int g_opt_digest_after[5] = {0, 0, 0, 1, 1};
char **g_opt_digest = (char *[]){"-p", "-q", "-r", "-s", NULL};
int	g_opt_cipher_after[9] = {0, 0, 1, 1, 0, 1, 1, 1, 1};
char **g_opt_cipher = (char *[]){
	"-e", "-d", "-i", "-o", "-a", "-k", "-p", "-s", "-v", NULL};

static void			set_up_null(t_parser *ps)
{
	ps->cmd = NULL;
	ps->read_size = 0;
	ps->type = NULL;
	ps->errors = NULL;
	ps->input = NULL;
	ps->output = NULL;
	ps->opt_digest = NULL;
	ps->opt_cipher = NULL;
	ps->pf = NULL;
	ps->str = NULL;
}

static t_option		*set_option(char **cmd, int *after, t_option *opt)
{
	size_t			i;
	t_option		*tmp[2];

	i = 0;
	while (cmd[i])
	{
		tmp[0] = (t_option*)malloc(sizeof(t_option));
		tmp[0]->str = ft_strdup(cmd[i]);
		tmp[0]->used = 0;
		tmp[0]->next = NULL;
		tmp[0]->content = NULL;
		tmp[0]->after = after[i];
		if (!opt)
		{
			opt = tmp[0];
			tmp[1] = opt;
		}
		else
		{
			tmp[1]->next = tmp[0];
			tmp[1] = tmp[1]->next;
		}
		i++;
	}
	return (opt);
}

void				initialize(t_parser *ps)
{
	set_up_null(ps);
	ps->opt_digest = set_option(g_opt_digest, g_opt_digest_after, NULL);
	ps->opt_cipher = set_option(g_opt_cipher, g_opt_cipher_after, NULL);
}
