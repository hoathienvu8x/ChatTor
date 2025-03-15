#include <stdlib.h>
#include <string.h>
#include "bst.h"

void insertSocket(struct socketBST *sRoot, struct socketBST *socket) {
  if(sRoot == NULL){
    sRoot = socket;
    return;
  }

  struct socketBST *tmp = sRoot;
  while(tmp->right != NULL)
    tmp = tmp->right;

  tmp->right = socket;
}

// ### Insert identity
void insertIdentity(struct identityBST **root, struct identityBST *identity){
  if(*root == NULL){
    *root = identity;
    return;
  }

  struct identityBST *tmp = *root;
  while(tmp->right != NULL)
    tmp = tmp->right;

  tmp->right = identity;
}

// ### Insert Room
void insertRoom(struct roomBST *rRoot, struct roomBST *room){
  if(rRoot == NULL){
    rRoot = room;
    return;
  }

  struct roomBST *tmp = rRoot;
  while(tmp->right != NULL)
    tmp = tmp->right;

  tmp->right = room;
}

// ### Search Socket
struct socketBST* searchSocket(struct socketBST *sRoot, int id){
  struct socketBST *tmp = sRoot;
  while(tmp != NULL){
    if(tmp->id == id)
      return tmp;

    tmp = tmp->right;
  }

  return NULL;
}

// ### Search identity
struct identityBST* searchIdentity(struct identityBST *root, char* id){
  struct identityBST *tmp = root;
  while(tmp != NULL){
    if(!strcmp(tmp->index, id))
      return tmp;

    tmp = tmp->right;
  }

  return NULL;
}

// ### Search Room
struct roomBST* searchRoom(struct roomBST *rRoot, char* room){
  struct roomBST *tmp = rRoot;
  while(tmp != NULL){
    if(!strcmp(tmp->room, room) && strlen(room) == strlen(tmp->room))
      return tmp;

    tmp = tmp->right;
  }

  return NULL;
}

// ### Remove Socket
void removeSocket(struct socketBST *sRoot, struct socketBST *socket){
  if(sRoot == NULL)
    return;

  struct socketBST* tmp = sRoot;
  if(sRoot == socket){
    sRoot = tmp->right;
    free(tmp);
    return;
  }

  while(tmp->right != socket && tmp->right != NULL)
    tmp = tmp->right;

  if(tmp->right == NULL)
    return;

  tmp->right = socket->right;
  free(socket);
}

// ### Remove identity
void removeIdentity(struct identityBST **root, struct identityBST *identity){
  if(*root == NULL)
    return;

  struct identityBST* tmp = *root;

  if(*root == identity){
    *root = tmp->right;
    free(tmp);
    return;
  }

  while(tmp->right != identity && tmp->right != NULL)
    tmp = tmp->right;

  if(tmp->right == NULL)
    return;

  tmp->right = identity->right;
  free(identity);
}

// ### Remove room
void removeRoom(struct roomBST *rRoot, struct roomBST *room){
  if(rRoot == NULL)
    return;

  struct roomBST* tmp = rRoot;
  if(rRoot == room){
    rRoot = tmp->right;
    free(tmp->room);
    free(tmp);
    return;
  }

  while(tmp->right != room && tmp->right != NULL)
    tmp = tmp->right;

  if(tmp->right == NULL)
    return;

  tmp->right = room->right;
  free(room->room);
  free(room);
}
