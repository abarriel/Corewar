/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 08:19:44 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/29 10:57:40 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned char apply_mask(unsigned char cde, int arg)
{
  if (arg == 1)
    return ((cde & 192) >> 6);
  if (arg == 2)
    return ((cde & 48) >> 4);
  if (arg == 3)
    return ((cde & 12) >> 2);
  return (cde);
}

unsigned int return_arg(t_core *core, t_process *process, int mod, int index, int cde)
{
  unsigned int res;

  // ft_printf("{%d}{%02b}\n",index, cde);
  // ft_printf("{9} [%02x] - %d\n",core->mem[(index) % MEM_SIZE], index);
 if ((cde & REG_CODE) == cde)
  {
    // res = index;
  // ft_printf("{9}{%p}{%d}",process->reg[index - 1],index);
    res = 0;
    res |= core->mem[index % MEM_SIZE];
    res = chatoi(process->reg[res - 1]);
  // ft_printf("{9}{%p}",process->reg[index - 1]);
    // ft_printf("vache\n");
    return(res);
  // ft_printf("res : %08x\n", res);
  }
if ((cde & IND_CODE) == cde)
  {
    res = chatohi(&(core->mem[index & MEM_SIZE]));
    if(mod == 1)
      res %= IDX_MOD;
    res += process->pc;
  }
  if ((cde & DIR_CODE) == cde)
  {
    //      exit(0);
     if(!process->op->l_size)
     {
       res = chatoi(&(core->mem[index % MEM_SIZE])); 
    // ft_printf("{%d}{%02x}",res, core->mem[index % MEM_SIZE]);
     }
    else
    {
     res = chatohi(&(core->mem[index % MEM_SIZE]));
    }
  }
  return(res);
}

unsigned char return_good_value(unsigned char cde, t_process *process)
{
  if ((cde & REG_CODE) == REG_CODE)
    return(1);
  if ((cde & IND_CODE) == IND_CODE)
   // { ft_printf("%d - %d",cde, IND_CODE);
    return(2);
  
  if ((cde & DIR_CODE) == DIR_CODE)
  {
     if(!process->op->l_size)
       return(4);
    else
      return(2);
  }
  return (0);
}

unsigned int get_n_arg(t_core *core, t_process *process, int arg, int mod)
{
  unsigned int res;
  unsigned char cde;
  unsigned char i;
  int index;

  cde = core->mem[(process->pc + 1) % MEM_SIZE];
  cde = apply_mask(cde, arg);
  if (arg == 1)
  {
    index =  process->pc + 2;
    // if(index > )
    // ft_printf("{8}{%02x}",core->mem[(process->pc + 2) % MEM_SIZE]);
    // exit(0);
    return(return_arg(core, process, mod, index, cde));
  }
  if (arg == 2)
  {
    i = return_good_value((((core->mem[(process->pc + 1) % MEM_SIZE]) & 192)>> 6), process);
    // if(!process->op->l_size)
    //     i += 2;
    // ft_printf("{9}%d = %08b",i, cde);
    index = (process->pc + 2) + i;
    // ft_printf("{9} [%02x] - %d\n",core->mem[(index) % MEM_SIZE], index);
    // exit(0);
    return(return_arg(core, process, mod, index, cde));
  }
  if (arg == 3)
  {
    i = return_good_value((((core->mem[(process->pc + 1) % MEM_SIZE]) & 192)>> 6), process);
    i += return_good_value((((core->mem[(process->pc + 1) % MEM_SIZE]) & 48)>> 4), process);
    index = (process->pc + 2) + i;
    // ft_printf()
    return(return_arg(core, process, mod, index, cde));
  }
  return (0);
}
