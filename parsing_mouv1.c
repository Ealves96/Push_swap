/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_mouv1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:16:10 by ealves            #+#    #+#             */
/*   Updated: 2023/05/25 13:04:16 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//fonction pour echanger les deux premiers elements de la liste a ou b,
void	ft_sa_sb(t_data *data, char c)
{
	t_node	*tmp;

	if (c == 'a' && data->head_a && data->head_a->next)
	{
		tmp = data->head_a->next;
		data->head_a->next = tmp->next;
		tmp->next = data->head_a;
		data->head_a = tmp;
		write(1, "sa\n", 3);
	}
	else if (c == 'b' && data->head_b && data->head_b->next)
	{
		tmp = data->head_b->next;
		data->head_b->next = tmp->next;
		tmp->next = data->head_b;
		data->head_b = tmp;
		write(1, "sb\n", 3);
	}
}

//fonction pour echanger les deux premiers elements des deux listes
void	ft_ss(t_data *data)
{
	t_node	*tmp;

	if (!(data->head_a && data->head_a->next))
		return ;
	tmp = data->head_a->next;
	data->head_a->next = tmp->next;
	tmp->next = data->head_a;
	data->head_a = tmp;
	if (!(data->head_b && data->head_b->next))
		return ;
	tmp = data->head_b->next;
	data->head_b->next = tmp->next;
	tmp->next = data->head_b;
	data->head_b = tmp;
	write(1, "ss\n", 3);
}

//decale les elements de la pile A d'une posiion vers le haut
void	ft_rotate_a(t_data *data)
{
	t_node	*tmp;
	t_node	*last_el;

	if (data->head_a != NULL && data->head_a->next != NULL)
	{
		last_el = data->head_a;
		while (last_el->next != NULL)
			last_el = last_el->next;
		tmp = data->head_a;
		data->head_a = data->head_a->next;
		last_el->next = tmp;
		tmp->next = NULL;
		write(1, "ra\n", 3);
	}
}

//decale les elements de la pile B d'une position vers le haut
void	ft_rotate_b(t_data *data)
{
	t_node	*tmp;
	t_node	*last_el;

	if (data->head_b != NULL && data->head_b->next != NULL)
	{
		last_el = data->head_b;
		while (last_el->next != NULL)
			last_el = last_el->next;
		tmp = data->head_b;
		data->head_b = data->head_b->next;
		last_el->next = tmp;
		tmp->next = NULL;
		write(1, "rb\n", 3);
	}
}

//decale les elements des deux piles d'une posiion vers le haut
void	ft_rotate_rr(t_data *data)
{
	t_node	*tmp;
	t_node	*last_el;

	if (!(data->head_a != NULL && data->head_a->next != NULL))
		return ;
	last_el = data->head_a;
	while (last_el->next != NULL)
		last_el = last_el->next;
	tmp = data->head_a;
	data->head_a = data->head_a->next;
	last_el->next = tmp;
	tmp->next = NULL;
	if (!(data->head_b != NULL && data->head_b->next != NULL))
		return ;
	last_el = data->head_b;
	while (last_el->next != NULL)
		last_el = last_el->next;
	tmp = data->head_b;
	data->head_b = data->head_b->next;
	last_el->next = tmp;
	tmp->next = NULL;
	write (1, "rr\n", 3);
}
