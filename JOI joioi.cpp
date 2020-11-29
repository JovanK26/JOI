#include <bits/stdc++.h>

using namespace std;
int mat[2001][2001];
int n,m;
int maks=0;
int mini=1000000000;
bool check(int med)
{
     int pos=0;
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
         {
             if(mat[i][j]+med<maks)
             {
                 pos=max(pos,j+1);
             }
         }
         for(int j=0;j<m;j++)
         {
             if(mat[i][j]-med>mini)
             {
                 if(j<pos)return 0;
             }
         }
     }
     return 1;
}
void fliprow()
{
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<m;j++)
        {
            swap(mat[i][j],mat[n-i-1][j]);
        }
    }
}
void flipcol()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m/2;j++)
        {
            swap(mat[i][j],mat[i][m-j-1]);
        }
    }
}
int solve()
{
    int l=0;
    int r=maks-mini;
    int med;
    while(l<=r)
    {
        med=(l+r)/2;
        if(check(med))
        {
            r=med-1;
        }
        else
        {
            l=med+1;
        }
    }
    return r+1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> mat[i][j];
            maks=max(maks,mat[i][j]);
            mini=min(mini,mat[i][j]);
        }
    }
    int rez=solve();
    fliprow();
    rez=min(rez,solve());
    flipcol();
    rez=min(rez,solve());
    fliprow();
    rez=min(rez,solve());
    cout << rez;
    return 0;
}
