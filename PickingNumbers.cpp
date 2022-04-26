#include <bits/stdc++.h>

std::vector<int> vec;
int i, g, h;
int n; //size of vector
int a;
int pos, neg; //Positive and Negatibe
int cur, tot; 

int main(){
    std::cin >> n;
    for(i = 0; i < n; ++i){
        std::cin >> a;
        vec.push_back(a);
        a = 0;
    }
    
    for(g = 0; g < n; ++g){
        for(h = 0; h < n; ++h){
            if(vec[h] < 0){
                vec[h] = vec[h] * -1;
            }
            
            cur = vec[g] - vec[h];
            if(cur == 0 || cur == 1){
                pos++;
            }
            else if(cur == 0 || cur == -1){
                neg++;
            }
            
            
            if(tot < neg || tot < pos){
                
                if(neg >= pos){
                    tot = neg;
            }
            
            else if(pos >= neg){
                    tot = pos;
            }
                
            }
            
        }
        
        pos = 0;
        neg = 0;
    }
    std::cout << tot;
    return 0;
}

//Time Complexity: O(N^2)
