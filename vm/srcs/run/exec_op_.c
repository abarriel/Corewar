/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 06:40:45 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/28 06:40:54 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int exec_add(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;

  cr = (t_core*)core;
  pr = (t_process*)pro;

  if(!checker_arg(cr, pr))
      return (0);
 
  // exit(0);
  return (1);
}

int exec_lld(void *core, void *pro)
{
  t_process *pr;
  t_core *cr;

  cr = (t_core*)core;
  pr = (t_process*)pro;

  if(!checker_arg(cr, pr))
      return (0);
 
  // exit(0);
  return (1);
}
