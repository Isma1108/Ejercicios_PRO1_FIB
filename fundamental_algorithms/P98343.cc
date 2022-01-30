#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const string unidades[] = {"zero", "un", "dos", "tres", "quatre", "cinc",
"sis", "set", "vuit", "nou", "deu", "onze", "dotze", "tretze", "catorze",
"quinze", "setze", "disset", "divuit", "dinou"};

const string decenas[] = {"?", "?", "?", "trenta", "quaranta", "cinquanta", "seixanta",
"setanta", "vuitanta", "noranta"};

string desencolar(queue<string>& ret) {
    string res;
    while (!ret.empty()) {
        if (ret.front() != "") {
            res += ret.front();
            if (ret.size() > 1) {
                res += " ";
            }
        }
        ret.pop();
    }
    return res;
}

string small2word(string num) {
    if (num.size() == 0 or num == "000") {
        return "";
    }
    while (num.size() >= 2 and num[0] == '0') {
        num.erase(num.begin());
    }
    queue<string> ret;
    if (num.size() == 1) {
        ret.push(unidades[num[0] - '0']);
    } else {
        if (num.size() == 3) {
            if (num[0] == '1') {
                ret.push("cent");
            } else {
                ret.push(unidades[num[0] - '0'] + "-cents");
            }
        }
        int k = (num.size() == 2 ? -1 : 0);
        if (!(num[1+k] == '0' and num[2+k] == '0')) {
            if (num[1+k] == '0') {
                ret.push(unidades[num[2+k] - '0']);
            } else if (num[1+k] == '1') {
                int numero = (num[1+k] - '0')*10 + (num[2+k] - '0');
                ret.push(unidades[numero]); 
            } else if (num[1+k] == '2') {
                if (num[2+k] == '0') ret.push("vint");
                else ret.push("vint-i-" + unidades[num[2+k] - '0']);
            } else {
                if (num[2+k] == '0') ret.push(decenas[num[1+k] - '0']);
                else ret.push(decenas[num[1+k] - '0'] + "-" + unidades[num[2+k] - '0']);
            }
        }
    }
    return desencolar(ret);
}


string num2word(string num) {
    vector<string> grups(4);
    int lleno_grupo = 3;
    int llenados = 0;
    for (int i = num.size()-1; i >= 0; --i) {
        grups[lleno_grupo].push_back(num[i]);
        ++llenados;
        if (llenados == 3) {
            --lleno_grupo;
            llenados = 0;
        }
    }
    for (auto &k : grups) {
        for (int i = 0; i < k.size()/2; ++i) {
            swap(k[i], k[k.size()-1-i]);
        }
    }
    
    queue<string> ret;
    string res;
    bool algo = false;
    if (!grups[0].empty() and grups[0] != "000") {
        if (grups[0] == "1") {
            ret.push("mil");
        } else if (grups[0] == "2") {
            ret.push("dos");
            ret.push("mil");
        }
        algo = true;
    }

    string tentativa;

    if (algo or (!grups[1].empty() and grups[1] != "000")) {
        tentativa = small2word(grups[1]);
        if (tentativa == "un" and !algo) {
            ret.push("un");
            ret.push("milio");
        } else {
            ret.push(tentativa);
            ret.push("milions");
        }
    }

    if (!grups[2].empty() and grups[2] != "000") {
        tentativa = small2word(grups[2]);
        if (tentativa == "un") {
            ret.push("mil");
        } else {
            ret.push(tentativa);
            ret.push("mil");
        }
    }

    if (!grups[3].empty() and grups[3] != "000") {
        tentativa = small2word(grups[3]);
        ret.push(tentativa);
    }

    return desencolar(ret);
}

int main() {
    string num;
    while (cin >> num) {
        cout << num << ": " << num2word(num) << "." << endl;
    }
}
