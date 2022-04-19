#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>

typedef long long ll;

//These are my standard libraries^

int h, w; 
int a;
int tot;
int temp;
int current;

void solution(int current, int temp){
    if(current - temp < 0){
      tot -= current;
    }
    else {
      tot -= temp;
    }
  }

int main(){
  std::cin >> h >> w;
  int arr[h][w];
  for(int i = 0; i < h; ++i){
    for(int b = 0; b < w; ++b){
       std::cin >> a;
       arr[i][b] = a;
    }
  }
  
/*
The First Piece of the main file, initializes a matrix by using the input given to us
We can set each place in the matrix without overflowing in space
*/

  for(int u = 0; u < h; ++u){
    for(int n = 0; n < w; ++n){
      current = arr[u][n];
      tot += (6 * current);
      
      /*
      These first two lines find us the current location of our matrix earlier, which we'll be working with
      Then the second line adds to the total, all of the sides of each cube, each 1x1x1 cube has 6 sides and the height
      or the current location will multiply by 6 to give us those total sides.
      */
      
      if(current > 1){
        tot -= (2 * (current - 1));
      }

      if(u - 1 >= 0){
        temp = arr[u - 1][n];
        solution(current, temp);
      }

      if(u + 1 < h){
        temp = arr[u + 1][n];
        solution(current, temp);
      }

      if(n - 1 >= 0){
        temp = arr[u][n - 1];
        solution(current, temp);
      }

      if(n + 1 < w){
        temp = arr[u][n + 1];
        solution(current, temp);
      }
    }
    
    /*
    After we're given our current, we first need to check the size of the cube, if it's size is one then we don't need to worry as all
    6 of it's sides could be exposed, otherwise take off the top of a cube and a bottom of the cube above
    in this problem we imagine each height is a new block
    
    Then we need to check it's surrounding possible 4 sides for sides that'll be covered up by running the solution function.
    In this function we check if that stack next to it is larger, if so we need to remove all of the faces of the side we're
    currently working with, otherwise remove the amount of faces that would be covered by the stack directly next to it.
    */
  }

  std::cout << tot;
  
  //Time Complexity: O(H*W)
}
