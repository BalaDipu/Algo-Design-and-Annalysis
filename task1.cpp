#include<bits/stdc++.h>
using namespace std;
vector<string> tokens;
int value[1000];
int base_value(int base, string s)
{
    int base_sum = 0;
    int rad = 0;
    for (int i = 0; i < s.size(); i++)
    {
        rad = ((int)s[i]) * pow(base, i);
        base_sum = (base_sum + rad) % 997;
    }
    return base_sum;
}
void stringTokenize(string line)
{
    stringstream check1(line);
    string intermediate;
    while (getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }
}
int main()
{
    int base = 26;
    string s;
    getline(cin, s);
    stringTokenize(s);
    for (int i = 0; i < tokens.size(); i++)
    {
        int base_sum = base_value(base, tokens[i]);
        value[base_sum]++;
    }

    int cnt = 0;
    for (int i = 0; i < 1000; i++)if (value[i])cnt++;
    cout << cnt << endl;
}
