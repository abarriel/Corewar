#include "vm.h"

int  exec_live(void *core, void *pro)
{

  return (1);
}

void exec_op(t_core *core, t_process *pro)
{
  int exec;

  if (pro->op->mnemonique)
    exec = pro->op->f(core, pro);
  else
    exec = 1;
  if (exec == 0)
    pro->pc = (pro->pc + pro->op->cde_oct + 1) % MEM_SIZE;
  else
    pro->pc += exec;
}
