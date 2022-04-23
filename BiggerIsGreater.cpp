#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <algorithm>

typedef long long ll;

//Basic Libraries and definitions^

int t; //TestCases
int x, n, current;
int mod = 1000000000; //10^9
std::vector<int> vec;
std::string s;

void solve(std::string s){
  current = 0;
  std::string prev = s;
  next_permutation(s.begin(),s.end());
/*This next permutation is a small cheatsheet that c++ had for this problem
We are working with next permutations in order to find the next largest string
in lexigraphical order and the function does it for us
*/

  for(int c = 0; c < s.length(); ++c){
   int aci = s[c];
   int prevAci = prev[c];
//We needed to compare the original string to the next permutation string to
//find extra test cases:
   if(prevAci > aci){
    std::cout << "no answer" << std::endl;
    c = s.length();
//If the permutated string has an element less than the old string without
//Finding a larger number in a spot before it, then it'll be less
   }
   else if(prevAci < aci){
    std::cout << s << std::endl;
    c = s.length();
//If the string already has a number larger than the old string, because it's
//guarenteed to permutated to the smallest extent, we're good to go
   }
    else if(prevAci == aci){
        ++current;
    }
//These if statements up and below look to see if the string has all the same letters

    if(current == s.length()){
        std::cout << "no answer" << std::endl;
    }
  }

}

int main(){
  //Runs the test cases with input
  std::cin >> t;
  for(int i = 0; i < t; ++i){
    std::cin >> s;
    solve(s);
  }
}

//Time complexity: O(N)
