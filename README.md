# Introduction
push_swap is a sorting algorithm project designed to sort a stack of integers using a limited set of operations on two stacks. The goal of the project is to implement an efficient algorithm that sorts numbers using the least number of moves possible.

In this implementation, a lazy, proximity-based sorting algorithm is employed to handle small sets of numbers, achieving minimal operations in both best and worst-case scenarios. It tests not only sorting efficiency but also algorithmic logic and performance under constraints.

## What are stacks?
A stack is a data structure in computer science that operates on a Last In, First Out (LIFO) principle. This means that the last element added to the stack is the first one to be removed. This only adds a little bit of complexity to the projects due the constraints.

![Stack representation](img/stack.jpg).

Source:
[infocodify](https://www.infocodify.com/c-programming/stack).

# Instalation
```
git clone https://github.com/Welepy-dev/push_swap.git
```
```
cd push_swap
```

```
make
```

# Usage
You can check the number of operations with this command:

```
ARG=($(shuf -i 1-100)) ; ./push_swap $ARG | wc -l
```

You can also use this command to use this cool visualizer courtesy of [@gecarval](https://github.com/gecarval).

```
ARG=($(shuf -i 1-100)) ; ./push_swap $ARG > ./push_swap_visualizer/result.txt ; ./push_swap_visualizer/push_swap_visualizer $ARG
```

This command writes every command to a txt file called result, you can then this to display the number of operations 

```
cat ./push_swap_visualizer/result.txt | wc -l
```

# Explanation
## Operations

As you read before, this project has a lot of constraints such as using stacks. another constraint is that we are limited to use certain commands to finish this project.

The commands are:

`sa` (swap a): Swap the first 2 elements at the top of the stack a. Does nothing if there is only one or if the stack is empty.
`sb` (swap b): Swap the first 2 elements at the top of the stack b. Does nothing if there is only one or if the stack is empty.
<table>
  <tr>
    <td>

### Swap A
![swap a operation](https://i.giphy.com/media/v1.Y2lkPTc5MGI3NjExejE5NjZlZHo3aTkyMGU4Y3NuNGhlNm52cWczc2E5eWNtb2Q1YWFnZyZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/9JGknv1acpLbEWvrEy/giphy.gif)
    </td>
    <td>
### Swap B
![swap b operation](https://i.giphy.com/media/v1.Y2lkPTc5MGI3NjExZm9kcGYxbWFlOXdiZXIwcGIyeGc3bHU5cHpsOGF5ZDRocXZrYWpsaiZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/S2l6ndPUlHAdTy02g3/giphy.gif)
    </td>
  </tr>
</table>

`pa` (push a): Takes the first element on top of stack b and puts it on stack a. Does nothing if stack b is empty or if stack a is full.

`pb` (push b): Takes the first element on top of stack a and puts it on stack b. Does nothing if stack a is empty or if stack b is full.

<table>
  <tr>
    <td>

### Push A
![push a operation](https://media.giphy.com/media/5cgl7rhV1xd2yMVt0S/giphy.gif)
    </td>
    <td>
### Push B
![push b operation](https://media.giphy.com/media/FHpuB6j1yylcUktPJC/giphy.gif)
    </td>
  </tr>
</table>

`ra` (rotate a): Shifts all the elements of the stack stack a up by one position. The first element becomes the last, does nothing if stack a is empty. 

`rb` (rotate b) : Shifts all the elements of the stack b one position upwards. The first element becomes the last one, does nothing if stack b is empty. 

<table>
  <tr>
    <td>

### Rotate A
![rotate a operation](https://media.giphy.com/media/dhrVJctdyfGUlpUKyM/giphy.gif)
    </td>
    <td>
### Rotate B
![rotate b operation](https://media.giphy.com/media/Wgaz9rYZdsg92ZM4PJ/giphy.gif)
    </td>
  </tr>
</table>

`rra` (reverse rotate a): Shifts all elements of the stack a down one position. The last element becomes the first, does nothing if stack a is empty. 

`rrb` (reverse rotate b): Shifts all the elements of the stack b one position downwards. The last element becomes the first, does nothing if stack b is empty. 

<table>
  <tr>
    <td>

### Reverse Rotate A
![reverse rotate a operation](https://media.giphy.com/media/t5swCXe3umePwelruL/giphy.gif)
    </td>
    <td>
### Reverse Rotate B
![reverse rotate b operation](https://media.giphy.com/media/vTsz9rzczIYmD6Vsnd/giphy.gif)
    </td>
  </tr>
</table>

And then, we have operations that changes both stacks, do mind that this every single one of these count only as one operation

`ss` (swap both) : Does `sa` and `sb` at the same time. 

`rr` (rotate both): `ra` and `rb` at the same time. 

`rrr` (reverse rotate both): `rra` and `rrb` at the same time.

<table>
  <tr>
    <td>

### Swap Both
![Swap both operation](https://media.giphy.com/media/diLOtwLDbp4BZ2f6Yd/giphy.gif)
    </td>
    <td>
### Rotate Both
![Rotate operation](https://media.giphy.com/media/SiMrZuvPln4lxqXIXo/giphy.gif)
    </td>
    <td>
### Reverse Rotate Both
![reverse rotate operation](https://media.giphy.com/media/YpqacbScKEvtgzqUPf/giphy.gif)
    </td>
  </tr>
</table>

## Code explanation
In this project you have the liberty of using tables, arrays, linked lists or any linear data structure to solve the problem, everyone said that is very hard to do it with arrays, so I made it to see if it actually is lol.
Firstly, I've declared two structs: one to store variables from stack a and b respectively and another that points to those stacks.

<table>
  <tr>
    <td>

### t_stack
```
typedef struct s_stack
{
	char	id;
	int		top;
	int		capacity;
	int		*collection;
	int		pivot;
}	t_stack;
```
  </td>
  <td>
  
### t_stack
```
typedef struct s_push_swa[
{
    t_stack *a;
    t_stack *b;
}  t_ps;
```
  </td>
  </tr>
  </table>
  
We have here an **`id`**, to identify each stack, an integer **`top`**, that stores the index of the element of the stack that is at the top, this integer is **initialized as -1** because this stack have to start at index 0.
another integer, `capacity`, to store the **maximum capacity** that these stacks can handle, this value is based on input and is made to allocate enough memory in **collection** to store the collection of numbers, we have a pointer to int called ***collection** to store the colection of integers of the input and a pivot, this pivot is used to make my lazy implementation of the quiscksort algorithm.

As for the libraries used here are they: (mostly for libft)

  ```
# include <stdbool.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>
# include <ctype.h>
# include <errno.h>
```
After the declaration of the control structures, I make some validations. Our project uses **Argument Counter** and **Argument Vector** in our main function, so at the beggining I check if those arguments are valid.
```
if (ac == 1 || (ac == 2 && (!ft_strlen(av[1]) || !ft_strcmp(av[1], " "))))
		error(NULL, '\0');
```
This if statement checks if our **Argument counter** is just 1, in other words just the program name. It also checks if the string that contains the number sequence is empty or if it is a bunch of spaces.
In the subject of this project it says that this project should work with several amounts of numbers with or without quotation marks  (" ") so we have an if statement to initialize and sort if this is the input.
```
if (ac == 2)
{
	matrix = ft_split(av[1], ' ');
	if (!is_matrix_valid(matrix, 'm'))
		error(matrix, 'm');
	init(&ps, matrix);
	if (!is_sorted(ps.a))
		choose_sort(&ps);
	ft_matrix_free(matrix);
}
```
Here we use split (hopefully you know it works), to return an allocated 2d arry of the argument counter separated by spaces. Then we check for duplicate numbers, non-numeric characters, and if the numbers are within the integer limits. If the input is valid, we initialize the stacks and sort them. If the stack is already sorted, we don't do anything. At the end we free the matrix that we allocated.

```
void	init(t_ps *ps, char **av)
{
	int	i;

	i = ft_matrix_len(av);
	init_stack(ps->a, av, i, 'a');
	init_stack(ps->b, av, i, 'b');
}
```

```
void	init_stack(t_stack *stack, char **av, int i, char id)
{
	stack->top = -1;
	stack->pivot = 0;
	stack->capacity = i;
	stack->collection = (int *)malloc(i * sizeof(int));
	if (!stack->collection)
		print_error("While allocating", id);
	i = stack->capacity - 1;
	if (id == 'a')
	{
		while (i >= 0)
			insert(stack, ft_atoi((av[i--])));
		stack->id = 'A';
	}
	else
		stack->id = 'B';
}
```
The **init** function is responsible for initializing the stacks and the collection of numbers.
As you can see, we first get the length of the matrix to allocate enough memory for the collection of numbers. Then we initialize the int values and finally insert all the matrix values into the stack a.

After the initialization, we have the **choose_sort** function that is responsible for choosing the sorting algorithm to be used based on the input.
```
void	choose_sort(t_ps *ps)
{
	if (ps->a->capacity == 2)
		swap(ps->a, "sa");
	else if (ps->a->capacity == 3)
		tiny_sort(ps->a);
	else if (ps->a->capacity <= 25)
		aproximity_sort(ps);
	else if (ps->a->capacity < 200)
		lazy_sort(ps, 5);
	else if (ps->a->capacity >= 200)
		lazy_sort(ps, 14);
}
```
Now I will explain the sorting algorithms that I used in this project.
For 2 numbers, we just swap them.
For 3 numbers, we use the **tiny_sort** function.

The **tiny_sort** function works this way:
```
void	tiny_sort(t_stack *stack)
{
	int	highest_position;

	highest_position = highest_stack_number_index(stack);
	if (highest_position == 2)
		rotate(stack, "ra");
	else if (highest_position == 1)
		reverse_rotate(stack, "rra");
	if (stack->collection[2] > stack->collection[1])
		swap(stack, "sa");
}
```
First we search the highest number index in the stack, if that number is at the top, we use rotate to send it to the bottom, if is in the middle we use reverse rotate to send it to the bottom. If the highest number isn't at the top nor the middle, that means its already at the bottom of the stack, so we don't do anything. At the end we check if the top number is greater than the middle one, if it is we swap them.

The **aproximity_sort** function is a lazy implementation of the selection sort algorithm, it works this way:
```
void	aproximity_sort(t_ps *ps)
{
	int	smallest_number_index;

	while (ps->a->top > 2)
	{
		smallest_number_index = smallest_stack_number_index(ps->a);
		if (smallest_number_index < ps->a->top / 2)
		{
			while (smallest_number_index != ps->a->top)
			{
				reverse_rotate(ps->a, "rra");
				smallest_number_index = smallest_stack_number_index(ps->a);
			}
		}
		else
		{
			while (smallest_number_index != ps->a->top)
			{
				rotate(ps->a, "ra");
				smallest_number_index = smallest_stack_number_index(ps->a);
			}
		}
		push(ps->a, ps->b, "pb");
	}
	tiny_sort(ps->a);
	while (ps->b->top >= 0)
		push(ps->b, ps->a, "pa");
}
```
Basically we always will be searching the smallest number of the stack A and send it to the stack B, then when there are only three numbers we use tiny sort, this tiny sort implementation just optimizes the code to do 2 or 3 less operations.
Explaining in more details, we search the smallest number index in the stack A, if that number is in the first half of the stack, we rotate the stack until that number is at the top, if it is in the second half of the stack, we reverse rotate the stack until that number is at the top. After that we push that number to the stack B. We repeat this process until there are only 3 numbers in the stack A, then we use tiny sort to sort them. At the end we push all the numbers from the stack B to the stack A.

The **lazy_sort** function is a lazy implementation of the quicksort algorithm, it works this way:
```
void	lazy_sort(t_ps *ps, int flag)
{
	int	*array;
	int	i;
	int	j;
	int	k;

	i = 0;
	*array = malloc(sizeof(int) * ps->a->capacity);
	ft_copy_array(*array, ps->a->collection, ps->a->capacity);
	bubble_sort(*array, ps->a->capacity);
	j = ps->a->top;
	while (++i < flag)
	{
		ps->a->pivot = array[i * ps->a->capacity / flag];
		while (--j >= 0)
		{
			if ((ps->a->collection[j] <= ps->a->pivot))
			{
				k = ps->a->collection[j];
				if (k != ps->a->collection[ps->a->top])
					while (k != ps->a->collection[ps->a->top])
						rotate(ps->a, "ra");
				while (ps->a->collection[ps->a->top] <= ps->a->pivot)
					push(ps->a, ps->b, "pb");
				j = ps->a->top;
			}
		}
		j = ps->a->top;
	}
	free(array);
	lazy_aproximity(ps);
	stack_it(ps);
}
```
First we allocate an array to store the collection of numbers, then we copy the collection of numbers from the stack A to the array and sort them using bubble sort. in that organized array we will find our 3 pivots
If you look at the code, you will see that we have a flag that is used to determine the number of pivots that we will use, this number is based on the input size, for example, if the input size is less than 200 we will use 3 pivots, if it is greater than 200 we will use 14 pivots.
this calculation `ps->a->pivot = array[i * ps->a->capacity / flag]` is used to find the current pivot and we iterate through the stack A to find the numbers that are less than the pivot, if we find a number that is less than the pivot we send it to the stack B, if it is greater we do nothing. That will prepare small chunk of numbers within a range which will redu At the end we sort the stack A using the **lazy_aproximity** to organize the last numbers and push all the numbers that are left.
lastly we have the **stack_it** function that is responsible for finding always the largest number in the stack B and sending it to the stack A.
After that we set the pivot to the middle of the array and start the quicksort algorithm. We iterate through the array and if the number is less than the pivot we send it to the stack B, if it is greater we do nothing. At the end we sort the stack A using the **aproximity_sort** function and push all the numbers from the stack B to the stack A.