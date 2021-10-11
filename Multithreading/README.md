Multithreading

Multithreading can be described as a form of task delegation for computer programs. One program, the 'parent' creates subroutines, also known as 'children'.
The children then perform tasks based on how they are programmed to function. However, the actions of the children are performed irrespective of what
all other entities are doing. For example, one thread could read the values of all of the even indexes of a list, while another reads all of the odd values,
which could effectively cut the time needed to read the entire thing in half. However, this practice comes with its own set of pitfalls. The most common of
which are Race Conditions, which occur when the end result of the actions of a number of threads is subject to change based on when each one performs specific
instructions. Areas of code where this can happen are known as critical sections. In order to counter this, steps have to be taken to ensure that these sections
cannot be executed by more than one thread at a time.