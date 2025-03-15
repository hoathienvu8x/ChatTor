#ifndef _BST_H
#define _BST_H

#define MAX_INDEX_SIZE 16

/*
title: bst
colour: white
emphasis: #6b6bb8
highlight: atelier-lakeside-dark
background: black
---
# BST

## Structs
*/

// Forward declarations
struct identityNode;

// ### Identity BST 
struct identityBST{
  char index[MAX_INDEX_SIZE + 1];
  unsigned char rb;
  struct identityNode *identity;
  struct identityBST *left, *right;
};

// ### Socket BST
struct socketBST{
  int id;
  unsigned char rb;
  struct identityBST *identities;
  struct socketBST *left, *right;
};

// ### Room BST
struct roomBST{
  char* room;
  unsigned char rb;
  struct identityBST *identities;
  struct roomBST *left, *right;
};

// ### Identity node
struct identityNode{
  char *name, *color;
  struct socketBST *socket;
  struct roomBST *room;
};

// ### Insert Socket
void insertSocket(struct socketBST *sRoot, struct socketBST *socket);

// ### Insert identity
void insertIdentity(struct identityBST **root, struct identityBST *identity);

// ### Insert Room
void insertRoom(struct roomBST *rRoot, struct roomBST *room);

// ### Search Socket
struct socketBST* searchSocket(struct socketBST *sRoot, int id);

// ### Search identity
struct identityBST* searchIdentity(struct identityBST *root, char* id);

// ### Search Room
struct roomBST* searchRoom(struct roomBST *rRoot, char* room);

// ### Remove Socket
void removeSocket(struct socketBST *sRoot, struct socketBST *socket);

// ### Remove identity
void removeIdentity(struct identityBST **root, struct identityBST *identity);

// ### Remove room
void removeRoom(struct roomBST *rRoot, struct roomBST *room);

#endif
