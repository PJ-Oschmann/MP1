/*
donuts.cpp

Created by PJ Oschmann on 9/20/21.

This program calculates the price of regular and fancy donuts and apple fritters, and displays the change which needs to be given when a given customer pays.
The output also contains the specific dollars and coins needed in the change.
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


//Regular: $.75 each, $7.99 per dozen
//Fancy: $.85 each, $8.49 per dozen
//Apple Fritters: $1.50 each


int main() {
    int numberOfRegularDonuts = 0; //User input
    int numberOfFancyDonuts = 0; //User input
    int numberOfAppleFritters = 0; //User input
    int dozensOfRegularDonuts = 0; //Program calcuates
    int leftOverRegularDonuts = 0; //Program calculates

    int dozensOfFancyDonuts = 0; //Program calculates
    int leftOverFancyDonuts = 0; //Program calculates

    float regularDozenTotal = 0.00f; //Program calculates
    float regularLeftOverTotal = 0.00f; //Program calculates
    float regularDonutTotal = 0.00f; //Program calculates

    float fancyDozenTotal = 0.00f; //Program calculates
    float fancyLeftOverTotal = 0.00f; //Program calculates
    float fancyDonutTotal = 0.00f; //Program calculates


    float appleFritterTotal = 0.00f; //Program calculates

    float total = 0.00f; //Program calculates
    float paidAmount = 0.00f; //User input
    float change = 0.00f; //Program calculates

    int dollars = 0; //Program calculates
    int quarters = 0; //Program calculates
    int dimes = 0; //Program calculates
    int nickels = 0; //Program calculates
    int pennies = 0; //Program calculates

    string changeOwedStr = ""; //Program calculates
    bool useChangeOwed = true; //Program calculates; should the final output show change or mention exact change was given?
    bool insufficientChangeGiven = false; //If the user doesn't give enough change, don't output anything.

    string dollar_string = "";
    string quarter_string = "";
    string dime_string = "";
    string nickel_string = "";
    string penny_string = "";


    //Get amount of regular donuts, fancy donuts, and apple fritters
    cout << "Number of regular donuts ordered: ";
    cin >> numberOfRegularDonuts;
    cout << "Number of fancy donuts ordered: ";
    cin >> numberOfFancyDonuts;
    cout << "Number of apple fritters ordered: ";
    cin >> numberOfAppleFritters;

    //Calculate price of regular donuts:

    dozensOfRegularDonuts = numberOfRegularDonuts/12; //Works thanks to truncating decimals
    leftOverRegularDonuts = numberOfRegularDonuts%12; //Left overs after dozens

    regularDozenTotal = dozensOfRegularDonuts * 7.99;
    regularLeftOverTotal = leftOverRegularDonuts * .75;
    regularDonutTotal = regularDozenTotal + regularLeftOverTotal;

    //cout << "DEBUG: regularDonutTotal=" << regularDonutTotal << endl;

    //Calculate price of fancy donuts:

    dozensOfFancyDonuts = numberOfFancyDonuts/12; //Works thanks to truncating decimals
    leftOverFancyDonuts = numberOfFancyDonuts%12; //Left overs after dozens

    fancyDozenTotal = dozensOfFancyDonuts * 8.49;
    fancyLeftOverTotal = leftOverFancyDonuts * .85;
    fancyDonutTotal = fancyDozenTotal + fancyLeftOverTotal;

    //cout << "DEBUG: fancyDonutTotal=" << fancyDonutTotal << endl;

    //Calculate price of apple fritters donuts:

    appleFritterTotal = numberOfAppleFritters * 1.50;

    //cout << "DEBUG: appleFritterTotal=" << appleFritterTotal << endl;

    //Calculate total price:

    total = (regularDonutTotal + fancyDonutTotal + appleFritterTotal)*1.075;

    //cout << "DEBUG: total=" << total << endl;
    cout << "Customer owes $";
    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << total << endl;
    cout << "Customer pays $";
    cin >> paidAmount;


    change = (paidAmount - total)+.005;

    //Find dollars
    dollars = change /1.00f;
    //cout << "DEBUG: dollars=" << dollars << endl;
    change -= (dollars * 1.00f);

    //Find quarters
    quarters = change /.25f;
    //cout << "DEBUG: quarters=" << quarters << endl;
    change -= (quarters * .25f);

    //Find dimes
    dimes = change /.10f;
    //cout << "DEBUG: dimes=" << dimes << endl;
    change -= (dimes * .10f);

    //Find nickels
    nickels = change /.05f;
    //cout << "DEBUG: nickels=" << nickels << endl;
    change -= (nickels * .05f);

    //Find pennies
    pennies = (change /.01f)+.005f;
    //cout << "DEBUG: pennies=" << pennies << endl;
    change -= (pennies * .01f);
    //cout << "DEBUG: change=" << change << endl;

    //Format output
    /*

    If there are multiple dollars or types of coin, the plural version of that unit is saved to a string variable. If it's 0, a blank string is saved to the variable.
    The output is then constructed below, unless the change equals the amount given (with .005 tolerance to variable paidAmount).

    */

    //Find number of each dollar or coin.
    if (dollars>1) {
        //cout << "DEBUG: GREATER" << endl;
        dollar_string = to_string(dollars) + " dollars, ";
    }
    else if (dollars == 1) {
        //cout << "DEBUG: EQUAL 1" << endl;
        dollar_string = to_string(dollars) + " dollar, ";
    }
    else if (dollars == 0) {
        //cout << "DEBUG: ZERO" << endl;
        dollar_string = "";
    }

    if (quarters>1) {
        //cout << "DEBUG: GREATER" << endl;
        quarter_string = to_string(quarters) + " quarters, ";
    }
    else if (quarters == 1) {
        //cout << "DEBUG: EQUAL 1" << endl;
        quarter_string = to_string(quarters) + " quarter, ";
    }
    else if (quarters == 0) {
        //cout << "DEBUG: ZERO" << endl;
        quarter_string = "";
    }

    if (dimes>1) {
        //cout << "DEBUG: GREATER" << endl;
        dime_string = to_string(dimes) + " dimes, ";
    }
    else if (dimes == 1) {
        //cout << "DEBUG: EQUAL 1" << endl;
        dime_string = to_string(dimes) + " dime, ";
    }
    else if (dimes == 0) {
        //cout << "DEBUG: ZERO" << endl;
        dime_string = "";
    }

    if (nickels>1) {
        //cout << "DEBUG: GREATER" << endl;
        nickel_string = to_string(nickels) + " nickels, ";
    }
    else if (nickels == 1) {
        //cout << "DEBUG: EQUAL 1" << endl;
        nickel_string = to_string(nickels) + " nickel, ";
    }
    else if (nickels == 0) {
        //cout << "DEBUG: ZERO" << endl;
        nickel_string = "";
    }

    if (pennies>1) {
        //cout << "DEBUG: GREATER" << endl;
        penny_string = to_string(pennies) + " pennies, ";
    }
    else if (pennies == 1) {
        //cout << "DEBUG: EQUAL 1" << endl;
        penny_string = to_string(pennies) + " penny, ";
    }
    else if (pennies == 0) {
        //cout << "DEBUG: ZERO" << endl;
        penny_string = "";
    }


    //Determine if amount paid equals the amount expected, with a tolerance of .005.
    if ((paidAmount >= (total-.005) && paidAmount <= (total+.005)) || (paidAmount <= (total+.005) && paidAmount <= (total-.005))) {
        useChangeOwed = false;
    }
    else if (total != paidAmount) {
        useChangeOwed = true;

    }

    else {
        cout << "this shouldn't happen lol";
    }

    //Output to screen



    //Output if change is owed
    if (useChangeOwed == true && insufficientChangeGiven == false) {
        changeOwedStr = dollar_string + quarter_string + dime_string + nickel_string + penny_string;
        changeOwedStr = changeOwedStr.substr(0,changeOwedStr.size()-2); //Remove last two charcters from end of string (will be space and comma)
        cout << fixed << showpoint;
        cout << setprecision(2);
        cout << "Change owed is " << paidAmount - total << " - " << changeOwedStr << "." << endl; //Print output, ending with a period.
        //cout << "Change owed is $" << dollar_string << quarter_string << dime_string << nickel_string << penny_string << endl;
    }

    //Output if no change is owed.
    else if (useChangeOwed == false || insufficientChangeGiven == false) {
        cout << "Exact payment received - no change owed" << endl;
    }
}
