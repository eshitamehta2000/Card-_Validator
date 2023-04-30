#include<iostream>
#include<string>

using namespace std;

void Validator(string cc_number,string weight)
{
    
    for(int i=0;cc_number[i]!='\0';i=i+2)
    {
        
        int x=stoi(string(1,cc_number[i]));
        x=x*2;
        if(x>9)
        {
           int sum=0;
            while(x!=0)
            {
                int y=x%10;
                x=x/10;
                sum+=y;
            }
           x=sum;
        }
        string str= to_string(x);  

        cc_number.replace(i,1,str);   

    }

  int final_sum=0;
 for(int i=0;cc_number[i]!='\0';i++)
    {
        int x=0;
        x=stoi(string(1,cc_number[i]));
        final_sum+=x;
    }
    if(final_sum%10==0)
    {
        cout<<"Valid";
    }
    else
    {
        cout<<"Invalid";
    }

}

int main()
{
    string cc_number;
    cout<<"Kindly enter your 16-digit Credit Card number(without any space)"<<endl;
    cin>>cc_number;
    int count_numbers=0;
    for(int i=0;cc_number[i]!='\0';i++)
    {
        if(cc_number[i]>='0' and cc_number[i]<='9')
        {
            count_numbers++;
        }   
    }
    if(cc_number.length()!=16 || count_numbers!=16)
    {
        cout<<"Wrong input";
        
    }
    else{
          string weight={"2121212121212121"};
          Validator(cc_number,weight);
    }
  
    return 0;
}