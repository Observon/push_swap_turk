/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eride-ol <eride-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:01:26 by eride-ol          #+#    #+#             */
/*   Updated: 2026/01/20 20:01:26 by eride-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
    int             value;
    int             index;
    int             pos;
    int             target_pos;
    int             cost_a;
    int             cost_b;
    struct s_stack  *next;
}   t_stack;

// Parsing e validação
int		is_valid_number(char *str);
int		has_duplicates(t_stack *stack);
int		is_sorted(t_stack *stack);
t_stack	*parse_arguments(int argc, char **argv);
int		parse_int(const char *str, int *out);
void	free_stack(t_stack **stack);
void	error_exit(void);

// Operações de pilha
void    sa(t_stack **stack_a, int print);
void    sb(t_stack **stack_b, int print);
void    ss(t_stack **stack_a, t_stack **stack_b, int print);
void    pa(t_stack **stack_a, t_stack **stack_b, int print);
void    pb(t_stack **stack_a, t_stack **stack_b, int print);
void    ra(t_stack **stack_a, int print);
void    rb(t_stack **stack_b, int print);
void    rr(t_stack **stack_a, t_stack **stack_b, int print);
void    rra(t_stack **stack_a, int print);
void    rrb(t_stack **stack_b, int print);
void    rrr(t_stack **stack_a, t_stack **stack_b, int print);

// Algoritmos de ordenação
void	sort_three(t_stack **stack);
void	sort_small(t_stack **stack_a, t_stack **stack_b);
void	rotate_to_min(t_stack **stack_a, int size);
void	turk_algorithm(t_stack **stack_a, t_stack **stack_b);
void	get_target_positions(t_stack **stack_a, t_stack **stack_b);
void	calculate_costs(t_stack **stack_a, t_stack **stack_b);
void	execute_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void	shift_stack(t_stack **stack_a);

// Utilitários
int     stack_size(t_stack *stack);
int     get_min_index(t_stack *stack);
int     get_max_index(t_stack *stack);
void    assign_index(t_stack *stack);
void    assign_positions(t_stack **stack);
t_stack *get_bottom(t_stack *stack);
void    stack_add_back(t_stack **stack, t_stack *new);
t_stack *create_node(int value);

#endif
