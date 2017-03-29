#include "vm.h"

void insert_op(t_process *pro, unsigned char *mem, t_op *tab_op)
{
  if (mem[pro->pc] < 17 && mem[pro->pc] > 0)
    pro->op = &tab_op[mem[pro->pc] - 1];
  else
    pro->op = &tab_op[16];
  pro->cycle_left = pro->op->nbr_cycles;
}

void lunch_op(t_core *core)
{
  t_process *pro;

  pro = core->process;
  while (pro)
  {
    if (pro->op == NULL)
      insert_op(pro, core->mem, core->op);
    pro = pro->next;
  }
}

void decrease(t_core *core)
{
  t_process *pro;

  pro = core->process;
  while (pro)
  {
    if (pro->cycle_left)
      pro->cycle_left -= 1;
    pro = pro->next;
  }
}

t_process *moove_last(t_core *core, t_process *pro)
{
  t_process *tmp;
  t_process *last;
  t_process *res;

  if (!core->process->next)
    return (core->process);
  last = NULL;
  tmp = core->process;
  while (tmp != pro)
  {
    last = tmp;
    tmp = tmp->next;
  }
  res = tmp->next;
  if (!res)
    return (res);
  if (last)
    last->next = tmp->next;
  else
    core->process = tmp->next;
  last = tmp;
  while (tmp && tmp->next)
    tmp = tmp->next;
  tmp->next = last;
  last->next = NULL;
  return (res);
}

void exec(t_core *core)
{
  t_process *pro;

  pro = core->process;
  while (pro)
  {
    if (pro->op != NULL && pro->cycle_left == 0)
    {
      // print_map(core);
      ft_printf("op : %s at cycle : %d from player : %d\n", pro->op->mnemonique, core->cycle, pro->player->nb);
      exec_op(core, pro);
      // print_map(core);
      ft_printf("\n");
      pro->op = NULL;
      pro = moove_last(core, pro);
    }
    else
      pro = pro->next;
  }
}

int count_live(t_player *players)
{
  t_player *tmp;
  int res;

  res = 0;
  tmp = players;
  while (tmp)
  {
    res += tmp->nb_live;
    tmp->nb_live = 0;
    tmp = tmp->next;
  }
  return (res);
}

void free_process(t_process **pro)
{
  t_process *tmp;
  int i;

  i = 0;
  tmp = *pro;
  while (i < REG_NUMBER)
  {
    free(tmp->reg[i]);
    i++;
  }
  free(tmp->reg);
  free(tmp);
  tmp = NULL;
}

void check_proces(t_process **pro)
{
  t_process *tmp;
  t_process *last;

  last = NULL;
  tmp = *pro;
  while (tmp)
  {
    if (tmp->life_flag == 0)
    {
      if (last)
        last->next = tmp->next;
      else
        *pro = tmp->next;
      free_process(&tmp);
    }
    else
    {
      tmp->life_flag = 0;
      last = tmp;
    }
    if (tmp)
      tmp = tmp->next;
    else
      tmp = *pro;
  }
}

void die_check(t_core *core)
{
  if ((core->cycle - core->last_check) % core->die_cycle == 0)
  {
    core->nb_player = count_live(core->player);
    if (core->nb_player >= NBR_LIVE)
      core->die_cycle -= CYCLE_DELTA;
    check_proces(&core->process);
    core->last_check = core->cycle;
  }
}

void run(t_core *core)
{
  print_map(core);
	while (core->nb_player != 0)
	{
    //print_map(core);
    core->cycle += 1;
		lunch_op(core);
		decrease(core);
		exec(core);
    die_check(core);
	}
}
