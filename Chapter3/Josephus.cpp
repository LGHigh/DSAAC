class List {
public:
    List();
    List* Insert();
    List* Remove(int N);
    int getNum(List* L);
    List* FindPrevious(List* L);
private:
    List* Next;
    int Num;
}

List(){
    Next=this;
    num=1;
    Last=this;
}

List* Insert(List* L ){
    List* Tmp=new List;
    Tmp->Num=L->Num+1;
    Tmp->Next=L->Next;
    L->Next=Tmp;
    return Tmp;
}

int getNum(List* L){
    return L->Num;
}

List* FindPrevious(){
    List* Tmp=this;
    while(Tmp->Next->Num!=this->Num)
        Tmp=Tmp->Next;
    return Tmp;
}

List* Remove(int N){
    if(N==0){
        List* Tmp=this->FindPrevious();
	Tmp->Next=this->Next;
	delete this;
	return Tmp->Next;
    }
    List* Tmp=this;
    for(int i=0;i<N-1;i++){
         Tmp=Tmp->Next;
    }
    List* TmpCell=Tmp->Next;
    Tmp->Next=Tmp->Next->Next;
    delete TmpCell->Next;
    return Tmp->Next;
}

int main(){
    List* Josephus=new List;
    for(int i=0;i<N-1;i++)
        Josephus=Josephus->Insert();
    for(int i=0;i<N-1;i++)
        Josephus=Josephus->Remove(M);
    Josephus->getNum();
}
