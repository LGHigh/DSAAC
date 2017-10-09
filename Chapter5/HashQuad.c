#ifndef _HashQuad_H

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl* HashTable;

HashTable InitializeTable(int TableSize);
void DestoryTable(HashTable H);
Position Find(ElementType Key,HashTable H);
void Insert(ElementType Key,HashTable H);
ElementType Retrieve(Position P,HashTable H);
HashTable Rehash(HashTable H);
/*Routines such as Delete and MakeEmpty are omitted*/

#endif /*_HashQuad_H*/

/*Place in the implementation file*/
enum KindOfEntry{Legitmate,Empty,Deleted};

struct HashEntry{
    ElementType Element;
    enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

/*Cell* TheCells will be an array of*/
/*HashEntry cells,allocated later*/
struct HashTbl{
    int TableSize;
    Cell* TheCells;
};

HashTable InitializeTable(int TableSize){
    HashTable H;
    int i;

    if(TableSize<MinTableSize){
        Error("Table size too small");
        return NULL;
    }

    /*Allocate table*/
    H=malloc(sizeof(struct HashTbl));
    if(H==NULL){
        FatalError("Out of Space");
    }

    H->TableSize=NextPrime(TableSize);

    /*Allocate array of Cell*/
    H->TheCells=malloc(sizeof(Cell)*H->TableSize);
    if(H->TheCells==NULL)
        FatalError("Out of Space");
    
    for(i=0;i<H->TableSize;i++)
        H->TheCells[i].Info=Empty;

    return H;
}

Position Find(ElementType Key, HashTable H){
    Position CurrentPos;
    int CollisionNum;

    CollisionNum=0;
    CurrentPos=Hash(Key,H->TableSize);
    while(H->TheCells[CurrentPos].Info!=Empty && H->TheCells[CurrentPos].Element!=Key){//Probably need strcmp
        CurrentPos+=2*++CollisionNum-1;
        if(CurrentPos>=H->TableSize)
            Current-=H->TableSize;
    }
    return CurrentPos;
}

void Insert(ElementType Key,HashTable H){
    Position Pos;

    Pos=Find(Key,H);
    if(H->TheCell[Pos].Info!=Legitimate){
        H->TheCells[Pos].Info=Legitimate;
        H->TheCells[Pos].Element=Key;
    }
}

HashTable Rehash(HashTable H){
    int i,OldSize;
    Cell* OldSize;

    OldCells=H->TheCells;
    OldSize=H->TableSize;

    H=InitializeTable(2*OldSize);

    for(i=0;i<OldSize;i++)
        if(OldCells[i].Info==Legitimate)
            Insert(OldCells[i].Element,H);
        
    free(OldCells);

    return H;
}