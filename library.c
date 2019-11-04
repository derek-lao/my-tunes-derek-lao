#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "library.h"
#include "song_node.h"

int sizeLibrary()
{
  int index = 0;
  int answer = 0;
  while(index < 27)
  {
    answer += size(library[index]);
    index ++;
  }
  return answer;
}

int convertIndex(char * songArtist)
{
  int index = *songArtist - 97;
  if(index < 0 || index > 25)//symbols that are not lower case letters
  index = 26;
  return index;
}
void add(char * songArtist, char * songName)
{
  library[convertIndex(songArtist)] = insert(library[convertIndex(songArtist)], songArtist, songName);
}

struct song_node * search_song(char * songArtist, char * songName)
{
  struct song_node * subject = library[convertIndex(songArtist)];
  return find_song(subject, songArtist, songName);
}

void print_entries_letter(char c)
{
  if(library[convertIndex(&c)])
  {
    if(convertIndex(&c) == 26)
    printf("symbols:\n");
    else
    printf("%c:\n", c);
    print_list(library[convertIndex(&c)]);
  }
  else
  printf("Entries of letter %c not found\n", c);
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
  library[convertIndex(songArtist)] = remove_song(library[convertIndex(songArtist)], songArtist, songName);
}

void print_songs_artist(char * songArtist)
{
  struct song_node * subject = library[convertIndex(songArtist)];
  subject = first_song_artist_helper(subject, songArtist).second;
  if(!subject)
  printf("songs by %s not found\n", songArtist);

  else
  {
    while(subject && !strcmp(subject->artist, songArtist))
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
  printf("\n#############################################################\n");
  for(letterIndex = 0 ; letterIndex < 27 ; letterIndex ++)
  {
    if(library[letterIndex])
    print_entries_letter((char) (letterIndex + 97));
  }
  printf("#############################################################\n\n");
}

// struct song_node *  print_series_random_100()
// {
//   struct song_node * frontMarker = *library;
//   struct song_node * subject;
//   struct song_node * element;
//   int letterIndex;
//   for(letterIndex = 0 ; letterIndex < 27 ;)
//   {
//     if(library[letterIndex])
//     {
//       subject = find_last(library[letterIndex]);
//       int nextLetterIndex = letterIndex + 1;
//       while(!library[nextLetterIndex] && nextLetterIndex < 27)
//       nextLetterIndex ++;
//
//       if(nextLetterIndex < 26 && library[nextLetterIndex])
//       subject->next = library[nextLetterIndex];
//
//       letterIndex = nextLetterIndex;
//     }
//     else
//     letterIndex ++;
//   }
//   subject = NULL;
//   int forLoopIndex;
//   for(forLoopIndex = 0 ; forLoopIndex < 100 ; forLoopIndex ++)
//   {
//     element = random_element(frontMarker);
//     subject = insert_front(subject, element->artist, element->name);
//   }
//   print_list(subject);
// }

struct song_node *  print_series_random_100()
{
  struct song_node * frontMarker = NULL;
  struct song_node * subject;
  struct song_node * element;
  int libIndex;
  int forLoopIndex;
  for(forLoopIndex = 0 ; forLoopIndex < 100 ; forLoopIndex ++)
  {
    subject = *library;
    int numberOfIterations = rand() % sizeLibrary();
    libIndex = 0;
    while(libIndex < 27)
    {
      if(library[libIndex])
      {
        while(subject && numberOfIterations)
        {
          subject = subject->next;
          numberOfIterations --;
        }
      }
      libIndex ++;
    }
    printf("frontMarker before insert_front is %ld\n", frontMarker);
    printf("subject is %ld\n", subject);
    frontMarker = insert_front(frontMarker, subject->artist, subject->name);
    printf("frontMarker after insert_front is %ld\n", frontMarker);
  }
  print_list(frontMarker);
}

void clear_library()
{
  int letterIndex;
  for(letterIndex = 0 ; letterIndex < 27 ; letterIndex ++)
  {
    printf("letterIndex is %d\n", letterIndex);
    printf("library[letterIndex] is: %ld\n", library[letterIndex]);
    library[letterIndex] = free_list(library[letterIndex]);
  }
}
