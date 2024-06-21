#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define sortx(X) sort(X.begin(),X.end());
#define el "\n"
#define yes cout<<"YES"<<el;
#define no cout<<"NO"<<el;
#define MW_HY ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ----------------------------Functions---------------------------- //
long long string_to_num(char c, string word){
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
bool isPrime(ll k)
{
  if (k == 1)
  {
    return false;
  }
  for (ll i = 2; i * i <= k; i++)
  {
    if (k % i == 0)
    {
      return false;
    }
  }
  return true;
}
// ----------------------------------------------------------------- //
void solution(){
  string word;
  cin >> word;
  ll size = word.size();
  bool first_case = false;
  bool cond = false;
  string row = "", column = "";
  for (ll i = 0; i < size; i++)
  {
    if (word[i] == 'R' && !isalpha(word[i+1]) && !cond)
    {
      cond = true;
    }
    else if (word[i] == 'C' && !isalpha(word[i+1]) && cond) 
    {
      first_case = true;
    }
    else if (cond && !first_case)
    {
      row += word[i];
    }
    else if (first_case)
    {
      column += word[i];
    }
  }
  if (first_case && cond) // first case
  {
    string res = "";
    ll x = string_to_num('x', column);
    ll y = x % 26;
    while (x)
    {
      y = x % 26;
      bool con = false;
      if (y == 0)
      {
        res = "Z" + res;
        x -= 26;
      }
      else
      {
        res = (char)(64+y) + res;
        x-= y;
      }
      x /= 26;
    }
    cout << res << row << el;
  }
  else
  {
    row = "";
    for (ll i = 0; i < size; i++)
    {
      if (isalpha(word[i]))
      {
        column += word[i];
      }
      else
      {
        row += word[i];
      }
    }
    ll res = 0;
    for (ll i = 0; i < column.size(); i++)
    {
      res *= 26;
      res += (int)(column[i]-64);
    }
    cout << "R" << row << "C" << res << el;
  }
}

int main(){ MW_HY
  int ntimes  = 1;
  cin >> ntimes;
  while (ntimes--)
  {
    solution();
  }
}