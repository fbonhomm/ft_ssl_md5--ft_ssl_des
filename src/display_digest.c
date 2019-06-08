/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_digest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:35:10 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/24 13:10:53 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

#define _P 0
#define _Q 1
#define _R 2

static void			display_cmd(char *cmd)
{
	size_t			i;
	unsigned char	c;

	i = 0;
	while (cmd[i])
	{
		c = ft_toupper(cmd[i++]);
		write(1, &c, 1);
	}
}

static void			set_option(t_parser *ps, uint32_t *opt)
{
	t_option		*o;

	opt[_P] = 0;
	opt[_Q] = 0;
	opt[_R] = 0;
	o = ps->opt_digest;
	while (o)
	{
		if (!ft_strcmp(o->str, "-p") && o->used)
			opt[_P] = 1;
		else if (!ft_strcmp(o->str, "-q") && o->used)
			opt[_Q] = 1;
		else if (!ft_strcmp(o->str, "-r") && o->used)
			opt[_R] = 1;
		o = o->next;
	}
}

static void			display_str(t_parser *ps, uint32_t *opt)
{
	t_option		*o;

	if (ps->str)
	{
		o = search_option(ps->opt_digest, "-s");
		if (opt[_Q])
			ft_print_str(2, ps->str, "\n");
		else if (opt[_R])
			ft_print_str(4, ps->str, "  \"", o->content, "\"\n");
		else
		{
			display_cmd(ps->cmd);
			ft_print_str(5, "(\"", o->content, "\")= ", ps->str, "\n");
		}
	}
}

void				display_digest(t_parser *ps)
{
	t_input			*f;
	uint32_t		opt[3];

	f = ps->input;
	set_option(ps, opt);
	while (f)
	{
		if (f->fd != -1)
		{
			if (opt[_Q] || f->stdin)
				ft_print_str(3, "(stdin)= ", f->output, "\n");
			else if (opt[_R])
				ft_print_str(4, f->output, "  ", f->name, "\n");
			else
			{
				display_cmd(ps->cmd);
				ft_print_str(5, "(", f->name, ")= ", f->output, "\n");
			}
		}
		else
			display_str(ps, opt);
		f = f->next;
	}
}
