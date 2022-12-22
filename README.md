# Array-Master
This is a C program that performs several tasks on an array of integers that is inputted by the user. The tasks include sorting the array in descending order, finding the number of matching indices between two copies of the array, and searching for a pair of elements in the array that add up to a specific target value.

## Functions
The program contains several functions that perform the following tasks:

+ makeArrayCopy: This function takes in two arrays and their size as arguments, and copies the elements of the first array to the second array.

+ myFavoriteSort: This function takes in an array and its size as arguments, and sorts the elements of the array in descending order using a binary search algorithm.

+ indexComparison: This function takes in two arrays and their size, as well as a pointer to an integer, and compares the elements of the two arrays at each index. If they are the same, it increments the integer pointed to by the pointer.

+ targetSum: This function takes in an array, its size, and a target value as arguments, as well as two pointers to integers. It uses a pair of pointers to search for a pair of elements in the array that add up to the target value. If such a pair is found, it sets the integers pointed to by the pointers to the indices of the elements. If no such pair is found, it returns -1.

## Usage
To use the program, compile it using a C compiler and run the executable. The program will prompt the user to input a list of numbers, ending with the terminal value of -999. The program will then perform the aforementioned tasks on the array and print the results to the console.
