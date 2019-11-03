#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "song_node.h"

int main()
{
  srand(time(NULL));
  struct song_node * thing;
  struct song_node * dummy;
  struct song_node * correct;
  printf("Testing linkedList\n\n");

  printf("Testing print_list and insert_front. This should come out alphabetically wrong:\n");
  printf("insert_front(dummy, \"drops\", \"basket\")\n");
  dummy = insert_front(dummy, "drops", "basket");
  print_list(dummy);
  printf("insert_front(dummy, \"heks\", \"mysong\")\n");
  dummy = insert_front(dummy, "heks", "mysong");
  print_list(dummy);
  printf("insert_front(dummy, \"dream\", \"bucket\")\n");
  dummy = insert_front(dummy, "dream", "bucket");
  print_list(dummy);
  printf("insert_front(dummy, \"dream\", \"angry\")\n");
  dummy = insert_front(dummy, "dream", "angry");
  print_list(dummy);
  printf("insert_front(dummy, \"yellow\", \"tight\")\n");
  dummy = insert_front (dummy, "yellow", "tight");
  print_list(dummy);
  printf("\n");

  printf("Testing print_list and insert_order:\n");
  printf("insert(thing, \"aman\", \"abc\")\n");
  thing = insert(thing, "aman", "abc");
  print_list(thing);
  printf("insert(thing, \"abro\", \"bakuc\")\n");
  thing = insert(thing, "abro", "bakuc");
  print_list(thing);
  printf("insert(thing, \"aman\", \"lsew\")\n");
  thing = insert(thing, "aman", "lsew");
  print_list(thing);
  printf("insert(thing, \"abro\", \"yeehaw\")\n");
  thing = insert(thing, "abro", "yeehaw");
  print_list(thing);
  printf("insert(thing, \"beezos\", \"halop\")\n");
  thing = insert(thing, "beezos", "halop");
  print_list(thing);
  printf("insert(thing, \"abro\", \"angry\")\n");
  thing = insert(thing, "abro", "angry");
  print_list(thing);
  printf("insert(thing, \"insta\", \"indra\")\n");
  thing = insert(thing, "insta", "indra");
  print_list(thing);
  printf("insert(thing, \"insta\", \"deedo\")\n");
  thing = insert(thing, "insta", "deedo");
  print_list(thing);
  printf("insert(thing, \"aman\", \"meow\")\n");
  thing = insert(thing, "aman", "meow");
  print_list(thing);
  printf("\n");

  printf("Testing print_node:\n");
  printf("print_node(thing)\n");
  print_node(thing);
  printf("print_node(thing->next->next->next)\n");
  print_node(thing->next->next->next);
  printf("\n");

  printf("Testing first_song_artist:\n");
  printf("Looking for the first song of aman:\n");
  correct = first_song_artist(thing, "aman");
  printf("Should return \"aman: abc\": ");
  print_node(correct);
  printf("\n");

  printf("Testing find_song:\n");
  printf("Looking for: [beezos, halop]\n");
  correct = find_song(thing, "beezos", "halop");
  printf("Node found!: ");
  print_node(correct);
  printf("\n");
  printf("Looking for: [beezos, drinkingGame]\n");
  correct = find_song(thing, "beezos", "drinkingGame");
  printf("If the thing print_node past these colons says the \"input pointer is null\", it means it came out as null, so it works and was not found:\n");
  print_node(correct);
  printf("\n");

  printf("Testing remove_song:\n");
  printf("Going to remove [aman: meow]\n");
  remove_song(thing, "aman", "meow");
  printf("Removed, here is the list:\n");
  print_list(thing);
  printf("Going to remove [beezos: halop]\n");
  remove_song(thing, "beezos", "halop");
  printf("Removed, here is the list:\n");
  print_list(thing);
  printf("Going to remove [beezos: halop] (this is the second time, it shouldn't work)\n");
  remove_song(thing, "beezos", "halop");
  printf("Removed, here is the list:\n");
  print_list(thing);
  printf("\n");

  printf("Testing random_element:\n");
  printf("Going to print 7 random nodes:\n");
  correct = random_element(thing);
  print_node(correct);
  correct = random_element(thing);
  print_node(correct);
  correct = random_element(thing);
  print_node(correct);
  correct = random_element(thing);
  print_node(correct);
  correct = random_element(thing);
  print_node(correct);
  correct = random_element(thing);
  print_node(correct);
  correct = random_element(thing);
  print_node(correct);
  printf("\n\n");
  printf("======================\n\n");

  printf("Testing library\n\n");

  return 0;
}
