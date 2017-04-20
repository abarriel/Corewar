/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseccia <cseccia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 17:57:31 by cseccia           #+#    #+#             */
/*   Updated: 2017/04/20 18:18:15 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		push_back(t_process *old, t_process *new)
{
	t_process *tmp_new;

	tmp_new = new;
	while (tmp_new->next)
		tmp_new = tmp_new->next;
	tmp_new->next = old;
}

t_process	*get_the_bigger(t_process *tmp, t_process **o, t_process **n)
{
	t_process *old;
	t_process *last;

	old = *o;
	last = *n;
	if (tmp->next && tmp->next->player->nb > old->player->nb)
	{
		old = tmp->next;
		last = tmp;
	}
	*o = old;
	*n = last;
	return (tmp->next);
}

t_process	*sort_process(t_core *core)
{
	t_process *new;
	t_process *old;
	t_process *last;
	t_process *tmp;

	new = NULL;
	while (core->process)
	{
		tmp = core->process;
		last = NULL;
		old = tmp;
		while (tmp)
			tmp = get_the_bigger(tmp, &old, &last);
		if (last)
			last->next = old->next;
		else
			core->process = core->process->next;
		old->next = NULL;
		if (new == NULL)
			new = old;
		else
			push_back(old, new);
	}
	return (new);
}
