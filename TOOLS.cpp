#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

const int INF = 2000000000;
const int MOD = 10007;

typedef long long Long;
typedef double DD;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define sf scanf
#define pf printf
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define REPI(i,a,b,c) for(int i=a; i<=b; i+=c)
#define REPR(i,a,b) for(int i=b; i>=a; --i)
#define REPRD(i,a,b,c) for(int i=b; i>=a; i-=c)
#define REPB(i,a) for(int i=a; ;i++)
#define REPRB(i,a) for(int i=a; ; i--)
#define mp(a,b) make_pair(a,b)
#define fs first
#define sc second
#define SZ(s) ((int)s.size())
#define PI 3.141592653589793
#define VS vector<string>
#define VI vector<int>
#define VD vector<DD>
#define VL vector<Long>
#define VVL vector<VL >
#define lim 17
#define tlim (1<<((int)ceil(log2(lim))+1))
#define unq(vec) stable_sort(vec.begin(),vec.end());\
vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())));
#define BE(a) a.begin(),a.end()
#define rev(a) reverse(BE(a));
#define sorta(a) stable_sort(BE(a))
#define sortc(a) sort(BE(a),comp)

int DP[lim][(1<<lim)], X[lim], Y[lim], dist[lim][lim], K;

int REC(int pos, int mask)
{
    int &ret = DP[pos][mask], tmp;
    tmp = mask&((1<<(K+1))-1);
    tmp = __builtin_popcount(tmp);
    if(tmp==(K+1)) return dist[pos][0];
    if(~ret) return ret;
    ret = INF;
    REP(i,1,(K))
    {
        if((mask&(1<<i))==0)
        {
            if((mask&(1<<(i+K)))!=0)
            {
                tmp = mask | (1<<i);
                tmp = tmp ^ (1<<(i+K));
                ret = min(ret,REC(i,tmp)+dist[pos][i]);
            }
        }
    }
    tmp = (mask>>(K+1));
    if(__builtin_popcount((tmp))<2)
    {
        REP(i,K+1,(2*K))
        {
            if((mask&(1<<i))==0 and (mask&(1<<(i-K)))==0)
            {
                ret = min(ret,REC(i,(mask|(1<<i)))+dist[pos][i]);
            }
        }
    }
    return ret;

}
int main(int argc, const char **argv)
{
    ios::sync_with_stdio(false);
    //double st=clock(),en;
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w+",stdout);
    int Test;
    cin>>Test;
    REP(i,1,Test)
    {
        cin>>K;
        X[0] = Y[0] = 0;
        REP(j,1,K)
        {
            cin>>X[j]>>Y[j]>>X[j+K]>>Y[j+K];
        }
        REP(j,0,(2*K))
        {
            REP(k,0,(2*K))
            {
                dist[j][k] = abs(X[j]-X[k]) + abs(Y[j]-Y[k]);
            }
        }
        mem(DP,-1);
        int RES = REC(0,1);
        cout<<RES<<"\n";
    }
    //en=clock();
    //cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    return 0;
}

