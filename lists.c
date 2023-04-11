/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:04:12 by leborges          #+#    #+#             */
/*   Updated: 2023/02/15 15:45:16 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_list(int num)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (!new)
		return (NULL);
	if (new)
	{
		new->data = num;
		new->next = NULL;
	}
	return (new);
}

void	list_add_back(t_stack **list, t_stack *new)
{
	t_stack	*begin;

	if (!*list)
		return ;
	if ((*list) && new)
	{
		begin = (*list);
		if (!begin)
			(*list) = new;
		else
		{
			while (begin->next)
				begin = begin->next;
			begin->next = new;
		}
	}
}

int	list_count(t_stack *list)
{
	int	count;

	count = 0;
	if (list)
	{
		while (list)
		{
			list = list->next;
			count++;
		}
	}
	return (count);
}

void	list_add_front(t_stack **list, t_stack *new)
{
	if (new)
	{
		new->next = *list;
		*list = new;
	}
}

void	list_remove(t_stack **list)
{
	t_stack	*current;
	t_stack	*next;

	if (*list)
	{
		current = (*list);
		while (current)
		{
			next = current->next;
			free (current);
			current = next;
		}
	}
	(*list) = NULL;
}
