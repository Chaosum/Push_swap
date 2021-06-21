/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:16:34 by mservage          #+#    #+#             */
/*   Updated: 2021/06/10 19:16:13 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H
# include "../push_swap.h"

int	found_median(t_stack *stack, t_var *var);
int	sorting_start(t_stack *a, t_stack *b, t_var *var);

#endif