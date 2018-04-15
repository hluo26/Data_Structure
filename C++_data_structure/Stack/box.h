
#ifndef _BOX_H_
#define _BOX_H_

class box
{
public:
  box();
  void setvalue(int x);
  int getvalue()const;
  void setprevious(box* prev);
  box* getprevious();

private:
  int m_value;
  box* m_previous;
};

#endif
