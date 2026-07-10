// 2062. Count Vowel Substrings of a String
// A substring is a contiguous (non-empty) sequence of characters within a string.

// A vowel substring is a substring that only consists of vowels ('a', 'e', 'i', 'o', and 'u') and has all five vowels present in it.

// Given a string word, return the number of vowel substrings in word.

 

// Example 1:

// Input: word = "aeiouu"
// Output: 2
// Explanation: The vowel substrings of word are as follows (underlined):
// - "aeiouu"
// - "aeiouu"
// Example 2:

// Input: word = "unicornarihan"
// Output: 0
// Explanation: Not all 5 vowels are present, so there are no vowel substrings.
// Example 3:

// Input: word = "cuaieuouac"
// Output: 7
// Explanation: The vowel substrings of word are as follows (underlined):
// - "cuaieuouac"
// - "cuaieuouac"
// - "cuaieuouac"
// - "cuaieuouac"
// - "cuaieuouac"
// - "cuaieuouac"
// - "cuaieuouac"
 

// Constraints:

// 1 <= word.length <= 100
// word consists of lowercase English letters only.
//Solution:-
#include<bits/stdc++.h>
using namespace std;
int main(){
    string word;
    cout<<"Enter the string: ";
    cin>>word;
    int n=word.length();
    set<char>vowels={'a','e','i','o','u'};
    int count =0;
    for(int i=0;i<n;i++){
        set<char>s;
        for(int j=i;j<n;j++){
            if(vowels.find(word[j])!=vowels.end()){
                s.insert(word[j]);
                if(s.size()==5){
                    count ++;
                }

            }
            else{
                break;
            }
        }

    }
    cout<<count<<endl;
}