#include <stdio.h>
#include <stdlib.h>
#include "song_node.h"

int main()
{
  printf("Testing linkedList\n");

  printf("Testing print_list and insert:\n");
  struct song_node * thing = NULL;
  thing = insert(thing, "abc", "aman");
  print_list(thing);
  thing = insert(thing, "bakuc", "abro");
  print_list(thing);
  thing = insert(thing, "lsew", "aman");
  print_list(thing);
  printf("After this line\n");
  thing = insert(thing, "yeehaw", "abro");
  print_list(thing);
  printf("Before this line\n");
  thing = insert(thing, "abc", "aman");
  print_list(thing);
  return 0;
}
