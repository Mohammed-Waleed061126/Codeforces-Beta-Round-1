#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el "\n"
#define yes cout<<"YES"<<el;
#define no cout<<"NO"<<el;
#define MW_HY ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;


void solution(){
  ll n, m , a;
  cin >> n >> m >> a;
  ll g = n / a, h = m / a;
  if (n % a)
  {
    g++;
  }
  if (m % a)
  {
    h++;
  }
  cout << h*g;
}

int main(){
  int size  = 1;
  //cin >> size;
  while (size--)
  {
    solution();
  }

}