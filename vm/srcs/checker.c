/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 06:22:52 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/28 06:23:04 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int check_cde_oct(t_core *core, t_process *pro)
{
	unsigned char index;
	int i;
	int decalage;
	unsigned char mem;
	int mask;

	i = 0;
	mask = 192;
	index = 0;
	decalage = 6;
	mem = core->mem[(pro->pc + 1) % MEM_SIZE];
  	// ft_printf("{RED}\n[%02x][%08b]\n",mem,mem);
  	while(i != pro->op->nbr_args)
  	{
		index = mem & mask;
		index = index >> decalage;
  	;
  		if(index & pro->op->type[i])
  		{
  			ft_printf("MATCH\n");	
  			ft_printf("{7}%x",core->mem[(pro->pc + 1) % MEM_SIZE]);	
  			ft_printf("{8}[%08b] - ",index);
  			ft_printf("{9}[%08b][%]\n",pro->op->type[i]);
  		}
  		else
  		{
  			ft_printf("NO MATCH\n");
  			return(0);
  		}
  		i++;
  		mask /= 4;
  		decalage -= 2;
  	}
	return(1);
}

int check_arg(t_core *core, t_process *pro, int pc)
{
	int i;

	i = 0;
	while(i != pro->op->nbr_args)
		i++;
	return(0);	
	return (1);
}

int checker_arg(t_core *core, t_process *pro)
{ 	
	int pc;

	pc = pro->pc;
  ft_printf("{9}%s - ",pro->op->mnemonique);
  ft_printf("{8}%02x- ",core->mem[(pro->pc) % MEM_SIZE]);
  if (pro->op->cde_oct == 1)
	{
		if(!(check_cde_oct(core, pro)))
			return(0);
		pc += 1;
		// core->mem[(pro->pc + 2) % MEM_SIZE]
	}
	if(!(check_arg(core, pro, pc)))
		return(0);
  // ft_printf("{5}%d",pro->op->type[MAX_ARGS_NUMBER]);
  // exit(0);
	// return (0);
	return (1);
}