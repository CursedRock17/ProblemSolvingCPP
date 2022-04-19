#include <bits/stdc++.h>

//Imports all the major libraries^

int elements, k;
int j, i, h;
int n;
unsigned long int tot = 10000000000000;
int cur;
std::vector<int> arr;

int main(){
    std::cin >> elements;
    std::cin >> k;
    for(i = 0; i < elements; ++i){
        std::cin >> n;
        arr.push_back(n);
        n = 0;
    }
    std::sort(arr.begin(), arr.end());
    //After sorted we should create a for-loop that moves through groups of k, then find the min and max and subtract, we store it in tot and do it until the end
    for(j = 0; j < elements - (k - 1); ++j){
        cur = (arr[j + (k - 1)]) - (arr[j]);
        if(cur < tot){
            tot = cur;
        }
        cur = 0;
    }
    std::cout << tot;
    return 0;
}
