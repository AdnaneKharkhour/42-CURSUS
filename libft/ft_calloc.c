/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:12:58 by akharkho          #+#    #+#             */
/*   Updated: 2024/11/05 13:37:01 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;

	if (count != 0 && size > 18446744073709551615ULL / count)
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, (count * size));
	return (p);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


// Function to test ft_calloc
void test_ft_calloc(size_t count, size_t size)
{
	int *ft_calloc_array;
	int *calloc_array;
	size_t i;

	// Allocate memory using ft_calloc
	ft_calloc_array = (int *)ft_calloc(count, size);
	if (!ft_calloc_array)
	{
		printf("ft_calloc failed for count = %zu, size = %zu\n", count, size);
		return;
	}

	// Allocate memory using calloc
	calloc_array = (int *)calloc(count, size);
	if (!calloc_array)
	{
		printf("calloc failed for count = %zu, size = %zu\n", count, size);
		free(ft_calloc_array);
		return;
	}

	// Compare the allocated memory
	for (i = 0; i < count * size / sizeof(int); i++)
	{
		if (ft_calloc_array[i] != calloc_array[i])
		{
			printf("Memory initialization mismatch at index %zu for count = %zu, size = %zu\n", i, count, size);
			free(ft_calloc_array);
			free(calloc_array);
			return;
		}
	}

	printf("Both ft_calloc and calloc initialized memory to zero correctly for count = %zu, size = %zu.\n", count, size);

	// Free allocated memory
	free(ft_calloc_array);
	free(calloc_array);
}

int main(void)
{
	// Test cases
	test_ft_calloc(10, sizeof(int)); // Normal allocation
	test_ft_calloc(0, sizeof(int));  // Zero count
	test_ft_calloc(10, 0);           // Zero size
	test_ft_calloc(SIZE_MAX / 2, 1); // Large allocation

	// Simulate allocation failure by setting a limit on memory allocation
	// This is platform-dependent and may require specific setup to test effectively

	return 0;
}