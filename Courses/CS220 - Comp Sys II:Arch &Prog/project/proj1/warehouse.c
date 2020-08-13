#include "order.h"
#include "bench.h"
#include <stdio.h>

int main(int argc, char **argv) {
	if (argc<2) {
		printf("Please invoke as %s <order_file>\n",argv[0]);
		return 1;
	}
	if (!openOrder(argv[1])) {
		return 1;
	}
	int emptySlot=0;
	int binArray[100]={0};
	do {
		int pn=nextPartNumber();
		int bin=pn/10;
		int bin8=-1, bin7=-1 ,bin6=-1 ,bin5=-1 ,bin4=-1,bin3=-1 ,bin2=-1 ,bin1=-1; 
		int binSlot8=-1, binSlot7=-1, binSlot6=-1, binSlot5=-1, binSlot4=-1, binSlot3=-1, binSlot2=-1, binSlot1=-1;
		int a = 0;
		binArray[bin]++;
		for(int i=0; i<5;i++){//to check if bin exists in any of the 5 slots
			if (binInSlot(i)==bin) { a=1; }
			if (binArray[binInSlot(i)] >= 8){ 
				binSlot8 = i;
				bin8 = binInSlot(i);
			}
			else if (binArray[binInSlot(i)] == 7){ 
				binSlot7 = i;
				bin7 = binInSlot(i);
			}
			else if (binArray[binInSlot(i)] == 6){ 
				binSlot6 = i;
				bin6 = binInSlot(i);
			}
			else if (binArray[binInSlot(i)] == 5){ 
				binSlot5 = i;
				bin5 = binInSlot(i);
			}
			else if (binArray[binInSlot(i)] == 4){ 
				binSlot4 = i;
				bin4 = binInSlot(i);
			}
			else if (binArray[binInSlot(i)] == 3){ 
				binSlot3 = i;
				bin3 = binInSlot(i);
			}
			else if (binArray[binInSlot(i)] == 2){ 
				binSlot2 = i;
				bin2 = binInSlot(i);
			}
			else if (binArray[binInSlot(i)] == 1){ 
				binSlot1 = i;
				bin1 = binInSlot(i);
			}
		}
		if(a==0){
			while(emptySlot!=5 && binInSlot(emptySlot)!=-1){//to find empty slot to reduce the returned bin cost
				emptySlot++;
			}
			if(emptySlot>=5){
				if(binSlot1!=-1){
					fetchBin(bin,binSlot1);
					binArray[bin1] = 0;
				}
				else if(binSlot2!=-1){
					fetchBin(bin,binSlot2);
					binArray[bin2] = 0;
				}
				else if(binSlot3!=-1){
					fetchBin(bin,binSlot3);
					binArray[bin3] = 0;
				}
				else if(binSlot4!=-1){
					fetchBin(bin,binSlot4);
					binArray[bin4] = 0;
				}
				else if(binSlot5!=-1){
					fetchBin(bin,binSlot5);
					binArray[bin5] = 0;
				}
				else if(binSlot6!=-1){
					fetchBin(bin,binSlot6);
					binArray[bin6] = 0;
				}
				else if(binSlot7!=-1){
					fetchBin(bin,binSlot7);
					binArray[bin7] = 0;
				}
				else if(binSlot8!=-1){
					fetchBin(bin,binSlot8);
					binArray[bin8] = 0;
				}
			}
			else{
				fetchBin(bin,emptySlot);//if not then fetch the bin
			}
		}
	} while(fetchNextPart());
	closeOrder();
	return 0;
}
