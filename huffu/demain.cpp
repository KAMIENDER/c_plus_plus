#include"huffmannode.h"
int main(){
	huff test;
	test.openddecodefile("out.huf");
	test.opendputdecoded("decode.txt");
	test.rebuildtree();
	return 0;
}
