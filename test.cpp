#include "Cipher.h"
#include "Caesar.h"
#include "RailFence.h"
#include "Ong.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string message;
    cout << "Input ";
    getline(cin, message);
    Caesar num1(message, false, 4);
    num1.Encrypt();
    cout << num1.GetMessage() << endl;
    num1.Decrypt();
    cout << num1.GetMessage() << endl;
    RailFence num2(message, false, 6);
    num2.Encrypt();
    cout << num2.GetMessage() << endl;
    num2.Decrypt();
    cout << num2.GetMessage() << endl;
    Ong num3(message, false);
    num3.Encrypt();
    cout << num3.GetMessage() << endl;
    num3.Decrypt();
    cout << num3.GetMessage() << endl;
}