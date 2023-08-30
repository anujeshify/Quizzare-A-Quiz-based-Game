//The <bits/stdc++. h> is a header file. This file includes all standard library.
//<iostream> is the header file which contains all the functions of program like cout, cin etc. and #include tells the preprocessor to include these header file in the program.
//The cstdlib header file contains definitions for C++ for performing a variety of operations. Include the standard header into a C++ program to effectively include the standard header < stdlib. h > within the std namespace.
//Fstream is a library that consists of both, ofstream and ifstream which means it can create files, write information to files, and read information from files. This header file is generally used as a data type that represents the file stream.
//direct.h is a header file for the C programming language for windows. It contains declaration of functions and required macros, struct etc used to manipulate file system directories.
//<windows. h> header file is used to access the Win32 API functions and it makes it easier for the user to use the in-built functionality. - The header file in particular includes the library and functions used in the libraries like stdio.
//The using namespace statement just means that in the scope it is present, make all the things under the std namespace available without having to prefix std:: before each of them.
//It means that during the preprocessing step you compiler will replace all the occurence of MAX_LEN by its value

#include<bits/stdc++.h>
#include<iostream>
#include <cstdlib>
#include <fstream>
#include <direct.h>
#include <windows.h>
#define SIZE 1000

using namespace std;
int score = 0;

//structure namescore consists of two parameters string x and int y
//Structure is a collection of variables of different data types under a single name.
// It is similar to a class in that, both holds a collecion of data of different data types.

struct namescore
{
    //A string in C++ is a type of object representing a collection (or sequence) of different characters.
    string x;
    //The int keyword is used to indicate integers. Its size is usually 4 bytes.
    // Meaning, it can store values from -2147483648 to 2147483647
    int y;
};


//declaring class for initialising a node for linked list
// node is a collection of two sub-elements or parts.
//A data part that stores the element and a next part that stores the link to the next node
class node
{
public:
    string name;
    int score, temp;
    //node* next
    //means: next is a pointer to a node structure, and indicates the next item in the list.
    node *next;
    // node(node &n)
    // {
    //    name = n.name;
    //    score = n.score;
    //    next = n.next;
    // };
    //parametrised constructor taking username and user score as input parammeter
    node(string username, int userscore)
    {
        name = username;
        score = userscore;
        //The C NUL is a single character that compares equal to 0.
        //The C NULL is a special reserved pointer value that does not point to any valid data object.
        next = NULL;
    }
};



//this function opens the file and stores the file value into namescore getdata structure
namescore getdata(string x, int y)
{
    //making file pointer ptr4
    //Ifstream - ifstream is an input file stream.
    // It is a special kind of an istream that reads in data from a data file.
    //Ofstream is an output file stream. It is a special kind of ostream that writes data out to a data file.
    ifstream ptr4;
    ptr4.open("scores.txt", ios::in);
    getline(ptr4, x);
    ptr4 >> y;
    namescore res = {x, y};
}


//linked list for storing user score and name
class leaderboard
{
public:
    node *head;
    node *tail;
    //default constructor
    leaderboard()
    {
        head = tail = NULL;
    }

    //this function adds values at the end of leaderboard linked list
    void appenddata(string a, int b)
    {
        node *temp = new node(a, b);
        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }


    //this function sorts the scores and the names of the participants in descending order
    //here in the function two pointers have been declared ptr and cpt

    void sorting()
    {
        node *ptr, *cpt;
        //ptr is intialised as head
        ptr = head;
        //it will keep working upto second last element
        while (ptr->next != NULL)
        {
            //cpt is pointing too the node next to the ptr.
            cpt = ptr->next;
            while (cpt!= NULL)
            {
                //if the data of node cpt is greater than node ptr data will get swapped
                //swapping is done in the descending order
                if (ptr->score < cpt->score)
                {

                    string name = ptr->name;
                    int score = ptr->score;
                    ptr->name = cpt->name;
                    ptr->score = cpt->score; //basic swapping
                    cpt->name = name;
                    cpt->score = score;
                }
                cpt = cpt->next;
            }
            ptr = ptr->next;
        }
    }



    //this function displays the leaderboard linked list
    void display()
    {
        node *temp = head;
        cout << "\n.------------------------.--------------." << endl;
        cout << "|\tName\t\t | \tScore\t|" << endl;
        while (temp != NULL)
        {
            cout << "|------------------------|--------------|" << endl;
            cout << "|" << temp->name << "      \t\t | \t";
            cout << temp->score << "\t|\n";
            temp = temp->next;
        }
        cout << ".------------------------.--------------." << endl;
        cout << endl;
    }


};



//this function converts string value to integer value
int stringTointeger(string str)
{
    int temp = 0;
    for (int i = 0; i < str.length(); i++) {

        // Since ASCII value of character from '0'
        // to '9' are contiguous. So if we subtract
        // '0' from ASCII value of a digit, we get
        // the integer value of the digit.
        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}




//opening,sorting and displaying  files containing username and score in leaderboard linked list
void dataintoll()
{
    ifstream scores;
    scores.open("scores.txt", ios::in);
    string str1, str2;
    leaderboard l1;
    while (getline(scores, str1) && getline(scores, str2))
    {
        int s2 = stringTointeger(str2);
        //int s2=stoi(str2);
        l1.appenddata(str1, s2);
    }
    l1.sorting();
    l1.display();
}



//queue data structure to store questions
//containing member functions enqueue(),peak(),size(),isempty ()
//Class- A class in C++ is a user-defined type
// or data structure declared with keyword class that has data and functions as its members whose access is governed by the three access specifiers private, protected or public.
class Queue
{
    string *arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    Queue(int size = SIZE);

    void enqueue(string x);
    string peek();
    int size();
    bool isEmpty();
    bool isFull();
    void checker(string);
    void fileworkanswer(fstream);
};


//second queue to store answers
class Queue2
{
    string *arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    Queue2(int size = SIZE);

    void enqueue(string x);
    string peek();
    int size();
    bool isEmpty();
    bool isFull();
    void getques();
};


//function to create new space in queue
//which is member function of queue
Queue::Queue(int size)
{
    arr = new string[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}


//function to create new space in queue
//which is member function of queue containing answers
Queue2::Queue2(int size)
{
    arr = new string[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}
//this function checks whether queue is full or not
//if it is full it displays overflow else add data into queue
void Queue::enqueue(string item)
{

    if (isFull())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}
//this function checks whether queue is full or not
//if it is full it displays overflow else add data into queue
void Queue2::enqueue(string item)
{

    if (isFull())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}
//this function helps in extracting the first element of the queue which is pointed by front
string Queue::peek()
{
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}
//this function helps in extracting the first element of the queue which is pointed by front
string Queue2::peek()
{
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}
//this function gives size of queue
int Queue::size()
{
    return count;
}
//this function gives size of queue
int Queue2::size()
{
    return count;
}
//to check if the queue is empty
bool Queue::isEmpty()
{
    return (size() == 0);
}
//to check if the queue is empty
bool Queue2::isEmpty()
{
    return (size() == 0);
}
//to check if the queue is full
bool Queue::isFull()
{
    return (size() == capacity);
}
//to check if the queue is full
bool Queue2::isFull()
{
    return (size() == capacity);
}
//function to check if the answer is correct if its correct then front value in queue 1 gets added
void Queue::checker(string x)
{
    string a = peek();

    if (x == a)
    {
        cout << "Correct Answer\n\n" << endl;
        score++;
        front++;
    }
    else
    {
        cout << "Incorrect Answer\n\n" << endl;
        front++;
    }
}
//it retrieves he value returned by peak function and increases the front pointer by one
void Queue2::getques()
{
    string l = peek();
    cout << l;
    front++;
}
//it retrieves the score from checker function and appends it in score.txt.
addscore(string name, int score)
{
    //The class ofstream is used for output to a file.
    // Both of these classes are defined in the standard C++ library header fstream
    ofstream ptr3;
    ptr3.open("scores.txt", ios::app);
    ptr3 << name << endl;
    ptr3 << score << endl;
}

int main()
{
    //it is use to change the colour of the text and the background of the system
    system("Color 0B");

     {
         //increases terminal window size
         system("mode 650");
         string hello = " Loading....... \n";
         int x=0;

         //printing hello string in presentable manner.
         while ( hello[x] != '\0')
         {
                cout << hello[x];
                //sleep function delays the process
                Sleep(200);
                x++;
         }

        //Printing loading bar
        char y= 219;

        //Gradually increasing the loading speed
        for (int i = 0; i < 35; i++)
        {
            cout << y;
            if (i < 10)
                Sleep(300);
            if (i >= 10 && i < 20)
                Sleep(150);
            if (i >= 10)
                Sleep(25);
        }
        cout<<" 100%\nQuiz game loaded! Press 'Enter' to continue:\n";

        //Input any value to continue with the program
        cin.get();

        //clears the screen
        system("cls");
    }

    //Title screen of the game
    titlescreen:
    {
        string hello = " \n HELLO, Welcome to\n\n";
        string hello2 = "\n\n\n\nThis game is created by \n21103001 - Anujesh Bansal \n21103023 - Vanshika Gupta \n21103002 - Nupur Tiwari \n21103017 - Atish Ranjan Mahali \n ";
        int x=0,y=0;

        //Printing hello string in presentable manner
        while ( hello[x] != '\0')
        {
            cout << hello[x];
            Sleep(10);
            x++;
        }

        //code to display Title of the game in form of ASCII ART
        cout<<"\n\n     QQQQQQQQQ                         iiii                                                                                                ";
        Sleep(10);
        cout<<"\n   QQ:::::::::QQ                      i::::i                                                                                               ";
        Sleep(10);
        cout<<"\n QQ:::::::::::::QQ                     iiii                                                                                                ";
        Sleep(10);
        cout<<"\nQ:::::::QQQ:::::::Q                                                                                                                        ";
        Sleep(10);
        cout<<"\nQ::::::O   Q::::::Quuuuuu    uuuuuu  iiiiiii zzzzzzzzzzzzzzzzz  aaaaaaaaaaaaa  rrrrr   rrrrrrrrr   rrrrr   rrrrrrrrr       eeeeeeeeeeee    ";
        Sleep(10);
        cout<<"\nQ:::::O     Q:::::Qu::::u    u::::u  i:::::i z:::::::::::::::z  a::::::::::::a r::::rrr:::::::::r  r::::rrr:::::::::r    ee::::::::::::ee  ";
        Sleep(10);
        cout<<"\nQ:::::O     Q:::::Qu::::u    u::::u   i::::i z::::::::::::::z   aaaaaaaaa:::::ar:::::::::::::::::r r:::::::::::::::::r  e::::::eeeee:::::ee";
        Sleep(10);
        cout<<"\nQ:::::O     Q:::::Qu::::u    u::::u   i::::i zzzzzzzz::::::z             a::::arr::::::rrrrr::::::rrr::::::rrrrr::::::re::::::e     e:::::e";
        Sleep(10);
        cout<<"\nQ:::::O     Q:::::Qu::::u    u::::u   i::::i       z::::::z       aaaaaaa:::::a r:::::r     r:::::r r:::::r     r:::::re:::::::eeeee::::::e";
        Sleep(10);
        cout<<"\nQ:::::O     Q:::::Qu::::u    u::::u   i::::i      z::::::z      aa::::::::::::a r:::::r     rrrrrrr r:::::r     rrrrrrre:::::::::::::::::e ";
        Sleep(10);
        cout<<"\nQ:::::O  QQQQ:::::Qu::::u    u::::u   i::::i     z::::::z      a::::aaaa::::::a r:::::r             r:::::r            e::::::eeeeeeeeeee  ";
        Sleep(10);
        cout<<"\nQ::::::O Q::::::::Qu:::::uuuu:::::u   i::::i    z::::::z      a::::a    a:::::a r:::::r             r:::::r            e:::::::e           ";
        Sleep(10);
        cout<<"\nQ:::::::QQ::::::::Qu:::::::::::::::uui::::::i  z::::::zzzzzzzza::::a    a:::::a r:::::r             r:::::r            e::::::::e          ";
        Sleep(10);
        cout<<"\n QQ::::::::::::::Q  u:::::::::::::::ui::::::i z::::::::::::::za:::::aaaa::::::a r:::::r             r:::::r             e::::::::eeeeeeee  ";
        Sleep(10);
        cout<<"\n   QQ:::::::::::Q    uu::::::::uu:::ui::::::iz:::::::::::::::z a::::::::::aa:::ar:::::r             r:::::r              ee:::::::::::::e  ";
        Sleep(10);
        cout<<"\n     QQQQQQQQ::::QQ    uuuuuuuu  uuuuiiiiiiiizzzzzzzzzzzzzzzzz  aaaaaaaaaa  aaaarrrrrrr             rrrrrrr                eeeeeeeeeeeeee  ";
        Sleep(10);
        cout<<"\n             Q:::::Q                                                                                                                       ";
        Sleep(10);
        cout<<"\n              QQQQQQ                                                                                                                       \n";
        cout<<"\n\t\t    ___       ____  _                               ____        _          ______                    ";
        cout<<"\n\t\t   /   |     / __ )(_)___  ____ ______________     / __ \\__  __(_)___     / ____/___ _____ ___  ___  ";
        cout<<"\n\t\t  / /| |    / __  / /_  / / __ `/ ___/ ___/ _ \\   / / / / / / / /_  /    / / __/ __ `/ __ `__ \\/ _ \\ ";
        cout<<"\n\t\t / ___ |   / /_/ / / / /_/ /_/ / /  / /  /  __/  / /_/ / /_/ / / / /_   / /_/ / /_/ / / / / / /  __/ ";
        cout<<"\n\t\t/_/  |_|  /_____/_/ /___/\\__,_/_/  /_/   \\___/   \\___\\_\\__,_/_/ /___/   \\____/\\__,_/_/ /_/ /_/\\___/  \n";

        //Printing hello2 string in presentable manner
        while ( hello2[y] != '\0')
        {
            cout << hello2[y];
            Sleep(10);
            y++;
        }
    }


    int inp;
    cout << "\n \nAre you ready?!" << endl;
    cout << "\n \tPress Enter to start the quiz... " << endl;

    //Input any value to continue with the program
    cin.get();

    //Main menu label
    menu:

    score=0;
    //clears the screen
    system("cls");

    cout<<"\n";

    //Prints Game title on top of main menu
    cout<<"\n\t   ___        _                         ";
    cout<<"\n\t  / _ \\ _   _(_)______ _ _ __ _ __ ___  ";
    cout<<"\n\t | | | | | | | |_  / _` | \'__| \'__/ _ \\ ";
    cout<<"\n\t | |_| | |_| | |/ / (_| | |  | | |  __/ ";
    cout<<"\n\t  \\__\\_\\\\__,_|_/___\\__,_|_|  |_|  \\___| ";

    cout<<"\n\t\tA Bizarre Quiz Game\n\n";


    //Main menu of the Game
    cout << "\nMAIN MENU\n";
    cout << "1.Play Quiz\n2.Show Leaderboard\n3.Go to Title Screen\n4.Exit the Quiz\n";
    option:
    cout<<"\nYour Option: ";

    //Input user option
    cin >> inp;

    //Use switch to specify many alternative blocks of code to be executed
    switch (inp)
    {
        //switch case case 1
        case 1:
        {
        //declaring label playquiz
        playquiz:

        //Adding sleep function to delay the program to add realism to the game
        Sleep(2000);

        //Clears the screen
        system("CLS");

        //Prints the title of the game
        cout<<"\n\t   ___        _                         ";
        cout<<"\n\t  / _ \\ _   _(_)______ _ _ __ _ __ ___  ";
        cout<<"\n\t | | | | | | | |_  / _` | \'__| \'__/ _ \\ ";
        cout<<"\n\t | |_| | |_| | |/ / (_| | |  | | |  __/ ";
        cout<<"\n\t  \\__\\_\\\\__,_|_/___\\__,_|_|  |_|  \\___| ";

        cout<<"\n\t\tA Bizarre Quiz Game\n\n\n";
        string name;
        string input;

        //Input name of the user
        cout << "\nEnter Name: ";
        cin >> name;

        cout << "Hi " << name << "!\nEnter \'yes\' to start quiz: ";
        cin >> input;
        if (input == "yes")
        {
            cout << "Starting..." << endl;

            //Adding sleep function to delay the program to add realism to the game
            Sleep(2000);

            //Clears the screen
            system("CLS");

            //Prints the title of the game
            cout<<"\n\t   ___        _                         ";
            cout<<"\n\t  / _ \\ _   _(_)______ _ _ __ _ __ ___  ";
            cout<<"\n\t | | | | | | | |_  / _` | \'__| \'__/ _ \\ ";
            cout<<"\n\t | |_| | |_| | |/ / (_| | |  | | |  __/ ";
            cout<<"\n\t  \\__\\_\\\\__,_|_/___\\__,_|_|  |_|  \\___| ";

            cout<<"\n\t\tA Bizarre Quiz Game\n\n\n";
                string x;
                string y;

                //fstream is used to create files, write information to files, and read information from files.
                fstream fptr;
                fstream fileptr;

                //initialising queue q and queue m
                Queue q(5);
                Queue2 m(10);

                //Opens the file answers.txt and questions.txt using read operations from a stream
                fileptr.open("answers.txt", ios::in);
                fptr.open("questions.txt", ios::in);

                //If file pointer fileptr is open
                if (fileptr.is_open())
                {
                    //loop to traverse answers.txt
                    for (int i = 0; i < 5; i++)
                    {
                        string ans;

                        //retrieves lines from fileptr
                        getline(fileptr, ans);

                        //inserts answer into queue q
                        q.enqueue(ans);
                    }
                }

                //If file pointer fptr is open
                if (fptr.is_open())
                {
                    //loop to traverse questions.txt
                    for (int i = 0; i < 10; i++)
                    {
                        string que;

                        //retrieves lines from fptr
                        getline(fptr, que);

                        //inserts answer into queue m
                        m.enqueue(que);

                    }
                }

                //loop to retrieve questions from queue m containing questions
                for (int i = 0; i < 5; i++)
                {
                    m.getques();
                    cout<<endl;
                    m.getques();

                    //Input user's answer choice
                    cout << "\n\nEnter your Choice: ";
                    cin >> x;
                    cout<<"";

                    //calls checker function
                    q.checker(x);
                }

                //Displays user score
                cout << "\n"<< "Your score is: " << score;
                cout << "\n\n";

                //calls addscore function which adds the score and user name into scores.txt
                addscore(name, score);
                int n2;

                //Goes back to main menu or exit the game
                cout << "\n\nPlay Another Round?\n1.Go to Main Menu\n2.Exit the Game\n";

                //declaring label2
                label2:
                cout<<"\nEnter your Choice: ";
                cin>>n2;
                if(n2==1)
                {
                    //this label takes the user back to main menu
                    goto menu;
                }
                else if(n2==2)
                {
                    //salutation for playing the game
                    cout << "Thank you for playing QUIZARRE!\nHope you have a good day! :)\n\n";

                    //Enter user input
                    cin.get();

                    //Closes the terminal window
                    exit(1);
                }
                else
                {
                    cout<<"Wrong Input! Please Try Again!\n";

                    //this label takes user back to label 2 to input user choice
                    goto label2;
                }
            }
            break;
        }

        //switchcase case 2
        case 2:
        {
            //Displays leaderboard ASCII Art
            cout << "\n\n" << endl;
            system("CLS");
            cout<<"\n _                    _           _                         _ ";
            cout<<"\n| |                  | |         | |                       | |";
            cout<<"\n| |     ___  __ _  __| | ___ _ __| |__   ___   __ _ _ __ __| |";
            cout<<"\n| |    / _ \\/ _` |/ _` |/ _ \\ '__| '_ \\ / _ \\ / _` | '__/ _` |";
            cout<<"\n| |___|  __/ (_| | (_| |  __/ |  | |_) | (_) | (_| | | | (_| |";
            cout<<"\n\\_____/\\___|\\__,_|\\__,_|\\___|_|  |_.__/ \\___/ \\__,_|_|  \\__,_|";
            cout<<"\n";

            //calls function dataintoll() that adds data into linked list and displays it
            dataintoll();
            int n1;

            //Goes back to main menu or exit the game
            cout << "\n\nPlay Another Round?\n1.Go to Main Menu\n2.Exit the Game\n";

            //declaring label1
            label1:
            cout<<"\nEnter your Choice: ";
            cin>>n1;
            if(n1==1)
            {
                //this label takes the user back to main menu
                goto menu;
            }
            else if(n1==2)
            {
                //salutation for playing the game
                cout << "Thank you for playing QUIZARRE!\nHope you have a good day! :)\n\n";

                //Enter user input
                cin.get();

                //Closes the terminal window
                exit(1);
            }
            else
            {
                cout<<"Wrong Input! Please Try Again!\n";

                //this label takes user back to label 2 to input user choice
                goto label1;
            }
        }

        //switchcase case 3
        case 3:
        {
            //function clears the screen
            system("cls");

            //goes back to title screen
            goto titlescreen;

            break;
        }

        //switchcase case 4
        case 4:
        {
            //declaring exit label
            exit:

            //salutation for playing the game
            cout << "Thank you for playing QUIZARRE!\nHope you have a good day! :)\n\n";

            //Enter user input
            cin.get();

            //Closes the terminal window
            exit(1);

            break;
        }

        //switchcase default case
        default:
        {
             cout<<"Wrong Input! Please Try Again!\n";
             //this label takes user back to label 2 to input user choice
             goto option;
        }
    }
    return 0;
}

