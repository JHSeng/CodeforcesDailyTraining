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
#define int int32_t
#define ll int64_t
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
#define inf 0x3f3f3f3f
//namespace
using namespace std;
//header end

int t,L,v,l,r;

int main()
{   
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d%d%d",&L,&v,&l,&r);
        if (r-l+1>=L) puts("0");
        else
        {
            ll ans=0,sum=L/v,mod=l%v;
            if (!mod) ans=sum-((r-l)/v+1);
            else ans=sum-((r-l+mod)/v);
            printf("%lld\n",ans);
        }
    }
    return 0;
}