/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <lcharvol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 03:31:31 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/25 04:55:41 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "libft.h"
# include "op.h"

typedef struct 		s_process
{
  char      pc;
  int       cycle_left;
	char 			reg[REG_NUMBER][REG_SIZE];
	char			carry;
  struct s_process *next;
}					t_process;

typedef struct    s_player
{
  char      *name;
  int       weight;
  char      *comment;
  char      id[REG_SIZE];
  int       last_live;
  int       nb_live;
  t_player  *next;
}                 t_player;

typedef struct 		s_core
{
  t_process *process;
  t_player  *player;
  int       mem[MAX_SIZE]
  int       act_cycle;
  int       cycle_sec;
}                 t_core;

#endif
