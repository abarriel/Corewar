#include "vm.h"

t_core *init_core(char **players)
{
	t_core *res;

	if (!(res = malloc(sizeof(t_core))))
		exit(write(1, "Bad malloc\n", 11));
	ft_bzero(res->mem, MAX_SIZE);
	res->players = init_player(players);
	res->process = NULL;
	res->cycles = 0;
	res->cycles_sec = 50;
	return (res);
}
