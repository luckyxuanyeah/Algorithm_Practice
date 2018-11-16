You are to find the closest common ancestor of two vertices in a binary tree. For example, the common ancestors of vertices 8 and 13 in the figure below are vertices 3 and 1. Among them, vertex 3 is the closest to the vertex 8 and 13. And the size of sub-tree (the number of vertices in the sub-tree) rooted by vertex 3 is 8.

![picture1](D://1lyx//google_wintercamp//1.png)

Given a binary tree and two vertices, write a program that finds the closest common ancestor and computes the size of the sub-tree rooted by the closest common ancestor. No input is given where one of the two given vertices is an ancestor of the other. For example, ‘11 and 3’ in the above tree is an invalid input. Therefore, your program does not have to consider this case.

[Constraints]
The number of vertices are from 3 to 10000

[Input]
You are given 10 test cases. Each test case has two lines, so the total number of lines is 20. In each test case, the first line consists of four integers, V (the number of vertices in the tree), E (the number of edges), and the indices of two vertices. E edges are listed in the next line. Each edge is represented by two vertices; the index of the parent vertex always precedes the index of the child. For example, the edge connecting vertices 5 and 8 is represented by “5 8”, not by “8 5.” There is no order in which the edges are given. Every consecutive integer in the input is separated by a space. 

Given 10 test cases,First 4 test cases contain small number of vertices(3, 5, 7, 10 each).
Next 6 test cases contain same or greater than 50 vertices.

The indices of vertices are integers from 1 to V, and root vertex always has the index 1. 
It is guaranteed that the parent vertex has smaller index than the child vertex.
In this problem, it is not important whether the child is the left child of the parent or the right child; so you can decide this arbitrarily.

[Output]
Output 10 answers in 10 lines. Each line starts with ‘#x’ meaning the index of a test case, and writes the answer after a space. The answer has two integers: the index of the closest common ancestor and the size of the sub-tree rooted by the closest common ancestor. These two integers are separated by a space as well. 

[I/O Example]
Input (20 lines in total)

13 12 8 13 ← Start of the first input

1 2 1 3 2 4 3 5 3 6 4 7 7 12 5 9 5 8 6 10 6 11 11 13

10 9 1 10 ← Start of the second input

1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10

...

Output (10 lines in total)

#1 3 8

#2 1 10

...
