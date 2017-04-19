#include "vm.h"

int  exec_live(void *core, void *pro)
{
  t_core *cor;
  t_process *pr;
  t_player *pla;
  unsigned char id[4];
  int i;

  i = 0;
  pr = (t_process*)pro;
  cor = (t_core*)core;
  pla = cor->player;
  while (i < 4)
  {
    id[i] = cor->mem[(pr->pc + i + 1) % MEM_SIZE];
    i++;
  }
  pr->life_flag = 1;
  while (pla && !cmp_4_oct(&pla->id[0], &id[0]))
    pla = pla->next;
  if (pla)
  {
    pla->nb_live ++;
    pla->last_live = cor->cycle;
    i = 0;
    while (i < 4)
    {
      cor->mem_c[(pr->pc + i + 1) % MEM_SIZE] = pla->color * 16 + 4;
      i++;
    }
  }
  return (5);
}

unsigned char *cp_reg(unsigned char *dest, unsigned char *src)
{
  int i;

  i = 0;
  while (i < REG_SIZE)
  {
    dest[i] = src[i];
    i++;
  }
  return (dest);
}

t_process *dup_process(t_process *pro)
{
  t_process *new;
  int i;

  new = (t_process*)malloc(sizeof(t_process));
  new->pc = pro->pc;
  new->life_flag = pro->life_flag;
  new->cycle_left = 0;
  new->op = NULL;
  new->carry = pro->carry;
  new->player = pro->player;
  new->reg = (unsigned char**)malloc(sizeof(unsigned char *) * REG_NUMBER);
  i = 0;
  while (i < REG_NUMBER)
  {
    new->reg[i] = (unsigned char*)malloc(REG_SIZE * sizeof(unsigned char));
    new->reg[i] = cp_reg(new->reg[i], pro->reg[i]);
    i++;
  }
  return (new);
}

int  exec_lfork(void *core, void *pro)
{
  t_core *cor;
  t_process *pr;
  t_process *new;
  unsigned short int jmp;

  pr = (t_process*)pro;
  cor = (t_core*)core;
  new = dup_process(pr);
  jmp = 0;
  jmp += (unsigned int)(cor->mem[(pr->pc + 1) % MEM_SIZE]) * 256;
  jmp += (unsigned int)(cor->mem[(pr->pc + 2) % MEM_SIZE]);
  new->pc = (new->pc + (jmp % MEM_SIZE)) % MEM_SIZE;
  cor->mem_c[new->pc] = 16 * new->player->color + 1;
  new->next = cor->process;
  cor->process = new;
  return (3);
}

int  exec_fork(void *core, void *pro)
{
  t_core *cor;
  t_process *pr;
  t_process *new;
  unsigned short int jmp;

  pr = (t_process*)pro;
  cor = (t_core*)core;
  new = dup_process(pr);
  jmp = 0;
  jmp += ((unsigned int)(cor->mem[(pr->pc + 1)]) * 256);
  jmp += (unsigned int)(cor->mem[(pr->pc + 2)]);
  new->pc = (new->pc + (((short int)jmp % MEM_SIZE) % IDX_MOD)) % MEM_SIZE;
  cor->mem_c[new->pc] = 16 * new->player->color + 1;
  new->next = cor->process;
  cor->process = new;
  return (3);
}

int  exec_zjmp(void *core, void *pro)
{
  t_core *cor;
  t_process *pr;
  unsigned short int jmp;

  pr = (t_process*)pro;
  if (pr->carry == 0)
    return (3);
  jmp = 0;
  cor = (t_core*)core;
  jmp += (unsigned int)(cor->mem[(pr->pc + 1) % MEM_SIZE]) * 256;
  jmp += (unsigned int)(cor->mem[(pr->pc + 2) % MEM_SIZE]);
  cor->mem_c[pr->pc] = pr->player->color * 16;
  pr->pc = (pr->pc + (uns_int(real_int(jmp % MEM_SIZE) % IDX_MOD))) % MEM_SIZE;
  //if ((real_int(jmp % MEM_SIZE) < -IDX_MOD) || (real_int(jmp % MEM_SIZE) > IDX_MOD))
  return (0);
}

void exec_op(t_core *core, t_process *pro)
{
  int exec;

  if (pro->op->mnemonique)
  {
    //  ft_printf("op : %s at cycle : %d from player : %d\n\n", pro->op->mnemonique, core->cycle, pro->player->nb);

    //ft_printf("{9}\nReturn Check  de %s=[%d]\n",pro->op->mnemonique, checker_arg(core, pro));
    // exit(0);
    if (pro->op->cde_oct == 0 || checker_arg(core, pro) == 1)
    {
      exec = pro->op->f(core, pro);
    }
    else
      exec = -1;
  }
  else
    exec = 1;
  if (exec == -1)
  {
    core->mem_c[pro->pc] = pro->player->color * 16;
    if (pro->op->cde_oct == 1)
      pro->pc = (pro->pc + size_args(core->mem[(pro->pc + 1) % MEM_SIZE], 4 - 2 * pro->op->l_size)) % MEM_SIZE;
    else
      pro->pc = (pro->pc + 1) % MEM_SIZE;
  }
  else
  {
    core->mem_c[pro->pc] = pro->player->color * 16;
    pro->pc = (pro->pc + exec) % MEM_SIZE;
  }
//  print_map(core);

}
