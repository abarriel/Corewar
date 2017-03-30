#include "vm.h"

void		init_op(void **res)
{
	static const t_op op[] = {{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, &exec_live},
		{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, &exec_ld},
		{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, &exec_st},
		{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, &exec_add},
		{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0, &exec_sub},
		{"and", 3, {RDI, RID, T_REG}, 6, 6, "r1,r2,r3. r1&r2 -> r3", 1, 0, &exec_and},
		{"or", 3, {RID, RID, T_REG}, 7, 6, "r1,r2,r3. r1 | r2 -> r3", 1, 0, &exec_or},
		{"xor", 3, {RID, RID, T_REG}, 8, 6, "r1,r2,r3. r1^r2 -> r3", 1, 0, &exec_xor},
		{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, &exec_zjmp},
		{"ldi", 3, {RDI, T_DIR | T_REG, T_REG}, 10, 25, "load index", 1, 1, &exec_ldi},
		{"sti", 3, {T_REG, RDI, T_DIR | T_REG}, 11, 25, "store index", 1, 1, &exec_sti},
		{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, &exec_fork},
		{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, &exec_lld},
		{"lldi", 3, {RDI, T_DIR | T_REG, T_REG}, 14, 50, "lng lod idx", 1, 1, &exec_lldi},
		{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, &exec_lfork},
		{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, &exec_aff},
		{0, 0, {0}, 0, 0, 0, 0, 0, NULL}};

	*res = (void*)op;
}

t_op		*get_op(void)
{
	void **get_op;
	t_op *res;

	*get_op = NULL;
	init_op(get_op);
	res = (t_op*)*get_op;
	return (res);
}

t_process *init_process(t_player *players, int nb_player, int i)
{
	t_process *res;
	unsigned char *reg;
	int j;

	if (!(res = malloc(sizeof(t_process))))
		exit(write(1, "Bad malloc\n", 11));
	res->pc = (int)(i * (MEM_SIZE / nb_player));
	res->player = players;
	res->cycle_left = 0;
	res->life_flag = 0;
	j = 0;
	res->reg = (unsigned char**)malloc(sizeof(unsigned char *) * REG_NUMBER);
	while (j < REG_NUMBER)
	{
		res->reg[j] = (unsigned char*)malloc(REG_SIZE * sizeof(unsigned char));
		ft_bzero(res->reg[j], REG_SIZE);
		j++;
	}
	ft_memcpy(res->reg[0], players->id, 4);
	res->carry = 0;
	res->op = NULL;
	res->next = NULL;
	if (players->next)
		res->next = init_process(players->next, nb_player, i + 1);
	return (res);
}

void	init_player(t_player *p, t_core *c)
{
	size_t petit;

	petit = 0xFFFFFFFF - (c->nb_player);
	p->nb = c->nb_player + 1;
	p->magic = 0;
	p->name = NULL;
	p->weight = 0;
	p->comment = NULL;
	p->prog = NULL;
	p->last_live = 0;
	p->nb_live = 0;
	petit = swap_st(petit);
	ft_memcpy(p->id, &petit, 4);
	p->next = NULL;
	p->name = ft_strnew(PROG_NAME_LENGTH + 1);
	p->comment = ft_strnew(COMMENT_LENGTH + 1);
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
		//ft_bzero(&core->mem_c[tmp_r->pc + tmp_p->weight], 10);
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
	ft_bzero(res->mem, MEM_SIZE);
	ft_bzero(res->mem_c, MEM_SIZE);
	res->player = NULL;
	res->process = NULL;
	res->dump = -1;
	res->last_check = 0;
	res->die_cycle = CYCLE_TO_DIE;
	res->op = get_op();
	res->visu = 0;
	res->cycle = 0;
	res->run = 1;
	res->cycle_sec = CYC_SEC_ST;
	return (res);
}
