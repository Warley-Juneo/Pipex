/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:49:09 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/01/14 21:25:14 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	*ft_memset(void *str, int c, size_t n)
{
	void	*string1;

	string1 = str;
	while (n--)
		*(unsigned char *)str++ = (unsigned char)c;
	return (string1);
}
