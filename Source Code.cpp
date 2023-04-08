// Source Code for Periodic Table Project
// Developed by Guru Vishnu M (2019)

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<process.h>
#include<iomanip.h>

class Element
{
 int Atomic_Number;
 char Element_Name[100];
 char Element_Symbol[5];
 float Atomic_Weight;
 int Group,Period;
 public:
  int Return_Z();    //Function to Return Atomic_Number
  int Return_G();    //Function to Return Group Number
  int Return_P();    //Function to Return Period Number
  char* Return_X();  //Function to Return Element_Symbol
  void Add(int);     //Function to Add a New Element
  void Edit();       //Function to Edit the Details of an Existing Element
  void Show1();      //Function to Show the Details of an Existing Element in Format 1
  void Show2();      //Function to Show the Details of an Existing Element in Format 2
};

int Element::Return_Z()
{
 return Atomic_Number;
}

int Element::Return_G()
{
 return Group;
}

int Element::Return_P()
{
 return Period;
}

char* Element::Return_X()
{
 return Element_Symbol;
}

void Element::Add(int Z)
{
 Atomic_Number=Z;
 if(Atomic_Number>=100)
 {
  char ch;
  cout<<"\nDo you want to assign Systematic Element Name\n"
      <<"and Element Symbol for Element "<<Atomic_Number<<"? (Y/N) : ";
  cin>>ch;

  if(ch=='Y'||ch=='y')
  {
   int digit1,digit2,digit3;

   digit1=Atomic_Number/100;
   digit2=(Atomic_Number/10)-(digit1*10);
   digit3=Atomic_Number%10;

   switch(digit1)
   {
    case 1:strcpy(Element_Name,"Un");
	   strcpy(Element_Symbol,"U");
	   break;
    case 2:strcpy(Element_Name,"Bi");
	   strcpy(Element_Symbol,"B");
	   break;
    case 3:strcpy(Element_Name,"Tri");
	   strcpy(Element_Symbol,"T");
	   break;
    case 4:strcpy(Element_Name,"Quad");
	   strcpy(Element_Symbol,"Q");
	   break;
    case 5:strcpy(Element_Name,"Pent");
	   strcpy(Element_Symbol,"P");
	   break;
    case 6:strcpy(Element_Name,"Hex");
	   strcpy(Element_Symbol,"H");
	   break;
    case 7:strcpy(Element_Name,"Sept");
	   strcpy(Element_Symbol,"S");
	   break;
    case 8:strcpy(Element_Name,"Oct");
	   strcpy(Element_Symbol,"O");
	   break;
    case 9:strcpy(Element_Name,"Enn");
	   strcpy(Element_Symbol,"E");
	   break;
   }

   switch(digit2)
   {
    case 0:strcat(Element_Name,"nil");
	   strcat(Element_Symbol,"n");
	   break;
    case 1:strcat(Element_Name,"un");
	   strcat(Element_Symbol,"u");
	   break;
    case 2:strcat(Element_Name,"bi");
	   strcat(Element_Symbol,"b");
	   break;
    case 3:strcat(Element_Name,"tri");
	   strcat(Element_Symbol,"t");
	   break;
    case 4:strcat(Element_Name,"quad");
	   strcat(Element_Symbol,"q");
	   break;
    case 5:strcat(Element_Name,"pent");
	   strcat(Element_Symbol,"p");
	   break;
    case 6:strcat(Element_Name,"hex");
	   strcat(Element_Symbol,"h");
	   break;
    case 7:strcat(Element_Name,"sept");
	   strcat(Element_Symbol,"s");
	   break;
    case 8:strcat(Element_Name,"oct");
	   strcat(Element_Symbol,"o");
	   break;
    case 9:strcat(Element_Name,"enn");
	   strcat(Element_Symbol,"e");
	   break;
   }

   switch(digit3)
   {
    case 0:strcat(Element_Name,"nillium");
	   strcat(Element_Symbol,"n");
	   break;
    case 1:strcat(Element_Name,"unnium");
	   strcat(Element_Symbol,"u");
	   break;
    case 2:strcat(Element_Name,"bium");
	   strcat(Element_Symbol,"b");
	   break;
    case 3:strcat(Element_Name,"trium");
	   strcat(Element_Symbol,"t");
	   break;
    case 4:strcat(Element_Name,"quadium");
	   strcat(Element_Symbol,"q");
	   break;
    case 5:strcat(Element_Name,"pentium");
	   strcat(Element_Symbol,"p");
	   break;
    case 6:strcat(Element_Name,"hexium");
	   strcat(Element_Symbol,"h");
	   break;
    case 7:strcat(Element_Name,"septium");
	   strcat(Element_Symbol,"s");
	   break;
    case 8:strcat(Element_Name,"octium");
	   strcat(Element_Symbol,"o");
	   break;
    case 9:strcat(Element_Name,"ennium");
	   strcat(Element_Symbol,"e");
	   break;
   }
   cout<<endl;

   cout<<"Element Name  : "<<Element_Name<<endl;
   cout<<"Element Symbol: "<<Element_Symbol<<endl;

   goto label_1;
  }
 }
 cout<<endl;
 cout<<"Element Name  : ";
 cin>>Element_Name;
 cout<<"Element Symbol: ";
 cin>>Element_Symbol;
 label_1:
 cout<<"Atomic Weight : ";
 cin>>Atomic_Weight;
 label_G:
 cout<<"Group         : ";
 cin>>Group;
 if(Group>18||Group<=0)
 {
  cout<<"\nINVALID Group Number\nEnter values only from 1 to 18\n\n";
  goto label_G;
 }
 label_P:
 cout<<"Period        : ";
 cin>>Period;
 if(Period>8||Period<=0)
 {
  cout<<"\nINVALID Period Number\nEnter values only from 1 to 8\n\n";
  goto label_P;
 }
}

void Element::Edit()
{
 cout<<"\nOld Details of the Element\n";
 Show1();
 cout<<"\n\nEnter the New Details of the Element\n";
 char E_Name[100];
 char E_Symbol[5];
 float A;
 int G,P;
 cout<<"\nNew Element Name   (Enter '#' to retain old one) : ";
 cin>>E_Name;
 if(strcmp(E_Name,"#")!=0)
  strcpy(Element_Name,E_Name);
 cout<<"New Element Symbol (Enter '#' to retain old one) : ";
 cin>>E_Symbol;
 if(strcmp(E_Symbol,"#")!=0)
  strcpy(Element_Symbol,E_Symbol);
 cout<<"New Atomic Weight  (Enter  0  to retain old one) : ";
 cin>>A;
 if(A!=0)
  Atomic_Weight=A;
 label_G:
 cout<<"New Group          (Enter  0  to retain old one) : ";
 cin>>G;
 if(G>18||G<0)
 {
  cout<<"\nINVALID Group Number\nEnter values only from 1 to 18\n\n";
  goto label_G;
 }
 if(G!=0)
  Group=G;
 label_P:
 cout<<"New Period         (Enter  0  to retain old one) : ";
 cin>>P;
 if(P>8||P<0)
 {
  cout<<"\nINVALID Period Number\nEnter values only from 1 to 8\n\n";
  goto label_P;
 }
 if(P!=0)
  Period=P;
}

void Element::Show1()
{
 cout<<"\nAtomic Number : "<<Atomic_Number;
 cout<<"\nElement Name  : "<<Element_Name;
 cout<<"\nElement Symbol: "<<Element_Symbol;
 cout.setf(ios::fixed);
 cout.setf(ios::showpoint);
 cout<<setprecision(3);
 cout<<"\nAtomic Weight : "<<Atomic_Weight;
 cout.unsetf(ios::showpoint);
 cout.unsetf(ios::fixed);
 cout<<"\nGroup         : "<<Group;
 cout<<"\nPeriod        : "<<Period;
}

void Element::Show2()
{
 cout<<setw(3)<<Atomic_Number<<"\t";
 cout<<setw(12)<<Element_Name<<"\t";
 cout<<setw(3)<<Element_Symbol<<"\t";
 cout.setf(ios::fixed);
 cout.setf(ios::showpoint);
 cout<<setprecision(3);
 cout<<setw(8)<<Atomic_Weight<<"\t";
 cout.unsetf(ios::showpoint);
 cout.unsetf(ios::fixed);
 cout<<setw(2)<<Group<<"\t"<<Period;
}

void User_Manual();     //Function to Diplay User Manual
void Add_Element();     //Function to Add a New Element
void Edit_Element();    //Function to Edit the Details of an Existing Element
void Show_Element();    //Function to Show the Details of an Existing Element in Format 1
void Show_Elements();   //Function to Show the Details of an Existing Element in Format 2
void Delete_Element();  //Function to Delete an Element
int Search_Element(int);//Function to Search an Element
void Print_Periodic_Table();    //Function to Print the Periodic Table
void Insertion_Sort(int[],int); //Function to Sort an Integer Array using Insertion Sort

void main()
{
 clrscr();
 int Menu_Choice;

 do
 {
  clrscr();

  cout<<"\n\t\t\t PERIODIC TABLE OF THE ELEMENTS";
  cout<<"\n\nMenu :\n";
  cout<<"\n 1. User Manual";
  cout<<"\n 2. Add a New Element";
  cout<<"\n 3. Edit the details of an Existing Element";
  cout<<"\n 4. View the Details of an Element ";
  cout<<"\n 5. View the Details for a Set of Elements ";
  cout<<"\n 6. Delete an Existing Element ";
  cout<<"\n 7. Print Periodic Table ";
  cout<<"\n 8. Exit ";
  cout<<"\n\nEnter your choice (1-8)  : ";
  cin>>Menu_Choice;

  switch(Menu_Choice)
  {
   case 1:User_Manual();
	  break;
   case 2:Add_Element();
	  break;
   case 3:Edit_Element();
	  break;
   case 4:Show_Element();
	  break;
   case 5:Show_Elements();
	  break;
   case 6:Delete_Element();
	  break;
   case 7:Print_Periodic_Table();
	  break;
   default:exit(0);
  }
 }while(Menu_Choice!=8);
}

void User_Manual()
{
 clrscr();

 cout<<"\nKindly Read the following Instructions:\n"
     <<"\n\nThis program is designed to store details of 136 Elements. "
     <<"Elements from Atomic Number 119 should have Period Number 8"
     <<"\n\nIn this program Lanthanum (Z=57) and Actinum (Z=89) are "
     <<"considered as d-block \nElements."
     <<"\n\nFor entering details of Lathanides and Actinides, Kindly "
     <<"enter Group number \nstarting from 5. Period number for Lathanides "
     <<"and Actinides should be entered as6 and 7 respectively"
     <<"\n\nFor Example,\nFor the Element, "
     <<"Cerium (Z=58), enter Group number as 5 and Period number as 6."
     <<"\n\nThis is to preserve the structure of the Periodic Table.";

 gotoxy(1,24);
 cout<<"Press any key to Return to Menu";
 getch();
}

void Add_Element()
{
 Element E;
 fstream F;
 F.open("Periodic_Table.dat",ios::binary|ios::in|ios::app);
 int Z;
 char ch;
 do
 {
  clrscr();
  cout<<"\nEnter the details of the New Element :\n\n";
  label_Z:
  cout<<"Atomic Number : ";
  cin>>Z;
  if(Z<=0)
  {
   cout<<"\nINVALID Atomic Number\nEnter only Natural Numbers\n\n";
   goto label_Z;
  }
  int c=0;
  c=Search_Element(Z);
  if(c==0)
  {
   E.Add(Z);
   F.write((char*)&E,sizeof(E));
  }
  else
  {
   cout<<"\nElement "<<Z<<" Already Exists\n";
   cout<<"\nDo you want to edit its details? (Y/N) : ";
   cin>>ch;
   if(ch=='Y'||ch=='y')
    Edit_Element();
  }
  cout<<"\nDo you want to Add More? (Y/N) : ";
  cin>>ch;
 }while(ch=='Y'||ch=='y');
 F.close();

 gotoxy(1,24);
 cout<<"Press any key to Return to Menu";
 getch();
}

void Edit_Element()
{
 clrscr();
 Element E;
 fstream F;
 F.open("Periodic_Table.dat",ios::binary|ios::in|ios::out);
 int Z,found=0;
 long pos;
 cout<<"\nEnter the Atomic Number of the Element to Edit its details : ";
 cin>>Z;
 while(!F.eof())
 {
  pos=F.tellg();
  F.read((char*)&E,sizeof(E));
  if(E.Return_Z()==Z)
  {
   found=1;
   E.Edit();
   F.seekg(pos);
   F.write((char*)&E,sizeof(E));
   cout<<"\nElement Details succesfully Edited";
   break;
  }
 }
 if(!found)
 {
  char ch;
  cout<<"\nDetails of Element "<<Z<<" is Not Found\n";
  cout<<"\nDo you want to Add this Element? (Y/N) : ";
  cin>>ch;
  if(ch=='Y'||ch=='y')
   Add_Element();
 }
 F.close();

 gotoxy(1,24);
 cout<<"Press any key to Return to Menu";
 getch();
}

void Show_Element()
{
 Element E;
 ifstream F;
 int Z,status;
 char ch;
 do
 {
  clrscr();
  F.open("Periodic_Table.dat",ios::binary|ios::in);
  status=0;
  label_Z:
  cout<<"\nEnter the Atomic Number of the Element to View its Details : ";
  cin>>Z;
  if(Z<=0)
  {
   cout<<"\nINVALID Atomic Number\nEnter only Natural Numbers\n\n";
   goto label_Z;
  }
  while(F.read((char*)&E,sizeof(E)))
  {
   if(Z==E.Return_Z())
   {
    E.Show1();
    status=1;
   }
  }
  if(!status)
  {
   char ch;
   cout<<"\nDetails of Element "<<Z<<" is Not Found\n";
   cout<<"\nDo you want to Add this Element? (Y/N) : ";
   cin>>ch;
   if(ch=='Y'||ch=='y')
    Add_Element();
  }
  F.close();
  cout<<"\n\nDo you want to View More? (Y/N) : ";
  cin>>ch;
 }while(ch=='Y'||ch=='y');

 gotoxy(1,24);
 cout<<"Press any key to Return to Menu";
 getch();
}

void Show_Elements()
{
 clrscr();
 Element E;
 ifstream F;
 int I[2][16],i,n,s=0;
 label:
 cout<<"\nEnter the Number of Elements (Maximum 15) : ";
 cin>>n;
 if(n>15)
 {
  cout<<"\nEnter values only from 1 to 15";
  goto label;
 }

 cout<<"\nEnter the Atomic Numbers of Elements to View their Details :\n\n";
 for(i=1;i<=n;i++)
 {
  label_i:
  cin>>I[0][i];
  if(I[0][i]<=0)
  {
   cout<<"\nINVALID Atomic Number\nEnter only Natural Numbers\n\n";
   goto label_i;
  }
  I[1][i]=0;
 }

 Insertion_Sort(I[0],n);

 clrscr();
 cout<<"\nS.No  Atomic\tElement Name\tElement\t  Atomic \tGroup\tPeriod";
 cout<<"\n      Number\t            \tSymbol \t  Weight \n\n";
 for(i=1;i<=n;i++)
 {
  F.open("Periodic_Table.dat",ios::binary|ios::in);
  while(F.read((char*)&E,sizeof(E)))
  {
   if(I[0][i]==E.Return_Z())
   {
    I[1][i]=1;
    cout<<setw(2)<<++s<<"\t";
    E.Show2();
    cout<<"\n";
   }
  }
  F.close();
 }
 for(i=1;i<=n;i++)
 {
  if(I[1][i]==0)
   cout<<"\nDetails of Element "<<I[0][i]<<" Not Found";
 }

 gotoxy(1,24);
 cout<<"Press any key to Return to Menu";
 getch();
}

void Delete_Element()
{
 clrscr();
 Element E;
 ifstream F;
 ofstream G;
 F.open("Periodic_Table.dat",ios::binary|ios::in);
 G.open("Temporary.dat",ios::binary|ios::out);
 int Z,found=0;
 char ch;
 cout<<"\nEnter the Atomic Number of the Element to DELETE its Details :";
 cin>>Z;
 while(F.read((char*)&E,sizeof(E)))
 {
  if(Z==E.Return_Z())
  {
   found=1;
   cout<<"\nElement Found";
   cout<<"\nAre you sure you want to Permanently DELETE this Element? (Y/N) : ";
   cin>>ch;
   if(ch=='N'||ch=='n')
    G.write((char*)&E,sizeof(E));
   else
    cout<<"\nElement "<<Z<<" Deleted Successfully";
  }
  else
   G.write((char*)&E,sizeof(E));
 }
 if(!found)
  cout<<"\nElement Not Found";
 F.close();
 G.close();
 remove("Periodic_Table.dat");
 rename("Temporary.dat","Periodic_Table.dat");

 gotoxy(1,24);
 cout<<"Press any key to Return to Menu";
 getch();
}

int Search_Element(int Z)
{
 Element E;
 ifstream F;
 F.open("Periodic_Table.dat",ios::binary|ios::in);
 while(F.read((char*)&E,sizeof(E)))
 {
  if(Z==E.Return_Z())
   return 1;
 }
 return 0;
}

void Print_Periodic_Table()
{
 Element E;
 ifstream F;
 F.open("Periodic_Table.dat",ios::binary|ios::in);

 char X[10][18][10];
 int Z[10][18];
 int i,j;

 for(i=0;i<10;i++)
  for(j=0;j<18;j++)
  {
   X[i][j][0]='#';
   Z[i][j]=0;
  }

 while(F.read((char*)&E,sizeof(E)))           //Transfer Block
 {
  if(E.Return_Z()<=57||(E.Return_Z()>=72&&E.Return_Z()<=89)||E.Return_Z()>=104)
  {
   strcpy(X[E.Return_P()-1][E.Return_G()-1],E.Return_X());
   Z[E.Return_P()-1][E.Return_G()-1]=E.Return_Z();
  }
  else
  {
   strcpy(X[E.Return_P()+2][E.Return_G()-1],E.Return_X());
   Z[E.Return_P()+2][E.Return_G()-1]=E.Return_Z();
  }
 }

 F.close();

 clrscr();
 cout<<"\n\t\t\t PERIODIC TABLE OF THE ELEMENTS\n";  //Display block

 cout<<" ";
 for(j=0;j<18;j++)
  cout<<setw(3)<<j+1<<" ";
 cout<<"\n";

 for(i=0;i<10;i++)
 {
  if(i<8)
   cout<<i+1;
  else
   cout<<" ";

  for(j=0;j<18;j++)
  {
   if(X[i][j][0]!='#')
    cout<<setw(3)<<X[i][j];
   else
    cout<<setw(3)<<" ";
   cout<<" ";
  }
  cout<<"\n";
  cout<<" ";

  for(j=0;j<18;j++)
  {
   if(Z[i][j]!=0)
    cout<<setw(3)<<Z[i][j];
   else
    cout<<setw(3)<<" ";
   cout<<" ";
  }
  cout<<"\n";
 }

 gotoxy(1,24);
 cout<<"Press any key to Return to Menu";
 getch();
}

void Insertion_Sort(int A[],int size)
{
 int temp,i,j;
 A[0]=INT_MIN;
 for(i=1;i<=size;i++)
 {
  temp=A[i];
  j=i-1;
  while(temp<A[j])
  {
   A[j+1]=A[j];
   j--;
  }
  A[j+1]=temp;
 }
}
