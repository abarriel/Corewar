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

int check_all_arg(t_core *core, t_process *pro, int i, int index, int *ok)
{
	int decal;

	decal = 0;
  	// ft_printf("{8}[%d] -[%d]  - Index=[%b]",i,*ok,index);
  	// ft_printf("{8}[%02x]",core->mem[(pro->pc + 1 + i) % MEM_SIZE]);	
  	// ft_printf("{4}[%02x]\n",core->mem[(pro->pc + 1 + i + *ok) % MEM_SIZE]);	
  	if (index & T_REG)
  	{
		if (core->mem[(pro->pc + 1 + i + *ok) % MEM_SIZE] > REG_NUMBER) 
		{
			// ft_printf("REG NUMBER TROP GRAND");
  			return(0);
		}
  		else   			
  			(*ok)++;
  	}
  	if(index & T_DIR)
  	{
  	// ft_printf("{RED}[%02x]\n",core->mem[(pro->pc + 1 + i + *ok) % MEM_SIZE]);	
  		if(!pro->op->l_size)
  		{
  			// ft_printf("{RED}4");
  			(*ok) += 2;
  		// ft_printf("{RED}[%02x]\n",core->mem[(pro->pc + 1 + i + *ok) % MEM_SIZE]);
  		}
  		else
  		{
  			// ft_printf("{RED}2");
  			(*ok) += 1;
  		// exit(0);	
  		}
  		// ft_printf("T_DIR");	
  	}
  	if( index & T_IND)
  	{
  		(*ok) += 1;
  	}
  	// exit(0);
	return (1);
}

int check_cde_oct(t_core *core, t_process *pro)
{
	int ok;
	unsigned char index;
	int i;
	int decalage;
	int mask;

	i = 0;
	ok = 0;
	mask = 192;
	index = 0;
	decalage = 6;
  	// ft_printf("{RED}\n[%02x]\n",core->mem[(pro->pc + 1) % MEM_SIZE]);
  	while(i != pro->op->nbr_args)
  	{
  		// ft_printf("{9}[%d]",i);
		index = core->mem[(pro->pc + 1) % MEM_SIZE] & mask;
		index = index >> decalage;
  		if(index & pro->op->type[i])
  		{
    			if(!(check_all_arg(core,pro,i + 1, index, &ok)))
  				return(0);
  		  			// ft_printf("{8}[%08b] - ",index);
  			// exit(0);
  		}
  		else
  		{
  			// ft_printf("\nNO MATCH\n");
  			return(0);
  		}	
  		i++;
  		// ft_printf("{7}[%02x]\n",core->mem[(pro->pc + 1 + i) % MEM_SIZE]);	
  		mask /= 4;
  		decalage -= 2;
  	}
  	// exit(0);
	return(1);
}

int checker_arg(t_core *core, t_process *pro)
{ 	
	int pc;

	pc = pro->pc;
  // ft_printf("{9}%s - ",pro->op->mnemonique);
  // ft_printf("{8}%02x- ",core->mem[(pro->pc) % MEM_SIZE]);
  if (pro->op->cde_oct == 1)
	{
		if(!(check_cde_oct(core, pro)))
			return(0);
		pc += 1;
		// core->mem[(pro->pc + 2) % MEM_SIZE]
	}
	// if(!(check_arg(core, pro, pc)))
	// 	return(0);
  // ft_printf("{5}%d",pro->op->type[MAX_ARGS_NUMBER]);
  // exit(0);
	// return (0);
	return (1);
}