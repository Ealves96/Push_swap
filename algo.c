/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:39:34 by ealves            #+#    #+#             */
/*   Updated: 2023/05/29 17:27:36 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//quand il y a toujours quelque chose a push dans un chunk
//(avant de passer au chunk suivant)
int	found_idx(t_data *data)
{
	t_node	*stack_a;

	stack_a = data->head_a;
	while (stack_a)
	{
		if (stack_a->idx >= data->chunk
			&& stack_a->idx >= 3)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

//creation de mes chunk en fonction de la longueur de ma liste
void	size_list(t_data *data)
{
	if (data->size_a >= 0 && data->size_a <= 20)
		data->div = data->size_a;
	else if (data->size_a > 20 && data->size_a <= 50)
		data->div = data->size_a / 2;
	else if (data->size_a > 50 && data->size_a < 300)
		data->div = data->size_a / 4;
	else
		data->div = data->size_a / 10;
}

//creation de mes sous chunk envoyes a stack_b
void	empty_a(t_data *data)
{
	size_list(data);
	data->chunk = data->size_a - data->div;
	data->med_chunk = data->size_a - data->div / 2;
	while (data->size_a > 3)
	{
		if (data->head_a->idx >= 3 && found_idx(data) == 1
			&& data->head_a->idx >= data->chunk)
		{
			ft_push_b(data);
			if (data->head_b->idx < data->med_chunk
				&& data->size_b >= 2)
				least_cost_number_a(data);
		}
		else
			ft_rotate_a(data);
		if (found_idx(data) == 0)
		{
			data->chunk -= data->div;
			data->med_chunk -= data->div;
		}
	}
}

// par rapport a la mediane, savoir s il faut rb ou rrb
void	least_cost_number(t_data *data)
{
	t_node	*stack_b;
	int		pos;

	pos = 0;
	stack_b = data->head_b;
	data->med_b = (int) data->size_b / 2;
	while (data->head_b->idx != data->size_a)
	{
		pos++;
		data->head_b = data->head_b->next;
	}
	data->head_b = stack_b;
	if (pos <= data->med_b)
		while (pos-- != 0)
			ft_rotate_b(data);
	else
	{
		pos = data->size_b - pos;
		while (pos-- != 0)
			ft_reverse_rb(data);
	}
}

//Le nombre avec le coût le moins élevé est déplacé de B vers A
void	empty_b(t_data *data)
{
	t_node	*stack_b;
	t_node	*stack_a;
	t_node	*min_node;
	int		min_cost;

	stack_b = data->head_b;
	stack_a = data->head_a;
	min_node = NULL;
	min_cost = INT_MAX;
	while (data->head_b)
	{
		least_cost_number(data);
		ft_push_a(data);
		least_cost_number_b(data);
	}
}
