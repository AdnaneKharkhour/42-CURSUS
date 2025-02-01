#include "push_swap.h"

t_stack	*ft_maxnode(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*max;

	if (!stack)
		return (NULL);
	tmp = stack;
	max = stack;
	while (tmp)
	{
		if (tmp->value > max->value)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int	max_node_position(t_stack *stack, int max_index)
{
	int		i;

	i = 0;
	while (stack && stack->index != max_index)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	sort_index(t_stack **stack)
{
	t_stack	*x;
	t_stack	*y;
	int		i;

	if (!stack)
		return ;
	x = *stack;
	while (x)
	{
		y = *stack;
		i = 0;
		while (y)
		{
			if (x->value > y->value)
				i++;
			y = y->next;
		}
		x->index = i;
		x = x->next;
	}
}

void	ft_range(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*max;
	int		s;
	int		i;

	while (*stack_b)
	{
		s = ft_nodesize(*stack_b) / 2;
		max = ft_maxnode(*stack_b);
		i = max->index;
		if (max_node_position(*stack_b, i) < s)
		{
			while ((*stack_b)->index != i)
				rotate(stack_b, "rb");
		}
		else
		{
			while ((*stack_b)->index != i)
				reverse_rotate(stack_b, "rrb");
		}
		push(stack_a, stack_b, "pa");
	}

}

void	filter_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_range	range;

	range.min = 0;
	range.max = (ft_nodesize(*stack_a) * 0.048) + 10;
	while (*stack_a)
	{
		if ((*stack_a)->index >= range.min && (*stack_a)->index <= range.max)
		{
			push(stack_b, stack_a, "pb");
			range.min++;
			range.max++;
		}
		else if ((*stack_a)->index > range.max)
			rotate(stack_a, "ra");
		else if ((*stack_a)->index < range.min)
		{
			push(stack_b, stack_a, "pb");
			rotate(stack_b, "rb");
			range.min++;
			range.max++;
		}
	}
	ft_range(stack_a, stack_b);
}
