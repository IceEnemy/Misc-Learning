#include <bits/stdc++.h>
using namespace std;

int main()
{
	string inp;

    // Read a line of input
    getline(cin, inp);

    // Convert each character in the string to uppercase
    for (char &c : inp) {
        c = toupper(c);
    }

    cout << inp << endl;

    return 0;
}

