#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector< vector<char> > sopa;
typedef vector< vector<int> > score;

int maxpunt(const sopa& a, const score& b, string word, bool& found) {
    int y = a.size();
    int x = a[0].size();
    int siz = word.size();
    int max = 0;
    
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            if (y - i >= siz) {
                bool esta = true;
                int sum = 0;
                int aux = 0;
                while (esta and aux < siz) {
                    if (word[aux] == a[i + aux][j]) {
                        sum += b[i + aux][j];
                        ++aux;
                    }
                    else esta = false;                
                }
                if (esta) {
                    if (sum > max)max = sum;
                    found = true;
                } 
            }

            if (x - j >= siz) {
                bool esta = true;
                int sum = 0;
                int aux = 0;
                while (esta and aux < siz) {
                    if (word[aux] == a[i][j + aux]) {
                        sum += b[i][j + aux];
                        ++aux;
                    }
                    else esta = false;                       
                }
                if (esta) {
                    if (sum > max)max = sum;
                    found = true;
                }
            }
        }
    }
    return max;
}

int main() {
    int x, y;
    while (cin >> y >> x) {        
        sopa a(y, vector<char> (x));

        for (int i = 0; i < y; ++i) {
            for (int j = 0; j < x; ++j) {
                cin >> a[i][j];
            }
        }

        score b(y, vector<int> (x));

        for (int i = 0; i < y; ++i) {
            for (int j = 0; j < x; ++j) {
                cin >> b[i][j];
            }
        }

        int n;
        cin >> n;
        vector <string> llista(n);
        for (int i = 0; i < n; ++i) cin >> llista[i];
        
        for (int i = 0; i < n; ++i) {
            bool found = false;
            int max = maxpunt(a, b, llista[i], found);
            if (not found) cout << "no" << endl;
            else cout << max << endl;
        }
    }   
}
