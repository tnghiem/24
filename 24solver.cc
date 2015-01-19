// Solves the game of 24 for any (non-zero) four numbers
// combining the four numbers using the four basic operations (add, subtract, multiply, divide)
// and using each number exactly once
// NB: only one possible solution will be given in each case
// NB1: in case there is no solution, a subsequent message will be printed

// 19/01/2014
// Trang-Anh Nghiem (taen2)
// I dedicate this to Tanaporn Na-Narong and James Devine-Stoneman


#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

#define target 24 // number to obtain

string OperatorSign(int k);

string OperatorSign(int k) // translates iterator on the four operations into an operator sign
{
    if (k==0) { return " + "; }
    if (k==1) { return " - "; }
    if (k==2) { return "*"; }
    if (k==3) { return "/"; }
}

typedef double (*Operator) (double a, double b);
double add (double a, double b);
double subtract (double a, double b);
double multiply (double a, double b);
double divide (double a, double b);

double add (double a, double b)
{
    double sum = a+b;
    return sum;
}

double subtract (double a, double b)
{
    double diff = a-b;
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

int main()
{
    // four-operator array
    Operator op[] =
    {
        add,
        subtract,
        multiply,
        divide
    };

    // variable definition and assignment
    double x[4]; // array of given numbers
    double xtest[4]; // permutation array to test
    double val0, val1, valtest; // intermediary and final results to test
    double xsol[4]; // solution array
    string opsignsol[3]; // solution signs

    xsol[0] = 0; // test for lack of solution

    cout<<"Enter four integers from 1 to 13"<<endl;
    for(int i=0; i<4; i++)
        {
            cin>>x[i];
        }

    // test permutation array filling
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
                                    for (int k0=0; k0<4; k0++)
                                    {
                                        val0 = op[k0](xtest[0],xtest[1]);
                                        for (int k1=0; k1<4; k1++)
                                        {
                                            val1 = op[k1](val0,xtest[2]);
                                            for (int k2=0; k2<4; k2++)
                                            {
                                                valtest = op[k2](val1,xtest[3]);
                                                if (valtest == target) // if the result is 24
                                                {
                                                    for (int l=0; l<4; l++)
                                                    {
                                                        xsol[l]=xtest[l]; // copy the solution to a solution array
                                                    }
                                                    opsignsol[0] = OperatorSign(k0);
                                                    opsignsol[1] = OperatorSign(k1);
                                                    opsignsol[2] = OperatorSign(k2); // copy the operator signs to op. sign array
                                                }
                                            }
                                        }
                                    }


                            }// endif on j3
                        }// end for on j3

                    }// endif on j2
                }// end for on j2

            }// endif on j1
        }// end for on j1
    }// end for on j0

    // solution output
    if (xsol[0]==0) // no solution found
    {
        cout << "No solution!" << endl;
    }
    else // at least one solution found
    {
        cout<<"(("<<xsol[0]<<opsignsol[0]<<xsol[1]<<")"<<opsignsol[1]<<xsol[2]<<")"<<opsignsol[2]<<xsol[3]<<endl;
    }

    return 0;

}
