#include"box.h"

box::box()
{
    m_value=0;
    m_previous=nullptr;
}

void box::setvalue(int x)
{
    m_value=x;
}

int box::getvalue()const
{
    return m_value;
}

void box::setprevious(box* prev)
{
  m_previous=prev;
}

box* box::getprevious()
{
  return m_previous;
}
