#include<iostream>
#include<string>
#include<queue>
#include"Scan.h"
#include"print.h"

using namespace std;

int main()
{
    
  	Scan sc;
	print pr;
		string input;
		cin >> input;
		queue <string> result_queue = sc.ToStringQueue(input);
		pr.PrintStringQueue(result_queue);
	return 0;
}	
			
		
		
	

	
	
