#include <iostream>
#include <locale>
#include "modAlphaCipher.h"
using namespace std;
void check(const wstring& Text, const wstring& key, const bool destructCipherText=false)
{ 
	try {
		wstring cipherText;
		wstring decryptedText;
		modAlphaCipher cipher(key);
		cipherText = cipher.encrypt(Text); // зашифровывание
		if (destructCipherText) // надо "портить"?
			cipherText.front() = tolower(cipherText.front()); // "портим"
		decryptedText = cipher.decrypt(cipherText);
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
/{ 
	locale loc("ru_RU.UTF-8");
    locale::global(loc);
	check(L"Lorem ipsum dolor sit amet, consectetur adipiscing elit",L"Lorem");
	check(L"Lorem ipsum dolor sit amet, consectetur adipiscing elit",L"");
	check(L"Lorem ipsum dolor sit amet, consectetur adipiscing elit",L"TEST 123");
	check(L"TLorem ipsum dolor sit amet, consectetur adipiscing elit",L"a");
	check(L"123",L"ABCD");
	check(L"Lorem ipsum dolor sit amet, consectetur adipiscing elit",L"consectetur",true);
return 0;
}