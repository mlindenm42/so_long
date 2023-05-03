/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:53:53 by mlindenm          #+#    #+#             */
/*   Updated: 2022/05/19 20:51:01 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	ptr = NULL;
	while (*lst != NULL)
	{
		ptr = (*lst)->next;
		if (*lst != NULL && del != NULL)
		{
			(del)((*lst)->content);
			free(*lst);
		}
		*lst = ptr;
	}
	*lst = NULL;
}
