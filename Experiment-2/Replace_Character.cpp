#include <bits/stdc++.h>
using namespace std;
 
long long factorial(int n) 
{
    long long res=1;
    for(int i=2; i<=n; i++)
    {
        res*=i;
    }
    return res;
}
 
long long countPermutations(string s) 
{
    int freq[26]={0};
    for(char c:s) 
    {
        freq[c-'a']++;
    }
    long long total=factorial(s.size());
    for(int i = 0; i < 26; i++)
    {
        if(freq[i]>1) 
        {
            total/=factorial(freq[i]);
        }
    }
    return total;
}
 
int main() 
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        string s;
        cin>>n>>s;
        string best=s;
        long long bestValue=countPermutations(s);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) 
            {
                string temp=s;
                temp[i]=s[j];
                long long value=countPermutations(temp);
                if (value<bestValue) {
                    bestValue=value;
                    best=temp;
                }
            }
        }
        cout<<best<<"\n";
    }
    return 0;
}
