#include <iostream>

using namespace std;

int main()
{
    cout << (!false) << endl;
    cout << (false || true) << endl;
    cout << (false && true) << endl;
    cout << ( (10==11) && (false && true) && false ) << endl;

    return 0;
}
