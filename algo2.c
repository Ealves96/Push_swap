/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:57:46 by ealves            #+#    #+#             */
/*   Updated: 2023/05/29 17:32:14 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//tri des 3 nombres qui restent dans ma stack_a en permanence
void	algo_3(t_data *data)
{
	t_node	*tmp;

	tmp = data->head_a;
	if (tmp->nmb > tmp->next->nmb && tmp->nmb > tmp->next->next->nmb)
		ft_rotate_a(data);
	else if (tmp->next->nmb > tmp->nmb && tmp->next->nmb > tmp->next->next->nmb)
		ft_reverse_ra(data);
	tmp = data->head_a;
	if (tmp->nmb > tmp->next->nmb)
		ft_sa_sb(data, 'a');
}

//par rapport a la mediane de ma liste A, savoir s il faut rb ou rr
void	least_cost_number_a(t_data *data)
{
	t_node	*stack_b;
	int		pos;

	pos = 0;
	stack_b = data->head_b;
	data->med_b = (int) data->size_b / 2;
	if (data->head_a->idx >= 3 && found_idx(data) == 1
		&& data->head_a->idx >= data->chunk)
	{
		ft_rotate_b(data);
		return ;
	}
	else
		ft_rotate_rr(data);
}

//par rapport a la mediane de ma liste B, savoir s il faut ra ou rr
void	least_cost_number_b(t_data *data)
{
	t_node	*stack_b;
	int		pos;

	pos = 0;
	stack_b = data->head_b;
	data->med_b = (int) data->size_b / 2;
	if (data->size_b < 2)
	{
		ft_rotate_a(data);
		return ;
	}
	while (data->head_b->idx != data->size_a)
	{
		pos++;
		data->head_b = data->head_b->next;
	}
	data->head_b = stack_b;
	if (pos <= data->med_b)
		ft_rotate_rr(data);
	else
	{
		ft_rotate_a(data);
	}
}
