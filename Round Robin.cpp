#include<iostream>
using namespace std;
int main()
{
	int i,j,k,q,n,TimeSlice,Temp;                  //te keeps a count of the no.of times a process enters the CPU before completion.
    int wa; 
	float AverageWaitingTime;
    int BurstTime[10],WaitingTime[10],te[10],Trunaround[10],ArrivalTime[10];j=0; 
	cout<<"Enter Number of Process"<<endl;
	cin>>n;
    for(i=0;i<n;i++)
    {
      cout<<"Enter Burst Time"<<endl; 
	  cin>>BurstTime[i];
	  cout<<"Enter Arrival Times"<<endl;
	  cin>>ArrivalTime[i];
	  te[i] = 0; WaitingTime[i] = 0;
	}
	for(i=0;i<n;i++)
	{
	 for(j=i+1;j<n;j++)
		{
		 if(ArrivalTime[j]<ArrivalTime[i])
			{
			 Temp = ArrivalTime[i];
			 ArrivalTime[i] = ArrivalTime[j];
			 ArrivalTime[j] = Temp;
         if(ArrivalTime[j] ==ArrivalTime[i])
			Temp = BurstTime[i];
			BurstTime[i] = BurstTime[j];
			BurstTime[j] = Temp;
		     }
		 }
	 }
	 cout<<"Enter Time Slice"<<endl;
	 cin>>TimeSlice;
	 cout<<"Process:"<<endl;
	    for(i=0;i<n;i++)
	 {
		 cout<<"\t"<<i+1<<endl;
	 } 
	cout<<"Burst Time:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"  "<<BurstTime[i]<<endl;
		Trunaround[i] = BurstTime[i];
	}
	cout<<"Arrival Time:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"  "<<ArrivalTime[i]<<endl;
	}
	cout<<"\t\t\t Gaint chart: \n\n\n"<<endl;
	while (j<=n)
	{
		j++;
		for(i = 0;i<n;i++)
		{
			if(Trunaround[i] ==0) 
			continue;
			if(Trunaround[i]>=TimeSlice)
			{
				cout<<"\t"<<q<<i+1<<endl;
				q = q + TimeSlice;
				Trunaround[i] = Trunaround[i] - TimeSlice;
				te[i] = te[i] + 1;
			}
			else
			{
				cout<<"  "<<q<<i+1<<endl;
				WaitingTime[i] = q-te[i]*TimeSlice;
				q = q +Trunaround[i];
				Trunaround[i] = Trunaround[i] - Trunaround[i];
			}
		}
	}
	AverageWaitingTime = 0;
	cout<<"Process Waiting Time:"<<endl;
	for(i=0;i<n;i++)
	{
		WaitingTime[i] = WaitingTime[i] + ArrivalTime[i];
		cout<<"  "<<i+1<<endl;
			cout<<WaitingTime[i]<<endl;
		AverageWaitingTime= AverageWaitingTime + WaitingTime[i];
	}
	wa = AverageWaitingTime;
	cout<<"Total Waiting Time:"<<wa<<endl;
	cout<<"Average Waiting Time:"<<AverageWaitingTime/n<<endl;
	return 0;
}

