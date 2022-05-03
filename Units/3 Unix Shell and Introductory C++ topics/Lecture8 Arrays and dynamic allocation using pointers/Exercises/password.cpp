#include <iostream>
using namespace std;

int main()
{
    char password[9];  // more memory
    cout<<"Please enter your password and press enter:"; //let user know to enter password and hit enter
    cin >> password;
    password[8] = '\0'; //add the null value to the last index 
    cout << "The password is: " << password << endl;
    return 0;
}
