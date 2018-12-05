//basic
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <algorithm>
#include <cmath>
#include <array>
#include <cstdint>
#include <iterator>
//STL
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
//define
// #define int int32_t
// #define ll int64_t
#define ll long long 
#define dou double
#define pb push_back
#define mp make_pair 
#define fir first
#define sec second
#define init(a,b) fill(begin(a),end(a),b)
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define rep0(i,a,b) for(int i=a;i<b;i++)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
//namespace
using namespace std;
//header end

int n,x;
set<int>s;

int main()
{
	s.clear();
	scanf("%d%d",&n,&x);
	rep1(i,1,n)
	{
		int k; scanf("%d",&k); s.insert(k);
	}
	int ans=0;
	rep1(i,0,x-1) if (!s.count(i)) ans++;
	if (s.count(x)) ans++;
	printf("%d\n",ans);
	return 0;
}