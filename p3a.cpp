#include <iostream>
using namespace std;

template <typename T>
void deliver_emails(int n) 
{
    T* ways = new T[n+1];
    ways[0] = 1;
    ways[1] = 1;
    if (n == 0 || n == 1) 
    {
        cout << "There is " << ways[n] << " way to deliver " << n << " email." << endl;
    }
    else 
    {
        for (int i = 2; i < n + 1; i++) 
        {
            ways[i] = (ways[(i - 1)] + ways[(i - 2)]);
            //cout << ways[i] << endl;
        }
        cout << "There are " << ways[n] << " ways to deliver " << n << " emails." << endl;
    }
    delete[] ways;
}

int main()
{
    int n;
    cout << "Enter the number of Emails: ";
    cin >> n;
    if (n <= 50) 
    {
        deliver_emails<long long int>(n);
    }
    else 
    {
        deliver_emails<double>(n);
    }
    return (0);
}
