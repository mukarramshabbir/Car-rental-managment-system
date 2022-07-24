#include <iostream>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// ----------------START OF PROTYPES---------------

void header();
void clearscreen();
void lines();
int adminmenu();
int mainmenu();
char usermenu();
string loginmenu();
void adduser(string username, string password, string role);
void availablecars();
void registration();
void addregistration(string name, int age, double id, double phonenumber, string father, string address, string occupation, string license, string type, string car);
void journeyinformation();
void addjourneyinformation(string pickup, string destination, int km, int starting, int ending, int days);
void generatebill();
void storegeneratebill(int rent);
void transactiondetails();
void savetransactiondetail(string cname, double number, double date, int cvv);
string addcar();
void storeaddcar(string cartype, string carname, string carcolor, string carlicense, int carmodel);
void updatecardetails();
void viewallrecords();
int sorting(int n);
void sort();
void adddiscount();
void createaccount();
void companypolicy();
void viewbookings();
void editprofiledetails();
string parserecord(string line, int field);
void storedataregistration();
void loaddataregistration();
void storebillinformation();
void storelogindetails();
void loadbillinformation();
void loadlogininformation();
void storejourneyinformation();
void loadjourneyinformation();

// ---------------END OF PROTOTYPES-----------------

// ---------------START OF VARIABLES----------------

int arraylength[5];
int const userlimit = 10;
int const maxrecord = 5;
int count = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
float discount = 15;
int indexes = 0;
char opti;
int largest = 0;
string username, password;
int carrentdupA[maxrecord];

string usernameA[userlimit];
string passwordA[userlimit];
string roleA[userlimit];

// adminoption # 1
int drent = 3000, wrent = 15000, drent1 = 4000, wrent1 = 20000, drent2 = 5000, wrent2 = 25000;
string car, name, pickup;
string customernameA[maxrecord];
int customerageA[maxrecord];
double customeridA[maxrecord];
double customerphonenumberA[maxrecord];
string customerfatherA[maxrecord];
string customeraddressA[maxrecord];
string customeroccupationA[maxrecord];
string customerlicenseA[maxrecord];
string customertypeA[maxrecord];
string customercarA[maxrecord];
// adminoption # 2
string pickupA[maxrecord];
string destinationA[maxrecord];
int kmA[maxrecord];
int startingA[maxrecord];
int endingA[maxrecord];
int daysA[maxrecord];
// adminoption # 3
int carrentA[maxrecord];
// adminoption # 4
string cnameA[maxrecord];
double accountnumberA[maxrecord];
double carddateA[maxrecord];
int cvvA[maxrecord];
// adminoption # 5
string cartypeA[maxrecord];
string carnameA[maxrecord];
string carcolorA[maxrecord];
string carlicenseA[maxrecord];
int carmodelA[maxrecord];
// useroption # 2
string loginusername = " ";
// ----------------END OF VARIABLES-----------------

main()
{ //---------------START OF MAIN---------------------

    loaddataregistration();
    loadbillinformation();
    loadlogininformation();
    loadjourneyinformation();

    string addacar;
    adduser("admin", "12345", "admin");
    adduser("user", "12345", "user");
    int res;

    string who;
    while (res != 3)
    {
        res = mainmenu();
        clearscreen();
        who = loginmenu();

        if (who == "admin")
        {
            int adminoption = 0;
            clearscreen();
            while (adminoption != 10)
            {
                adminoption = adminmenu();
                clearscreen();

                if (adminoption == 1)
                { // registration
                    header();
                    registration();
                    storedataregistration();
                }
                else if (adminoption == 2)
                { // journey information
                    header();
                    journeyinformation();
                    int l;
                    for (int i = 0; i < maxrecord; i++)
                    {
                        if (customercarA[i] == car)
                        {
                            l = i;
                        }
                    }
                    cout << "Your selected car: " << customercarA[l] << endl;
                    lines();
                    storejourneyinformation();
                }
                else if (adminoption == 3)
                { // generate bill

                    generatebill();
                }
                else if (adminoption == 4)
                { // transaction details
                    header();
                    transactiondetails();
                    storebillinformation();
                }
                else if (adminoption == 5)
                { // add a car
                    header();
                    addacar = addcar();
                }
                else if (adminoption == 6)
                { // update car details
                    header();
                    updatecardetails();
                }
                else if (adminoption == 7)
                { // view all records
                    header();
                    viewallrecords();
                }
                else if (adminoption == 8)
                { // add discount offers
                    header();
                    adddiscount();
                }
                else if (adminoption == 9)
                { // create account
                    header();
                    createaccount();
                    storelogindetails();
                }
                else if (adminoption == 10)
                { // logout
                    header();
                    cout << " " << endl;
                    cout << "Thanks for using CAR RENTAL MANAGMENT SYSTEM " << endl;
                    cout << " " << endl;
                }
                clearscreen();

                
            }
        }
        if (who == "user")
        {
            char useroption = '0';
            clearscreen();
            while (useroption != '6')
            {
                useroption = usermenu();
                clearscreen();
                if (useroption == '1')
                {
                    header();
                    availablecars();
                }
                else if (useroption == '2')
                { // view bookings
                    viewbookings();
                }
                else if (useroption == '3')
                { // view company policy
                    companypolicy();
                }
                else if (useroption == '4')
                { // edit profile details
                    editprofiledetails();
                }
                else if (useroption == '5')
                { // customer feedback
                    string feedback;
                    header();
                    cout << "**************** Customer Feedback ******************|" << endl;
                    lines();
                    cout << "Enter your feedback: ";
                    cin >> feedback;
                    lines();
                }
                else if (useroption == '6')
                { // logout
                    header();
                    lines();
                    cout << "Thanks for using Car Rental Managment system as a USER." << endl;
                    lines();
                }
                else if (useroption > 6 || useroption < 0)
                {
                    header();
                    cout << "You entered wrong number...Please TRY AGAIN..." << endl;
                }
                clearscreen();
            }
        }
        else if(who!="admin" && who!="user"){cout<<"You entered wrong username and password"<<endl;}
    }

} // ----------------END OF MAIN---------------------

// ---------------START OF FUNCTION-----------------
void header()
{
    cout << "//////////////////////////////////////////////////////////////////////" << endl;
    cout << "" << endl;
    cout << "                    CAR RENTAL MANAGMENT SYSTEM             " << endl;
    cout << "" << endl;
    cout << "//////////////////////////////////////////////////////////////////////" << endl;
    cout << "" << endl;
}
void clearscreen()
{
    cout << "Enter any number to continue: ";
    getch();
    system("cls");
}

void lines()
{
    cout << " " << endl;
    cout << "-----------------------------------------------------|" << endl;
    cout << "-----------------------------------------------------|" << endl;
    cout << "" << endl;
}

int mainmenu()
{
    int option;
    header();
    cout << "1. Log in as Admin: " << endl;
    cout << "2. Log in as Customer: " << endl;
    cout << "3. Exit the program: " << endl;
    cout << "\n";
    cout << "Enter your Option: ";
    cin >> option;
    while(option>3 || option<0)
    {
        cout<<"You enterd invalid option."<<endl;
        cout << "Enter your Option: ";
        cin >> option;
    }
    return option;
}

int adminmenu()
{

    header();
    int opt;
    cout << "" << endl;
    cout << "****************** ADMIN MAIN MENU ******************|" << endl;
    cout << "-----------------------------------------------------|" << endl;
    cout << "-----------------------------------------------------|" << endl;
    cout << "" << endl;
    cout << "  1.Registration: " << endl;
    cout << "  2.Enter the Journey Information: " << endl;
    cout << "  3.Generate Bill: : " << endl;
    cout << "  4.Transaction Details: " << endl;
    cout << "  5.Add A Car: " << endl;
    cout << "  6.Update Car details: " << endl;
    cout << "  7.View All Records: " << endl;
    cout << "  8.Add Discount Offers: " << endl;
    cout << "  9.Create Account: " << endl;
    cout << " 10.Logout: " << endl;
    lines();
    cout << " Enter your option...";
    cin >> opt;
    while (opt > 10 || opt < 0)
    {
        cout << "Invalid option.Please choose option between 1-10" << endl;
        cout << " Enter your option...";
        cin >> opt;
    }

    return opt;
}

char usermenu()
{
    char option;
    header();
    // main menu of user
    cout << "" << endl;
    cout << " *************** CUSTOMER MAIN MENU *****************|" << endl;
    cout << "-----------------------------------------------------|" << endl;
    cout << "-----------------------------------------------------|" << endl;
    cout << "" << endl;
    cout << " 1.Check Available Cars: " << endl;
    cout << " 2.View Bookings: " << endl;
    cout << " 3.View Company Policy: " << endl;
    cout << " 4.Edit Profile Details: " << endl;
    cout << " 5.Customer Feedback: " << endl;
    cout << " 6.Logout: " << endl;
    lines();
    cout << "Enter your Option: ";
    cin >> option;
    while(option>'6' || option<'0')
    {
        cout<<"You entered invalid option."<<endl;
        cout << "Enter your Option: ";
        cin >> option;
    }
    return option;
}

string loginmenu()
{
    header();

    cout << "       Enter the Username: ";
    cin >> username;
    cout << "       Enter the Password: ";
    cin >> password;
    for (int i = 0; i < userlimit; i++)
    {
        if (usernameA[i] == username && passwordA[i] == password)
        {
            loginusername = username;
            return roleA[i];
        }
        // else if (usernameA[i] != username && passwordA[i] != password)
        // {
        //     cout << "You entered wrong username and password.Try again" << endl;
        //     break;
        // }
    }

    loginusername = " ";
    return "wrong";
}

void createaccount()
{
    if (count < userlimit)
    {
        string user, pass, role;
        cout << "****************** Create Account *******************|" << endl;

        lines();
        cout << "Enter the username: ";
        cin >> user;
        cout << "Enter the password: ";
        cin >> pass;
        cout << "Enter the role: ";
        cin >> role;
        while(role!="user" && role!="admin" && role!="User" && role!="Admin" && role!="USER" && role!="ADMIN")
        {
            cout<<"Please select either 'User' or 'Admin'."<<endl;
            cout << "Enter the role: ";
            cin >> role;
        }
        adduser(user, pass, role);
        lines();
    }
    else
    {
        cout << "No more space to add users" << endl;
    }
}

void adduser(string username, string password, string role)
{

    if (count < userlimit)
    {
        usernameA[count] = username;
        passwordA[count] = password;
        roleA[count] = role;
        count = count + 1;
    }
    else
    {
        cout << "-------------SORRY-----------" << endl;
        cout << "No More Space To Add Users." << endl;
    }
}

void availablecars()
{
    int option1;
    cout << "***************** Available Cars ********************|" << endl;
    cout << "-----------------------------------------------------|" << endl;
    cout << "-----------------------------------------------------|" << endl;
    cout << "" << endl;
    cout << "Select one of these Car Types:" << endl;
    cout << "" << endl;
    cout << " 1.Sedan:" << endl;
    cout << "" << endl;
    cout << " 2.SUV(Sports Utility Vehicle):" << endl;
    cout << "" << endl;
    cout << " 3.Convertible:" << endl;
    lines();
    cout << "Enter your option...";
    cin >> option1;
    while(option1>3 || option1<0)
    {
        cout<<"You entered invalid option."<<endl;
        cout << "Enter your option...";
        cin >> option1;
    }
    system("cls");

    // Available Car types
    if (option1 == 1)
    {
        // SEDAN TYPE

        header();
        lines();
        cout << "The cars available of the Sedan type are:" << endl;
        cout << "" << endl;
        cout << " 1.HONDA CIVIC: " << endl;
        cout << "" << endl;
        cout << "Body Color: WHITE       License no: LE1122       Model:2018   " << endl;
        cout << "" << endl;
        cout << " 2.TOYOTA COROLLA: " << endl;
        cout << "" << endl;
        cout << "Body Color: WHITE       License no: FE9733       Model:2017   " << endl;
        cout << "" << endl;
        cout << " 3.HYUNDAI ELANTRA: " << endl;
        cout << "" << endl;
        cout << "Body Color: WHITE       License no: DE8899       Model:2020   " << endl;
        cout << "" << endl;
        for (int i = 0; i < count5; i++)
        {
            if (cartypeA[i] == "sedan" || cartypeA[i] == "Sedan" || cartypeA[i] == "SEDAN")
            {
                cout << " " << 3 + 1 << "." << carnameA[i] << ":" << endl;
                cout << " " << endl;
                cout << "Body color: " << carcolorA[i] << "\t\t"
                     << "License no: " << carlicenseA[i] << "\t\t"
                     << "Model: " << carmodelA[i] << endl;
                cout << " " << endl;
            }
        }
        lines();
    }
    else if (option1 == 2)
    {
        // SUV TYPE
        header();
        lines();
        cout << "The cars available of the SUV type are:" << endl;
        cout << "" << endl;
        cout << " 1.HONDA B-RV: " << endl;
        cout << "" << endl;
        cout << "Body Color: WHITE       License no: DE8999       Model:2019   " << endl;
        cout << "" << endl;
        cout << " 2.KIA SPORTAGE:" << endl;
        cout << "" << endl;
        cout << "Body Color: WHITE       License no: LF8787       Model:2019   " << endl;
        cout << "" << endl;
        cout << " 3.HYUNDAI TUCSON:" << endl;
        cout << "" << endl;
        cout << "Body Color: WHITE       License no: DF1232       Model:2021   " << endl;
        cout << "" << endl;
        for (int i = 0; i < count5; i++)
        {
            if (cartypeA[i] == "SUV" || cartypeA[i] == "Suv" || cartypeA[i] == "suv")
            {
                cout << " " << 3 + 1 << "." << carnameA[i] << ":" << endl;
                cout << " " << endl;
                cout << "Body color: " << carcolorA[i] << "\t\t"
                     << "License no: " << carlicenseA[i] << "\t\t"
                     << "Model: " << carmodelA[i] << endl;
                cout << " " << endl;
            }
        }
        lines();
    }
    else if (option1 == 3)
    {
        // CONVERTIBLE TYPE
        header();
        lines();
        cout << "The cars available of the Convertible type are:" << endl;
        cout << "" << endl;
        cout << " 1.CHAMARO ZL1:" << endl;
        cout << "" << endl;
        cout << "Body Color: Yellow       License no: AA2000       Model:2016   " << endl;
        cout << "" << endl;
        cout << " 2.FORD MUSTANG:" << endl;
        cout << "" << endl;
        cout << "Body Color: RED       License no: BB3000       Model:2018   " << endl;
        cout << "" << endl;
        cout << " 3.PORSCHE 911:" << endl;
        cout << "" << endl;
        cout << "Body Color: BLACK       License no: CC4000       Model:2015   " << endl;
        cout << "" << endl;
        for (int i = 0; i < count5; i++)
        {
            if (cartypeA[i] == "Convertible" || cartypeA[i] == "CONVERTIBLE" || cartypeA[i] == "convertible")
            {
                cout << " " << 3 + 1 << "." << carnameA[i] << ":" << endl;
                cout << " " << endl;
                cout << "Body color: " << carcolorA[i] << "\t\t"
                     << "License no: " << carlicenseA[i] << "\t\t"
                     << "Model: " << carmodelA[i] << endl;
                cout << " " << endl;
            }
        }
        lines();
    }
    else if (option1 > 3 || option1 < 0)
    {
        header();
        lines();
        cout << "You entered wrong number.Please TRY AGAIN" << endl;
        lines();
    }
}

void registration()
{
    if (count1 < maxrecord)
    {
        string father, address, occupation, type, license;
        double id, phonenumber;
        int age;
        cout << "************** Customer Information *****************|" << endl;
        cout << "-----------------------------------------------------|" << endl;
        cout << "-----------------------------------------------------|" << endl;
        cout << "" << endl;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your Birth Year: ";
        cin >> age;
        cout << "Enter your National ID: ";
        cin >> id;
        cout << "Enter your Phone Number: ";
        cin >> phonenumber;
        cout << "Enter your father name: ";
        cin >> father;
        cout << "Enter your address: ";
        cin >> address;
        cout << "Enter your Occupation: ";
        cin >> occupation;
        cout << "Does user has a avalid driving license (Yes/No): ";
        cin >> license;
        while (license != "yes" && license != "no" && license != "YES" && license != "NO")
        {
            cout << "Please enter YES or NO" << endl;
            cout << "Does user has a avalid driving license (Yes/No): ";
            cin >> license;
        }
        if (license == "yes" || license == "YES")
        {
            lines();
            clearscreen();
            header();
            cout << "" << endl;
            cout << "CAR Selection: " << endl;
            lines();
            cout << "Select any of these Car types: " << endl;
            cout << "" << endl;
            cout << "Sedan Type:        1.Honda Civic    2.Toyota Corolla    3.Hyundai Elantra " << endl;
            cout << "" << endl;
            cout << "SUV Type:          1.Honda B-RV     2.KIA Sportage      3.Hyundai Tucson " << endl;
            cout << "" << endl;
            cout << "Convertible type:  1.Chamaro ZL-1   2.Ford Mustang      3.Porsche 911 " << endl;
            cout << "" << endl;

            cout << "Select the CAR TYPE: ";
            cin >> type;
            while (type != "Convertible" && type != "convertible" && type != "SUV" && type != "suv" && type != "Sedan" && type != "sedan")
            {
                cout << "Invalid cartype" << endl;
                cout << "Select the CAR TYPE: ";
                cin >> type;
            }
            if (type == "Sedan" || type == "sedan")
            {

                cout << "Enter the name of the CAR: ";
                cin >> car;
                while (car != "HondaCivic" && car != "hondacivic" && car != "ToyotaCorolla" && car != "toyotacorolla" && car != "HyundaiElantra" && car != "hyundaielantra")
                {
                    cout << "Invalid car name.TRY AGAIN." << endl;
                    cout << "Enter the name of the CAR: ";
                    cin >> car;
                }
                if (car == "HondaCivic" || car == "hondacivic")
                {

                    cout << "Daily Rent of this car= " << drent << endl;
                    cout << "Weekly Rent of this car= " << wrent << endl;
                }
                else if (car == "ToyotaCorolla" || car == "toyotacorolla")
                {

                    cout << "Daily Rent of this car= " << drent << endl;
                    cout << "Weekly Rent of this car= " << wrent << endl;
                }
                else if (car == "HyundaiElantra" || car == "hyundaielantra")
                {

                    cout << "Daily Rent of this car= " << drent << endl;
                    cout << "Weekly Rent of this car= " << wrent << endl;
                }
            }
            else if (type == "SUV" || type == "suv")
            {

                cout << "Enter the name of the CAR: ";
                cin >> car;
                while (car != "HondaB-RV" && car != "hondabrv" && car != "hondaB-RV" && car != "KIASportage" && car != "kiasportage" && car != "KIAsportage" && car != "HyundaiTucson" && car != "hyundaitucson")
                {
                    cout << "Invalid car name.TRY AGAIN." << endl;
                    cout << "Enter the name of the CAR: ";
                    cin >> car;
                }
                if (car == "HondaB-RV" || car == "hondabrv" || car == "hondaB-RV")
                {

                    cout << "Daily Rent of this car= " << drent1 << endl;
                    cout << "Weekly Rent of this car= " << wrent1 << endl;
                }
                else if (car == "KIASportage" || car == "kiasportage" || car == "KIAsportage")
                {

                    cout << "Daily Rent of this car= " << drent1 << endl;
                    cout << "Weekly Rent of this car= " << wrent1 << endl;
                }
                else if (car == "HyundaiTucson" || car == "hyundaitucson")
                {

                    cout << "Daily Rent of this car= " << drent1 << endl;
                    cout << "Weekly Rent of this car= " << wrent1 << endl;
                }
            }
            else if (type == "Convertible" || type == "convertible")
            {

                cout << "Enter the name of the CAR: ";
                cin >> car;
                while (car != "ChamaroZL-1" && car != "chamaroZL-1" && car != "chamarozl-1" && car != "FordMustang" && car != "fordmustang" && car != "Porsche911" && car != "porsche911")
                {
                    cout << "Invalid car name.TRY AGAIN." << endl;
                    cout << "Enter the name of the CAR: ";
                    cin >> car;
                }
                if (car == "ChamaroZL-1" || car == "chamaroZL-1" || car == "chamarozl-1")
                {

                    cout << "Daily Rent of this car= " << drent2 << endl;
                    cout << "Weekly Rent of this car= " << wrent2 << endl;
                }
                else if (car == "FordMustang" || car == "fordmustang")
                {

                    cout << "Daily Rent of this car= " << drent2 << endl;
                    cout << "Weekly Rent of this car= " << wrent2 << endl;
                }
                else if (car == "Porsche911" || car == "porsche911")
                {

                    cout << "Daily Rent of this car= " << drent2 << endl;
                    cout << "Weekly Rent of this car= " << wrent2 << endl;
                }
            }
        }
        if (license == "No" || license == "no" || license == "NO")
        {
            cout << "You are not eligible for registration..." << endl;
        }

        addregistration(name, age, id, phonenumber, father, address, occupation, license, type, car);
    }
    else
    {
        cout << "No more space to add customers..." << endl;
    }
}

void addregistration(string name, int age, double id, double phonenumber, string father, string address, string occupation, string license, string type, string car)
{
    if (count1 < maxrecord)
    {
        customernameA[count1] = name;
        customerageA[count1] = age;
        customeridA[count1] = id;
        customerphonenumberA[count1] = phonenumber;
        customerfatherA[count1] = father;
        customeraddressA[count1] = address;
        customeroccupationA[count1] = occupation;
        customerlicenseA[count1] = license;
        customertypeA[count1] = type;
        customercarA[count1] = car;
        count1 = count1 + 1;
    }
    else
    {
        cout << "No more space to register the users" << endl;
    }
}

void journeyinformation()
{
    string destination, car;
    int km;
    int starting = 0, ending = 0, days = 0;
    cout << "************** Journey Information ******************|" << endl;
    cout << "-----------------------------------------------------|" << endl;
    cout << "-----------------------------------------------------|" << endl;
    cout << "" << endl;
    cout << "Enter the pickup point: ";
    cin >> pickup;
    cout << "Enter Destination: ";
    cin >> destination;
    cout << "Enter the approximated kilometers= ";
    cin >> km;
    cout << "" << endl;
    cout << "NOTE: If your days are greater than 10,you will be given 15 percent discount on each car..." << endl;
    cout << "" << endl;
    cout << "Enter the starting date: ";
    cin >> starting;
    while (starting > 31 || starting < 0)
    {
        cout << "Invalid Date.Please write date betwwen 1-30" << endl;
        cout << "Enter the starting date: ";
        cin >> starting;
    }
    cout << "Enter the ending date: ";
    cin >> ending;
    while (ending > 31 || ending < 0)
    {
        cout << "Invalid Date.Please write date betwwen 1-30" << endl;
        cout << "Enter the ending date: ";
        cin >> ending;
    }
    if (starting > ending)
    {
        int d = 31 - starting;
        days = d + ending;
    }
    else
    {
        days = ending - starting;
    }
    cout << "Total days= " << days << endl;

    addjourneyinformation(pickup, destination, km, starting, ending, days);
}

void addjourneyinformation(string pickup, string destination, int km, int starting, int ending, int days)
{

    if (count2 < maxrecord)
    {
        pickupA[count2] = pickup;
        destinationA[count2] = destination;
        kmA[count2] = km;
        startingA[count2] = starting;
        endingA[count2] = ending;
        daysA[count2] = days;

        count2 = count2 + 1;
    }
    else
    {
        cout << "No more space to add journey information" << endl;
    }
}

void generatebill()
{
    int rent = 0, dis, payablerent;
    int l = 0, m = 0;
    header();
    cout << "***************** Customer Bill *********************|" << endl;
    cout << "-----------------------------------------------------|" << endl;
    cout << "-----------------------------------------------------|" << endl;
    cout << " " << endl;
    for (int i = 0; i < count1; i++)
    {
        if (customernameA[i] == name)
        {
            l = i;
        }
    }
    cout << "   Customer name: "
         << "\t\t\t" << customernameA[l] << endl;
    cout << "   Customer ID: "
         << "\t\t\t" << customeridA[l] << endl;
    cout << "   Customer Phone Number: "
         << "\t\t" << customerphonenumberA[l] << endl;
    cout << "   Customer Father Name: "
         << "\t\t" << customerfatherA[l] << endl;
    cout << "   Customer Address: "
         << "\t\t\t" << customeraddressA[l] << endl;
    for (int i = 0; i < count2; i++)
    {
        if (pickupA[i] == pickup)
        {
            m = i;
        }
    }
    cout << "   Customer Pickup: "
         << "\t\t\t" << pickupA[m] << endl;
    cout << "   Customer Destination: "
         << "\t\t" << destinationA[m] << endl;
    cout << "   Starting date: "
         << "\t\t\t" << startingA[m] << endl;
    cout << "   Ending date: "
         << "\t\t\t" << endingA[m] << endl;
    cout << "   Total days: "
         << "\t\t\t\t" << daysA[m] << endl;
    cout << "   Your Selected Car: "
         << "\t\t\t" << customercarA[l] << endl;

    if (customercarA[l] == "HondaCivic" || customercarA[l] == "hondacivic" || customercarA[l] == "ToyotaCorolla" || customercarA[l] == "toyotacorolla" || customercarA[l] == "HyundaiElantra" || customercarA[l] == "hyundaielantra")
    {

        rent = daysA[m] * drent;
        cout << "------------------------------------------------|" << endl;
        cout << "Total amount= " << rent << endl;
        cout << "------------------------------------------------|" << endl;
        if (daysA[m] >= 10)
        {
            dis = (rent * discount) / 100;
            rent = rent - dis;
            cout << "------------------------------------------------|" << endl;
            cout << "Your payable amount after discount= " << rent << endl;
            cout << "------------------------------------------------|" << endl;
        }
    }
    else if (customercarA[l] == "HondaB-RV" || customercarA[l] == "hondabrv" || customercarA[l] == "hondaB-RV" || customercarA[l] == "KIASportage" || customercarA[l] == "kiasportage" || customercarA[l] == "KIAsportage" || customercarA[l] == "HyundaiTucson" || customercarA[l] == "hyundaitucson")
    {

        rent = daysA[m] * drent1;
        cout << "------------------------------------------------|" << endl;
        cout << "Total Amount= " << rent << endl;
        cout << "------------------------------------------------|" << endl;
        if (daysA[m] >= 10)
        {
            dis = (rent * discount) / 100;
            rent = rent - dis;
            cout << "------------------------------------------------|" << endl;
            cout << "Your payable amount after discount= " << rent << endl;
            cout << "------------------------------------------------|" << endl;
        }
    }
    else if (customercarA[l] == "ChamaroZL-1" || customercarA[l] == "chamaroZL-1" || customercarA[l] == "chamarozl-1" || customercarA[l] == "FordMustang" || customercarA[l] == "fordmustang" || customercarA[l] == "Porsche911" || customercarA[l] == "porsche911")
    {
        rent = daysA[m] * drent2;
        cout << "   ------------------------------------------------|" << endl;
        cout << "   Total Amount= " << rent << endl;
        cout << "   ------------------------------------------------|" << endl;
        if (daysA[m] >= 10)
        {
            dis = (rent * discount) / 100;
            rent = rent - dis;
            cout << "   ------------------------------------------------|" << endl;
            cout << "   Your payable amount after discount= " << rent << endl;
            cout << "   ------------------------------------------------|" << endl;
        }
    }
    lines();
    storegeneratebill(rent);
}

void storegeneratebill(int rent)
{
    carrentA[count3] = rent;
    count3 = count3 + 1;
}

void transactiondetails()
{
    int option = 0;
    cout << "*************** Transaction details *****************|" << endl;
    cout << "-----------------------------------------------------|" << endl;
    cout << "-----------------------------------------------------|" << endl;
    cout << " " << endl;
    cout << "  Select any of the payment method: " << endl;
    cout << " " << endl;
    cout << "1.Credit Card: " << endl;
    cout << "2.Debit Cars: " << endl;
    cout << "3.Easypaisa: " << endl;
    cout << "4.Jazzcash: " << endl;
    lines();
    cout << "Enter your Option: " << endl;
    cin >> option;
    while (option > 4 || option < 0)
    {
        cout << "Invalid option. Please Try again" << endl;
        cout << "Enter your Option: " << endl;
        cin >> option;
    }
    clearscreen();
    if (option == 1 || option == 2 || option == 3 || option == 4)
    {
        header();
        int cvv, l, m;
        double number, date;
        string cname;
        lines();

        cout << "Enter your Name: ";
        cin >> cname;
        cout << "Enter the Card Number: ";
        cin >> number;
        cout << "Enter the expiry Year: ";
        cin >> date;
        cout << "Enter the CVV: ";
        cin >> cvv;

        lines();
        savetransactiondetail(cname, number, date, cvv);
        clearscreen();
        header();
        cout << " " << endl;
        cout << "**************** Customer Receipt *******************|" << endl;
        cout << "-----------------------------------------------------|" << endl;
        cout << "-----------------------------------------------------|" << endl;
        cout << " " << endl;

        for (int i = 0; i < count1; i++)
        {
            if (customernameA[i] == name)
            {
                l = i;
            }
        }
        for (int i = 0; i < count3; i++)
        {
            if (accountnumberA[i] == number)
            {
                m = i;
            }
        }
        cout << "   Customer name: " << cnameA[l] << endl;
        cout << "   Customer address: " << customeraddressA[l] << endl;
        cout << "   Customer cell number: " << customerphonenumberA[l] << endl;
        cout << "   Account Number: " << accountnumberA[m] << endl;
        cout << "   Card Expiry Date: " << carddateA[m] << endl;
        cout << "   Card CVV: " << cvvA[m] << endl;
        cout << "   ------------------------------------------------|" << endl;
        cout << "   Total Amount Paid = " << carrentA[l] << endl;
        cout << "   ------------------------------------------------|" << endl;
        lines();
    }
    else
    {
        header();
        cout << "You entered a wrong number...Please TRY AGAIN..." << endl;
    }
    
}

void savetransactiondetail(string cname, double number, double date, int cvv)
{
    if (count4 < maxrecord)
    {
        cnameA[count4] = cname;
        accountnumberA[count4] = number;
        carddateA[count4] = date;
        cvvA[count4] = cvv;

        count4 = count4 + 1;
    }
    else
    {
        cout << "No more space to add credentials" << endl;
    }
}

string addcar()
{
    string cartype, carname, carcolor, carlicense;
    int carmodel;
    cout << "****************** Add a New Car ********************|" << endl;

    lines();
    cout << "Enter the car type(sedan/SUV/Convertible): ";
    cin >> cartype;
    while (cartype != "sedan" && cartype != "Sedan" && cartype != "SEDAN" && cartype != "SUV" && cartype != "Suv" && cartype != "suv" && cartype != "convertible" && cartype != "Convertible" && cartype != "CONVERTIBLE")
    {
        cout << "You entered wrong car type.Please select from given cartypes..." << endl;
        cout << "1.Sedan            2.SUV             3.Convertible" << endl;
        cout << "Enter the car type: ";
        cin >> cartype;
    }
    if (cartype == "sedan" || cartype == "Sedan" || cartype == "SEDAN" || cartype == "SUV" || cartype == "Suv" || cartype == "suv" || cartype == "convertible" || cartype == "Convertible" || cartype == "CONVERTIBLE")
    {
        cout << "Enter the name of the car: ";
        cin >> carname;
        cout << "Enter the Car Body Color: ";
        cin >> carcolor;
        cout << "Enter the license number: ";
        cin >> carlicense;
        cout << "Enter the model: ";
        cin >> carmodel;
    }
    lines();
    storeaddcar(cartype, carname, carcolor, carlicense, carmodel);
    return cartype;
}

void storeaddcar(string cartype, string carname, string carcolor, string carlicense, int carmodel)
{

    if (count5 < maxrecord)
    {
        cartypeA[count5] = cartype;
        carnameA[count5] = carname;
        carcolorA[count5] = carcolor;
        carlicenseA[count5] = carlicense;
        carmodelA[count5] = carmodel;
        count5 = count5 + 1;
    }
}

void updatecardetails()
{
    {

        string type, updatecar;
        cout << "*************** Update Car Details: *****************|" << endl;

        lines();
        cout << "Enter the CAR Type: ";
        cin >> type;
        while (type != "sedan" && type != "Sedan" && type != "SEDAN" && type != "SUV" && type != "Suv" && type != "suv" && type != "convertible" && type != "Convertible" && type != "CONVERTIBLE")
        {
            cout << "You entered wrong car type.Please select from given cartypes..." << endl;
            cout << "1.Sedan            2.SUV             3.Convertible" << endl;
            cout << "Enter the car type: ";
            cin >> type;
        }
        cout << "Enter the name of CAR: ";
        cin >> updatecar;
        while (updatecar != "HondaCivic" && updatecar != "hondacivic" && updatecar != "ToyotaCorolla" && updatecar != "toyotacorolla" && updatecar != "HyundaiElantra" && updatecar != "hyundaielantra" && updatecar != "HondaB-RV" && updatecar != "hondabrv" && updatecar != "hondaB-RV" && updatecar != "KIASportage" && updatecar != "kiasportage" && updatecar != "KIAsportage" && updatecar != "HyundaiTucson" && updatecar != "hyundaitucson" && updatecar != "ChamaroZL-1" && updatecar != "chamaroZL-1" && updatecar != "chamarozl-1" && updatecar != "FordMustang" && updatecar != "fordmustang" && updatecar != "Porsche911" && updatecar != "porsche911")
        {
            cout << "You entered invalid name of car.Please try again." << endl;
            cout << "Enter the name of CAR: ";
            cin >> updatecar;
        }
        if (updatecar == "HondaCivic" || updatecar == "hondacivic" || updatecar == "ToyotaCorolla" || updatecar == "toyotacorolla" || updatecar == "HyundaiElantra" || updatecar == "hyundaielantra")
        {
            cout << "Change daily rent= ";
            cin >> drent;
            cout << "Change weekly rent= ";
            cin >> wrent;
        }
        else if (updatecar == "HondaB-RV" || updatecar == "hondabrv" || updatecar == "hondaB-RV" || updatecar == "KIASportage" || updatecar == "kiasportage" || updatecar == "KIAsportage" || updatecar == "HyundaiTucson" || updatecar == "hyundaitucson")
        {
            cout << "Change daily rent= ";
            cin >> drent1;
            cout << "Change weekly rent= ";
            cin >> wrent1;
        }
        else if (updatecar == "ChamaroZL-1" || updatecar == "chamaroZL-1" || updatecar == "chamarozl-1" || updatecar == "FordMustang" || updatecar == "fordmustang" || updatecar == "Porsche911" || updatecar == "porsche911")
        {
            cout << "Change daily rent= ";
            cin >> drent2;
            cout << "Change weekly rent= ";
            cin >> wrent2;
        }
        lines();
    }
}

void viewallrecords()
{
    
    int temp;

    cout << "**************** VIEW ALL RECORDS: ******************|" << endl;
    cout << "-----------------------------------------------------|" << endl;
    cout << "-----------------------------------------------------|" << endl;
    // cout << count1 << endl;
    cout << "" << endl;
    cout << "Name"
         << "\t\t"
         << "CNIC No"
         << "\t\t"
         << "Address"
         << "\t\t"
         << "Starting"
         << "\t\t"
         << "Ending"
         << "\t\t"
         << "Car"
         << "\t\t"
         << "Total Rent" << endl;
    for (int i = 0; i < count1; i++)
    {

        cout << customernameA[i] << "\t" << customeridA[i] << "\t\t" << customeraddressA[i] << "\t" << startingA[i] << "\t\t" << endingA[i] << "\t\t" << customercarA[i] << "\t\t" << carrentA[i] << endl;
    }

    lines();
    for(int i=0;i<count1;i++)
    {
        carrentdupA[i]=carrentA[i];
    }
    cout<<"Press 1 to print the record in merit order";
    cin>>opti;
    while(opti!='1')
    {
        cout<<"You entered inalid number"<<endl;
        cout<<"Press 1 to print the record in merit order";
        cin>>opti;
    }
    if(opti=='1')
    {system("cls");
    header();
    lines();
        cout << "Name"
         << "\t\t"
         << "CNIC No"
         << "\t\t"
         << "Address"
         << "\t\t"
         << "Starting"
         << "\t\t"
         << "Ending"
         << "\t\t"
         << "Car"
         << "\t\t"
         << "Total Rent" << endl;
         for(int i=0;i<count1;i++)
         {
            largest=sorting(i);
            temp=carrentdupA[largest];
            carrentdupA[largest]=carrentdupA[i];
            carrentdupA[i]=temp;
         }
         for(int i=0;i<count1;i++)
         {
            for(int j=0;j<count1;j++)
            {
                if(carrentdupA[i]==carrentA[j])
                {
                    cout << customernameA[j] << "\t" << customeridA[j] << "\t\t" << customeraddressA[j] << "\t" << startingA[j] << "\t\t" << endingA[j] << "\t\t" << customercarA[j] << "\t\t" << carrentA[j] << endl;
                }
            }
         }

         lines();

    }
    // sort();
}

int sorting(int n)
{
    
    int max = -1;
    int l = 0;
    for (int i = n; i < count1; i++)
    {
        if (carrentdupA[i] > max)
        {
            max = carrentdupA[i];
            l = i;
        }
    }
    return l;
}

// void sort()
// {
//     int c=0;
    
//     int l=0,temp=carrentA[0];
//     for(int i=0;i<count1;i++)
//     {
//         l=sorting(i);
//             temp=carrentdupA[l];
//             carrentdupA[l]=carrentdupA[i];
//             carrentdupA[i]=temp;

//         c++;
//     }
//     for(int i=0;i<c;i++)
//     {
//         cout<<carrentdupA[i]<<",";
//     }
// }

void adddiscount()
{

    cout << "*************** Add Discount Offers: ****************|" << endl;
    cout << "-----------------------------------------------------|" << endl;
    cout << "-----------------------------------------------------|" << endl;
    cout << "" << endl;
    cout << "Enter the percentage of discount: ";
    cin >> discount;
    while(discount>100 || discount<0)
    {
        cout<<"You entered invalid percentage."<<endl;
        cout << "Enter the percentage of discount: ";
        cin >> discount;
    }
    cout << "You have successfully added a discount.";
    lines();
}

void companypolicy()
{
    header();
    cout << "*************** View Company Policy *****************|" << endl;
    lines();
    cout << "Use of Personal Information:" << endl;
    cout << "We use your personal information for various purposes described below, which depend on the site you visit or the app you use." << endl;

    cout << "Your Use of Online Sites, Apps, and Services:" << endl;

    cout << "Book the requested travel or enable vacation property booking" << endl;
    cout << "Provide services related to the booking and/or account" << endl;
    cout << "Create, maintain, and update user accounts on our platform and authenticate you as a user" << endl;
    cout << "Maintain your search and travel history, accommodation and travel preferences, and similar information about your use of Expedia Group platform and services, and as otherwise described in this Privacy Statement" << endl;
    cout << "Enable and facilitate acceptance and processing of payments, coupons, and other transactions" << endl;
    cout << "Administer loyalty and rewards programs" << endl;
    cout << "Collect and enable booking-related reviews" << endl;
    cout << "Help you to use our services faster and easier through features like the ability to sign-in using your account within the online services and sites of some of the Expedia Group companies" << endl;
    cout << "Communications and Marketing:" << endl;
    cout << "Respond to your questions, requests for information, and process information choices" << endl;
    cout << "Enable communication between you and the travel supplier like hotels and vacation property owners" << endl;
    lines();
}

void viewbookings()
{
    header();
    cout << "****************** View Bookings ********************|" << endl;
    lines();
    if (loginusername != " ")
    {
        for (int i = 0; i < count1; i++)
        {
            if (customernameA[i] == loginusername)
            {
                cout << "Your name: " << customernameA[i] << endl;
                cout << "Your ID: " << customeridA[i] << endl;
                cout << "Your phone number: " << customerphonenumberA[i] << endl;
                cout << "Your address: " << customeraddressA[i] << endl;
                cout << "Your selected car: " << customercarA[i] << endl;
                cout << "Your total rent: " << carrentA[i] << endl;
            }
        }
    }
    else if(loginusername==" ")
    {
        cout << "No bookings yet..." << endl;
    }
    lines();
}

void editprofiledetails()
{
    header();
    cout << "*************** Edit Profile Details ****************|" << endl;
    lines();
    if (loginusername != " ")
    {
        for (int i = 0; i < count1; i++)
        {
            if (customernameA[i] == loginusername)
            {
                cout << "Enter the new username: ";
                cin >> usernameA[i];
                cout << "Enter the new password: ";
                cin >> passwordA[i];
            }
        }
    }
    else if(loginusername==" ")
    {
        cout<<"No bookings yet."<<endl;
    }
    lines();
}

void storebillinformation()
{
    int idx = 0;
    fstream cfile;
    cfile.open("billinfo.txt", ios::out);
    while (idx < count4)
    {
        string row = cnameA[idx] + " "+ to_string(accountnumberA[idx]) + " " +to_string(carddateA[idx]) + " "+ to_string(cvvA[idx]) + " " + to_string(carrentA[idx]);

        cfile <<row << endl;
        idx++;
    }
    cfile.close();
}

void storelogindetails()
{
    int idx = 0;
    fstream afile;
    afile.open("logindetails.txt", ios::out);
    while (idx < count)
    {
        string row= usernameA[idx] + ","+ passwordA[idx] + ","+ roleA[idx];
        afile<<row << endl;

        idx++;
    }
    afile.close();
}

string parserecord(string line, int field)
{
    int commacount = 1;
    string item;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            commacount++;
        }
        if (commacount == field)
        {
            if (line[i] != ',')
            {
                item = item + line[i];
            }
        }
    }
    return item;
}

void loadbillinformation()
{
    string line;
    int idx = 0;
    fstream afile;
    afile.open("billinfo.txt", ios::in);
    string row;
    afile>>row;
    while (!(afile.eof()))
    {
    
        // cout << accountnumberA[idx]<<endl;
        afile >> cnameA[idx];
        afile >> accountnumberA[idx];
        afile >> carddateA[idx];
        afile >> cvvA[idx];
        afile >> carrentA[idx];
        // cout<<parserecord(line,2)<<"/""";
        // cout<<parserecord(line,3)<<"/""";
        // cout<<parserecord(line,4)<<"/""";
        // cnameA[idx] = parserecord(line, 1);
        // accountnumberA[idx] = stoi(parserecord(line, 2));
        // carddateA[idx] = stoi(parserecord(line, 3));
        // cvvA[idx] = stoi(parserecord(line, 4));
        // carrentA[idx] = stoi(parserecord(line, 5));

        idx++;
        count4++;
    }
}

void loadlogininformation()
{
    string line;
    int idx = 0;
    fstream afile;
    afile.open("logindetails.txt", ios::in);
    
    while (!(afile.eof()))
    {
        getline(afile, line);
        // cout<<parserecord(line,1)<<"/""";
        // cout<<parserecord(line,2)<<"/""";
        usernameA[idx] = parserecord(line, 1);
        passwordA[idx] = parserecord(line, 2);
        roleA[idx] = parserecord(line, 3);

        idx++;
        count++;
        
    }
    afile.close();
}

void storedataregistration()
{
    int idx = 0;

    fstream afile;
    afile.open("registrationdata.txt", ios::out);
    {

        while (idx < count1)
        {
            string row = customernameA[idx] + " " + to_string(customerageA[idx]) + " " + to_string(customeridA[idx]) + " " + to_string(customerphonenumberA[idx]) + " " + customerfatherA[idx] + " " + customeraddressA[idx] + " " + customeroccupationA[idx] + " " + customerlicenseA[idx] + " " + customertypeA[idx] + " " + customercarA[idx];
            afile << row << endl;
            // cout << "---------------" << idx << endl;
            idx++;
        }
    }
    afile.close();
}
void loaddataregistration()
{
    int idx = 0;
    fstream afile;
    afile.open("registrationdata.txt", ios::in);

    string row;
    afile >> row;
    while (!afile.eof())
    {

        afile >> customernameA[idx];
        afile >> customerageA[idx];
        afile >> customeridA[idx];
        afile >> customerphonenumberA[idx];
        afile >> customerfatherA[idx];
        afile >> customeraddressA[idx];
        afile >> customeroccupationA[idx];
        afile >> customerlicenseA[idx];
        afile >> customertypeA[idx];
        afile >> customercarA[idx];
        // cout << "This is running-------------";
        count1++;

        idx++;
    }

    afile.close();
}

void storejourneyinformation()
{
    int idx = 0;
    fstream afile;
    afile.open("journeyinformation.txt", ios::out);

    while (idx < count2)
    {
        string row=  pickupA[idx] + " " +destinationA[idx]+ " "+ to_string(kmA[idx])+ " "+ to_string(startingA[idx])+  " " + to_string(endingA[idx])+  " " + to_string(daysA[idx]) ;
        afile<<row<<endl;
        idx++;
    }

    afile.close();
}
void loadjourneyinformation()
{
    int idx = 0;
    fstream afile;
    afile.open("journeyinformation.txt", ios::in);
    string row;
    afile>>row;
    while (!afile.eof())
    {
        afile >> pickupA[idx];
        afile >> destinationA[idx];
        afile >> kmA[idx];
        afile >> startingA[idx];
        afile >> endingA[idx];
        afile >> daysA[idx];

        idx++;
        count2++;
    }
}
// --------------END OF FUNCTIONS-------------------