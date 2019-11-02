struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

//and later:

struct song_node * table[27];

void print_list_debug(struct song_node * subject);
void print_list(struct song_node * subject);
struct song_node * insert(struct song_node * subject, char * songName, char * songArtist);
// insert nodes in order alphabetical by Artist then by Song

struct song_node * first_song_artist(struct song_node *subject, char * artist);
// find and return a pointer to the first song of an artist based on artist name

struct song_node * find_song(struct song_node * subject, char * songName, char * songArtist);
// find and return a pointer to a node based on artist and song name. I will return NULL if it doesn't exist

struct song_node * free_list(struct song_node * subject);
struct song_node * remove_song_node(struct song_node *front, char * songName, char * songArtist);
