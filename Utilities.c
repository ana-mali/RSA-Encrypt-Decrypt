#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>
#include <time.h>
#include <windows.h>
int RNG_prime();
int coprime(int n1,int n2);
int setup_RSA_values(char*);
int *generate_key(int n,int phi);
char encrypt(int plain, int n, int e);
char decrypt(int cipher,int n, int d);
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


int find_gcd(int num1, int num2){
    int gcd; 
    for (int i = 1; i <= num1 && i <= num2 ; ++i){
        if (num1 % i == 0 && num2 % i == 0){
            gcd = i;
        }
    }
    return gcd;
}

/* 
Parameters:
    num1 - integer
    num2 - integer
Returns: 
    found - returns 1 if they are coprime and 0 otherwise*/
int coprime(int num1, int num2)  
{  
    if (find_gcd(num1, num2) == 1){
        return 1;
    }
    else{
        return 0;
    }
}


/*
Generates e and d values according to e*d mod phi = 1
Paramters:
    phi - used to help compute results
    n - p*q
Returns:
    arr - array of size 2 [e,d]
*/
int* generate_key(int n,int phi){
    //e must be less than phi
    //e must be coprime of n and phi
    int e;
    int* arr = (int*)malloc(sizeof(int)*2);
    for (int i=2;i<phi;i++){
        if (coprime(i,n) && coprime(i,phi)){
            arr[0]=i;
            break;
        }
    }
    
     //d*e mod phi =1
    // int counter=1;
    // int val=counter*e;
    // while(!val%phi==1){
    //     counter++;
    //     val=counter*e;
    // }
    // arr[1]=counter;

    int i=1;
    for (;;){
        int value=i*e;
        if (value%phi==1){
            arr[1]=i;
            break;
        }
        i++;
    }
    return arr;
}

int check_prime(int a)
{
   int c;
 
   for ( c = 2 ; c <= a - 1 ; c++ )
   { 
      if ( a%c == 0 )
     return 0;
   }
   return 1; // is prime
}

/*
Random Prime Number Generator
Returns:
    p - prime # for p and q 
*/
int RNG_prime(){
    int i, n;
    time_t t;
    /* Intializes random number generator */
    srand((unsigned) time(&t));
    /* random numbers from 0 to 1000 */
    int randomInt = rand() % 1000;
    if (check_prime(randomInt) == 1){
        return randomInt;
    }
    else { 
        while(1){
            randomInt = rand() % 1000;
            if (check_prime(randomInt) == 1){
                return randomInt;
            }
        }
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
    Sleep(1000);
    int q=RNG_prime();
    int phi=Phi(p,q);
    int n=p*q;
    int * arr_e_d =generate_key(n,phi);
    printf("p: %d q: %d\n",p,q);
    printf("n: %d phi: %d\n",n,phi);
    printf("e: %d d:%d \n",arr_e_d[0],arr_e_d[1]);
 //   printf("e*d mod phi = 1 = %d*%d mod %d= %d",arr_e_d[0],arr_e_d[1],phi,(arr_e_d[0]*arr_e_d[1])%phi);
}