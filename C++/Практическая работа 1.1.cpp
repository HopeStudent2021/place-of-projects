/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int main()
{
    float a, b, d, k, x, y;
    
    
    cout<<"a = ";
    cin >> a;
    
    cout<<"b = ";
    cin >> b;
    
    cout<<"x = ";
    cin >> x;
    
    cout<<"y = ";
    cin >> y;
    
    cout<<"k = ";
    cin >> k;
    
    d = (pow(k, (-atan(x))) - a* sqrt(6) - cos(3*a*b))/ (pow((sin(a* asin(x)+log(y))),2));
    
    cout<<"d = " << round(d*1000)/1000;
    
    

    return 0;
}