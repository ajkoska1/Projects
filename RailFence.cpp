//Title: RailFence.cpp
//Author: AJ Koska
//Date: 4/18/22
//Description: This is the implementation file for the RailFence class

#include "RailFence.h"
RailFence::RailFence(){}
RailFence::RailFence(string message, bool isEncrypted, int rails): Cipher(message, isEncrypted)
{
    m_rails = rails;
}
RailFence::~RailFence(){}
void RailFence::Encrypt()
{
    string message = GetMessage();
    char rails[m_rails][message.length()];
    for (int i = 0; i < m_rails; i++)
    {
        for(int j = 0; j < message.length(); j++)
        {
            rails[i][j] = '\0';
        }
    }
    bool turn = false;
    int row = 0;
    int col = 0;
    for (int i = 0; i < message.length(); i++)
    {
        if (row == (m_rails - 1) || (row == 0))
        {
            turn = !turn;
        }
        rails[row][col] = message[i];
        col++;
        turn?row++ : row--;
    }
    string encrypted;
    for (int i = 0; i < m_rails; i++)
    {
        for (int j = 0; j < message.length(); j++)
        {
            if (rails[i][j] != '\0')
            {
                encrypted.push_back(rails[i][j]);
            }
            
        }
    }
    SetMessage(encrypted);
    ToggleEncrypted();
}
void RailFence::Decrypt()
{
    string message = GetMessage();
    char rails[m_rails][message.length()];
    for (int i = 0; i < m_rails; i++)
    {
        for (int j = 0; j < message.length(); j++)
        {
            rails[i][j] = '\0';
        }
    }
    bool turn = false;
    int row = 0;
    int col = 0;
    for (int i = 0; i < message.length(); i++)
    {
        if ((row == 0) || (row == (m_rails - 1)))
        {
            turn = !turn;
        }
        rails[row][col] = '!';
        col++;
        turn?row++ : row--;
    }
    string decrypted;
    int index = 0;
    for (int i = 0; i < m_rails; i++)
    {
        for (int j = 0; j < message.length(); j++)
        {
            if (rails[i][j] == '!')
            {
                rails[i][j] = message[index];
                index++;
            }
        }
    }
    for (int j = 0; j < message.length(); j++)
    {
        for (int i = 0; i < m_rails; i++)
        {
            if (rails[i][j] != '\0')
            {
                decrypted.push_back(rails[i][j]);
            }
        }
    }
    SetMessage(decrypted);
    ToggleEncrypted();
}
string RailFence::ToString()
{
    return "RailFence";
}
string RailFence::FormatOutput()
{
    return "0";
}