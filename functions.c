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
}

struct song_node * insert(struct song_node * subject, char * songName, char * songArtist)
{
  struct song_node * p = malloc(sizeof(struct song_node));
  strcpy(p->name, songName);
  strcpy(p->artist, songArtist);
  struct song_node * prev = subject;

  if(!subject || strcmp(subject->artist, songArtist) > 0)
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
    while(strcmp(subject->name, songName) < 0)
    {
      prev = subject;
      subject = subject->next;
    }
    prev->next = p;
    p->next = subject;
    return p;
  }
  //CASES FOR THE FIRST NODE COMPLETE

  while(strcmp(subject->artist, songArtist) < 0)
  {
    prev = subject;
    subject = subject->next;
  }
  if(strcmp(subject->artist, songArtist) > 0)
  {
    prev->next = p;
    p->next = subject;
    return p;
  }
  if(!strcmp(subject->artist, songArtist))
  {
    if(strcmp(subject->name, songName) >= 0)
    {
      prev->next = p;
      p->next = subject;
      return p;
    }
    while(strcmp(subject->name, songName) < 0)
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

struct song_node * * first_song_artist_helper(struct song_node *subject, char * songArtist)
{
  static struct node * answers[2];
  struct node * prev = subject;
  if(subject && strcmp(subject->artist,songArtist))
    subject = subject->next;
  while(subject && strcmp(subject->artist,songArtist))
  {
    prev = subject;
    subject = subject->next;
  }
  *answers = prev;
  *(answers + 1) = subject;
  return answers;//this becomes NULL if you go through the whole list
}
struct song_node * first_song_artist(struct song_node *subject, char * songArtist)
{
  struct song_node * * arrayOfAnswers= first_song_artist_helper(subject, songArtist);
  struct song_node * answer = *(arrayOfAnswers + 1);
  free(arrayOfAnswers);
  arrayOfAnswers = NULL;
  return answer;
}

struct song_node * * find_song_helper(struct song_node * subject, char * songName, char * songArtist)
{
  static struct song_node * answers[2];
  struct song_node * prev = *(first_song_artist_helper(subject, songArtist));
  subject = *(first_song_artist_helper(subject, songArtist) + 1);
  if(!subject)
  {
    *answers = NULL;
    *(answers + 1) = NULL;
  }
  while(!strcmp(subject->artist, songArtist))
  {
    if(!strcmp(subject->name, songName))
    {
      *answers = prev;
      *(answers + 1) = subject;
      return answers;
    }
    prev = subject;
    subject = subject->next;
  }
  //if you made it here, it means the song was not found;
  *answers = NULL;
  *(answers + 1) = NULL;
  return answers;//this becomes NULL. If this goes here immediately and skips the while loop, it means the first_song_artist is not working
}
struct song_node * find_song(struct song_node * subject, char * songName, char * songArtist)
{
  struct song_node * * arrayOfAnswers= first_song_helper(subject, songName, songArtist);
  struct song_node * answer = *(arrayOfAnswers + 1);
  free(arrayOfAnswers);
  arrayOfAnswers = NULL;
  return answer;
}

struct song_node * remove_song_node(struct song_node *subject, char * songName, char * songArtist)
{
  struct song_node * prev = *(find_song_helper(subject, songName, songArtist));
  subject = *(find_song_helper(subject, songName, songArtist) + 1);

  if(subject)//meaning that if the song was found
  {
    prev->next = subject->next;
    free(subject);
    subject = NULL;
    return prev;
  }
  // return subject;//can be used for debugging, this will be NULL if not found
  return NULL;//return this if not found;
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
  srand(time(NULL));
  int numberOfIterations = rand() % size(subject);
  while(numberOfIterations)
  {
    subject = subject->next;
    numberOfIterations --;
  }
  return subject;
}
