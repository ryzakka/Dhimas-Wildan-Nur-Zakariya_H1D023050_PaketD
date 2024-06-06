#include <iostream>
using namespace std;

typedef struct node *address;
struct node{
    address prev; //node sebelumnya
    int data; //id buku
    address next; //node berikutnya
};

address first, last = NULL;

address alokasi(int datanya){
    address hasil = new node;
    hasil -> data = datanya;
    hasil -> next = hasil -> prev = NULL;
    return hasil;
}

void insertfirst(address baru){
    if(first == NULL){
        first = last = baru;} else {
            baru -> next = first;
            first -> prev = baru;
            first = baru;
        }
    }
    
void insertlast(address baru){
    if(first == NULL){
        first = last = baru;} else {
            last -> next = baru;
            baru -> prev = last;
            last = baru;
        }
    }

void deletefirst(){
    if(first == NULL){
        cout << "Daftar buku kosong." << endl;
        return;
    }
    
    first = first->next;
    delete first->prev;
    first->prev = NULL;
}

void deletelast(){
    if(first==NULL){
        cout << "Daftar buku kosong." << endl;
        return;
    }
    last = last -> prev;
    delete last -> next;
    last -> next = NULL;
}

void cetak(){
    address p=first;
    while (p!=NULL){
        cout<< "ID buku: " << p->data << endl;
        p = p -> next;
    }
}

//lanjutkan fungsi untuk mengecek ID buku prima
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;}}
    return true;
}


//Fungsi untuk mencetak buku dengan ID prima
void printPrimeBookIDs() {
    address p = first;
    while (p != NULL) {
        if (isPrime(p->data)) {
            cout << "ID buku prima: " << p->data << endl;}
        p = p->next;}}


//Fungsi untuk menemukan buku berdasarkan ID
address cariBuku(int id) {
    address p = first;
    while (p != NULL) {}
    return NULL;
}


//Fungsi untuk menghapus buku berdasarkan id
void hapusBuku(int id) {
    address p = first;
    while (p != NULL) {
        if (p->data == id) {
            if (p == first) {
                deletefirst();} else if (p == last) {
                deletelast(); } else{
                p->prev->next = p->next;
                p->next->prev = p->prev;
                delete p;}
            return;}
        p = p->next;}
    cout << "Buku dengan ID " << id << " tidak ditemukan." << endl;
}


int main(){
    insertlast(alokasi(10));
    insertfirst(alokasi(30));
    insertlast(alokasi(50));
    insertlast(alokasi(19));
    insertfirst(alokasi(90));
    insertlast(alokasi(27));
    insertlast(alokasi(11));
    
    
    cout << "Daftar buku awal: " << endl;
    cetak();
    
    hapusBuku(20);
    hapusBuku(10);
    cout << "\nDaftar buku setelah penghapusan" << endl;
    cetak();
    
    cout << "\nDaftar buku dengan ID Bilangan Prima: " << endl;
    printPrimeBookIDs();
    return 0;
} 
