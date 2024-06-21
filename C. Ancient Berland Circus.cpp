#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <fstream>
const double pi = acos(-1.0);
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define sortx(X) sort(X.begin(),X.end());
#define el "\n"
#define yes cout<<"YES"<<el;
#define no cout<<"NO"<<el;
#define imp cout<<"-1"<<el;
#define Y_N if(cond){yes}else{no}
#define MW_HY ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;
// ----------------------------Functions---------------------------- //
ll string_to_num(char c, string word){
  ll val = 0;
  if (c == 'x')
  {
    for (ll i = 0; i < word.size(); i++)
    {
      val *= 10;
      val += word[i]-48;
    }
  }
  else
  {
    val += c-48;
  }
  return val;
}
ld Gcd(ld x, ld y){
  return fabs(y)<1e-2?x:Gcd(y,fmod(x,y));
}
ld triangle_area(ld a, ld b, ld c){
  ld s = (a+b+c)/2;
  ld res = sqrtf(s*(s-a)*(s-b)*(s-c));
  return res;
}
ld avg(ll size){
  ld val;
  ld sum = 0;
  for (ll i = 0; i < size; i++)
  {
    cin >> val;
    sum += val;
  }
  ld res = sum/size;
  return res;
}
ld distance(ld x1, ld y1, ld x2, ld y2){
  ld d1 = abs(x1-x2), d2 = abs(y1-y2);
  ld dis = sqrtl(d1*d1+d2*d2);
  return dis;
}
ld shoelace(ll vertix, ld arr[][2]){
  ld x = 0, y = 0;
  for (ll i = 0; i < vertix; i++)
  {
    x += arr[i][0]*arr[i+1][1];
  }
  for (ll i = 0; i < vertix; i++)
  {
    y += arr[i][1]*arr[i+1][0];
  }
  ld res = abs(x-y)/2;
  return res;
}
string num_to_string(ll val){
  string word = "";
  while (val)
  {
    ll x = val%10;
    word = (char)(x+48) + word;
    val /= 10;
  }
  return word;
}
string binary_code(ll x){
  string word = "";
  while (x)
  {
    if (x % 2)
    {
      word = '1' + word;
    }
    else
    {
      word = '0' + word;
    }
    x /= 2;
  }
  return word;
}
bool is_prime(ll x){
  if (x == 2)
  {
    return true;
  }
  if (x < 2 || x % 2 == 0)
  {
    return false;
  }
  for (ll i = 3; i <= sqrtl(x); i+=2)
  {
    if (x % i == 0)
    {
      return false;
    }
  }
  return true;
}
bool is_palindrom(string word){
  ll start = 0, end = word.size()-1;
  while (start <= end)
  {
    if (word[start] != word[end])
    {
      return false;
    }
    start++, end--;
  }
  return true;
}
void swap(int x, int y){
  int temp = x;
  x = y;
  y = temp;
}
// ----------------------------------------------------------------- //

void solution(){
  ld arr[4][2];
  for (ll i = 0; i < 3; i++)
  {
    cin >> arr[i][0] >> arr[i][1];
    if (i == 0)
    {
      arr[3][0] = arr[i][0];
      arr[3][1] = arr[i][1];
    }
  }
  ld a = distance(arr[0][0],arr[0][1],arr[1][0],arr[1][1]);
  ld b = distance(arr[1][0],arr[1][1],arr[2][0],arr[2][1]);
  ld c = distance(arr[0][0],arr[0][1],arr[2][0],arr[2][1]);
  ld t_area = shoelace(3,arr);
  ld R = (a*b*c)/(4*t_area);
  ld A = acos(((a*a)-(b*b)-(c*c))/(-2*b*c));
  ld B = acos(((b*b)-(a*a)-(c*c))/(-2*a*c));
  ld C = acos(((c*c)-(a*a)-(b*b))/(-2*a*b));
  ld n = Gcd(A,Gcd(B,C));
  double res = 1.570796 / n * R * R * sin(2 * n);
  cout << fixed << setprecision(6) << res << el;
}

int main(){ MW_HY
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  int ntimes = 1;
  //cin >> ntimes;
  while (ntimes--)
  {
    solution();
  }
}