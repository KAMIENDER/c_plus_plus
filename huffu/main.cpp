#include"huffmannode.h"
int main(){
	huff test;
	test.openinfile("test.txt");
	test.openoutfile("out.huf");
	test.Encode();
	return 0;
}
