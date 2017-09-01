#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

ofstream f("cal.out");
int x[100],a[100][100],liniePornire,coloanaPornire,n,m,linieCurenta,coloanaCurenta;
int depLin[8]={-2,-1,1,2,2,1,-1,-2},
    depCol[8]={1,2,2,1,-1,-2,-2,-1};

int sol(int k)
{


    if(k==m*n)
        return 1;

  return 0;

}

int cont(int k,int l,int c)
{
        if(l<0 || c<0 || l>=n || c>=m)
        return 0;

    if(a[l][c]!=0)
        return 0;
    else
       return 1;
}

void afisare()
{
  int i,j;
  for(i=0;i<n;i++)
    {
    for(j=0;j<m;j++)
        f<<a[i][j]<<" ";
    f<<endl;
    }
f<<endl;
}
void backtracking(int k, int l, int c)
{
    int i, lnou,cnou;
    if(sol(k))
        afisare();
    else
        for(i=0;i<=7;i++)
        {
            x[k]=i;
            lnou=l+depLin[x[k]];
            cnou=c+depCol[x[k]];
            if(cont(k,lnou,cnou))
            {
                a[lnou][cnou]=k+1;
                backtracking(k+1,lnou,cnou);
                a[lnou][cnou]=0;
                            }
        }



}


int main()
{
    cin>>n>>m;
    cout << "linia de pornire>>";
    cin>>liniePornire;
    cout<<endl;
    cout << "coloana de pornire>>";
    cin>>coloanaPornire;
    cout<<endl;
    linieCurenta=liniePornire;
    coloanaCurenta=coloanaPornire;
    a[linieCurenta][coloanaCurenta]=1;
    backtracking(1, linieCurenta,coloanaCurenta);
    return 0;
}
