#include<iostream>
#include<fstream>
#include <windows.h>
#include<stdlib.h>

using namespace std;

class clinic
{
    int age;
    char bg[5];
    char mno[11];
    char city[15];
    char tal[15];
    char dist[15];

protected:
    int id;
    char name[10];
    char lname[10];


public:

    void getdata();
    void showdata();
    void storedata();
    int searchdata(int);
    void searchdata();
    void update(int pid);
    void exit();
    bool validmobile(char[]);
    bool validstring(char nam[]);
    void bloodgroup();
    int getid();

}c1;


void clinic::getdata()
{
    cout<<"\n Patient ID ";
    id=getid();

    cout<<id;

    while(1)
    {
        cout<<"\nEnter Patient First Name \n";
        cin>>name;
        if(validstring(name))
            break;
    }

    while(1)
    {
        cout<<"\nEnter Patient Last Name \n";
        cin>>lname;
        if(validstring(lname))
            break;
    }


    do
    {
        cout<<"\nEnter Patient age \n";
        cin>>age;
        if(age>1 && age<100)
            break;
        else
            cout<<"Age not VALID "<<endl;
    }
    while(1);


    cout<<"\nChose Patient blood group \n";
    bloodgroup();

    cin.ignore();
    while(1)
    {
        cout<<"\nEnter Patient Mobile No \n";
        cin>>mno;
        if(validmobile(mno))
            break;
    }

    cout<<"\nEnter Patient Address \n";
    while(1)
    {
        cout<<"\tCity: ";
        cin>>city;
        if(validstring(city))
            break;
        else
            cout<<"\nRe-enter city name: "<<endl;
    }

    while(1)
    {
        cout<<"\tTaluka: ";
        cin>>tal;
        if(validstring(tal))
            break;
        else
            cout<<"Re-enter Taluka name: "<<endl;
    }

    while(1)
    {
        cout<<"\tDistrict: ";
        cin>>dist;
        if(validstring(dist))
            break;
        else
            cout<<"Re-enter District name: "<<endl;
    }

    cout<<"-----------------------"<<endl;
}


bool clinic::validmobile(char mno[])
{
    if (strlen(mno)==10)
    {

        for(int i=0; i<10; i++)
        {
            if(!isdigit(mno[i]))
            {
                return false;
            }
        }
    }
    else
    {
        cout<<"NOT valid mobile number "<<endl;
        return false;
    }
    cout<<"Valid mobile Number "<<endl;
    return true;
}


void clinic:: showdata()
{
    cout<<"patient case no  \t"<<id<<endl;
    cout<<"patient First Name  \t"<<name<<endl;
    cout<<"patient Last Name  \t"<<lname<<endl;
    cout<<"patient age  \t\t"<<age<<endl;
    cout<<"patient blood group  \t"<<bg<<endl;
    cout<<"mobile Number  \t\t"<<mno<<endl;
    cout<<"**Patient Address** \n";
    cout<<"\tCity \t\t"<<city<<endl;
    cout<<"\tTaluka \t\t"<<tal<<endl;
    cout<<"\tDistrict \t"<<dist<<endl;

    cout<<"----------------------------------------------------------"<<endl;
}

void clinic:: storedata()
{
    ofstream fout;
    fout.open("clinic.txt",ios::app);
    fout.write((char *)this,sizeof(*this));
    fout.close();
    cout<<"\n Data is stored in file \n";
}


void clinic :: update(int pid)
{
    int val,ch;
    char a;
    fstream file;
    file.open("clinic.txt",ios::in|ios::out|ios::app);

    file.seekg(0);

    file.read((char*)this,sizeof(*this));
    while(!file.eof())
    {

        if(id==pid)
        {
            val=file.tellp();
            file.seekp(val- sizeof(*this));
            showdata();

            cout<<"\n\t1. Patient First Name \n";
            cout<<"\t2. Patient Last Name \n";
            cout<<"\t3. Patient age \n";
            cout<<"\t4. Patient blood group \n";
            cout<<"\t5. Patient Mobile No \n";
            cout<<"\t6. City:\n";
            cout<<"\t7. Taluka: \n";
            cout<<"\t8. Dist: \n";

repeat:
            cout<<"\nWhich Field Do You Want TO Update : ";
            cin>>ch;

            switch(ch)
            {
            case 1:
                while(1)
                {
                    cout<<"\nEnter Patient First Name \n";
                    cin>>name;
                    if(validstring(name))
                        break;
                }
                break;

            case 2:
                while(1)
                {
                    cout<<"\nEnter Patient Last Name \n";
                    cin>>lname;
                    if(validstring(lname))
                        break;
                }
                break;

            case 3:
                do
                {
                    cout<<"\nEnter Patient age \n";
                    cin>>age;
                    if(age>4 && age<100)
                        break;
                    else
                        cout<<"Age not VALID "<<endl;
                }
                while(1);
                break;

            case 4:
                cout<<"\nChose Patient blood group \n";
                bloodgroup();
                break;

            case 5:
                while(1)
                {
                    cout<<"\nEnter Patient Mobile No \n";
                    cin>>mno;
                    if(validmobile(mno))
                        break;
                }
                break;

            case 6:
                while(1)
                {
                    cout<<"\tCity: ";
                    cin>>city;
                    if(validstring(city))
                        break;
                    else
                        cout<<"\nRe-enter city name: "<<endl;
                }
                break;
            case 7:
                while(1)
                {
                    cout<<"\tTaluka: ";
                    cin>>tal;
                    if(validstring(tal))
                        break;
                    else
                        cout<<"Re-enter Taluka name: "<<endl;
                }
                break;

            case 8:
                while(1)
                {
                    cout<<"\tDistrict: ";
                    cin>>dist;
                    if(validstring(dist))
                        break;
                    else
                        cout<<"Re-enter District name: "<<endl;
                }
                break;

            default:
                cout<<"\nPlease Enter Valid choice...!"<<endl;
            }

            cout<<"\nDo You Want To Continue...?y/n ";
            cin>>a;

            if(a=='Y'||a=='y')
            {
                goto repeat;
            }
            else
            {
                file.write((char *)this,sizeof(*this));
                file.close();
                cout<<"\n Data is stored in file"<<endl;
                // storedata();
                break;
            }

        }
        file.read((char*)this,sizeof(*this));
    }

}


int clinic::searchdata(int pid)
{
    ifstream fin;
    int flag=1;

    fin.open("clinic.txt",ios::in);
    if(!fin)
        cout<<"File is not opening ";
    else
        {
            fin.read((char *)this,sizeof(*this));
            while(!fin.eof())
            {
                if(pid==id)
                {
                    showdata();
                    return 1;
                }
                fin.read((char *)this,sizeof(*this));
            }
                printf("\nRecord Not Found...!");
                return 0;
        }
}


void clinic::searchdata()
{
    ifstream fin;

    fin.open("clinic.txt",ios::in);
    if(!fin)
        cout<<"File is not opening ";

    fin.read((char *)this,sizeof(*this));
    while(!fin.eof())
    {
        showdata();
        fin.read((char *)this,sizeof(*this));
    }
}


void clinic::exit()
{
    system("cls");
    cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout<<"\t@@ _______________________________________________________________________________________ @@\n";
    cout<<"\t@@|                                           		                                  |@@\n";
    cout<<"\t@@|                                           		                                  |@@\n";
    cout<<"\t@@|                                           		                                  |@@\n";
    cout<<"\t@@|                                           		                                  |@@\n";
    cout<<"\t@@|                                           		                                  |@@\n";
    cout<<"\t@@|                               THANK YOU FOR USING                                     |@@\n";
    cout<<"\t@@|                                                                                       |@@\n";
    cout<<"\t@@|                            DENTAL CLINIC SYSTEM                                       |@@\n";
    cout<<"\t@@|                                                                                       |@@\n";
    cout<<"\t@@|                                                                                       |@@\n";
    cout<<"\t@@|                                                                                       |@@\n";
    cout<<"\t@@|                                                                                       |@@\n";
    cout<<"\t@@|                                                                                       |@@\n";
    cout<<"\t@@|                                                                                       |@@\n";
    cout<<"\t@@|_______________________________________________________________________________________|@@\n";
    cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";

}

bool clinic::validstring(char nam[])
    {
        int namelen,i;
        while(nam[i]!='\0')
        {
            i++;
        }

        namelen=i;
        for(int i=0; i<namelen; i++)
        {
            if(!isalpha(nam[i]) || namelen<3)
            {
                cout<<"INVALID";
                return false;
            }
        }
        return true;
    }

void clinic::bloodgroup()
    {
        int ch;
z:
        cout<<"\t\t1.A+"<<endl;
        cout<<"\t\t2.AB+"<<endl;
        cout<<"\t\t3.B+"<<endl;
        cout<<"\t\t4.O+"<<endl;
        cout<<"\t\t5.A-"<<endl;
        cout<<"\t\t6.AB-"<<endl;
        cout<<"\t\t7.B-"<<endl;
        cout<<"\t\t8.O-"<<endl;
        cout<<"Enter Your Choice ";
        cin>>ch;

        switch(ch)
        {
        case 1:
            bg[0]='A';
            bg[1]='+';
            break;

        case 2:
            bg[0]='A';
            bg[1]='B';
            bg[2]='+';
            break;

        case 3:
            bg[0]='B';
            bg[1]='+';
            break;

        case 4:
            bg[0]='O';
            bg[1]='+';
            break;

        case 5:
            bg[0]='A';
            bg[1]='-';
            break;

        case 6:
            bg[0]='A';
            bg[1]='B';
            bg[2]='-';
            break;

        case 7:
            bg[0]='B';
            bg[1]='-';
            break;

        case 8:
            bg[0]='O';
            bg[1]='-';
            break;

        default:
            cout<<endl<<"Please Enter Valid Choice "<<endl;
            goto z;
        }
    }


int clinic::getid()
    {
        int temp;
        fstream file;
        file.open("clinic.txt",ios::in|ios::app);

        file.read((char*)this,sizeof(*this));
        if(!file.eof())
        {
            do
            {
                temp=id;
                file.read((char*)this,sizeof(*this));
            }
            while(!file.eof());
            return temp+1;
        }

        else
        {
            return 1001;
            //cout<<"hello";
        }
}


class treatment:private clinic
{
    int treatno[10];
    float docfee;
    float casefee;
    float treatfee;
    float total;

public:
    void bill();
    treatment();
    void showbill();
    void storebill();
    int searchbill(int);
} b1;

treatment::treatment()      // Constructor
{
    docfee=100;
    casefee=250;
}

void treatment::bill()
{
    int ch,i=0,pid;
    total=0;
    char a;

    cout<<"Enter the patient id\n";
    cin>>pid;
    if(searchdata(pid))
    {
        id=pid;
    cout<<"Treatment Details "<<endl<<endl;

    cout<<"\t1.Scalling"<<endl<<endl;
    cout<<"\t2.Silver Filling"<<endl<<endl;
    cout<<"\t3.Root Canal Treatment"<<endl<<endl;
    cout<<"\t4.Crown Prosthesis"<<endl<<endl;
    cout<<"\t5.Complete Denture"<<endl<<endl;
    cout<<"\t6.Removable Partial Denture"<<endl<<endl;
    cout<<"\t7.Mucogingival Surgury"<<endl<<endl;
    cout<<"\t8.Disimpaction"<<endl<<endl;
    cout<<"\t9.Minir Oral Surgury"<<endl<<endl;
    cout<<"\t10.Apicectomy"<<endl<<endl;
    cout<<"\t11.Composite Restoration"<<endl<<endl;
    cout<<"\t12.Fixed Bridge Prosthesis"<<endl<<endl;

repeat:

    cout<<"Enter Your Choice "<<endl;
    cin>>ch;

    switch(ch)
    {
    case 1:
        treatfee=100;
        cout<<"\t"<<i+1<<". Scalling\t\t\t Rs.100"<<endl;
        total=total+treatfee+docfee;
        treatno[i]=ch;
        break;

    case 2:
        treatfee=100;
        cout<<"\t"<<i+1<<". Silver Filling\t\t Rs.100"<<endl;
        total=total+treatfee+docfee;
        treatno[i]=ch;
        break;

    case 3:
        treatfee=300;
        cout<<"\t"<<i+1<<". Root Canal Treatment\t\t Rs.300"<<endl;
        total=total+treatfee+docfee;
        treatno[i]=ch;
        break;

    case 4:
        treatfee=1280;
        cout<<"\t"<<i+1<<"Crown Prosthesis\t\t Rs.1280"<<endl;
        total=total+treatfee+docfee;
        treatno[i]=ch;
        break;

    case 5:
        treatfee=300;
        cout<<"\t"<<i+1<<". Complete Denture\t\t Rs.300"<<endl;
        total=total+treatfee+docfee;
        treatno[i]=ch;
        break;

    case 6:
        treatfee=180;
        cout<<"\t"<<i+1<<" .Removable Partial Denture\t Rs.180"<<endl;
        total=total+treatfee+docfee;
        treatno[i]=ch;
        break;

    case 7:
        treatfee=1500;
        cout<<"\t"<<i+1<<" .Mucogingival Sugury\t\t Rs.1500"<<endl;
        total=total+treatfee+docfee;
        treatno[i]=ch;
        break;

    case 8:
        treatfee=300;
        cout<<"\t"<<i+1<<" .Disimpaction\t\t\t Rs.300"<<endl;
        total=total+treatfee+docfee;
        treatno[i]=ch;
        break;

    case 9:
        treatfee=1000;
        cout<<"\t"<<i+1<<". Minir Oral Surgury\t\t Rs.1000"<<endl;
        total=total+treatfee+docfee;
        treatno[i]=ch;
        break;

    case 10:
        treatfee=1500;
        cout<<"\t"<<i+1<<". Apicectomy\t\t\t Rs.1500"<<endl;
        total=total+treatfee+docfee;
        treatno[i]=ch;
        break;

    case 11:
        treatfee=300;
        cout<<"\t"<<i+1<<". Composite Restoration\t\t Rs.300"<<endl;
        total=total+treatfee+docfee;
        treatno[i]=ch;
        break;

    case 12:
        treatfee=4000;
        cout<<"\t"<<i+1<<". Fixed Bridge Prosthesis\t Rs.4000"<<endl;
        total=total+treatfee+docfee;
        treatno[i]=ch;
        break;

    default:
        printf("Please Enter Valid Choice...!");
        goto repeat;
    }

    if(i==0)
        total+=casefee;

    cout<<"\nDo You Want To Continue...! y/n ";
    cin>>a;

    if(a=='y' || a=='Y')
    {
        i++;
        //docfee*=2;
        goto repeat;
    }
    else
        {
            docfee*=(i+1);
            storebill();
            showbill();
        }

    }
}

void treatment::storebill()
{
   // cout<<"hello";
    FILE *fptr;
    fptr=fopen("data.txt","r+");
    fwrite(&b1,sizeof(class treatment),1,fptr);
    fflush(stdin);
    fclose(fptr);
    printf("\nData is Stored In FILE \n");
}


void treatment::showbill()
{
    cout<<"*******************************************************************************"<<endl;
    cout<<"\tPatient Case Paper No.\t"<<id<<endl;
    cout<<"*******************************************************************************"<<endl;

    cout<<"\tDoctor Fees\t\t\t Rs."<<docfee<<endl;
    cout<<"\tCase Paper Fees\t\t\t Rs."<<casefee<<endl;

    for(int i=0; i<=10; i++)
    {
        if(treatno[i]==1)
            cout<<"\t"<<i+1<<". Scalling\t\t\t Rs.100"<<endl;

        else if(treatno[i]==2)
            cout<<"\t"<<i+1<<". Silver Filling\t\t Rs.100"<<endl;

        else if(treatno[i]==3)
            cout<<"\t"<<i+1<<". Root Canal Treatment\t\t Rs.300"<<endl;

        else if(treatno[i]==4)
        cout<<"\t"<<i+1<<"Crown Prosthesis\t\t Rs.1280"<<endl;

        else if(treatno[i]==5)
        cout<<"\t"<<i+1<<". Complete Denture\t\t Rs.300"<<endl;

        else if(treatno[i]==6)
        cout<<"\t"<<i+1<<" .Removable Partial Denture\t Rs.180"<<endl;

        else if(treatno[i]==7)
        cout<<"\t"<<i+1<<" .Mucogingival Sugury\t\t Rs.1500"<<endl;

        else if(treatno[i]==8)
        cout<<"\t"<<i+1<<" .Disimpaction\t\t\t Rs.300"<<endl;

        else if(treatno[i]==9)
        cout<<"\t"<<i+1<<". Minir Oral Surgury\t\t Rs.1000"<<endl;

        else if(treatno[i]==10)
        cout<<"\t"<<i+1<<". Apicectomy\t\t\t Rs.1500"<<endl;

        else if(treatno[i]==11)
        cout<<"\t"<<i+1<<". Composite Restoration\t\t Rs.300"<<endl;

        else if(treatno[i]==12)
        cout<<"\t"<<i+1<<". Fixed Bridge Prosthesis\t Rs.4000"<<endl;

    }
    cout<<"*******************************************************************************"<<endl;
    cout<<"\tTotal\t\t\t\t Rs."<<total<<endl;
}


int treatment::searchbill(int pid)
{
     FILE *fptr;
    //int flag=1;

    fptr=fopen("data.txt","a+");
    //fptr.seekg(0);
    if(!fptr)
    {
        cout<<"File is not opening ";
        return 0;
    }
    else
        {
            //fread(&c,sizeof(struct child),1,fp);
            fread(&b1,sizeof(class treatment),1,fptr);
            while(!feof(fptr))
            {
                if(pid==id)
                {
                    showdata();
                    fclose(fptr);
                    return 1;
                }
                fread(&b1,sizeof(treatment),1,fptr);
            }
                printf("\nRecord Not Found...!");
                return 0;
        }
}
int main()
{
    system("Color E0");
    //system()

    cout<<"********************************************************************************************************************"<<endl<<endl;
    cout<<"******************************************************* DENTAL CLINIC SYSYTEM **************************************"<<endl<<endl;
    cout<<"************************************************************** WELCOME *********************************************"<<endl<<endl;
    cout<<"********************************************************************************************************************"<<endl<<endl;

    while(1)
    {
        int ch,pid;
        //clinic c1;
        //treatment b1;
        cout<<"\n\t  DENTAL CLINIC SYSTEM \n\n";
        cout<<"\n\tPlease,  Choose from the following Options: \n\n";
        cout<<"\t _________________________________________________________________\n";
        cout<<"\t|                                           	                  |\n";
        cout<<"\t|             1  >> Add New Patient Record                        |\n";
        cout<<"\t|             2  >> Search the Record                             |\n";
        cout<<"\t|             3  >> Update the Record                             |\n";
        cout<<"\t|             4  >> All patient details                           |\n";
        cout<<"\t|             5  >> Generate the Bill                             |\n";
        cout<<"\t|             6  >> Show Bill                                     |\n";
        cout<<"\t|             7  >> Exit                                          |\n";
        cout<<"\t|_________________________________________________________________|\n\n";

        cout<<"\nEnter your choice \n";
        cin>>ch;
        system("cls");

        switch(ch)
        {
        case 1:
            c1.getdata();
            c1.storedata();
            system("cls");
            break;

        case 2:
            cout<<"Enter the patient id to search ";
            cin>>pid;
            c1.searchdata(pid);
            break;

        case 3:
            cout<<"Enter the patient id to modify ";
            cin>>pid;
            c1.update(pid);
            break;

        case 4:
            cout<<"The details of all patients \n";
            c1.searchdata();
            break;

        case 5:
            b1.bill();
            //b1.showbill();
            //c1.storebill();
            break;

        case 6:
            cout<<"Enter the patient id \n";
            cin>>pid;
            if(b1.searchbill(pid))
                b1.showbill();
            break;

        case 7:
            cout<<"Exiting from program \n";
            system("cls");
            cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
            cout<<"\t@@ ______________________________________________________________________________ @@\n";
            cout<<"\t@@|                                           		                         |@@\n";
            cout<<"\t@@|                                           		                         |@@\n";
            cout<<"\t@@|                                           		                         |@@\n";
            cout<<"\t@@|                                           		                         |@@\n";
            cout<<"\t@@|                                           		                         |@@\n";
            cout<<"\t@@|                         THANK YOU FOR USING                                  |@@\n";
            cout<<"\t@@|                                                                              |@@\n";
            cout<<"\t@@|                         DENTAL CLINIC SYSTEM                                 |@@\n";
            cout<<"\t@@|                                                                              |@@\n";
            cout<<"\t@@|                                                                              |@@\n";
            cout<<"\t@@|                                                                              |@@\n";
            cout<<"\t@@|                                                                              |@@\n";
            cout<<"\t@@|                                                                              |@@\n";
            cout<<"\t@@|                                                                              |@@\n";
            cout<<"\t@@|______________________________________________________________________________|@@\n";
            cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
            return 0;
            break;
        }
    }
}
