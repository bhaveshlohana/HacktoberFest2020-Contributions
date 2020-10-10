
#include <bits/stdc++.h> 
#include <string>
using namespace std; 

// Function generates the encoded text 
string encoder(string key) 
{ 
	string encoded = ""; 
	// This array represents the  26 letters of alphabets 
	bool arr[26] = {0}; 

	for (int i=0; i<key.size(); i++) 
	{ 
		if(key[i] >= 'A' && key[i] <= 'Z') 
		{ 
			if (arr[key[i]-65] == 0) 
			{ 
				encoded += key[i]; 
				arr[key[i]-65] = 1; 
			} 
		} 
		else if (key[i] >= 'a' && key[i] <= 'z') 
		{ 
			if (arr[key[i]-97] == 0) 
			{ 
				encoded += key[i] - 32; 
				arr[key[i]-97] = 1; 
			} 
		} 
	} 

	for (int i=0; i<26; i++) 
	{ 
		if(arr[i] == 0) 
		{ 
			arr[i]=1; 
			encoded += char(i + 65); 
		} 
	} 
	return encoded; 
} 

// Function that generates cipher message 
string cipheredIt(string msg, string encoded) 
{ 
	string cipher=""; 

	// This loop ciphered the message. 
	// Spaces, special characters and numbers remain same. 
	for (int i=0; i<msg.size(); i++) 
	{ 
		if (msg[i] >='a' && msg[i] <='z') 
		{ 
			int pos = msg[i] - 97; 
			cipher += encoded[pos]; 
		} 
		else if (msg[i] >='A' && msg[i] <='Z') 
		{ 
			int pos = msg[i] - 65; 
			cipher += encoded[pos]; 
		} 
		else
		{ 
			cipher += msg[i]; 
		} 
	} 
	return cipher; 
} 

// Main function 
int main() 
{ 

	string key; 							// Store Keyword
    cout<<"Enter Your Key: ";
	cin >> key; 
	cout << "Keyword : " <<key << endl; 

	
	string encoded = encoder(key); 					// encoder Function Call
	string message;
	cout<<"Enter Your Message: ";  
	ws(cin);							
    //cin>>message;							
	getline(cin,message);										// Store your Message
	cout << "Message before Ciphering : " << message << endl; 


	cout << "Ciphered Text : " << cipheredIt(message,encoded) << endl; 

	return 0; 
} 
