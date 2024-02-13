#include <iostream>
#include <string>
using namespace std;

int main(){
    int B, G;
    cin >> B >> G;
    string s = B > G ? "Bat" : "Glove";
    cout << s << endl;
    return 0;
}