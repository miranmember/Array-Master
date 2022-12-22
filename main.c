/*Author: Miran Member 09/13/2020*/
#include <stdio.h>

//copies orignal array to another array
void makeArrayCopy (int arr1[], int arr2[], int size) {
  for (int i = 0; i < size; i++) {
    arr2[i] = arr1[i];
  }
}

//uses binary search to sort the array in desending order.
void myFavoriteSort (int arr[], int size){
  int a;
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if(arr[j] == 0){// since the array doubles in size and the input is not always the same as the size, the array ends up with extra zeroes at the end. This ensures that that will not effect the output.
        break;
      }
      if (arr[i] > arr[j]) {
        a =  arr[i];
        arr[i] = arr[j];
        arr[j] = a;
      }
    }
  }
}

//compares the arrys and increases the coutner if they both have same indices
void indexComparison (int arr1[],int arr2[],int size, int *counter){
  *counter = 0;
  for(int i = 0; i < size; i++) {
    if(arr2[i] == 0){
      break;
    }
    else if(arr1[i] == arr2[i]){
       *counter = *counter + 1;//pass-by-value so habe to derefrence it
    }
  }
  return;
}

//Set two pointers at the beginning and the end of the array, then start moving the pointers inward while checking their sum. If it’s exactly the “target”, then we are done, and can return 1. If it exceeds the “target” value, then any sum using the larger element is too large, so move the pointer corresponding to that element inward. If the sum is less than “target” value, then any sum using the lower element is too small, so move the pointer corresponding to that element inwards.  If done with scanning the array and cannot find any two elements that sum up to “target” value, return -1.
int targetSum(int arr[], int size, int target, int*index1, int* index2){
  int temp = 0;
  int counter1 = 0;
  int counter2 = size-1;
  while (target != temp){
    temp = arr[counter1] + arr[counter2];//adding the two values from diffrent ends
    if (counter1 == counter2) {
      break;
    }
    else if (temp > target || (arr[counter2] == 0)) {// makes sure the input is not zero 
      counter2 = counter2 - 1;
    }
    else if (temp < target) {
      counter1 = counter1 + 1;
    }
    else if (temp == target){
      *index1 = counter1;
      *index2 = counter2;
      return 1;
    }
  }
  return -1;
}


int main (int argc, char** argv)
{
 int val; 
 int userInput;
 int *arr1;
 int size = 5;
 int *arr2;
 arr1 = (int*) malloc(sizeof(int) * size);//mallocting 5 int size intially and can be increased if need be.

 printf ("Enter in a list of numbers to be stored in a dynamic array.\n");
 printf ("End the list with the terminal value of -999\n");

 scanf ("%d", &val);//taking input form the user to store in the array
 int counter = 0;
  while (val != -999) {
    if(counter >= size) {//if the size of array is too small double by creating a temp and increasin the orignal array, then copying the temp to the new bigger array.
      int *temp;
      temp = arr1;
      arr1 =	(int*) malloc(sizeof(int) * size * 2);
      for (int i = 0; i < size; i++){
        arr1[i] = temp[i];
      }
      free(temp);
      size = size * 2;//doubling the size with the array.
    }
    arr1[counter] = val;
    counter++;
    scanf("%d", &val);
  }
  arr2 = (int*) malloc(sizeof(int) * size);
  makeArrayCopy (arr1, arr2, size);//copies arr1 to arr2
  myFavoriteSort (arr2, size);//sorts arr2

  printf("Enter 1 to perform index comparison, enter 2 to perform target sum.\n"); 
  while(1 == 1){//statement runs constatnly unless break; is called to ensure the user only types 1, 2 when choosing the option. if the user types anything else the if statement will call continue; which will make the while loop go on.
    scanf("%d", &val);
    if(val == 1){
      indexComparison(arr1, arr2, size, &counter);//calls the to see if any array indeces are in the same place
      if (counter == 0){//if counter never moved that means all the array indices are in diffrent place
        printf("All elements change location in the sorted array.\n");
      }
      else {
        printf("%d values are in the same location in both arrays. \n", counter);
      }
      break;
    }
    else if(val == 2){
      printf ("Enter in a list of numbers to use for searching.  \n");
      printf ("End the list with a terminal value of -999\n");
      int target, index1, index2;
      scanf ("%d", &target);
      while (target != -999) {
        int result = targetSum(arr2, size, target, &index1, &index2);//assigning the result from targetsum which either returns -1 if the array does not have any number to sum up to target or 1 if it succesed in which case it will print the location.
        if( result == -1){
          printf("Target sum failed!\n"); 
        }
        else {
          printf("Success! Elements at indices %d and %d add up to %d\n", index1, index2, target);
        }
        scanf("%d", &target);
      }
      break;
    }
    else {
      printf("Invalid input.Enter 1 or 2.\n");
      continue;
    }
  }

 printf ("Good bye\n");
 free(arr1);//good practice to free the mallocated memory
 free(arr2);
 return 0;
}