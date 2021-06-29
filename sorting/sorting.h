/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:16:34 by mservage          #+#    #+#             */
/*   Updated: 2021/06/29 10:52:04 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H
# include "../push_swap.h"

int	sort_three_elem_only_a(t_stack **a);
int	sort_three_elem_b(t_stack **a, t_stack **b);
int	sort_three_elem_a(t_stack **a, t_stack **b);
int	sorting_stack_a(t_stack **a, t_stack **b, t_var var, int len);
int	sorting_stack_b(t_stack **a, t_stack **b, t_var var, int len);

#endif