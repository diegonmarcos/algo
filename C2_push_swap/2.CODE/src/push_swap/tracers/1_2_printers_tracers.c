/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_2_printers_tracers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:53:04 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/25 10:25:50 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_printers1(t_ft_printers_db s, t_list_program *list_program);

void	print_results(t_list_program *list_program)
{
	char	filename[100];

	ft_snprintf(filename, sizeof(filename), "%s%d.txt", \
				"log/3.Unit_Testing/moves/moves_from_struct_", \
				list_program->stack_a_size);
	ft_fprintf1(filename, "%S\n", list_program->moves);
	ft_printf("%S", list_program->moves_optim);
}

void	ft_printers(t_ft_printers_db s, t_list_program *list_program)
{
	if (s == START)
	{
		ft_fprintf2("w", "log/2.Memory_Check/allocs/malloc_allocs", "");
		ft_fprintf2("w", "log/2.Memory_Check/allocs/malloc_allocs.txt", "");
		ft_fprintf2("w", SA_PATH, "SA_input:\n%L\n", *list_program->stack_a);
		ft_fprintf2("w", SB_PATH, "SB_input:\n%L\n", *list_program->stack_b);
	}
	else if (s == END)
	{
		ft_fprintf2("a", SA_PATH, "SA_output:\n%L\n", *list_program->stack_a);
		ft_fprintf2("a", SB_PATH, "SB_output:\n%L\n", *list_program->stack_b);
	}
	else if (s == MOVEF)
	{
		ft_fprintf2("a", SA_PATH, \
			"\nMoves:%S\n\nMoves Optimized:%S", \
			list_program->moves, list_program->moves_optim);
		ft_fprintf2("a", SA_PATH, \
			"\nArray Size:%d\nMoves Count:%d\nMoves Optimized Count:%d\n", \
			list_program->stack_a_size, list_program->move_count, \
			list_program->move_optim_count);
	}
	else
		ft_printers1(s, list_program);
}

static void	ft_printers1(t_ft_printers_db s, t_list_program *list_program)
{
	int	last;

	if (s == SELEC)
		ft_fprintf2("a", SA_PATH, "ALGO:Selection\n");
	else if (s == RADIX)
		ft_fprintf2("a", SA_PATH, "ALGO:Radix\n");
	else if (s == QUICK)
		ft_fprintf2("a", SA_PATH, "ALGO:Quick\n");
	else if (s == GEAR)
		ft_fprintf2("a", SA_PATH, "ALGO:Gear\n");
	last = list_program->move_count - 1;
	if (s == MOVES && DBG)
	{
		ft_fprintf2("a", SA_PATH, "SA:Move:%s | %d\n%L", \
			list_program->moves[last], list_program->move_count, \
			*list_program->stack_a);
		ft_fprintf2("a", SB_PATH, "SB:Move:%s | %d\n%L", \
			list_program->moves[last], list_program->move_count, \
			*list_program->stack_b);
	}
}

void	ft_printers_gearsort(t_ft_printers_db s, t_move_lower_cost *v, \
			t_list_program *list_program)
{
	if (s == PRICES && DBG)
		ft_fprintf2("a", PRICES_PATH, "%d;%d;%d\n", list_program->move_count, \
			v->value_of_cheapest, v->price_of_cheapest);
}

void	printer_dbg_split(t_ft_printers_db s, t_split_chunks *split_chunks, \
			t_list_program *list_program)
{
	if (!DBG)
		return ;
	if (s == MERGE_AS)
	{
		ft_fprintf2("a", SA_PATH, "\nMERGE B AND SORT\n");
		ft_fprintf2("a", SB_PATH, "\nMERGE B AND SORT\n");
	}
	else if (s == MERGE_NS)
	{
		ft_fprintf2("a", SA_PATH, "\nMERGE B NO SORT\n");
		ft_fprintf2("a", SB_PATH, "\nMERGE B NO SORT\n");
	}
	else if (s == SPLIT)
		ft_fprintf2("a", SA_PATH, "\nSPLIT\n");
	ft_fprintf2("a", SA_PATH, "MIN:%d\n", \
		split_chunks->min.min);
	ft_fprintf2("a", SA_PATH, "PIVOT1:%d\n", \
		split_chunks->pivot1);
	ft_fprintf2("a", SA_PATH, "PIVOT2:%d\n", \
		split_chunks->pivot2);
	ft_fprintf2("a", SA_PATH, "MAX:%d\nPOS:%d\n\n", \
		split_chunks->max.max, split_chunks->position_from);
	ft_printers(END, list_program);
}
