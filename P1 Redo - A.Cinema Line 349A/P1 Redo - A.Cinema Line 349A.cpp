#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    int Number_of_People;
    cin >> Number_of_People;

    vector<int> People_Money;                               // VECTOR for Storing Roll Money Values
    int Input;                                              // Can't push back directly using the loop
    int Counter = 1;                                        // Person Number Counter
    for (int i = 0; i < Number_of_People; i++)              // loop for pushing Money Values
    {
        cin >> Input;
        People_Money.push_back(Input);
        Counter++;
    }

    vector<int>::iterator IT;
    //for(IT = People_Money.begin(); IT != People_Money.end(); IT++)
    //{
    //    cout << *IT << "\t";
    //}

    int Whatif_25 = 0, Whatif_50 = 0, Whatif_100 = 0;
    for (IT = People_Money.begin(); IT != People_Money.end(); IT++)
    {
        if (*IT == 25)              //If taken 25R     
        {
            Whatif_25++;            //Increas The Change of 25 with 1  
        }
        else if (*IT == 50)         //If taken 50R    
        {
            if (Whatif_25 >= 1)    //Check if there is a change of 25R and if there is
            {
                Whatif_25--;      //Decreas The Change of 25R with 1  
                Whatif_50++;     //And increase the Change of 50R PAPERs with 1
            }
            else
            {
                cout << "NO";   //if there is not enough 25R Change Cout NO cause the roll is corrupted
                return 0;
            }
        }
        else if (*IT == 100)                         //If taken 25R    
        {
            if (Whatif_25 >= 1 && Whatif_50 >= 1)   //Check if there are a change of 25R and 50R if there are give the customer a paper of 50 and one of 25
            {
                Whatif_25--;            //give the customer a paper of 25
                Whatif_50--;            //give the customer a paper of 50
            }
            else if (Whatif_25 >= 3 && Whatif_50 == 0)      //Check if there isn't enough change of 50 Paper and there is of 25 paper
            {
                Whatif_25 -= 3; //if yes give 3 of 25
            }
            else
            {
                cout << "NO";   //if there is not enough Change Cout NO
                return 0;
            }
        }
        //TotalMoney_Reserve = ((Change_25) + (Change_50) + (Whatif_100));

        //if (TotalMoney_Reserve < 0)
        //{
        //    cout << "NO";
        //}
        //if (TotalMoney_Reserve == 0)
        //{
        //    cout << "YES";
        //}
        //if (TotalMoney_Reserve > 0)
        //{
        //    cout << "YES";
        //}
        
    }
    cout << "YES";      // all the chances of failed or fault or to corrupt the roll has been taken in "resolved" so why saying no??? say yes please!
}