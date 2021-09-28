
#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>

#define SIZE 10

using namespace std;

int main(){
		
        float p[SIZE][SIZE], x[SIZE], ratio, c[SIZE][SIZE], key[SIZE][SIZE];
		int i,j,k,n;

        cout<< setprecision(3)<< fixed;

		cout << "Bentuk Matriks : ";
		cin >> n;

        cout<<"Matrix Cipher : " << endl;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				cout<<"c["<< i<<"]"<< j<<"]= ";
                cin>> c[i][j];
			}
		}

		cout<<"Matrix Plain : " << endl;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				cout<<"p["<< i<<"]"<< j<<"]= ";
                cin>> p[i][j];
			}
		}

		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){

				if(i==j)
				{
				    p[i][j+n] = 1;
				}
				else
				{
				    p[i][j+n] = 0;
				}
			}
		}

		for(i=1;i<=n;i++){
			if(p[i][i] == 0.0)
			{
				cout<<"Mathematical Error!";
				exit(0);
			}
			for(j=1;j<=n;j++){
				if(i!=j){

					ratio = p[j][i]/p[i][i];
					for(k=1;k<=2*n;k++){
					    p[j][k] = p[j][k] - ratio*p[i][k];
					}
				}
			}
		}

		for(i=1;i<=n;i++)
		{
			for(j=n+1;j<=2*n;j++)
			{
			   	p[i][j] = p[i][j]/p[i][i];
		    }
		}

        for(i=0; i < n; i++){    
            for(j=0; j < n; j++){    
                key[i][j]=0;    
                for(k=0; k < n; k++){    
                    key[i][j]+= (c[i][k]*p[k][j]);    
                }    
            }    
        } 

		cout<< endl<<"Key :"<< endl;
		for(i=1;i<=n;i++)
		{
			for(j=n+1;j<=2*n;j++)
			{
			    cout<< key[i][j]<<"\t";
			}
			cout<< endl;
		}
		return(0);
}

	