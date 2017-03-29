/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 06:40:45 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/29 11:04:56 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned int chatohi(unsigned char *str)
{
  unsigned int final;

	final = 0;
  final |= ((unsigned int)(str)[0] << 8);
	final |= ((unsigned int)(str)[1]);
  return (final);
}

unsigned int chatoi(unsigned char *str)
{
  unsigned int final;

	final = 0;
	final |= ((unsigned int)(str)[0] << 24);
	final |= ((unsigned int)(str)[1] << 16);
	final |= ((unsigned int)(str)[2] << 8);
	final |= ((unsigned int)(str)[3]);
	return (final);
}

void insert_in_reg(unsigned char *reg, unsigned int cpy)
{
  reg[0] = (cpy & 0xFF000000) >> 24;
  reg[1] = (cpy & 0x00FF0000) >> 16;
  reg[2] = (cpy & 0x0000FF00) >> 8;
  reg[3] = (cpy & 0x000000FF);
}

int size_arg(unsigned char oc_cde, int d_size, int i)
{
  unsigned int cde;

  if (i == 1)
    cde = (cde & 192) >> 6;
  else if (i == 2)
    cde = (cde & 48) >> 4;
  else
    cde = (cde & 12) >> 2;
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
  res += size_arg(oc_cde, d_size, 2);
  res += size_arg(oc_cde, d_size, 3);
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
  reg = process->reg[core->mem[(process->pc + 2 + dec) % MEM_SIZE]];
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
  res = chatoi(&(cr->mem[get_n_arg(cr, pr, 1, 1) % MEM_SIZE]));
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
    insert_in_reg(get_n_reg(cr, pr, 3), res);
  else
    insert_in_reg(&cr->mem[get_n_arg(cr, pr, 2, 1) % MEM_SIZE], res);
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
  ft_printf("2\n");
  if (res == 0)
    pr->carry = 1;
  else
    pr->carry = 0;
  insert_in_reg(&cr->mem[(get_n_arg(cr, pr, 2, 1) + get_n_arg(cr, pr, 3, 1)) % MEM_SIZE], res);
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
  ft_printf("%c", (unsigned char)res);
  return(3);
}
