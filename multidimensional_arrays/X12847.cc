#include <iostream>
#include <vector> 
using namespace std;
 
typedef vector< vector<bool> > Board;
 
const int N = 10;
 
void dibuixar_tauler(const Board& tauler) {
    cout << "  12345678910" << endl;
   
    for (int i = 0; i < N; ++i) {
        cout << char(int('a') + i) << ' ';
        for (int j = 0; j < N; ++j) {
            if (tauler[i][j]) cout << 'X';
            else cout << '.';
        }
        cout << endl;
    }
}
 
void colocar_vaixell(Board& tauler) {
   
    char c1, orientacio;
    int j, mida;
   
    cin >> c1 >> j >> mida >> orientacio;
   
    int i = int(c1 - 'a');
    j = j - 1;
   
    if (orientacio == 'h') {
        for (int k = 0; k < mida; ++k) {
            tauler[i][j+k] = true;
        }
    } else {
        for (int k = 0; k < mida; ++k) {
            tauler[i+k][j] = true;
        }  
    }
}
 
int min(int a, int b) {
    if (a <= b) return a;
    else return b;
}
int max(int a, int b) {
    if (a >= b) return a;
    else return b;
}
 
bool trobar_horizontal(const Board& tauler, int i, int from, int to) {
    for (int j = from; j <= to; ++j) {
        if (tauler[i][j]) return true;
    }
    return false;
}
 
bool trobar_vertical(const Board& tauler, int j, int from, int to) {
    for (int i = from; i <= to; ++i) {
        if (tauler[i][j]) return true;
    }
    return false;
}
 
int calcular_distancia(const Board& tauler, int i0, int j0) {
    int dist = 1;
   
    while (dist <= 10) {
        // Busquem la part de dalt
        if (i0 - dist >= 0) {
            if (trobar_horizontal(tauler, i0-dist, max(0, j0 - dist), min(j0 + dist, N-1))) return dist;
        }
       
        // Busquem la part de baix
        if (i0 + dist < N) {
            if (trobar_horizontal(tauler, i0+dist, max(0, j0 - dist), min(j0 + dist, N-1))) return dist;
        }
       
        // Busquem la part esquerra
        if (j0 - dist >= 0) {
            if (trobar_vertical(tauler, j0-dist, max(0, i0 - dist), min(i0 + dist, N-1))) return dist;
        }
       
        // Busquem la part dreta
        if (j0 + dist < N) {
            if (trobar_vertical(tauler, j0+dist, max(0, i0 - dist), min(i0 + dist, N-1))) return dist;
        }
   
        ++dist;
    }
 
    return dist;
}
 
void processar_tirada(const Board& tauler, int i, int j) {
    cout << char(int('a') + i) << j+1;
   
    if (tauler[i][j]) {
        cout << " tocat!" << endl;
    } else {
        cout << " aigua! vaixell mes proper a distancia " << calcular_distancia(tauler, i, j) << endl;
    }
}
 
int main() {
   
    Board tauler = Board(N, vector<bool>(N, false));
   
    for (int i = 0; i < 10; ++i) colocar_vaixell(tauler);
   
    dibuixar_tauler(tauler);
    cout << endl;
   
    char c;
    int j;
   
    while (cin >> c >> j) {
        int i = int(c - 'a');
        j = j - 1;
        processar_tirada(tauler, i, j);
    }
}
