#include <iostream>
#include<cassert>
using namespace std;
#include <iostream>
#include<string>
#include<cstring>
using namespace std;
class stateData{
private:
    string name;
    string capitalarea;
    int yearofadmission;
    int orderofadmission;
public:
    stateData();
    stateData(string a ,string b,int c,int d);
    ~stateData();
    void setname(string a);
    void setcapital(string a);
    void setyear(int c);
    void setorder(int c);
    string  getname();
    string  getcapital();
    int getyear();
    int getorder();
    bool operator ==( const stateData &s);

    bool operator !=(const stateData &s);

friend istream&  operator >>( istream &input,stateData& s){

input>>s.name;
input>>s.capitalarea ;
input>>s.orderofadmission;
input>>s.yearofadmission;
return input;

    }
    friend ostream& operator <<( ostream &output,stateData& s){
output<<"state's name:"<<s.name<<endl;
output<<" state's capitalarea:"<<s.capitalarea<<endl;
output<<"state's order of admission: "<<s.orderofadmission<<endl;
output<<"state's year of admission:"<<s.yearofadmission<<endl;
return output;
}
};
stateData::stateData(){
name="Nothing";
capitalarea=" ";
orderofadmission=0;
yearofadmission=0;
}
stateData::stateData(string a ,string b,int c,int d){
name=a;
capitalarea=b;
orderofadmission=c;
yearofadmission=d;
}
stateData::~stateData(){
    string *a=&name;
    string *b=&capitalarea;
delete a;
delete b;
}
void stateData::setname(string a){
name=a;
}
void stateData::setcapital(string a ){

capitalarea=a;
}
void stateData::setyear(int c){
yearofadmission=c;

}
void stateData::setorder(int c){
orderofadmission=c;
}
string  stateData::getcapital(){

return capitalarea;

}
string  stateData::getname(){

return name;
}
int stateData::getorder(){
return orderofadmission;}
int stateData::getyear(){

return yearofadmission;
}
bool stateData::operator ==( const stateData &s){
return(name==s.name);
}
bool stateData::operator!=(const stateData &s){
return(!(name==s.name));

}







int i;
template<class t>
class hasht{
private:
    int maxsize;
    int lenght;
    t* ht;
    int* a;//positions situations
public:
    int hashFunc(string name)
{
int i, sum;
int len;
i = 0;
sum = 0;
len = name.length();
for (int k = 0; k < 15 - len; k++)
name = name + ' '; //increase the length of the name
//to 15 characters
for (int k = 0; k < 5; k++)
{
sum = sum + static_cast<int>(name[i]) * 128 * 128
+ static_cast<int>(name[i + 1]) * 128
+ static_cast<int>(name[i + 2]);
i = i + 3;
}
return sum % maxsize;
}
    hasht();
    ~hasht();
    hasht(int b);
    void insertt(int hashindex, const t &q);
    void searchh(int hashindex, const t &q,  bool &found) const;
    bool isItemAtEqual(int hashindex, const t& q) const;
    void retrieve(int hashindex, t q) const;
    void removee(int hashindex, const t& q);
void print(){
for(int i=0;i<maxsize;i++){
        if(a[i]!=0){
    cout<<i<<" "<<ht[i]<<"   "<<a[i]<<endl;}

}

}
};
template<class t>
void hasht<t>::removee(int hashindex, const t& q){
    bool r;
this->searchh(hashindex,q,r);
if(r==1){
    a[hashindex]=-1;



}
else{
    cerr<<"the number is not in the table";

}

}
template<class t>
void hasht<t>::retrieve(int hashindex, t q) const{
if(a[hashindex]==1){
    q=ht[hashindex];

}
else{

    cerr<<"there is not any element in this position";
}

}
template<class t>
bool hasht<t>::isItemAtEqual(int hashindex, const t& q) const{

return (ht[hashindex]==q);
}
template<class t>
void hasht<t>::searchh(int hashindex, const t &q,  bool &found)const{

    int inc;
    inc=2;

    if(ht[hashindex]==q){
        found=1;

    }

else {
        int u;
u=0;
    int p;
        p=hashindex+inc;
    while (u<maxsize/2 && !found){

         if(ht[p]==q) {found=1;hashindex=p;}
        p=p+inc;
        inc=inc+2;

u++;
    }


}
}
template<class t>
hasht<t>::~hasht(){
delete []a;
delete []ht;

}
template<class t>
hasht<t>::hasht(){
maxsize=0;
lenght=0;
a=new int [maxsize];
ht=new t[maxsize];
for(int j=0;j<maxsize;j++){
    a[j]=0;
}

}
template<class t>
hasht<t>::hasht(int b){

maxsize=b;
lenght=0;
a=new int [maxsize];
ht=new t[maxsize];
for(int j=0;j<maxsize;j++){
    a[j]=0;
}


}
template<class t>
void hasht<t>::insertt(int hashindex,const t &q){
int pCount;
int inc;
pCount = 0;
inc = 1;
while (a[hashindex] == 1
&& ht[hashindex] != q && pCount < maxsize / 2)
{
pCount++;
hashindex = (hashindex + inc) % maxsize;
inc = inc + 2;
}
if (a[hashindex] != 1)
{
ht[hashindex] = q;
a[hashindex] = 1;
lenght++;
}
else if(ht[hashindex] == q)
cerr << "Error: No duplicates are allowed." << endl;
else
cerr << "Error: The table is full. "
<< "Unable to resolve the collision." << endl;
}
int main()
{hasht<string > HASH(100);
stateData s1("Alabama","Montogomery",1819,22);
stateData s2("Alaska","Juneau",1959,49);
stateData s3("Arizona","phoenix",1912,48);
stateData s4("Arkanas","little Rock",1836,25);
stateData s5("California","sacramento",1850,31);
stateData s6("Colorado","Denever",1876,38);
int a1=HASH.hashFunc(s1.getname());
int a2=HASH.hashFunc(s2.getname());
int a3=HASH.hashFunc(s3.getname());
int a4=HASH.hashFunc(s4.getname());
int a5=HASH.hashFunc(s5.getname());
int a6=HASH.hashFunc(s6.getname());
HASH.insertt(a1,s1.getname());
HASH.insertt(a2,s2.getname());
HASH.insertt(a3,s3.getname());
HASH.insertt(a4,s4.getname());
HASH.insertt(a5,s5.getname());
HASH.insertt(a6,s6.getname());



HASH.removee(a5,s5.getname());
HASH.print();



    return 0;
}
