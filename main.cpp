/************************************CAR RENTAL MANAGEMENT SYSYTEM************************/

/***************************************HEADER FILES**************************************/
#include<bits/stdc++.h>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<dos.h>
#define lux 1000
#define nonlux 100
using namespace std;
/****************************************************************************************/

/*************INPUT IN GRAPH FROM FILE AND FLOYYD WARSHALL ALGORITHM**********************/


vector<vector<int> > places,places2;
vector<vector<int> > dis,distt;




  void readfile()
    {
   string line;
   ifstream graph;
   string filename="city1.txt";

   graph.open(filename);

   if(!graph)
   {
       cout<<"unable to open file";

   }
   else
   {
      while(getline(graph,line))
      {
          vector<int> v1;
          stringstream linestream(line);
          int value;
          while(linestream >> value)
          {
              v1.push_back(value);
          }

          places.push_back(v1);
      }
       graph.close();
   }
   }

 void readfile2()
    {
   string line;
   ifstream graph;
   string filename="city2.txt";

   graph.open(filename);

   if(!graph)
   {
       cout<<"unable to open file";

   }
   else
   {
      while(getline(graph,line))
      {
          vector<int> v1;
          stringstream linestream(line);
          int value;
          while(linestream >> value)
          {
              v1.push_back(value);
          }
          places2.push_back(v1);
      }
       graph.close();
   }
   }


void wfi(vector<vector<int> >shortestPathArr)
{


    //vector<vector<int>> dis;


        dis.insert(dis.end(),shortestPathArr.begin(),shortestPathArr.end());  // copy shortestPathArr in the 2d vector dis
        for(int k=0;k<10;k++)
        {
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if((dis[i][j]>(dis[i][k]+ dis[k][j])) && (dis[k][j]!=99999) && (dis[i][k]!=99999))
                {
                    dis[i][j]=(dis[i][k]+ dis[k][j]);
                }
            }
        }
    }

}


void wfi2(vector<vector<int> >shortestPathArr)
{
        distt.insert(distt.end(),shortestPathArr.begin(),shortestPathArr.end());  // copy shortestPathArr in the 2d vector dis
        for(int k=0;k<10;k++)
        {
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if((distt[i][j]>(distt[i][k]+ distt[k][j])) && (distt[k][j]!=99999) && (distt[i][k]!=99999))
                {
                    distt[i][j]=(distt[i][k]+ distt[k][j]);
                }
            }
        }
    }
}

/***************************************************************************************************************/

/*******************************************CLASSES*************************************************************/




class carrent
{
private:
    char name[30];
    char address[80];                               //private data members
    int no_of_days;
    char cartype[30];
    int carno;
    double rent;

public:
    void getdata1();                                // public member function
    void getdata2();
    void showdata();
    void luxury();
    void cars();
    void nonluxury();
    void insertdata();
    void deletedata();
    void searchcar();
    void viewall();
    int retcar();
};

int carrent::retcar()
{
    return carno;
}

/**************************************************************************************************/
/**********************************FUNCTION DECLARATION AND PROTOTYPE ********************************************/

void thanku();
void admin();           //FUNCTION PROTOTYPE
void User();



void admin_user()
{
    system("cls");
    char ch;
    cout << "\n\t\tEnter Your Choice (A,B,C)" << endl
         << endl
         << endl;
    Beep(0,200);
    cout << "\n\t\t\t(A).ADMIN" << endl
         << endl;
    Beep(0,200);
    cout << "\n\t\t\t(B).USER" << endl
         << endl;
    Beep(0,200);
    cout << "\n\t\t\t(C).EXIT" << endl
         << endl;
    cout<<"\n\t\t\tYour choice: ";
    cin>>ch;
    switch (ch)
    {
        case 'A':
            admin();
            break;
        case 'B': User();
        break;
        case 'C':
        thanku();
        exit(1000);
    }

}

void admin()
{
    carrent d;
    char username[100],password[100];
    system("cls");
    cout<<"\n\t\t\t\tWELCOME TO THE ADMIN SECTION"<<endl<<endl;
    cout<<"\nDEFAULT USERNAME: ADMIN PASSWORD: PASSWORD"<<endl<<endl;
    cout<<"\tUsername: ";
    cin>>username;
     cin.sync();
      cin.sync();
    cout<<endl;
    cout<<"\tPassword: ";
    gets(password);
     cin.sync();
    if(!((strcmp(username,"ADMIN")==0) && (strcmp(password,"PASSWORD")==0)))
    {
        cout<<"WRONG USERNAME OR PASSWORD!!!!!!";
        exit(100);
    }
    else
    {
        system("cls");
        char ch;
        cout << "\n\n\tEnter Your Choice (A,B,C)" << endl
             << endl
             << endl;
        cout << "\n\t\t(A).Search A Record" << endl
             << endl;
        cout << "\n\t\t(B).ALL RECORDS" << endl
             << endl;
        cout << "\n\t\t(C).EXIT" << endl
             << endl;
        cout<<"\n\t\tYour choice : ";
    cin>>ch;
    switch (ch)
    {
        case 'A':
            d.searchcar();
            break;
        case 'B':
                d.viewall();
                break;
        case 'C':
            thanku();
            exit(1000);
    }

    }
}

int sd=0;
int trip=0;

void User()
{
    system("cls");
    carrent c;
    char ch;
    cout << "\n\n\tEnter Your Choice (A,B,C,D)" << endl
         << endl
         << endl;
    Beep(0,200);
    cout << "\n\t\t(A).Rent for Self Drive" << endl
         << endl;
    Beep(0,200);
    cout << "\n\t\t(B).Rent a Ride" << endl
         << endl;
    Beep(0,200);
    cout << "\n\t\t(C).Booking Details" << endl
         << endl;
    Beep(0,200);
    cout << "\n\t\t(D).Cancel Reservation " << endl
         << endl;
    Beep(0,200);
    cout << "\n\t\t(E).Exit " << endl
         << endl;
    cout<<"\n\t\tYour choice: ";
    cin >> ch;
    switch (ch)
    {
    case 'A':
        sd=1;
        c.cars();
        break;
    case 'B':
        trip=1;
       c.cars();
        break;
    case 'C':
        c.searchcar();
        break;
    case 'D':
        c.deletedata();
        break;
    case 'E':
        thanku();
        exit(1000);
    default:
        cout << "\nInvalid Input";
    }
}

void carrent::viewall()
{
    carrent d;
    ifstream f;
    f.open("CAR_RENT.DAT",ios::in|ios::binary);
    if(!f)
    {
        cout<<"FILE IS NOT OPEN!!!!!!"<<endl;
    }
    else
    {
        f.read((char *)&d,sizeof(d));
        while(!f.eof()){
            d.showdata();
            system("pause");
            f.read((char *)&d,sizeof(d));
        }
        f.close();
    }

}

void carrent::getdata1()
{
    int fare = 1500;
    cout << "\n\t\t\t\tCAR RENTAL SERVICE" << endl
         << endl
         << endl;
    cout << "\n\nINFORMATION OF CUSTOMER" << endl
         << endl;
    cout << "\n\t Name of the person     ";
    cin.sync();
    gets(name);
    cout << endl;
    cout << "\n\t Address                ";
    gets(address);
    cout << endl;
    cout << "\n\t Hire for days          ";
    cin >> no_of_days;
    cout << endl;
    cout << "\n\t Car number             ";
    cin >> carno;
    cout << endl;
    cout << "\n\t Car type(type luxury/nonluxury)         ";
    cin.sync();
    gets(cartype);
    cout << endl
         << endl;
    cout<<"********************************************************"<<endl;



    if (strcmp(cartype, "luxury") == 0)
    {

        rent = (fare + no_of_days * 3000);
        cout << "\n\n\tTotal Rent   "
             << "Rs " << rent << endl;
    }

    else if (strcmp(cartype, "nonluxury") == 0)
    {
        rent = (fare + no_of_days * 1500);
        cout << "\n\n\tTotal Rent   "
             << "Rs " << rent << endl;
    }

    cout << "\n\tRent : " << rent << endl;

    getch();
}


void carrent::getdata2()
{
    cout << "\n\t\t\t\tCAR RENTAL SERVICE" << endl
         << endl
         << endl;
    cout << "\n\nINFORMATION OF CUSTOMER" << endl
         << endl;
    cout << "\n\t Name of the person     ";
    cin.sync();
    gets(name);
    cout << endl;
    cout << "\n\t Address                ";
    gets(address);
    cout << endl;
    no_of_days=0;
    cout << "\n\t Car number             ";
    cin >> carno;
    cout << endl;
    cout << "\n\t Car type(type luxury/nonluxury)         ";
    cin.sync();
    gets(cartype);
    cout << endl
         << endl;
    int city;
    cout<<"\t\t\tWE are Currently Operating in Mumbai AND Delhi"<<endl;

    cout<<"\n\t\t\tPlease select your city(press 0 for Mumbai and press 1 for Delhi) : ";
    cin>>city;
    if(city==0)
    {
     int source,destination;

    cout<<"\n\t\t\t0.Marine Drive  1.Bandra  3.GateWay of India  4.Dadra"<<endl;
    cout<<"\t\t\t5.Meera Road  6.Juhu  7.Mud Island  8.Film City  9.Navi Mumbai"<<endl<<endl;
    cout<<"\t\t\tStarting Point: ";
    cin>>source;
    cout<<"\t\t\tEnd Point: ";
    cin>>destination;
    readfile();
    wfi(places);

    if (strcmp(cartype, "luxury") == 0)
    {

        int dist=dis[source][destination];

        rent = (lux + dist*lux);
        cout<<"\n\t\t\t**************************************************************************"<<endl;
        cout<<"\n\t\t\tDistance for the shortest route: "<<dist<<" km"<<endl;
        cout << "\n\n\t\t\tEstimated Fare   "
             << "Rs " << rent << endl;
    }

    else if (strcmp(cartype, "nonluxury") == 0)
    {
        int dist=dis[source][destination];
        cout<<"\n\t\t\t**************************************************************************"<<endl;
        cout<<"\n\t\t\tDistance for the shortest route: "<<dist<<" km"<<endl;
        rent = (nonlux + dist*nonlux);
        cout << "\n\n\t\t\tEstimated Fare   "
             << "Rs " << rent << endl;
    }
    }

    else if(city==1)
    {
          int source,destination;

    cout<<"\n\t\t\t0.Rajiv Chowk  1.NDLS RAILWAY STATION  3.KAROL BAGH  4.SAROGINI MARKET"<<endl;
    cout<<"\t\t\t5.INDIA GATE  6.JHANDEWALAN  7.RAJOURI GARDEN  8.DWARKA SEC 10  9.AIRPORT"<<endl<<endl;
    cout<<"\t\t\tStarting Point: ";
    cin>>source;
    cout<<"\t\t\tEnd Point: ";
    cin>>destination;
    readfile2();
    wfi2(places2);

    if (strcmp(cartype, "luxury") == 0)
    {


        int dist=distt[source][destination];

        rent = (lux + dist*lux);
        cout<<"\n\t\t\t**************************************************************************"<<endl;
        cout<<"\n\t\t\tDistance for the shortest route: "<<dist<<" km"<<endl;
        cout << "\n\n\t\t\tEstimated Fare   "
             << "Rs " << rent << endl;
    }

    else if (strcmp(cartype, "nonluxury") == 0)
    {
        int dist=distt[source][destination];
        rent = (nonlux + dist*nonlux);
        cout<<"\n\t\t\t**************************************************************************"<<endl;
        cout<<"\n\t\t\tDistance for the shortest route: "<<dist<<" km"<<endl;
        cout <<"\n\n\t\t\tEstimated Fare   "
             << "Rs " << rent << endl;
    }
    }
getch();
}





void carrent::showdata()
{
    system("cls");
    cout << "\n\nINFORMATION OF CUSTOMER" << endl
         << endl;
    cout << "\n\t Name of the person     ";
    cout << name;
    cout << endl;
    cout << "\n\t Address    ";
    cout << address;
    cout << endl;
    cout << "\n\t Hire for days     ";
    cout << no_of_days;
    cout << endl;
    cout << "\n\t Car number       ";
    cout << carno;
    cout << endl;
    cout << "\n\t Car type         ";
    cout << cartype;
    cout << endl
         << endl;
    cout << "\n\t Rent of the car   ";
    cout << rent;
    cout << endl
         << endl;

}
/************************************INTRODUCTION FUNCTION*************************************************/

void intro()
{
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(h,14);
    cout << "\n\t\t\t \tJAYPEE INSTITUTE OF INFORMATION TECHNOLOGY NOIDA" << endl
         << endl
         << endl;
    Beep(0,1000);
              cout << "\n\n\n";
    cout << "\t\t\t\t * * *  **** *      ****  ***   ***   ****   " << endl;
    Beep(0,300);
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *        "<< endl;
    Beep(0,300);
    cout << "\t\t\t\t * * * ***** *     *     *   * * * * *****    " << endl;
    Beep(0,300);
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *         " << endl;
    Beep(0,300);
    cout << "\t\t\t\t  ***   **** *****  ****  ***  * * *  ****     " << endl;
    cout<<endl;
    Beep(0,300);
    cout<<"\t\t\t\t======================================="<<endl;
    cout<<"\t\t\t\t THIS IS CAR RENTAL MANAGEMENT SYSTEM"<<endl;
    cout<<"\t\t\t\t======================================="<<endl;
    cout << "\n\t\t\t\t\t THANKS FOR CHOOSING US" << endl
         << endl
         << endl;
    cout << "\n\t\t\t\t\t\tMADE BY" << endl;
    cout<<"\t\t\t\t----------------------------------------"<<endl;
    cout << "\t\t\t\t |  ENROLLMENT          NAME           |" << endl;
    cout << "\n\t\t\t\t |  19102147            ARYAN PANDEY   |" << endl;
    cout << "\n\t\t\t\t |  19102146            PRATEEK SHARMA |" << endl;
    cout << "\n\t\t\t\t |  19102124            SHRUTI SHARMA  |" << endl;
    cout << "\n\t\t\t\t |  19102126            ASBHISHEK ROY  |" << endl;
    cout<<"\t\t\t\t----------------------------------------"<<endl;

    cout << "\n\t\t\t\t 5th SEMESTER DSA LAB PROJECT" << endl;
    cout << "\n\t\t\t\t BRANCH - ECE" << endl;
     cout << "\n\t\t\t\t BATCH - A5" << endl

         << endl;
    cout << "\n\t\t\t\t NOTE: THIS PROGRAM IS CASE SENSITIVE!!!!!!" << endl;
}
/**********************************************************************************************************************************/

void mercedes()
{
    char ch;
    cout << "\n\t\t\t\t CAR RENTAL SERVICE" << endl
         << endl
         << endl;
    cout << "\n\tDESCRIPTION" << endl;
    cout << "\n\tCar type - LUXURY";
    cout << "\n\tCar color - BLACK";
    cout << "\n\tMileage - 15 kmpl";
    cout << "\n\tMax speed - 250 km/h" << endl
         << endl
         << endl;
    cout << "\n\nDo you want to  CONTINUE.....(Y) ";
    cin >> ch;
    system("cls");
}

void BMW()
{
    char ch;
    cout << "\n\t\t\t\t CAR RENTAL SERVICE" << endl
         << endl
         << endl;
    cout << "\n\tDESCRIPTION" << endl;
    cout << "\n\tCar type - LUXURY";
    cout << "\n\tCar color - GRAY";
    cout << "\n\tMileage - 17kmpl";
    cout << "\n\tMax speed - 260 km/h" << endl
         << endl
         << endl;
    cout << "\n\nDo you want to  CONTINUE.....(Y) ";
    cin >> ch;
    system("cls");
}

void AUDI()
{
    char ch;
    cout << "\n\t\t\t\t CAR RENTAL SERVICE" << endl
         << endl
         << endl;
    cout << "\n\tDESCRIPTION" << endl;
    cout << "\n\tCar type - LUXURY";
    cout << "\n\tCar color - YELLOW";
    cout << "\n\tMileage - 12 kmpl";
    cout << "\n\tMax speed - 280 km/h" << endl
         << endl
         << endl;
    cout << "\n\nDo you want to  CONTINUE.....(Y) ";
    cin >> ch;
    system("cls");
}

void suzuki()
{
    char ch;
    cout << "\n\t\t\t\t CAR RENTAL SERVICE" << endl
         << endl
         << endl;
    cout << "\n\tDESCRIPTION" << endl;
    cout << "\n\tCar type - NON LUXURY";
    cout << "\n\tCar color - RED";
    cout << "\n\tMileage - 25 kmpl";
    cout << "\n\tMax speed - 200 km/h" << endl
         << endl
         << endl;
    cout << "\n\nDo you want to  CONTINUE.....(Y) ";
    cin >> ch;
    system("cls");
}

void innova()
{
    char ch;
    cout << "\n\t\t\t\t CAR RENTAL SERVICE" << endl
         << endl
         << endl;
    cout << "\n\tDESCRIPTION" << endl;
    cout << "\n\tCar type - NON LUXURY";
    cout << "\n\tCar color - WHITE";
    cout << "\n\tMileage - 17 kmpl";
    cout << "\n\tMax speed - 180 km/h" << endl
         << endl
         << endl;
    cout << "\n\nDo you want to  CONTINUE.....(Y) ";
    cin >> ch;
    system("cls");
}

void tatasumo()
{
    char ch;
    cout << "\n\t\t\t\t CAR RENTAL SERVICE" << endl
         << endl
         << endl;
    cout << "\n\tDESCRIPTION" << endl;
    cout << "\n\tCar type - NON LUXURY";
    cout << "\n\tCar color - BLUE";
    cout << "\n\tMileage - 15 kmpl";
    cout << "\n\tMax speed - 200 km/h" << endl
         << endl
         << endl;
    cout << "\n\nDo you want to  CONTINUE.....(Y) ";
    cin >> ch;
    system("cls");
}

void renault()
{
    char ch;
    cout << "\n\t\t\t\t CAR RENTAL SERVICE" << endl
         << endl
         << endl;
    cout << "\n\tDESCRIPTION" << endl;
    cout << "\n\tCar type NON LUXURY";
    cout << "\n\tCar color - GOLD";
    cout << "\n\tMileage - 10 kmpl";
    cout << "\n\tMax speed - 220 km/h" << endl
         << endl
         << endl;
    cout << "\n\nDo you want to  CONTINUE.....(Y) ";
    cin >> ch;
    system("cls");
}

void carrent::luxury()
{
    char ch;
    cout << "\n\t\t\t\t CAR RENTAL SERVICE" << endl
         << endl
         << endl;
    cout << "\n\t\t\tCARS AVAILABLE" << endl
         << endl;
    cout << "\n\t(A).Mercedes Benz" << endl
         << endl;
    cout << "\n\t(B).BMW" << endl
         << endl;
    cout << "\n\t(C).AUDI" << endl
         << endl;
    cout << "\n\t\tSelect the car you want to hire (A,B,C)   ";
    cin >> ch;
    system("cls");
    switch (ch)
    {
    case 'A':
        mercedes();
        insertdata();
        break;
    case 'B':
        BMW();
        insertdata();

        break;
    case 'C':
        AUDI();
        insertdata();
        break;
    default:
        cout << "\nInvalid Input";
    }
    getch();
}

void carrent::nonluxury()
{
    char ch;
    cout << "\n\t\t\t\t CAR RENTAL SERVICE" << endl
         << endl
         << endl;
    cout << "\n\t\t\tCARS AVAILABLE" << endl
         << endl;
    cout << "\n\t(A).SUZUKI Dezire" << endl
         << endl;
    cout << "\n\t(B).Innova" << endl
         << endl;
    cout << "\n\t(C).TATA Sumo" << endl
         << endl;
    cout << "\n\t(D).RENAULT Duster" << endl
         << endl;
    cout << "\n\t\tSelect the car you want to hire (A,B,C,D)    ";
    cin >> ch;
    system("cls");

    switch (ch)
    {
    case 'A':
        suzuki();
        insertdata();
        break;
    case 'B':
        innova();
        insertdata();

        break;
    case 'C':
        tatasumo();
        insertdata();
        break;
    case 'D':
        renault();
        insertdata();
        break;
    default:
        cout << "\nInvalid Input";
    }
    getch();
}

void carrent::cars()
{
    char ch;
    system("cls");
    cout << "\n\t\t\t\t CAR RENTAL SERVICE" << endl
         << endl
         << endl;
    cout << "\n\t\t\tTYPE OF CAR" << endl
         << endl;
    cout << "\n\t(A).LUXURY" << endl
         << endl;
    cout << "\n\t(B).NON-LUXURY" << endl
         << endl
         << endl;
    cout << "\n\t Select your option (A-B)"
         << "   ";
    cin >> ch;
    system("cls");
    switch (ch)
    {
    case 'A':
        if (ch == 65)
            luxury();
        break;
    case 'B':
        if (ch == 66)
            nonluxury();
        break;
    default:
        cout << "\nInvalid Input";
    }
    getch();
}

void carrent::insertdata()
{
    fstream f;
    f.open("CAR_RENT.dat",ios::in|ios::out|ios::binary|ios::app);
    char ans = 'y';
    carrent d;
    if(sd==1){
    d.getdata1();}
    else if(trip==1)
    {
        d.getdata2();
    }
        f.write((char*)&d,sizeof(d));

    f.close();
}

void carrent::searchcar()
{
    system("cls");
    ifstream i("CAR_RENT.DAT", ios::in | ios::binary);
    int ch;
    cout << "\n\tEnter the car number of the car";
    cin >> ch;
    carrent h;

    while (!i.eof())
    {
        i.read((char *)&h, sizeof(h));
        if (ch == h.retcar())
            h.showdata();
    }
    i.close();
    getch();
}

void carrent::deletedata()
{
    system("cls");
    char ch;
    cout << "\n\tEnter the car number of the car";
    cin >> ch;
    carrent h, j;
    ifstream i("CAR_RENT.DAT", ios::in | ios::binary);
    ofstream o("NEW_RENT.DAT", ios::out | ios::binary);
    i.read((char *)&h, sizeof(h));
    while (!i.eof())
    {
        if (ch != h.retcar())
            o.write((char *)&j, sizeof(j));
        cout << "data deleted successfully" << endl;

        break;
    }
    i.close();
    o.close();
    remove("CAR_RENT.DAT");
    rename("NEW_RENT.DAT", "CAR_RENT.DAT");
}


void thanku()
{
    system("cls");
    cout << endl
         << endl;
    cout<<"\n\n\n\n"<<endl;
    cout << "\t\t\t\tTTTTTTTTTT  HH   HH       AA       NNNN      NN  KK   KK     SSSSSSSS     " << endl;
    Beep(0,500);
    cout << "\t\t\t\t    TT      HH   HH      AAAA      NN NN     NN  KK  KK      SS            " << endl;
    Beep(0,500);
    cout << "\t\t\t\t    TT      HH   HH     AA  AA     NN  NN    NN  KK KK       SS             " << endl;
    Beep(0,500);
    cout << "\t\t\t\t    TT      HHHHHHH    AA AA AA    NN   NN   NN  KKK         SSSSSSSS                " << endl;
    Beep(0,500);
    cout << "\t\t\t\t    TT      HH   HH   AA      AA   NN    NN  NN  KK KK             SS          " << endl;
    Beep(0,500);
    cout << "\t\t\t\t    TT      HH   HH  AA        AA  NN     NN NN  KK  KK            SS            " << endl;
    Beep(0,500);
    cout << "\t\t\t\t    TT      HH   HH AA          AA NN      NNNN  KK    KK    SSSSSSSS                  " << endl;
    getch();
}


/*********************************************MAIN FUNCTION*******************************************/
int main()
{
    system("cls");
    carrent c;

    intro();
    char ans;
    cout << "\n\nDo you want to  CONTINUE.....(Y) ";
    cin >> ans;
    if (ans == 89)
    {
        system("cls");
        admin_user();
    }
    return 0;
    exit(1);
    getch();
}


