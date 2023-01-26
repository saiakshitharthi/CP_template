#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define rep(i, n) for (ll i = 0; i < n; i++)
#define mod 1000000007
#define INF 10000000000000000
#define ff first
#define ss second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pie 3.141592653589793238462643383279
#define PYES cout << "YES" << endl
#define PNO cout << "NO" << endl
#define SB(a) sort(a.begin(), a.end(), greater<ll>());
#define SS(a) sort(a.begin(), a.end());
#define vll vector<ll>
#define vpll vector<pll>
#define vvll vector<vll>
#define umll unordered_map<ll, ll>
#define mll map<ll, ll>
#define vbl vector<bool>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template <typename T>
inline void setmin(T &a, T b)
{
    if (a > b)
        a = b;
}
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
vector<bool> prime;
vector<ll> fact, inv, primes, factors, pf;
typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void factorize(ll a)
{
    factors.clear();
    for (ll i = 1; i * i <= a; i++)
    {
        if (i * i == a)
            factors.pb(i);
        else if (a % i == 0)
        {
            factors.pb(i);
            factors.pb(a / i);
        }
    }
    sort(factors.begin(), factors.end());
}

ll power(ll a, ll b)
{
    if (a == 1 || b == 0)
        return 1;
    ll c = power(a, b / 2);
    ll res = 1;
    res = c * c;
    if (res >= mod)
        res %= mod;
    if (b % 2)
        res *= a;
    if (res >= mod)
        res %= mod;
    return res;
}
ll modInv(int a)
{
    return power(a, mod - 2);
}
void factorial(ll n)
{
    fact.resize(n + 1);
    fact[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        fact[i] = fact[i - 1] * i;
        if (fact[i] >= mod)
            fact[i] %= mod;
    }
}
void InvFactorial(ll n)
{
    inv.resize(n + 1);
    inv[0] = 1;
    for (ll i = 1; i <= n; i++)
        inv[i] = modInv(fact[i]);
}
ll ncr(ll n, ll r)
{
    if (n < r || n < 0 || r < 0)
        return 0;
    ll b = inv[n - r];
    ll c = inv[r];
    ll a = fact[n] * b;
    if (a >= mod)
        a %= mod;
    a *= c;
    if (a >= mod)
        a %= mod;
    return a;
}
void remove_duplicates(vpll &v)
{
    sort(v.begin(), v.end());
    ll _size = unique(v.begin(), v.end()) - v.begin();
    v.resize(_size);
}
unsigned ll gcd(unsigned ll u, unsigned ll v)
{
    if (u == 0 || v == 0)
        return max(u, v);
    unsigned ll shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do
    {
        v >>= __builtin_ctz(v);
        if (u > v)
            swap(u, v);
        v -= u;
    } while (v != 0);
    return u << shift;
}
ll sumofdigits(ll n)
{
    ll answer = 0;
    int k = 0;
    while (n)
    {
        k = (n - (n / 10) * 10);
        answer += k;
        n = n / 10;
    }
    return answer;
}
void sieve(ll n)
{
    prime.assign(n + 1, 1);
    prime[1] = false;
    for (ll p = 2; p * p <= n; p++)
    {
        if (prime[p])
        {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (ll i = 2; i < n + 1; i++)
    {
        if (prime[i])
            primes.push_back(i);
    }
}
void prime_sieve(ll n)
{
    pf.assign(n + 1, 0);
    rep(i, n + 1) pf[i] = i;
    for (ll i = 2; i <= n; i++)
    {
        if (pf[i] == i)
        {
            for (ll j = i; j <= n; j += i)
                pf[j] = i;
        }
    }
}
bool IsInt(float m)
{
    if (m - (ll)m == 0)
    {
        return true;
    }
    return false;
}
string getString(char x)
{
    // string class has a constructor
    // that allows us to specify size of
    // string as first parameter and character
    // to be filled in given size as second
    // parameter.
    string s(1, x);

    return s;
}

ll primeFactors(ll n)
{
    // Print the number of 2s that divide n
    ll count = 0;
    while (n % 2 == 0)
    {
        count++;
        n = n / 2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            count++;
            n = n / i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        count++;
    return count;
}
ll faxt(ll n)
{
    ll answer = 1;
    if (n == 0)
    {
        return 1;
    }
    while (n)
    {
        answer = (answer * n) % mod;
        n--;
    }
    return answer % mod;
}
ll npr(ll n, ll r)
{
    ll answer = 1;
    for (ll i = n - r + 1; i <= n; i++)
    {
        answer = (answer * i) % mod;
    }
    return answer;
}
// --------------------------GRAPH ALGORITHMS--------------------------------------------
// DFS
void dfs(ll vt, vector<vll> &adjacencylist, vector<bool> &visited)
{

    if (visited[vt])
    {
        return;
    }
    visited[vt] = true;

    for (auto x : adjacencylist[vt])
    {
        if (visited[x])
        {
            continue;
        }
        else
        {
            dfs(x, adjacencylist, visited);
        }
    }
}
// BFS
void bfs(int vertex, vbl &visited, vvll &adjacencylist)
{
    visited[vertex] = 1;

    queue<ll> pendingvertices;

    pendingvertices.push(vertex);
    while (pendingvertices.size() != 0)
    {

        ll vert = pendingvertices.front();
        pendingvertices.pop();
        for (auto k : adjacencylist[vert])
        {

            if (visited[k])
            {

                continue;
            }

            pendingvertices.push(k);

            visited[k] = 1;
        }
    }
}
/*
    //when graph is given in the form of grid, then adjacencylist is as below:
    for(ll i = 0;i<n*m;i++){
        if(i/m!=0){

            adjacencylist[i].pb(i-m);


        }
        if(i/m!=n-1){
            adjacencylist[i].pb(i+m);
        }
        if(i%m!=0){
            adjacencylist[i].pb(i-1);
        }
        if(i%m!=m-1){
            adjacencylist[i].pb(i+1);
        }
        if(i/m!=0&&i%m!=0){
            adjacencylist[i].pb(i-m-1);
        }
        if(i/m!=0&&i%m!=m-1){
            adjacencylist[i].pb(i-m+1);
        }
        if(i/m!=n-1&&i%m!=0){
            adjacencylist[i].pb(i+m-1);
        }
        if(i/m!=n-1&&i%m!=m-1){
            adjacencylist[i].pb(i+m+1);
        }
    }

    Last 4 are for corners also, that means, corners are also edges, but rest are for adjacent elements are edges

*/
// printing the vector

void printvect(vll &arr)
{
    rep(i, arr.size())
    {
        cout << arr[i] << " ";
    }
}
void dsutemplate()
{
    ll n, m;
    cin >> n >> m;
    vll parent(n + 1, 0);
    rep(i, n + 1)
    {
        if (i > 0)
        {
            parent[i] = i;
        }
    }
    vvll parentrep(n + 1);
    rep(i, n)
    {
        parentrep[i + 1].pb(i + 1);
    }
    while (m--)
    {
        string s;
        cin >> s;
        if (s == "get")
        {
            ll u, v;
            cin >> u >> v;
            if (parent[u] == parent[v])
            {
                cout << "YES" << endl;
                continue;
            }
            cout << "NO" << endl;
            continue;
        }
        else
        {
            ll u, v;
            cin >> u >> v;
            if (parent[u] == parent[v])
            {
                continue;
            }

            ll p1 = parent[u], p2 = parent[v];
            if (parentrep[p1].size() > parentrep[p2].size())
            {
                swap(p1, p2);
            }
            for (auto x : parentrep[p1])
            {
                parent[x] = p2;
                parentrep[p2].pb(x);
            }
            parentrep[p1].clear();
        }
    }
}
//---------------------------------------------------------------------------------------------
void primeFactors(ll n, map<ll, ll> &pfacs)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        pfacs[2]++;
        n = n / 2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            pfacs[i]++;
            n = n / i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        pfacs[n]++;
}
ll pw(ll a, ll b)
{
    ll answer = 1;
    while (b--)
    {
        answer *= a;
    }
    return answer;
}
char changecase(char c)
{
    if (c >= 65 && c <= 90)
    {
        return c + 30;
    }
    return c - 30;
}

void findDivisors(ll n, set<ll> &divisors)
{

    // Note that this loop runs till square root
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            // If divisors are equal, print only one
            if (n / i == i)
                divisors.insert(i);

            else // Otherwise print both
                divisors.insert(i);
            divisors.insert(n / i);
        }
    }
}

ll noofdigts(ll n)
{

    ll count = 0;
    while (n)
    {
        count++;
        n /= 10;
    }
    return count;
}

char pchangecase(char &c)
{
    if (c >= 65 && c <= 90)
    {
        return c + 32;
    }
    return c;
}

void scanvect(vll &arr)
{
    for (auto &x : arr)
    {
        cin >> x;
    }
}
void printmat(vvll &arr)
{
    for (auto &x : arr)
    {
        printvect(x);
        cout << endl;
    }
}
bool isPalindrome(string &s)
{
    string t = s;
    reverse(all(t));
    return (s == t);
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------

void dfs(ll a, vvll &adjacencylist,vll& dist,vbl&visited){
    if(visited[a]){
        return;
    }
    visited[a] = 1;
    for(auto x:adjacencylist[a]){
        if(!visited[x]){

            dist[x] = dist[a]+1;
            dfs(x,adjacencylist,dist,visited);
        }
        
    }

}

ll bit_sum(vll &arr,ll index){
    ll sum = 0;
    while(index!=0){
        sum+=arr[index];
        index = index&(index-1);
    }
    return sum;
}
void bit_update(vll &arr, ll index, ll value){

    while(index<arr.size()){
        arr[index]+=value;
        ll v = index-(index&(index-1));
        index+=v;
    }
}
void solve()
{
    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast();

    ll T = 1;
    // cin >> T;

    for (ll z = 1; z <= T; z++)
    {
        // cout << "Case #" << z << ": ";
        // cout << "test " << z << endl;
        solve();
    }
}