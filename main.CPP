#include<iostream>
#include<string>
#include"BinaryTree.h"
#include"StackOfBinaryTree.h"
#include"stackForPostfix.h"

/*
This program is unable to deal with "the parentheses operators(...)" yet.
 */


int IdentifyChar(char x){
//identify whether the character is an operator or an operand.
    switch(x){
        case '*':
            return 2;
        case '/':
            return 2;
        case '+':
            return 1;
        case '-':
            return 1;
        case ' ':
            return 0;  
    }
    return 0;
}

void PrintPostorder();
void PrintInorder();



int main()
{
    int i;
    std::cout<< "1. Infix To Postfix"<<"\n"
             << "2. Postfix To Infix"<<"\n"
             << "Select a model(Input a number): ";
    std::cin>>i;
    if(i==1){
        std::cout<<"Infix expression To Postfix expression."<<" ";
        PrintPostorder();        
    }else if(i==2){
        std::cout<<"Postfix expression To Infix expression."<<" ";
        PrintInorder();
    }else{
        std::cerr<<"Error Input!"<<std::endl;
    }

 
    return 0;
}



//definitions of functions for "Infix to Postfix":
std::string ReadInput(){
//read a stream from standard input and return it.
    std::cout<<"Please input a correponding expression: "<<std::endl;
    std::string ins;
    std::cin>>ins;
    return ins;
}

void PopAndPrint(StackNode* s, char x){
//pop and print element in the given stack in postorder.
    if(IsEmpty(s)){
        Push(s, x);
    }else{
        //compare the priorities of the operators.
        if(IdentifyChar(x) > IdentifyChar(s->next->data)){
            Push(s, x);
        }else{
            PopAndPrintTop(s);
            PopAndPrint(s, x);
            
        }
    } 
}

//main function for print postfix expression:
void PrintPostorder(){
    std::string str = ReadInput();
    //creat a stack to store the operator.
    StackNode* s1 = CreatStack(); 
    for(auto& c1 : str){
        if(!IdentifyChar(c1)){
            std::cout<<c1<<" ";
        }else{
            PopAndPrint(s1, c1);
        }
        
    }
//print the last left operators in the stack.
    Print(s1); 
    std::cout<<std::endl;
}


//main function for print infix expression:
void PrintInorder(){
    stackHead s1 = CreateStack(); 
    std::string str1 = ReadInput();
    for(auto& c : str1){
        if(IdentifyChar(c)==0){
            (*s1).Push(CreateTree(c));
        }else{
            tree subRight = (*s1).PopAndTop()->root;
            tree subLeft = (*s1).PopAndTop()->root;
            tree root = MergeTrees(subLeft, subRight);
            root->data = c;
            (*s1).Push(root);
        }
    }
    
    PrintInorder((*s1).PopAndTop()->root); 
    std::cout<<std::endl;
}