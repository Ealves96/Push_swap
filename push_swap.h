/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:45:43 by elie              #+#    #+#             */
/*   Updated: 2023/05/29 17:18:20 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "includes/ft_printf/ft_printf.h"
# include "includes/libft/libft.h"
# include <stdlib.h>
# include <limits.h>

// définition de la structure d'un maillon de la liste chaînée
typedef struct s_node
{
	int				nmb;
	int				pos;
	int				idx;
	struct s_node	*next;
}					t_node;

typedef struct s_data
{
	int		argc;
	t_node	*stack_a;
	t_node	*head_a;
	t_node	*stack_b;
	t_node	*head_b;
	int		size_a;
	int		size_b;
	int		med_b;
	int		chunk;
	int		med_chunk;
	int		div;
}			t_data;

//////////main.c//////////
void	set_data(t_data *data);
void	ft_tri(t_data *data, int argc);

//////////parcing_utils.c//////////
void	ft_error(t_data *data, const char *msg);
void	arg_error(t_data *data, char **argv);
void	free_node(t_data *data);
int		ft_index(t_data *data, int nmb, char **argv);
int		add_node(t_data *data, int nmb, int pos, char **argv);

//////////parsing_utils2//////////
void	verif_doublon(t_data *data);
int		ps_atoi(t_data *data, const char *str);
int		verif_tri(t_data *data, int argc);

//////////parcing_mouv1.c//////////
//echange les deux premiers elements
void	ft_sa_sb(t_data *data, char c);
void	ft_ss(t_data *data);
//decale les elements d'une position vers le haut
void	ft_rotate_a(t_data *data);
void	ft_rotate_b(t_data *data);
void	ft_rotate_rr(t_data *data);

//////////parcing_mouv2.c//////////
//decale les elements d'une position vers le bas
void	ft_reverse_ra(t_data *data);
void	ft_reverse_rb(t_data *data);
void	ft_reverse_rr(t_data *data);
//prend le premier element de la pile et l'ajoute a l'autre pile
void	ft_push_a(t_data *data);
void	ft_push_b(t_data *data);

//////////algo.c//////////
int		found_idx(t_data *data);
void	size_list(t_data *data);
void	empty_a(t_data *data);
void	least_cost_number(t_data *data);
void	empty_b(t_data *data);

//////////algo2.c//////////
void	algo_3(t_data *data);
void	least_cost_number_a(t_data *data);
void	least_cost_number_b(t_data *data);
// void	print_list(t_data *data);

#endif
