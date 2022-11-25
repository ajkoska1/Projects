//File: Cipher.cpp
//Author: AJ Koska
//Date: 4/17/22
//Description: The implementation file for Cipher.h
#include "Cipher.h"
Cipher::Cipher(){}
Cipher::Cipher(string message, bool isEncrypted)
{
  m_message = message;
  m_isEncrypted = isEncrypted;
}
Cipher::~Cipher(){}
string Cipher::GetMessage()
{
  return m_message;
}
bool Cipher::GetIsEncrypted()
{
  return m_isEncrypted;
}
void Cipher::SetMessage(string message)
{
  m_message = message;
}
void Cipher::ToggleEncrypted()
{
  m_isEncrypted = !(m_isEncrypted);
}
