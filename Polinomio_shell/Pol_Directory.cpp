/** Pol_Directory.cpp
*/
#include <iostream>
#include <fstream>		/*ifstream,ofstream*/
#include "Pol_Directory.h"
using namespace std;

Pol_Directory::Pol_Directory():size(0),capacity(1){
	the_directory=new Directory_entry[1];
}

Pol_Directory::~Pol_Directory(){
	delete[] the_directory;
}

*/
void Pol_Directory::load_data(const std::string& source_name){
	
	this->source_name=source_name;
	
	ifstream in(source_name.c_str());
	if(in){
		string name;
		string coeffs;
		while(getline(in,name)){
			if(getline(in,coeffs)){
			
				add(name,coeffs);
			}
		}
		in.close();
	}
}



std::string Pol_Directory::add_or_change_entry(const std::string& var_name,const std::string& coeffs)
{
	string old_coeffs="";
	int index=find(var_name);
	if(index!=-1){
		old_coeffs=the_directory[index].coeffs;
		the_directory[index].coeffs=coeffs;
	}else{
		add(var_name,coeffs);
	}
	modified=true;
	return old_coeffs;
}


void Pol_Directory::add(const std::string& var_name,const std::string& coeffs){
	if(size==capacity){
		reallocate();
	}
	
	the_directory[size]=Directory_entry(var_name,coeffs);
	size++;
}


void Pol_Directory::reallocate(){

	capacity*=2;
	
	Directory_entry *new_directory=new Directory_entry[capacity];
	
	for(int i=0;i<size;i++){
		new_directory[i]=the_directory[i];
	}
	
	delete[] the_directory;
	
	the_directory=new_directory;
}

std::string Pol_Directory::lookup_entry(const std::string& var_name) const {
	int index=find(var_name);
	if(index!=-1){
		return the_directory[index].coeffs;
	}else{
		return "";
	}
}

int Pol_Directory::find(const std::string& var_name) const {
	for(int i=0;i<size;i++){
		if(the_directory[i].var_name==var_name){
			return i;
		}
	}
	return -1;
}



void Pol_Directory::save(){
	if(modified){
		ofstream out(source_name.c_str());
		for(int i=0;i<size;i++){
			out<<the_directory[i].var_name<<endl;
			out<<the_directory[i].coeffs<<endl;
		}
	}
}
