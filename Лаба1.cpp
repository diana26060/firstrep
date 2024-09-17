#include <iostream>
#include <cmath>
using namespace std;
double Fact(int k)
{
    if (k == 0 || k == 1)
    {
        return 1;
    }
    return k * Fact(k - 1);
}
double Fun(double x)
{
    return (1 / exp(x));
}
double Taylor(double x, int k, double e)
{
    double s = 1; double r = 0;
    for (int i = 1; i < k; i++)
    {
        r = pow(-1, i) * pow(x,i) / Fact(i);
            if (fabs(r) >= e)
            {
                s += r;
            }
            else
            {
                break;
            }
    }
    return s;
}
int main()
{
    
    double x; cout << "Type x" << endl; cin >> x;
    double e; cout << "Type e" << endl; cin >> e;
    int k; cout << "Type k" << endl; cin >> k;

    cout << "Function value=" << Fun(x) << endl;
    cout << "Function value through Taylor=" << Taylor(x, k, e);
}