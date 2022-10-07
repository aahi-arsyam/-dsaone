#include<iostream>
using namespace std;

/*int digitsum(int n)
{
    if(n==0)
        return 0;
    return digitsum(n/10) + (n%10);
}*/

int digitsum(int n)
{
    if(n<=9)
        return 0;
    return digitsum(n/10) + (n%10);
}

int main()
{
    cout<<digitsum(345);
    return 0;
}