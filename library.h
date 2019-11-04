struct song_node * library[27];

//helper functions start
int convertIndex(char * songArtist);
//helper functions end

void add(char * songArtist, char * songName);

struct song_node * search_song(char * songArtist, char * songName);

void print_entries_letter(char c);

struct song_node * find_artist(char * songArtist);

void delete_song(char * songArtist, char * songName);

void print_songs_artist(char * songArtist);

void print_library();

struct song_node *  print_series_random_100();

void clear_library();
