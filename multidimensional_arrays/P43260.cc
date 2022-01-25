#include <iostream>
#include <vector>
using namespace std;
void print(vector <vector <char> >& v) {for (int i=0; i<v.size(); ++i) {cout<<"|"; for (int j=0; j<v[0].size(); ++j){cout<<v[i][j];} cout<<"|"<<endl;}}

vector <vector <char> > cruz_recursiva(vector <vector <char> >& v, int n) {
    if (n==0) return v;
    int vx=v[0].size(), vy=v.size();
    vector <vector <char> > c((3*vy), vector <char> ((3*vx),' '));
    int x, y;
   
    x=vx;
    y=0;
    for (int i=0; i<vy; ++i) for (int j=0; j<vx; ++j) c[i+y][j+x] = v[i][j];
   
    x=0;
    y=vy;
    for (int i=0; i<vy; ++i) for (int j=0; j<vx; ++j) c[i+y][j+x] = v[i][j];
   
    x=vx;
    y=vx;
    for (int i=0; i<vy; ++i) for (int j=0; j<vx; ++j) c[i+y][j+x] = v[i][j];
   
    x=vx*2;
    y=vy;
    for (int i=0; i<vy; ++i) for (int j=0; j<vx; ++j) c[i+y][j+x] = v[i][j];
   
    x=vx;
    y=vy*2;
    for (int i=0; i<vy; ++i) for (int j=0; j<vx; ++j) c[i+y][j+x] = v[i][j];
   
    return cruz_recursiva(c,n-1);
}
 
int main() {
    vector <vector <char> > v(3, vector <char> (3, ' '));
    v[0][1]='|';
    v[2][1]='|';
    v[1][1]='O';
    v[1][0]='-';
    v[1][2]='-';
    int n;
    cin>>n;
    vector <vector <char> > c = cruz_recursiva(v,n-1);   
    print(c);
}
