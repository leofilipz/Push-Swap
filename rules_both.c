/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_both.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:11:59 by leborges          #+#    #+#             */
/*   Updated: 2023/02/15 15:12:01 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	swap(a, NULL);
	swap(b, NULL);
	ft_printf("ss\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, NULL);
	rotate(b, NULL);
	ft_printf("rr\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a, NULL);
	rev_rotate(b, NULL);
	ft_printf("rrr\n");
}
