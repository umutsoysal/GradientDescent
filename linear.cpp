
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std; 


bool custom_sort(double a, double b)
{
    double a1=abs(a-0);
    double b1=abs(b-0);
    return a1<b1;
}


int main()
{
    double x1[] = {2.7810836, 1.465489372, 3.396561688, 1.38807019, 3.06407232,7.627531214,5.332441248,6.922596716,8.675418651 ,7.673756466};                          
    double x2[] = {2.550537003,2.362125076,4.400293529,1.850220317,3.005305973,2.759262235,2.088626775,1.77106367,-0.2420686549,3.508563011};
    double y[] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    vector<double> error; // for storing the error values.
    double err;
    double b0=0;
    double b1=0;
    double b2=0;
    double alpha=0.01;
    double e=2.71828;

    for (int i = 0; i< 4000; i++){

        int idx = i% 10;
        double p = -(b0 + b1 * x1[idx]+ b2* x2[idx]); //making the prediction
        double pred  = 1/(1+ pow(e,p)); //calculating final prediction applying sigmoid
        err = y[idx]-pred;  //calculating the error
        b0 = b0 - alpha * err*pred *(1-pred)* 1.0;   //updating b0
        b1 = b1 + alpha * err * pred*(1-pred) *x1[idx];//updating b1
        b2 = b2 + alpha * err * pred*(1-pred) * x2[idx];//updating b2
        cout<<"B0="<<b0<<" "<<"B1="<<b1<<" "<<"B2="<<b2<<" error="<<err<<endl;// printing values after every step
        error.push_back(err);
    }

    sort(error.begin(),error.end(),custom_sort);//custom sort based on absolute error difference
    cout<<error.size()<<endl;
    cout<<"Finaddl Values are: "<<"B0="<<b0<<" "<<"B1="<<b1<<" "<<"B2="<<b2<<" error="<<error[0];

    
    
    /*Testing Phase*/
    double test1,test2; //enter test x1 and x2
    cin>>test1>>test2;
    double pred=b0+b1*test1+b2*test2; //make prediction
    cout<<"The value predicted by the model= "<<pred<<endl;
    if(pred>0.5)
    pred=1;
    else
    pred=0;
    cout<<"The class predicted by the model= "<<pred;
    for(int i=0; i < error.size(); i++)
        std::cout << error.at(i) << ' '<<endl;
    return 0;
}