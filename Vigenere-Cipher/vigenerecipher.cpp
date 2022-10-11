/*
    Nama    : Indah Sutriyati
    NPM     : 140810200040
    Kelas   : B
    Program : Vigenere Cipher
*/
#include <iostream>
#include <string>
using namespace std;

class Vigenere{
    public:
        string key;
        Vigenere(string key){
            for (int i = 0; i < key.size(); ++i){
                if (key[i] >= 'A' && key[i] <= 'Z')
                    this->key += key[i];
                else if (key[i] >= 'a' && key[i] <= 'z')
                    this->key += key[i] + 'A' - 'a';
            }
        }
 
        string encrypt(string text){
            string out;
 
            for (int i = 0, j = 0; i < text.length(); ++i){
                char c = text[i];
 
                if (c >= 'a' && c <= 'z')
                    c += 'A' - 'a';
                else if (c < 'A' || c > 'Z')
                    continue;
 
                out += (c + key[j] - 2 * 'A') % 26 + 'A';
                j = (j + 1) % key.length();
            }
 
            return out;
        }
 
        string decrypt(string text){
            string out;
 
            for (int i = 0, j = 0; i < text.length(); ++i){
                char c = text[i];
 
                if (c >= 'a' && c <= 'z')
                    c += 'A' - 'a';
                else if (c < 'A' || c > 'Z')
                    continue;
 
                out += (c - key[j] + 26) % 26 + 'A';
                j = (j + 1) % key.length();
            }
            return out;
        }
};

int main(){
    Vigenere cipher("bebas");
    string str, keyword;
    string cipher_text, plain_text;
    int pilih;

    do{
        cout << "===========================\n";
        cout << "  Program Vigenere Cipher  \n";
        cout << "===========================\n\n";
        cout << "Menu\n";
        cout << "1. Enkripsi\n";
        cout << "2. Deskripsi\n";
        cout << "3. Exit\n";
        cout << "Pilih menu : ";
        cin >> pilih;
        system("cls");
        cout << "===========================\n";
        cout << "  Program Vigenere Cipher  \n";
        cout << "===========================\n\n";
        switch (pilih){
        case 1:
            cout << "Masukan Kata\t: ";
            cin.ignore(100, '\n');
            getline(cin, str);
            cout << "Masukan Key\t: ";
            cin >> keyword;
            cipher.key = keyword;
            cipher_text = cipher.encrypt(str);
            cout << "Ciphertext\t: " << cipher_text << "\n";
            break;
        case 2:
            cout << "Masukan Kata\t: ";
            cin.ignore(100, '\n');
            getline(cin, str);
            cout << "Masukan Key\t: ";
            cin >> keyword;
            cipher.key = keyword;
            plain_text = cipher.decrypt(cipher_text);
            cout << "Decrypted Text\t: " << plain_text<< "\n";
            break;
        default:
            break;
        }
    } while (pilih != 3);
}