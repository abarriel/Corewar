/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 06:40:45 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/29 11:51:10 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void insert_in_reg(unsigned char *reg, unsigned int cpy)
{
  // ft_printf("trois\n");
  // ft_printf("%02x\n", reg[0]);
  reg[0] = (cpy & 0xFF000000) >> 24;
  reg[1] = (cpy & 0x00FF0000) >> 16;
  reg[2] = (cpy & 0x0000FF00) >> 8;
  reg[3] = (cpy & 0x000000FF);
  // ft_printf("quatre\n");
}

int size_arg(unsigned char oc_cde, int d_size, int i)
{
  unsigned int cde;

  if (i == 1)
    cde = (oc_cde & 192) >> 6;
  else if (i == 2)
    cde = (oc_cde & 48) >> 4;
  else
    cde = (oc_cde & 12) >> 2;
  // ft_printf("cde : %02x\n", oc_cde);
  if (cde == 1)
    return (1);
  if (cde == 3)
    return (2);
  return (d_size);
}

int size_args(unsigned char oc_cde, int d_size)
{
  int res;

  res = 0;
  res += size_arg(oc_cde, d_size, 1);
  // ft_printf("1 : %d\n", res);
  res += size_arg(oc_cde, d_size, 2);
  // ft_printf("2 : %d\n", res);
  if(oc_cde & 12)
  {
  res += size_arg(oc_cde, d_size, 3);
  // ft_printf("3 : %d\n", res);
  }
  return (2 + res);
}

unsigned char *get_n_reg(t_core *core, t_process *process, int arg)
{
  unsigned char *reg;
  int dec;
  int i;

  i = 1;
  dec = 0;
  while (i < arg)
  {
    dec += size_arg(core->mem[(process->pc + 1) % MEM_SIZE], 4 - 2 * process->op->l_size, i);
    i++;
  }
  // ft_printf("{%d}{%d}",i,dec);
  reg = process->reg[core->mem[(process->pc + 2 + dec) % MEM_SIZE] - 1];
  // ft_printf("%d\n", core->mem[(process->pc + 2 + dec) % MEM_SIZE] - 1);
  return (reg);
}

int exec_and(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;
  unsigned int res;

  cr = (t_core*)core;
  pr = (t_process*)pro;
  res = get_n_arg(cr, pr, 1, 1) & get_n_arg(cr, pr, 2, 1);
  // ft_printf("res : %08x | %08x\n", get_n_arg(cr, pr, 1, 1), get_n_arg(cr, pr, 2, 1));
  // exit(0);
  if (res == 0)
    pr->carry = 1;
  else
    pr->carry = 0;
  insert_in_reg(get_n_reg(cr, pr, 3), res);
  return (size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 4));
}

int exec_or(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;
  unsigned int res;

  cr = (t_core*)core;
  pr = (t_process*)pro;
  res = get_n_arg(cr, pr, 1, 1) | get_n_arg(cr, pr, 2, 1);
  if (res == 0)
    pr->carry = 1;
  else
    pr->carry = 0;
  insert_in_reg(get_n_reg(cr, pr, 3), res);
  return (size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 4));
}

int exec_xor(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;
  unsigned int res;

  cr = (t_core*)core;
  pr = (t_process*)pro;
  res = get_n_arg(cr, pr, 1, 1) ^ get_n_arg(cr, pr, 2, 1);
  if (res == 0)
    pr->carry = 1;
  else
    pr->carry = 0;
  insert_in_reg(get_n_reg(cr, pr, 3), res);
  return (size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 4));
}

int exec_ld(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;
  unsigned int res;

  cr = (t_core*)core;
  pr = (t_process*)pro;
  res = get_n_arg(cr,pr,1,1);
  // ft_printf("{7}{%u}{%02x}\n",res, cr->mem[pr->pc % MEM_SIZE]);
  // res = chatoi(&(cr->mem[get_n_arg(cr, pr, 1, 1) % MEM_SIZE]));
 
  if (get_n_arg(cr, pr, 1, 1) == 0)
    pr->carry = 1;
  else
    pr->carry = 0;
  insert_in_reg(get_n_reg(cr, pr, 2), res);
  return (size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 4));
}

int exec_lld(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;
  unsigned int res;

  cr = (t_core*)core;
  pr = (t_process*)pro;
  res = chatoi(&(cr->mem[get_n_arg(cr, pr, 1, 0) & MEM_SIZE]));
  if (get_n_arg(cr, pr, 1, 1) == 0)
    pr->carry = 1;
  else
    pr->carry = 0;
  insert_in_reg(get_n_reg(cr, pr, 2), res);
  return (size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 4));
}

int exec_ldi(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;
  unsigned int res;

  cr = (t_core*)core;
  pr = (t_process*)pro;
  res = chatoi(&(cr->mem[(get_n_arg(cr, pr, 1, 1) + get_n_arg(cr, pr, 2, 1)) % MEM_SIZE]));
  if (get_n_arg(cr, pr, 1, 1) + get_n_arg(cr, pr, 2, 1) == 0)
    pr->carry = 1;
  else
    pr->carry = 0;
  insert_in_reg(get_n_reg(cr, pr, 3), res);
  return (size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 2));
}

int exec_lldi(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;
  unsigned int res;

  cr = (t_core*)core;
  pr = (t_process*)pro;
  res = chatoi(&(cr->mem[(get_n_arg(cr, pr, 1, 0) + get_n_arg(cr, pr, 2, 0)) % MEM_SIZE]));
  if (get_n_arg(cr, pr, 1, 1) + get_n_arg(cr, pr, 2, 1) == 0)
    pr->carry = 1;
  else
    pr->carry = 0;
  insert_in_reg(get_n_reg(cr, pr, 3), res);
  return (size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 2));
}

int exec_st(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;
  unsigned int res;

  cr = (t_core*)core;
  pr = (t_process*)pro;
  res = get_n_arg(cr, pr, 1, 1);
  if (res == 0)
    pr->carry = 1;
  else
    pr->carry = 0;  
  if (cr->mem[(pr->pc + 1) % MEM_SIZE] == (unsigned char)80)
  {
    // ft_printf("d\n");
    insert_in_reg(get_n_reg(cr, pr, 2), res);
    // ft_printf("c\n");
  }
  else
  {
    insert_in_reg(&cr->mem[get_n_arg(cr, pr, 2, 1) % MEM_SIZE], res);
  }
  return (size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 4));
}

int exec_sti(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;
  unsigned int res;

  cr = (t_core*)core;
  pr = (t_process*)pro;
  res = get_n_arg(cr, pr, 1, 1);
  // ft_printf("res : %08x\n", res);
  // ft_printf("to have : %02x %02x %02x %02x\n", pr->reg[0][0], pr->reg[0][1], pr->reg[0][2], pr->reg[0][3]);
  // exit(0);
  if (res == 0)
    pr->carry = 1;
  else
    pr->carry = 0;
  insert_in_reg(&cr->mem[(get_n_arg(cr, pr, 2, 1) + get_n_arg(cr, pr, 3, 1)) % MEM_SIZE], res);
  // ft_printf("{7}2Arg(15) =  %d\n",get_n_arg(cr, pr, 2, 1));
  // ft_printf("{7}3Arg(1) =  %d\n",get_n_arg(cr, pr, 3, 1));
  // ft_printf("{9}%d\n",(get_n_arg(cr, pr, 2, 1) + get_n_arg(cr, pr, 3, 1)));
  // exit(0);
  // ft_printf("return : %d\n", size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 2));
  return (size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 2));
}

int exec_add(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;
  unsigned int res;

  cr = (t_core*)core;
  pr = (t_process*)pro;
  res = chatoi(pr->reg[cr->mem[(pr->pc + 2) % MEM_SIZE] - 1]) + chatoi(pr->reg[cr->mem[(pr->pc + 3) % MEM_SIZE] - 1]);
  if (res == 0)
    pr->carry = 1;
  else
    pr->carry = 0;
  insert_in_reg(pr->reg[cr->mem[(pr->pc + 4) % MEM_SIZE] - 1], res);
  return (5);
}

int exec_sub(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;
  unsigned int res;

  cr = (t_core*)core;
  pr = (t_process*)pro;
  res = chatoi(pr->reg[cr->mem[(pr->pc + 2) % MEM_SIZE] - 1]) - chatoi(pr->reg[cr->mem[(pr->pc + 3) % MEM_SIZE] - 1]);
  if (res == 0)
    pr->carry = 1;
  else
    pr->carry = 0;
  insert_in_reg(pr->reg[cr->mem[(pr->pc + 4) % MEM_SIZE] - 1], res);
  return (5);
}

int exec_aff(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;
  unsigned int res;

  cr = (t_core*)core;
  pr = (t_process*)pro;
  res = chatoi(pr->reg[cr->mem[(pr->pc + 2) % MEM_SIZE] - 1]) % 256;
  // write(1,&res,1);
  ft_printf("{8}{%c}\n", (unsigned char)res);
  // exit(0);
  return(3);
}
