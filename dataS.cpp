#include<iostream>
using namespace std;

struct Data
{
    string vNum;
    string tNum;
    string date;
    string type;
};

class TollDataStorage
{
    int lastIndex = -1;
    int size = 2;
    Data *storage = new Data[size];
    public:
    void insertData(Data d)
    {
        if(lastIndex == size-1)
        {
            size++;
            lastIndex++;
            storage[lastIndex] = d;
        }
        else
        {
            lastIndex++;
            storage[lastIndex] = d;
        }
    }

    void searchInfo(string vN)
    {
        bool flag = false;
        for(int i=0; i<size; i++)
        {
            if(storage[i].vNum == vN)
            {
                cout << "Vehicle Number: " << storage[i].vNum << endl;
                cout << "Date: " << storage[i].date << endl;
                cout << "Ticket Number: " << storage[i].tNum << endl;
                flag = true;
            }
        }
        if(!flag)
        {
            cout << "Vehicle with number: " << vN << " not found" << endl;
        }
    }

    void perticularTypeIncome(string dt, string tp)
    {
        int income = 0;
        for(int i=0; i<size; i++)
        {
            if(storage[i].date == dt && storage[i].type == tp)
            {
                if(storage[i].type == "Heavy-duty")
                {
                    income = income+800;
                }
                else if(storage[i].type == "Medium-duty")
                {
                    income = income+500;
                }
                else if(storage[i].type == "Light-duty")
                {
                    income = income+300;
                } 
            }
        }
        cout << "Total income in " << tp << " booth for date " << dt << " is" << income << endl;
    }

    void Income(string dt)
    {
        int income = 0;
        for(int i=0; i<size; i++)
        {
            if(storage[i].date == dt)
            {
                if(storage[i].type == "Heavy-duty")
                {
                    income = income+800;
                }
                else if(storage[i].type == "Medium-duty")
                {
                    income = income+500;
                }
                else if(storage[i].type == "Light-duty")
                {
                    income = income+300;
                } 
            }
        }
        cout << "Total income for date: " << dt << " is " << income << endl;
    }


};

class Serial //actually the queue 
{
    Data vQueue[10];
    public: 
    int maxsize = 10;
    int front = -1;
    int rear = -1; //these variables are public too because these are used to do deQueue to free up space from outside of the class
    
    bool isEmpty()
    {
        bool flag = false;
        if(front==-1 && rear==-1)
        {
            flag = true;
        }

        return flag;
    }

    bool isFull()
    {
        bool flag = false;
        if(((rear+1)%maxsize)==front)
        {
            flag = true;
        }

        return flag;
    }

    void enQueue(Data d)//not checking if full same because this func must return value, so will check these two condition from where this func is called
    {
        if(isEmpty())
        {
            front = 0;
            rear = 0;
            vQueue[rear] = d;
        }
        else
        {
            rear = (rear+1)%maxsize;
            vQueue[rear] = d;
        }
    }

    Data deQueue() //not checking if empty or front and rear is same because this func must return value, so will check these two condition from where this func is called
    {
        Data d = vQueue[front];
        front = (front+1)%maxsize;
        return d;
    }

};



int main()
{
    TollDataStorage tds;
    Serial ht;//for heavy type
    Serial mt;// for medium type
    Serial lt;//for light type
    bool mainMenu = true; //makes sure main menu runs as long as user wants
    cout << "\nWelcome to Padma Bridge Toll Data Storage System" << endl;
    cout << "________________________________\n" << endl;

    while(mainMenu)
    {
        cout << "\nMain Menu\n" << endl;
        cout << "Choose from bellow" << endl;
        cout << "1. Select your counter type" << endl;
        cout << "2. Get information of a vehicle" << endl;
        cout << "3. Total income of the day" << endl;
        cout << "0. To exit" << endl;

        cout << "Input:";
        int choice1 = 0;
        int choice2 = 0;
        bool hv = true; //for heavy type's while loop
        bool md = true; //for medium type's while loop
        bool lg = true; //for light type's while loop
        cin >> choice1;
        switch (choice1)
        {
        case 1:
            cout << "Choose from bellow:\n__________________" << endl;
            cout << "1. Counter for Heavy-duty type vehicle" << endl;
            cout << "2. Counter for Medium-duty type vehicle" << endl;
            cout << "3. Counter for Light-duty type vehicle" << endl;
            cout << "0. Go back to menu\n" << endl;
            cout << "Input:";


            cin >> choice2;
            
            switch (choice2)
            {
            case 1:
                /* heavy */
                while(hv)
                {
                    cout << "Choose from bellow" << endl;
                    cout << "1. Insert information" << endl;
                    cout << "0. Go Back to previous menu" << endl;
                    int choice3 = 0;
                    cout << "Input: ";
                    cin >> choice3;
                    string dt;
                    string ticket;
                    string vehicleNumber;
                    Data info;
                    switch (choice3)
                    {
                    case 1:
                        cout << "Input Todays date (format: dd-mm-yy month must be integer)" << endl;
                        cin >> dt;
                        info.type = "Heavy-duty";
                        info.date = dt;
                        cout << "Enter Vehicle number" << endl;
                        cin >> vehicleNumber;
                        info.vNum = vehicleNumber;
                        cout << "Enter Ticket number" << endl;
                        cin >> ticket;
                        info.tNum = ticket;
                        if(ht.isFull())
                        {
                            while(!ht.isEmpty()) //dequeueing untill it is fully empty
                            {
                                tds.insertData(ht.deQueue());
                                if(ht.front == ht.rear)
                                {
                                    ht.front = -1;
                                    ht.rear = -1;
                                }
                            }
                        }
                        ht.enQueue(info);
                        cout << "Information inserted...\n" << endl;
                    break;
                    case 0:
                        hv = false;
                        cout << "Going Back to previous menu" << endl;
                        break;
                
                    default:
                        cout << "Wrong Input" << endl;
                        break;
                    }
                }
                break;

            case 2:
                /* medium */
                while(md)
                {   
                    cout << "Choose from bellow" << endl;
                    cout << "1. Insert information" << endl;
                    cout << "0. Go Back to previous menu" << endl;
                    int choice4 = 0;
                    cout << "Input: ";
                    cin >> choice4;
                    string dt;
                    string ticket;
                    string vehicleNumber;
                    Data info;
                    switch (choice4)
                    {
                    case 1:
                        cout << "Input Todays date (format: dd-mm-yy month must be integer)" << endl;
                        cin >> dt;
                        info.type = "Medium-duty";
                        info.date = dt;
                        cout << "Enter Vehicle number" << endl;
                        cin >> vehicleNumber;
                        info.vNum = vehicleNumber;
                        cout << "Enter Ticket number" << endl;
                        cin >> ticket;
                        info.tNum = ticket;
                        if(mt.isFull())
                        {
                            while(!mt.isEmpty()) //dequeueing untill it is fully empty
                            {
                                tds.insertData(mt.deQueue());
                                if(mt.front == mt.rear)
                                {
                                    mt.front = -1;
                                    mt.rear = -1;
                                }
                            }
                        }
                        mt.enQueue(info);
                        cout << "Information inserted...\n" << endl;
                    break;
                    case 0:
                        md = false;
                        cout << "Going Back to previous menu" << endl;
                        break;
                
                    default:
                        cout << "Wrong Input" << endl;
                        break;
                    }
                }
                break;
            case 3:
                /* light */
                while(lg)
                {   
                    cout << "Choose from bellow" << endl;
                    cout << "1. Insert information" << endl;
                    cout << "0. Go Back to previous menu" << endl;
                    int choice5 = 0;
                    cout << "Input: ";
                    cin >> choice5;
                    string dt;
                    string ticket;
                    string vehicleNumber;
                    Data info;
                    switch (choice5)
                    {
                    case 1:
                        cout << "Input Todays date (format: dd-mm-yy month must be integer)" << endl;
                        cin >> dt;
                        info.type = "Light-duty";
                        info.date = dt;
                        cout << "Enter Vehicle number" << endl;
                        cin >> vehicleNumber;
                        info.vNum = vehicleNumber;
                        cout << "Enter Ticket number" << endl;
                        cin >> ticket;
                        info.tNum = ticket;
                        if(lt.isFull())
                        {
                            while(!lt.isEmpty()) //dequeueing untill it is fully empty
                            {
                                tds.insertData(lt.deQueue());
                                if(lt.front == lt.rear)
                                {
                                    lt.front = -1;
                                    lt.rear = -1;
                                }
                            }
                        }
                        lt.enQueue(info);
                        cout << "Information inserted...\n" << endl;
                    break;
                    case 0:
                        lg = false;
                        cout << "Going Back to previous menu" << endl;
                        break;
                
                    default:
                        cout << "Wrong Input" << endl;
                        break;
                    }
                }
                break;
            case 0:
                cout << "Going back to menu" << endl;
                break;
            
            default:
                cout << "Wrong Input" << endl;
                break;
            }

            break;

        case 2:
            while(!ht.isEmpty()) //dequeueing untill it is fully empty
                {
                    tds.insertData(ht.deQueue());
                    if(ht.front == ht.rear)
                    {
                        ht.front = -1;
                        ht.rear = -1;
                    }
                }
            
            while(!mt.isEmpty()) //dequeueing untill it is fully empty
                {
                    tds.insertData(mt.deQueue());
                    if(mt.front == mt.rear)
                    {
                        mt.front = -1;
                        mt.rear = -1;
                    }
                }
            
            while(!lt.isEmpty()) //dequeueing untill it is fully empty
                {
                    tds.insertData(lt.deQueue());
                    if(lt.front == lt.rear)
                    {
                        lt.front = -1;
                        lt.rear = -1;
                    }
                }
            cout << "Please enter the vehicle number: ";
            {
            string vNumber; //used {} because can not declare string in switch case because of scope jump 
            cin >> vNumber;
            tds.searchInfo(vNumber);
            }
            break;
        case 3:
            while(!ht.isEmpty()) //dequeueing untill it is fully empty
                {
                    tds.insertData(ht.deQueue());
                    if(ht.front == ht.rear)
                    {
                        ht.front = -1;
                        ht.rear = -1;
                    }
                }
            
            while(!mt.isEmpty()) //dequeueing untill it is fully empty
                {
                    tds.insertData(mt.deQueue());
                    if(mt.front == mt.rear)
                    {
                        mt.front = -1;
                        mt.rear = -1;
                    }
                }
            
            while(!lt.isEmpty()) //dequeueing untill it is fully empty
                {
                    tds.insertData(lt.deQueue());
                    if(lt.front == lt.rear)
                    {
                        lt.front = -1;
                        lt.rear = -1;
                    }
                }
            
            {
            string vType, date; //used {} because can not declare string in switch case because of scope jump 
            cout << "Enter date: ";
            cin >> date;
            tds.perticularTypeIncome(date, "Heavy-duty");
            tds.perticularTypeIncome(date, "Medium-duty");
            tds.perticularTypeIncome(date, "Light-duty");
            tds.Income(date);
            }

            break;
        case 0:
            mainMenu = false;
            cout << "Exiting The System" << endl;
            break; 

        default:
            cout << "Wrong Input" << endl;
            break;
        }
    }



    return 0;
}