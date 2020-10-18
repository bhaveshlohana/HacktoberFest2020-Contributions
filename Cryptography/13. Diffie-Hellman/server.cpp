/* Author : Aditya Pranav, AKSHAT AGARWAL 

13. Compute common secret key between client and server using Diffie-Hellman key exchange technique. Perform encryption and decryption of message using the shared secret key (Use simple XOR operation to encrypt and decrypt the message.)  */

/* Server Program */

# include <bits/stdc++.h>
# include <arpa/inet.h> 
using namespace std;

int createServer(int port)  // TCP connection
{
	int sersock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {AF_INET, htons(port), INADDR_ANY};
    
    bind(sersock, (struct sockaddr *) &addr, sizeof(addr));
    cout << "\nServer Online. Waiting for client...." << endl;
    
    listen(sersock, 5);
    int sock = accept(sersock, NULL, NULL);
    cout << "Connection Established." << endl;
    return sock;
}

int randInRange(int low, int high) // excluding high and low
{
    return rand()%(high-(low+1)) + (low+1) ;
}

long powermod(long a, long b, long  q)
{
	long res=1;
	for(long i=0; i<b; i++)
	{
		res=(res*a)%q;
	}
	return res;
}

int main()
{
     
	
	long q1, alpha1,q2, alpha2;
	cout << "\nEnter values for Alice :";
	cout<<"\nEnter a prime number, q : "; cin >> q2;
	cout<<"Enter primitive root of q, alpha : "; cin >> alpha2;
	srand(time(NULL));
	long Xc = randInRange(1, q2); // Alice's private key (1<Xa<q)
	cout<< "\nClient's private key, Xc = " << Xc <<endl;
	
	long Yc = powermod(alpha2, Xc, q2); // Alice's public key
	cout<< "\nAlice 's public key,  Yc = " << Yc <<endl;
	
	cout << "\nEnter values for Bob :";
	cout<<"\nEnter a prime number, q : "; cin >> q1;
	cout<<"\nEnter primitive root of q, alpha : "; cin >> alpha1;
	
	srand(time(NULL));
	long Xs = randInRange(1, q1); // Bob's private key
	cout<< "\nBob's private key, Xs = " << Xs <<endl;
	
	long Ys = powermod(alpha1, Xs, q1); // Bob's public key
	cout<< "Bob's public key,  Ys = " << Ys <<endl;
	
	long k1 = powermod(Yc,Xs,q1);	
	cout<<"\nSecret Key of bob, k = "<<k1<<endl;
	long k2 = powermod(Ys,Xc,q2);	
	cout<<"\nSecret Key of Alice, k = "<<k<<endl;

	long msg;
	cout<<"\nEnter a message(number) to send to Alice: "; cin>>msg;
	
	long cipher = msg ^ k; // encryption

	cout << "Encrypted msg sent to Alice: " << cipher << endl << endl;
}

/* 
some values for q and alpha
q=11, alpha=2
q=71, alpha=7
*/

/*
Enter port : 4444

Server Online. Waiting for client....
Connection Established.

Enter a prime number, q : 11
Enter primitive root of q, alpha : 2

Client's public key,  Yc = 5

Server's private key, Xs = 10
Server's public key,  Ys = 1

Secret Key, k = 1

Enter a message(number) to send : 453
Encrypted msg sent to client: 452
*/
