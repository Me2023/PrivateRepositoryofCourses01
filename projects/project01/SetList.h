#ifndef SETLIST_H
#define SETLIST_H

typedef int DataType;
typedef struct node {
    DataType data;
    struct node *link;
}SetNode, *LinkedSet;

void initSet(LinkedSet& S);
void insertRear(LinkedSet& L, DataType endTag);
SetNode *Contains(LinkedSet& S, DataType x);
bool addMember(LinkedSet& S, DataType x);
bool delMember(LinkedSet& S, DataType x);
void Merge(LinkedSet& LA, LinkedSet& LB, LinkedSet& LC);
void Intersect(LinkedSet& LA, LinkedSet& LB, LinkedSet& LC);
void Diff(LinkedSet& LA, LinkedSet& LB, LinkedSet& LC);
void printSet(LinkedSet S);


#endif