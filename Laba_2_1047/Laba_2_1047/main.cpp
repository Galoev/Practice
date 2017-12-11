#include <iostream>
#include <math.h>

using namespace std;

int main_() {
    double a0, an_1, n=0;
    double *c = new double[n];
    cin>>n;
    cin>>a0;
    cin>>an_1;
    
    for (int i=1; i<=n; i++)
        cin>>c[i];
    
    double sum = 0;
    
    for (int i=1; i<=n; i++)
        sum +=(n+1-i)*c[i];
    
    double a1;
    //a1 = an_1/(n+1) + (a0*n)/(n+1) - sum;
    a1=(a0+n*an_1-2*sum)/(n+1);
    std::cout.setf(std::ios_base::fixed,std::ios_base::floatfield);
    cout.precision(2);
    cout << a1;
    //printf("%.2f",a1);
    return 0;
}

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{ double a,b,x,c[3003],s=0,k=0;       int i,n;
    cin>>n;
    cin>>a>>b;
    for(i=1; i<=n; i++) cin>>c[i];
    for(i=1; i<=n; i++) {s+=c[i]; k+=s; }
    x=(a*n+b-2*s)/(n+1);
    cout<<setiosflags(ios::fixed|ios::showpoint)<<setprecision(2)<<x;
    return 0;
    
}



