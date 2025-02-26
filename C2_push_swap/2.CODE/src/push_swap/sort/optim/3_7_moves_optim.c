/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_7_moves_optim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:39:18 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/26 13:19:57 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moves_optimizations_0(int *j, t_list_program *list_program);
void	moves_optimizations_1(int *j, t_list_program *list_program);
void	ft_strlcpy_optm(int *j, char *move, int *i, t_list_program \
				*list_program);

void	moves_optimizations(t_list_program *list_program)
{
	int	j;

	j = 0;
	moves_optimizations_0(&j, list_program);
	list_program->move_optim_count = j;
	moves_optimizations_1(&j, list_program);
	list_program->move_optim_count = j;
}

void	moves_optimizations_0(int *j, t_list_program *list_program)
{
	int		i;
	char	*arr0;
	char	*arr1;

	i = 0;
	while (i < list_program->move_count)
	{
		arr0 = list_program->moves[i];
		arr1 = list_program->moves[i + 1];
		if (!ft_strcmp(arr0, "sa") && !ft_strcmp(arr1, "sb") || \
				(!ft_strcmp(arr0, "sb") && !ft_strcmp(arr1, "sa")))
			ft_strlcpy_optm(j, "ss", &i, list_program);
		else if (!ft_strcmp(arr0, "ra") && !ft_strcmp(arr1, "rb") || \
				(!ft_strcmp(arr0, "rb") && !ft_strcmp(arr1, "ra")))
			ft_strlcpy_optm(j, "rr", &i, list_program);
		else if (!ft_strcmp(arr0, "rra") && !ft_strcmp(arr1, "rrb") || \
				(!ft_strcmp(arr0, "rra") && !ft_strcmp(arr1, "rrb")))
			ft_strlcpy_optm(j, "rrr", &i, list_program);
		else
			ft_snprintf(list_program->moves_optim[*j], 12000, "%s", \
					list_program->moves[i]);
		i++;
		(*j)++;
	}
}

void	moves_optimizations_1(int *j, t_list_program *list_program)
{
	int	i;

	i = 0;
	*j = 0;
	while (i < list_program->move_optim_count)
	{
		if (!ft_strcmp(list_program->moves_optim[i], "ra") && \
			!ft_strcmp(list_program->moves_optim[i + 1], "rra") || \
			(!ft_strcmp(list_program->moves_optim[i], "rra") && \
			!ft_strcmp(list_program->moves_optim[i + 1], "ra")))
			i++;
		else if (!ft_strcmp(list_program->moves_optim[i], "rb") && \
				!ft_strcmp(list_program->moves_optim[i + 1], "rrb") || \
				(!ft_strcmp(list_program->moves_optim[i], "rrb") && \
				!ft_strcmp(list_program->moves_optim[i + 1], "rb")))
			i++;
		else
		{
			ft_snprintf(list_program->moves_optim[*j], 12000, "%s", \
					list_program->moves_optim[i]);
			(*j)++;
		}
		i++;
	}
}

void	ft_strlcpy_optm(int *j, char *move, int *i, t_list_program \
				*list_program)
{
	ft_strlcpy(list_program->moves_optim[*j], move, 4);
	(*i)++;
}

void	moves_optimizations_2(int *j, t_list_program *list_program);

/*
// New aggregate rotation optimization: Sum all rotation moves and 
//then recreate a minimal move sequence.
void	moves_optimizations_aggregate(t_list_program *list_program)
{
    int		ra_net = 0;
    int		rb_net = 0;
    int		i;
    int		j;
    char	**temp_moves;
    char	buffer[64];

    // First pass: aggregate net rotations from the original moves list.
    for (i = 0; i < list_program->move_count; i++)
    {
        if (!ft_strcmp(list_program->moves[i], "ra"))
            ra_net++;
        else if (!ft_strcmp(list_program->moves[i], "rra"))
            ra_net--;
        else if (!ft_strcmp(list_program->moves[i], "rb"))
            rb_net++;
        else if (!ft_strcmp(list_program->moves[i], "rrb"))
            rb_net--;
        // You may also process "rr" or "rrr" if they appear.
        else if (!ft_strcmp(list_program->moves[i], "rr"))
        {
            ra_net++;
            rb_net++;
        }
        else if (!ft_strcmp(list_program->moves[i], "rrr"))
        {
            ra_net--;
            rb_net--;
        }
    }

    // Second pass: build a new move list based on the aggregated net rotations.
    // Allocate a temporary array to hold the new moves.
    temp_moves = malloc(sizeof(char *) * list_program->move_count);
    if (!temp_moves)
        return ;
    j = 0;

    // First, handle simultaneous rotations if both nets have the same sign.
    if (ra_net > 0 && rb_net > 0)
    {
        int common = ra_net < rb_net ? ra_net : rb_net;
        for (i = 0; i < common; i++)
            temp_moves[j++] = ft_strdup("rr");
        ra_net -= common;
        rb_net -= common;
    }
    else if (ra_net < 0 && rb_net < 0)
    {
        int common = (-ra_net) < (-rb_net) ? (-ra_net) : (-rb_net);
        for (i = 0; i < common; i++)
            temp_moves[j++] = ft_strdup("rrr");
        ra_net += common;
        rb_net += common;
    }

    // Then add remaining rotations for stack A.
    while (ra_net > 0)
    {
        temp_moves[j++] = ft_strdup("ra");
        ra_net--;
    }
    while (ra_net < 0)
    {
        temp_moves[j++] = ft_strdup("rra");
        ra_net++;
    }

    // Then add remaining rotations for stack B.
    while (rb_net > 0)
    {
        temp_moves[j++] = ft_strdup("rb");
        rb_net--;
    }
    while (rb_net < 0)
    {
        temp_moves[j++] = ft_strdup("rrb");
        rb_net++;
    }

    // Now you can replace the original moves_optim array with the new one.
    // Free the old moves_optim if needed, then copy over.
    for (i = 0; i < j; i++)
    {
        ft_snprintf(list_program->moves_optim[i], 12000, "%s", temp_moves[i]);
        free(temp_moves[i]);
    }
    free(temp_moves);
    list_program->move_optim_count = j;
}
*/