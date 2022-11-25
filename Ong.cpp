//Title: Ong.cpp
//Author: AJ Koska
//Date: 4/19/22
//Description: The implementation file for Ong class
#include "Ong.h"
const string DASH = "-";
Ong::Ong(){}
Ong::Ong(string message, bool isEncrypted): Cipher(message, isEncrypted){}
Ong::~Ong(){}
bool Ong::IsVowel(char curr_char)
{
    char vowels[10] = {'A', 'E', 'I', 'O', 'U','a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < 10; i++)
    {
        if (curr_char == vowels[i])
        {
            return true;
        }
    }
    return false;
}
void Ong::Encrypt()
{
    string encrypted;
    string curr;
    string message = GetMessage();
    for (int i = 0; i < message.length(); i++)
    {
        curr = "";
        if (IsVowel(message[i]))
        {
            if (i != 0 && (message[i - 1] != ' '))
            {
                curr = DASH + message[i];
            }
            else
            {
                curr = message[i];
            }
        }
        else if ((int(message[i]) < 65) || ((int(message[i]) > 90) && (int(message[i]) < 97)) || (int(message[i]) > 123))
        {
            if (message[i] == ' ' || message[i] == '(')
            {
                curr = message[i];
            }
            else
            {
                curr = DASH + message[i];
            }
        }
        else
        {
            if (i != 0 && (message[i - 1] != ' '))
            {
                curr = DASH + message[i] + ong;
            }
            else
            {
                curr = message[i] + ong;
            }
        }
        encrypted = encrypted + curr;
    }
    SetMessage(encrypted);
    ToggleEncrypted();
}
void Ong::Decrypt()
{
    string message = GetMessage();
    string decrypted = "";
    string curr;
    for (int i = 0; i < message.length(); i++)
    {
        if (IsVowel(message[i]))
        {
            curr = message[i];
            if ((i < message.length() - 1) && message[i + 1] == '-')
            {
                i++;
            }
        }
        else if ((int(message[i]) < 65) || ((int(message[i]) > 90) && (int(message[i]) < 97)) || (int(message[i]) > 123))
        {            
            curr = message[i];
            if (message[i + 1] == '-')
            {
                i++;
            }
        }
        else
        {
            curr = message[i];
            i += 3;
            if ((i < message.length() - 1) && message[i + 1] == '-')
            {
                i++;
            }
        }
        decrypted = decrypted + curr;
    }
    SetMessage(decrypted);
    ToggleEncrypted();
}
string Ong::ToString()
{
    return "Ong";
}
string Ong::FormatOutput()
{
    return "0";
}