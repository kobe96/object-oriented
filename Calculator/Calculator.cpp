#include<iostream>
#include<string>
#include<queue>
#include"Scan.h"
#include"Print.h"

using namespace std;
void Scan::ToStringQueue()
{	
	
	std::queue<std::string>ToStringQueue(const std::string&input);
	{
			
			 std::queue<string>result_queue;
			
			for(int i = 0;i < input.size();)
		{
			string item ="";
			
			if (isdigit(input[i]))
			{
				do
				{
					item.push_back(input[i++]);
				}while (i<input.size()&&isdigit(input[i]));
			}
			
			else
				{
					item.push_back(input[i++]);
				}
				result_queue.push(item);
		}
		
	return result_queue;
		} 
	
}
		int main()
		{
			
			string input;
			getline(cin,input) ;
			input.Scan::ToStringQueue();
			
		}
		
	

	
	
