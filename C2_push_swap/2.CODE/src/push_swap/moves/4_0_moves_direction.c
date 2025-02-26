/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_0_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:31:50 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/25 10:12:29 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//##############################################################################
// HEADER
//##############################################################################

// LIBRARIES
#include "push_swap.h"

static void	push2(t_list_dls **dest_stack, t_list_dls *node_to_move, \
					char direction, t_list_program *list_program);

//##############################################################################
// STACK MOVES
//##############################################################################

// - Push the top element of statck.
void	push(char direction, t_list_program *list_program)
{
	t_list_dls	**src_stack;
	t_list_dls	**dest_stack;
	t_list_dls	*node_to_move;

	src_stack = list_program->stack_a;
	dest_stack = list_program->stack_b;
	if (direction == 'a')
		src_stack = list_program->stack_b;
	if (direction == 'a')
		dest_stack = list_program->stack_a;
	if (*src_stack == NULL)
		return ;
	node_to_move = *src_stack;
	if ((*src_stack)->next == *src_stack)
		*src_stack = NULL;
	else
	{
		(*src_stack)->prev->next = (*src_stack)->next;
		(*src_stack)->next->prev = (*src_stack)->prev;
		*src_stack = (*src_stack)->next;
	}
	push2(dest_stack, node_to_move, direction, list_program);
}

static void	push2(t_list_dls **dest_stack, t_list_dls *node_to_move, \
					char direction, t_list_program *list_program)
{
	if (*dest_stack == NULL)
	{
		*dest_stack = node_to_move;
		node_to_move->next = node_to_move;
		node_to_move->prev = node_to_move;
	}
	else
	{
		node_to_move->next = *dest_stack;
		node_to_move->prev = (*dest_stack)->prev;
		(*dest_stack)->prev->next = node_to_move;
		(*dest_stack)->prev = node_to_move;
		*dest_stack = node_to_move;
	}
	ft_snprintf(list_program->moves[list_program->move_count++], \
				list_program->max_moves, "p%c", direction);
	ft_printers(MOVES, list_program);
}

/* SWAP 
 * Swap the top two elements of stack.
 * Stack_name is 'a' for stack_a and 'b' for stack_b
 * If the stack is empty or has only one element, it does nothing
*/
void	swap(char stack_name, t_list_program *list_program)
{
	t_list_dls	*first;
	t_list_dls	*second;
	t_list_dls	**stack;

	if (stack_name == 'a')
		stack = list_program->stack_a;
	else
		stack = list_program->stack_b;
	first = *stack;
	second = (*stack)->next;
	if (*stack == NULL || (*stack)->next == *stack)
		return ;
	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
	if (first->next != NULL)
		first->next->prev = first;
	if (second->prev != NULL)
		second->prev->next = second;
	*stack = second;
	ft_snprintf(list_program->moves[list_program->move_count++], \
				list_program->max_moves, "s%c", stack_name);
	ft_printers(MOVES, list_program);
}

/** @brief Rotates the specified stack.
 *
 * 	@details
 * 	@par Details:
 * 	- function rotates the given stack based on the provided direction.
 * 	- The direction "r" rotates the stack upward (counter-clockwise, 
 * 		head to tail).
 * 	- The direction "rr" rotates the stack downward (clockwise, tail to head).
 * 	- The stack_name 'a' refers to stack_a and 'b' refers to stack_b.
 * 	- If the specified stack is empty or contains only one element, 
 * 		no rotation is performed.
 * 
 * 	@par Usage:
 * 	- @b direction The rotation direction: "r" or "rr".
 * 	- @b stack_name The identifier for the stack: 'a' or 'b'.
 * 	- @b list_program Pointer to the structure containing the stacks.
 * 	- @b return is void.
 */
void	rotate(char *direction, char stack_name, t_list_program *list_program)
{
	t_list_dls	*head;
	t_list_dls	*tail;
	t_list_dls	**stack;

	if (stack_name == 'a')
		stack = list_program->stack_a;
	else
		stack = list_program->stack_b;
	head = *stack;
	tail = (*stack)->prev;
	if (*stack == NULL || (*stack)->next == *stack)
		return ;
	if (ft_strncmp(direction, "r", sizeof("r")) == 0)
		*stack = head->next;
	else if (ft_strncmp(direction, "rr", sizeof("rr")) == 0)
		*stack = tail;
	else
		return ;
	ft_snprintf(list_program->moves[list_program->move_count++], \
				list_program->max_moves, "%s%c", direction, stack_name);
	ft_printers(MOVES, list_program);
}
