
template <typename T>

node<T>::node()
{
  m_value=0;
  m_next=nullptr;
}

template <typename T>

void node<T>::setvalue(T x)
{
  m_value=x;
}

template <typename T>

T node<T>::getvalue()const
{
  return m_value;
}

template <typename T>

void node<T>::setnext(node<T>* next)
{
  m_next=next;
}

template <typename T>

node<T>* node<T>::getnext()const
{
  return m_next;
}
