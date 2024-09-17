#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int k,b = 1;
    cout<<"Type k: ";
    cin>>k;
   double x, kk = 0.1, s = 1, res = 1, ex, d;
   cout<<"Type x: ";
   cin>>x;
   for(int i = 1; i < k; i++){
    kk *= 0.1;
   }
   while(fabs(s) >= kk){
    s *= x;
    s /= b;
    if (b % 2 == 1)
    res -= s;
    else res += s;
    b++;
   }
   ex = 1 / (exp(k));
cout<<"ex: "<<ex<<endl;
cout<<"res: "<<res<<endl;
d = fabs(res - ex);
cout<<d;
return 0;

}