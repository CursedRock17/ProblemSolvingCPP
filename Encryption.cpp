#include <bits/stdc++.h>

int i, n, j, b;
std::vector<char> arr;
int tot;
int flr; //lowest one = rows
int cel; //greater round = columns
std::string s;

int main(){
    std::cin >> s;
    for(i = 0; i < s.length(); ++i){
        arr.push_back(s[i]);
        if(s[i] == ' '){
            arr.pop_back();
        }
    }
    //removed all the spaces and simplified the string
    int tot = arr.size();
    int rnd = sqrt (tot);
    flr = floor (rnd);
    cel = floor (rnd) + 1;
  
    if(sqrt(tot) == flr){
        cel = flr;
    }
  
 //Find the total as the size of our simplified string, and we will round the sqrt of that number both down and up to get
 //The rows and columns needed for this problem
  
    for(j = 0; j < cel; ++j){
        for(n = j; n < arr.size(); n += cel){
            std::cout << arr[n];
        }
        std::cout << ' ';
    }
  
  //Time Complexity: O(n^2)
}
