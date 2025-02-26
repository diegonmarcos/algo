/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.1.Moves_both.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:31:41 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/19 09:05:45 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//##############################################################################
// HEADER
//##############################################################################

// LIBRARIES
//#include "all_inc_inc.h"
#include "push_swap.h"

//##############################################################################
// STACK MOVES
//##############################################################################
/*
- Swap the top two elements of both stacks.
*/
void	swap_both(t_list_program *list_program)
{
	int			i;
	t_list_dls	**stack;
	t_list_dls	*first;
	t_list_dls	*second;

	i = 2;
	stack = list_program->stack_a;
	while (i-- || *stack == NULL || (*stack)->next == *stack)
	{
		first = *stack;
		second = (*stack)->next;
		first->next = second->next;
		second->prev = first->prev;
		first->prev = second;
		second->next = first;
		if (first->next != NULL)
			first->next->prev = first;
		if (second->prev != NULL)
			second->prev->next = second;
		*stack = second;
		stack = list_program->stack_b;
	}
	ft_snprintf(list_program->moves[list_program->move_count++], \
				list_program->max_moves, "ss");
	ft_printers(MOVES, list_program);
}

/*
- Rotate the top two elements of stack.
*/
void	rotate_both(char *direction, t_list_program *list_program)
{
	int			i;
	t_list_dls	**stack;
	t_list_dls	*head;
	t_list_dls	*tail;

	stack = list_program->stack_a;
	i = 2;
	while (i--)
	{
		if (*stack == NULL || (*stack)->next == *stack)
			return ;
		head = *stack;
		tail = (*stack)->prev;
		if (ft_strncmp(direction, "r", sizeof("r")) == 0)
			*stack = head->next;
		else if (ft_strncmp(direction, "rr", sizeof("rr")) == 0)
			*stack = tail;
		stack = list_program->stack_b;
	}
	ft_snprintf(list_program->moves[list_program->move_count++], \
				list_program->max_moves, "%s", direction);
	ft_printers(MOVES, list_program);
}
