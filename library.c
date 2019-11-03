#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "library.h"

int convertIndex(char * songArtist)
{
  int index = *songArtist - 97;
  if(index < 0 || index > 25)//symbols that are not lower case letters
  index = 26;
  return index;
}
void add(char * songArtist, char * songName)
{
  insert(library[convertIndex(songArtist)], songArtist, songName);
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

struct song_node * find_artist(char * songArtist)
{
  struct song_node * subject = library[convertIndex(songArtist)];
  struct song_node * answer = first_song_artist_helper(subject, songArtist).second;
  if(!answer)
  {
    printf("%s not found\n", songArtist);
    return answer;
  }
  return answer;
}

void delete_song(char * songArtist, char * songName)
{
  struct song_node * subject = library[convertIndex(songArtist)];
  remove_song(subject, songArtist, songName);
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
  for(letterIndex = 0 ; letterIndex < 26 ;)
  {
    printf("%c:\n", (char) letterIndex)
    print_entries_letter((char) letterIndex);
    printf("\n");
    letterIndex ++;
  }
  if(letterIndex == 26)
  {
    printf("symbols:\n")
    print_entries_letter((char) letterIndex);
    printf("\n");
  }
}

struct song_node *  print_series_random_100()
{
  struct song_node * frontMarker = *library;
  struct song_node * subject;
  struct song_node * element;
  int letterIndex;
  for(letterIndex = 0 ; letterIndex < 26 ; letterIndex ++)
  {
    subject = find_last(library[letterIndex]);
    subject.next = library[letterIndex + 1];
  }
  subject = NULL;
  int forLoopIndex;
  for(forLoopIndex = 0; forLoopIndex < 100 ; forLoopIndex ++)
  {
    element = random_element(frontMarker);
    subject = insert_front(subject, element->artist, element->name);
  }
  return subject;
}

void clear_library()
{
  int letterIndex;
  for(letterIndex = 0 ; letterIndex < 27 ; letterIndex ++)
  {
    free_list(library[letterIndex]);
  }
}
