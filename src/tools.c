/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:52:01 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/17 16:58:55 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

t_option		*search_option(t_option *o, char *opt)
{
	t_option	*result;

	result = NULL;
	while (o)
	{
		if (!ft_strcmp(o->str, opt) && o->used)
		{
			result = o;
			break ;
		}
		o = o->next;
	}
	return (result);
}

void			add_begin_input(t_parser *ps, t_input *elem)
{
	t_input		*start;

	start = ps->input;
	if (start)
	{
		if (start->stdin)
		{
			while (start->next && start->stdin && start->next->stdin)
				start = start->next;
			elem->next = start->next;
			start->next = elem;
		}
		else
		{
			elem->next = start;
			ps->input = elem;
		}
	}
	else
		ps->input = elem;
}

void			add_end_input(t_parser *ps, t_input *elem)
{
	t_input		*start;

	start = ps->input;
	if (start)
	{
		while (start->next)
			start = start->next;
		start->next = elem;
	}
	else
		ps->input = elem;
}

void			add_end_output(t_parser *ps, t_output *elem)
{
	t_output	*start;

	start = ps->output;
	if (start)
	{
		while (start->next)
			start = start->next;
		start->next = elem;
	}
	else
		ps->output = elem;
}
