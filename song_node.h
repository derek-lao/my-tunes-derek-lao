struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};


//and later:

struct song_node * table[27];
