#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
	unordered_map<string, int> hashmap;
	
	//insert key-value pair in map
	hashmap.insert(make_pair("Rose", 10)); //one way to insert
	hashmap.insert(make_pair("Daisy", 12));
	
	hashmap["Jasmine"] = 7; //another way to insert
	
	hashmap["Daisy"] += 3; //update a value
	
	//extract value of a key
	cout<<"The value of Rose is: "<<hashmap["Rose"]<<"\n";
	
	//print all key-value pairs of hashmap
	unordered_map<string, int> :: iterator itr;
	cout<<"All Key-Value pairs are: \n";
	for(itr = hashmap.begin(); itr != hashmap.end(); itr++){
		cout<<itr->first<<" "<<itr->second<<"\n";
	}
	
	//alternatively:
	for(auto itr1:hashmap){
		cout<<itr1.first<<" "<<itr1.second<<"\n";
	}
	
	//search an element using 'count'
	//count just tells whether key is present or not
	if(hashmap.count("Lotus") == 0)
		cout<<"Lotus not found in map\n";
	else
		cout<<"The value of Lotus is: "<<hashmap["lotus"]<<"\n";
		
	//search for an element using 'find'
	//'find' returns iterator to element and we can access the key and value	
	unordered_map<string, int> :: iterator it;
	it = hashmap.find("Jasmine");
	
	if(it != hashmap.end())
		cout<<it->first<<" -> "<<it->second<<"\n";
	else
		cout<<"Jasmine is not found in map\n";
		
}
