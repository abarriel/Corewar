#include "vm.h"

int  exec_live(void *core, void *pro)
{
  return (1);
}

void exec_op(t_core *core, t_process *pro)
{
  ft_printf("res : %d\n", pro->op->f(core, pro));
}
