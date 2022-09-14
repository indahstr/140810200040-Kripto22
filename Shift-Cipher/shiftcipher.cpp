/*
    Nama    : Indah Sutriyati
    NPM     : 140810200040
    Kelas   : B
    Program : Shift Cipher
*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main(){
    cout << "========================\n";
    cout << "  SHIFT CIPHER PROGRAM\n";
    cout << "========================\n\n";

    cout << "Teks  : ";
    char teks[100];
    cin.getline(teks,100);

    int i, j, length, pilihan, key;
    cout << "Kunci : ";
    cin >> key;
    cout << endl;

    length = strlen(teks);
    
    cout << "Menu \n1. Enkripsi \n2. Dekripsi \n";
    cout << "\nPilih menu : ";
    cin >> pilihan;
    cout << endl;
    
    if(pilihan == 1){
        char ch;
        for(int i = 0; teks[i] != '\0'; ++i){
            ch = teks[i];
            if(ch >= 'a' && ch <= 'z'){
                ch = ch + key;
                if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
                }  
                teks[i] = ch;
            }
            else if(ch >= 'A' && ch <= 'Z'){
                ch = ch + key;
                if (ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
                }
                teks[i] = ch;
            }
        }
        printf("Ciphertext : %s", teks);
    }
    else if(pilihan == 2){
        char ch;
        for(int i = 0; teks[i] != '\0'; ++i){
            ch = teks[i];
            if(ch >= 'a' && ch <= 'z') {
                ch = ch - key;
                if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
                }
                teks[i] = ch;
            }
            else if(ch >= 'A' && ch <= 'Z') {
                ch = ch - key;
                if(ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
                }
                teks[i] = ch;
            }
        }
        cout << "Plaintext : " << teks;
    }
    cout << "\n========================\n";

    return 0;
}