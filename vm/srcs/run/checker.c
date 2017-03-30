/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 06:22:52 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/30 17:45:12 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"


int check_all_arg(t_core *core, t_process *pro, int index, int *ok)
{

  // decal = 0;
    // ft_printf("{8}[%d] - [%b]   ",*ok,index);
     // ft_printf("{4}[%02x]\n",core->mem[(pro->pc + 1  + *ok) % MEM_SIZE]);
  if ((index & REG_CODE) == REG_CODE)
  {
    // ft_printf("{8}[%02x]",core->mem[(pro->pc + 1 + *ok) % MEM_SIZE]);
    // ft_printf("{8}[%08b]\n",index);
    if (core->mem[(pro->pc + 1 + *ok) % MEM_SIZE] > REG_NUMBER)
    {
      // ft_printf("REG NUMBER TROP GRAND");
      return(0);
    }
    (*ok)++;
    // else
    //   (*ok)++;
  }
  else if ((index & DIR_CODE) == DIR_CODE)
  {
    // ft_printf("{8}[%02x]",core->mem[(pro->pc + 1 + i) % MEM_SIZE]);
    // ft_printf("{8}[%08b]\n",index);
    // ft_printf("{RED}[%02x]\n",core->mem[(pro->pc + 1 + i + *ok) % MEM_SIZE]);
    if(!pro->op->l_size)
    {
      // ft_printf("{8} 4[%08b] - ",index);
        // ft_printf("{RED}4");
      (*ok) += 4;
      // ft_printf("{RED}[%02x]\n",core->mem[(pro->pc + 1 + i + *ok) % MEM_SIZE]);
    }
    else
    {
        // ft_printf("{RED}2");
      (*ok) += 2;
      // exit(0);
    }
      // ft_printf("T_DIR");
  }
  else if ((index & IND_CODE) == IND_CODE)
  {
    // ft_printf("{8}[%02x]",core->mem[(pro->pc + 1 + i) % MEM_SIZE]);
    // ft_printf("{8}[%08b]\n",index);
    // ft_printf("{8}[%08b]",index);
    (*ok) += 2;
  }
    // exit(0);
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
  // ft_printf("{RED}\n[%02x]\n",index);
  while(arg != pro->op->nbr_args)
  {
    // ft_printf("{9}[%d]",arg);
    cde = apply_mask(index, arg + 1);
    if(cde & pro->op->type[arg])
    {
      if(!(check_all_arg(core,pro, cde, &ok)))
        return(0);
    }
    else
     return(0);
   arg++;

 }
 return(1);
}

int checker_arg(t_core *core, t_process *pro)
{
	int pc;

	pc = pro->pc;
  // ft_printf("{8}%02x- ",core->mem[(pro->pc) % MEM_SIZE]);
  if (pro->op->cde_oct == 1)
  {
    // ft_printf("{9}%s - ",pro->op->mnemonique);
    if(!(check_cde_oct(core, pro)))
    {
      // exit(0);
     return(0);
    }
   pc += 1;
		// core->mem[(pro->pc + 2) % MEM_SIZE]
 }
	// if(!(check_arg(core, pro, pc)))
	// 	return(0);
  // ft_printf("{5}%d",pro->op->type[MAX_ARGS_NUMBER]);
  // exit(0);
	// return (0);
 return (1);
}
