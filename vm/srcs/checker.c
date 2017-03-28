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

int checker_arg(t_core *core, t_process *pro)
{ 
ft_printf("{9}%s - ",pro->op->mnemonique);
  ft_printf("{8}%02x- ",core->mem[(pro->pc) % MEM_SIZE]);
  ft_printf("{5}%02x",core->mem[(pro->pc + 1) % MEM_SIZE]);
  exit(0);
	return (0);
	return (1);
}