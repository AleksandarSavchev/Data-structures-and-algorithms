#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
struct Node
{
    int num;
    char sym;
    Node* nsym[30];
    Node() :num(0), sym('!') { for (int i = 0; i<30; i++)nsym[i] == nullptr; }
};
struct Trie
{
    Node* root;
    Trie() {root = new Node;}
    void Add(string a)
    {
        int j, br = 0;
        char b;
        Node* temp = root;
        Node* temp1 = new Node;
        int n = a.size();
        for (int i = 0; i<n; i++)
        {
            b = a[i];
            j = b - 97;
            if (temp->nsym[j] == nullptr)
            {
                if (br == 0)
                cout << b;
                temp1=new Node;
                temp1->sym = b;
                temp->nsym[j] = temp1;
                temp = temp1;
                br++;
            }
            else
            {
                if (br == 0)
                    cout << b;
                temp = temp->nsym[j];
            }
        }
        if (temp->nsym[29] == nullptr)
        {
            temp1 = new Node;
            temp1->num = 1;
            temp->nsym[29] = temp1;
        }
        else
        {
            temp1 = temp->nsym[29];
            temp1->num++;
            cout << " " << temp1->num;
        }
        cout << endl;
    }
};

int main()
{
    string a;
    int n;
    Trie tree;
    cin >> n;
    cin.ignore();
    for (int i = 0; i<n; i++)
    {
        getline(cin, a);
        tree.Add(a);
        a.clear();
    }
    return 0;
}