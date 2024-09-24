#include <bits/stdc++.h>
using namespace std;

const bool thirty_days_month[13] = {0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0};

struct date{
    int day, month, year;
    date(int d = 1, int m = 1, int y = 1){
        day = d;
        month = m;
        year = y;
        if(!valid_date())
            cout<<"Invalid date\n";
    }
    bool leap_year(){
        return year%4 == 0;
    }
    bool valid_date(){
        if(month>12 || month<1 || day<1 || year<1) return false;
        if(month == 2){
            if(leap_year()){
                return day<=29;
            }
            return day<=28;
        }
        if(thirty_days_month[month]) return day<=30;
        return day<=31;
    }
    bool operator== (const date& a)const {
        return day==a.day&&month==a.month&&year==a.year;
    }
    bool operator< (const date& a) const{
        if(year == a.year){
            if(month == a.month)
                return day < a.day;
            return month < a.month;
        }
        return year < a.year;
    }
};
struct time_in_day{
    int hour, minute;
    time_in_day(int h=0, int m=0){
        hour = h;
        minute = m;
        if(!valid_time())
            cout<<"Invalid time\n";
    }
    bool valid_time(){
        return hour<24&&hour>=0&&minute<60&&minute>=0;
    }
    bool operator < (const time_in_day& a) const {
        if(hour == a.hour)
            return minute < a.minute;
        return hour < a.hour;
    }
};

struct Flight {
    string flight_code;
    date departure_date;
    time_in_day departure_time;
    string departure_place;
    string arrival_place;

    void Enter(){
        cout << "Nhap ma chuyen bay: ";
        getline(cin, flight_code);

        cout << "Nhap ngay khoi hanh (ngay thang nam): ";
        do{
            cin>>departure_date.day>>departure_date.month>>departure_date.year;
            if(departure_date.valid_date())
                break;
            cout << "Ngay khong hop le, vui long nhap lai: ";
        }while(true);

        cout << "Nhap gio khoi hanh (gio phut): ";
        do{
            cin>>departure_time.hour>>departure_time.minute;
            if(departure_time.valid_time())
                break;
            cout << "Gio khong hop le, vui long nhap lai: ";
        }while(true);

        cout << "Nhap noi di: ";
        cin.ignore();
        getline(cin, departure_place);

        cout << "Nhap noi den: ";
        //cin.ignore();
        getline(cin, arrival_place);
    }
};

void display_flights(vector<Flight> flights) {
    for (Flight fl : flights) {
        cout << "Ma chuyen bay: " << fl.flight_code
             << ", Ngay khoi hanh: " << fl.departure_date.day<<"/"<<fl.departure_date.month<<"/"<<fl.departure_date.year
             << ", Thoi gian: " << fl.departure_time.hour<<"h "<<fl.departure_time.minute<<"p"
             << ", Noi khoi hanh: " << fl.departure_place
             << ", Noi den: " << fl.arrival_place << endl;
    }
}

vector<Flight> find_flight_by_code(vector<Flight> flights, string code) {
    vector<Flight> result;
    for (Flight flight : flights)
        if (flight.flight_code == code)
            result.push_back(flight);
    return result;
}

// tim chuyen bay theo ca noi di va noi den, neu muon tim noi di thi is_departure = true, va nguoc lai
vector<Flight> find_flights_by_place(vector<Flight> flights, string place, bool is_departure = true) {
    vector<Flight> result;
    for (Flight flight : flights) {
        if (is_departure && flight.departure_place == place)
            result.push_back(flight);
        else if (!is_departure && flight.arrival_place == place)
            result.push_back(flight);
    }
    return result;
}

void sort_flights_by_datetime(vector<Flight>& flights) {
    sort(flights.begin(), flights.end(), [](const Flight& f1, const Flight& f2) {
        if (f1.departure_date == f2.departure_date)
            return f1.departure_time < f2.departure_time;
        return f1.departure_date < f2.departure_date;
    });
}
// Hien thi danh sach chuyen bay tu 1 noi trong 1 ngay
vector<Flight> flights_from_place_on_date(vector<Flight> flights, string place, date date) {
    vector<Flight> result;
    for (Flight flight : flights)
        if (flight.departure_place == place && flight.departure_date == date)
            result.push_back(flight);
    return result;
}

int count_flights_between_places( vector<Flight> flights, string departure_place, string arrival_place) {
    int cnt = 0;
    for (Flight flight : flights)
        if (flight.departure_place == departure_place && flight.arrival_place == arrival_place)
            cnt++;
    return cnt;
}

int main() {
    vector<Flight> flights;
    int n;
    cout<<"Nhap so luong chuyen bay: ";
    cin>>n;
    cin.ignore();
    for(int i=1;i<=n;i++){
        Flight flight;
        flight.Enter();
        flights.push_back(flight);
    }
    sort_flights_by_datetime(flights);
    cout<<"Danh sach chuyen bay: \n";
    display_flights(flights);
    cout<<"Nhap vao noi khoi hanh: ";
    string place;
    getline(cin, place);
    vector<Flight> list_flight = find_flights_by_place(flights, place, true);
    display_flights(list_flight);
    cout<<"Nhap vao noi khoi hanh: ";
    string departure_place;
    getline(cin, departure_place);
    cout<<"Nhap vao noi can den: ";
    string arrival_place;
    getline(cin, arrival_place);
    cout<<"So luong chuyen bay la: "<<count_flights_between_places(flights, departure_place, arrival_place);
    return 0;
}
