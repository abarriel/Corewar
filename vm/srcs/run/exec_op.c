#include "vm.h"

int cmp_4_oct(unsigned char *one, unsigned char *two)
{
  if (one[0] == two[0] && one[1] == two[1] &&
    one[2] == two[2] && one[3] == two[3])
    return (1);
  return(0);
}

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
  }
  return (5);
}

void cp_reg(unsigned char *dest, unsigned char *src)
{
  int i;

  i = 0;
  while (i < REG_SIZE)
  {
    dest[i] = src[i];
    i++;
  }
}

t_process *dup_process(t_process *pro)
{
  t_process *new;
  int i;

  new = (t_process*)malloc(sizeof(t_process));
  new->pc = pro->pc;
  new->life_flag = 0;
  new->cycle_left = 0;
  new->op = NULL;
  new->carry = pro->carry;
  new->player = pro->player;
  new->reg = (unsigned char**)malloc(sizeof(unsigned char *) * REG_NUMBER);
  i = 0;
  while (i < REG_NUMBER)
  {
    new->reg[i] = (unsigned char*)malloc(REG_SIZE * sizeof(unsigned char));
    cp_reg(new->reg[i], pro->reg[i]);
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
  jmp += (unsigned int)(cor->mem[(pr->pc + 1) % MEM_SIZE]) * 256;
  jmp += (unsigned int)(cor->mem[(pr->pc + 2) % MEM_SIZE]);
  new->pc = (new->pc + (jmp % MEM_SIZE)) % MEM_SIZE;
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
  jmp += (unsigned int)(cor->mem[(pr->pc + 1) % MEM_SIZE]) * 256;
  jmp += (unsigned int)(cor->mem[(pr->pc + 2) % MEM_SIZE]);
  new->pc = (new->pc + ((jmp % MEM_SIZE) % IDX_MOD)) % MEM_SIZE;
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
  //if (pr->carry == 0)
  //  return (3);
  jmp = 0;
  cor = (t_core*)core;
  jmp += (unsigned int)(cor->mem[(pr->pc + 1) % MEM_SIZE]) * 256;
  jmp += (unsigned int)(cor->mem[(pr->pc + 2) % MEM_SIZE]);
  pr->pc = (pr->pc + (jmp % MEM_SIZE)) % MEM_SIZE;
  return (0);
}

void exec_op(t_core *core, t_process *pro)
{
  int exec;

  if (pro->op->mnemonique)
  {
    ft_printf("{9}\n\nReturn Check  de %s=[%d]\n",pro->op->mnemonique, checker_arg(core, pro));
    // exit(0);
    if (pro->op->cde_oct == 0 || checker_arg(core, pro))
    {
     print_map(core);
      exec = pro->op->f(core, pro);
    }
    else
      exec = -1;
  }
  else
    exec = 1;
  if (exec == -1)
    pro->pc = (pro->pc + pro->op->cde_oct + 1) % MEM_SIZE;
  else
    pro->pc += exec;
}
