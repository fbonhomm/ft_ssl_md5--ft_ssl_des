/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:39:01 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/06 14:47:03 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static void		select_algo(t_parser *ps, int mode)
{
	if (!ft_strcmp(ps->type, "cipher"))
	{
		if (!ft_strcmp(ps->cmd, "base64"))
			readfile_base64(ps, mode);
		else if (!ft_strcmp(ps->cmd, "des-ecb"))
			readfile_des(ps, mode, ECB_MODE);
		else if (!ft_strcmp(ps->cmd, "des-cbc") || !ft_strcmp(ps->cmd, "des"))
			readfile_des(ps, mode, CBC_MODE);
		else if (!ft_strcmp(ps->cmd, "des-pcbc"))
			readfile_des(ps, mode, PCBC_MODE);
		else if (!ft_strcmp(ps->cmd, "des3-ecb"))
			readfile_des(ps, mode, ECB3_MODE);
		else if (!ft_strcmp(ps->cmd, "des3-cbc"))
			readfile_des(ps, mode, CBC3_MODE);
		else if (!ft_strcmp(ps->cmd, "des3-pcbc"))
			readfile_des(ps, mode, PCBC3_MODE);
	}
	else if (!ft_strcmp(ps->type, "digest"))
	{
		readstr_digest(ps);
		readfile_digest(ps);
		display_digest(ps);
	}
}

int				main(int ac, char **av)
{
	int			mode;
	int			index;
	char		**cmd;
	t_parser	*ps;

	if (ac <= 1)
		cmd = select_cmd();
	else
		cmd = ft_strdup_array(av + 1);
	ps = (t_parser*)malloc(sizeof(t_parser));
	initialize(ps);
	index = parser(ps, cmd);
	if (index != 0)
	{
		file_descriptor(ps, cmd, index);
		if (verify_argument(ps))
		{
			mode = (search_option(ps->opt_cipher, "-d")) ? 2 : 1;
			select_algo(ps, mode);
		}
	}
	display_error(ps);
	free_ssl(ps);
	ft_strdel_array(&cmd);
	return (0);
}
