/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 17:16:49 by mservage          #+#    #+#             */
/*   Updated: 2021/05/27 18:26:19 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

void push(t_stack *stack_a, t_stack *stack_b, int a_b)
{
	t_stack *temp;
	if (a_b)
	{
		if (stack_a)
		{
			temp = stack_a;
			stack_a = stack_a->next;
			temp->next = stack_b;
			stack_b = temp;
		}
		write(1, "pa\n", 3);
	}
	else
	{
		if (stack_b)
		{
			temp = stack_b;
			stack_b = stack_b->next;
			temp->next = stack_a;
			stack_a = temp;
		}
		write(1, "pb\n", 3);
	}
}