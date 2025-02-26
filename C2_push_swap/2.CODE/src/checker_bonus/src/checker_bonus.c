/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:56:06 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/26 13:23:57 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_moves_to_apply(char **line, t_list_program *list_program)
{
	if (ft_strncmp(*line, "pb", 2) == 0)
		push('b', list_program);
	else if (ft_strncmp(*line, "ra", 2) == 0)
		rotate("r", 'a', list_program);
	else if (ft_strncmp(*line, "rb", 2) == 0)
		rotate("r", 'b', list_program);
	else if (ft_strncmp(*line, "sa", 2) == 0)
		swap('a', list_program);
	else if (ft_strncmp(*line, "sb", 2) == 0)
		swap('b', list_program);
	else if (ft_strncmp(*line, "pa", 2) == 0)
		push('a', list_program);
	else if (ft_strncmp(*line, "rra", 3) == 0)
		rotate("rr", 'a', list_program);
	else if (ft_strncmp(*line, "rrb", 3) == 0)
		rotate("rr", 'b', list_program);
	else if (ft_strncmp(*line, "rrr", 3) == 0)
		rotate_both("rrr", list_program);
	else if (ft_strncmp(*line, "rr", 2) == 0)
		rotate_both("rr", list_program);
	else if (ft_strncmp(*line, "ss", 2) == 0)
		swap_both(list_program);
	else
		return (1);
	return (0);
}

static int	apply_moves_to_stack(char **line, t_list_program *list_program)
{
	while (*line)
	{
		if (!check_moves_to_apply(line, list_program))
			line++;
		else
			halt_exit_(1);
	}
	if (is_sorted_linked_list(*list_program->stack_a) \
		&& !*list_program->stack_b)
	{
		write(1, "OK\n", 3);
		halt_exit_(0);
	}
	else
	{
		write(1, "KO\n", 3);
		halt_exit_(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list_program	*list_program;
	char			*line2[10001];

	error_handling_input_0(argc, argv);
	data_alloc(argc, argv, list_program);
	error_handling_input_1(list_program);
	*list_program->stack_a = array_to_d_linked_list(\
								list_program->stack_a_array);
	get_next_line2(0, line2);
	apply_moves_to_stack(line2, list_program);
	ft_free_push_swap_end(list_program);
	return (0);
}
