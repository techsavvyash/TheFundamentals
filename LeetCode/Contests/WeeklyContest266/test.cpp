#include <iostream>
using namespace std;

long long int countV(char subStr[]) {
    long long int count = 0;

    for(int i=0;subStr[i];i++) {
        if(subStr[i] == 'a' || subStr[i] == 'e' || subStr[i] == 'i' || subStr[i] == 'o' || subStr[i] == 'u'  ) count++ ;
    }

    return count ;
}

void subsequence(char in[],int i,char ou[],int j/*, long long int &count*/){

	// Base case
	if(in[i]=='\0'){
		ou[j]='\0';
		cout<<ou<<endl;
		//count += countV(ou);
	}

	// Recursive case
	// exclude karo
	subsequence(in,i+1,ou,j/*, count*/);



	// include karo
	ou[j]=in[i];
	subsequence(in,i+1,ou,j+1/*, count*/);

	//cout << count << endl;
}


int main(){
	char input[100],output[100];
	cin>>input;
	//long long int count = 0;
	subsequence(input,0,output,0);

	



}