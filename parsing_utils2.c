/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:51:09 by ealves            #+#    #+#             */
/*   Updated: 2023/05/25 18:39:45 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	verif_doublon(t_data *data)
{
	t_node	*tmp;
	t_node	*i;

	tmp = data->head_a;
	while (tmp)
	{
		i = tmp->next;
		while (i)
		{
			if (tmp->nmb == i->nmb)
				ft_error(data, "Error\n");
			i = i->next;
		}
		tmp = tmp->next;
	}
}

int	verif_tri(t_data *data, int argc)
{
	t_node	*tmp;

	tmp = data->head_a;
	if (argc == 1)
		exit(1);
	if (argc < 3)
	{
		free_node(data);
		exit (0);
	}
	while (data->head_a && data->head_a->next != NULL)
	{
		if (data->head_a->next->nmb > data->head_a->nmb)
			data->head_a = data->head_a->next;
		else
		{
			data->head_a = tmp;
			return (1);
		}
	}
	data->head_a = tmp;
	return (0);
}

int	ps_atoi(t_data *data, const char *str)
{
	int		i;
	long	result;
	int		sign;

	sign = 1;
	i = 0;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '-' || str[i + 1] == '+'
			|| str[i + 1] == ' ' || str[i + 1] == '\0')
			ft_error(data, "Error\n");
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	return (sign * result);
}
