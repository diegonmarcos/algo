/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_2_selectionsort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:31:07 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/25 11:21:25 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* https://linktr.ee/diegonmarcos											  */
/* ************************************************************************** */

//##############################################################################
// HEADER
//##############################################################################
#include "push_swap.h"
/*
Will look for the min and rotate the stack until it is at the top and 
	then push it to the other stack
*/

void	selection_sort(t_list_program *list_program)
{
	int	size;
	int	pushes;

	pushes = 0;
	ft_printers(SELEC, list_program);
	size = list_program->stack_a_size;
	if (is_sorted_linked_list(*list_program->stack_a))
		return ;
	if (size == 2)
		swap('a', list_program);
	else
		selection_sort_recursion(&pushes, list_program);
}

void	selection_sort_recursion(int *pushes, \
			t_list_program *list_program)
{
	int			pos;
	t_list_dls	*min_node;
	t_list_dls	**stack_a;
	int			size;

	size = ft_lstsize(*list_program->stack_a);
	if (size == 3)
	{
		sort_3(list_program->stack_a, list_program);
		selection_sort_merge_back(pushes, list_program);
		return ;
	}
	stack_a = list_program->stack_a;
	min_node = find_min_node(*stack_a);
	pos = min_node_pos(list_program);
	while ((*stack_a)->value != min_node->value)
	{
		if (pos < size / 2)
			rotate("r", 'a', list_program);
		else
			rotate("rr", 'a', list_program);
	}
	push('b', list_program);
	return ((*pushes)++, selection_sort_recursion(pushes, list_program));
}

/*
| Case 0 | Case A | Case B | Case C | Case D | Case E | Case F |
|--------|--------|--------|--------|--------|--------|--------|
|   2    |   3    |   3    |   2    |   2    |   1    |   1    |
|   1    |   2    |   1    |   1    |   3    |   3    |   2    |
|   2    |   1    |   2    |   3    |   1    |   2    |   3    |
*/
void	sort_3(t_list_dls **stack_a, t_list_program *list_program)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
	if (first > second && first == third)
		swap('a', list_program);
	if (first > second && second > third && first > third)
	{
		swap('a', list_program);
		rotate("rr", 'a', list_program);
	}
	else if (first > second && second < third && first > third)
		rotate("r", 'a', list_program);
	else if (first > second && second < third && first < third)
		swap('a', list_program);
	else if (first < second && second > third && first > third)
		rotate("rr", 'a', list_program);
	else if (first < second && second > third && first < third)
	{
		rotate("rr", 'a', list_program);
		swap('a', list_program);
	}
}

void	selection_sort_merge_back(int *pushes, t_list_program *list_program)
{
	while ((*pushes)-- > 0)
		push('a', list_program);
}

int	min_node_pos(t_list_program *list_program)
{
	t_list_dls	*min_node;
	t_list_dls	*current;
	int			pos;

	pos = 0;
	min_node = find_min_node(*list_program->stack_a);
	current = *list_program->stack_a;
	while (current != min_node)
	{
		pos++;
		current = current->next;
	}
	return (pos);
}
