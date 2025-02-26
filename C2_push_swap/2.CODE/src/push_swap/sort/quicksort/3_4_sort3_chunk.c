/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.3.Selectionsort_chunk.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:59:09 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/21 11:11:14 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/*
CASE 0
2
1

Case A
3
2
1

Case B
3
1
2

Case C
2
1
3


Case D
2
3
1

CASE E
1
3
2

CASE F
1
2
3
*/
