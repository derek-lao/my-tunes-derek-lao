#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "song_node.h"

// void print_list_debug(struct song_node * subject)
// {
//   printf("the value is %d and the pointer is %ld and the next pointer is %ld", (*subject).i, subject, (*subject).next);
//   printf("\n");
// }

int size(struct song_node *subject)
{
  int answer = 0;
  while(subject)
  {
    subject = subject->next;
    answer ++;
  }
  return answer;
}

void print_list(struct song_node * subject)
{
  while(subject)
  {
    printf(" %s: %s |", subject->artist, subject->name);
    subject = subject->next;
  }
  printf("\n");
}

void print_node(struct song_node * subject)
{
  if(subject)
  printf("%s: %s\n", subject->artist, subject->name);
  else
  printf("input pointer was null\n");
}

struct song_node * insert(struct song_node * subject, char * songArtist, char * songName)
{
  struct song_node * frontMarker = subject;
  struct song_node * p = malloc(sizeof(struct song_node));
  strcpy(p->name, songName);
  strcpy(p->artist, songArtist);
  p->next = NULL;
  struct song_node * prev = subject;

  if(!subject)
  {
    p->next = subject;
    return p;
  }
  if(strcmp(subject->artist, songArtist) > 0)
  {
    p->next = subject;
    return p;
  }
  if(!strcmp(subject->artist, songArtist))
  {
    if(strcmp(subject->name, songName) >= 0)
    {
      p->next = subject;
      return p;
    }
    while(subject && !strcmp(subject->artist, songArtist) && strcmp(subject->name, songName) < 0)
    {
      prev = subject;
      subject = subject->next;
    }
    prev->next = p;
    p->next = subject;
    return frontMarker;
  }
  //CASES FOR THE FIRST NODE COMPLETE

  while(subject && strcmp(subject->artist, songArtist) < 0)
  {
    prev = subject;
    subject = subject->next;
  }
  if(subject && strcmp(subject->artist, songArtist) > 0)
  {
    prev->next = p;
    p->next = subject;
    return frontMarker;
  }
  while(subject && !strcmp(subject->artist, songArtist) && strcmp(subject->name, songName) < 0)
  {
    prev = subject;
    subject = subject->next;
  }
  prev->next = p;
  p->next = subject;
  return frontMarker;
}

struct twoPointers first_song_artist_helper(struct song_node *subject, char * songArtist)
{
  struct twoPointers answers;
  struct song_node * prev = subject;
  if(subject && strcmp(subject->artist,songArtist))
    subject = subject->next;
  while(subject && strcmp(subject->artist,songArtist))
  {
    prev = subject;
    subject = subject->next;
  }
  answers.first = prev;
  answers.second = subject;
  return answers;
}
struct song_node * first_song_artist(struct song_node *subject, char * songArtist)
{
  struct song_node * answer = first_song_artist_helper(subject, songArtist).second;
  if(!answer)
  {
    printf("First song by %s not found\n", songArtist);
    return answer;
  }
  return answer;
}

struct twoPointers find_song_helper(struct song_node * subject, char * songArtist, char * songName)
{
  struct twoPointers answers = first_song_artist_helper(subject, songArtist);
  struct song_node * prev = answers.first;
  subject = answers.second;
  if(!subject)
  {
    answers.first = NULL;
    answers.second = NULL;
    return answers;
  }
  while(!strcmp(subject->artist, songArtist))
  {
    if(!strcmp(subject->name, songName))
    {
      answers.first = prev;
      answers.second = subject;
      return answers;
    }
    prev = subject;
    subject = subject->next;
  }
  //if you made it here, it means the song was not found;
  answers.first = NULL;
  answers.second = NULL;
  return answers;//this becomes NULL. If this goes here immediately and skips the while loop, it means the first_song_artist is not working
}
struct song_node * find_song(struct song_node * subject, char * songArtist, char * songName)
{
  struct song_node * answer = find_song_helper(subject, songArtist, songName).second;
  if(!answer)
  {
    printf("%s: %s not found\n", songArtist, songName);
    return answer;
  }
  return answer;
}

struct song_node * remove_song(struct song_node *subject, char * songArtist, char * songName)
{
  struct song_node * frontMarker = subject;
  if(!strcmp(subject->artist, songArtist) && !strcmp(subject->name, songName))
  {
    subject = subject->next;
    return subject;
  }
  struct twoPointers answers = find_song_helper(subject, songArtist, songName);
  struct song_node * prev = answers.first;
  subject = answers.second;

  if(subject)//meaning that if the song was found
  {
    prev->next = subject->next;
    free(subject);
    subject = NULL;
    return frontMarker;
  }
  printf("%s: %s not found\n", songArtist, songName);
  return frontMarker;//return this if not found;
}

struct song_node * free_list(struct song_node * subject)
{
  struct song_node * p;
  while(subject)
  {
    p = subject;
    subject = (*subject).next;
    free(p);
  }
  p = NULL;
  return subject;
}

struct song_node * random_element(struct song_node *subject)
{
  int numberOfIterations = rand() % size(subject);
  while(numberOfIterations)
  {
    subject = subject->next;
    numberOfIterations --;
  }
  return subject;
}
