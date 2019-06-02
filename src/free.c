/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:17:16 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/26 19:44:31 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static void		free_input(t_input *in)
{
	t_input		*tmp;
	t_input		*tmp1;

	if (in)
	{
		tmp = in;
		tmp1 = in->next;
		while (tmp)
		{
			if (tmp->fd != -1)
				close(tmp->fd);
			free(tmp->name);
			free(tmp);
			tmp = tmp1;
			tmp1 = (tmp1) ? tmp1->next : NULL;
		}
	}
}

static void		free_output(t_output *out)
{
	t_output	*tmp;
	t_output	*tmp1;

	if (out)
	{
		tmp = out;
		tmp1 = out->next;
		while (tmp)
		{
			if (tmp->fd != -1)
				close(tmp->fd);
			free(tmp->name);
			free(tmp);
			tmp = tmp1;
			tmp1 = (tmp1) ? tmp1->next : NULL;
		}
	}
}

static void		free_option(t_option *opt)
{
	t_option	*tmp;
	t_option	*tmp1;

	if (opt)
	{
		tmp = opt;
		tmp1 = opt->next;
		while (tmp)
		{
			free(tmp->str);
			free(tmp->content);
			free(tmp);
			tmp = tmp1;
			tmp1 = (tmp1) ? tmp1->next : NULL;
		}
	}
}

void			free_ssl(t_parser *ps)
{
	ft_strdel(&ps->cmd);
	ft_strdel(&ps->type);
	ft_strdel_array(&ps->errors);
	free_input(ps->input);
	free_output(ps->output);
	free_option(ps->opt_digest);
	free_option(ps->opt_cipher);
	if (ps->pf && ps->pf->ctx)
		free(ps->pf->ctx);
	free(ps->pf);
	free(ps->str);
	free(ps);
}
