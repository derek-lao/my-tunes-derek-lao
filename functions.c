#include<stdio.h>
#include<stdlib.h>
#include "song_node.h"

void print_list_debug(struct song_node * subject)
{
  printf("the value is %d and the pointer is %ld and the next pointer is %ld", (*subject).i, subject, (*subject).next);
  printf("\n");
}

void print_list(struct song_node * subject)
{
  while(subject)
  {
    printf("song artist: %s\nsong name: %s\n\n", subject->artist, subject->name);
    subject = subject->next;
  }
}

struct song_node * insert(struct song_node * subject, char * songName, char * songArtist);
{
  struct song_node * p = malloc(sizeof(struct song_node));
  strcpy(p->name, *songName);
  strcpy(p->artist, *songArtist);

  struct song_node * prev;

  if(!subject)
  {
    p->next = subject;
    return p;
  }

  if(strcmp(subject->artist, *songArtist) > 0)
  {
    p->next = subject;
    return p;
  }

  if(!strcmp(subject->artist, *songArtist))
  {
    if(strcmp(subject->name, *songName) >= 0)
    {
      p->next = subject;
      return p;
    }

    while(strcmp(subject->name, *songName) < 0)
    {
      prev = subject;
      subject = subject->next;
    }
    prev->next = p;
    p->next = subject;
    return p;
  }
  //CASES FOR THE FIRST NODE COMPLETE

  while(strcmp(subject->artist, *songArtist) < 0)
  {
    prev = subject;
    subject = subject->next;
  }

  if(strcmp(subject->artist, *songArtist) > 0)
  {
    prev->next = p;
    p->next = subject;
    return p;
  }

  if(!strcmp(subject->artist, *songArtist))
  {
    if(strcmp(subject->name, *songName) >= 0)
    {
      prev->next = p;
      p->next = subject;
      return p;
    }

    while(strcmp(subject->name, *songName) < 0)
    {
      prev = subject;
      subject = subject->next;
    }
    prev->next = p;
    p->next = subject;
    return p;
  }
  printf("You should not have gotten up to this step! Error in function \"insert\" in file \"functions.c\"\n");
  return subject;
}

struct song_node * first_song_artist(struct song_node *subject, char * songArtist)
{
  while(subject && strcmp(subject->artist,*songArtist))
  {
    subject = subject->next;
  }
  return subject;
}

struct song_node * find_song(struct song_node * subject, char * songName, char * songArtist)
{
  struct song_node * loopingPointer = first_song_artist(subject, songArtist);
  while(!strcmp(loopingPointer->artist, songArtist))
  {
    if(!strcmp(loopingPointer->name, songName))
    {
      return loopingPointer;
    }
    loopingPointer = loopingPointer->next;
  }
  return NULL;
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

struct song_node * remove_song_node(struct song_node *front, char * songName, char * songArtist);
{
  struct song_node *prev;
  // printf("front is %ld\n", front);
  while((*front).i == data)
  {
    struct song_node *temp = front;
    front = (*front).next;
    free(temp);
    temp = NULL;
  }
  // printf("front is %ld\n", front);
  struct song_node *frontMarker = front;
  while(front)
  {
    // printf("front before is %ld\n", front);
    prev = front;
    front = (*front).next;
    // printf("got up to here\n");
    while(front && (*front).i == data)
    {
      struct song_node *temp = front;
      front = (*front).next;
      (*prev).next = front;
      free(temp);
      temp = NULL;
    }
    // printf("front after is %ld\n", front);
  }
  return frontMarker;
}
