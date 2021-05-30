/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:11:58 by mservage          #+#    #+#             */
/*   Updated: 2021/05/26 08:14:56 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "push_swap_struct.h"
# include "./instructions/instructions.h"
# include "./Utils/utils.h"

/* Dans push_swap.c */
t_stack	*init_stack_a(int ac, char **av);
int	check_doublon(t_stack *stack_a, int ac);
int	check_arg_num(int ac, char **av);
int main (int ac, char **av);

#endif