#include "modRouteCipher.h"
#include <iostream>
#include <locale>
using namespace std;
void check(const wstring& Text, const int key)
{ 
	try{
		wstring cipherText;
		wstring decryptedText;
		modRouteCipher cipher(key, Text);
		cipherText = cipher.encrypt(Text, key);
		decryptedText = cipher.decrypt(cipherText, key);
		wcout<<L"key="<<key<<endl;
		wcout<<Text<<endl;
		wcout<<cipherText<<endl;
		wcout<<decryptedText<<endl;
	}
	catch (const cipher_error & e) {
		wcerr<<"Error: "<<e.what()<<endl;
	}
}
int main(int argc, char **argv)
{ 
	locale loc("ru_RU.UTF-8");
    locale::global(loc);
	wstring Text =L"123456789";
	check(Text, 4); // Text + key 
	return 0;
}