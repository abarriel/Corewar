#include "vm.h"

t_process *init_process(t_player *players, int nb_player, int i)
{
	t_process *res;

	if (!(res = malloc(sizeof(t_process))))
		exit(write(1, "Bad malloc\n", 11));
	res->pc = i * (MEM_SIZE / nb_player);
	res->cycle_left = 0;
	ft_bzero(res->reg, REG_NUMBER * REG_SIZE);
	ft_memcpy(players->id, res->reg[0], 4);
	res->carry = 0;
	res->next = NULL;
	if (players->next)
		res->next = init_process(players->next, nb_player, i + 1);
	return (res);
}

void	init_player(t_player *p)
{
  p->magic = 0;
  p->name = NULL;
  p->weight = 0;
  p->comment = NULL;
  p->prog = NULL;
  p->last_live = 0;
  p->nb_live = 0;
}

void  init_core(t_core *core)
{
	t_player *tmp_p;
	t_process *tmp_r;
	int i;

	core->process = init_process(core->player, core->nb_player, 0);
	tmp_p = core->player;
	tmp_r = core->process;
	i = 1;
	while (tmp_p)
	{
		ft_memcpy(&core->mem[tmp_r->pc], tmp_p->prog, tmp_p->weight);
		ft_memset(&core->mem_c[tmp_r->pc], i, tmp_p->weight);
		core->mem_c[tmp_r->pc] = 10 * i;
		tmp_p = tmp_p->next;
		tmp_r = tmp_r->next;
		i++;
	}
}

t_core *new_core()
{
	t_core *res;

	if (!(res = malloc(sizeof(t_core))))
		exit(write(1, "Bad malloc\n", 11));
	res->player = NULL;
	ft_bzero(res->mem, MEM_SIZE);
	ft_bzero(res->mem_c, MEM_SIZE);
	res->process = NULL;
	res->dump = -1;
	res->visu = 0;
	res->cycle = 0;
	res->run = 1;
	res->cycle_sec = CYC_SEC_ST;
	return (res);
}
