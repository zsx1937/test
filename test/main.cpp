#include <iostream>
#include <vector>
using namespace std;
string validIPAddress(string IP);
void copy(string &s,string::iterator b,string::iterator e);
bool judge4(string s);
bool judge6(string s);

string validIPAddress(string IP) {
    string s4[4]={""};
    string s8[8]={""};
    int i,n4=0,n8=0;
    auto b=begin(IP),e=end(IP),cb=b,ce=b,c=b;
    while (c!=e)
    {
        if (*c=='.') {
            if(n4<4) copy(s4[n4],cb,c);
            n4++;c++;cb=c;
        }
        else if (*c==':'){
            if (n8<8) copy(s8[n8],cb,c);
            n8++;c++;cb=c;
        }
        else c++;
    }
    if (n4==3) copy(s4[n4],cb,c);
    if (n8==7) copy(s8[n8],cb,c);
    bool flag4=true,flag8=true;
    for(i=0;i<4;++i){
        cout<<s4[i]<<" "<<judge4(s4[i])<<endl;
        if (judge4(s4[i])) continue;
        else flag4=false;
    }
    for(i=0;i<8;++i){
        cout<<s8[i]<<" "<<judge6(s8[i])<<endl;
        if (judge6(s8[i])) continue;
        else flag8=false;
    }
    cout<<n4<<n8<<endl;
    cout<<"flag4= "<<flag4<<endl;
    cout<<"flag8= "<<flag8<<endl;
    if (n4==3 &&n8==0&& flag4)return "IPv4";
    if (n4==0 &&n8==7&& flag8)return "IPv6";
    return "Neither";
}
void copy(string &s,string::iterator b,string::iterator e){
    for(;b!=e;++b) s+=*b;
}
bool judge4(string s){
    auto b=begin(s),e=end(s);
    if (*b=='0' && s.length()>1) return false;
    if (s.length()==0 or s.length()>3) return false;
    for(;b!=e;++b){
        if (*b>='0'&&*b<='9') continue;
        else return false;
    }
    int n=0;
    for(b=begin(s);b!=e;++b) n=n*10+*b-'0';
    if (n<256) return true;
    else return false;
}
bool judge6(string s){
    auto b=begin(s),e=end(s);
    auto l=s.length();
    if (l>4 or l==0) return false;
    if (*b=='0' && l<4&&l>1) return false;
    for(;b!=e;++b){
        char c=*b;
        if ((c<='9'&&c>='0')||(c<='f'&&c>='a')||(c<='F'&&c>='A')) continue;
        else return false;
    }
    return true;
}


int main()
{
    string s="1.1.1.1";
    cout<<validIPAddress(s)<<endl;
    cout<<judge6("85a3")<<endl;
    
    return 0;
}