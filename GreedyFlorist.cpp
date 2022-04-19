#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

int i, j, h;
int n, k;
int tot, cur;
int added;
std::vector<int> arr;
std::vector<int> v;
int flower, friends;

//First Step is sorting the stuff they put in
int main(){
    std::cin >> flower >> friends;
    for(i = 0; i < flower; ++i){
        std::cin >> n;
        arr.push_back(n);
        n = 0;
    }
    //We need to reverse the array in order to go from greatest to smallest and give each flower to each person and we need to sort it
    std::sort (arr.begin(), arr.end());
    for(h = flower - 1; h >= 0; --h){
        v.push_back(arr[h]);
    }
    //Above is the decreased prices in a new array
    while(cur != friends){
    for(j = cur; j < flower; j += friends){
        tot += (v[j] * (1 + added));
        ++added;
    }
    ++cur;
    added = 0;
    //This resets the amount of extra flowers they've bought
    //It also Adds one to the current friend that we're on, one we hit the number of friends the loop ends
    //The actual loop Starts at the friend number and we add the amount of friends because it should get us back to the friend that's buying flowers, it ends once we're out flowers
    }
    std::cout << tot;
    return 0;
}
