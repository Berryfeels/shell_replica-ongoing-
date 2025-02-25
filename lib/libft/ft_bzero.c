/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:47:52 by jslusark          #+#    #+#             */
/*   Updated: 2024/05/07 12:04:56 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/* #include <stdio.h>
#include <strings.h>
int main(void)
{
	// Test 1: Zero on characters array
	char arr1[5] = {'a', 'b', 'c', 'd', 'e'};
	printf("\n");
	ft_bzero(arr1, 5);
	printf("Test 1: ");
	for (int i = 0; i < 5; i++)
		printf("%d ", arr1[i]); // Expect 0 0 0 0 0
	printf("\n");

	// Test 2: Zero part of an array
	char arr2[5] = {'x', 'y', 'z', 'w', 'v'};
	ft_bzero(arr2, 3);
	printf("Test 2: ");
	for (int i = 0; i < 5; i++)
		printf("%d ", arr2[i]); // Expect 0 0 0 'w' 'v'
	printf("\n");

	// Test 3: Zero as integer array
	int arr3[3] = {1, 2, 3};
	ft_bzero(arr3, sizeof(arr3));
	printf("Test 3: ");
	for (int i = 0; i < 3; i++)
		printf("%d ", arr3[i]); // Expect 0 0 0
	printf("\n");

	// Test 4: Zero with zero length
	char arr4[5] = {'1', '2', '3', '4', '5'};
	ft_bzero(arr4, 0); // No effect should be observed
	printf("Test 4: ");
	for (int i = 0; i < 5; i++)
		printf("%c ", arr4[i]); // Expect '1' '2' '3' '4' '5'
	printf("\n");

	return 0;
} */
/* writes 0 to a byte of the string
therefore why we use memset inside*/
