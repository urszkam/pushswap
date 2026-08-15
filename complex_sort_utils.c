#include "push_swap.h"

int	compute_iterations(int size)
{
	int	iterations;

	iterations = 0;
	while (size > 1)
	{
		iterations++;
		size = (size + 1) / 2;
	}
	return (iterations);
}