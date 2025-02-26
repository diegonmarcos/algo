/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_4_sort3_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:59:09 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/26 17:39:07 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
| Case 0 | Case A | Case B | Case C | Case D | Case E | Case F |
|--------|--------|--------|--------|--------|--------|--------|
|   2    |   3    |   3    |   2    |   2    |   1    |   1    |
|   1    |   2    |   1    |   1    |   3    |   3    |   2    |
|   2    |   1    |   2    |   3    |   1    |   2    |   3    |
*/
void	selection_sort_chunk(t_list_program *list_program)
{
	t_list_dls	**stack_a;
	int			first;
	int			second;
	int			third;

	stack_a = list_program->stack_a;
	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
	if (first > second && first == third)
		swap('a', list_program);
	else if (first > second && second > third && first > third)
	{
		rotate("r", 'a', list_program);
		rotate("r", 'a', list_program);
		push('b', list_program);
		rotate("rr", 'a', list_program);
		rotate("rr", 'a', list_program);
		swap('a', list_program);
		push('a', list_program);

	}
	else if (first > second && second < third && first > third)
	{
		swap('a', list_program);
		push('b', list_program);
		swap('a', list_program);
		push('a', list_program);
	}
	else if (first > second && second < third && first < third)
		swap('a', list_program);
	else if (first < second && second > third && first > third)
	{
		rotate("r", 'a', list_program);
		rotate("r", 'a', list_program);
		push('b', list_program);
		rotate("rr", 'a', list_program);
		rotate("rr", 'a', list_program);
		push('a', list_program);
	}
	else if (first < second && second > third && first < third)
	{
		push('b', list_program);
		swap('a', list_program);
		push('a', list_program);
	}
	else if ((first < second && second < third && first < third) \
		|| first == second)
		return ;
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