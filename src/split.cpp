#include <iostream>
#include <sstream>
#include <string>

using namespace std;
int main()
{
    // greet the user
    string name;
    cout << "What is your name? ";
    getline(cin, name);
    cout << "Hello " << name << ", nice to meet you.\n";

    // read file line by line
    istringstream input;
    input.str("1\n2\n3\n4\n5\n6\n7\n");
    int sum = 0;
    for (string line; getline(input, line);)
        sum += stoi(line);
    cout << "\nThe sum is " << sum << ".\n\n";

    // use separator to read parts of the line
    istringstream input2;
    input2.str("a;b;c;d");
    for (string line; getline(input2, line, ';');)
        cout << line << '\n';
}
