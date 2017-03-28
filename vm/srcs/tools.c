/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 05:45:22 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/28 05:45:29 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_usage(void)
{
	ft_printf("Usage: ./corewar [-dump N -n N -v] <champion1.cor> <...>\n\n");
	ft_printf("    -dump nbr_cycles : Au bout de nbr_cycles cycles ");
	ft_printf("d’exécution, dump la mémoire sur la sortie standard,");
	ft_printf(" puis quitte la partie.\n");
	ft_printf("    -n numer         : Fixe le numéro du prochain joueur.\n");
	ft_printf("    -v               : interface graphique mlx\n");
	exit(0);
}
