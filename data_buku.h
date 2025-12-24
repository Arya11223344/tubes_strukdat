#ifndef DATA_BUKU_H
#define DATA_BUKU_H

#include <iostream>
#include <string>
using namespace std;

struct Buku {
    string idBuku;
    string judul;
    int tahun;
    int totalPenulis;   
};

struct Penulis {
    string idPenulis;
    string nama;
    int jumlahBuku;     
};

struct elmBuku;
struct elmPenulis;
struct elmRelasi;

typedef elmBuku* adrBuku;
typedef elmPenulis* adrPenulis;
typedef elmRelasi* adrRelasi;

struct elmBuku {
    Buku info;
    adrBuku next;
};

struct ListBuku {
    adrBuku first;
};

struct elmRelasi {
    adrBuku buku;      
    adrRelasi next;
};

struct elmPenulis {
    Penulis info;
    adrPenulis next;
    adrPenulis prev;
    adrRelasi firstRelasi;   
};

struct ListPenulis {
    adrPenulis first;
    adrPenulis last;
};


void createListBuku(ListBuku &LB);
void createListPenulis(ListPenulis &LP);

adrBuku alokasiBuku(const Buku &b);
adrPenulis alokasiPenulis(const Penulis &p);
adrRelasi alokasiRelasi(adrBuku b);

void insertLastBuku(ListBuku &LB, adrBuku p);
adrBuku findBukuByID(ListBuku LB, const string &id);
adrBuku deleteBukuByID(ListBuku &LB, const string &id);

void insertLastPenulis(ListPenulis &LP, adrPenulis p);
adrPenulis findPenulisByID(ListPenulis LP, const string &id);
adrPenulis deletePenulisByID(ListPenulis &LP, const string &id);

bool tambahRelasiPenulisBuku(ListPenulis &LP, ListBuku &LB,
                             const string &idPenulis, const string &idBuku);
void hapusRelasiPenulis(adrPenulis pen);              
void hapusRelasiBuku(ListPenulis &LP, adrBuku b);     

void tampilkanSemuaBukuBesertaPenulis(ListBuku LB, ListPenulis LP);
void tampilkanSemuaPenulis(ListPenulis LP);
void tampilkanBukuDariPenulis(ListPenulis LP);
void tampilkanPenulisDariBuku(ListPenulis LP, ListBuku LB);
void tampilkanPenulisPalingAktifDanTidak(ListPenulis LP);

void menuTambahPenulis(ListPenulis &LP);
void menuTambahBuku(ListBuku &LB);
void menuRelasiPenulisBuku(ListPenulis &LP, ListBuku &LB);
void menuHapusPenulis(ListPenulis &LP);
void menuHapusBuku(ListPenulis &LP, ListBuku &LB);

#endif