/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_6_sort_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:30:57 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/26 12:48:13 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//##############################################################################
// HEADER
//##############################################################################

// LIBRARIES
#include "push_swap.h"

/*
** Function check if the stack is sorted
*/
int	is_sorted_linked_list(t_list_dls *stack)
{
	t_list_dls	*current;

	if (stack == NULL)
		return (1);
	current = stack;
	while (current->next != stack)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	is_sorted_linked_list_push(t_list_program *list_program)
{
	if (*list_program->stack_b)
		return ;
	if (is_sorted_linked_list(*list_program->stack_a))
	{
		print_results(list_program);
		ft_free_push_swap_end(list_program);
		exit (0);
	}
}

int	max_node_finder(t_list_dls **stack, t_list_program *list_program)
{
	int			max_node;
	int			rotations;
	t_list_dls	*current;

	rotations = 0;
	max_node = (*stack)->index;
	current = *stack;
	while (rotations < ft_lstsize(*stack))
	{
		if (current->index > max_node)
			max_node = current->index;
		current = current->next;
		rotations++;
	}
	return (max_node);
}

// Function to move a value from one position to another
/* void	move_value(t_list_dls **stack_a, t_list_dls **stack_b,
		t_position from, t_position to, t_list_program *list_program)
{
	if (from == to)
		return ;
	if (from == TOP_A)
	{
		if (to == BOTTOM_A)
			rotate("r", 'a', stack_a, list_program);
		else if (to == TOP_B)
			push('b', stack_a, stack_b, list_program);
		else if (to == BOTTOM_B)
		{
			push('b', stack_a, stack_b, list_program);
			rotate("r", 'b', stack_b, list_program);
		}
	}
	else if (from == BOTTOM_A)
	{
		if (to == TOP_A)
			rotate("rr", 'a', stack_a, list_program);
		else if (to == TOP_B)
		{
			rotate("rr", 'a', stack_a, list_program);
			push('b', stack_a, stack_b, list_program);
		}
		else
		{
			rotate("rr", 'a', stack_a, list_program);
			push('b', stack_a, stack_b, list_program);
			rotate("r", 'b', stack_b, list_program);
		}
	}
	else if (from == TOP_B)
	{
		if (to == BOTTOM_B)
			rotate("r", 'b', stack_b, list_program);
		else if (to == TOP_A)
			push('a', stack_a, stack_b, list_program);
		else
		{
			push('a', stack_a, stack_b, list_program);
			rotate("r", 'a', stack_a, list_program);
		}
	}
	else
	{
		if (to == TOP_B)
			rotate("rr", 'b', stack_b, list_program);
		else if (to == TOP_A)
		{
			rotate("rr", 'b', stack_b, list_program);
			push('a', stack_a, stack_b, list_program);
		}
		else
		{
			rotate("rr", 'b', stack_b, list_program);
			push('a', stack_a, stack_b, list_program);
			rotate("r", 'a', stack_a, list_program);
		}
	}
} */
