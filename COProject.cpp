#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;
static int p = 0;
class Bus
{
  char Busno[5], Driver[10], Arrival[5], Departure[5], Source[10],Destination[10], seatno[8][4][10];
public:
  void install();
  void allotment();
  void Vacant();
  void show();
  void avail();
  void position(int i);
}
bus[10];
void vline(char ch)
{
  for (int i=63;i>0;i--)
  cout<<ch;
}
void Bus::install()
{
  cout<<"Enter bus no: ";
  cin>>bus[p].Busno;
  cout<<"\nEnter Driver's name: ";
  cin>>bus[p].Driver;
  cout<<"\nArrival time: ";
  cin>>bus[p].Arrival;
  cout<<"\nDeparture: ";
  cin>>bus[p].Departure;
  cout<<"\nFrom: \t\t\t";
  cin>>bus[p].Source;
  cout<<"\nTo: \t\t\t";
  cin>>bus[p].Destination;
  bus[p].Vacant();
  p++;
  system("cls");
}
void Bus::allotment()
{
  int seat;
  char number[5];
  top:
  cout<<"Bus no: ";
  cin>>number;
  int n;
  for(n=0;n<p;n++)
  {
    if(strcmp(bus[n].Busno, number)==0)
    break;
  }
  while(n<p)
  {
    cout<<"\nSeat Number: ";
    cin>>seat;
    if(seat>32)
    {
      cout<<"\nThere are only 32 seats available in this bus.";
  }
      else
    {
    if (strcmp(bus[n].seatno[seat/4][(seat%4)-1], "Vacant")==0) 
      {
        cout<<"Enter passanger's name: ";
        cin>>bus[n].seatno[seat/4][(seat%4)-1];
        break;
      }
    else
      cout<<"The seat no. is already reserved.\n";
      }
      }
    if(n>p)
    {
      cout<<"Enter correct bus no.\n";
      goto top;
    }
  }
void Bus::Vacant()
{
  for(int i=0; i<8;i++)
  {
    for(int j=0;j<4;j++)
    {
      strcpy(bus[p].seatno[i][j], "Vacant");
    }
  }
}
void Bus::show()
{
  int n;
  char number[5];
  cout<<"Enter bus no: ";
  cin>>number;
  for(n=0;n<p;n++)
  {
    if(strcmp(bus[n].Busno, number)==0)
    break;
  }
while(n<p)
{
  vline('*'); 
  cout<<"Bus no: "<<bus[n].Busno;
   vline('*');
 cout<<"\nDriver: \t"<<bus[n].Driver<<"\t\tArrival time: \t"<<bus[n].Arrival<<"\tDeparture time:"<<bus[n].Departure<<"\nSource: \t"<<bus[n].Source<<"\t\tDestination: \t"<< bus[n].Destination<<"\n";
 
  bus[n].position(n);
  int a=1;
  for (int i=0; i<8; i++)
  {
    for(int j=0;j<4;j++)
    {
      ++a;
      if(strcmp(bus[n].seatno[i][j],"Vacant")!=0)
      cout<<"\nThe seat no "<<a-1<<" is reserved for "<<bus[n].seatno[i][j]<<".";
     }
  }
  break;
  }
  if(n>p)
    cout<<"Enter correct bus no: ";
}
void Bus::position(int l)
{
  int s=0;p=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0;j<4; j++)
    {
      s++;
      if(strcmp(bus[l].seatno[i][j], "Vacant")==0)
        {
          cout.width(7);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(14);
          cout.fill(' ');
          cout<<bus[l].seatno[i][j];
          p++;
        }
        else
        {
        cout.width(7);
        cout.fill(' ');
        cout<<s<<".";
        cout.width(14);
        cout.fill(' ');
        cout<<bus[l].seatno[i][j];
        }
      }
    }
  cout<<"\n\nThere are "<<p<<" seats vacant in Bus No: "<<bus[l].Busno;
  }
void Bus::avail()
{
 for(int n=0;n<p;n++){
 if (strlen(bus[n].Busno)!=0 && strlen(bus[n].Driver)!=0 && strlen(bus[n].Arrival)!=0 && strlen(bus[n].Departure)!=0 && strlen(bus[n].Source)!=0 && strlen(bus[n].Destination)!=0)
  {
    vline('*');
    cout<<"Bus no: "<<bus[n].Busno;
    vline('*');
    cout<<"\nDriver: \t"<<bus[n].Driver<<"\t\tArrival time: \t"<<bus[n].Arrival<<"\tDeparture Time: \t"<<bus[n].Departure<<"\nSource: \t"<<bus[n].Source<<"\t\t\t\t\tDestination: \t\t" <<bus[n].Destination<<"\n";
    
  }
 }
}
int main()
{
system("cls");
int w;
while(1)
{

  cout<<"\n\n";
  cout<<"\t\t\t1.Bus Entry\n\t\t\t"<<"2.Book Your Bus\n\t\t\t"<<"3.Show Booking Details\n\t\t\t"<<"4.Buses Available. \n\t\t\t"<<"5.Exit";
cout<<"\n\t\t\tEnter your choice: ";
  cin>>w;
  switch(w)
  {
    case 1:  bus[0].install();
      break;
    case 2:  bus[0].allotment();
      break;
    case 3:  bus[0].show();
      break;
    case 4:  bus[0].avail();
      break;
    case 5:  exit(0);
    
  }
  
}
return 0;
}

