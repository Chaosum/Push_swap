/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:16:53 by mservage          #+#    #+#             */
/*   Updated: 2021/06/28 16:03:40 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

void	swap(t_stack **stack, int a_b)
{
	t_stack	*temp;

	temp = (*stack)->next;
	if (temp)
	{
		(*stack)->next = temp->next;
		ft_lst_stack_add_front(stack, temp);
	}
	if (a_b == 'a')
		write(1, "sa\n", 3);
	else if (a_b == 'b')
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a, 2);
	swap(stack_b, 2);
	write(1, "ss\n", 3);
}
