/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:41:40 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/04 16:41:40 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void
	swap(int *arr, int ind1, int ind2)
{
	int store;

	store = arr[ind1];
	arr[ind1] = arr[ind2];
	arr[ind2] = store;
}

static int
	partition(int *arr, int start, int end)
{
	int pivot;
	int i;
	int j;

	pivot = arr[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (arr[j] < pivot)
		{
			i++;
			if (i != j)
				swap(arr, i, j);
		}
		j++;
	}
	swap(arr, i + 1, end);
	return (i + 1);
}

static void
	quicksort(int *arr, int start, int end)
{
	int pivot;

	if (start < end)
	{
		pivot = partition(arr, start, end);
		quicksort(arr, start, pivot - 1);
		quicksort(arr, pivot + 1, end);
	}
}

void
	quick_sort(int *arr, int len)
{
	quicksort(arr, 0, len - 1);
}
