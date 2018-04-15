
template <typename T>

queue<T>::queue()
{
  m_front=nullptr;
  m_back=nullptr;
  m_size=0;
}

template <typename T>

queue<T>::~queue()
{
  while(m_size>=1)
  {
    dequeue();
  }
}

template <typename T>

void queue<T>::enqueue(const T x)
{
  if(isempty())
  {
    node<T>* temp = new node<T>();
    temp->setvalue(x);
    temp->setnext(nullptr);
    m_front=temp;
    m_back=temp;
    m_size++;
  }
  else
  {
    node<T>* temp = new node<T>();
    temp->setvalue(x);
    m_back->setnext(temp);
    m_back=temp;
    m_size++;
  }
}

template <typename T>

T queue<T>::dequeue()throw(PreconditionViolationException)
{
  if(isempty())
  {
    throw(PreconditionViolationException("It is an empty queue"));
  }
  else
  {
    node<T>* temp = m_front;
    T tempval = temp->getvalue();
    temp=temp->getnext();
    delete m_front;
    m_front=temp;
    m_size--;
    return tempval;
  }
}

template <typename T>

bool queue<T>::isempty()const
{
  if(m_size==0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <typename T>

int queue<T>::size()const
{
  return m_size;
}

template <typename T>

T queue<T>::peek()const throw(PreconditionViolationException)
{
  if(isempty())
  {
    throw(PreconditionViolationException("It is an empty queue"));
  }
  else
  {
    T tempval=m_front->getvalue();
    return tempval;
  }
}

template <typename T>

void queue<T>::print()const
{
  if(isempty())
  {
    std::cout<<"empty queue"<<std::endl;
  }
  else
  {
    node<T>* temp = m_front;
    while(temp!=nullptr)node<T>* temp = m_front;
  while(temp!=nullptr)
  {
    if(temp->getvalue()==x)
    {
      //when the value is in the last node of the queue
      if(x==m_back->getvalue())
      {
        node<T>* t1 = m_front;
        while(t1->getnext()!=m_back)
        {
          t1=t1->getnext();
        }
        t1->setnext(nullptr);
        delete m_back;
        m_back=t1;
        m_size--;
      }
      //when the value is in the first node of the queue
      else if(x==m_front->getvalue())
      {
        node<T>* t1 = m_front->getnext();
        delete m_front;
        m_front=t1;
        m_size--;
      }
      //when the value is in the middle range of the queue
      else
      {
        node<T>* t1 = m_front;
        node<T>* t2 = m_front;
        while(t1->getvalue()!=x)
        {
          t2=t1;
          t1=t1->getnext();
        }

        t2->setnext(t1->getnext());
        delete t1;
        m_size--;
      }
    }
    temp=temp->getnext();
  }
    {
      std::cout<<temp->getvalue()<<std::endl;
      temp=temp->getnext();
    }
  }
}

template <typename T>

bool queue<T>::remove(const T x)
{
  if(isempty())
  {
    std::cout<<"It is an empty queue"<<std::endl;
    return false;
  }
  else
  {
    node<T>* temp = m_front;
    while(temp!=nullptr)
    {
      if(temp->getvalue()==x)
      {
        //when the value is in the last node of the queue
        if(x==m_back->getvalue())
        {
          node<T>* t1 = m_front;
          while(t1->getnext()!=m_back)
          {
            t1=t1->getnext();
          }
          t1->setnext(nullptr);
          delete m_back;
          m_back=t1;
          m_size--;
          return true;
        }
        //when the value is in the first node of the queue
        else if(x==m_front->getvalue())
        {
          node<T>* t1 = m_front->getnext();
          delete m_front;
          m_front=t1;
          m_size--;
          return true;
        }
        //when the value is in the middle range of the queue
        else
        {
          node<T>* t1 = m_front;
          node<T>* t2 = m_front;
          while(t1->getvalue()!=x)
          {
            t2=t1;
            t1=t1->getnext();
          }

          t2->setnext(t1->getnext());
          delete t1;
          m_size--;
          return true;
        }
      }
      temp=temp->getnext();
    }
    return false;
  }

}
