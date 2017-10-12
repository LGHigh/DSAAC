#include <algorithm>
#include <vector>
using namespace std;

void InsertionSort(vector<int> a,int N){
    int Tmp;
    int j;
    for(int i=1;i<N;i++){
        Tmp=a[i];
        for(j=i;j>0 && a[j-1]>Tmp;j--){
            a[j]=a[j-1];
        }
        a[j]=Tmp;
    }
}

void ShellSort(vector<int> a, int N){
    int Increment;
    int Tmp;

    for(Increment=N/2;Increment>0;Increment/=2){
        for(int i=Increment;i<N;i++){
            int j;
            Tmp=a[i];
            for(j=i;j>=Increment;j-=Increment)
                if(Tmp<a[j-Increment])
                    a[j]=a[j-Increment];
                else
                    break;
            a[j]=Tmp;
        }
    }
}

#define LeftChild(i) (2*i+1)
void PercDown(vector<int> a, int i, int N){
    int Child;
    int Tmp;

    for(Tmp=a[i];LeftChild(i)<N;i=Child){
        Child=LeftChild(i);
        if(Child!=N-1 && a[Child+1]>a[Child])
            Child++;
        if(Tmp<a[Child])
            a[i]=a[Child];
        else 
            break;
    }
    a[i]=Tmp;
}

void HeapSort(vector<int> a,int N){
    for(int i=N/2;i>=0;i--)
        PercDown(a,i,N);
    for(int i=N-1;i>0;i--){
        swap(a[0],a[i]);
        PercDown(a,0,i);
    }
}

void Merge(vector<int> a,vector<int> TmpArray,int Lpos,int Rpos,int RightEnd){
    int LeftEnd,NumElements,TmpPos;
    
    LeftEnd=Rpos-1;
    TmpPos=Lpos;
    NumElements=RightEnd-Lpos+1;

    while(Lpos<=LeftEnd && Rpos<=RightEnd)
        if(a[Lpos]<=a[Rpos])
            TmpArray[TmpPos++]=a[Lpos++];
        else  
            TmpArray[TmpPos++]=a[Rpos++];

    while(Lpos<=LeftEnd)
        TmpArray[TmpPos++]=a[Lpos++];
    while(Rpos<=RightEnd)
        TmpArray[TmpPos++]=a[Rpos++];

    for(int i=0;i<NumElements;i++,RightEnd--){
        a[RightEnd]=TmpArray[RightEnd];
    }
}

void MSort(vector<int> a,vector<int> TmpArray,int Left,int Right){
    int Center;

    if(Left<Right){
        Center=(Left+Right)/2;
        MSort(a,TmpArray,Left,Center);
        MSort(a,TmpArray,Center+1,Right);
        Merge(a,TmpArray,Left,Center+1,Right);
    }
}

void MergeSort(vector<int> a,int N){
    vector<int> TmpArray;
    TmpArray.resize(N);
    MSort(a,TmpArray,0,N-1);
}

#define Cutoff (3)

int Median3(vector<int> a,int Left, int Right){
    int Center=(Left+Right)/2;

    if(a[Left]>a[Center])
        swap(a[Left],a[Center]);
    if(a[Left]>a[Right])
        swap(a[Left],a[Right]);
    if(a[Center]>a[Right])
        swap(a[Center],a[Right]);

    swap(a[Center],a[Right-1]);
    return a[Right-1];
}

void QSort(vector<int> a,int Left,int Right){
    int i,j;
    int Pivot;

    if(Left+Cutoff<=Right){
        Pivot=Median3(a,Left,Right);
        i=Left;j=Right-1;
        while(1){
            while(a[++i]<Pivot){}
            while(a[--j]>Pivot){}
            if(i<j)
                swap(a[i],a[j]);
            else 
                break;
        }
        swap(a[i],a[Right-1]);

        QSort(a,Left,i-1);
        QSort(a,i+1,Right);
    }
    else
        InsertionSort(A+Left,Right-Left+1);
}

void QuickSort(vector<int> a,int N){
    QSort(a,0,N-1);
}