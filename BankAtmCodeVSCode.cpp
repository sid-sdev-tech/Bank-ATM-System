#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

long int num;

class Login
{
private :
    string Card_no,Account_no,Person_name;
    long int Pin_no;

public :

    void setPerson_name(string D)
    {
        Person_name = D;
    }
    void setAccount_no(string C)
    {
        Account_no = C;
    }
    void setCard_no(string A)
    {
        Card_no = A;
    }
    void setPin_no(long B)
    {
        Pin_no = B;
    }

    string getPerson_name()
    {
        return Person_name;
    }
    string getAccount_no()
    {
        return Account_no;
    }
    string getCard_no()
    {
        return Card_no;
    }
    int getPin_no()
    {
        return Pin_no;
    }

        void accept_customer_details()
        {
            string person_name,account_number,card_number;
            long int pin_number;

            cout<<"\n Accepting Employee Details : \n"<<endl;
            cout<<"Enter the Person Name : "<<endl;
            cin>>person_name;
            cout<<"Enter the Account Number of the Person : "<<endl;
            cin>>account_number;
            cout<<"Enter the 16 digit ATM Card Number of the Person : "<<endl;
            cin>>card_number;
            cout<<"Enter the 4 digit ATM PIN NUMBER : "<<endl;
            cin>>pin_number;

            setPerson_name(person_name);
            setAccount_no(account_number);
            setCard_no(card_number);
            setPin_no(pin_number);

        }

        void display_customer_details()
        {
            ofstream fout;
            string pnm,an,cn;
            int pn,i;

            pnm = getPerson_name();
            an = getAccount_no();
            cn  = getCard_no();
            pn = getPin_no();

        cout<<"\n Displaying the Employee details : \n"<<endl;
        cout<<"The Person's Name : "<<pnm<<endl;
        cout<<"The Account Number of the Person : "<<an<<endl;
        cout<<"The 16 digit ATM Card Number of the Person : "<<cn<<endl;
        cout<<"The 4 digit ATM PIN NUMBER : "<<pn<<endl;

        fout.open("Persons_data.TXT",ios::app);
        fout<<pnm<<"\t"<<an<<"\t"<<cn<<"\t"<<pn<<"\n";
        fout.close();

        }

};

class ATM
{
    int amount;
    public :
        int CURRENT_BALANCE(int aabb)
        {
            amount = aabb;
            cout<<"The current balance is : "<<amount<<endl;

            return 0;
        }

        void BALANCE(double balance)
        {
            cout<<"Balance = "<<amount<<endl;
            amount = balance;
            cout<<"Now your current Balance amount is "<<amount<<endl;
        }

        long int Deposit(int bbcc)
        {
            int deposit;
            amount = bbcc;
            cout<<"Enter the amount you want to deposit"<<endl;
            cin>>deposit;
            cout<<"Before deposit your amount is : "<<amount<<endl;
            amount = amount + deposit;
            cout<<"After deposit your amount is : "<<amount<<endl;

            return amount;
        }

        long int Withdraw(int ccdd)
        {
            int withdraw;
            amount = ccdd;
            cout<<"Enter the amount you want to deduct from your account"<<endl;
            cin>>withdraw;
            amount = amount - withdraw;
            cout<<"Now, Your amount is = "<<amount<<endl;

            return amount;
        }

        void op_call(string accnum)
        {
            string Accnumber = accnum;
            int cc,choice,ncount = 0,flag4 = 0;
            char ch;
            int bal,bal0;

            std::vector <string> accno;
            std::vector <int> accbal;
            string accountno;
            int accbalance,abalance;
            std::ifstream finv;

            finv.open("C:\\Users\\hp\\VisualStudioCodePrograms\\ATMprogram\\Persons_Balance.TXT",ios::in);
            if(!finv.is_open())
            {
                cout<<"Error..,File Not Opened"<<endl;
            }
            else
            {
                cout<<"Account Holders Balance File  Opened.."<<endl;
                while (finv.good()!='\0')
                {
                    /* code */
                    cout<<"\n Number count : "<<ncount<<endl;
                finv>>accountno>>accbalance;

                    if( accountno == " " || accbalance == -1)
                    {
                        break;
                    }
                    else
                    {
                    cout<<accountno<<" --> "<<accbalance<<endl;
                    accno.push_back(accountno);
                    accbal.push_back(accbalance);
                    accountno = ' ';
                    accbalance = ' ';
                    ncount++;
                    }
                }
                cout<<"Outside of while loop now.."<<endl;
                cout<<Accnumber<<endl;
            }

            finv.close();

            for (int a = 0; a < ncount; a++)
            {
                /* code */
                cout<<accno[a]<<endl;

                if(Accnumber == accno[a])
                {
                    abalance = accbal[a];
                    cout<<"The Account Number Matched.."<<endl;
                    cout<<"Select one operation from below options :-"<<endl;
                    cout<<" 1 - Check Balance \n 2 - DEPOSIT AMOUNT \n 3 - WITHDRAW AMOUNT \n 4 - EXIT \n ------------------------"<<endl;
                    cout<<"Enter your choice : "<<endl;
                    cin>>choice;
                    cc = a;
                }
                else if(a==(ncount-1))
                {
                    cout<<"The Account number didn't match.."<<endl;
                }
                cout<<"A has value : "<<a<<endl;
            }

            switch(choice)
            {
                case 1 :CURRENT_BALANCE(abalance);
                        accbal[cc] = abalance;
                        break;

                case 2 :
                        cout << "Deposit Some Amount in your account" << endl;
                        bal = Deposit(abalance);
                        cout<<bal<<endl;
                        BALANCE(bal);
                        accbal[cc] = bal;
                        break;

                case 3 :
                        bal0 = Withdraw(abalance);
                        cout<<bal0<<endl;
                        BALANCE(bal0);
                        accbal[cc] = bal0;
                        break;

                case 4 : break;

            }

            for (int aa = 0; aa < ncount; aa++)
            {
                /* code */
                cout<<accno[aa]<<" --> "<<accbal[aa]<<endl;
            }

            std::fstream foutv;

            foutv.open("C:\\Users\\hp\\VisualStudioCodePrograms\\ATMprogram\\Persons_Balance.TXT",ios::out);
        if(!foutv.is_open())
        {
            cout<<"Error file not found"<<endl;
        }
        else{
            cout<<"\n File opened \n"<<endl;
            if(flag4 == 0)
            {
                cout<<"Account_NO"<<"\t\t"<<"Balance"<<endl;
                flag4 = 1;
            }
            for (int II = 0; II < ncount; II++)
            {
                /* code */
            cout<<accno[II]<<"\t\t"<<accbal[II]<<'\n'<<endl;
            foutv<<accno[II]<<"\t\t"<<accbal[II]<<'\n';
            }

        }
        foutv.close();
        }

};

class Access : public Login,public ATM
{

public :

        void account_ass()
        {
            std::vector <Login> l(num);

            vector <string> P_NAME,ACC_NO,CARD_NUM;
            vector <int> PIN_NUM;
            int upn;

            string ucn;
            string name,acn,cno;
            int pno;

            //string CARD_NUMBER[sz],PIN_NUMBER[sz],ACC_NO[sz],P_NAME[sz];
            int flag0 = 0,flag1 = 0,flag2 = 0,flag02 = 0;
            int chance = 3,c = 0,p = 0;
            char ch;
            int count = 0;

                std:: ifstream fin1;
                fin1.open("Persons_data.TXT",ios::in);
                if(fin1.is_open())
                {
                    while (fin1.good()!='\0')
                    {
                        cout<<"count : "<<count<<endl;

                        fin1>>name>>acn>>cno>>pno;

                        if( name == " " || acn == " " ||  cno == " " || pno == 0)
                        {
                            break;
                        }
                        else
                        {
                        cout<<name<<","<<acn<<","<<cno<<","<<pno<<endl;
                        cout<<"\n";
                        }

                        P_NAME.push_back(name);
                        ACC_NO.push_back(acn);
                        CARD_NUM.push_back(cno);
                        PIN_NUM.push_back(pno);

                        name = " ";
                        acn = " ";
                        cno = " ";
                        pno = 0;
                        //cout<<P_NAME.size()<<"  "<<P_NAME.capacity()<<endl;//cout<<PIN_NUM.size()<<"  "<<PIN_NUM.capacity()<<endl;

                        count++;
                    }
                }

                fin1.close();
                    cout<<count<<endl;
                for(int o = 0;o<count;o++)
                {
                cout<<"value of o is : "<<o<<endl;
                //l[o] = VL[o];// P_NAME[o] = l[o].getPerson_name();// ACC_NO[o] = l[o].getAccount_no();// CARD_NUM[o] = l[o].getCard_no();// PIN_NUM[o] = l[o].getPin_no();

                // cout<<"\n CARD_NUMBER IS HERE : "<<l[o].getCard_no()<<"\n AND ITS PIN NUMBER IS : "<<l[o].getPin_no()<<endl;
                // cout<<"The Account Number is : "<<l[o].getAccount_no()<<" \n Person's Name is : "<<l[o].getPerson_name()<<endl;
                // cout<<"Object :"<<o+1<<" address : "<<&l[o]<<endl;

                cout<<"\n CARD_NUMBER IS HERE : "<<CARD_NUM[o]<<"\n AND ITS PIN NUMBER IS : "<<PIN_NUM[o]<<endl;
                cout<<"The Account Number is : "<<ACC_NO[o]<<" \n Person's Name is : "<<P_NAME[o]<<endl;
                cout<<"Object :"<<o+1<<" address : "<<&l[o]<<endl;

                }

            cout<<"Please enter your 16 digit ATM CARD NUMBER to access your account now.."<<endl;
            cin>>ucn;

            for(int m = 0;m<count;m++)
            {
                // for(int mm=0;mm<count;mm++)// {//     cout<<"PIN NUMBER :"<<PIN_NUM[mm]<<endl;// }
                cout<<"Value of m is : "<<m<<endl;

                    if(ucn == CARD_NUM[m])
                    {
                    cout<<"THE CARD NUMBER HAS VALUE :"<<CARD_NUM[m]<<"\n USER CARD NUMBER VALUE IS : "<<ucn<<endl;

                        flag1 = 1;
                    }
                    if(flag1 == 1)
                    {
                        cout<<"\t\t....Welcome...."<<endl;

                        flag0 = 1;
                        //break;
                        while(c<chance)
                        {

                        cout<<"Value of c is : "<<c<<endl;

                        cout <<"Now, Please enter your PIN NUMBER here.."<<endl;
                        cin>>upn;
                        cout<<"THE PIN NUMBER HAS VALUE :"<<PIN_NUM[m]<<endl;

                            if(upn == PIN_NUM[m])
                            {
                                cout<<"THE PIN NUMBER HAS VALUE :"<<PIN_NUM[m]<<"\n USER PIN NUMBER VALUE IS : "<<upn<<endl;
                                flag2 = 1;
                            }

                            if (flag2 == 1)
                            {
                                cout<<"Please select which operation you want to perform .."<<endl;
                                flag02 = 1;
                                cout<<"\t\t==>> *WELCOME* <<=="<<endl;
                                cout<<"\t\tMr/Mrs. "<<P_NAME[m]<<endl;
                                cout<<"Your Account Number :- "<<ACC_NO[m]<<endl;

                                    op_call(ACC_NO[m]);
                                    cout<<"Do you want to perform operation once again .. [y/n] "<<endl;
                                    cin>>ch;
                                    ch = (ch == 'y') ? 'y' : 'n';
                                        cout<<ch<<endl;
                                    if (ch == 'y')
                                    {
                                    op_call(ACC_NO[m]);

                                        cout<<"Do you want to perform operation again .. [y/n] "<<endl;
                                        cin>>ch;
                                        ch = (ch == 'y') ? 'y' : 'n';

                                        if (ch == 'y')
                                        {
                                        op_call(ACC_NO[m]);
                                        }
                                    }

                                break;

                            }
                            else
                            {
                                cout<<"THE PIN NUMBER YOU ENTERED IS INCORRECT .. !! \n     PLEASE ENTER CORRECT PIN NUMBER AGAIN    "<<endl;
                            }
                            c++;
                        }

                        cout<<"Outside of while loop now.."<<endl;

                        if(c == 3)
                        {
                            cout<<"You have tried 3 incorrect attempts , please try after 24 Hours Now.."<<endl;
                            break;
                        }
                    }
                    else if(m == (count-1))
                    {
                        cout<<"No Match \n Please enter carefully.."<<endl;
                        break;
                    }

                    if(flag0 == 1 && flag02 == 1)
                    {
                        cout<<"Flag0 is now 1 "<<endl;
                        cout<<"Flag02 is now 1"<<endl;
                        cout<<"Value of m is : "<<m<<endl;
                        break;
                    }
                }

            cout<<"Inside Account access method now.."<<endl;
       }

        void Pin_change()
        {
            std::vector <string> cardlist,pname,acclist;
            std::vector <int> pinlist;

            std:: ifstream fin;
            string line,name,acn,cno,flag = "0";
            int pno,count = 0,flag2 = 0;

            fin.open("Persons_data.TXT",ios::in);
            if(fin.is_open())
            {
                while (fin.good()!='\0')
                {
                    cout<<"count : "<<count<<endl;
                    fin>>name>>acn>>cno>>pno;
                    if( name == " " || acn == " " ||  cno == " " || pno == 0)
                    {
                        break;
                    }
                    else
                    {
                        if(flag == "0")
                        {
                            cout<<"Name"<<"\t\t"<<"Account_NO"<<"\t"<<"Card_NO\t"<<"\tPIN_No"<<endl;
                            flag = "o";
                        }
                        cout<<name<<"\t"<<"\t"<<acn<<"\t"<<cno<<"\t"<<pno<<'\n'<<endl;

                        pname.push_back(name);
                        acclist.push_back(acn);
                        cardlist.push_back(cno);
                        pinlist.push_back(pno);
                    }
                    name = ' ';
                    acn = ' ';
                    cno = ' ';
                    pno = 0;

                    /*getline(fin,name,'\t');getline(fin,acn,'\t');getline(fin,cno,'\t');getline(fin,pno,'\t');
                    cout<<name<<","<<acn<<","<<cno<<","<<pno<<endl; */
                    count++;
                }

                fin.close();

            }
            else
            {
                cout<<"Cannot read file"<<endl;
            }

            int c2 = 0,c3 = 0,c4 = 0;
            int ch =1 ;

            string ucard_no;
            int new_pin_nm,Cnew_pin_nm;

            int upin_no;
            // cout<<"SZ has value : "<<SZ<<endl;// int number;// number = SZ;//std::vector <Login> L(number);
            cout<<"Count has value :"<<count<<endl;

            for(int nn = 0;(nn<count);nn++)
            {
                cout<<"NN is : "<<nn<<endl;                 //L[nn] = VLP[nn];

                cout<<"CARD NUMBER List : "<<cardlist[nn]<<endl;
                cout<<"PIN NUMBER List : "<<pinlist[nn]<<endl;
            }

            cout<<"Please enter your 16 digit ATM CARD NUMBER here...."<<endl;
            cin>>ucard_no;

            cout<<"Please enter your current PIN NUMBER "<<endl;
            cin>>upin_no;

             //do
            //{
            for(int u = 0;u<(count);u++)
            {
                cout<<"u and count has values as : "<<u<<" "<<count<<endl;
                if(ucard_no == cardlist[u])
                {
                    do
                  {

                    if (upin_no == pinlist[u])
                    {
                        do
                        {

                        cout<<"Now, Please enter new PIN NUMBER to change "<<endl;
                        cin>>new_pin_nm;
                        cout<<"Please,Re-enter your new PIN NUMBER to confirm "<<endl;
                        cin>>Cnew_pin_nm;

                            if(new_pin_nm == Cnew_pin_nm)
                            {
                                pinlist[u] = Cnew_pin_nm;
                                cout<<endl;
                                break;
                            }
                            else
                            {
                                cout<<"The New PIN NUMBER AND CONFIRM PIN NUMBER NOT MATCHED \n Please re-enter both the numbers .."<<endl;

                                c2++;
                                cout<<"Value of c2 : "<<c2<<endl;

                            }

                        }while( c2<4 );
                        cout<<"Outside of while loop now.."<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"The PIN NUMBER YOU ENTERED DID NOT MATCH \n Please enter you correct PIN Number .."<<endl;
                        cout<<"Please enter your current PIN NUMBER "<<endl;
                        cin>>upin_no;
                        c3++;
                        cout<<"Value of c3 : "<<c3<<endl;
                    }
                  }while(c3 <2 );
                cout<<"Outside of while loop now..!!"<<endl;
                break;
                }
                else if(u == (count - 1))
                {

                    if(ch<4)
                    {
                    cout<<"Please Re-Enter correctly Your 16 digit ATM CARD NUMBER ..!!"<<endl;
                    cout<<"Please enter your 16 digit ATM CARD NUMBER here...."<<endl;
                    cin>>ucard_no;
                    u = 0;
                    ch++;
                    }
                    else
                    {
                        cout<<"You have attempted 4 incorrect chances \n Please exit and perform your operations again.. "<<endl;
                    }
                    c4++;
                    cout<<"Value of c4 : "<<c4<<endl;
                }
              }
            cout<<"Outside of for loop now.."<<endl;
           //break;
            //}while(c4<2);

            fstream fout;

            fout.open("Persons_data.txt",ios::out);
        if(!fout.is_open())
        {
            cout<<"Error file not found"<<endl;
        }
        else{
            cout<<"\n File opened \n"<<endl;
            if(flag2 == 0)
            {
                cout<<"Name"<<"\t\t"<<"Account_NO"<<"\t"<<"Card_NO\t"<<"\tPIN_No"<<endl;
                flag2 = 1;
            }
            for (int I = 0; I < count; I++)
            {
                /* code */
            cout<<pname[I]<<"\t"<<"\t"<<acclist[I]<<"\t"<<cardlist[I]<<"\t"<<pinlist[I]<<'\n'<<endl;
            fout<<pname[I]<<"\t"<<acclist[I]<<"\t"<<cardlist[I]<<"\t"<<pinlist[I]<<'\n';
            }

        }
        fout.close();

            for(int s = 0; s < count;s++)
            {
                cout<<"PIN NUMBER : "<<pinlist[s]<<endl;
//                vec6[s] = pinlist[s];//                cout<<"Vector PIN NUMBER : "<<vec6[s]<<endl;
            }
        }
};
int main()
{
    int N;
    string line,name,acn,cno,pno,flag = "0";
    cout<<"Enter how many person's details you want to add :- "<<endl;
    cin>>N;

    //std::vector<Login> lg(N);//Access ac[N];
    ATM atm;
    std::vector <Access> ac(N);
    Access a;
    std::vector <Login> vl;

     for(int K = 0;K<N;K++)
    {
        ac[K].accept_customer_details();
    }

     for(int I=0;I<N;I++)
     {
         ac[I].display_customer_details();
     }

    a.account_ass();
    a.Pin_change();

    return 0;
}
