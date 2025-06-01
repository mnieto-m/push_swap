/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:23:13 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/06/01 23:18:11 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin_s1free(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	int		i;
	int		j;
	char	*str;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if ((l1 + l2) == 0)
		return (NULL);
	str = (malloc(sizeof(char) * (l1 + l2 + 1)));
	if (!str)
		return (NULL);
	str[l1 + l2] = '\0';
	i = -1;
	while (++i < (int)l1)
		str[i] = s1[i];
	free(s1);
	j = -1;
	while (++j < (int)l2)
		str[i++] = s2[j];
	return (str);
}

t_list	*ft_lstcopy_new(t_list *lst)
{
	t_list	*new_list;
	void	*content_copy;

	if (!lst)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content_copy = malloc(sizeof(int));
		if (!content_copy)
			return (NULL);
		*(int *)content_copy = *(int *)lst->content;
		ft_lstadd_back(&new_list, ft_lstnew(content_copy));
		lst = lst->next;
	}
	return (new_list);
}
