/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 06:40:45 by abarriel          #+#    #+#             */
/*   Updated: 2017/04/17 23:45:15 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int real_int(unsigned int nb)
{
  if (nb < 2048)
    return (nb);
  return (nb - 4096);
}

int uns_int(int nb)
{
  ft_printf("------- %d\n", nb);
  if (nb < 0)
    return (nb + 4096);
  return (nb);
}

void insert_in_color(char *map, int index, unsigned char color, int len)
{
  int i;

  i = 0;
  while (i < len)
  {
    map[(index + i) % MEM_SIZE] = color;
    i++;
  }
}

void insert_in_reg(unsigned char *reg, int index, unsigned int cpy)
{
  // ft_printf("trois\n");
  ft_printf("%d\n", index);
  reg[index] = (cpy & 0xFF000000) >> 24;
  reg[(index + 1) % MEM_SIZE] = (cpy & 0x00FF0000) >> 16;
  reg[(index + 2) % MEM_SIZE] = (cpy & 0x0000FF00) >> 8;
  reg[(index + 3) % MEM_SIZE] = (cpy & 0x000000FF);
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
  // ft_printf("{%d}{%d}",i, dec);
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
  insert_in_reg(get_n_reg(cr, pr, 3), 0, res);
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
  insert_in_reg(get_n_reg(cr, pr, 3), 0, res);
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
  insert_in_reg(get_n_reg(cr, pr, 3), 0, res);
  return (size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 4));
}

int exec_ld(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;
  unsigned int res;

  ft_printf("%s\n", "vache");
  cr = (t_core*)core;
  pr = (t_process*)pro;
  res = get_n_arg(cr, pr, 1, 0);
  // ft_printf("{7}{%u}{%02x}\n",res, cr->mem[pr->pc % MEM_SIZE]);
  // res = chatoi(&(cr->mem[get_n_arg(cr, pr, 1, 1) % MEM_SIZE]));

  if (res == 0)
    pr->carry = 1;
  else
    pr->carry = 0;
  insert_in_reg(get_n_reg(cr, pr, 2), 0, res);
  ft_printf("\n--------------- load : %08X in : r%d ----------------------\n", res, cr->mem[pr->pc + 6]);
  return (size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 4));
}

int exec_lld(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;
  unsigned int res;

  cr = (t_core*)core;
  pr = (t_process*)pro;
  res = chatoi(&(cr->mem[(pr->pc + get_n_arg(cr, pr, 1, 0)) % MEM_SIZE]));
  if (res == 0)
    pr->carry = 1;
  else
    pr->carry = 0;
  insert_in_reg(get_n_reg(cr, pr, 2), 0, res);
  return (size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 4));
}

int exec_ldi(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;
  unsigned int res;
  int add;

  cr = (t_core*)core;
  pr = (t_process*)pro;
  add = real_int(get_n_arg(cr, pr, 1, 0) % MEM_SIZE) + real_int((get_n_arg(cr, pr, 2, 0) % MEM_SIZE));
  res = chatoi(&(cr->mem[uns_int((add % IDX_MOD) + pr->pc) % MEM_SIZE]));
  ft_printf("stock at %d + %d", (real_int(get_n_arg(cr, pr, 1, 0) % MEM_SIZE)), get_n_arg(cr, pr, 2, 0));
  ft_printf("LDI at : %08X\n", res);
  if (res == 0)
    pr->carry = 1;
  else
    pr->carry = 0;
  insert_in_reg(get_n_reg(cr, pr, 3), 0, res);
  return (size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 2));
}

int exec_lldi(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;
  unsigned int res;

  cr = (t_core*)core;
  pr = (t_process*)pro;
  res = chatoi(&(cr->mem[((pr->pc + (get_n_arg(cr, pr, 1, 1)) + get_n_arg(cr, pr, 2, 1)))]));
  if (res == 0)
    pr->carry = 1;
  else
    pr->carry = 0;
  insert_in_reg(get_n_reg(cr, pr, 3), 0, res);
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
    insert_in_reg(get_n_reg(cr, pr, 2), 0, res);
    // ft_printf("c\n");
  }
  else
  {
    //ft_printf("\nHERE\n");
    ft_printf("--------------------------------->%d\n", ((unsigned short int)(pr->pc + (short int)get_n_arg(cr, pr, 2, 1)) % MEM_SIZE) % MEM_SIZE);
    insert_in_reg(cr->mem, ((unsigned short int)(pr->pc + (short int)get_n_arg(cr, pr, 2, 1)) % MEM_SIZE) % MEM_SIZE, res);
    insert_in_color(cr->mem_c, (pr->pc + get_n_arg(cr, pr, 2, 1)) % MEM_SIZE, pr->player->nb * 10 + 1, 4);
  }
  return (size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 4));
}

int exec_sti(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;
  unsigned int res;
  int add;

  cr = (t_core*)core;
  pr = (t_process*)pro;
  res = get_n_arg(cr, pr, 1, 1);
   ft_printf("res : %08x\n", res);
   ft_printf("to have : %02x %02x %02x %02x\n", pr->reg[0][0], pr->reg[0][1], pr->reg[0][2], pr->reg[0][3]);
  // exit(0);
  if (res == 0)
    pr->carry = 1;
  else
    pr->carry = 0;
  add = real_int(get_n_arg(cr, pr, 2, 0) % MEM_SIZE) + real_int((get_n_arg(cr, pr, 3, 0) % MEM_SIZE));
  insert_in_reg(cr->mem, uns_int((add % IDX_MOD) + pr->pc) % MEM_SIZE, res);
  insert_in_color(cr->mem_c, uns_int((add % IDX_MOD) + pr->pc) % MEM_SIZE, pr->player->nb * 10 + 1, 4);

  ft_printf("here%d\n", uns_int((add % IDX_MOD) + pr->pc) % MEM_SIZE);
  ft_printf("{9}%d\n",(get_n_arg(cr, pr, 2, 0) % MEM_SIZE));
  ft_printf("{9}%d\n",(get_n_arg(cr, pr, 3, 0) % MEM_SIZE));
  ft_printf("{8}%d\n",pr->pc);
  ft_printf("{9}%d\n",(((get_n_arg(cr, pr, 2, 0) % MEM_SIZE) + (get_n_arg(cr, pr, 3, 0) % MEM_SIZE)) + pr->pc) % MEM_SIZE);
  // exit(0);
  // ft_printf("return : %d\n", size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 2));
  ft_printf("size arg: %d", size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 2));
  return (size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 2));
}

int exec_add(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;
  unsigned int res;

  cr = (t_core*)core;
  pr = (t_process*)pro;
  ft_printf("r%d + r%d\n", cr->mem[(pr->pc + 2) % MEM_SIZE], cr->mem[(pr->pc + 3) % MEM_SIZE]);
  res = chatoi(pr->reg[cr->mem[(pr->pc + 2) % MEM_SIZE] - 1]) + chatoi(pr->reg[cr->mem[(pr->pc + 3) % MEM_SIZE] - 1]);
  if (res == 0)
    pr->carry = 1;
  else
    pr->carry = 0;
  ft_printf("add : %08X\n", res);
  insert_in_reg(pr->reg[cr->mem[(pr->pc + 4) % MEM_SIZE] - 1], 0, res);
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
  insert_in_reg(pr->reg[cr->mem[(pr->pc + 4) % MEM_SIZE] - 1], 0, res);
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
  //ft_printf("{8}{%c}\n", (unsigned char)res);
  // exit(0);
  return(3);
}
