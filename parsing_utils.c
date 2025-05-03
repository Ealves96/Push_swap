/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:07:01 by ealves            #+#    #+#             */
/*   Updated: 2023/05/29 17:17:18 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_data *data, const char *msg)
{
	write (2, msg, ft_strlen(msg));
	free_node(data);
	free(data->head_b);
	exit (1);
}

void	arg_error(t_data *data, char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (argv[j])
	{
		i = 0;
		if (argv[j][i] == '+' || argv[j][i] == '-')
		{
			if (!argv[j][i + 1])
				ft_error(data, "Error\n");
			i++;
		}
		while (argv[j][i] != '\0')
		{
			if (!ft_isdigit(argv[j][i]))
				ft_error(data, "Error\n");
			i++;
		}
		if (ft_strlen(argv[j]) > 11 || ft_atoi(argv[j]) > 2147483647
			|| ft_atoi(argv[j]) < -2147483648)
			ft_error(data, "Error\n");
		j++;
	}
}

void	free_node(t_data *data)
{
	t_node	*current;

	while (data->head_a != NULL)
	{
		current = data->head_a;
		data->head_a = data->head_a->next;
		free(current);
	}
	while (data->head_b != NULL)
	{
		current = data->head_b;
		data->head_b = data->head_b->next;
		free(current);
	}
}

int	ft_index(t_data *data, int nmb, char **argv)
{
	int		j;
	int		idx;

	j = 1;
	idx = 0;
	while (j < data->argc)
	{
		if (ps_atoi(data, argv[j]) == nmb)
			j++;
		else if (ps_atoi(data, argv[j]) < nmb)
		{
			idx++;
			j++;
		}
		else
			j++;
	}
	return (idx);
}

// fonction pour ajouter un maillon dans la liste a
int	add_node(t_data *data, int nmb, int pos, char **argv)
{
	t_node	*new_node;
	t_node	*tmp;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		ft_error(data, "Error\n");
	new_node->nmb = nmb;
	new_node->pos = pos;
	new_node->idx = ft_index(data, nmb, argv);
	new_node->next = NULL;
	if (data->head_a == NULL)
	{
		data->head_a = new_node;
		data->stack_a = data->head_a;
	}
	else
	{
		tmp = data->head_a;
		while (data->head_a->next != NULL)
			data->head_a = data->head_a->next;
		data->head_a->next = new_node;
		data->head_a = tmp;
	}
	return (1);
}

// void	print_list(t_data *data)
// {
// 	data->stack_a = data->head_a;
// 	data->stack_b = data->head_b;

// 	ft_printf("Stack A :\n");
// 	while (data->stack_a != NULL)
// 	{
// 		ft_printf("idx %d: %d , addr = %p, next = %p\n",
// 			data->stack_a->idx, data->stack_a->nmb,
			// 	data->stack_a ,data->stack_a->next);
// 		data->stack_a = data->stack_a->next;
// 	}
// 	ft_printf("\nStack B :\n");
// 	while (data->stack_b)
// 	{
// 		ft_printf("idx %d: %d\n", data->stack_b->idx, data->stack_b->nmb);
// 		data->stack_b = data->stack_b->next;
// 	}
// 	ft_printf("Mediane : %d\n", data->med_b);
// 	ft_printf("\n");
// }
