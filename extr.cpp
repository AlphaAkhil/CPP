#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <fstream> //file handling header
#include <sstream>
using namespace std;



// chenge a strin num to int
int to_int(string num){
	int len = num.length();
	string numarr[10] = {"0","1","2","3","4","5","6","7","8","9"};
	int new_num =0;
	for(int i=0; i<len; i++){
		int val = 1 ;
		string str = num.substr(i,1);
		for(int j=0; j<11;j++){
			if( str == numarr[j]){
				val = j;
				break;
			}
		new_num += val*pow(10,len-i-1);
		}
	}
	return new_num; // string to ineger
}

//case1:

//show menu bar
void show_menu(){
	cout<<("================================================MENU============================================================\n");
	cout <<"1: show menu\n";
	cout <<"2: show all expenses \n";
	cout <<"3: add expenses \n";
	cout <<"4: find expenses \n";
	cout <<"5: exit the appliction \n";
}


//case 2
//list of items
void list_show(bool x){
	string line; // store every single line
	int i= 0; // count the list
	fstream exp_file; 
	exp_file.open("exp_file.txt",ios::in); // open file in reading mode
	
	//checking file open or not
	if(exp_file.is_open()){	
	    //while loop for get very line
		while(!exp_file.eof()){
            getline(exp_file, line); //get lines
            cout<<line<<"\n"; // out that lines;
		}
		exp_file.close();
	}else{
		cout <<"sorce file is not able or not opend try again \n";
	}
}



//case 3 part 2
//saving our data in file which we create
void save_file(int money,string exp_type,string date){
	// create a object
	fstream exp_file;
	exp_file.open("exp_file.txt", ios::app);
	
	if (!exp_file) {
		cout << "try again!\n";
	}else {
		cout << "date saved\n";
		exp_file <<date<<" | "<<money<<":"<<exp_type<<"\n";
		exp_file.close();
	}
}

// add new expendature in list
void add_exped(){ 
	int money;
	string  expred_type ,date;
	cout<<"money expendature:/> $";
	cin >> money;
	cout<<"\expendature type:/> ";
	cin >> expred_type;
	cout<<"Enter Date yyyy/mm/dd:/>";
	cin >> date;
	if(date.length() == 10){
		save_file(money, expred_type, date);
	}else{
		cout<<"enter valid data\n";
		add_exped();	
	};
	
}

//ask for date we need of search expendature
void show_data(string data){
	string year;
	cout << data.length()<<"\n";
}



// show list of all expences
void finding(string date,int len){
	fstream exp_file; 
	string line;
	exp_file.open("exp_file.txt",ios::in); // open file in reading mode
		 
	//checking file open or not
	if(exp_file.is_open()){	
		string money;
		int total_spend =0 ;
	    //while loop for get very line
		while(!exp_file.eof()){
			//get lines
            getline(exp_file, line);
            //checking date from database...
			if(date== line.substr(0,len)){
				
				money = line.substr(13,line.find(":")-13);
				cout<<money<<"::";
				total_spend += to_int(money);		
				cout<<total_spend<<"\n";	
				cout<<line<<"\n";	
			}
		}
		exp_file.close();
		cout<<"\n_______________________________________________________________________\n";
		cout<<"total spend is :"<<total_spend<<"\n";
	}else{
		cout <<"appliction not work or sorce file removed please restart and try again";
	}
	

}
void find_exped(){
	string date;
	cout<<"enter date yyyy/mm/dd :/>";
	cin >> date;
	int len = date.length();
	if(len == 10){
		finding(date,len);
	}else if(len==7){
		cout<<"date is null \n";
		finding(date,len);
		
	}else{
		cout<<"enter date in the form of yyyy/mm/dd or yyyy/mm\n";
	}
}



// change a number to string
string to_string(int x){
	string numarr[10] = {"0","1","2","3","4","5","6","7","8","9"};
	string new_str = "";
	while(x != 0){
		new_str = numarr[x%10] + new_str;
		x /= 10;
	}
	return new_str;
}





void list_show(){
	string line; // store every single line
	int i= 0; // count the list
	fstream exp_file; 
	exp_file.open("exp_file.txt",ios::in); // open file in reading mode
	
	//checking file open or not
	if(exp_file.is_open()){	
	    //while loop for get very line
		while(!exp_file.eof()){
            getline(exp_file, line); //get lines
            cout<<line<<"\n"; // out that lines;
		}
		exp_file.close();
	}else{
		cout <<"sorce file is not able or not opend try again \n";
	}
	
}


show_discription(){
	cout<<"=======================================================>ANDEN<====================================================\n";
	cout<< "this appliction is case sencative please inter value carefully...\n";
	cout<<"date are form of yyyy/mm/dd first four are year the slash then two are from month then slash and 2 day space and enter valid date;";
}


void choose_option(){
	bool run = true;
	while (run){
		int enter;
		cout<< "option$:/> ";
		cin >> enter;
		switch(enter){
			case 0:
				show_discription();
				break;
			case 1:
				show_menu();
				break;
			case 2:
				list_show();
				break;
			case 3:
				add_exped();
				break;
			case 4:
				find_exped();
				break;
			case 5:
				run = false;
				break;
			default:
				cout<<"Please Enter Right  Type of Input";
				show_menu();
				break;			
		}
		
	}
	
}	

int main(){
	show_discription();
	show_menu();
	choose_option();	
	return 0;
}
