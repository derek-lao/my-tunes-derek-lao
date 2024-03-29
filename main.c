#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "song_node.h"
#include "library.h"

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
  printf("\n\n");

  printf("Testing print_list and insert:\n");
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
  printf("\n\n");

  printf("Testing print_node:\n");
  printf("print_node(thing)\n");
  print_node(thing);
  printf("print_node(thing->next->next->next)\n");
  print_node(thing->next->next->next);
  printf("\n\n");

  printf("Testing first_song_artist:\n");
  printf("Looking for the first song of aman:\n");
  correct = first_song_artist(thing, "aman");
  printf("Should return \"aman: abc\": ");
  print_node(correct);
  printf("\n\n");

  printf("Testing find_song:\n");
  printf("Looking for: [beezos, halop]\n");
  correct = find_song(thing, "beezos", "halop");
  printf("Node found!: ");
  print_node(correct);
  printf("\n");
  printf("Looking for: [beezos, drinkingGame]\n");
  correct = find_song(thing, "beezos", "drinkingGame");
  print_node(correct);
  printf("\n\n");

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
  printf("\n\n");

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

  printf("Testing free_list:\n");
  printf("Going to free the list:\n");
  printf("free_list(thing) being called between this line and the next\n");
  thing = free_list(thing);
  printf("print_list(thing) the contents will be printed on the next line\n");
  printf("thing is %ld\n", thing);
  print_list(thing);
  printf("===============================================================\n\n");

  printf("Testing library\n\n");

  printf("Testing add and print_library\n\n");
  printf("add(\"taylor swift\", \"blank space\")\n");
  add("taylor swift", "blank space");
  printf("printing library\n");
  print_library();
  printf("add(\"katy perry\", \"dark horse\")\n");
  add("katy perry", "dark horse");
  printf("printing library\n");
  print_library();
  add("taylor swift", "begin again");
  add("katy perry", "firework");
  add("katy perry", "last friday night");
  add("andy grammer", "honey, i'm good");
  add("andy grammer", "good to be alive");
  add("bruno mars", "grenade");
  add("bruno mars", "just the way you are");
  add("bruno mars", "paradise");
  add("taylor swift", "red");
  add("drake", "god's plan");
  add("justin bieber", "baby");
  add("selena gomez", "hands to myself");
  add("selena gomez", "who says");
  add("tove lo", "habits");
  add("adele", "hello");
  add("adele", "set fire to the rain");
  add("adele", "rolling in the deep");
  add("justin bieber", "boyfriend");
  add("justin bieber", "sorry");
  add("justin bieber", "love yourself");
  add("justin bieber", "what do you mean");
  add("justin timberlake", "sexy back");
  add("justin timberlake", "suit & tie");
  add("bruno mars", "uptown funk");
  add("bruno mars", "24k magic");
  add("john lennon", "imagine");
  printf("added a bunch of songs, printing library\n");
  print_library();
  printf("\n\n");

  printf("Testing search_song\n");
  printf("search_song(\"taylor swift\", \"blank space\"): ");
  correct = search_song("taylor swift", "blank space");
  print_node(correct);
  printf("search_song(\"taylor swift\", \"delicate\"): ");
  correct = search_song("taylor swift", "delicate");
  print_node(correct);
  printf("\n\n");

  printf("Testing print_entries_letter\n");
  printf("print_entries_letter('a'):\n");
  print_entries_letter('a');
  printf("\n");
  printf("print_entries_letter('j'):\n");
  print_entries_letter('j');
  printf("\n");
  printf("print_entries_letter('z'):\n");
  print_entries_letter('z');
  printf("\n\n");

  printf("Testing find_artist, will return pointer to first song_node of the artist if found\n");
  printf("find_artist(\"andy grammer\"): ");
  print_node(find_artist("andy grammer"));
  printf("find artist(\"michael jackson\"): ");
  find_artist("michael jackson");

  printf("Testing delete_song\n");
  printf("Original library:\n");
  print_library();
  printf("delete_song(\"bruno mars\", \"24k magic\")\n");
  delete_song("bruno mars", "24k magic");
  print_library();
  printf("delete_song(\"taylor swift\", \"begin again\")\n");
  delete_song("taylor swift", "begin again");
  print_library();
  printf("delete_song(\"justin bieber\", \"what do you mean\")\n");
  delete_song("justin bieber", "what do you mean");
  print_library();
  printf("delete song(\"justin bieber\", \"what do you mean\")\n");
  printf("(this is supposed to delete something nonexistent, so it should not work):\n");
  delete_song("justin bieber", "what do you mean");
  print_library();
  printf("\n\n");

  printf("Testing print_songs_artist\n");
  printf("print_songs_artist(\"justin bieber\"):\n");
  print_songs_artist("justin bieber");
  printf("\n");
  printf("print_song_artist(\"michael jackson\"):\n");
  print_songs_artist("michael jackson");
  printf("\n\n");

  printf("Testing shuffle_print_100\n");
  printf("shuffle_print_100() (this is supposed to return a series of random 100 songs from the library):\n");
  shuffle_print_100();
  printf("\n\n");

  printf("Testing clear_library\n");
  clear_library();
  printf("clear_library() called, printing library...:\n");
  print_library();

  return 0;
}
