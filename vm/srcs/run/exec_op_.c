/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 06:40:45 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/29 08:40:31 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned int chatohi()
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
  return (size_arg(cr, pr));
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
  return (size_arg(cr, pr));
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
  return (size_arg(cr, pr));
}

int exec_ld(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;
  unsigned int res;

  res = chatoi(cr->mem[get_n_arg(cr, pr, 1, 1)]);
  if (get_n_arg(cr, pr, 1, 1) == 0)
    pr->carry = 1;
  else
    pr->carry = 0;
  insert_in_reg(get_n_reg(cr, pr, 2), res);
  return (size_arg(cr, pr))
}

int exec_lld(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;
  unsigned int res;

  res = chatoi(cr->mem[get_n_arg(cr, pr, 1, 0)]);
  if (get_n_arg(cr, pr, 1, 1) == 0)
    pr->carry = 1;
  else
    pr->carry = 0;
  insert_in_reg(get_n_reg(cr, pr, 2), res);
  return (size_arg(cr, pr))
}

int exec_ldi(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;
  unsigned int res;

  res = chatoi(cr->mem[get_n_arg(cr, pr, 1, 1) + get_n_arg(cr, pr, 2, 1)]);
  if (get_n_arg(cr, pr, 1, 1) + get_n_arg(cr, pr, 2, 1) == 0)
    pr->carry = 1;
  else
    pr->carry = 0;
  insert_in_reg(get_n_reg(cr, pr, 3), res);
  return (size_arg(cr, pr))
}

int exec_ldi(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;
  unsigned int res;

  res = chatoi(cr->mem[get_n_arg(cr, pr, 1, 0) + get_n_arg(cr, pr, 2, 0)]);
  if (get_n_arg(cr, pr, 1, 1) + get_n_arg(cr, pr, 2, 1) == 0)
    pr->carry = 1;
  else
    pr->carry = 0;
  insert_in_reg(get_n_reg(cr, pr, 3), res);
  return (size_arg(cr, pr))
}

int exec_st(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;
  unsigned int res;
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

int exec_lld(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;

  cr = (t_core*)core;
  pr = (t_process*)pro;

  // exit(0);
  return (1);
}
