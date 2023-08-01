#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int EVENT = 6;
int menuPrograme();
void availability();
int menuEvent(string e[]);
int suggestFood();
double cost(int);
void help();
void feedback();
void aboutUs();  //Use void return type, because function does not return a value.


struct userInfo { //Structure tag
	string name;
	string email;
	int contNum;
	double budget;
	int numGuests;  // Structure members
};
userInfo user; //Define a variable to structure userInfo.

userInfo userDetails(); //Structure function prototype to get user input.
void receipt(userInfo, double, string, int); //function prototype to Display receipt.Use void, because function does not return a value.

int main() {

	int operation, ListTypeEvent, package;
	double totalCost;
	string typeEvent[EVENT] = { "Special Event", "Corporate Event","Malay Event","Chinese Event", "Indian Event","Other Event" };

	do {

		// Call menuPrograme() function and then return choice to variable operation.
		operation = menuPrograme(); // Mohamad Khairul Ikwan bin Md Yusoff
		
		if (operation == 1) {

			cin.ignore();
			availability(); // Akmal Zahin bin Zulkepli
			user = userDetails(); // Muhamad Nabil bin Muhamad Shukri
			ListTypeEvent = menuEvent(typeEvent); // Mohamad Khairul Ikwan bin Md Yusoff
			package = suggestFood(); // Akmal Zahin bin Zulkepli
			totalCost = cost(package);// Mohamad Khairul Ikwan bin Md Yusoff
			receipt(user, totalCost, typeEvent[ListTypeEvent], package); // Muhamad Nabil bin Muhamad Shukri
		}

		else if (operation == 2) // Akmal Zahin bin Zulkepli
			help();

		else if (operation == 3) // Mohamad Khairul Ikwan bin Md Yusoff
			feedback();

		else if (operation == 4) // Muhamad Nabil bin Muhamad Shukri
			aboutUs();

		else
			cout << "Thank you for your visit. We hope to see you again.\n";

	} while (operation >= 1 && operation <= 4); // Loop if the value of operation is within the range of 1 until 4.

	return 0;
}

// Mohamad Khairul Ikwan bin Md Yusoff
int menuPrograme() { // Function to display menu and return user's choice to variable operation in main.
	int choice;
	cout << "WELCOME TO THREE GUYS CATERING\n";
	cout << "1. Make a reservation\n";
	cout << "2. Help\n";
	cout << "3. Feedback\n";
	cout << "4. About Us\n";
	cout << "Press any other key to exit the program\n";
	cout << "Your choice : ";
	cin >> choice;
	return choice;
}

// Akmal Zahin bin Zulkepli 
void availability() { // Function to check if user's state is within the area covered by the caterer.

	char state[20];
	string m = "MELAKA";
	string j = "JOHOR";
	string s = "SELANGOR";
	string STATE = "";

	do {
		cout << "\nEnter your state : ";
		cin.getline(state, 20);

		for (int i = 0; i < 20; i++) { // Make all the letters uppercase for easier validating.
			if (state[i] != '\0') // Uppercase the letter, if reached the end, break from loop.
				state[i] = toupper(state[i]);
			else
				break;
		}

		for (int i = 0; i < 20; i++) { // Store the letters in a string variable STATE.

			if (state[i] != '\0') // Store the letter, if reached the end, break from loop.
				STATE = STATE + state[i];
			else
				break;
		}

			if (STATE != m && STATE != j && STATE != s) { // Print message to tell user the entered state is out of service area.
				cout << "The state is out of our service area. We only cover Melaka, Johor and Selangor.\n";
				STATE.clear();
			}
		
	} while (STATE != m && STATE != j && STATE != s); // Loop if the state entered by user is not Melaka, Johor or Selangor.
}

// Muhamad Nabil bin Muhamad Shukri
userInfo userDetails() {

	cout << "\n-----Customer Details-----\nThank you for your interest in Three Guys Catering.\nKindly fill up the form below and we will get back to you right away.\n";
	cout << "\nName : ";
	getline(cin, user.name); // Use getline function to put a line of input, because including spaces, into a string
	cout << "Email : ";
	getline(cin, user.email);  //Use the dot (.) operator to refer to members of struct variables
	cout << "Contact Number : ";
	cin >> user.contNum;      //Use cin to read input into int contNum


	cout << "Estimated number of guests (minimum 300) : "; //Set a minimum amount of guest of a single event
	cin >> user.numGuests;  //dot (.) operator to refer to members of struct variables
	while (user.numGuests < 300) //Input validation if user enter guest less than 300
	{
		cout << "Please enter the estimated number of guests not less than 300.\n";
		cout << "Estimated number of guests (minimum 300) : ";
		cin >> user.numGuests;
	}

	cout << "Budget :RM ";
	cin >> user.budget;  //dot (.) operator to refer to members of struct variables
	while ((user.numGuests * 8) > user.budget)  //Input validation if userBudget is less than the package with the minimum price(RM 8)
	{
		cout << "Based on the number of guests, the minimum budget required is RM " << user.numGuests * 8 << ".\n";
		cout << "Budget :RM ";
		cin >> user.budget;
	}


	return user; //return structure userInfo to print in Receipt() Function
}

// Mohamad Khairul Ikwan bin Md Yusoff
int menuEvent(string e[]) { // Function to display the type of events and return choice to variable ListTypeEvent in main.
	int choice;
	string nameEvent;

	do {
		cout << "\nList Type Of Event\n";
		// Use for loop to display type of event. Output element-by-element.
		for (int i = 0; i < EVENT; i++) {
			cout << i + 1 << ". " << e[i] << endl;
		}
		cout << "Choose the Event : ";
		cin >> choice;
		if (choice < 1 || choice > 6) // Print invalid choice message if choice is less than 1 or more than 6.
			cout << "\nInvalid Choice. Please Try Again.";
		else
			cout << "\nEnter Your event name : "; // Ask user to enter the name of the event.
		cin.clear(); cin.ignore();
		getline(cin, nameEvent);
		cout << endl;
	} while (choice < 1 || choice > 6); // Loop if choice is less than 1 or more than 6.

	return choice - 1;
}

// Akmal Zahin bin Zulkepli
int suggestFood() { // Function to display the recommended package based on user's budget.

	int suggest, choice;
	cout << "-----Below are the recommended package based on your budget.-----\n\n";

	// Assign the value 1,2,3,4 or 5 to variable suggest based on user's budget.
	if ((user.numGuests * 16) <= user.budget)
		suggest = 1;
	else if ((user.numGuests * 14) <= user.budget)
		suggest = 2;
	else if ((user.numGuests * 12) <= user.budget)
		suggest = 3;
	else if ((user.numGuests * 10) <= user.budget)
		suggest = 4;
	else
		suggest = 5;

	switch (suggest) { // Display available packages based on suggest.

	case 1: cout << "Package 1 (RM 16 per pax)\n\n";
		cout << "Beriani rice\nSpiced chicken\nMutton curry\nPickled fruits\nPapadom\nCordial drinks & cendol\n\n";

	case 2: cout << "Package 2 (RM 14 per pax)\n\n";
		cout << "Beriani rice\nAyam masak merah\nCurry meat\nPickled fruits\nPapadom\nCordial drinks & teh tarik\n\n";

	case 3: cout << "Package 3 (RM 12 per pax)\n\n";
		cout << "Tomato rice\nAyam masak merah\nCurry meat\nWatermelon fruits\nPapadom\nCordial drinks\n\n";

	case 4: cout << "Package 4 (RM 10 per pax)\n\n";
		cout << "Nasi hujan panas\nSpicy fried chicken\nDaging masak kurma\nOrange fruits\nPapadom\nCordial drinks\n\n";

	default: cout << "Package 5 (RM 8 per pax)\n\n";
		cout << "White rice\nAyam masak merah\nBlackpepper meat\nOrange fruits\nPapadom\nSyrup\n\n";
	}

	do {
		cout << "Select your package : ";
		cin >> choice;
		if (choice < suggest || choice > 5) // Print message to select available package only if choice is less than suggest or more than 5. 
			cout << "Please select only the package offered above.\n";
	} while (choice < suggest || choice > 5); // Loop if choice is less than suggest or more than 5.

	return choice; // Return choice to variable package in main.
}

// Mohamad Khairul Ikwan bin Md Yusoff
double cost(int PACKAGE) { // Function to calculate the total cost of reservation.
                           
	double totalCost;

	if (PACKAGE == 1)
		totalCost = user.numGuests * 16;
	else if (PACKAGE == 2)
		totalCost = user.numGuests * 14;
	else if (PACKAGE == 3)
		totalCost = user.numGuests * 12;
	else if (PACKAGE == 4)
		totalCost = user.numGuests * 10;
	else if (PACKAGE == 5)
		totalCost = user.numGuests * 8;

	cout << "\nThank you for your reservation.\n\n";
	return totalCost; // Return value to variable totalCost in main.
}

//Muhamad Nabil bin Muhamad Shukri
void receipt(userInfo user, double totalCost, string event, int package) //Passing Multiple Arguments in parameter
{
	cout << "------------------------------------\n";
	cout << "------------RECEIPT-----------------\n" << "Invoice to: \n";
	cout << "Name:            " << user.name << endl;
	cout << "Email:           " << user.email << endl;    //Display structure members passed to the function
	cout << "Contact Number:  0" << user.contNum << endl;
	cout << "Type of Event:   " << event << endl;        //Display Event type string passed to the funtion
	cout << "Package Number:  " << package << endl;      //Display Package string passed to the funtion
	cout << "-------------------------------\n";
	cout << fixed << setprecision(2) << "TOTAL COST:      RM " << totalCost << endl; // Display TotalCost value passed to the function.  
	                                                                                 // Set 2 decimal places because it's a price.
	cout << "------------------------------------\n";
	cout << "------------------------------------\n\n";
}

// Akmal Zahin bin Zulkepli 
void help() { // Function to display the caterer's contact information.

	cout << "\nIf you have further inquiries or need help, do contact us by : " << "\n";
	cout << "Our contact number : 012-3456789\n";
	cout << "Hotline: 1700-81-8244\n";
	cout << "Our email : threeguyscatering@gmail.com" << "\n";
	cout << "Business Hours: MONDAY - FRIDAY from 10.00AM - 6.00PM\n\n";

}

// Mohamad Khairul Ikwan bin Md Yusoff
void feedback() { // Function to receive feedback from users.

	int star;
	string feedback;

	cout << "\n==Thank You for choosing our catering service==";
	cout << "\n*Please choose a rating for our service and leave your feedback below *" << endl;
	cout << "\n|| 5 star"
		<< "|| 4 star"
		<< "|| 3 star"
		<< "|| 2 star"
		<< "|| 1 star";
	cout << "\nchoose star : "; // Ask user to enter the number of stars.
	cin >> star; 
	cout << "\nFeedback : "; // Ask user to enter their feedback.
	cin.clear(); cin.ignore();
	getline(cin, feedback); 
	cout << "\nThank you for your feedback \"" << feedback << "\" and give " << star << " star." << endl;
	cout << "\nWe will use it to improve our service. Have A Nice Day\n" << endl;
}

// Muhamad Nabil bin Muhamad Shukri
void aboutUs() { //Use void return type, because function does not return a value.

	cout << "\n\n\tThree Guys Catering was incorporated in the year 2003 with the objective of making good food"
		" affordable to all Malaysians. We strongly believe that good food does"
		"\n not have to come at a high price";
	cout << " that is why we go by our business philosophy of giving Malaysians from all walks of life the access to high-quality food.\n\n"
		"\tThree Guys Catering not only operates as a cafe, but also provides catering service to accommodate to the increasing";
	cout << " demand for our delicious food. From an annual"
		"\n revenue of around RM200,000, our business then grew almost 10 times the"
		"size in less than a decade. Thanks to the continuous support we received from new and repeat \n customers.\n\n";
	cout << "\tA gentle reminder, Three Guys Catering serves Halal food and is observing Halal practice. Should you have self-prepared"
		"non-Halal food during the function, kindly"
		"\n advise us earlier so that we can standby some disposables for your convenience.\n\n";
}

