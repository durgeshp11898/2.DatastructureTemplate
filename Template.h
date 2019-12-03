
//	This Program Contains Following Data structures
//	
//	1.Singly Linear Linked List
//	2.Singly Circular Linked List
//	3.Doubly Linear Linked List
//	4.Doubly Circular Linked List
//	5.Stack(Dynamic)
//	6.Queue(Dynamic)
//	7.Priority Queue(Dynamic)
//	 
//	ClassName 		:GEN_SLLL
//	Description		:This is class designed for Singly linear linked list		
#include<iostream>
using namespace std;

#define TRUE 1
#define FALSE 0

template<class T>
struct node
{
	T            Data;
	struct node* Next;
};

//Generic Class For Singly Linear Linked List

template<class T>
class GEN_SLLL
{
private:

	struct node<T>*		Head;		//Start Pointer
	struct node<T>* 	Tail;		//End  Pointer
	int 				size;

public:	

		GEN_SLLL();
		~GEN_SLLL();
		void InsertFirst(T);
		void InsertLast(T);
		void InsertAtPos(T,int);
		inline void Display();
		inline void DisplayR();
		inline int Count();
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
		int Frequency(T);
		int FirstOccurance(T);
		int LastOccurance(T);
		int Summation();
		int Largest();
		int Smallest();
		void ReverseList();
		void Concat(GEN_SLLL<T> &op1,GEN_SLLL<T> &op2);
		
		friend bool operator ==(GEN_SLLL<T> &op1,GEN_SLLL<T> &op2)					//Compares Linked List For Equality
		{
			struct node<T>* temp1=op1.Head;
			struct node<T>* temp2=op2.Head;

			while((temp1!=NULL)&&(temp2!=NULL))
			{
					if(temp1->Data!=temp2->Data)
					{
							break;
					}
					temp1=temp1->Next;
					temp2=temp2->Next;
			} 
			if((temp1==NULL)&&(temp2==NULL))
			{
					return TRUE;
			}
			else
			{
					return FALSE;
			}
		}

		friend bool operator >(GEN_SLLL<T> &op1,GEN_SLLL<T> &op2)					//Check For Greater than
		{
			struct node<T>* temp1=op1.Head;
			struct node<T>* temp2=op2.Head;

			while((temp1!=NULL)&&(temp2!=NULL))
			{
					if((temp1->Data) <= (temp2->Data))
					{
							break;
					}
					temp1=temp1->Next;
					temp2=temp2->Next;
			} 
			if((temp1==NULL)&&(temp2==NULL))
			{
					return TRUE;
			}
			else
			{
					return FALSE;
			}
		}

		friend bool operator <(GEN_SLLL<T> &op1,GEN_SLLL<T> &op2)					//Check for Less Than
		{
			struct node<T>* temp1=op1.Head;
			struct node<T>* temp2=op2.Head;

			while((temp1!=NULL)&&(temp2!=NULL))
			{
					if((temp1->Data) >= (temp2->Data))
					{
							break;
					}
					temp1=temp1->Next;
					temp2=temp2->Next;
			} 
			if((temp1==NULL)&&(temp2==NULL))
			{
					return TRUE;
			}
			else
			{
					return FALSE;
			}
		}

};	

template<class T>
GEN_SLLL<T>::GEN_SLLL()					//CONSTRUCTOR
{
	Head=NULL;
	Tail=NULL;
	size=0;
}

template<class T>
GEN_SLLL<T>::~GEN_SLLL()					//DESTRUCTOR
{
	struct node<T>* temp;
	struct node<T>* Navigate;

	if(Head!=NULL)
	{
		Navigate=Head;
		while(Navigate!=NULL)
		{
			temp=Navigate->Next;
			delete Navigate;
			Navigate=temp;
		}
	}
}

template<class T>
void GEN_SLLL<T>::InsertFirst(T tVal)		//GENERIC FUNCTION TO DISPLAY SINGLY LINEAR LINKED LIST
{
	struct node<T>* newn=NULL;

	newn=new struct node<T>;
	if(newn==NULL)
	{
		return;
	}

	newn->Next=NULL;
	newn->Data=tVal;

	if(Head==NULL)
	{
		Head=newn;
		Tail=newn;
	}
	else
	{
		newn->Next=Head;
		Head=newn;
	}
	size++;
}

template<class T>
void GEN_SLLL<T>::DisplayR()			     //GENERIC FUNCTION TO DISPLAY SINGLY LINEAR LINKED LIST IN REVERSE MANNER
{
	struct node<T>* temp=Head;
	T Arr[size];
	int i=0;
	while(temp!=NULL)
	{
		Arr[i]=temp->Data;
		temp=temp->Next;
		i++;		
	}
	i--;
	while(i>=0)
	{
		cout<<"| "<<Arr[i]<<" |"<<"->";
		i--;
	}
	cout<<"NULL\n";
}

template<class T>										
void GEN_SLLL<T>::Display()					 //GENERIC FUNCTION TO DISPLAY SINGLY LINEAR LINKED LIST
{
	struct node<T>* temp=Head;
	while(temp!=NULL)
	{
		cout<<"| "<<temp->Data<<" |"<<"->";
		temp=temp->Next;
	}
	cout<<"NULL\n";
}

template<class T>
int GEN_SLLL<T>::Count()					 //GENERIC FUNCTION TO COUNT NODES IN SINGLY LINEAR LINKED LIST
{
	return this->size;
}

template<class T>
void GEN_SLLL<T>::InsertLast(T tVal)		 //GENERIC FUNCTION TO INSERT NODE AT LAST POSITION IN SINGLY LINEAR LINKED LIST
{
	struct node<T>* newn = NULL;
	newn = new struct node<T>;

	if(newn==NULL)
	{
		return;
	}

	newn->Next=NULL;
	newn->Data=tVal;

	if(Head==NULL)
	{
		Head=newn;
		Tail=newn;
	}
	else
	{
		Tail->Next=newn;
		Tail=newn;
	}
	size++;
}

template<class T>
void GEN_SLLL<T>::InsertAtPos(T tVal,int iPos)			//GENERIC FUNCTION TO INSERT NODE AT GIVEN POSITION IN SLLL
{
	if((Head==NULL) || (iPos>size+1) || (iPos<=0))
	{
		return;
	}
	else if(iPos==1)
	{
		InsertFirst(tVal);
	}
	else if(iPos==size+1)
	{
		InsertLast(tVal);
	}
	else
	{
		struct node<T>* newn=NULL;
		struct node<T>* temp=Head;

		newn = new struct node<T>;
		if(newn==NULL)
		{
			return;
		}

		newn->Next=NULL;
		newn->Data=tVal;

		for(int i=1;i<(iPos-1);i++)
		{
			temp=temp->Next;
		}
		newn->Next=temp->Next;
		temp->Next=newn;
		size++;
	}
}
template<class T>
void GEN_SLLL<T>::DeleteFirst()					//GENERIC FUNCTION TO DELETE FIRST NODE IN SLLL
{
	struct node<T>* temp=Head;
	if(Head==NULL)
	{
		return;
	}
	else 
	{
		Head=Head->Next;
		delete (temp);
	}
}

template<class T>
void GEN_SLLL<T>::DeleteLast()				  //GENERIC FUNCTION TO DELETE LAST NODE IN SLLL
{
	if(Head==NULL)
	{
		return;
	}
	else if(Head->Next==NULL)
	{
		delete Head;
		Head=NULL;
	}
	else
	{
		struct node<T>* temp=Head;

		while(temp->Next!=Tail)
		{
			temp=temp->Next;
		}
		delete Tail;
		Tail=temp;
		Tail->Next=NULL;
	}
}

template<class T>
void GEN_SLLL<T>::DeleteAtPos(int iPos)			//GENERIC FUNCTION TO DELETE NODE FROM GIVEN POSITION IN SLLL
{
	if((Head==NULL) || (iPos<=0) || (iPos>size))
	{
		return;
	}
	else if(iPos==1)
	{
		DeleteFirst();
	}
	else if(iPos==size)
	{
		DeleteLast();
	}
	else
	{
		struct node<T>* target=NULL;
		struct node<T>* Navigate=Head;

		for(int i=1;i<(iPos-1);i++)
		{
			Navigate=Navigate->Next;
		}
		target=Navigate->Next;
		Navigate->Next=target->Next;
		delete target;
	}
}

template<class T>
int GEN_SLLL<T>::Frequency(T tVal)			//GENERIC FUNCTION TO COUNT FREQUENCY OF GIVEN DATA IN SLLL
{
	struct node<T>* temp=Head;
	int iCnt=0;
	while(temp!=NULL)
	{
		if(temp->Data==tVal)
		{
			iCnt++;
		}
		temp=temp->Next;
	}
	return iCnt;
}

template<class T>
int GEN_SLLL<T>::FirstOccurance(T tVal)		//GENERIC FUNCTION TO SEARCH FIRST OCCURANCE  OF GIVEN DATA IN SLLL
{
	struct node<T>* temp=Head;
	int iCnt=1,iPos=0;
	while(temp!=NULL)
	{
		if((temp->Data)==tVal)
		{
			iPos=iCnt;
			break;
		}
		iCnt++;
		temp=temp->Next;
	}
	return iPos;
}

template<class T>
int GEN_SLLL<T>::LastOccurance(T tVal)			//GENERIC FUNCTION TO SEARCH LAST OCCURANCE OF GIVEN DATA IN SLLL
{
	struct node<T>* temp=Head;
	int iCnt=1,iPos=0;
	while(temp!=NULL)
	{
		if((temp->Data)==tVal)
		{
			iPos=iCnt;
		}
		iCnt++;
		temp=temp->Next;
	}
	return iPos;
}

template<class T>
int GEN_SLLL<T>::Summation()					//GENERIC FUNCTION TO FIND SUMMATION DATA IN SLLL
{
	struct node<T>* temp=Head;
	int iSum=0;
	while(temp!=NULL)
	{
		iSum=iSum+temp->Data;
		temp=temp->Next;
	}
	return iSum;
}

template<class T>
int GEN_SLLL<T>::Largest()						//GENERIC FUNCTION TO FIND LARGEST OF GIVEN DATA IN SLLL
{
	struct node<T>* temp=Head;
	int tMax=0;
	tMax=temp->Data;
	while(temp!=NULL)
	{
		if((temp->Data)>=tMax)
		{
			tMax=temp->Data;
		}
		temp=temp->Next;
	}
	return tMax;
}

template<class T>
int GEN_SLLL<T>::Smallest()					//GENERIC FUNCTION TO FIND SMALLEST OF GIVEN DATA IN SLLL
{
	struct node<T>* temp=Head;
	int tMin=0;
	tMin=temp->Data;
	while(temp!=NULL)
	{
		if((temp->Data)<=tMin)
		{
			tMin=temp->Data;
		}
		temp=temp->Next;
	}
	return tMin;
}

template<class T>
void GEN_SLLL<T>::ReverseList()						//GENERIC FUNCTION TO REVERSE LINKED LIST IN PLACE
{
	struct node<T>* NEXT=NULL;
	struct node<T>* curr=Head;
	struct node<T>* PREV=NULL;
	
	if(Head==NULL)
	{
		return;
	}
	else
	{
		while(curr!=NULL)
		{
			NEXT=curr->Next;		//make current node's Next node as Next
			curr->Next=PREV;		//store PREV value in current node's Next value
			PREV=curr;				//make current node as PREV for further operations
			curr=NEXT;				//move to Next node;
		}
		Head=PREV;					//at last PREV will contain Last node address
	}		
}

template<class T>
void GEN_SLLL<T>::Concat(GEN_SLLL<T> &op1,GEN_SLLL<T> &op2)		////GENERIC FUNCTION TO CONCAT TWO LINKED LIST
{
	struct node<T>* temp=op1.Head;
	
	if((op1.Head==NULL) && (op2.Head==NULL))
	{
		return;
	}
	
	while(temp->Next!=NULL)
	{
		temp=temp->Next;
	}
	temp->Next=op2.Head;
	op1.size=op1.size+op2.size;
}

///////////////////////////////////////////////////////////////////////
//	 
//	ClassName 		:GEN_SCLL
//	Description		:This is class designed Singly Circular linked list		
///

#include<iostream>
using namespace std;

template<class T>
struct node
{
	T			 Data;
	struct node<T>* Next;
};

template<class T>
class GEN_SCLL
{
private:
	struct node<T>* Head;
	struct node<T>* Tail;
	T  iSize;

public:

	GEN_SCLL();
	~GEN_SCLL();

	void InsertFirst(T );
	void InsertLast(T );
	void InsertAtPos(T ,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	T Count();
};

template<class T>
GEN_SCLL<T>::GEN_SCLL()
{
	Head=NULL;
	Tail=NULL;
	iSize=0;
}

template<class T>
GEN_SCLL<T>::~GEN_SCLL()
{
	struct node<T>* temp=NULL;
	if((Head!=NULL)&&(Tail!=NULL))
	{
		do
		{
			temp=Head;
			Head=Head->Next;
			Tail->Next=Head;
			delete temp;

		}while(Head!=Tail->Next);
	}
}

template<class T>
void GEN_SCLL<T>::Display()
{
	struct node<T>* temp=Head;
	if((Head==NULL)&&(Tail==NULL))
	{
		return;
	}
	do
	{
		cout<<"|"<<temp->Data<<"|->";
		temp=temp->Next;
	}while(temp!=Tail->Next);
}

template<class T>
T GEN_SCLL<T>::Count()
{
	return this->iSize;
}

template<class T>
void GEN_SCLL<T>::InsertFirst(T tVal)
{
	struct node<T>* newn=NULL;
	newn=new struct node<T>;

	newn->Next=NULL;
	newn->Data=tVal;

	if((Head==NULL) && (Tail==NULL))
	{
		Head=newn;
		Tail=newn;
	}
	else
	{
		newn->Next=Head;
		Head=newn;
	}
	Tail->Next=Head;
	iSize++;
}

template<class T>
void GEN_SCLL<T>::InsertLast(T tVal)
{
	struct node<T>* newn=NULL;

	newn=new struct node<T>;
	newn->Next=NULL;
	newn->Data=tVal;

	if((Head==NULL) && (Tail==NULL))
	{
		Head=newn;
		Tail=newn;
	}
	else
	{
		Tail->Next=newn;
		Tail=Tail->Next;
	}
	Tail->Next=Head;
	iSize++;
}

template<class T>

void GEN_SCLL<T>::DeleteFirst()
{
	if((Head==NULL)&&(Tail==NULL))
	{
		return;
	}
	else if(Head==Tail)
	{
		delete Head;
		Head=NULL;
		Tail=NULL;
	}
	else
	{
		Head=Head->Next;
		delete Tail->Next;
		Tail->Next=Head;
	}
	iSize--;
}

template<class T>
void GEN_SCLL<T>::DeleteLast()
{
	if((Head==NULL)&&(Tail==NULL))
	{
		return;
	}
	else if(Head==Tail)
	{
		delete Tail;
		Head=NULL;
		Tail=NULL;
	}
	else
	{
		struct node<T>* temp=Head;
		while(temp->Next!=Tail)
		{
			temp=temp->Next;
		}
		delete Tail;
		Tail=temp;
		Tail->Next=Head;
	}
	iSize--;
}

template<class T>
void GEN_SCLL<T>::InsertAtPos(T tVal,int iPos)
{
	if((Head==NULL) || (Tail==NULL) || (iPos<=0) || (iPos>iSize+1))
	{
		return;
	}
	else if(iPos==1)
	{
		InsertFirst(tVal);
	}
	else if(iPos==iSize+1)
	{
		InsertLast(tVal);
	}
	else
	{ 
		struct node<T>* newn=NULL;
		struct node<T>* temp=Head;

		newn = new struct node<T>;
		if(newn==NULL)
		{
			return;
		}

		newn->Next=NULL;
		newn->Data=tVal;

		for(int i=1;i<(iPos-1);i++)
		{
			temp=temp->Next;
		}
		newn->Next=temp->Next;
		temp->Next=newn;
		iSize++;
	}
}

template<class T>
void GEN_SCLL<T>::DeleteAtPos(int iPos)
{
	if((Head==NULL) || (Tail==NULL) || (iPos<=0) || (iPos>iSize))
	{
		return;
	}
	else if(iPos==1)
	{
		DeleteFirst();
	}
	else if(iPos==iSize)
	{
		DeleteLast();
	}
	else
	{ 
		struct node<T>* temp=Head;
		struct node<T>* target=NULL;

		for(int i=1;i<(iPos-1);i++)
		{
			temp=temp->Next;
		}
		target=temp->Next;
		temp->Next=target->Next;
		delete target;
		iSize--;
	}
}

///////////////////////////////////////////////////////////////////////
//	 
//	ClassName 		:GEN_DLLL
//	Description		:This is class designed for Doubly linear linked list	
///////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

template<class T>
struct node
{
	T 			 Data;
	struct node* Next;
	struct node* Prev;
};

template<class T>
class GEN_DLLL
{
private:

	struct node<T>* Head;
	struct node<T>* Tail;
	int 		    iSize;
public:

	GEN_DLLL();
	~GEN_DLLL();

	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	inline void DisplayF();
	inline void DisplayB();
	inline int Count();

};

template<class T>
GEN_DLLL<T>::GEN_DLLL()
{
	Head=NULL;
	Tail=NULL;
	iSize=0;
}

template<class T>
GEN_DLLL<T>::~GEN_DLLL()
{
	struct node<T>* temp=NULL;
	while(Head!=NULL)
	{
		temp=Head;
		Head=Head->Next;
		delete temp;
	}
}

template<class T>
void GEN_DLLL<T>::DisplayF()
{
	struct node<T>* temp=Head;
	cout<<"\nNULL";
	while(temp!=NULL)
	{
		cout<<"<-"<<"|"<<temp->Data<<"|"<<"->";
		temp=temp->Next;
	}
	cout<<"NULL\n";
}

template<class T>
void GEN_DLLL<T>::DisplayB()
{
	struct node<T>* temp=Tail;
	cout<<"\nNULL";
	while(temp!=NULL)
	{
		cout<<"<-"<<"|"<<temp->Data<<"|"<<"->";
		temp=temp->Prev;
	}
	cout<<"NULL\n";
}

template<class T>
int GEN_DLLL<T>::Count()
{
	return this->iSize;
}

template<class T>
void GEN_DLLL<T>::InsertFirst(T  tVal)
{
	struct node<T>* newn=NULL;
	newn=new struct node<T>;
	if(newn==NULL)
	{
		return;
	}
	newn->Next=NULL;
	newn->Prev=NULL;
	newn->Data= tVal;

	if(Head==NULL)
	{
		Head=newn;
		Tail=newn;
	}
	else
	{
		Head->Prev=newn;
		newn->Next=Head;
		Head=newn;
	}
	iSize++;
}

template<class T>
void GEN_DLLL<T>::InsertLast(T   tVal)
{
	struct node<T>* newn=NULL;
	newn=new struct node<T>;
	if(newn==NULL)
	{
		return;
	}
	newn->Next=NULL;
	newn->Prev=NULL;
	newn->Data=tVal;

	if(Head==NULL)
	{
		Head=newn;
		Tail=newn;
	}
	else
	{
		Tail->Next=newn;
		newn->Prev=Tail;
		Tail=newn;
	}
	iSize++;
}

template<class T>
void GEN_DLLL<T>::DeleteFirst()
{
	if(Head==NULL)
	{
		return;
	}
	else if(Head->Next==NULL)
	{
		delete Head;
		Head=NULL;
		Tail=NULL;
		iSize--;
	}
	else
	{
		Head=Head->Next;
		delete Head->Prev;
		Head->Prev=NULL;
		iSize--;
	}
	
}

template<class T>
void GEN_DLLL<T>::DeleteLast()
{
	if(Head==NULL)
	{
		return;
	}
	else if(Head->Next==NULL)
	{
		delete Head;
		Head=NULL;
		Tail=NULL;
		iSize--;
	}
	else
	{
		Tail=Tail->Prev;
		delete Tail->Next;
		Tail->Next=NULL;
		iSize--;
	}
	
}

template<class T>
void GEN_DLLL<T>::InsertAtPos(T   tVal,int iPos)
{
	if((Head==NULL) || (iPos<1) || (iPos>(Count()+1)))
	{
		return;
	}
	if(iPos==1)
	{
		InsertFirst(tVal);
	}
	else if(iPos==(Count()+1))
	{
		InsertLast(tVal);
	}
	else
	{
		struct node<T>* newn = NULL;
		struct node<T>* temp=Head;
		newn=new struct node<T>;
		if(newn==NULL)
		{
			return;
		}
		newn->Next=NULL;
		newn->Prev=NULL;
		newn->Data=tVal;

		for(T  i=1;i<(iPos-1);i++)
		{
			temp=temp->Next;
		}
		newn->Next=temp->Next;
		temp->Next->Prev=newn;
		temp->Next=newn;
		newn->Prev=temp;
		iSize++;
	}
	
}


template<class T>
void GEN_DLLL<T>::DeleteAtPos(int iPos)
{
	if((Head==NULL) || (iPos<1) || (iPos>Count()))
	{
		return;
	}
	if(iPos==1)
	{
		DeleteFirst();
	}
	else if(iPos==Count())
	{
		DeleteLast();
	}
	else
	{
		struct node<T>* temp=Head;

		for(int i=1;i<(iPos-1);i++)
		{
			temp=temp->Next;
		}
		temp->Next=temp->Next->Next;
		delete(temp->Next->Prev);
		temp->Next->Prev=temp;
		iSize--;
	}
}

///////////////////////////////////////////////////////////////////////
//	 
//	ClassName 		:GEN_DCLL
//	Description		:This is class designed for Doubly Circular linked list		
///////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

template<class T>
struct node
{
	T 			 Data;
	struct node* Next;
	struct node* Prev;
};

template<class T>
class GEN_DCLL
{
private:

	struct node<T>* Head;
	struct node<T>* Tail;
	int 			iSize;

public:

	GEN_DCLL();
	~GEN_DCLL();

	void InsertFirst(T );
	void InsertLast(T );
	void InsertAtPos(T ,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void DisplayF();
	void DisplayR();
	int Count();

};

template<class T>
GEN_DCLL<T>::GEN_DCLL()
{
	this->Head=NULL;
	this->Tail=NULL;
	this->iSize=0;
}

template<class T>
GEN_DCLL<T>::~GEN_DCLL()
{
	struct node<T>* temp=NULL;
	if((Head!=NULL)&&(Tail!=NULL))
	{
		do
		{
			temp=Head;
			Head=Head->Next;
			Tail->Next=Head;
			delete temp;

		}while(Head!=Tail->Next);
	}
}


template<class T>
void GEN_DCLL<T>::InsertFirst(T  tVal)
{
	struct node<T>* newn=new struct node<T>;

	newn->Next=NULL;
	newn->Prev=NULL;
	newn->Data=tVal;

	if((Head==NULL) && (Tail==NULL))
	{
		Head=newn;
		Tail=newn;
	}
	else
	{
		newn->Next=Head;
		Head->Prev=newn;
		Head=newn;
	}
	Tail->Next=Head;
	Head->Prev=Tail;
	iSize++;
}

template<class T>
void GEN_DCLL<T>::InsertLast(T  tVal)
{
	struct node<T>* newn=new struct node<T>;

	newn->Next=NULL;
	newn->Prev=NULL;
	newn->Data=tVal;

	if((Head==NULL) && (Tail==NULL))
	{
		Head=newn;
		Tail=newn;
	}
	else
	{
		Tail->Next=newn;
		newn->Prev=Tail;
		Tail=newn;
	}
	Tail->Next=Head;
	Head->Prev=Tail;
	iSize++;
}

template<class T>
void GEN_DCLL<T>::DisplayF()
{
	struct node<T>* temp=Head;
	/*for(int i=1;i<=iSize;i++)
	{
		cout<<"<-|"<<temp->Data<<"|->";
		temp=temp->Next;
	}*/
	temp=Head;
	if((Head==NULL)&&(NULL==Tail))
	{
		return;
	}
	cout<<"\n->";
	do
	{
		cout<<"<-|"<<temp->Data<<"|->";
		temp=temp->Next;
	}while(temp!=Tail->Next);
	cout<<"<-\n";
}

template<class T>
void GEN_DCLL<T>::DisplayR()
{
	struct node<T>* temp=Tail;
	/*for(int i=1;i<=iSize;i++)
	{
		cout<<"<-|"<<temp->Data<<"|->";
		temp=temp->Prev;
	}*/

	temp=Tail;
	if((Head==NULL)&&(NULL==Tail))
	{
		return;
	}
	cout<<"\n->";
	do
	{
		cout<<"<-|"<<temp->Data<<"|->";
		temp=temp->Prev;
	}while(temp!=Head->Prev);
	cout<<"<-\n";
}

template<class T>
void GEN_DCLL<T>::DeleteFirst()
{
	if((Head==NULL)&&(NULL==Tail))
	{
		return;
	}
	else if(Head==Tail)
	{
		delete Head;
		Head=NULL;
		Tail=NULL;
	}
	else
	{
		Head=Head->Next;
		delete Head->Prev;
		Tail->Next=Head;
		Head->Prev=Tail;
		iSize--;
	}
}

template<class T>
void GEN_DCLL<T>::DeleteLast()
{
	if((Head==NULL)&&(NULL==Tail))
	{
		return;
	}
	else if(Head==Tail)
	{
		delete Tail;
		Head=NULL;
		Tail=NULL;
	}
	else
	{
		Tail=Tail->Prev;
		delete Tail->Next;
		Tail->Next=Head;
		Head->Prev=Tail;
		iSize--;
	}
}

template<class T>
void GEN_DCLL<T>::InsertAtPos(T  tVal,int iPos)
{
	
	if((iPos<1)||(iPos>iSize+1))
	{
		return;
	}
	if(iPos==1)
	{
		InsertFirst(tVal);
	}
	else if(iPos==iSize+1)
	{
		InsertLast(tVal);
	}
	else
	{
		struct node<T>* newn=NULL;
		struct node<T>* temp=Head;
		newn=new struct node<T>;

		newn->Next=NULL;
		newn->Prev=NULL;
		newn->Data=tVal;

		for(int i=1;i<iPos;i++)
		{
			temp=temp->Next;
		}
		
		temp->Prev->Next=newn;
		newn->Prev=temp->Prev;
		newn->Next=temp;
		temp->Prev=newn;
		iSize++;
	}
}

template<class T>
void GEN_DCLL<T>::DeleteAtPos(int iPos)
{
	if((iPos<1)||(iPos>iSize))
	{
		return;
	}
	if(iPos==1)
	{
		DeleteFirst();
	}
	else if(iPos==iSize)
	{
		DeleteLast();
	}
	else
	{
		struct node<T>* temp=Head;
		for(int i=1;i<iPos;i++)
		{
			temp=temp->Next;
		}
		temp->Prev->Next=temp->Next;
		temp->Next->Prev=temp->Prev;
		delete temp;
		iSize--;
	}
}

template<class T>
int GEN_DCLL<T>::Count()
{
	return this->iSize;
}
