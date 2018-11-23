#include<iostream>
#include<string>
#include<cstring> 
using namespace std;
class Mystring {
private:
	size_t size;
	char *all;
public:
	Mystring();
	~Mystring();
	Mystring(const Mystring &copy);//copy constructor
	Mystring(const char*copy); //conversion from C-string
	void operator = (const Mystring &copy);//assignment
	const char *c_str() const { return all; }; //get C-string equvalent
	size_t length() const { return size; };
	//search the first occurence of str after pos in Mystring and returns the first occurence, returns length of Mystring otherwise.
	size_t find_first_of(const Mystring *str, size_t pos = 0) const;
	//returns a newly constructed Mystring object with its value initialied to a copy of a substring of this object from start to end.
	Mystring substr(size_t start, size_t end);
};
Mystring::Mystring() {
	size = 0;
}
Mystring::~Mystring() {
	size = 0;
	delete[] all;
}
Mystring::Mystring(const Mystring &copy) {
	size = copy.length();
	all = new char[size + 1];
	const char *now = copy.c_str();
	for (int t = 0; t <= size; t++) {
		all[t] = now[t];
	}
}
Mystring::Mystring(const char*in) {
	int t = 0;
	size = 0;
	size = strlen(in);
	all = new char[size + 1];
	for (int u = 0; u <= size; u++) {
		all[u] = in[u];
	}
}
void Mystring::operator = (const Mystring &copy) {
	size = copy.length();
	delete[] all;
	const char *now = copy.c_str();
	all = new char[size + 1];
	for (int t = 0; t<=size; t++) {
		all[t] = now[t];
	}
}
size_t Mystring::find_first_of(const Mystring *str, size_t pos) const {
	const char *find = (*str).c_str();
	size_t fnow = strlen(find);
	for (int t = pos; t<=size - fnow; t++) {
		int u = 0;
		bool key = 0;
		while (u<fnow&&all[u+t] == find[u]) {
			if(u==fnow-1){
				key=1;
			}
			u++;
		}
		if (key){
			return t;
		}
	}
	return size;
}
Mystring Mystring::substr(size_t start, size_t end) {
	char *temp;
	int len = end - start+1;
	temp = new char[len+1];
	for (int t = 0; t<=len; t++) {
		if (t != len) temp[t] = all[t + start];
		else temp[t] = all[size];
	}
	Mystring out(temp);
	delete[] temp;
	return out;
}
void print(Mystring in){
	const char *a=in.c_str();
	for(int t=0;t<in.length();t++){
		cout<<a[t];
	}
	cout<<endl;
}
int main(){
	string in;
	cin>>in;
	Mystring a(in.c_str());
	print(a);
	cout<<in<<endl;
	cout<<a.length()<<endl;
	cout<<in.length()<<endl;
	Mystring find("12");
	string f1="12";
	cout<<a.find_first_of(&find)<<endl;
	cout<<in.find_first_of(f1)<<endl;
	Mystring b=a;
	string out=in;
	print(b);
	cout<<out<<endl;
	cout<<b.length()<<endl;
	cout<<out.length()<<endl;
	cout<<b.find_first_of(&find)<<endl;
	cout<<out.find_first_of("12")<<endl;
	print(b.substr(1,3));
	cout<<out.substr(1,3)<<endl;
	return 0;
}
