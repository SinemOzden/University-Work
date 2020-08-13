#include <iostream>
#include <stdint.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib> 

using namespace std;

uint8_t MULx(uint8_t V, uint8_t c);
uint8_t MULy(uint8_t V, int i, uint8_t c);
unsigned int MULa(uint8_t c);
unsigned int DIV(uint8_t c);
unsigned int SBox1(unsigned int w);
unsigned int SBox2(unsigned int w);
uint8_t callSR(uint8_t a);
uint8_t callSQ(uint8_t a);
void IntializationMode(unsigned int F);
void KeystreamMode();
unsigned int FSM();
int openFile(string fileName);
bool theCommand(vector<string> stringVector);

unsigned int s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15;
unsigned int R1, R2, R3;
unsigned int k0, k1, k2, k3, var0, var1, var2, var3;
int n;

uint8_t SR [16][16]= {  {0X63, 0X7C ,0X77, 0X7B ,0XF2 ,0X6B ,0X6F ,0XC5 ,0X30 ,0X01 ,0X67 ,0X2B ,0XFE ,0XD7 ,0XAB ,0X76},
                    {0XCA ,0X82 ,0XC9 ,0X7D ,0XFA ,0X59 ,0X47 ,0XF0 ,0XAD ,0XD4 ,0XA2 ,0XAF ,0X9C ,0XA4 ,0X72 ,0XC0},
                    {0XB7 ,0XFD ,0X93 ,0X26 ,0X36 ,0X3F ,0XF7 ,0XCC ,0X34 ,0XA5 ,0XE5 ,0XF1 ,0X71 ,0XD8 ,0X31 ,0X15},
                    {0x04 ,0xC7 ,0x23 ,0xC3 ,0x18 ,0x96 ,0x05 ,0x9A ,0x07 ,0x12 ,0x80 ,0xE2 ,0xEB ,0x27 ,0xB2 ,0x75},
                    {0x09 ,0x83 ,0x2C ,0x1A ,0x1B ,0x6E ,0x5A ,0xA0 ,0x52 ,0x3B ,0xD6 ,0xB3 ,0x29 ,0xE3 ,0x2F ,0x84},
                    {0x53 ,0xD1 ,0x00 ,0xED ,0x20 ,0xFC ,0xB1 ,0x5B ,0x6A ,0xCB ,0xBE ,0x39 ,0x4A ,0x4C ,0x58 ,0xCF},
                    {0xD0 ,0xEF ,0xAA ,0xFB ,0x43 ,0x4D ,0x33 ,0x85 ,0x45 ,0xF9 ,0x02 ,0x7F ,0x50 ,0x3C ,0x9F ,0xA8},
                    {0x51 ,0xA3 ,0x40 ,0x8F ,0x92 ,0x9D ,0x38 ,0xF5 ,0xBC ,0xB6 ,0xDA ,0x21 ,0x10 ,0xFF ,0xF3 ,0xD2},
                    {0xCD ,0x0C ,0x13 ,0xEC ,0x5F ,0x97 ,0x44 ,0x17 ,0xC4 ,0xA7 ,0x7E ,0x3D ,0x64 ,0x5D ,0x19 ,0x73},
                    {0x60 ,0x81 ,0x4F ,0xDC ,0x22 ,0x2A ,0x90 ,0x88 ,0x46 ,0xEE ,0xB8 ,0x14 ,0xDE ,0x5E ,0x0B ,0xDB},
                    {0xE0 ,0x32 ,0x3A ,0x0A ,0x49 ,0x06 ,0x24 ,0x5C ,0xC2 ,0xD3 ,0xAC ,0x62 ,0x91 ,0x95 ,0xE4 ,0x79},
                    {0xE7 ,0xC8 ,0x37 ,0x6D ,0x8D ,0xD5 ,0x4E ,0xA9 ,0x6C ,0x56 ,0xF4 ,0xEA ,0x65 ,0x7A ,0xAE ,0x08},
                    {0xBA ,0x78 ,0x25 ,0x2E ,0x1C ,0xA6 ,0xB4 ,0xC6 ,0xE8 ,0xDD ,0x74 ,0x1F ,0x4B ,0xBD ,0x8B ,0x8A},
                    {0x70 ,0x3E ,0xB5 ,0x66 ,0x48 ,0x03 ,0xF6 ,0x0E ,0x61 ,0x35 ,0x57 ,0xB9 ,0x86 ,0xC1 ,0x1D ,0x9E},
                    {0xE1 ,0xF8 ,0x98 ,0x11 ,0x69 ,0xD9 ,0x8E ,0x94 ,0x9B ,0x1E ,0x87 ,0xE9 ,0xCE ,0x55 ,0x28 ,0xDF},
                    {0x8C ,0xA1 ,0x89 ,0x0D ,0xBF ,0xE6 ,0x42 ,0x68 ,0x41 ,0x99 ,0x2D ,0x0F ,0xB0 ,0x54 ,0xBB ,0x16} };

uint8_t SQ [16][16]= {  {0X25, 0X24, 0X73, 0X67, 0XD7, 0XAE, 0X5C, 0X30, 0XA4, 0XEE, 0X6E, 0XCB, 0X7D, 0XB5, 0X82, 0XDB},
                    {0XE4, 0X8E, 0X48, 0X49, 0X4F, 0X5D, 0X6A, 0X78, 0X70, 0X88, 0XE8, 0X5F, 0X5E, 0X84, 0X65, 0XE2},
                    {0XD8, 0XE9, 0XCC, 0XED, 0X40, 0X2F, 0X11, 0X28, 0X57, 0XD2, 0XAC, 0XE3, 0X4A, 0X15, 0X1B, 0XB9},
                    {0XB2, 0X80, 0X85, 0XA6, 0X2E, 0X02, 0X47, 0X29, 0X07, 0X4B, 0X0E, 0XC1, 0X51, 0XAA, 0X89, 0XD4},
                    {0XCA, 0X01, 0X46, 0XB3, 0XEF, 0XDD, 0X44, 0X7B, 0XC2, 0X7F, 0XBE, 0XC3, 0X9F, 0X20, 0X4C, 0X64},
                    {0X83, 0XA2, 0X68, 0X42, 0X13, 0XB4, 0X41, 0XCD, 0XBA, 0XC6, 0XBB, 0X6D, 0X4D, 0X71, 0X21, 0XF4},
                    {0X8D, 0XB0, 0XE5, 0X93, 0XFE, 0X8F, 0XE6, 0XCF, 0X43, 0X45, 0X31, 0X22, 0X37, 0X36, 0X96, 0XFA},
                    {0XBC, 0X0F, 0X08, 0X52, 0X1D, 0X55, 0X1A, 0XC5, 0X4E, 0X23, 0X69, 0X7A, 0X92, 0XFF, 0X5B, 0X5A},
                    {0xEB ,0x9A ,0x1C ,0xA9 ,0xD1 ,0x7E ,0x0D ,0xFC ,0x50 ,0x8A ,0xB6 ,0x62 ,0xF5 ,0x0A ,0xF8 ,0xDC},
                    {0x03 ,0x3C ,0x0C ,0x39 ,0xF1 ,0xB8 ,0xF3 ,0x3D ,0xF2 ,0xD5 ,0x97 ,0x66 ,0x81 ,0x32 ,0xA0 ,0x00},
                    {0x06 ,0xCE ,0xF6 ,0xEA ,0xB7 ,0x17 ,0xF7 ,0x8C ,0x79 ,0xD6 ,0xA7 ,0xBF ,0x8B ,0x3F ,0x1F ,0x53},
                    {0x63 ,0x75 ,0x35 ,0x2C ,0x60 ,0xFD ,0x27 ,0xD3 ,0x94 ,0xA5 ,0x7C ,0xA1 ,0x05 ,0x58 ,0x2D ,0xBD},
                    {0xD9 ,0xC7 ,0xAF ,0x6B ,0x54 ,0x0B ,0xE0 ,0x38 ,0x04 ,0xC8 ,0x9D ,0xE7 ,0x14 ,0xB1 ,0x87 ,0x9C},
                    {0xDF ,0x6F ,0xF9 ,0xDA ,0x2A ,0xC4 ,0x59 ,0x16 ,0x74 ,0x91 ,0xAB ,0x26 ,0x61 ,0x76 ,0x34 ,0x2B},
                    {0xAD ,0x99 ,0xFB ,0x72 ,0xEC ,0x33 ,0x12 ,0xDE ,0x98 ,0x3B ,0xC0 ,0x9B ,0x3E ,0x18 ,0x10 ,0x3A},
                    {0x56 ,0xE1 ,0x77 ,0xC9 ,0x1E ,0x9E ,0x95 ,0xA3 ,0x90 ,0x19 ,0xA8 ,0x6C ,0x09 ,0xD0 ,0xF0 ,0x86} };

int main(int argc, char **argv){
    if(argc < 3){
		printf("Please invoke as %s inputFile outputFile \n",argv[0]);
		return 1;
	}		

    string inputFile = argv[1];
    string outputFile = argv[2];

    openFile(inputFile);

    s0  = k0 ^ 0XFFFFFFFF;
    s1  = k1 ^ 0XFFFFFFFF;
    s2  = k2 ^ 0XFFFFFFFF;
    s3  = k3 ^ 0XFFFFFFFF;

    s4  = k0;
    s5  = k1;
    s6  = k2;
    s7  = k3;

    s8  = k0 ^ 0XFFFFFFFF;
    s9  = k1 ^ 0XFFFFFFFF ^ var3;
    s10 = k2 ^ 0XFFFFFFFF ^ var2;
    s11 = k3 ^ 0XFFFFFFFF;

    s12 = k0 ^ var1;
    s13 = k1;
    s14 = k2;
    s15 = k3 ^ var0;
    
    R1 = 0; R2 = 0; R3 = 0;
    
    unsigned int F;
    unsigned int zt;
        
    for(int i=0; i<32; i++){
        F = FSM();
        IntializationMode(F);
    }

    FSM();
    KeystreamMode();
    ofstream output(argv[2]);

    for(int i=0; i<n; i++){
        F = FSM();
        zt = F ^ s0;
        output<<hex<<zt<<endl;
        KeystreamMode();
    }
    

}

uint8_t MULx(uint8_t V, uint8_t c){
    uint8_t k = (V >> 7) & 0xF; 
        if (k & 1){
            V = V<<1;
            V = V ^ c;
        }
        else{
            V = V<<1;
        } 
    return V;
}

uint8_t MULy(uint8_t V, int i, uint8_t c){
    uint8_t a;
    if(i==0){
        return V;
    }
    a = MULx(MULy(V,i-1,c),c);
    return a;
}

unsigned int MULa(uint8_t c){
    uint8_t one = MULy(c,23,0xA9); 
    uint8_t two = MULy(c, 245, 0xA9);
    uint8_t three = MULy(c, 48, 0xA9);
    uint8_t four = MULy(c, 239, 0xA9);

    unsigned int mula = 0;
    mula = mula | (one << 24);
    mula = mula | (two <<16); 
    mula = mula | (three << 8);
    mula = mula | (four);
    return mula;
}

unsigned int DIV(uint8_t c){
    uint8_t one = MULy(c, 16, 0xA9);
    uint8_t two = MULy(c, 39, 0xA9);
    uint8_t three = MULy(c, 6, 0xA9);
    uint8_t four = MULy(c, 64, 0xA9);

    unsigned int div = 0;
    div = div | (one << 24);
    div = div | (two <<16); 
    div = div | (three << 8);
    div = div | (four);

    return div;
}

unsigned int SBox1(unsigned int w){
    uint8_t w0 = (w >> 24) & 0xFF;
    uint8_t sw0 = callSR(w0);

    uint8_t w1 = (w >> 16) & 0xFF;
    uint8_t sw1 = callSR(w1);

    uint8_t w2 = (w >> 8) & 0xFF;
    uint8_t sw2 = callSR(w2);

    uint8_t w3 =  w & 0xFF;
    uint8_t sw3 = callSR(w3);

    uint8_t r0 = MULx(sw0,0x1B) ^ sw1 ^ sw2 ^ (MULx(sw3,0x1B) ^ sw3);
    uint8_t r1 = (MULx(sw0,0x1B) ^ sw0) ^ MULx(sw1, 0x1B) ^ sw2 ^ sw3;
    uint8_t r2 = sw0 ^ (MULx(sw1, 0x1B) ^ sw1) ^ MULx(sw2, 0x1B) ^ sw3;
    uint8_t r3 = sw0 ^ sw1 ^ (MULx(sw2, 0X1B) ^ sw2) ^ MULx(sw3,0x1B);

    unsigned int r = 0;
    r = r | (r0 << 24);
    r = r | (r1 <<16); 
    r = r | (r2 << 8);
    r = r | (r3);
    return r;
}

unsigned int SBox2(unsigned int w){
    uint8_t w0 = (w >> 24) & 0xFF;
    uint8_t sw0 = callSQ(w0);

    uint8_t w1 = (w >> 16) & 0xFF;
    uint8_t sw1 = callSQ(w1);

    uint8_t w2 = (w >> 8) & 0xFF;
    uint8_t sw2 = callSQ(w2);

    uint8_t w3 =  w & 0xFF;
    uint8_t sw3 = callSQ(w3);

    uint8_t r0 = MULx(sw0,0x69) ^ sw1 ^ sw2 ^ (MULx(sw3,0x69) ^ sw3);
    uint8_t r1 = (MULx(sw0,0x69) ^ sw0) ^ MULx(sw1, 0x69) ^  sw2 ^ sw3;
    uint8_t r2 = sw0 ^ (MULx(sw1, 0x69) ^ sw1) ^ MULx(sw2, 0x69) ^ sw3;
    uint8_t r3 = sw0 ^ sw1 ^ (MULx(sw2, 0X69) ^ sw2) ^ MULx(sw3,0x69);

    unsigned int r = 0;
    r = r | (r0 << 24);
    r = r | (r1 << 16); 
    r = r | (r2 << 8);
    r = r | (r3);

    return r;
}

uint8_t callSR(uint8_t a){
    uint8_t x = (a >> 4) & 0xF;
    uint8_t y = a & 0xF;
    return SR[x][y];
}

uint8_t callSQ(uint8_t a){
    uint8_t x = (a >> 4) & 0xF;
    uint8_t y = a & 0xF;
    return SQ[x][y];
}

void IntializationMode(unsigned int F){
    uint8_t s00 = (s0 >> 24) & 0xFF;
    uint8_t s01 = (s0 >> 16) & 0xFF;
    uint8_t s02 = (s0 >> 8) & 0xFF;
    uint8_t s03 =  s0 & 0xFF;

    uint8_t s110 = (s11 >> 24) & 0xFF;
    uint8_t s111 = (s11 >> 16) & 0xFF;
    uint8_t s112 = (s11 >> 8) & 0xFF;
    uint8_t s113 =  s11 & 0xFF;

    unsigned int temp0 = 0;
    temp0 = temp0 | (s01 << 24);
    temp0 = temp0 | (s02 <<16); 
    temp0 = temp0 | (s03 << 8);

    unsigned int temp11 = 0;
    temp11 = temp11 | (s110 <<16); 
    temp11 = temp11 | (s111 << 8);
    temp11 = temp11 | (s112);

    unsigned int v = temp0 ^ MULa(s00) ^ s2 ^ temp11 ^ DIV(s113) ^ F;

    s0 = s1;
    s1 = s2;
    s2 = s3;
    s3 = s4;
    s4 = s5;
    s5 = s6;
    s6 = s7;
    s7 = s8;
    s8 = s9;
    s9 = s10;
    s10 = s11;
    s11 = s12;
    s12 = s13;
    s13 = s14;
    s14 = s15;
    s15 = v;
 }

void KeystreamMode(){
    uint8_t s00 = (s0 >> 24) & 0xFF;
    uint8_t s01 = (s0 >> 16) & 0xFF;
    uint8_t s02 = (s0 >> 8) & 0xFF;
    uint8_t s03 =  s0 & 0xFF;

    uint8_t s110 = (s11 >> 24) & 0xFF;
    uint8_t s111 = (s11 >> 16) & 0xFF;
    uint8_t s112 = (s11 >> 8) & 0xFF;
    uint8_t s113 =  s11 & 0xFF;

    unsigned int temp0 = 0;
    temp0 = temp0 | (s01 << 24);
    temp0 = temp0 | (s02 <<16); 
    temp0 = temp0 | (s03 << 8);

    unsigned int temp11 = 0;
    temp11 = temp11 | (s110 <<16); 
    temp11 = temp11 | (s111 << 8);
    temp11 = temp11 | (s112);

    unsigned int v = temp0 ^ MULa(s00) ^ s2 ^ temp11 ^ DIV(s113);

    s0 = s1;
    s1 = s2;
    s2 = s3;
    s3 = s4;
    s4 = s5;
    s5 = s6;
    s6 = s7;
    s7 = s8;
    s8 = s9;
    s9 = s10;
    s10 = s11;
    s11 = s12;
    s12 = s13;
    s13 = s14;
    s14 = s15;
    s15 = v;
 }

unsigned int FSM(){
    unsigned int F = ((s15 + R1) & 0xFFFFFFFF) ^ R2;
    unsigned int r = ((R3 ^ s5) + R2) & 0xFFFFFFFF;
    R3 = SBox2(R2);
    R2 = SBox1(R1);
    R1 = r;
    return F;
}

int openFile(string fileName){
	ifstream inFS;
	string fileLine,line;
	vector<string> stringVector;
	string word;
	int i=0;
    inFS.open(fileName);
	if(inFS.is_open()){
		while(getline(inFS, fileLine)){
            istringstream inSS(fileLine);
            while(inSS>>word){
                stringVector.push_back(word);//writing file to string vector
                inSS.clear();
            }
        }
        theCommand(stringVector);//calling command function
	}
    inFS.close();//closing file
	return 0;
}

bool theCommand(vector<string> stringVector){
    sscanf(stringVector.at(1).c_str(), "%x", &k0); 
    sscanf(stringVector.at(2).c_str(), "%x", &k1);
    sscanf(stringVector.at(3).c_str(), "%x", &k2); 
    sscanf(stringVector.at(4).c_str(), "%x", &k3);  

    sscanf(stringVector.at(6).c_str(), "%x", &var0);  
    sscanf(stringVector.at(7).c_str(), "%x", &var1); 
    sscanf(stringVector.at(8).c_str(), "%x", &var2); 
    sscanf(stringVector.at(9).c_str(), "%x", &var3);

    n = stoi(stringVector.at(11));
}
