/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_mouv2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:05:58 by ealves            #+#    #+#             */
/*   Updated: 2023/05/24 14:32:55 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//decale les elements de la pile A d'une position vers le bas
void	ft_reverse_ra(t_data *data)
{
	t_node	*tmp;
	t_node	*last_el;

	if (data->head_a != NULL && data->head_a->next != NULL)
	{
		last_el = data->head_a;
		while (last_el->next != NULL)
			last_el = last_el->next;
		tmp = last_el;
		last_el = data->head_a;
		while (last_el->next != tmp)
			last_el = last_el->next;
		last_el->next = NULL;
		tmp->next = data->head_a;
		data->head_a = tmp;
		write(1, "rra\n", 4);
	}
}

//decale les elements de la pile B d'une position vers le bas
void	ft_reverse_rb(t_data *data)
{
	t_node	*tmp;
	t_node	*last_el;

	if (data->head_b != NULL && data->head_b->next != NULL)
	{
		last_el = data->head_b;
		while (last_el->next != NULL)
			last_el = last_el->next;
		tmp = last_el;
		last_el = data->head_b;
		while (last_el->next != tmp)
			last_el = last_el->next;
		last_el->next = NULL;
		tmp->next = data->head_b;
		data->head_b = tmp;
		write(1, "rrb\n", 4);
	}
}

void	ft_reverse_rr(t_data *data)
{
	if ((data->head_a && data->head_a->next)
		&& (data->head_b && data->head_b->next))
	{
		ft_reverse_ra(data);
		ft_reverse_rb(data);
		write(1, "rrr\n", 4);
	}
}

//Prends le premier element de la pile B et l'ajoute a la pile A
void	ft_push_a(t_data *data)
{
	t_node	*tmp;

	if (data->head_b)
	{
		tmp = data->head_b;
		data->head_b = tmp->next;
		tmp->next = NULL;
		if (data->head_a == NULL)
			data->head_a = tmp;
		else
		{
			tmp->next = data->head_a;
			data->head_a = tmp;
		}
		data->size_a++;
		data->size_b--;
		write(1, "pa\n", 3);
	}
}

//Prends le premier element de la pile A et l'ajoute a la pile B
void	ft_push_b(t_data *data)
{
	t_node	*tmp;

	if (data->head_a)
	{
		tmp = data->head_a;
		data->head_a = tmp->next;
		tmp->next = NULL;
		if (data->head_b == NULL)
			data->head_b = tmp;
		else
		{
			tmp->next = data->head_b;
			data->head_b = tmp;
		}
		data->size_a--;
		data->size_b++;
		write(1, "pb\n", 3);
	}
}
