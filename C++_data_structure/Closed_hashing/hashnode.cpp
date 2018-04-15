#include"hashnode.h"

hashnode::hashnode(int x,bool y)
{
  m_value = x;
  //m_key = 0;
  m_flag = y;
}

int hashnode::getvalue()
{
  return m_value;
}

/*int hashnode::getkey()
{
  return m_key;
}*/

bool hashnode::getflag()
{
  return m_flag;
}
