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

void moove_last(t_core *core, t_process *pro)
{
  t_process *tmp;
  t_process *last;

  last = NULL;
  tmp = ore->process;
  while (tmp != pro)
  {
    last = tmp;
    tmp = tmp->next;
  }
  if (last)
    last->next = tmp->next;
  else
    core->process = tmp;
  last = tmp;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = last;
}

void exec(t_core *core)
{
  t_process *pro;

  pro = core->process;
  while (pro)
  {
    if (pro->op && pro->cycle_left == 0)
    {
      exec_op(core, pro);
      ft_printf("op : %s at cycle : %d from plaayer : %d\n", pro->op->mnemonique, core->cycle, pro->player->nb);
      pro->op = NULL;
      moove_last(core, pro);
    }
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
  free(pro->mnemonique);
  free(pro->comment);
  free(pro);
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
        *pro = tmp;
      free_process(&tmp);
      tmp = NULL;
    }
    tmp->life_flag = 0;
    last = tmp;
    tmp = tmp->next;
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
	while (core->nb_player != 0)
	{
    core->cycle += 1;
		lunch_op(core);
		decrease(core);
		exec(core);
    die_check(core);
	}
}
