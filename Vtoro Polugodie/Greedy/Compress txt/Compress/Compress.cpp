#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream file("C:\\Users\\p194d\\Downloads\\Anna Karenina-nekompresirano.txt");
    if (!file) {
        cout<<"nejke brt";
    }
    char ch;
    map <char,long long> chars;
    while (file.get(ch)) {
        chars[ch]++;
    }
    vector<pair<char,long long>> v;
    for (auto i:chars) {
        v.push_back(i);
    }
    vector<pair<long long, char>> v2(v.size());
    for (int i=0; i<v.size();i++) {
        v2[i].first=v[i].second;
        v2[i].second=v[i].first;
    }
    sort(v2.begin(),v2.end());
    for (int i=v.size()-1; i>=0;i--) {
        v[v.size()-1-i].first=v2[i].second;
        v[v.size()-1-i].second=v2[i].first;
    }
    vector<pair<char,string>> f(v.size());
    string o="0";
    for (int i=0;i<v.size();i++) {
        f[i].first=v[i].first;
        f[i].second=o;
        o="1"+o;
    }
    ofstream file2("C:\\Users\\p194d\\Downloads\\Anna Karenina-guide.txt");
    for (int i=0;i<f.size();i++) {
        file2<<f[i].second<<endl;
        file2<<f[i].first<<endl;
    }
    file2.close();
    ofstream file3("C:\\Users\\p194d\\Downloads\\Anna Karenina-kompresirano.txt");
    file.clear();
    file.seekg(0);
    while (file.get(ch)) {
        for (int i=0;i<f.size();i++) {
            if (f[i].first==ch) {
                file3<<f[i].second;
            }
        }
    }
}