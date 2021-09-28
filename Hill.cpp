#include <iostream>
#include <vector>
using namespace std;

int main(){
    int i,j,k,m;
    cout << "Masukkan Jumlah Pembagi\n";
    cin >> m;
    cout << "Matriks Kunci\n";
    int key[m][m];
    for(i=0; i < m; i++){
        for(j=0; j < m; j++){
            cin >> key[i][j];
        }
    }
    cout<<"Enter the message to encrypt\n";
    string s;
    cin>>s;
    int temp = (m-s.size()%m)%m;
    for(i=0;i<temp;i++){
        s+='x';
    }
    k=0;
    string ans="";
    while(k<s.size()){
        for(i=0;i<m;i++){
            int sum = 0;
            int temp = k;
            for(j=0;j<m;j++){
                sum += (key[i][j]%26*(s[temp++]-'a')%26)%26;
                sum = sum%26;
            }
            ans += (sum+'a');
        }
        k+=m;
    }
    cout << ans << '\n';

    return 0;    
}