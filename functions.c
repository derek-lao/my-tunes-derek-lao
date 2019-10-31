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
    printf("%d ", (*subject).i);
    subject = (*subject).next;
  }
  printf("\n");
}

struct song_node * insert_front(struct song_node * subject, int data)
{
  struct song_node * p = malloc(sizeof(struct song_node));
  (*p).i = data;
  (*p).next = subject;
  // printf("song_node inserted, the value is %d, the pointer is %ld\n", data, p);
  return p;
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

struct song_node * remove_song_node(struct song_node *front, int data)
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
