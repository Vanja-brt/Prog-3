#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream file("C:\\Users\\p194d\\Downloads\\Anna Karenina-kompresirano.txt");
    ifstream guide("C:\\Users\\p194d\\Downloads\\Anna Karenina-guide.txt");
    ofstream end("C:\\Users\\p194d\\Downloads\\Anna Karenina-vrateno.txt");
    int amount1=0;
    char ch;
    while (file.get(ch)) {
        if (ch=='1') {
            amount1++;
        }
        else {
            string check="0";
            for (int i=0;i<amount1;i++) {
                check="1"+check;
            }
            string line;
            while (getline(guide,line)) {
                if (line==check) {
                    if (line=="1111111111110") {
                        end<<"\n";
                    }
                    else if (line=="0") {
                        end<<" ";
                    }
                    else {
                        getline(guide,line);
                        end<<line;
                    }
                }
            }
            guide.clear();
            guide.seekg(0);
            amount1=0;
        }
    }
    end.close();
}