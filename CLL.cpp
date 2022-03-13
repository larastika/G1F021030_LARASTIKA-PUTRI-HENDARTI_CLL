//--------------------------------//
//__CIRCULAR SINGLE LINKED LIST__//
//-BY: LARASTIKA PUTRI HENDARTI-//
//-----------------------------//

#include <iostream>
using namespace std;

// Deklarasi struktur untuk Circular Single Linked List
struct Tanggal_Lahir{
  string Bulan;
  int Tanggal, Tahun;

  Tanggal_Lahir *next;
};

Tanggal_Lahir *head, *tail, *newNode, *cur, *del;

// create Circular Single Linked List
void createCircularSingleLinkedList( int Tanggal, string Bulan, int Tahun ){

  head = new Tanggal_Lahir();
  head->Tanggal = Tanggal;
  head->Bulan= Bulan;
  head->Tahun = Tahun;
  tail = head;
  tail->next = head;

}

	//Sequential SLL//
	int countSingleLinkedList(){
		cur=head;
		int jumlah=0;
		while(cur!=NULL){
			jumlah++;
			cur=cur->next;
		}
		return jumlah;
}

// add first
void addFirst(int Tanggal, string Bulan, int Tahun){
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    newNode = new Tanggal_Lahir();
    newNode->Tanggal=Tanggal;
    newNode->Bulan= Bulan;
    newNode->Tahun= Tahun;
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
  }
}

// add Last
void addLast( int Tanggal, string Bulan, int Tahun ){
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    newNode = new Tanggal_Lahir();
    newNode->Tanggal= Tanggal;
    newNode->Bulan= Bulan;
    newNode->Tahun= Tahun;
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
  }
}

// add Middle
void addMiddle(int Tanggal, string Bulan, int Tahun, int posisi)
{
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    if( posisi == 1 ){
      cout << "Posisi satu bukan posisi tengah!!!" << endl;
    }else{
      newNode = new Tanggal_Lahir();
      newNode->Tanggal= Tanggal;
      newNode->Bulan= Bulan;
      newNode->Tahun= Tahun;

      // tranversing
      int nomor = 1;
      cur = head;
      while (nomor < posisi - 1)
      {
        cur = cur->next;
        nomor++;
      }
      newNode->next = cur->next;
      cur->next = newNode;
    }
  }
}

// remove First
void removeFirst(){
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    del = head;
    head = head->next;
    tail->next = head;
    delete del;
  }
}

// remove last
void removeLast()
{
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    del = tail;
    cur = head;
    while( cur->next != tail ){
      cur = cur->next;
    }
    tail = cur;
    tail->next = head;
    delete del;
  }
}

// remove middle
void removeMiddle(int posisi)
{
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    // tranversing
    int nomor = 1;
    cur = head;
    while( nomor < posisi - 1 ){
      cur = cur->next;
      nomor++;
    }
    del = cur->next;
    cur->next = del->next;
    delete del;
  }
}


void printCircular()
{
  if( head == NULL ){
    	cout << "Buat Linked List dulu!!" << endl;
  }else{
    	cout << "Tanggal_Lahir " << endl;
    	cout << "|_______________________________________________________|" << endl; 
   		cout << "| Tanggal\t| Bulan\t\t\t| Tahun\t\t|" << endl;
    	cout << "|_______________________________________________________|" << endl; 
    	cur = head;
    while (cur->next != head)
    {
      // print
    	cout << "|"	 << cur->Tanggal<<"\t\t|"<< cur->Bulan<< "\t\t\t|"<< cur->Tahun<< "\t\t|" << endl;
      	cur = cur->next;
    }
    	cout << "|"  << cur->Tanggal<<"\t\t|"<< cur->Bulan<< "\t\t\t|"<< cur->Tahun<< "\t\t|"<< endl;
    	cout << "|_______________________________________________________|" << endl;
  }
}


int main(){

  createCircularSingleLinkedList(26,"Juli",2003);
printCircular();
 
  addFirst(4,"Mei",2003);
printCircular();

  addLast(29,"Juni",2003);
printCircular();

  addMiddle(05,"April",2003 , 5);
printCircular();

  removeMiddle(6);

  printCircular();

  removeFirst();

  printCircular();

  removeLast();

  printCircular();
}
