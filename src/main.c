#include <stdio.h>
#include <stdlib.h>

#define OBJS 8

struct quote_object
{
  int id;
  int (* foo)();
};

int
foo1 ()
{
  printf ( "foo1 was called!\n" );
  return 0;
}

int
foo2 ()
{
  printf ( "foo2 was called!\n" );
  return 0;
}

int
main ( int argc, char ** argv )
{
  struct quote_object * quote_objects[OBJS] = { 0 };
  int * foos[2] = { foo1, foo2 };
  int i;

  for ( i = 0 ; i < OBJS ; i++ )
    {
      quote_objects[i] = malloc( sizeof ( struct quote_object ) );
      quote_objects[i]->id = i;
      quote_objects[i]->foo = foos[ i % 2 ];
    }

  for ( i = 0 ; i < OBJS ; i++ )
    {
      (quote_objects[i]->foo)();
      printf ( "by \"object\" no.%d\n\n", quote_objects[i]->id );
    }

  for ( i = 0 ; i < OBJS ; i++ )
    {
      free ( quote_objects[i] );
    }
  return 0;
}
