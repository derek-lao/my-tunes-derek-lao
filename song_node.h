struct song_node{
  char artist[100];
  char name[100];
  struct song_node *next;
};

struct twoPointers{
  struct song_node * first;
  struct song_node * second;
};

void print_list(struct song_node * subject);
void print_node(struct song_node * subject);
int sizeOfList(struct song_node *subject);

struct song_node * insert(struct song_node * subject, char * songArtist, char * songName);
// insert nodes in order alphabetical by Artist then by Song, returns pointer to inserted node

struct twoPointers first_song_artist_helper(struct song_node *subject, char * songArtist);
struct song_node * first_song_artist(struct song_node *subject, char * artist);
// find and return a pointer to the first song of an artist based on artist name and the pointer before it. returns [last pointer, NULL]

struct twoPointers find_song_helper(struct song_node * subject, char * songArtist, char * songName);
struct song_node * find_song(struct song_node * subject, char * songArtist, char * songName);
// find and return a pointer to a node based on artist and song name and the pointer before it. I will return [last pointer, next artist] if it does not exist

struct song_node * free_list(struct song_node * subject);
struct song_node * remove_song(struct song_node *front, char * songArtist, char * songName);
// find and return a pointer to the node before the freed node;

struct song_node * random_element(struct song_node *subject);
// Return a pointer to random element in the list.
