#include<stdio.h>

int main(){
	char str[100];
	printf("DFA to accept strings ending with /'01/' over the characters {0,1}");
	printf("\n\n Enter the string :\n\n");
	scanf("%s",str);
	
	int flag =1;
	char prev =str[0],curr,f='a';
	if(str[0]=='1'){
		f='b';
	}
	else if(str[0]=='0')
		f='a';
	
	else{
		flag =0;
		printf("not accepted by DFA");
		return -1;
	}	
	
	for(int i=0;str[i]!='\0';i++){
		if(str[i]=='1' || str[i]=='0'){
		
			switch(f){
			case 'a' : if(str[i]=='1')
					break;
				else if(str[i]=='0')
				{ f='b';
					break;
				}else{
					flag =0;
					printf("not accepted by DFA");
					return -1;
				}	
 

			case 'b' : if(str[i]=='1'){
					f='c';
					break;
				}else if(str[i]=='0')
				{ f='b';
					break;
				}else{
					flag =0;
					printf("not accepted by DFA");
					return -1;
				}	
			case 'c' : if(str[i]=='1'){
					f='a';
					break;
				}else if(str[i]=='0')
				{ f='b';
					break;
				}else{
					flag =0;
					printf("not accepted by DFA");
					return -1;
				}	

			}
			
		}
		else{
			flag =0;
			break;
		}
		
	}
	
	
 

	for(int i=1;str[i]!='\0';i++){
		if(str[i]=='1' || str[i]=='0'){
			prev=curr;
			curr=str[i];
			
			if(prev=='0' && curr=='1')
				flag=1;	
			else
				flag=0;
		}
		else{
			flag =0;
			break;
		}
		
	}
	
	if(f=='c'){	
		printf("It is accepted by the DFA\n");
	}else{
		printf("It is not accepted by the DFA\n");
	}return 0;
	
}
 
