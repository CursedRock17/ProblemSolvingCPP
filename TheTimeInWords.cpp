#include <bits/stdc++.h>

//Library that implements most library^

int h;
int i;
int m;
int ml;
std::vector<std::string> hour{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve"};
std::vector<std::string> minute{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "quarter", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine", "thirty"};



//if it's before x:30 then its past x, otherwise if its x: >30 its to next hour;
//But for those thirty we need that time in minutes, vectors can directly corrolate to numbers so they're perfect;

std::string hr;
std::string min;
int main(){
    
    std::cin >> h;
    std::cin >> m;
    
  //Simple input of the hours(h) and minutes(m)
  
  /*
  So for the following lines, they want us to use minutes past, before 30 minutes, but 30 mins and greater use minutes to
  We need to leave spaces out for our outliars in the question examples such as: Five oclock (5:00) which shouldn't mention
  minutes at all.
  
  The odd ones out are: The exact hour, at quarter of an hour, at half an hour, and at 1 past the minute
  */
  
    if(m < 15 && m > 1){
    min = minute[m - 1];
    std::cout << min << ' ' << "minutes past" << ' ';
        hr = hour[h - 1];
    std::cout << hr << ' ';
    }
    else if(m > 15 && m <= 29){
    min = minute[m - 1];
    std::cout << min << ' ' << "minutes past" << ' ';
        hr = hour[h - 1];
    std::cout << hr << ' ';
    }
    else if(m > 30 && m <= 44){
    m = 60 - m;
    min = minute[m - 1];
    std::cout << min << ' ' << "minutes to" << ' ';
    hr = hour[h];
    std::cout << hr << ' ';
    }
    else if(m > 30 && m > 45){
    m = 60 - m;
    min = minute[m - 1];
    std::cout << min << ' ' << "minutes to" << ' ';
    hr = hour[h];
    std::cout << hr << ' ';
    }
    else if(m == 00){
        hr = hour[h - 1];
        std::cout << hr << ' ' << "o' clock";
    }
    else if(m == 30){
    min = minute[m - 1];
    std::cout << "half past" << ' ';
        hr = hour[h - 1];
    std::cout << hr << ' ';
    }
    else if(m == 15){
    min = minute[m - 1];
    std::cout << min << ' ' << "past" << ' ';
        hr = hour[h - 1];
    std::cout << hr << ' ';
    }
    else if(m == 1){
    min = minute[m - 1];
    std::cout << min << ' ' << "minute past" << ' ';
        hr = hour[h - 1];
    std::cout << hr << ' ';
    }
    else if(m == 45){
    min = minute[m - 1];
    std::cout << "quarter to" << ' ';
        hr = hour[h];
    std::cout << hr << ' ';
    }
    return 0;
}
