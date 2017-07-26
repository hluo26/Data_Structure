#include"hashnode.h"

hashnode::hashnode(int x)
{
  m_value = x;
  m_next = nullptr;
}

void hashnode::setnext(hashnode* next)
{
  m_next = next;
}

int hashnode::getvalue()
{
  return m_value;
}

hashnode* hashnode::getnext()
{
  return m_next;
}
