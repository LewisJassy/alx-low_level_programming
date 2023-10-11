#include "function_pointers.h"
#include <stdlib.h>

/**
 * array_iterator - execute `action' on every element of `array'
 * @array: array to modify
 * @size: size of `array'
 * @action: function to call on elements of `array'
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	for (size_t i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
