#include <bits/stdc++.h> 
using namespace std; 
  
int day_of_the_week(int y, int m, int d) 
{  
    int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; 
      
    // if month is less than 3 reduce year by 1 
    if (m < 3) 
        y -= 1; 
      
    return ((y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7); 
} 
  
int main(void) 
{ 
    int day = 23, month = 2, year = 2020; 
    cout<<(day_of_the_week(year, month, day)); 
    return 0 ; 
} 
