/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:44:51 by elie              #+#    #+#             */
/*   Updated: 2023/05/29 17:07:04 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_data(t_data *data)
{
	data->stack_a = NULL;
	data->head_a = NULL;
	data->stack_b = NULL;
	data->head_b = NULL;
	data->size_a = 0;
	data->med_b = 0;
	data->chunk = 0;
	data->med_chunk = 0;
	data->div = 0;
}

void	ft_tri(t_data *data, int argc)
{
	if (verif_tri(data, argc))
	{
		if (data->size_a == 2)
		{
			ft_sa_sb(data, 'a');
			return ;
		}
		empty_a(data);
		algo_3(data);
		empty_b(data);
	}
}

int	main(int argc, char **argv)
{
	int		nmb;
	int		i;
	t_data	data;

	i = 0;
	ft_memset(&data, 0, sizeof(t_data));
	set_data(&data);
	data.argc = argc;
	i = 1;
	arg_error(&data, argv);
	while (i < argc)
	{
		nmb = ps_atoi(&data, argv[i]);
		add_node(&data, nmb, i - 1, argv);
		i++;
	}
	data.size_a = i - 1;
	verif_doublon(&data);
	ft_tri(&data, argc);
	free_node(&data);
	return (0);
}
