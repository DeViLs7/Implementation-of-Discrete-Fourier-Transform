#include<iostream>
#include<math.h>
#include<string.h>
#define eps 0.000001
using namespace std;
float x[1005];
int  n, N, k;
struct Complex
{
       float r,i;
       Complex(float x = 0, float y = 0)
       {
              r = x;
              i = y;
              if (fabs(r) <= eps)
                 r = 0;
              if (fabs(i) <= eps)
                 i = 0;
       } 
       void printNumber()
       {
            if (r != 0)
               cout << r; 
            if (i < 0)
               cout << "-";
            else if (i > 0 && r != 0)
               cout << "+";
            if (i != 0)
               cout <<  fabs(i) << "j";
            cout << " "; 
       }      
};
Complex produceNumber(int n, int N, int k)
{
        float PI = acos(-1);
        Complex ret(cos((2 * PI * n * k) / N), -1 *  sin((2 * PI * n * k) / N));
        return ret;
}
Complex mulNumber(Complex c, float i)
{       Complex ret(i * c.r, i * c.i);
        return ret;
}
Complex addComplex(Complex n1, Complex n2)
{
        Complex ret(n1.r + n2.r, n1.i + n2.i);
        return ret;
}
float modComplex(Complex n)
{
        float ret;
        ret = sqrt(pow(n.r, 2) + pow(n.i, 2));
        return ret;
}
float angleComplex(Complex n)
{
      float ret;
      float PI = acos(-1);
      if (fabs(n.r) <= eps && n.i > 0)
         return 90;
      else if (fabs(n.r) <= eps && n.i < 0)
          return 270;
      ret = atan(fabs(n.i)/fabs(n.r)) * 180 / PI; 
      if (n.r >= 0 && n.i >= 0)
         return ret;
      else if (n.r < 0 && n.i > 0)
         return 180 - ret;
      else if (n.r > 0 && n.i < 0)
         return 360 - ret;
      return 180 + ret;
}
Complex tw[1005][1005], res[1005];
int main()
{
    int i, j, k;
    memset(x, 0, sizeof(x));
    cout << "Please,Enter n\n";
    cin >> n;
    cout << "Please,Enter x(n)\n";
    for (i = 0; i < n; ++i)
        cin >> x[i];
    cout << "Please,Enter N\n";
    cin >> N;
    k = N;
    for (i = 0; i < k; ++i)
        for (j = 0; j < N; ++j)
            tw[i][j] = produceNumber(j, N, i);
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j)
            res[i] = addComplex(res[i],  mulNumber(tw[i][j], x[j]));
    cout << "Modulas of values are : ";
    for (i = 0; i < N - 1; ++i)
        cout << modComplex(res[i]) << ", ";
    cout << modComplex(res[N-1]) << "\n";
    cout << "Angels of values are : ";
    for (i = 0; i < N - 1; ++i)
        cout << angleComplex(res[i]) << ", ";
    cout << angleComplex(res[N - 1]) << "\n"; 
    return 0;
}
