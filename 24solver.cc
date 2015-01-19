// Solves the game of 24 for any (non-zero) four numbers
// combining the four numbers using the four basic operations (add, subtract, multiply, divide)
// and using each number exactly once
// NB: only one possible solution will be given in each case
// NB1: in case there is no solution, a subsequent message will be printed

// 19/01/2014
// Trang-Anh Nghiem (taen2)
// I dedicate this to Tanaporn Na-Narong and James Devine-Stoneman


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#define target 24 // number to obtain

string WriteOperation(int k, double x, string str);

string WriteOperation(int k, double x, string str) // translates iterator on the four operations into result string
{
    if (k==0)
        {
            stringstream s;
            s << "(" << str << " + " << x << ")";
            return s.str();
        }

    if (k==1)
        {
            stringstream s;
            s << "(" << str << " - " << x << ")";
            return s.str();
        }

    if (k==2)
        {
            stringstream s;
            s << "(" << x << " - " << str << ")";
            return s.str();
        }

    if (k==3)
        {
            stringstream s;
            s << str << "*" << x;
            return s.str();
        }

    if (k==4)
        {
            stringstream s;
            s << "(" << str << "/" << x << ")" ;
            return s.str();
        }

    if (k==5)
        {
            stringstream s;
            s << "(" << x << "/" << str << ")" ;
            return s.str();
        }
}

typedef double (*Operator) (double a, double b);
double add (double a, double b);
double subtract (double a, double b);
double commute_subtract (double a, double b);
double multiply (double a, double b);
double divide (double a, double b);
double commute_divide (double a, double b);

double add (double a, double b)
{
    double sum = a + b;
    return sum;
}

double subtract (double a, double b)
{
    double diff = a - b;
    return diff;
}

double commute_subtract (double a, double b)
{
    double diff = b - a;
    return diff;
}

double multiply (double a, double b)
{
    double prod = a*b;
    return prod;
}

double divide (double a, double b)
{
    double quot = a/b;
    return quot;
}

double commute_divide (double a, double b)
{
    double quot = b/a;
    return quot;
}

int main()
{
    // four-operator array
    Operator op[] =
    {
        add,
        subtract,
        commute_subtract,
        multiply,
        divide,
        commute_divide,
    };

    // variable definition and assignment
    double x[4]; // array of given numbers
    double xtest[4]; // permutation array to test
    double valtest[4]; // intermediary and final results to test
    string stringtest[3]; // intermediary and final written operations to test
    bool sol = 0; // existence of a solution
    double err = 0.01;

    cout<<"Enter four integers from 1 to 13"<<endl;
    for(int i=0; i<4; i++)
        {
            cin>>x[i];
        }

    // test permutation array filling and testing
    for (int j0=0; j0<4; j0++)
    {
        xtest[0] = x[j0];
        for (int j1=0; j1<4; j1++)
        {
            if (j1!=j0) // use each given number only once
            {
                xtest[1] = x[j1];
                for (int j2=0; j2<4; j2++)
                {
                    if (j2!=j1 && j2!=j0)
                    {
                        xtest[2] = x[j2];

                        for (int j3=0; j3<4; j3++)
                        {
                            if (j3!=j2 && j3!=j1 && j3!=j0)
                            {
                                xtest[3] = x[j3]; // test permutation array filled in

                                    // four operation testing on permutation array
                                    for (int k0=0; k0<6; k0++)
                                    {
                                        valtest[0] = op[k0](xtest[0],xtest[1]);
                                        stringstream sstr;
                                        sstr.str("");
                                        sstr << xtest[0]; //writing the first test number into a string in order to write the operation
                                        stringtest[0] = WriteOperation(k0,xtest[1],sstr.str());

                                        for (int k1=0; k1<6; k1++)
                                        {
                                            valtest[1] = op[k1](valtest[0],xtest[2]);
                                            stringtest[1] = WriteOperation(k1,xtest[2],stringtest[0]);

                                            for (int k2=0; k2<6; k2++)
                                            {
                                                valtest[2] = op[k2](valtest[1],xtest[3]);
                                                stringtest[2] = WriteOperation(k2,xtest[3],stringtest[1]);

                                                if ((valtest[2] - target)*(valtest[2] - target)<err*err) // if the result is 24
                                                {
                                                    sol = 1;
                                                    cout<<valtest[2]<<"\t"<<stringtest[2]<<endl;
                                                }// endif 24
                                            }// end for on k2
                                        }// end for on k1
                                    }// end for on k0
                                    // end four-operation testing

                            }// endif on j3
                        }// end for on j3

                    }// endif on j2
                }// end for on j2

            }// endif on j1
        }// end for on j1
    }// end for on j0

    // solution output
    if (sol == 0) // no solution found
    {
        cout << "No solution!" << endl;
    }

    return 0;

}
