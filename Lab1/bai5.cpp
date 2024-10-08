#include <bits/stdc++.h>
using namespace std;
struct date{
    int day, month, year;
    // luu thang thu i co phai la thang co 30 ngay hay khong
    const bool thirty_days_month[13] = {0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0};
    date(int d = 1, int m = 1, int y = 1){
        day = d;
        month = m;
        year = y;
        if(!valid_date())
            cout<<"Invalid date\n";
    }
    //Truong hop nam nhuan
    bool leap_year(){
        return year%4 == 0;
    }
    //Ngay do co hop le khong
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
    // Tinh ngay tiep theo
    date next_date(){
        if(!valid_date())
            return date(-1, -1, -1);
        if(day==31 && month==12)
            return date(1, 1, year+1);
        if(month==2){
            if(leap_year() && day==29) return date(1, 3, year);
            if(!leap_year() && day==28) return date(1, 3, year);
            return date(day+1, 2, year);
        }
        if(thirty_days_month[month] && day==30)
            return date(1, month+1, year);
        if(!thirty_days_month[month] && day==31)
            return date(1, month+1, year);
        return date(day+1, month, year);
    }
    // Tinh ngay truoc do
    date previous_date(){
        if(!valid_date())
            return date(-1, -1, -1);
        if(day==1 && month==1)
            return date(31, 12, year-1);
        if(month == 3){
            if(leap_year() && day==1) return date(29, 2, year);
            if(!leap_year() && day==1) return date(28, 2, year);
            return date(day-1, 3, year);
        }
        if(day == 1){
            if(thirty_days_month[month-1]) return date(30,month-1,year);
            return date(31,month-1,year);
        }
        return date(day-1, month, year);
    }
    // tinh ngay nay la ngay thu bao nhieu trong nam
    int day_of_year(){
        if(!valid_date()) return -1;
        int sum = day;
        for(int i=1; i<month; i++){
            if(i==2){
                sum += leap_year()+28;
                continue;
            }
            if(thirty_days_month[i])
                sum += 30;
            else sum += 31;
        }
        return sum;
    }
};
int main()
{
    cout<<"Enter Day/Month/Year: ";
    date a;
    cin>>a.day>>a.month>>a.year;
    date nexta = a.next_date();
    date preva = a.previous_date();
    cout<<"The next day is "<<nexta.day<<"/"<<nexta.month<<"/"<<nexta.year<<"\n";
    cout<<"The previous day is "<<preva.day<<"/"<<preva.month<<"/"<<preva.year<<"\n";
    cout<<a.day<<"/"<<a.month<<"/"<<a.year<<" is the "<<a.day_of_year()<<"(th) day of the year";
    return 0;
}

