#include <iostream>
#include <vector>
#include <iterator>
#include <string>

using std::string;

using namespace std;

char M[7][7] = {{'a','b','a','c','a','x','i'},{'i','a','b','a','c','a','x'},{'x','i','a','b','a','c','a'},{'a','x','i','a','b','a','c'},{'c','a','x','i','a','b','a'},{'a','c','a','x','i','a','b'},{'b','a','c','a','x','i','a'}};

std::vector<std::string> arredores_validos(int a, int b)
{
    std::vector<std::string> l;
    for (int i=-1; i<2; i++)
    {
        for (int j=-1; j<2; j++)
        {
            if ((a + i >= 0) and (a + i <= 6))
            {
                if ((b + j >= 0) and (b + j <= 6))
                {
                    string str1 = to_string(a+i) +','+ to_string(b+j);
                    l.push_back(str1);

                }
            }
        }
    }
    return l;
}

int main()
{

    std::vector<std::string> arredores;

    //for (int i = 0; i< arredores.size(); i++) std::cout << arredores[i]<< "\n";


    std::vector<std::string> b;
    std::vector<std::string> a_2;
    std::vector<std::string> c;
    std::vector<std::string> a_3;
    std::vector<std::string> x;
    std::vector<std::string> i_1;
    std::vector<std::string> lul;
    for (int i=0; i<7; i++)
    {

        for (int j=0; j<7; j++)
        {

            if (M[i][j] == 'a')
            {
                std::vector<std::string> arredores = arredores_validos(i,j);

                for (int k=0; k<arredores.size(); k++)
                {
                    std::string el=arredores[k];

                    //procurando b em arredores de a
                    if ( M[int(el[0])-48][int(el[2])-48] == 'b')
                    {
                        b.push_back(to_string(i)+","+to_string(j)+" "+to_string(int(el[0])-48)+","+to_string(int(el[2])-48));
                    }
                }
            }
        }
    }

    //procurando a em arredores de b
    for (int u=0; u<b.size(); u++)
    {
        int x1 = b[u][b[u].size()-3]-48;
        int y1 = b[u][b[u].size()-1]-48;

        std::vector<std::string> arredores = arredores_validos(x1,y1);

        for (int o=0; o<arredores.size(); o++)
        {
            std::string el = arredores[o];
            if (M[int(el[0])-48][int(el[2])-48] == 'a')
            {
                a_2.push_back(b[u]+" "+to_string(int(el[0])-48)+","+to_string(int(el[2])-48));
            }

        }
    }

        for (int u=0; u<a_2.size(); u++)
    {
        int x1 = a_2[u][a_2[u].size()-3]-48;
        int y1 = a_2[u][a_2[u].size()-1]-48;

        std::vector<std::string> arredores = arredores_validos(x1,y1);

        for (int o=0; o<arredores.size(); o++)
        {
            std::string el = arredores[o];
            if (M[int(el[0])-48][int(el[2])-48] == 'c')
            {
                c.push_back(a_2[u]+" "+to_string(int(el[0])-48)+","+to_string(int(el[2])-48));
            }

        }
    }
        for (int u=0; u<c.size(); u++)
    {
        int x1 = c[u][c[u].size()-3]-48;
        int y1 = c[u][c[u].size()-1]-48;

        std::vector<std::string> arredores = arredores_validos(x1,y1);

        for (int o=0; o<arredores.size(); o++)
        {
            std::string el = arredores[o];
            if (M[int(el[0])-48][int(el[2])-48] == 'a')
            {
                a_3.push_back(c[u]+" "+to_string(int(el[0])-48)+","+to_string(int(el[2])-48));
            }

        }
    }
        for (int u=0; u<a_3.size(); u++)
    {
        int x1 = a_3[u][a_3[u].size()-3]-48;
        int y1 = a_3[u][a_3[u].size()-1]-48;

        std::vector<std::string> arredores = arredores_validos(x1,y1);

        for (int o=0; o<arredores.size(); o++)
        {
            std::string el = arredores[o];
            if (M[int(el[0])-48][int(el[2])-48] == 'x')
            {
                x.push_back(a_3[u]+" "+to_string(int(el[0])-48)+","+to_string(int(el[2])-48));
            }

        }
    }
        for (int u=0; u<x.size(); u++)
    {
        int x1 = x[u][x[u].size()-3]-48;
        int y1 = x[u][x[u].size()-1]-48;

        std::vector<std::string> arredores = arredores_validos(x1,y1);

        for (int o=0; o<arredores.size(); o++)
        {
            std::string el = arredores[o];
            if (M[int(el[0])-48][int(el[2])-48] == 'i')
            {
                i_1.push_back(x[u]+" "+to_string(int(el[0])-48)+","+to_string(int(el[2])-48));
            }

        }
    }


    cout<<"i_1"<<endl;
    for (int i = 0; i< i_1.size(); i++) std::cout << i_1[i]<< "\n";
    cout<<i_1.size()<<endl;



    return 0;
}
