#include "fscrypt.h"
#include <string.h>
//endchar al!
void *fs_encrypt(void *plaintext, int bufsize, char *keystr, int *resultlen){
    BF_KEY key;//key
    BF_set_key(&key, strlen(keystr), (const unsigned char *) keystr);//create key
    char IV[BLOCKSIZE] = {0,0,0,0,0,0,0,0};//initilazation vector

    char* pt = static_cast<char*> (plaintext);
    int diff, blocks;
    unsigned char* buffer;
    if(bufsize%BLOCKSIZE == 0){//if bufsize fills the block create extra block
        diff = (bufsize / BLOCKSIZE) + 1; //how many blocks-1
        buffer = new unsigned char[bufsize+BLOCKSIZE];//to return (ciper buffer)
    }
    else{//if bufsize not fill block fill block 
        diff = (bufsize / BLOCKSIZE) + 1;//how many blocks-1
        blocks = diff*BLOCKSIZE;//how many blocks plain text need
        buffer = new unsigned char[blocks];//create buffer
    }

    if(bufsize < BLOCKSIZE){
        //pad to complete 64
        diff = BLOCKSIZE - bufsize;
        char buffer1[BLOCKSIZE];//buffer of plain txt
        char buffer2[BLOCKSIZE];//buffer of XOR
        char buffer3[BLOCKSIZE];//buffer for encrypt

        for (int i = 0; i < bufsize; i++){//buffsize includes end char
            buffer1[i] = pt[i];//put plain text to buffer
        }
        for(int i = bufsize; i<=BLOCKSIZE; i++){//to pad after end char till BLOCKSIZE
            buffer1[i] = diff;//pad with the needed pad number 
        }
        //xor 
        for(int i = 0; i<BLOCKSIZE; i++){
            buffer2[i] =buffer1[i] ^ IV[i];
        }
        //call ecb and put result in buffer
        
        unsigned char* bf2 = reinterpret_cast<unsigned char*>(buffer2);
        
        unsigned char* bf3 = reinterpret_cast<unsigned char*>(buffer3);
        
        BF_ecb_encrypt(bf2, bf3, &key,1);
        
        for(int i = 0; i<BLOCKSIZE; i++){
            buffer[i] = bf3[i];
        }    

    }
    else if (bufsize%BLOCKSIZE == 0){
        char buffer1[BLOCKSIZE];//plaintext buffer
        char buffer2[BLOCKSIZE];//xor buffer
        char buffer3[BLOCKSIZE];//encrpt buffer

        for(int i = 0; i< diff;i++){
            //plain txt
            if(i == diff-1){
                for(int j = 0; j < BLOCKSIZE; j++){//put plain text in buffer
                    buffer1[j] = BLOCKSIZE;
                }  
            }
            else{
                for(int j = 0; j < BLOCKSIZE; j++){//put plain text in buffer
                    buffer1[j] = pt[j+(i*BLOCKSIZE)];
                }
            }

            //xor
            if(i == 0){//if it is the first iteration xor with initilization
                for(int j = 0; j<BLOCKSIZE; j++){//xor with initilization
                    buffer2[j] =buffer1[j] ^ IV[j];
                }
            }
            else{
                for(int j = 0; j<BLOCKSIZE; j++){//xor with initilization
                    buffer2[j] =buffer1[j] ^ buffer3[j];
                }
            }

            //call ecb
            unsigned char* bf2 = reinterpret_cast<unsigned char*>(buffer2);
            unsigned char* bf3 = reinterpret_cast<unsigned char*>(buffer3);
        
            BF_ecb_encrypt(bf2, bf3, &key,1);
            
            for(int j = 0; j<BLOCKSIZE; j++){//put first part in buffer
                buffer[j+(i*BLOCKSIZE)] = bf3[j];
            }
        }

    }
    else
    {
        int pads = BLOCKSIZE - (bufsize % BLOCKSIZE);
        int lB = bufsize / BLOCKSIZE;
        int lastBlock  = lB * BLOCKSIZE;

        char buffer1[BLOCKSIZE];//plian txt buffer
        char buffer2[BLOCKSIZE];//xor buffer
        char buffer3[BLOCKSIZE];//encrpt buffer

        //put plain text in buffer1 cipher in buffer2
        //put buffer2 in big buffer

        for(int i = 0; i< diff;i++){
            //plain txt
            if(i == diff-1){
                for (int j = 0; j < lastBlock; j++){//buffsize includes end char
                    buffer1[j] = pt[j+(i*BLOCKSIZE)];
                }
                for(int j = lastBlock; j<pads+lastBlock; j++){//to pad after end char till BLOCKSIZE
                    buffer1[j] = pads;//pad with how small the 
                }  
            }
            else{
                for(int j = 0; j < BLOCKSIZE; j++){//put plain text in buffer
                    buffer1[j] = pt[j+(i*BLOCKSIZE)];
                }  
            }

            //xor
            if(i == 0){//if it is the first iteration xor with initilization
                for(int j = 0; j<BLOCKSIZE; j++){//xor with initilization
                    buffer2[j] =buffer1[j] ^ IV[j];
                }
            }
            else{
                for(int j = 0; j<BLOCKSIZE; j++){//xor with initilization
                    buffer2[j] =buffer1[j] ^ buffer3[j];
                }
            }

            //call ecb
            unsigned char* bf2 = reinterpret_cast<unsigned char*>(buffer2);
            unsigned char* bf3 = reinterpret_cast<unsigned char*>(buffer3);
        
            BF_ecb_encrypt(bf2, bf3, &key,1);
            
            for(int j = 0; j<BLOCKSIZE; j++){//put first part in buffer
                buffer[j+(i*BLOCKSIZE)] = bf3[j];
            }
        }
        
    }
    
    *resultlen = strlen((char*)buffer);
    
    //delete[] buffer;
    return (void*) buffer;
}

// decrypt ciphertext of length bufsize. Use keystr as the key.
void *fs_decrypt(void *ciphertext, int bufsize, char *keystr, int *resultlen){
    BF_KEY key;//key
    BF_set_key(&key, strlen(keystr), (const unsigned char *) keystr);//create key
    char IV[BLOCKSIZE] = {0,0,0,0,0,0,0,0};//initilazation vector

    char* ct = static_cast<char*> (ciphertext);
    int diff, blocks;
    unsigned char* buffer;
    diff = bufsize / BLOCKSIZE;//how many blocks-1
    blocks = diff*BLOCKSIZE;//how many blocks plain text need
    buffer = new unsigned char[blocks];//create buffer

    if(bufsize < BLOCKSIZE){
        diff = BLOCKSIZE - bufsize;
        char buffer1[BLOCKSIZE];//buffer of ciphertxt
        char buffer2[BLOCKSIZE];//buffer for dencrypt

        for (int i = 0; i < bufsize; i++){//buffsize includes end char
            buffer1[i] = ct[i];//put ciphertext to buffer
        }
        //call ecb and put result in buffer        
        unsigned char* bf1 = reinterpret_cast<unsigned char*>(buffer1);
        
        BF_ecb_encrypt(bf1, bf1, &key,0);

        //xor 
        for(int i = 0; i<BLOCKSIZE; i++){
            buffer2[i] =bf1[i] ^ IV[i];
        }
        
        for(int i = 0; i<BLOCKSIZE; i++){
            buffer[i] = buffer2[i];
        }    

    }
    else{
        int pads = BLOCKSIZE - (bufsize % BLOCKSIZE);
        int lB = bufsize / BLOCKSIZE;
        int lastBlock  = lB * BLOCKSIZE;

        char buffer1[BLOCKSIZE];//ciphertxt buffer
        char buffer2[BLOCKSIZE];//cipher -1 txt buffer
        char buffer3[BLOCKSIZE];//dencrpt buffer

        //put plain text in buffer1 cipher in buffer2
        //put buffer2 in big buffer

        for(int i = diff-1; i>= 0; i--){
            //ciphertxt
            for(int j = 0; j < BLOCKSIZE; j++){//put ciphertext in buffer
                buffer1[j] = ct[j+(i*BLOCKSIZE)];
            }
            if(i == 0){
                //ciphertxt
                for(int j = 0; j < BLOCKSIZE; j++){//put ciphertext in buffer
                    buffer2[j] = IV[j];
                }
            }
            else{
                //ciphertxt
                for(int j = 0; j < BLOCKSIZE; j++){//put ciphertext in buffer
                    buffer2[j] = ct[j+((i-1)*BLOCKSIZE)];
                }
            }
            //call ecb
            unsigned char* bf1 = reinterpret_cast<unsigned char*>(buffer1);
            unsigned char* bf2 = reinterpret_cast<unsigned char*>(buffer1);;

            BF_ecb_encrypt(bf1, bf1, &key, 0);
            
            //xor
            for(int j = 0; j<BLOCKSIZE; j++){//xor with initilization
                buffer3[j] = bf1[j] ^ buffer2[j];
            }
            for(int j = 0; j<BLOCKSIZE; j++){//put first part in buffer
                buffer[j+(i*BLOCKSIZE)] = buffer3[j];
            }
        }
    }
    
    *resultlen = strlen((char*)buffer)+1;
    
    //delete[] buffer;
    return (void*) buffer;
}