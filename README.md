# Introduction
push_swap is a sorting algorithm project designed to sort a stack of integers using a limited set of operations on two stacks. The goal of the project is to implement an efficient algorithm that sorts numbers using the least number of moves possible.

In this implementation, a proximity-based sorting algorithm is employed to handle small sets of numbers (like 10 or 100), achieving minimal operations in both best and worst-case scenarios. It tests not only sorting efficiency but also algorithmic logic and performance under constraints.

## What are stacks?
A stack is a fundamental data structure in computer science that operates on a Last In, First Out (LIFO) principle. This means that the last element added to the stack is the first one to be removed. This only adds a little bit of complexity to the projects due the constraints.

![Stack representation](img/stack.jpg).

Source:
[infocodify](https://www.infocodify.com/c-programming/stack).

# Instalation
```git clone https://github.com/Welepy-dev/push_swap.git```.

```cd push_swap```.

```make```.

# Usage
You can check the number of operations with this command:

```ARG=($(shuf -i 1-100)) ; ./push_swap $ARG | wc -l```.

You can also use this command to use this cool visualizer courtesy of [@gecarval](https://github.com/gecarval).

```ARG=($(shuf -i 1-100)) ; ./push_swap $ARG > ./push_swap_visualizer/result.txt ; ./push_swap_visualizer/push_swap_visualizer $ARG```.

This command writes every command to a txt file called result, you can then use: 

```cat ./push_swap_visualizer/result.txt | wc -l``` to display the number of operations.

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
In this project you have the liberty of using tables, arrays, linked lists or any linear data structure to solve the problem, everyone said that is very hard to do it with arrays, so I made it.
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
	int		pivo;
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
We have here an `id`, to identify each stack, an `integer top`, that stores the index of the element of the stack that is at the top, this integer is **initialized as -1** because this stack have to start at index 0.
another integer, `capacity`, to store the **maximum capacity** that these stacks can handle, this value is based on input and is made to allocate enough memory in *collection to store the collection of numbers, a pointer to int called ***collection** to store the colection of integers of the input and a pivot, this pivot is used to make my lazy implementation of the quiscksort algorithm
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
In the subject of this project it says that this project should work with several amounts of numbers with or without quotation marks  ("") so we have an if statement to initialize and sort if this is the input.
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
Here we use split (hopefully you know it works), to return an allocated 2d arry of the argument counter separated by spaces.
