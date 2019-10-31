struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

//and later:

struct song_node * table[27];

void print_list_debug(struct song_node * subject);
void print_list(struct song_node * subject);
struct song_node * insert_front(struct song_node * subject, char * songName, char * songArtist);
struct song_node * free_list(struct song_node * subject);
struct song_node * remove_song_node(struct song_node *front, char * songName, char * songArtist);
