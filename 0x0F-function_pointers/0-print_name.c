#include "function_pointers.h"
/**
 *print_name - printing name
 *@name: string name
 *@f : function pointer
 */
void print_name(char *name, void (*f)(char *)){
	if (f == NULL) {
		exit (EXIT_FAILURE);
	}
	f(name);
}
