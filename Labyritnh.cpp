#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pll pair<ll, ll>
#define vl vector<ll>
#define pb push_back
#define pp pop_back
#define f(i, a, b) for (ll i = a; i < b; ++i)
#define rev(i, a, b) for (ll i = a; i >= b; --i)
#define print(x) cout << x << endl
#define endl '\n'
#define F first
#define S second
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define to(n) to_string(n)
#define low(v, n) lower_bound(v.begin(), v.end(), n) - v.begin()
#define upp(v, n) upper_bound(v.begin(), v.end(), n) - v.begin()
#define mod 1000000007
#define mex 100005
string s[1001];
bool vis[1001][1001];
ll dis[1001][1001];
pll parent[1001][1001];
ll n, m;
string path;
ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};
queue<pll> q;

bool valid(ll x, ll y)
{
    if (x < 1 || x > n || y < 1 || y > m)
    {
        return false;
    }
    if (vis[x][y] == true || s[x][y] == '#')
    {
        return false;
    }
    return true;
}

void bfs(ll ax, ll ay, ll bx, ll by)
{
    vis[ax][ay] = 1;
    q.push({ax, ay});
    dis[ax][ay] = 0;

    while (q.empty() == false)
    {
        ll nodex = q.front().F;
        ll nodey = q.front().S;
        q.pop();
        f(i, 0, 4)
        {
            if (valid(nodex + dx[i], nodey + dy[i]) == true)
            {
                ll childx = nodex + dx[i];
                ll childy = nodey + dy[i];
                vis[childx][childy] = true;
                dis[childx][childy] = dis[nodex][nodey] + 1;
                parent[childx][childy] = {nodex, nodey};

                q.push({childx, childy});
            }
        }
    }

    if (vis[bx][by] == false)
    {
        print("NO");
        return;
    }

    print("YES");
    print(dis[bx][by]);

    pll current = {bx, by};
    pll destination = {ax, ay};
    while (current != destination)
    {
        pll k = parent[current.F][current.S];

        if (k.F == current.F - 1)
        {
            path.pb('D');
        }
        if (k.F == current.F + 1)
        {
            path.pb('U');
        }
        if (k.S == current.S - 1)
        {
            path.pb('R');
        }
        if (k.S == current.S + 1)
        {
            path.pb('L');
        }

        current = k;
    }

    reverse(path.begin(), path.end());

    print(path);
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    ll ax, ay, bx, by;
    string r;
    f(i, 1, n + 1)
    {
        cin >> r;
        r = "a" + r;
        s[i] = r;

        f(j, 1, m + 1)
        {
            if (s[i][j] == 'A')
            {
                ax = i;
                ay = j;
            }
            if (s[i][j] == 'B')
            {
                bx = i;
                by = j;
            }
        }
    }

    bfs(ax, ay, bx, by);

    return 0;
}

