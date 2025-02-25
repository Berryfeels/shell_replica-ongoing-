/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:48:32 by jslusark          #+#    #+#             */
/*   Updated: 2024/05/07 14:42:16 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	tot_size;
	void	*dst;

	tot_size = size * nmemb;
	dst = malloc(tot_size);
	if (!dst)
		return (0);
	ft_memset(dst, 0, tot_size);
	return (dst);
}
/*
#include <stdio.h>
#include <stdint.h> // for uintptr_t to check alignment
void print_memory(char *ptr, size_t n) {
    printf("Memory: ");
    for (size_t i = 0; i < n; i++) {
        printf("%02x ", (unsigned char)ptr[i]);
    }
    printf("\n");
}
int main(void) {
    // Test 1: Basic functionality with non-zero members
    int *array = ft_calloc(10, sizeof(int));
    printf("Test 1 - First 10 integers should all be zero:\n");
    print_memory((char *)array, 10 * sizeof(int));
    free(array);

    // Test 2: Zero elements allocated
    double *doubles = ft_calloc(0, sizeof(double));
    printf("Test 2 - Pointer should be non-NULL (implementation-specific):\n");
    printf("Pointer: %p\n", doubles);
    free(doubles);

    return 0;
}
 */
