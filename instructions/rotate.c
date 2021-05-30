/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:25:59 by mservage          #+#    #+#             */
/*   Updated: 2021/05/27 18:50:58 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

void rotate(t_stack *stack, int a_b)
{
	t_stack *temp;

	temp = stack;
	stack = stack->next;
	temp->next = NULL;
	ft_lst_stack_add_back(&stack, temp);
	if (a_b == 1)
		write(1,"ra\n", 3);
	else if (a_b == 0)
		write(1,"rb\n", 3);
}

void rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, 2);
	rotate(stack_b, 2);
	write(1, "rr\n", 3);
}