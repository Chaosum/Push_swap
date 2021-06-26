/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:51:33 by mservage          #+#    #+#             */
/*   Updated: 2021/06/26 04:53:12 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

void	r_rotate(t_stack **stack, int a_b)
{
	t_stack	*temp;
	t_stack	*start;

	start = *stack;
	while (start->next)
	{
		temp = start;
		start = start->next;
	}
	temp->next = NULL;
	start->next = *stack;
	*stack = start;
	if (a_b == 'a')
		write(1, "rra\n", 4);
	else if (a_b == 'b')
		write(1, "rrb\n", 4);
}

void	r_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	r_rotate(stack_a, 2);
	r_rotate(stack_b, 2);
	write(1, "rrr\n", 4);
}
