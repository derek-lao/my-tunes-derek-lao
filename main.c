#include <stdio.h>
#include <stdlib.h>
#include "song_node.h"

int main()
{
  printf("Testing linkedList\n");

  printf("Testing print_list and insert:\n");
  struct song_node * thing = NULL;
  thing = insert(thing, "abc", "artist");
  thing = insert(thing, "bakuc", "artist");
  thing = insert(thing, "lsew", "artist");
  thing = insert(thing, "yeehaw", "artist");
  thing = insert(thing, "abc", "artist");
  print_list(thing);
  return 0;
}
