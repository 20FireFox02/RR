#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int readfile(vector <vector <int>>&);
int transposition(vector <vector <int>>&, vector <vector <int>>&);
int dfs(int, vector <vector <int>>&, vector <int>&, vector <bool>&);
int dfstr(int, vector <vector <int>>&, vector <int>&, vector <bool>&);
int bypasscomp(int, int, vector <vector <int>>&, vector <vector <int>>&, vector <vector <int>>&, vector <bool>&);

int main()
{
    vector <vector <int>> graf;
    vector <vector <int>> graftr;
    vector <vector <int>> grafcomp;
    vector <vector <int>> grafcon;
    vector <int> order;
    vector <int> componenta;
    vector <bool> usedv;
    vector <bool> usedcomp;

    setlocale(LC_ALL, "rus");

    readfile(graf);

    transposition(graf, graftr);

    for (int i = 0; i < graf.size(); i++)
        usedv.push_back(false);

    for (int i = 0; i < graf.size(); i++)
        if (!usedv.at(i))
            dfs(i, graf, order, usedv);

    int q = 1;

    for (int i = 0; i < order.size(); i++)
        usedv.at(i) = false;

    for (int i = order.size() - 1; i >= 0; i--)
        if (!usedv.at(order.at(i) - 1)) {
            dfstr(order.at(i) - 1, graftr, componenta, usedv);
            grafcomp.push_back(componenta);
            cout << "\nКомпонента " << q << ":   ";
            for (int j = 0; j < componenta.size(); j++)
                cout << componenta.at(j) << "   ";
            componenta.clear();
            q++;
        }

    for (int i = 0; i < grafcomp.size(); i++)
        usedcomp.push_back(false);

    for (int i = 0; i < grafcomp.size(); i++) {
        grafcon.push_back({ i + 1 });
        for (int j = 0; j < usedcomp.size(); j++)
            usedcomp.at(j) = false;
        for (int j = 0; j < grafcomp[i].size(); j++)
            bypasscomp(grafcomp[i].at(j) - 1, i, graf, grafcomp, grafcon, usedcomp);
    }

    cout << "\n\nГраф конденсации:\n" << endl;
    cout << grafcon.size() << endl;
    for (int i = 0; i < grafcon.size(); i++) {
        cout << "\n";
        for (int j = 0; j < grafcon[i].size(); j++)
            cout << grafcon[i].at(j) << "   ";
    }

    cout << endl << endl;

    return 0;
}

int readfile(vector <vector <int>>& graf)
{
    int size;
    string name;

    cout << "Введите номер графа (файла):    ";
    cin >> name;
    name += ".txt";

    ifstream file(name);
    string s;
    getline(file, s);
    size = stoi(s);

    for (size_t i = 0; i < size; i++) {
        graf.push_back(vector<int>());
        getline(file, s);
        string tmp;
        for (char j : s) {
            if (j != ' ') {
                tmp += j;
            }
            else {
                graf[i].push_back(stoi(tmp));
                tmp = "";
            }
        }
        graf[i].push_back(stoi(tmp));
    }

    file.close();

    return 0;
}

int transposition(vector <vector <int>>& graf, vector <vector <int>>& graftr)
{
    for (int i = 0; i < graf.size(); i++)
        graftr.push_back({ i + 1 });

    for (int i = 0; i < graf.size(); i++)
        for (int j = 1; j < graf[i].size(); j++)
            graftr[graf[i].at(j) - 1].push_back(i + 1);

    return 0;
}

int dfs(int v, vector <vector <int>>& graf, vector <int>& order, vector <bool>& usedv)
{
    usedv.at(v) = true;

    for (size_t i = 1; i < graf[v].size(); i++)
        if (!usedv.at(graf[v].at(i) - 1))
            dfs(graf[v].at(i) - 1, graf, order, usedv);

    order.push_back(v + 1);

    return 0;
}

int dfstr(int v, vector <vector <int>>& graftr, vector <int>& componenta, vector <bool>& usedv)
{
    usedv.at(v) = true;
    componenta.push_back(v + 1);
    for (size_t i = 1; i < graftr[v].size(); i++)
        if (!usedv.at(graftr[v].at(i) - 1))
            dfstr(graftr[v].at(i) - 1, graftr, componenta, usedv);

    return 0;
}

int bypasscomp(int v, int c, vector <vector <int>>& graf, vector <vector <int>>& grafcomp, vector <vector <int>>& grafcon, vector <bool>& usedcomp)
{
    for (int i = 0; i < grafcomp.size(); i++) {
        if (i == c)
            continue;
        for (int j = 0; j < grafcomp[i].size(); j++)
            for (int k = 1; k < graf[v].size(); k++)
                if (graf[v].at(k) == grafcomp[i].at(j))
                    if (!usedcomp[i]) {
                        usedcomp[i] = true;
                        grafcon[c].push_back(i + 1);
                    }
    }

    return 0;
}