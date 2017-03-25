/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <lcharvol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 03:31:31 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/25 07:18:13 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "libft.h"
# include "op.h"

# define CYC_SEC_ST 50

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
  size_t    weight;
  char      *comment;
  char      *prog;
  char      id[REG_SIZE];
  int       last_live;
  int       nb_live;
  t_player  *next;
}                 t_player;

typedef struct 		s_core
{
  t_process *process;
  t_player  *player;
  int       nb_player;
  char      mem[MAX_SIZE]
  int       cycle;
  int       cycle_sec;
  int       dump;
}                 t_core;

#endif
