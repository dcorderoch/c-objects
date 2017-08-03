#include <stdio.h>
#include <stdlib.h>

struct my_struct
{
  int id;
  void (* foo)();
};

void
something ()
{
  printf ( "something was called!\n" );
}

void
other ()
{
  printf ( "other was called!\n" );
}

int
main ( int argc, char ** argv )
{
  struct my_struct * structs[2] = { 0 };
  structs[0] = malloc( sizeof ( struct my_struct ) );
  structs[0]->id = 1;
  structs[0]->foo = something;

  structs[1] = malloc( sizeof ( struct my_struct ) );
  structs[1]->id = 2;
  structs[1]->foo = other;

  (structs[1]->foo)();
  (structs[0]->foo)();

  free ( structs[0] );
  free ( structs[1] );
  return 0;
}
