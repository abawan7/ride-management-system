#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include<stdio.h>
#include <ctime>
#include <cstdlib>
#include <time.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

//----------------------------------------------------------Cooridnates----------------------------------------------------------

void setCursorPointer(int x = 0, int y = 0)
{
	HANDLE handle;
	COORD coordinates;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(handle, coordinates);
}



//----------------------------------------------------------Name----------------------------------------------------------
class Name {
private:
	char* first_name;
	char* last_name;
public:
	Name();
	Name(string FN, string LN);
	Name(const Name& name) {
		first_name = name.first_name;
		last_name = name.last_name;
	}

	void setFName(string);
	void setLName(string);
	char* getFName();
	char* getLName();

	friend ostream& operator<<(ostream&, Name&);
	friend istream& operator>>(istream&, Name&);
};

Name::Name() {
	string FN = " ";
	string LN = " ";
	first_name = &FN[0];
	last_name = &LN[0];
}

Name::Name(string FN, string LN) {
	first_name = &FN[0];
	last_name = &LN[0];
}

void Name::setFName(string FN) {
	first_name = new char[FN.length() + 1];
	for (int i = 0; i < FN.length(); i++) {
		first_name[i] = FN[i];
	}
	first_name[FN.length()] = '\0';
}

void Name::setLName(string LN) {
	last_name = new char[LN.length() + 1];
	for (int i = 0; i < LN.length(); i++) {
		last_name[i] = LN[i];
	}
	last_name[LN.length()] = '\0';
}

char* Name::getFName() {
	return first_name;
}
char* Name::getLName() {
	return last_name;
}

ostream& operator<<(ostream& cout, Name& n) {
	cout << n.first_name << " " << n.last_name << endl;
	return cout;
}


istream& operator>>(istream& fin, Name& n)
{
	string fN, lN;

	cout << "Enter First Name:\t";
	fin >> fN;
	cout << "Enter Last Name:\t";
	fin >> lN;

	n.setFName(fN);
	n.setLName(lN);

	return fin;
}


//----------------------------------------------------------Date----------------------------------------------------------

class Date {
private:
	int day;
	int month;
	int year;

public:
	Date();
	Date(int, int, int);
	Date(const Date&);
	~Date() {};

	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int getDay();
	int getMonth();
	int getYear();

	friend ostream& operator<<(ostream&, const Date&);
	friend istream& operator>>(istream&, Date&);
};

Date::Date() {
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

Date::Date(const Date& date) {
	day = date.day;
	month = date.month;
	year = date.year;
}

void Date::setDay(int d) {
	day = d;
}
void Date::setMonth(int m) {
	month = m;
}
void Date::setYear(int y) {
	year = y;
}

int Date::getDay() {
	return day;
}
int Date::getMonth() {
	return month;
}

int Date::getYear() {
	return year;
}

ostream& operator<<(ostream& out, const Date& date) {
	out << date.day << " / " << date.month << " / " << date.year;
	return out;
}

istream& operator>>(istream& cin, Date& d)
{
	int day, month, year;

	cout << "Enter Day:\t";
	cin >> day;
	cout << "Enter Month:\t";
	cin >> month;
	cout << "Enter Year:\t";
	cin >> year;

	d.setDay(day);
	d.setMonth(month);
	d.setYear(year);


	return cin;
}



//----------------------------------------------------------M-Time----------------------------------------------------------

class mTime {
private:
	int hour;
	int min;
	int sec;

public:
	mTime();
	mTime(int, int, int);
	mTime(const mTime&);
	~mTime() {};

	void setHour(int);
	void setMin(int);
	void setSec(int);
	int getHour();
	int getMin();
	int getSec();

	friend ostream& operator<<(ostream&, const mTime&);
	friend istream& operator>>(istream&, mTime&);
};

mTime::mTime() {
	hour = 0;
	min = 0;
	sec = 0;
}

mTime::mTime(int h, int m, int s) {
	hour = h;
	min = m;
	sec = s;
}

mTime::mTime(const mTime& time) {
	hour = time.hour;
	min = time.min;
	sec = time.sec;
}

void mTime::setHour(int h) {
	hour = h;
}
void mTime::setMin(int m) {
	min = m;
}
void mTime::setSec(int s) {
	sec = s;
}

int mTime::getHour() {
	return hour;
}
int mTime::getMin() {
	return min;
}
int mTime::getSec() {
	return sec;
}

ostream& operator<<(ostream& out, const mTime& Time) {
	out << Time.hour << " : " << Time.min << " : " << Time.sec << endl;
	return out;
}

istream& operator>>(istream& cin, mTime& Time) {
	int h, m, s;
	cout << "Enter hour: ";
	cin >> h;
	cout << "Enter minute: ";
	cin >> m;
	cout << "Enter second: ";
	cin >> s;

	Time.setSec(s);
	Time.setMin(m);
	Time.setHour(h);

	return cin;
}




//----------------------------------------------------------Service----------------------------------------------------------

class Service {
private:
	char* source;
	char* destination;
	float distance;
	Date booking_Date;
	mTime booking_Time;
	int status;
	float fuelrate;
	int customer_id;
	int driver_id;
	int vehicle_id;

public:
	Service();
	Service(string, string, float, Date, mTime, bool, float, int, int, int);

	void setSource(string);
	void setDestination(string);
	void setDistance(float);
	void setBookingDate(Date);
	void setBookingTime(mTime);
	void setStatus(int);
	void setFuelRate(float);
	void setCId(int);
	void setDId(int);
	void setVId(int);

	char* getSource();
	char* getDestination();
	float getDistance();
	Date getBookingDate();
	mTime getBookingTime();
	int getStatus();
	float getFuelRate();
	int getCId();
	int getDId();
	int getVId();

	friend ostream& operator<<(ostream&, Service&);
	friend istream& operator>>(istream&, Service&);

};

Service::Service() {
	string s = " ";
	string d = " ";
	source = &s[0];
	destination = &d[0];
	distance = 0;
	booking_Date = Date();
	booking_Time = mTime();
	status = 0;
	fuelrate = 0;
	customer_id = 0;
	driver_id = 0;
	vehicle_id = 0;
}

Service::Service(string s, string d, float dis, Date bDate, mTime bTime, bool st, float fRate, int cID, int dID, int vID) {
	source = &s[0];
	destination = &d[0];
	distance = dis;
	booking_Date = bDate;
	booking_Time = bTime;
	status = st;
	fuelrate = fRate;
	customer_id = cID;
	driver_id = dID;
	vehicle_id = vID;
}

void Service::setSource(string s) {
	source = new char[s.length() + 1];
	for (int i = 0; i < s.length(); i++) {
		source[i] = s[i];
	}
	source[s.length()] = '\0';
}

void Service::setDestination(string d) {
	destination = new char[d.length() + 1];
	for (int i = 0; i < d.length(); i++) {
		destination[i] = d[i];
	}
	destination[d.length()] = '\0';
}

void Service::setDistance(float d) {
	distance = d;
}

void Service::setBookingDate(Date date) {
	booking_Date = date;
}

void Service::setBookingTime(mTime time) {
	booking_Time = time;
}

void Service::setStatus(int status) {
	status = status;
}

void Service::setFuelRate(float rate) {
	fuelrate = rate;
}

void Service::setCId(int cid) {
	customer_id = cid;
}

void Service::setDId(int did) {
	driver_id = did;
}

void Service::setVId(int vid) {
	vehicle_id = vid;
}

char* Service::getSource() {
	return source;
}

char* Service::getDestination() {
	return destination;
}

float Service::getDistance() {
	return distance;
}

Date Service::getBookingDate() {
	return booking_Date;
}

mTime Service::getBookingTime() {
	return booking_Time;
}

int Service::getStatus() {
	return status;
}

float Service::getFuelRate() {
	return fuelrate;
}

int Service::getCId() {
	return customer_id;
}

int Service::getVId() {
	return vehicle_id;
}

int Service::getDId() {
	return driver_id;
}


ostream& operator<<(ostream& out, Service& service) {
	out << "------------------Ride Information------------------\n";
	out << "Source: " << service.getSource() << endl;
	out << "Destination: " << service.getDestination() << endl;
	out << "Distance: " << service.getDistance() << endl;
	out << "Booking Date: " << service.getBookingDate() << endl;
	out << "Booking Time: " << service.getBookingTime() << endl;
	out << "Status (0: pending, 1: completed ): ";
	if (service.getStatus() == 0) {
		cout << "Complete!" << endl;
	}
	else {
		cout << "Pending!" << endl;
	}
	out << "Customer ID: " << service.getCId() << endl;
	out << "Driver ID: " << service.getDId() << endl;
	out << "Vehicle ID: " << service.getVId() << endl;

	out << "----------------------------------------------------\n";
	return out;
}

istream& operator>>(istream& cin, Service& service) {

	string s;
	string d;
	float distance;
	Date date;
	mTime mtime;
	int status;
	int cid, did, vid;

	cout << "Enter Source: ";
	cin >> s;
	cin.ignore();

	cout << "Enter Destiantion: ";
	cin >> d;
	cin.ignore();

	cout << "Enter distance (in KMs): ";
	cin >> distance;

	cout << "Enter Booking Date: \n";
	cin >> date;

	cout << "Enter Booking Time: \n";
	cin >> mtime;

	cout << "Enter Status (0 for pending, 1 if complete): ";
	cin >> status;

	cout << "Enter Customer ID: ";
	cin >> cid;

	cout << "Enter Driver ID: ";
	cin >> did;

	cout << "Enter Vehicle ID: ";
	cin >> vid;

	srand(time(0));
	int sid = rand();

	service.setSource(s);
	service.setDestination(d);
	service.setDistance(distance);
	service.setBookingDate(date);
	service.setBookingTime(mtime);
	service.setStatus(status);
	service.setCId(cid);
	service.setDId(did);
	service.setVId(vid);

	return cin;
}

//----------------------------------------------------------Ride----------------------------------------------------------


class Ride : public Service {
private:
	int no_Passengers;
	char* ride_Type;
	float drive_Ranking;
	float vehicle_Ranking;

public:
	Ride(int nop = 0, string type = "", float drank = 0, float vrank = 0, string s = "", string d = "", float dis = 0, Date bDate = Date(), mTime bTime = mTime(), bool st = 0, float fRate = 0, int cID = 0, int dID = 0, int vID = 0) : Service(s, d, dis, bDate, bTime, st, fRate, cID, dID, vID) {
		no_Passengers = nop;
		ride_Type = new char[type.length()];
		strcpy_s(ride_Type, type.length(), type.c_str());
		drive_Ranking = drank;
		vehicle_Ranking = vrank;
	}

	void setNoofPassengers(int);
	void setRideType(string);
	void setDRank(float);
	void setVRank(float);

	int getNoofPassengers();
	char getRideType();
	float getDRank();
	float getVRank();

	friend ostream& operator<<(ostream&, Ride&);
	friend istream& operator>>(istream&, Ride&);
};

void Ride::setNoofPassengers(int no) {
	no_Passengers = no;
}


void Ride::setRideType(string type) {
	ride_Type = new char[type.length()];
	strcpy_s(ride_Type, type.length(), type.c_str());
}

void Ride::setDRank(float rank) {
	drive_Ranking = rank;
}

void Ride::setVRank(float rank) {
	vehicle_Ranking = rank;
}

int Ride::getNoofPassengers() {
	return no_Passengers;
}


char Ride::getRideType() {
	return *ride_Type;
}

float Ride::getDRank() {
	return drive_Ranking;
}

float Ride::getVRank() {
	return vehicle_Ranking;
}

ostream& operator<<(ostream& out, Ride& ride) {
	out << "------------------Ride Information------------------\n";

	out << "Source: " << ride.getSource() << endl;
	out << "Destination: " << ride.getDestination() << endl;
	out << "Distance: " << ride.getDistance() << endl;
	out << "Booking Date: " << ride.getBookingDate();
	out << "Booking Time: " << ride.getBookingTime();
	out << "Status: " << ride.getStatus() << endl;
	out << "Customer ID: " << ride.getCId() << endl;
	out << "Driver ID: " << ride.getDId() << endl;
	out << "Vehicle ID: " << ride.getVId() << endl;
	out << "No. of Passengers: " << ride.getNoofPassengers() << endl;
	out << "Ride type: " << ride.getRideType() << endl;
	out << "Driver Ranking: " << ride.getDRank() << endl;
	out << "Vehicle Ranking: " << ride.getVRank() << endl;

	out << "----------------------------------------------------\n";
	return out;
}

istream& operator>>(istream& in, Ride& ride) {

	string s;
	string d;
	string type;

	float distance;
	Date date;
	mTime mtime;
	int status;
	int cid, did, vid;

	cout << "Enter Source: ";
	cin >> s;
	cin.ignore();

	cout << "Enter Destiantion: ";
	cin >> d;
	cin.ignore();

	cout << "Enter distance (in KMs): ";
	cin >> distance;

	cout << "Enter Booking Date: \n";
	cin >> date;

	cout << "Enter Booking Time: \n";
	cin >> mtime;


	cout << "Enter Customer ID: ";
	cin >> cid;

	cout << "Enter Driver ID: ";
	cin >> did;

	cout << "Enter Vehicle ID: ";
	cin >> vid;

	cout << "Enter No of Passengers: ";
	cin >> ride;

	cout << "Enter ride type (intercity, intracity): ";
	cin >> type;

	ride.setSource(s);
	ride.setDestination(d);
	ride.setDistance(distance);
	ride.setBookingDate(date);
	ride.setBookingTime(mtime);
	ride.setStatus(0);
	ride.setCId(cid);
	ride.setDId(did);
	ride.setVId(vid);
	ride.setRideType(type);
	ride.setDRank(0);
	ride.setVRank(0);

	return in;
}


//----------------------------------------------------------Delivery----------------------------------------------------------


class Delivery : public Service {
private:
	float goodsWeight;
	char* goodsType;

public:
	Delivery(string s = "", string d = "", float dis = 0, Date bDate = Date(), mTime bTime = mTime(), int st = 0, float fRate = 0, int cID = 0, int dID = 0, int vID = 0, int sID = 0, float fare = 0, float weight = 0, string type = "") :Service(s, d, dis, bDate, bTime, st, fRate, cID, dID, vID) {
		goodsWeight = weight;
		goodsType = &type[0];
	}

	void setGoodsWeight(float);
	void setGoodsType(string);

	float getGoodsWeight();
	char getGoodsType();

	friend ostream& operator<<(ostream&, Delivery&);
	friend istream& operator>>(istream&, Delivery&);
};

void Delivery::setGoodsWeight(float goodW) {
	goodsWeight = goodW;
}

void Delivery::setGoodsType(string type) {
	goodsType = &type[0];
}

char Delivery::getGoodsType() {
	return *goodsType;
}

float Delivery::getGoodsWeight() {
	return goodsWeight;
}

class Person {
private:
	Name pName;
	Date DOB;
	int Age;
	int Nid;
public:
	Person() {
		Age = 0;
		Nid = 0;
	}
	Person(Name, Date, int, int);
	Person(const Person&);

	void setName(Name);
	void setDOB(Date);
	void setAge(int);
	void setID(int);

	Name getName();
	Date getDOB();
	int getAge();
	int getID();

	friend ostream& operator<<(ostream&, const Person&);
	friend istream& operator>>(istream&, Person&);
};

Person::Person(Name name, Date dob, int age, int id) {
	pName = name;
	DOB = dob;
	Age = age;
	Nid = id;
}

Person::Person(const Person& person) {
	pName = person.pName;
	DOB = person.DOB;
	Age = person.Age;
	Nid = person.Nid;
}

void Person::setName(Name name) {
	pName = name;
}

void Person::setDOB(Date dob) {
	DOB = dob;
}

void Person::setAge(int age) {
	Age = age;
}
void Person::setID(int id) {
	Nid = id;
}

Name Person::getName() {
	return pName;
}

Date Person::getDOB() {
	return DOB;
}
int Person::getAge() {
	return Age;
}
int Person::getID() {
	return Nid;
}

ostream& operator<<(ostream& cout, const Person& person) {
	cout << "-------- Person Information --------" << endl;
	cout << "Person ID: " << person.Nid << endl;
	cout << "DOB: " << person.DOB << endl;
	cout << "Age: " << person.Age << endl;
	cout << "------------------------------------" << endl;
	return cout;
}

istream& operator>>(istream& cin, Person& person) {
	int id, age;
	Name name;
	Date dob;

	srand(time(0));
	id = rand();

	cin >> name;


	cout << "Enter Date of Birth: \n";
	cin >> dob;
	cout << "Enter age: ";
	cin >> age;

	person.setID(id);
	person.setName(name);
	person.setDOB(dob);
	person.setAge(age);

	return cin;
}


//----------------------------------------------------------Customer----------------------------------------------------------


class Customer : public Person {
private:
	int customer_Id;
	int no_of_Bookings;
	Service** booking_History;
public:
	Customer();
	Customer(Name, Date, int, int, int, int, Service**);
	Customer(const Customer&);

	void setcId(int);
	int getcId();
	void set_History(Service*);
	void set_booking() {
		no_of_Bookings++;
	}
	int get_vehicle_id() {
		for (int i = 0; i < no_of_Bookings; i++) {
			if (getcId() == booking_History[i]->getCId()) {
				return booking_History[i]->getVId();
			}
		}
	}
	int get_Booking();
	void gethistory();
	friend ostream& operator <<(ostream&, Customer&);
	friend istream& operator >>(istream&, Customer&);
};

Customer::Customer() {
	customer_Id = 0;
	no_of_Bookings = 0;
	booking_History = new Service * [100];
	for (int i = 0; i < 100; i++)
	{
		booking_History[i] = new Service[1];
	}
}

Customer::Customer(Name name, Date dob, int age, int id, int cID, int no_booking, Service** history) :Person(name, dob, age, id) {
	no_of_Bookings = no_booking;
	customer_Id = cID;
	booking_History = NULL;
}

Customer::Customer(const Customer& cus) {
	customer_Id = cus.customer_Id;
	no_of_Bookings = cus.no_of_Bookings;
	booking_History = new Service * [100];
}

void Customer::setcId(int id) {
	customer_Id = id;
}

int Customer::getcId() {
	return customer_Id;
}

int Customer::get_Booking() {
	return no_of_Bookings;
}

void Customer::set_History(Service* history) {
	booking_History[no_of_Bookings - 1] = history;
}

void Customer::gethistory() {
	int cid, cID;
	for (int i = 0; i < no_of_Bookings; i++) {
		if (booking_History[i]->getCId() == getcId()) {
			cout << "-----------------------Customer Info-----------------------" << endl;
			cout << "Source: " << booking_History[i]->getSource() << endl;
			cout << "Destination: " << booking_History[i]->getDestination() << endl;
			cout << "Distance: " << booking_History[i]->getDistance() << endl;
			cout << "Booking Date: " << booking_History[i]->getBookingDate() << endl;
			cout << "Booking Time: " << booking_History[i]->getBookingTime() << endl;
			cout << "Status (0: pending, 1: completed ): ";
			if (booking_History[i]->getStatus() == 0) {
				cout << "Pending!" << endl;
			}
			else if (booking_History[i]->getStatus() == 1) {
				cout << "Complete!" << endl;
			}
			else {
				cout << "Cancelled" << endl;
			}
			cout << "Customer ID: " << booking_History[i]->getCId() << endl;
			cout << "Driver ID: " << booking_History[i]->getDId() << endl;
			cout << "Vehicle ID: " << booking_History[i]->getVId() << endl;
		}
	}
}

ostream& operator<<(ostream& out, Customer& customer) {
	out << "------------- Customer Information -------------------" << endl;
	out << "Person Name: " << customer.getName().getFName() << " " << customer.getName().getLName() << endl;
	out << "Customer ID: " << customer.getcId() << endl;
	out << "Person ID: " << customer.getID() << endl;
	out << "DOB: " << customer.getDOB() << endl;
	out << "Age: " << customer.getAge() << endl;
	out << "------------------------------------------------------" << endl;
	return out;
}

istream& operator>>(istream& in, Customer& customer) {
	cout << "------------- Customer Information -------------------" << endl;
	string fn, ln;
	Date dob;
	int day, month, year, age, id, customer_Id;

	cout << "Enter First Name: ";
	in >> fn;
	cout << "Enter Last Name: ";
	in >> ln;
	cout << "Enter Age: ";
	in >> age;
	cout << "Enter Day: ";
	in >> day;
	cout << "Enter Month: ";
	in >> month;
	cout << "Enter Year: ";
	in >> year;

	dob.setDay(day);
	dob.setMonth(month);
	dob.setYear(year);

	Name name;
	name.setFName(fn);
	name.setLName(ln);

	id = rand();

	customer.setName(name);
	customer.setAge(age);
	customer.setDOB(dob);
	customer.setID(id);

	cout << "------------------------------------------------------" << endl;
	return in;
}

class Driver : public Person {
private:
	int driver_id;
	char** license_list;
	int no_of_license;
	float overallRanking;
	float salary;
	int experience;
	int status;
	Service** serviceHistory;
	int no_of_booking;

public:
	Driver();
	Driver(int dID, char** list, int totalLicence, float rank, float sal, int exp, int stat, Service** history, Name name, Date dob, int age, int id) :Person(name, dob, age, id) {
		driver_id = id;
		no_of_booking = 0;
		salary = sal;
		experience = exp;
		status = stat;
		overallRanking = rank;
		no_of_license = totalLicence;
		license_list = nullptr;
		if (list != nullptr) {
			license_list = new char* [no_of_license];

			for (int i = 0; i < no_of_license; i++)
			{
				for (int j = 0; list[i][j] != '\0'; j++) {
					license_list[i] = new char[strlen(list[i])];
					license_list[i] = list[i];
				}
			}
		}
		serviceHistory = new Service * [100];
		for (int i = 0; i < 100; i++)
		{
			serviceHistory[i] = new Service[1];
		}
	}
	void setDId(int);
	void setLicenceList(string);
	void setNoofLicences(int);
	void setRanking(float);
	void setSalary(float);
	void setExperience(int);
	void setStatus(int);
	void setHistory(Service*);
	char* getLicenseFile(int);
	void set_Booking();

	int getDId();
	void getLicenceList();
	int getNoofLicences();
	float getRanking();
	float getSalary();
	int getStatus();
	void getHistory() {
		cout << "----------------------------";
		for (int i = 0; i < no_of_booking; i++) {
			if (serviceHistory[i]->getDId() == getDId()) {
				cout << "-----------------------Driver Info-----------------------" << endl;
				cout << "Source: " << serviceHistory[i]->getSource() << endl;
				cout << "Destination: " << serviceHistory[i]->getDestination() << endl;
				cout << "Distance: " << serviceHistory[i]->getDistance() << endl;
				cout << "Booking Date: " << serviceHistory[i]->getBookingDate() << endl;
				cout << "Booking Time: " << serviceHistory[i]->getBookingTime() << endl;
				cout << "Status (0: pending, 1: completed ): ";
				if (serviceHistory[i]->getStatus() == 0) {
					cout << "Pending!" << endl;
				}
				else if (serviceHistory[i]->getStatus() == 1) {
					cout << "Complete!" << endl;
				}
				else {
					cout << "Cancelled" << endl;
				}
				cout << "Customer ID: " << serviceHistory[i]->getCId() << endl;
				cout << "Driver ID: " << serviceHistory[i]->getDId() << endl;
				cout << "Vehicle ID: " << serviceHistory[i]->getVId() << endl;
			}
		}
	}

	friend ostream& operator<<(ostream&, Driver&);
	friend istream& operator>>(istream&, Driver&);
};

Driver::Driver() {
	no_of_booking = 0;
	driver_id = 0;
	license_list = new char* [1];
	license_list = nullptr;
	no_of_license = 0;
	overallRanking = 0;
	salary = 0;
	experience = 0;
	status = 1;
	serviceHistory = new Service * [100];
	for (int i = 0; i < 100; i++)
	{
		serviceHistory[i] = new Service[1];
	}
}

void Driver::setDId(int id) {
	driver_id = id;
}
void Driver::setLicenceList(string list) {
	string license;
	string l = list;
	int Position;
	cout << no_of_license;
	license_list = new char* [no_of_license];
	for (int i = 0; i < no_of_license; i++)
	{
		license_list[i] = new char[30];
	}
	for (int i = 0; i < no_of_license; i++) {
		Position = list.find(',');
		license = (list.substr(0, Position));
		list.erase(0, Position + 1);
		for (int j = 0; j < license.length(); j++) {
			license_list[i][j] = license[j];
		}
		license_list[i][license.length()] = '\0';
	}
}
void Driver::setHistory(Service* history) {
	serviceHistory[no_of_booking - 1] = history;
}

void Driver::set_Booking() {
	no_of_booking++;
}

void Driver::setNoofLicences(int no) {
	no_of_license = no;
}
void Driver::setRanking(float rank) {
	overallRanking = rank;
}
void Driver::setSalary(float salary) {
	this->salary = salary;
}
void Driver::setExperience(int exp) {
	this->experience = exp;
}
void Driver::setStatus(int sts) {
	status = sts;
}


int Driver::getDId() {
	return	driver_id;
}
void Driver::getLicenceList() {
	int count = 1;
	for (int i = 0; i < no_of_license; i++) {
		cout << "\n" << count << "> ";
		for (int j = 0; license_list[i][j] != '\0'; j++) {
			cout << license_list[i][j];
		}
		count++;
	}
}

char* Driver::getLicenseFile(int a) {
	for (int i = 0; i < getNoofLicences(); i++)
	{
		if (a == i) {
			return license_list[i];
		}
	}
}
int Driver::getNoofLicences() {
	return no_of_license;
}
float Driver::getRanking() {
	return overallRanking;
}
float Driver::getSalary() {
	return salary;
}
int Driver::getStatus() {
	return status;
}

ostream& operator<<(ostream& out, Driver& driver) {
	out << "------------- Driver Information -------------------" << endl;
	out << "Name: " << driver.getName().getFName() << " " << driver.getName().getLName() << endl;
	out << "Driver ID: " << driver.getDId() << endl;
	out << "Person ID: " << driver.getID() << endl;
	out << "DOB: " << driver.getDOB();
	out << "Age: " << driver.getAge() << endl;
	out << "No of Licences: " << driver.getNoofLicences() << endl;
	out << "License List: ";
	driver.getLicenceList();
	cout << endl;
	out << "Ranking: " << driver.getRanking() << endl;
	out << "Salary: " << driver.getSalary() << endl;
	out << "Status (1:free, 2: booked, 3: cancelled): " << driver.getStatus() << endl;
	return out;
}

istream& operator >> (istream& in, Driver& driver) {
	int day, month, year, age, no_of_license, driver_id, id;
	float salary, ranking;
	string fn, ln, license_list, license;
	Name name;
	Date dob;

	id = rand();
	driver_id = rand();


	cout << "Enter First Name: ";
	in >> fn;
	cout << "Enter last Name: ";
	in >> ln;
	cout << "Enter Day: ";
	in >> day;
	cout << "Enter Month: ";
	in >> month;
	cout << "Enter Year: ";
	in >> year;
	cout << "Enter Age: ";
	in >> age;
	cout << "Enter No Of License: ";
	in >> no_of_license;
	cout << "Enter License List: ";
	in >> license_list;
	cout << "Enter Salary: ";
	in >> salary;
	cout << "Enter Ranking: ";
	in >> ranking;

	name.setFName(fn);
	name.setLName(ln);
	dob.setDay(day);
	dob.setMonth(month);
	dob.setYear(year);

	driver.setName(name);
	driver.setDOB(dob);
	driver.setAge(age);
	driver.setNoofLicences(no_of_license);
	driver.setSalary(salary);
	driver.setLicenceList(license_list);
	driver.setRanking(ranking);
	driver.setDId(driver_id);
	driver.setID(id);
	driver.setStatus(1);
	return in;
}

class Features {
private:
	int fid;
	char* description;
	float cost;
public:
	Features(int, string, float);
	void set_fid(int);
	void set_description(string);
	void set_cost(float);

	int get_fid();
	char* get_description();
	float get_cost();

	friend ostream& operator << (ostream&, Features&);
	friend istream& operator >> (istream&, Features&);
};

Features::Features(int feature_id = 0, string des = " ", float c = 0) {
	fid = feature_id;
	description = new char[des.length() + 1];
	for (int i = 0; i < des.length(); i++) {
		description[i] = des[i];
	}
	description[des.length()] = '\0';
	cost = c;
}

void Features::set_fid(int feature_id) {
	fid = feature_id;
}

void Features::set_description(string des) {
	description = new char[des.length() + 1];
	for (int i = 0; i < des.length(); i++) {
		description[i] = des[i];
	}
	description[des.length()] = '\0';
}

void Features::set_cost(float c) {
	cost = c;
}

int Features::get_fid() {
	return fid;
}

char* Features::get_description() {
	return description;
}

float Features::get_cost() {
	return cost;
}

ostream& operator << (ostream& out, Features& feature) {
	cout << "Feature_id: " << feature.get_fid() << endl;
	cout << "Description: " << feature.get_description() << endl;
	cout << "Cost: " << feature.get_cost() << endl;
	return out;
}

istream& operator << (istream& in, Features& feature) {
	string des;
	int feature_id;
	float cost;
	cout << "Enter Feature ID: ";
	in >> feature_id;
	cout << "Enter Description: ";
	in >> des;
	cout << "Enter Cost: ";
	in >> cost;

	feature.set_description(des);
	feature.set_fid(feature_id);
	feature.set_cost(cost);

	return in;
}

class Vehicle {
private:
	int vehicle_id;
	int registration;
	float avgmileage;
	char* licenseType;
	bool status;
	char* fueltype;
	float overallRanking;
	int no_of_vehicle;
	Date manufacturing_Date;
	Features* list;
	Service** serviceHistory;
	int no_of_booking;
public:
	Vehicle() {
		no_of_booking = 0;
		no_of_vehicle = 0;
		Date dob;
		Name name;
		int day, month, year;
		vehicle_id = 0;
		registration = 0;
		avgmileage = 0;
		status = 1;
		overallRanking = 0;
		list = nullptr;
		serviceHistory = nullptr;
		serviceHistory = new Service * [100];
		for (int i = 0; i < 100; i++)
		{
			serviceHistory[i] = new Service[1];
		}
	}
	Vehicle(int vid, int reg, float avgmil, string lic, int stat, string fuel_t, float overrank, int day, int month, int year) {
		no_of_booking = 0;
		vehicle_id = vid;
		registration = reg;
		avgmileage = avgmil;
		no_of_vehicle = 0;
		licenseType = new char[lic.length() + 1];
		for (int i = 0; i < lic.length(); i++) {
			licenseType[i] = lic[i];
		}
		licenseType[lic.length()] = '\0';

		status = stat;

		fueltype = new char[fuel_t.length() + 1];
		for (int i = 0; i < fuel_t.length(); i++) {
			fueltype[i] = fuel_t[i];
		}
		fueltype[fuel_t.length()] = '\0';

		overallRanking = overrank;

		list = nullptr;
		serviceHistory = new Service * [100];
		for (int i = 0; i < 100; i++)
		{
			serviceHistory[i] = new Service[1];
		}
	}
	void setVId(int);
	void setRegNo(int);
	void setAvgMil(int);
	void setLicenceType(string);
	void setFuelType(string);
	void setOverallRanking(int);
	void manu_Date(const Date);
	void set_Booking() {
		no_of_booking++;
	}

	void setHistory(Service* history) {
		serviceHistory[no_of_vehicle - 1] = history;
	}

	void getHistory() {
		cout << "----------------------------";
		for (int i = 0; i < no_of_booking; i++) {
			if (serviceHistory[i]->getVId() == getVid()) {
				cout << "-----------------------Vehicle Info-----------------------" << endl;
				cout << "Source: " << serviceHistory[i]->getSource() << endl;
				cout << "Destination: " << serviceHistory[i]->getDestination() << endl;
				cout << "Distance: " << serviceHistory[i]->getDistance() << endl;
				cout << "Booking Date: " << serviceHistory[i]->getBookingDate() << endl;
				cout << "Booking Time: " << serviceHistory[i]->getBookingTime() << endl;
				cout << "Status (0: pending, 1: completed ): ";
				if (serviceHistory[i]->getStatus() == 0) {
					cout << "Pending!" << endl;
				}
				else if (serviceHistory[i]->getStatus() == 1) {
					cout << "Complete!" << endl;
				}
				else {
					cout << "Cancelled" << endl;
				}
				cout << "Customer ID: " << serviceHistory[i]->getCId() << endl;
				cout << "Driver ID: " << serviceHistory[i]->getDId() << endl;
				cout << "Vehicle ID: " << serviceHistory[i]->getVId() << endl;
			}
		}
	}
	int getVid();
	int getRegNo();
	int getAvgMil();
	char* getLicense_Type();
	char* getFuelType();
	int getRanking();
	Date getManuDate();
	friend ostream& operator << (ostream&, Vehicle&);
	friend istream& operator >> (istream&, Vehicle&);
};

void Vehicle::setVId(int vid) {
	vehicle_id = vid;
}

void Vehicle::setRegNo(int reg) {
	registration = reg;
}

void Vehicle::setAvgMil(int avg) {
	avgmileage = avg;
}

void Vehicle::manu_Date(const Date dob) {
	manufacturing_Date = dob;
}

void Vehicle::setLicenceType(string lic) {
	licenseType = new char[lic.length() + 1];
	for (int i = 0; i < lic.length(); i++) {
		licenseType[i] = lic[i];
	}
	licenseType[lic.length()] = '\0';
}

void Vehicle::setFuelType(string fuel_t) {
	fueltype = new char[fuel_t.length() + 1];
	for (int i = 0; i < fuel_t.length(); i++) {
		fueltype[i] = fuel_t[i];
	}
	fueltype[fuel_t.length()] = '\0';
}

void Vehicle::setOverallRanking(int rank) {
	overallRanking = rank;
}

int Vehicle::getVid() {
	return vehicle_id;
}

int Vehicle::getRegNo() {
	return registration;
}

int Vehicle::getAvgMil() {
	return avgmileage;
}

char* Vehicle::getLicense_Type() {
	return licenseType;
}

char* Vehicle::getFuelType() {
	return fueltype;
}

int Vehicle::getRanking() {
	return overallRanking;
}

Date Vehicle::getManuDate() {
	return manufacturing_Date;
}

ostream& operator << (ostream& out, Vehicle& veh) {
	out << "-----------------Vehical Info------------------" << endl;
	out << "Vehical ID: " << veh.getVid() << endl;
	out << "Registration: " << veh.getRegNo() << endl;
	out << "License Type: " << veh.getLicense_Type() << endl;
	out << "Manufacturing Date: " << veh.getManuDate() << endl;
	out << "Aveage Milage: " << veh.getAvgMil() << endl;
	out << "Fuel Type: " << veh.getFuelType() << endl;
	out << "Ranking: " << veh.getRanking() << endl;
	return out;
}

istream& operator >> (istream& in, Vehicle& Vehicles) {
	int vehicle_id, registration, Position, day, month, year;
	float avgmileage;
	string licenseType, fueltype;
	bool status;
	float overallRanking;

	cout << "Enter Vehicle ID: ";
	cin >> vehicle_id;
	cout << "Enter Registration No:  ";
	in >> registration;
	cout << "Enter Average: ";
	in >> avgmileage;
	cout << "Enter License Type: ";
	in >> licenseType;
	cout << "Enter Fuel Type: ";
	in >> fueltype;
	cout << "Enter Day: ";
	in >> day;
	cout << "Enter Month: ";
	in >> month;
	cout << "Enter Year: ";
	in >> year;
	cout << "Enter Overall Ranking: ";
	in >> overallRanking;

	Date dob;
	dob.setDay(day);
	dob.setMonth(month);
	dob.setYear(year);

	Vehicles.setRegNo(registration);
	Vehicles.setVId(vehicle_id);
	Vehicles.setAvgMil(avgmileage);
	Vehicles.setOverallRanking(overallRanking);
	Vehicles.manu_Date(dob);
	Vehicles.setFuelType(fueltype);
	Vehicles.setLicenceType(licenseType);
	return in;
}

void split_Service_Vehical(string line, Vehicle* Vehicles, int i) {
	int Position, goodweight, no_of_booking, customer_id, day, month, year, status, distance, driver_id, vehical_id, hour, min, sec;
	string goodType, source, destination;
	mTime time;

	Position = line.find(',');
	vehical_id = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << vehical_id;

	Position = line.find(',');
	no_of_booking = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << no_of_booking;

	Position = line.find(',');
	goodweight = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << goodweight;

	Position = line.find(',');
	goodType = (line.substr(0, Position));
	line.erase(0, Position + 1);
	cout << goodType;

	Position = line.find(',');
	source = (line.substr(0, Position));
	line.erase(0, Position + 1);
	cout << source;

	Position = line.find(',');
	destination = (line.substr(0, Position));
	line.erase(0, Position + 1);
	cout << destination;

	Position = line.find('/');
	day = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << day;

	Position = line.find('/');
	month = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << month;

	Position = line.find(',');
	year = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << year;

	Position = line.find(',');
	status = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << status;

	Position = line.find(',');
	distance = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << distance;

	Position = line.find(',');
	customer_id = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << customer_id;

	Position = line.find(',');
	driver_id = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << driver_id;

	Position = line.find(',');
	hour = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << hour;

	Position = line.find(',');
	min = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << min;

	Position = line.find(',');
	sec = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << sec;

	time.setHour(hour);
	time.setMin(min);
	time.setSec(sec);

	Date dob;
	dob.setDay(day);
	dob.setMonth(month);
	dob.setYear(year);

	Service* service = new Service[1];
	service->setSource(source);
	service->setCId(customer_id);
	service->setDestination(destination);
	service->setBookingDate(dob);
	service->setStatus(status);
	service->setDistance(distance);
	service->setDId(driver_id);
	service->setVId(vehical_id);
	service->setBookingTime(time);

	Vehicles[vehical_id].set_Booking();
	Vehicles[vehical_id].setHistory(service);
	cout << endl;
}

void split_Vehicle(string line, Vehicle* Vehicles, int i) {
	int vehicle_id, registration, Position, day, month, year;
	float avgmileage;
	string licenseType, fueltype;
	bool status;
	float overallRanking;

	Position = line.find(',');
	registration = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << registration;

	Position = line.find(',');
	avgmileage = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << avgmileage;

	Position = line.find(',');
	licenseType = (line.substr(0, Position));
	line.erase(0, Position + 1);
	cout << licenseType;

	Position = line.find(',');
	fueltype = (line.substr(0, Position));
	line.erase(0, Position + 1);
	cout << fueltype;

	Position = line.find('/');
	day = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << day;

	Position = line.find('/');
	month = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << month;

	Position = line.find(',');
	year = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << year;

	Position = line.find(',');
	overallRanking = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << overallRanking;

	vehicle_id = i;

	Date dob;
	dob.setDay(day);
	dob.setMonth(month);
	dob.setYear(year);

	Vehicles[i].setRegNo(registration);
	Vehicles[i].setVId(vehicle_id);
	Vehicles[i].setAvgMil(avgmileage);
	Vehicles[i].setOverallRanking(overallRanking);
	Vehicles[i].manu_Date(dob);
	Vehicles[i].setFuelType(fueltype);
	Vehicles[i].setLicenceType(licenseType);
	cout << endl;
}


void split_Service_Driver(string line, Driver* drivers, int i) {
	int Position, goodweight, no_of_booking, customer_id, day, month, year, status, distance, driver_id, vehical_id, hour, min, sec;
	string goodType, source, destination;
	mTime time;

	Position = line.find(',');
	driver_id = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << driver_id;

	Position = line.find(',');
	no_of_booking = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << no_of_booking;

	Position = line.find(',');
	goodweight = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << goodweight;

	Position = line.find(',');
	goodType = (line.substr(0, Position));
	line.erase(0, Position + 1);
	cout << goodType;

	Position = line.find(',');
	source = (line.substr(0, Position));
	line.erase(0, Position + 1);
	cout << source;

	Position = line.find(',');
	destination = (line.substr(0, Position));
	line.erase(0, Position + 1);
	cout << destination;

	Position = line.find('/');
	day = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << day;

	Position = line.find('/');
	month = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << month;

	Position = line.find(',');
	year = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << year;

	Position = line.find(',');
	status = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << status;

	Position = line.find(',');
	distance = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << distance;

	Position = line.find(',');
	customer_id = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << customer_id;

	Position = line.find(',');
	vehical_id = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << vehical_id;

	Position = line.find(',');
	hour = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << hour;

	Position = line.find(',');
	min = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << min;

	Position = line.find(',');
	sec = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << sec;

	time.setHour(hour);
	time.setMin(min);
	time.setSec(sec);

	Date dob;
	dob.setDay(day);
	dob.setMonth(month);
	dob.setYear(year);

	Service* service = new Service[1];
	service->setSource(source);
	service->setCId(customer_id);
	service->setDestination(destination);
	service->setBookingDate(dob);
	service->setStatus(status);
	service->setDistance(distance);
	service->setDId(driver_id);
	service->setVId(vehical_id);
	service->setBookingTime(time);

	drivers[driver_id].set_Booking();
	drivers[driver_id].setHistory(service);
	cout << endl;
}

void split_Service_Customer(string line, Customer* Customers, int i) {
	int Position, goodweight, no_of_booking, customer_id, day, month, year, status, driver_id, vehical_id, hour, min, sec;
	float distance;
	string goodType, source, destination;
	mTime time;

	Position = line.find(',');
	customer_id = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << customer_id;

	Position = line.find(',');
	no_of_booking = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << no_of_booking;

	Position = line.find(',');
	goodweight = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << goodweight;

	Position = line.find(',');
	goodType = (line.substr(0, Position));
	line.erase(0, Position + 1);
	cout << goodType;

	Position = line.find(',');
	source = (line.substr(0, Position));
	line.erase(0, Position + 1);
	cout << source;

	Position = line.find(',');
	destination = (line.substr(0, Position));
	line.erase(0, Position + 1);
	cout << destination;

	Position = line.find('/');
	day = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << day;

	Position = line.find('/');
	month = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << month;

	Position = line.find(',');
	year = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << year;

	Position = line.find(',');
	status = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << status;

	Position = line.find(',');
	distance = stof((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << distance;

	Position = line.find(',');
	driver_id = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << driver_id;

	Position = line.find(',');
	vehical_id = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << vehical_id;

	Position = line.find(',');
	hour = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << hour;

	Position = line.find(',');
	min = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << min;

	Position = line.find(',');
	sec = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << sec;

	time.setHour(hour);
	time.setMin(min);
	time.setSec(sec);

	Date dob;
	dob.setDay(day);
	dob.setMonth(month);
	dob.setYear(year);

	Service* service = new Service[1];
	service->setSource(source);
	service->setCId(customer_id);
	service->setDestination(destination);
	service->setBookingDate(dob);
	service->setStatus(status);
	service->setDistance(distance);
	service->setDId(driver_id);
	service->setVId(vehical_id);
	service->setBookingTime(time);

	Customers[customer_id].set_booking();
	Customers[customer_id].set_History(service);

	cout << endl;
}

void split_customer(string line, Customer* Customers, int i) {
	int Position, day, month, year, id, customer_Id, no_of_booking, age, goodweight;
	string fn, ln, goodType, source, destination;
	Name name;
	Date dob;

	customer_Id = i;

	Position = line.find(' ');
	fn = (line.substr(0, Position));
	line.erase(0, Position + 1);
	cout << fn;

	Position = line.find(',');
	ln = (line.substr(0, Position));
	line.erase(0, Position + 1);
	cout << ln;

	name.setFName(fn);
	name.setLName(ln);

	Position = line.find('/');
	day = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << day;

	Position = line.find('/');
	month = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << month;

	Position = line.find(',');
	year = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << year;

	Position = line.find(',');
	no_of_booking = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);

	Position = line.find(',');
	age = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << age;

	dob.setDay(day);
	dob.setMonth(month);
	dob.setYear(year);

	id = rand();

	Customers[i].setcId(customer_Id);
	Customers[i].setAge(age);
	Customers[i].setName(name);
	Customers[i].setDOB(dob);
	Customers[i].setID(id);
	cout << endl;
}

void Driver_split(string line, Driver* driver, int i) {
	int Position;
	int day, month, year, age, no_of_license, driver_id, id;
	float salary, ranking;
	string fn, ln, license_list, license;
	Name name;
	Date dob;
	Position = line.find(' ');
	fn = (line.substr(0, Position));
	line.erase(0, Position + 1);
	cout << fn;

	Position = line.find(',');
	ln = (line.substr(0, Position));
	line.erase(0, Position + 1);
	cout << ln;

	Position = line.find('/');
	day = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << day;

	Position = line.find('/');
	month = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << month;

	Position = line.find(',');
	year = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << year;

	Position = line.find(',');
	age = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << age;

	Position = line.find(',');
	no_of_license = atoi((line.substr(0, Position)).c_str());
	line.erase(0, Position + 1);
	cout << no_of_license;

	Position = line.find(',');
	salary = stof(line.substr(0, Position));
	line.erase(0, Position + 1);
	cout << salary;

	Position = line.find(',');
	ranking = stof(line.substr(0, Position));
	line.erase(0, Position + 1);
	cout << ranking;

	Position = line.find(' ');
	license_list = (line.substr(0, Position));
	line.erase(0, Position + 1);

	cout << license_list;

	cout << license_list.length();

	id = rand();
	driver_id = i;

	name.setFName(fn);
	name.setLName(ln);
	dob.setDay(day);
	dob.setMonth(month);
	dob.setYear(year);


	driver[i].setName(name);
	driver[i].setDOB(dob);
	driver[i].setAge(age);
	driver[i].setNoofLicences(no_of_license);
	driver[i].setSalary(salary);
	driver[i].setRanking(ranking);
	driver[i].setDId(driver_id);
	driver[i].setID(id);
	driver[i].setLicenceList(license_list);
	cout << endl;
}

class TMS {

private:
	int customer;
	int vehicle;
	int drivers;

	Customer* Customers;
	Driver* Drivers;
	Vehicle* Vehicles;

public:
	TMS(int c = 0, int d = 0, int v = 0) {
		customer = c;
		drivers = d;
		vehicle = v;
		Customers = new Customer[customer];
		Drivers = new Driver[drivers];
		Vehicles = new Vehicle[vehicle];

	}

	void find_customer() {
		int i = 0;
		string line;
		ifstream Fetch("customers.txt");
		if (Fetch.is_open())
		{
			while (getline(Fetch, line))
			{
				split_customer(line, Customers, i);
				i++;
			}
			Fetch.close();
		}
		else {
			cout << "File not Found" << endl;
		}
		customer = i;
	}

	void find_Customer_History() {
		int i = 0;
		string line;
		ifstream Fetch("CustomerHistory.txt");
		if (Fetch.is_open())
		{
			while (getline(Fetch, line))
			{
				split_Service_Customer(line, Customers, i);
				i++;
			}
			Fetch.close();
		}
		else {
			cout << "File not Found" << endl;
		}
	}
	void find_Driver_History() {
		int i = 0;
		string line;
		ifstream Fetch("DriverHistory.txt");
		if (Fetch.is_open())
		{
			while (getline(Fetch, line))
			{
				split_Service_Driver(line, Drivers, i);
				i++;
			}
			Fetch.close();
		}
		else {
			cout << "File not Found" << endl;
		}
	}

	void find_Vehical_History() {
		int i = 0;
		string line;
		ifstream Fetch("VehicalHistory.txt");
		if (Fetch.is_open())
		{
			while (getline(Fetch, line))
			{
				split_Service_Vehical(line, Vehicles, i);
				i++;
			}
			Fetch.close();
		}
		else {
			cout << "File not Found" << endl;
		}
	}

	void find_Driver() {
		int i = 0;
		string line;
		ifstream Fetch("Drivers.txt");
		if (Fetch.is_open())
		{
			while (getline(Fetch, line))
			{
				Driver_split(line, Drivers, i);
				i++;
			}
			Fetch.close();
		}
		else {
			cout << "File not Found" << endl;
		}
	}

	void find_Vehical() {
		int i = 0;
		string line;
		ifstream Fetch("Vehical.txt");
		if (Fetch.is_open())
		{
			while (getline(Fetch, line))
			{
				split_Vehicle(line, Vehicles, i);
				i++;
			}
			Fetch.close();
		}
		else {
			cout << "File not Found" << endl;
		}
		drivers = i;
	}

	void Menu() {
		int x;
		while (true) {
			_getch();
			system("cls");
			SetConsoleTextAttribute(console, 10);
			cout << "Press 1 to add new customer" << endl;
			cout << "Press 2 to Add a Driver" << endl;
			cout << "Press 3 to Add a Vehical" << endl;
			cout << "Press 4 to Print list of Customers" << endl;
			cout << "Press 5 to Print list of all Drivers" << endl;
			cout << "Press 6 to Print list of All Vehicals " << endl;
			cout << "Press 7 to Service history of a perticular vehical" << endl;
			cout << "Press 8 to Booking history of the perticular customer" << endl;
			cout << "Press 9 to Service history of the drivers" << endl;
			cout << "Press 10 to Print list of all Drivers who have the ranking above 4.5" << endl;
			cout << "Press 11 to Print list of all drivers having multiple liecences and their liecence information" << endl;
			cout << "Press 12 to get the salaries of the drivers" << endl;
			cout << "Press 13 to Book a service" << endl;
			cout << "Press 14 to cancel the Service" << endl;
			cout << "Press 15 for the List of customers who have used the same vehical" << endl;
			cout << "Press 16 for the list of the drivers who have completed the delivery service on the same days" << endl;
			cout << "Press 17 to print the list of all pending services on that perticular date" << endl;
			cout << "Press 18 to print the pending services of the perticular driver" << endl;
			cout << "Press 19 to get the all canceled services by a customer" << endl;

			cin >> x;
			system("cls");
			SetConsoleTextAttribute(console, 9);
			if (x == 1) {
				Customers[customer].setcId(customer);
				cin >> Customers[customer];
				Customers[customer].setID(customer);
				customer++;
				ofstream Write("customers");
				for (int i = 0; i < customer; i++) {
					Write << Customers[i].getName().getFName() << " " << Customers[i].getName().getLName() << "," << Customers[i].getDOB().getDay() << "/"
						<< Customers[i].getDOB().getMonth() << "/" << Customers[i].getDOB().getYear() << "," << "0" << "," << Customers[i].getAge() << "," << endl;
				}
			}
			else if (x == 2) {
				cin >> Drivers[drivers];
				drivers++;
				ofstream Write("drivers");
				for (int i = 0; i < drivers; i++) {
					Write << Drivers[i].getName().getFName() << " " << Drivers[i].getName().getLName() << "," << Drivers[i].getDOB().getDay() << "/"
						<< Drivers[i].getDOB().getMonth() << "/" << Drivers[i].getDOB().getYear() << "," << Drivers[i].getAge() << "," << Drivers[i].getNoofLicences()
						<< "," << Drivers[i].getSalary() << "," << Drivers[i].getRanking() << ",";
					for (int j = 0; j < Drivers[i].getNoofLicences(); j++) {
						Write << Drivers[i].getLicenseFile(j) << ",";
					}
					Write << endl;
				}
			}

			else if (x == 3) {
				Vehicles[vehicle].setVId(vehicle);
				cin >> Vehicles[vehicle];
				vehicle++;
				ofstream Write("Vehicals");
				for (int i = 0; i < vehicle; i++) {
					Write << Vehicles[i].getVid() << "," << Vehicles[i].getRegNo() << "," << Vehicles[i].getLicense_Type() << "," << Vehicles[i].getFuelType()
						<< "," << Vehicles[i].getManuDate() << "," << Vehicles[i].getRanking() << endl;
				}
			}

			else if (x == 4) {
				for (int i = 0; i < customer; i++) {
					cout << Customers[i];
				}
			}
			else if (x == 5) {
				for (int i = 0; i < drivers; i++) {
					cout << Drivers[i];
				}
			}

			else if (x == 6) {
				for (int i = 0; i < vehicle; i++) {
					cout << Vehicles[i];
				}
			}

			else if (x == 7) {
				for (int i = 0; i < vehicle; i++) {
					int x;
					cout << "Enter Vehical Id: ";
					cin >> x;
					Vehicles[x].getHistory();
				}
			}

			else if (x == 8) {
				int x;
				cout << "Enter Customers Id: ";
				cin >> x;
				Customers[x].gethistory();
			}


			else if (x == 9) {
				int x;
				cout << "Enter Drivers Id: ";
				cin >> x;
				Drivers[x].getHistory();
			}

			else if (x == 10) {
				for (int i = 0; i < drivers; i++) {
					if (Drivers[i].getRanking() >= 4.5) {
						cout << Drivers[i];
					}
				}
			}

			else if (x == 11) {
				cout << "Driver With Multiple License: ";
				for (int i = 0; i < drivers; i++) {
					if (Drivers[i].getNoofLicences() > 1) {
						cout << "Driver Name: " << Drivers[i].getName().getFName() << " " << Drivers[i].getName().getLName() << endl;
						cout << "License List : ";
						Drivers[i].getLicenceList();
						cout << endl;
					}
				}
			}

			else if (x == 12) {
				for (int i = 0; i < drivers; i++) {
					cout << "Drivers Name: " << Drivers[i].getName().getFName() << " " << Drivers[i].getName().getLName() << endl;
					cout << "Driver Salary: " << Drivers[i].getSalary() << endl;
					cout << "-------------------------" << endl << endl;
				}
			}

			else if (x == 15) {
				for (int i = 0; i < customer; i++) {
					for (int j = 0; j < customer; j++) {
						if (Customers[i].get_vehicle_id() == Customers[j].get_vehicle_id()) {
							cout << "Name: " << Customers[i].getName().getFName() << " " << Customers[i].getName().getLName() << endl;
							cout << "Name: " << Customers[i].getName().getFName() << " " << Customers[i].getName().getLName() << endl;
							cout << "Vehicle Id: " << Customers[i].get_vehicle_id();
						}
					}
				}
			}
			cout << "Press Any To Start Again" << endl;
		}
	}
};


void welcomeMessage()
{
	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 300;
	fontex.dwFontSize.X = 36;
	fontex.dwFontSize.Y = 36;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);
	int x = 33;
	int y = 8;
	SetConsoleTextAttribute(console, 12);
	setCursorPointer(x, y); cout << "TRANSPORT MANAGEMENT SYSTEM";
	setCursorPointer(x + 3, y + 3); cout << "Press Any Key To Start";
	setCursorPointer(x + 1, y + 4); cout << "Developed By Abdullah Awan";
}


int main() {
	srand(time(0));
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	welcomeMessage();
	_getch();
	system("cls");
	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 10;
	fontex.dwFontSize.X = 20;
	fontex.dwFontSize.Y = 20;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);
	TMS T1(10, 10, 10);
	T1.find_customer();
	T1.find_Customer_History();
	T1.find_Driver();
	T1.find_Driver_History();
	T1.find_Vehical();
	T1.find_Vehical_History();
	T1.Menu();
}