/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 08:19:44 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/29 08:19:45 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

unsigned char aply_mask(unsigned char cde, int arg)
{
  if (arg == 1)
    return ((cde & 192) >> 6);
  if (arg == 2)
    return ((cde & 48) >> 4);
  if (arg == 3)
    return ((cde & 12) >> 2);
  return (cde & 3);
}

unsigned int get_n_arg(t_core *core, t_process *process, int arg, int mod)
{
  unsigned int res;
  unsigned char cde;
  int i;

  cde = core->mem[(process->pc + 1) % MEM_SIZE];
  cde = aply_mask(cde, arg);
  return (res);
}
