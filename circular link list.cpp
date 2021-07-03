#include<iostream>
using namespace std;

class NODE
{
private:
	int data;
	NODE *next;
public:
	void setdata(int val)
	{
		data=val;
	}
	int getdata()const
	{
		return data;
	}
	void setnext(NODE *ptr)
	{
		next=ptr;
	}
	NODE* getnext()
	{
		return next;
	}
};

class LIST
{
private:
	NODE *headnode;
	NODE *current;
	NODE *previous;
	int size;
public:
	LIST()
	{
		headnode=current=previous=NULL;
		size=0;
	}
	void add(int val)
	{
		NODE *newnode=new NODE();
		newnode->setdata(val);
		if(current!=NULL)
		{
			/*newnode->setnext(headnode);
			current->setnext(newnode);
			previous=current;
			current=newnode;*/
			newnode->setnext(current->getnext());
			current->setnext(newnode);
			previous=current;
			current=newnode;
		}
		else
		{
			newnode->setnext(newnode);
			previous=headnode=current=newnode;
		}
		size++;

	}
	void Delete()
	{
		if(current!=NULL||size!=0)
		{
			previous->setnext(current->getnext());
			delete current;
			current=previous->getnext();
			size--;
		}
	}
	bool search(int val)
	{
		NODE *temp=headnode;
		bool flag=false;
		this->start();
		for(int i=0;i<length();i++)
		{
			if(temp->getdata()==val)
			{
				flag=true;
				return 1;
			}
			//this->next();
			temp=temp->getnext();
		}
		if(flag==false)
		{
			return 0;
		}

	}
	void start()
	{
		previous=current=headnode;
	}
	int getvalue()
	{
		return current->getdata();
	}
	int length()
	{
		return size;
	}
	int next()
	{
		if(size!=0||current!=NULL)
		{
			previous=current;
			current=current->getnext();
			return 1;
		}
		return 0;
	}
	void AlterDelete()
	{
		start();
		while(size!=1)
		{
			next();
			if(current==headnode)
			{
				//headnode=headnode->getnext();
				current=headnode->getnext();
			}
			Delete();
		}
	}
	void Douplicate() 
	{
		NODE* temp=headnode;
		int count;
		bool flag=false;
		for(int i=0;i<size;i++)
		{
			for(int k=0;k<=i;k++)
			{
				count=temp->getdata();
				temp=temp->getnext();
			}
			for(int j=0;j<size;j++)
			{
				if(count==temp->getdata())
				{
					flag=true;
				}
				if(j<size-1)
				temp=temp->getnext();
			}
			temp=headnode;
		}
		if(flag==true)
		{
			this->Delete();
			this->BubbleSort();
		}
		else
		{
			cout<<"There is no dublicate value."<<endl;
		}

	}
	void BubbleSort() 
	{
	int val;
	NODE* temp=headnode;
	for(int i=0;i<=this->length()-1;i++)
	{
		for(int j=0;j<=this->length()-i-1;j++)
		{
			if(temp->getdata()>temp->getnext()->getdata())
			{
				val=temp->getdata();
				temp->setdata(temp->getnext()->getdata());
				temp->getnext()->setdata(val);
			}
			temp=temp->getnext();
		}
		temp=headnode;
	}
}
	
};
void display(LIST obj)
	{
		
		obj.start();
		for(int i=0;i<obj.length();i++)
		{
		
		cout<<obj.getvalue()<<endl;
		obj.next();
		}
	}

int main()
{
	char choice;
	int val;
	LIST l;
	do
	{
		cout<<"\t__________________________"<<endl;
		cout<<"\t|       ***MENUE***       |"<<endl;
		cout<<"\t| I/i :: insert           |"<<endl;
		cout<<"\t| D/d :: delete one by one|"<<endl;
		cout<<"\t| R/r :: delete alternate |"<<endl;
		cout<<"\t| X/x :: duplicate delete |"<<endl;
		cout<<"\t| P/p :: print LIST       |"<<endl;
		cout<<"\t| E/e ::  exit(0)         |"<<endl;
		cout<<"\t -------------------------"<<endl;
		cout<<"choice= ";
		cin>>choice;
		switch(choice)
		{
		case 'I':case 'i':
			cout<<"Enter value which you want to insert: ";
			cin>>val;
			l.add(val);
			break;
		case 'D':case'd':
			cout<<"Enter value which you want to dell: ";
			cin>>val;
			if(l.search(val))
			{
				l.Delete();
			}
			else
				cout<<"Sorry! value not found."<<endl;
			break;
		case 'R':case 'r':
			 l.AlterDelete();
			break;
			case 'X':case 'x':
			 l.Douplicate();
			break;
		case'P':case'p':
		     display(l);
			break;
		case'E':case'e':
			break;
		default:
			cout<<"Sorry! Inavlid choice."<<endl;
			cout<<"Chose the appropriate choice."<<endl;
		}
	}
	while(choice!='E'&&choice!='e');
	system("pause");
	
}

