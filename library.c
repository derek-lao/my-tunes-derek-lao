#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "library.h"

//index = char value - 97;

int convertIndex(char * songArtist)
{
  int index = *songArtist - 97;
  if(index < 0 || index > 25)//symbols that are not lower case letters
  index = 26;
  return index;
}
struct song_node * add(char * songArtist, char * songName)
{
  return insert(library[convertIndex(songArtist)], songArtist, songName);
}

struct song_node * search_song(char * songArtist, char * songName)
{
  struct song_node * subject = library[convertIndex(songArtist)];
  return find_song(subject, songArtist, songName);
}

void print_entries_letter(char c)
{
  print_list(library[convertIndex(&c)]);
}

void print_songs_artist(char * songArtist)
{
  struct song_node * subject = library[convertIndex(songArtist)];
  subject = first_song_artist_helper(subject, songArtist).second;
  if(!subject)
  printf("First song by %s not found\n", songArtist);

  else
  {
    while(!strcmp(subject->artist, songArtist))
    {
      printf(" %s: %s |", subject->artist, subject->name);
      subject = subject->next;
    }
    printf("\n");
  }
}

void print_library()
{
  int letterIndex;
  for(letterIndex = 0 ; letterIndex < 27 ; letterIndex ++)
  {
    print_entries_letter((char) letterIndex);
  }
}
