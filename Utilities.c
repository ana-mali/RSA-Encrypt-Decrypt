#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>
#include <time.h>
int RNG_prime();
int coprime(int n1,int n2);
int setup_RSA_values(char*);
int generate_key(int n,int phi);
char encrypt(int plain, int n, int e);
int Phi(int p, int q);


//Anastasia, Jonotham and Ruicheng
//CP460 Applied Cryptography Project

//Module used for utility functions for RSA 
//Classes can be used to form attributes such as:
//Sender info, reciever info, sender/reciever public and private key

typedef struct{
    int n,p,q,e,d,phi;
    char* plaintext; 
//    int plaintext; //number form
    char* ciphertext;
//    int ciphertext; //number form

}RSA;

int setup_RSA_values(char* plaintext){
    //set up random integer values
    int p=RNG_prime();
    int q=RNG_prime();
    int n=p*q;
    int phi=Phi(p,q); 
//    int e=
//    int d=
    

    
}
/* 
Parameters:
    num1 - integer
    num2 - integer
Returns: 
    found - returns 1 if they are coprime and 0 otherwise*/
int coprime(int num1, int num2)  
{  
    int min, count, found = 1;  
    min = num1 < num2 ? num1 : num2;  
    for(count = 2; count <= min; count++)  
    {  
        if( num1 % count == 0 && num2 % count == 0 )  //if divisible then not coprime
        {  
            found = 0;  
            break;  
        }  
    }  
    return(found);  
}


/*
Generates e and d values according to e*d mod phi = 1
Paramters:
    phi - used to help compute results
    n - p*q
Returns:
    e - encryption value
    d - decryption value
*/
int generate_key(int n,int phi){
    //e must be less than phi
    //e must be coprime of n and phi
    int e,d;
    for (int i=1;i<n;i++){
        if (coprime(i,n)){
            if (coprime(i,phi))
            e=i;
            break;
        }
    }

    for (int i=1;i<n;i++){
        int value=i*e;
        int m=value%n;
        if (m==1){
            d=i;
            break;
        }
    }
    return e,d;
}



/*
Random Prime Number Generator
Returns:
    p - prime # for p and q 
*/
int RNG_prime(){
    int found=0;
    time_t t;
   /* Intializes random number generator */
    srand((unsigned) time(&t));
    int lower = 1;
    int upper = 1000;
    int p = rand() % (upper - lower) + lower;
    for (int i = 2; i <= p / 2; ++i) {
    // if n is divisible by i, then n is not prime
    // change flag to 1 for non-prime number
        if (p % i == 0) {
        found = 1;
        break;
        }
    }
    if (found==0){
        return p;
    }else{
        RNG_prime(); //run program again until prime 
    }
}


/*
Parameters:
    plain - string as plain text
Returns:
    output - string as cipher text
*/
char encrypt(int plain, int n, int e){
    double y=pow(plain,e);
    long w=y;
    return w%n;
}

/*
Parameters:
    cipher - string as cipher text
Returns:
    output - string as plain text
*/
char decrypt(int cipher,int n, int d){
    //double x=pow(cipher, d);
    
}

/*
Generate both public or private key
*/
char create_key(){
    
}

/*
Phi function 
phi(n)=(p-1)(q-1)
Parameters:
    p - large prime
    q - large prime
Returns:
    phi - Euler Phi result
 */
int Phi(int p, int q){
    int n = (p-1)*(q-1);
    return n;
}


int main(){
    int p=RNG_prime();
    printf("%d\n",p);


}