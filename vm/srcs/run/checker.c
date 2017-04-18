/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 06:22:52 by abarriel          #+#    #+#             */
/*   Updated: 2017/04/17 23:59:21 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"


int check_all_arg(t_core *core, t_process *pro, int index, int *ok)
{

   ft_printf("{8}[%d] - [%b]   ",*ok,index);
  //   ft_printf("{4}[%02x]\n",core->mem[(pro->pc + 1  + *ok) % MEM_SIZE]);
  if (index == REG_CODE)
  {
    if (core->mem[(pro->pc + 1 + *ok) % MEM_SIZE] > REG_NUMBER)
    {
      ft_printf("REG NUMBER TROP GRAND\n");
      return(0);
    }
    if (core->mem[(pro->pc + 1 + *ok) % MEM_SIZE] < 1)
    {
      ft_printf("REG NUMBER TROP PETIT\n");
      return (0);
    }
    (*ok)++;
  }
  else if (index == DIR_CODE)
  {
    if(!pro->op->l_size)
          (*ok) += 4;
       else
     (*ok) += 2;
  }
  else if (index == IND_CODE)
    (*ok) += 2;
  return (1);
}

int check_cde_oct(t_core *core, t_process *pro)
{
  int ok;
  unsigned char cde;
  unsigned char index;
  int arg;
  int decalage;
  int mask;

  arg = 0;
  ok = 1;
  index = core->mem[(pro->pc + 1) % MEM_SIZE];
  ft_printf("here [%08b]\n", index);
  // if (index == 255)
  //   return (0);
  while(arg != pro->op->nbr_args)
  {
    cde = apply_mask(index, arg + 1);
    // ft_printf("{9}%x",  pro->op->nbr_args);
    ft_printf("{9}[%d - %d][%d][%d][%s]",  cde, pro->op->type[0],cde & pro->op->type[arg],arg,pro->op->mnemonique );

    if(cde & pro->op->type[arg])
    {
      // ft_printf("ddd");
      if(!(check_all_arg(core,pro, cde, &ok)))
      {
      return(0);
      }
    }
    else
     return(0);
   arg++;
 } 
 if(pro->op->nbr_args == 2)
    {
      if(15 & index)
        return 0;
    }
  if(pro->op->nbr_args == 1)
    {
      if(63 & index)
        return 0;
    }
     if(pro->op->nbr_args == 3)
    {
      if(3 & index)
        return 0;
    }
 return(1);
}

int checker_arg(t_core *core, t_process *pro)
{
	int pc;

	pc = pro->pc;
  ft_printf("-------------------------->     {8}%02x- ",core->mem[(pro->pc) % MEM_SIZE]);
  if (pro->op->cde_oct == 1)
  {
    if(!(check_cde_oct(core, pro)))
     return(0);
   ft_printf("{1}%s","sorti");
   pc += 1;
 }
 return (1);
}
