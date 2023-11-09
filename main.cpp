//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//


/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array. 
 *	
 */


#include <iostream>
#include <fstream>
#include <cmath> 
#include "slist.h"
using namespace std;

class Airport 
{
public:
 char code[5];
double longitude;
double latitude;
};

void simpleSortTotal(LinkedList* s, int low, int high);
int partition(LinkedList* s, int low, int high);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);
double distanceAus(Airport* data) {
  return distanceEarth(data->latitude, data->longitude, 30.19449997, -97.66989899);
}

int main()
{
    ifstream infile;
    int i=0;
    char cNum[100] ;
    LinkedList* airportList= new LinkedList();
    infile.open ("airport-codes_US.csv", ifstream::in);
    if (infile.is_open())
    {
      string header;
      //getline(infile, header);
        while (infile.good())
        {
          Airport * val = new Airport();
            infile.getline(val->code, 256, ',');
            infile.getline(cNum, 256, ',');
            infile.getline(cNum, 256, ',');
            infile.getline(cNum, 256, ',');
            val->longitude = atof(cNum);
          infile.getline(cNum, 256, ',');
            val->latitude = atof(cNum);
          airportList->add(val);
          infile.ignore(256, '\n');
        }
      
      simpleSortTotal(airportList, 0, airportList->size()-1);
      int farthestIndex = airportList->size()-12;
      Airport* farthestAirport = airportList->get(farthestIndex);
      cout << "Farthest airport from Austin-Bergstorm International airport is: " << farthestAirport -> code << "  " <<distanceAus(farthestAirport) << " miles away" << endl;
      const double maxDistance = 100.0;
      cout << "Airports within 100 miles of Austin-Bergstrom International airport: " << endl;
      for (int i=0; i<airportList->size();i++) {
        Airport* currentAirport = airportList->get(i);
        double distance = distanceAus(currentAirport);
        if (distance <= maxDistance) {
          cout << currentAirport->code << " Distance: " << distanceAus(currentAirport) << " miles" << endl;
      }
      }
      infile.close();
    }
    else
    {
        cout << "Error opening file";
    }
  
}
#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return (2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v)))/1.609;
}


/*
  Provide sort routine on linked list
*/

void simpleSortTotal(LinkedList* l, int low, int high)
{
  if (low < high) {
    int mid= partition(l, low, high);
    simpleSortTotal(l, low, mid-1);
    simpleSortTotal(l, mid+1, high);
  }
}

int partition(LinkedList* l, int low, int high) {
  double pivot = distanceAus(l->get(high));
  int i=low-1;

  for (int j=low; j<=high-1; j++) {
    if (distanceAus(l->get(j)) < pivot) {
      i++;
      l->exchg(i,j);
    }
  }
  l->exchg(i+1, high);
  return i+1;
}