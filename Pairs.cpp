#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>

typedef long long ll;

//Standard Libaries and Headings^

void swap(int *a, int *b){
  int t = *a;
  *a = *b;
  *b = t;
}

//void swap is a simple swap command made with pointers, just moving around numbers

int partitian(int data[], int low, int high){
  int index = low - 1;

  int pivot = data[high];

  for(int j = low; j < high; ++j){
    if(data[j] <= pivot){
      index++;

      swap(&data[index], &data[j]);
    }
  }

    swap(&data[index + 1], &data[high]);

    return (index + 1);
}

void quickSort(int data[], int low, int high){
  if(low < high){
    int p = partitian(data, low, high);

    quickSort(data, low, (p - 1));

    quickSort(data, (p + 1), high);
  }
}

/*
Quicksort is the type of search, a simple sorting data structure, I would learn it if you didn't know it, tutorials will teach you
how it works, but quickly you have an unsorted array with a pivot point at the end, you move between elements swapping
if they're smaller with the swap method above, and look to get both sides of that "partitian" or pivot point in the graph
*/

int BinarySearch(int data[], int target, int low, int high){
  if(low <= high){
    int mid = low + (high - low) / 2;

    if(data[mid] == target){
      return mid;
    }

    if(data[mid] > target){
      return BinarySearch(data, target, low, mid - 1);
    }

    else {
      return BinarySearch(data, target, (mid + 1), high);
    }
  }
  else {
    return -1;
  }
}

/*
Another really handy and simple method you should learn - Binary Search, name implies it's purpose, you try to search through an array
log n speed instead of a linear search, by splitting in half constantly
*/

int n, t; //Size then Target
int x, a;
int tot;

int main(){
  std::cin >> n >> t;
  int vec[n];
  int size = sizeof(vec) / sizeof(vec[0]);

  for(int b = 0; b < n; ++b){
    std::cin >> a;
    vec[b] = a;
  }

//Simply receive input and create an array with the exact size of n, or the user input, unfortunately couldn't use Vectors instead of the array

  quickSort(vec, 0, size - 1);


  for(int c = 0; c < size; ++c){
    int target = vec[c] - t;
    int result = BinarySearch(vec, target, 0, size - 1);
    if(result != -1){
      ++x;
    }
  }

  /*
  Call the sorting method then we'll work through each spot in the array, we'll set a predetermined target that goes with the spot in the array
  To think about this, the constraints said all the numbers had to be unique, so each number minus a number we'll call x will get to the target
  For Example: we're at 9 and the target is 3 (9 - x = 3) Solve for x, the pair has to be 6, we can then find this pair in our now sorted array
  if we find the number ++x just adds one to the number of pairs found
  
  */
  std::cout << x;
}

/*
Time Complexity: O(log n(n))
*/
