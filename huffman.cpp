#include <iostream>
#include <string>
#include "huffman.hpp"
using namespace std;

int main() {
    cout<<"Enter your choice (1 for compress, 2 for decompress): ";
    int choice; bool flag=false; 
    while(!flag){
        cin>>choice; 
        if(choice!=1 && choice!=2)
            cout<<"Invalid choice. Please enter either '1' or '2'"<<endl;
        else flag=true;
    } string inputFileName, outputFileName; cin.ignore();
    if(choice==1){
        cout<<"Enter the name of the input file: ";
        getline(cin, inputFileName); 
        cout<<"Enter the name for the compressed file: ";
        getline(cin, outputFileName); 
    }else{
        cout<<"Enter the name of the compressed file: ";
        getline(cin, inputFileName);
        cout << "Enter the name for the output file: ";
        getline(cin, outputFileName);
    } huffman obj(inputFileName, outputFileName);
    if(choice==1) {
        obj.compress();
        cout<<"Compressed successfully"<<endl;
    }else{
        obj.decompress();
        cout<<"Decompressed successfully"<<endl;
    } return 0;
}
