#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include <unordered_map>

typedef long long ll;

//Basic Libraries and Definitions^
//TestCases

ll x, t, h, b, n;
int mod = 1000000000; //10^9
std::vector<int> vec;
std::stack<ll> s;
bool correct = false;

int main(){
  std::cin >> t;
  for(int i = 0; i < t; ++i){
      std::cin >> h;
      if(s.empty() || s.top() != h){
        s.push(h);
      }
  }
  
/*
We will use a stack in this case because it follows FILO (First in Last out), because in problem we're given the scores
in descending order and the players give scores in ascending order(Down then up), we only need to add to the stack if it's not a repeat.
*/
  std::cin >> b;
  for(int c = 0; c < b; ++c){
      std::cin >> x;
      while(!s.empty() && x >= s.top()){
          s.pop();
      }
      std::cout << (s.size() + 1) << std::endl;
  }
}

/*
After creating the stack we start to get our inputs, for each one we're going to need to go through the stack to see if it's greater than 
the current index in the stack. After we pass a number that x is greater than, we can pop it off the top of the stack because we can only get 
numbers larger than x, therefore the index of those previous numbers won't affect the current x. Then we have a built in score counter in
the size of the stack + 1;

Time Complexity: O(n(log n))
*/
