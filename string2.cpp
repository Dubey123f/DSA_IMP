#include<iostream>
using namespace std;
char toUpper(char ch){
    if(ch>='A' && ch<='Z'){
        return ch;
    }
    else{
char temp=ch;
temp=ch-'a'+'A';
return temp;
    }
    }
char tolower(char ch){
    if(ch>='a'&& ch<='z'){
        return ch;
    }
    else{
        char temp=ch;
        temp=ch-'A'+'a';
        return temp;
    }

}
bool isPalindrome(char name[],int n){
    int s=0,e=n-1;
    while(s<e){
        if(tolower(name[s])!=tolower(name[e])){
            return false;
        }
        else{
         
            s++;
            e--;
        }
    }
    return true;
}
void reverse(char name[],int n){
    int s=0,e=n-1;
    while(s<e){
        swap(name[s++],name[e--]);
    }
}
int getLength(char name[]){
    int c=0;
    for(int i=0;name[i]!='\0';i++){
        c++;
    }
    return c;
}
int getMaxoccurCharacter(string s){
    int arr[26]={0};
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        int number=0;
        if(ch>='a' && ch<='z'){
            number=ch-'a';
        }
        else{
            number=ch-'A';
        }
        arr[number]++;
    }
    int max=-1,ans=0;
    for(int i=0;i<26;i++){
        if(max<arr[i]){
            ans=i;
            max=arr[i];
        }
    }
    char finalans='a'+ans;
    return finalans;

}

int main(){
    // char name[20];
    // cout<<"Enter your name: ";
    // cin>>name;
    // cout<<"Your Name is: "<<name<<endl;
    // int l=getLength(name);
    // cout<<"Length of your name is: "<<l<<endl;
    // reverse(name,l);
    // cout<<"Your name after reversing is: "<<name<<endl;
    // if(isPalindrome(name,l)){
    //     cout<<"Your name is a Palindrome"<<endl;
    // }
    // else{
    //     cout<<"Your name is not a Palindrome"<<endl;
    // }
    // char ch;
    // cout<<"Enter a character to convert it to lower case: ";
    // cin>>ch;
    // cout<<"Lower case of "<<ch<<" is: "<<tolower(ch)<<endl;
    // cout<<"Enter a character to convert it to upper case: ";
    // cin>>ch;
    // cout<<"Upper case of "<<ch<<" is: "<<toUpper(ch)<<endl;
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    char maxChar = getMaxoccurCharacter(s);
    cout<<"Maximum occurring character in the string is: "<<maxChar<<endl;
 
    return 0;
}