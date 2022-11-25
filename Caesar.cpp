//Title: Caesar.cpp
//Author: AJ Koska
//Date: 4/17/22
//Description: This is the implementation of the Caesar class
#include "Caesar.h"
Caesar::Caesar(){}
Caesar::Caesar(string message, bool isEncrypted, int shift): Cipher(message, isEncrypted)
{
  m_shift = shift;
}
Caesar::~Caesar(){}
void Caesar::Encrypt()
{
  string message = GetMessage();
  char curr;
  string encrypted;
  for (int i = 0; i < message.length(); i++)
    {
		curr = message[i];
    if ((int(curr) >= 97) &&  (int(curr) <= 122))
      {
	if (int(curr) + m_shift > 122)
	  {
	    curr = char((int(curr) + m_shift) - 26);
	  }
	else if (int(curr) + m_shift < 97)
	  {
	    curr = char((int(curr) + m_shift) + 26);
	  }
	else
	  {
	    curr = char(int(curr) + m_shift);
	  }
      }
    else if ((int(curr) >= 65) && (int(curr) <= 90))
      {
	if (int(curr) + m_shift > 90)
	  {
	    curr = char((int(curr) + m_shift) - 26);
	  }
	else if (int(curr) + m_shift < 65)
	  {
	    curr = char((int(curr) + m_shift) + 26);
	  }
	else
	  {
	    curr = char(int(curr) + m_shift);
	  }
      }
    encrypted.push_back(curr);
    }
	SetMessage(encrypted);
	ToggleEncrypted();
}
void Caesar::Decrypt()
{
  string message = GetMessage();
  char curr;
  string decrypted;
  for (int i = 0; i < message.length(); i++)
    {
		curr = message[i];
      if ((int(curr) >= 97) &&  (int(curr) <= 122))
	{
	  if (int(curr) - m_shift < 97)
	    {
	      curr = char((int(curr) - m_shift) + 26);
	    }
	  else if (int(curr) - m_shift > 122)
	    {
	      curr = char((int(curr) - m_shift) - 26);
	    }
	  else
	    {
	      curr = char(int(curr) - m_shift);
	    }
	}
      else if ((int(curr) >= 65) && (int(curr) <= 90))
	{
	  if (int(curr) - m_shift > 90)
	    {
	      curr = char((int(curr) - m_shift) - 26);
	    }
	  else if (int(curr) - m_shift < 65)
	    {
	      curr = char((int(curr) - m_shift) + 26);
	    }
	  else
	    {
	      curr = char(int(curr) - m_shift);
	    }
	}
      decrypted.push_back(curr);
    }
	SetMessage(decrypted);
	ToggleEncrypted();
}
string Caesar::ToString()
{
	return "Caesar";
}
string Caesar::FormatOutput()
{
	return "0";
}