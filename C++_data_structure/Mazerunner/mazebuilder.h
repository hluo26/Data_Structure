#ifndef MAZEBUILDER_H
#define MAZEBUILDER_H

class mazebuilder
{

public:
  mazebuilder();
  ~mazebuilder();
  void build();
  void print();
  bool isexit();
  char** getmaze();
  int getrow();
  int getcol();
  int getstartrow();
  int getstartcol();


private:
  char** table;
  int col;
  int row;
  int scol;
  int srow;
};

#endif
