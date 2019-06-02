/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:16:04 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/23 22:31:26 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstpush(void *lst, void *elem)
{
	while (lst->next)
		lst = lst->next;
	lst->next = elem;
}
