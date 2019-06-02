/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encrypt_des.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 11:38:38 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/24 11:24:13 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static void		f(t_des_data *data)
{
	int			i;

	i = 0;
	while (i < 16)
	{
		function_extension(data->right, &data->trans);
		or_exclusif(data->new_key[i++], &data->trans);
		apply_sbox(data->trans, &data->sbox);
		second_permutation(data->sbox, &data->trans2);
		or_exclusif_2(data->left, &data->trans2);
		data->left = data->right;
		data->right = data->trans2;
	}
}

void			encrypt_des(t_des *s, uint64_t buf, uint64_t key)
{
	t_des_data	data;

	gen_keys(key, data.new_key);
	initial_permutation(buf, &data.trans);
	slice_data(data.trans, &data.left, &data.right);
	f(&data);
	aggregate_data(data.left, data.right, &buf);
	final_permutation(buf, &s->result);
}
