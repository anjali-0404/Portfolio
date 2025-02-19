#include<iostream>
#include<string>

using namespace std;

int max_books=100;
int max_borrowers=50;

string titles[100];
string authors[100];
int ISBNs[100];
bool available[100];
string borrowerNames[50];
string borrowedBooks[50][100];

int numBooks=0;
int numBorrowers=0;

int findBookIndexByTitle(string title){
for(int i=0;i<numBooks;++i){
if(titles[i]==title){
return i;
}
}
return -1;
}

void addBook(string title,string author,int ISBN){
if(numBooks<max_books){
titles[numBooks]=title;
authors[numBooks]=author;
ISBNs[numBooks]=ISBN;
available[numBooks]=true;
numBooks++;
}else{
cout<<"Maximum number of books reached."<<endl;
}
}

void addBorrower(string name){
if(numBorrowers<max_borrowers){
borrowerNames[numBorrowers]=name;
numBorrowers++;
}else{
cout<<"Maximum number of borrowers reached."<<endl;
}
}

void checkoutBook(string bookTitle,int ISBN){
string borrowerName;
cout<<"Enter borrower name:";
cin.ignore();getline(cin,borrowerName);

int bookIndex=-1,borrowerIndex=-1;
for(int i=0;i<numBooks;++i){
if(titles[i]==bookTitle&&ISBNs[i]==ISBN){
bookIndex=i;
break;
}
}
for(int i=0;i<numBorrowers;++i){
if(borrowerNames[i]==borrowerName){
borrowerIndex=i;
break;
}
}
if(bookIndex!=-1&&borrowerIndex!=-1){
if(available[bookIndex]){
available[bookIndex]=false;
borrowedBooks[borrowerIndex][bookIndex]=to_string(ISBN);
cout<<"Book \""<<titles[bookIndex]<<"\" checked out to "<<borrowerNames[borrowerIndex]<<endl;
}else{
cout<<"Book is not available for checkout."<<endl;
}
}else{
cout<<"Book or borrower not found."<<endl;
}
}

void returnBook(int ISBN,string borrowerName){
int bookIndex=-1,borrowerIndex=-1;
for(int i=0;i<numBooks;++i){
if(ISBNs[i]==ISBN){
bookIndex=i;
break;
}
}
for(int i=0;i<numBorrowers;++i){
if(borrowerNames[i]==borrowerName){
borrowerIndex=i;
break;
}
}
if(bookIndex!=-1&&borrowerIndex!=-1){
if(!available[bookIndex]){
available[bookIndex]=true;
borrowedBooks[borrowerIndex][bookIndex]="";
cout<<"Book \""<<titles[bookIndex]<<"\" returned by "<<borrowerNames[borrowerIndex]<<endl;
}else{
cout<<"Book is already returned."<<endl;
}
}else{
cout<<"Book or borrower not found."<<endl;
}
}

void searchBooks(string searchTerm){
cout<<"Search Results:"<<endl;
for(int i=0;i<numBooks;++i){
if(titles[i].find(searchTerm)!=string::npos||authors[i].find(searchTerm)!=string::npos||to_string(ISBNs[i]).find(searchTerm)!=string::npos){
cout<<"Title:"<<titles[i]<<",Author:"<<authors[i]<<",ISBN:"<<ISBNs[i]<<",Available:"<<(available[i]?"Yes":"No")<<endl;
}
}
}

void calculateFine(string borrowerName){
int borrowerIndex=-1;
for(int i=0;i<numBorrowers;++i){
if(borrowerNames[i]==borrowerName){
borrowerIndex=i;
break;
}
}
if(borrowerIndex!=-1){
cout<<"Fine calculation for borrower "<<borrowerName<<endl;
cout<<"No overdue books. No fine."<<endl;
}else{
cout<<"Borrower not found."<<endl;
}
}

int main(){
char choice;
do{
cout<<"Welcome to the Library Management System!"<<endl;
cout<<"1.Add Book"<<endl;
cout<<"2.Add Borrower"<<endl;
cout<<"3.Search Books"<<endl;
cout<<"4.Checkout Book"<<endl;
cout<<"5.Return Book"<<endl;
cout<<"6.Calculate Fine"<<endl;
cout<<"7.Exit"<<endl;
cout<<"Enter your choice:";
cin>>choice;

switch(choice){
case '1':{
string title,author;
int ISBN;
cout<<"Enter Title:";
cin.ignore();getline(cin,title);
cout<<"Enter Author:";
getline(cin,author);
cout<<"Enter ISBN:";
cin>>ISBN;
addBook(title,author,ISBN);
}
break;
case '2':{
string name;
cout<<"Enter Borrower Name:";
cin.ignore();getline(cin,name);
addBorrower(name);
}
break;
case '3':{
string searchTerm;
cout<<"Enter search term:";
cin.ignore();getline(cin,searchTerm);
searchBooks(searchTerm);
}
break;
case '4':{
string bookTitle;
int ISBN;
cout<<"Enter Book Title:";
cin.ignore();getline(cin,bookTitle);
cout<<"Enter ISBN:";
cin>>ISBN;
checkoutBook(bookTitle,ISBN);
}
break;
case '5':{
int ISBN;
string borrowerName;
cout<<"Enter ISBN:";
cin>>ISBN;
cout<<"Enter borrower name:";
cin.ignore();getline(cin,borrowerName);
returnBook(ISBN,borrowerName);
}
break;
case '6':{
string borrowerName;
cout<<"Enter borrower name:";
cin.ignore();getline(cin,borrowerName);
calculateFine(borrowerName);
}
break;
case '7':
cout<<"Exiting program."<<endl;
break;
default:
cout<<"Invalid choice."<<endl;
}
}while(choice!='7');

return 0;
}