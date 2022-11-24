//Anastasia, Jonotham and Ruicheng
//CP460 Applied Cryptography Project

//Module used for utility functions for RSA 
//Classes can be used to form attributes such as:
//Sender info, reciever info, sender/reciever public and private key

typedef struct{
    int n,p,q,e,k,phi;
    char* plaintext; 
    int plaintext; //number form
    char* ciphertext;
    int ciphertext; //number form

}RSA;


int setup_RSA_values(char* plaintext){
    //set up random integer values
    int p=RNG_prime();
    int q=RNG_prime();
    int n=p*q;
    int phi=Phi(p,q); 
    int e=RNG(n);
    int k=RNG(n);
    
    //convert plain text into number form
    char alphabet[26]=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v',
                    'w','x','y','z']; 
    char cap_alphabet[26]=['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V',
                    'W','X','Y','Z'];
    
}

/*
Normal Random Number Generator
Paramters:
    n - integer used as upper bound
Returns:
    e - exponent value between 1 and n
*/
int RNG(int n){
    int lower=1;
    extern unsigned int urand();
    int e = urand() % (n - lower) + lower;
    return e;
}

/*
Random Prime Number Generator
Returns:
    p - prime # for p and q 
*/
int RNG_prime(){
    int found=0;
    extern unsigned int urand();
    int lower = 1;
    int upper = 1000;
    int p = urand() % (upper - lower) + lower;
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
char encrypt(char *plain){

}

/*
Parameters:
    cipher - string as cipher text
Returns:
    output - string as plain text
*/
char decrypt(char *cipher){

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
