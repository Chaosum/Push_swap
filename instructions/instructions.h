/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:20:20 by mservage          #+#    #+#             */
/*   Updated: 2021/06/22 17:59:24 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H
# include "../push_swap.h"

void	push(t_stack **stack_a, t_stack **stack_b, int a_b);
void	r_rotate(t_stack **stack, int a_b);
void	r_rotate_both(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack, int a_b);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);
void	swap(t_stack **stack, int a_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

#endif