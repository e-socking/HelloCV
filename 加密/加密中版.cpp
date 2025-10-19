#include<iostream>
#include<string>
#include<fstream>
#include<cstdio>
using namespace std;
class Crypto{//code
    public:
    string mi(int a,string b);
    string unmi(int a,string b);

};
class FileHandler{//files
    public:
    void fliema(string a);
    string fliere();
};
class Menu{
    public:
    void v(){cout<<"=======这只是一个普普通通的命令行菜单,如果密钥太大的话它就会哭和生成bug======="<<endl;}

};
void FileHandler::fliema(string a){
     

    ofstream file("encrypted.txt");
    file<<a;
    file.close();
}
string FileHandler::fliere(){string a;
    ifstream infile("encrypted.txt");
    if(!infile.is_open()){cout<<"文件不存在"<<endl;}
    getline(infile,a);//注意此处把文件内容给到a的写法
    char *b="encrypted.txt";
    remove(b);
    return a;
}
string Crypto::mi(int a,string b){string sentence;int asc;
for(int i=0;i<b.size();i++){
    asc = b[i];
if ((65 <= asc && asc <= 90) || (97 <= asc && asc <= 122)){
     asc+=a;
                 
     if((65 <= asc && asc <= 90) || (97 <= asc && asc <= 122)){
        sentence+=asc;
     }
     else{asc=asc-26;
    sentence+=asc;}
    }
    else{sentence+=asc;}
}
return sentence;
}
string Crypto::unmi(int a,string b){string sentence;int asc;
for(int i=0;i<b.size();i++){
    asc = b[i];
if ((65 <= asc && asc <= 90) || (97 <= asc && asc <= 122)){
     asc-=a;
                 
     if((65 <= asc && asc <= 90) || (97 <= asc && asc <= 122)){
        sentence+=asc;
     }
     else{asc=asc+26;
    sentence+=asc;}
    }
    else{sentence+=asc;}
}
return sentence;
}

int main(){int choice;
    class FileHandler q;
    Menu m;
    m.v();
    cout<<"加密输入0"<<endl<<"解密输入1"<<endl<<"加密文件输入2"<<endl;
    cin>>choice;
    Crypto crypto;
    if(choice==0){
    
    int a;string b,c;

    cout<<"请输入要加密的文本："<<endl;
    cin>>b;
    cout<<"请输入密钥：";
    
    cin>>a;
    if(a>52){cout<<"QAQ哒咩！"<<endl;}
c=crypto.mi(a,b);

cout<<"加密结果"<<c<<endl;
}
else if(choice==2){cout<<"请输入要加密的文件路径"<<endl;;
    string path,m,n;int s;
    cin>>path;
    ifstream file2(path);
    getline(file2,m);
    
    if(!file2.is_open()){cout<<"文件不存在"<<endl;}
    cout<<"请输入密钥：";
    cin>>s;
    n=crypto.mi(s,m);
    q.fliema(n);cout<<"加密文件已经保存到encrypted.txt";
}
else{int w,t;string e,r;
    
    cout<<"从加密文件中读取按1,手动输入按2"<<endl;
    cin>>w;
    cout<<"请输入密钥："<<endl;
    cin>>t;
    if(w==2){
    cout<<"请输入要解密的文本："<<endl;
    cin>>e;
    r=crypto.unmi(t,e);
    cout<<"解密结果"<<r<<endl;
    }
    else{
    e=q.fliere();
    r=crypto.unmi(t,e);
    cout<<"解密结果"<<r<<endl<<"已移除加密文件（π_π）";
    }
}
return 0;
}