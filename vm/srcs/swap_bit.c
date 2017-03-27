/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 04:50:27 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/27 04:50:28 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

size_t swap_st(size_t val)
{
    val = ((val << 8) & 0xFF00FF00 ) | ((val >> 8) & 0xFF00FF); 
    return (val << 16) | (val >> 16);
}

unsigned short int swap_usint(unsigned short int val) 
{
    return (val << 8) | (val >> 8);
}

short int swap_sint(short int val) 
{
    return (val << 8) | ((val >> 8) & 0xFF);
}

unsigned int swap_uint(unsigned int val )
{
    val = ((val << 8) & 0xFF00FF00 ) | ((val >> 8) & 0xFF00FF); 
    return (val << 16) | (val >> 16);
}

int swap_int(int val)
{
    val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF); 
    return (val << 16) | ((val >> 16) & 0xFFFF);
}
