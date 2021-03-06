
#include <iostream>
using namespace std;

#include "test.h"

struct obj
{
	obj * next;
	int value;	
};

class  Lista
{
	private:
		obj * front, * back;
	 	unsigned counter;
	
	public: 
	
		Lista();
		obj* pushFront (obj * p);
		obj* popFront();
		obj* popBack();
		obj* erase( int val);
		void showValues();
		unsigned  size() { return counter; } 
		
		obj* first() { return front; }
		obj* last()  { return back; }
	
};

Lista::Lista()
{
	front = NULL;
	back = NULL;
	counter = 0;
}
	
obj * Lista::pushFront (obj * p)
{
	p->next = front;
	front = p;
	if (!back) back = front;
	counter++;
	return front;
	
}
    
obj * Lista::popFront()
{
	obj * p;
	if (front)
	{
		p = front;	
		front = front->next;
		if(!front) back = NULL;
		counter--;
		return p; 	
	}
	else return NULL;
}

obj * Lista::popBack()
{
	obj * p;
	if (back)
	{
		p = back;
		if(p == front) 
		{
			front = back = NULL;
		}
		else
		{
			back = front;
			while (back->next != p )
			{
				back = back->next;		
			}
			back->next = NULL;
		} 
		counter--;
		return p;
	}
	else  return NULL;
	

}


//obj * Lista::erase(obj * p)
//{
//	obj * p1;
//
//	if(p == front) return popFront();
//	else
//	{
//    p1 = front;
//    while(p1->next != p) 
//	{
//		p1 = p1->next;
//	}
//    p1->next = p->next;
//    
//    counter--;
//    return p;
//	}
//}

/// usuwa element o wartosc val z listy

/// - jak elementu ?
/// - jak sa dwa lub wiecej takie lementy ?

obj * Lista::erase(int val)
{
	obj * p;
	obj * p1;

	if(val == front->value) return popFront();
	else
	{
    p = front;
    while(p->value != val) 
	{
	    p = p->next;
	}
	cout << p->value;
    p1 = p->next;
	p->next = p1->next;
    
    counter--;
    return p1;
	}
} 


void Lista::showValues()
    {
      obj * p;
      
      if(!front) cout << "Lista jest pusta." << endl;
      else
      {
        p = front;
        while(p)
        {
          cout << p->value << " ";
          p = p->next;
        }
        cout << endl;
      }
    }



void test_zbyszka() 
{
    Lista sl;
    
    CHECK_EQUAL(sl.size(), 0 );
    
    for(int i = 1; i <= 10; i++)
    {
        obj* p = new obj;
        p->value = i;
        sl.pushFront(p);
        CHECK_EQUAL(sl.size(), i );
    }
    CHECK_EQUAL(sl.size(), 10 );
    sl.popFront();
    CHECK_EQUAL(sl.size(), 9 );
    sl.erase(5);
    CHECK_EQUAL(sl.size(), 8 );
}

void test_na_usuwanie()
{
    Lista sl;
    CHECK_EQUAL(sl.size(), 0 );
    for(int i = 1; i <= 3; i++)
    {
        obj* p = new obj;
        p->value = i;
        sl.pushFront(p);
    }
    
    CHECK_EQUAL(sl.first()->value, 3);
    CHECK_EQUAL(sl.first()->next->value, 2);
    CHECK_EQUAL(sl.first()->next->next->value, 1);
    
    sl.erase(1);
    
    CHECK_EQUAL(sl.first()->value, 3);
    CHECK_EQUAL(sl.first()->next->value, 2);
    //CHECK_EQUAL(sl.first()->next->next, 0);
    CHECK_EQUAL(sl.size(), 2);
}

void stare_main()
{

	Lista sl;
	int   i;
  
	cout << "(A) : "; sl.showValues();  
  
	for(i = 1; i <= 10; i++)
	{
	    obj* p = new obj;
	    p->value = i;
	    sl.pushFront(p);
	}


	cout << "(B) : ";   sl.showValues();
  
	sl.popFront();

	cout << "(C) : ";   sl.showValues(); 
	
	sl.erase(5);
	
	cout << "(5) : ";   sl.showValues();
}

int main(int argc, char** argv)
{
    RUN_TEST(stare_main);
    RUN_TEST(test_zbyszka);
    RUN_TEST(test_na_usuwanie);
    
    if( error_count != 0 ) {
        return 1;
    } else {
        return 0;
    }
}
