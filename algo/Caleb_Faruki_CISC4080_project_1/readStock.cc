/**********************************************************************
* Author: Caleb Faruki
* Course: CISC4080 Algorithms
* Date: September 27, 2013
* File: read information from stocks.
**********************************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Stock.h"

//finance.yahoo.com

using namespace std;
#define output_bit 1 // change it to 1/0 if you want(don’t want to print/output

//debug tip: pause your program
void pauseIT() {
	cout <‌< "Wait, press ENTER to continue,...";
	cin.clear(); //clear errors
	cin.sync(); //clear the buffer
	cin.get(); //wait for a letter
}

void setOutputPrecision(int n){
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(n);
}

int main(int argc, char** argv) {

	static int n;

	int* n;

	n = new int[1000];

	const int n = 249;
	Stock GoogleStock[n]; // a struct array
	char filename[100] = "google_stock_.txt";
	double *google_stock_adj_close=new double[n];
	FILE *fp;
	char header[100];
	// items since the 2nd line in the file
	double open, high, low, close, adj_close;
	int volume;
	char date[10];
	//header information
	char date_s[10],open_s[10], high_s[10], low_s[10],
	close_s[10], volume_s[10], adj_s[10], adj_close_s[10];
	int i=0;
	// Read a file
	fp=fopen(filename, "r"); //open a file for read
	// book keeping: make sure it is not a NULL
	if(!fp)
		perror("Double-check your input file");
	// read the header information (first line)
	if(!feof(fp)){
		fscanf(fp, "%s %s %s %s %s %s %s %s\n", date_s, open_s,
		high_s, low_s, close_s,volume_s, adj_s, adj_close_s);
	}
	// merge the "adj" and "Close" to "AdjClose"
	strcat(adj_s, adj_close_s);
	strcpy(adj_close_s, adj_s);
	//read the main information from the 2nd line to the file end:
	// feof will tell you if the file ends
	while(!feof(fp)){
		fscanf(fp, "%s %lf %lf %lf %lf %10d %lf\n",
		date, &open, &high, &low, &close, &volume, &adj_close);
		//copy information to a structure array
		strcpy(GoogleStock[i].date, date);
		GoogleStock[i].open = open;
		GoogleStock[i].high = high;
		GoogleStock[i].low = low;
		GoogleStock[i].close = close;
		GoogleStock[i].volume = volume;
		GoogleStock[i].adj_close = adj_close;
		//copy the adj close price to an independent array
		google_stock_adj_close[i]= adj_close;
		i++;
	}

	fclose(fp); //close your program after finishing reading
	cout<‌<"Finish reading \n"<‌<endl;
	if (output_bit) {
		cout<‌<"The stock information is written in a structure array: \n"<‌<endl;
		pauseIT();
		for(int i=0;i<n;i++){
			fprintf(stderr, "%s %lf %lf %lf %lf %d %lf\n",
			GoogleStock[i].date,
			GoogleStock[i].open,
			GoogleStock[i].high,
			GoogleStock[i].low,
			GoogleStock[i].close,
			GoogleStock[i].volume,
			GoogleStock[i].adj_close);
		}
	cout<‌<endl<‌<endl;
	}

	if(output_bit){
		cout<‌<"This is the adjusted close price of Google stock"<‌<endl;
		pauseIT();
		setOutputPrecision(3);
		for(int i=0;i<n;i++)
			cout<‌<google_stock_adj_close[i]<‌<endl;
	}
	
	delete []google_stock_adj_close;
	
	return 0;
}
