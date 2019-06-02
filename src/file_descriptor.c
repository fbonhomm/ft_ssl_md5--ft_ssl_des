/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_descriptor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:17:52 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/06 13:33:57 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static void		handling_file_descriptor_input_str(t_parser *ps, char *str)
{
	t_input		*elem;

	elem = (t_input*)malloc(sizeof(t_input));
	elem->next = NULL;
	elem->fd = -1;
	elem->name = ft_strdup(str);
	add_end_input(ps, elem);
}

static void		handling_file_descriptor_input(t_parser *ps, char *file)
{
	int			fd;
	t_input		*elem;

	elem = (t_input*)malloc(sizeof(t_input));
	elem->next = NULL;
	elem->fd = -1;
	elem->stdin = FALSE;
	if (!file)
	{
		elem->fd = STDIN_FILENO;
		elem->stdin = TRUE;
		elem->name = ft_strdup("stdin");
		add_begin_input(ps, elem);
	}
	else if (check_file(file) && (fd = open(file, O_RDONLY)) != -1)
	{
		elem->name = ft_strdup(file);
		elem->fd = fd;
		add_end_input(ps, elem);
	}
	else
	{
		free(elem);
		error(ps, file, strerror(errno));
	}
}

static void		handling_file_descriptor_output(t_parser *ps, char *file)
{
	int			fd;
	t_output	*elem;

	elem = (t_output*)malloc(sizeof(t_output));
	elem->next = NULL;
	elem->stdout = FALSE;
	elem->output_cipher = NULL;
	if (!file)
	{
		elem->fd = STDOUT_FILENO;
		elem->stdout = TRUE;
		elem->name = ft_strdup("stdout");
		add_end_output(ps, elem);
	}
	else if ((fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0755)) != -1)
	{
		elem->fd = fd;
		elem->name = ft_strdup(file);
		add_end_output(ps, elem);
	}
	else
	{
		free(elem);
		error(ps, file, strerror(errno));
	}
}

void			browse_opt(t_parser *ps)
{
	t_option	*o;

	o = (!ft_strcmp(ps->type, "digest")) ? ps->opt_digest : ps->opt_cipher;
	while (o)
	{
		if (!ft_strcmp(o->str, "-s") && o->used)
			handling_file_descriptor_input_str(ps, o->content);
		if (!ft_strcmp(o->str, "-i") && o->used)
			handling_file_descriptor_input(ps, o->content);
		else if (!ft_strcmp(o->str, "-o") && o->used)
			handling_file_descriptor_output(ps, o->content);
		o = o->next;
	}
}

void			file_descriptor(t_parser *ps, char **cli, int i)
{
	browse_opt(ps);
	while (cli[i] && !ft_strcmp(ps->type, "digest"))
		handling_file_descriptor_input(ps, cli[i++]);
	if (!ps->input
	|| (!ft_strcmp(ps->type, "digest") && search_option(ps->opt_digest, "-p"))
	|| (!ft_strcmp(ps->type, "cipher") && !search_option(ps->opt_cipher, "-i")))
		handling_file_descriptor_input(ps, NULL);
	if (!ps->output || !search_option(ps->opt_cipher, "-o"))
		handling_file_descriptor_output(ps, NULL);
}
