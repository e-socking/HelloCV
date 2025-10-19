#include<iostream>
#include<string>
using namespace std;
int main(){
    int asc,a,c;
    char word;//、逐个读取
    string sentence,b;
    cout<<"请输入密钥：";
    cin>>a;
    cout<<"请输入要加密的文本：";
    cin>>b;
    for(int i=0;i<b.size();i++){if(65<=(c=b[i])<=90||97<=(c=b[i])<=122){
     asc=word+a;
     word=asc;
     sentence+=word;
    }
    else{sentence+=word;}
}
cout<<"加密结果"<<sentence;
return 0;

    

}