#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("fisier.in");

int main()
{
    int stari, n, m, p, x, y, z, q[500][500], stare_curenta, starifinale[100];
    char alfabet[100];

    fin >> stari >> n;

    for (int i = 0; i < n; i++)
        fin >> alfabet[i];

    fin >> m;

    for (int i = 0; i < stari; i++)
    {
        for (int j = 0; j < n; j++)
        {
            q[i][j] = -1;
        }
    }

    for (int i = 0; i < m; i++)
    {
        fin >> x >> y >> z;
        q[x][y] = z;
    }

    fin >> p;
    for (int i = 0; i < p; i++)
        fin >> starifinale[i];

    /* for (int i = 0; i < stari; i++)
     {
         for (int j = 0; j < n; j++)
         {
             cout << q[i][j] << " ";
         }
         cout << endl;
     } */


    string cuvant;
    cin >> cuvant;

    stare_curenta = 0;
    vector<int> drum;
    drum.push_back(stare_curenta);

    for (int i = 0; i < cuvant.length(); i++)
    {
        int litera = -1;
        for (int j = 0; j < n; j++)
        {
            if (alfabet[j] == cuvant[i])
            {
                litera = j;
                break;
            }
        }
        if (litera == -1)
        {
            cout << "Cuvantul contine caractere invalide!" << endl;
            return 0;
        }

        if (q[stare_curenta][litera] == -1)
        {
            cout << "Cuvantul nu este acceptat!" << endl;
            return 0;
        }
        else
        {
            stare_curenta = q[stare_curenta][litera];
            drum.push_back(stare_curenta);
        }
    }

    bool este_stare_finala = false;
    for (int i = 0; i < p; i++)
    {
        if (stare_curenta == starifinale[i])
        {
            este_stare_finala = true;
            break;
        }
    }

    if (!este_stare_finala)
    {
        cout << "Cuvantul nu este acceptat!" << endl;
        return 0;
    }

    cout << "Cuvantul este acceptat. Drumul parcurs este: ";
    for (int i = 0; i < drum.size(); i++)
    {
        cout << drum[i] << " ";
    }
    cout << endl;

    return 0;
}

/*4 
3
0 1 2
5
0 1 0 
0 0 1
1 1 0 
1 0 2
2 2 3
2
1 3*/