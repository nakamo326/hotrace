#ifndef DARRAY_H
#define DARRAY_H

#include <stdbool.h>

typedef struct s_darray {
	int	base;
	int	check;
} t_darray;

void	make_darray(t_darray *arr);

#endif /* DARRAY_H */
