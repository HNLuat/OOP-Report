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
    // kiem tra nam nay co phai nam nhuan khong
    bool leap_year(){
        return year%4 == 0;
    }
    // kiem tra ngay thang nam co hop le khong
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
    // tinh xem hom nay la ngay thu bao nhieu trong nam
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
    // tinh so ngay tu thoi diem 1, 1, 1 den thoi diem day, month, year
    int total_days_from_begining(){
        return day_of_year() + (year-1)/4 + 365*(year-1);
    }
    // Khoi tao operator == va <
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


struct passbook{
    string idbook;
    string savingType;
    string customerName;
    string customerId;
    date OpeningDate;
    long long deposit;
    double interestRate;

    // Chinh lai suat cho doi tuong
    void setInterestRate( double rate ) {
        interestRate = rate;
    }
    // Kiem tra co dau cach trong string hay khong
    bool check_space( string str ) {
        for ( int i =0; i< str.size();i++ )
            if ( str[i] == ' ' ) return true;
        return false;
    }
    // Kiem tra co so trong string hay khong
    bool check_number( string str ) {
        for ( int i =0; i< str.size(); i++ )
            if ( str[i] >= '0' && str[i] <= '9' ) return true;
        return false;
    }
    // Kiem tra co ki tu dac biet trong string hay khong
    bool check_specialcharacter( string str ){
        for ( int i=0; i< str.size(); i++ )
            if ( !((str[i] >= '0' && str[i] <= '9')
                    || (str[i] >= 'a' && str[i] <= 'z')
                    || (str[i] >= 'A' && str[i] <= 'Z') ) )
                            return true;
        return false;
    }

    // Kiem tra ma so co hop le khong
    bool valid_idbook(){
        if ( idbook.size() <= 5 && !check_space(idbook) && !check_specialcharacter(idbook) ) return true;
    }
    // Kiem tra CMND co hop le khong
    bool valid_customerId(){
        for ( int i=0; i< customerId.size(); i++ )
            if ( customerId[i] > '9' || customerId[i] < '0' )
                return false;

        return customerId < "2147483647";
    }
    // Khoi tao cho doi tuong
    passbook() : idbook(""), savingType(""), customerName(""),
        customerId(""), OpeningDate(date(1,1,1)), deposit(0),
        interestRate(0.0) {}

    // Ham nhap du lieu cho doi tuong
    void nhapdulieu(){
        cout << "Nhap ma so tiet kiem: ";
        while ( true ) {
            getline(cin, idbook);
            if ( valid_idbook() )
                break;
            cout << "Ma so khong hop le, vui long nhap lai: ";
        }

        cout << "Nhap phuong thuc tiet kiem: ";
        getline(cin, savingType);
        cout << "Nhap ten chu so huu: ";
        getline(cin, customerName);

        cout << "Nhap ma CCCD chu so huu: ";
        while ( true ) {
            getline(cin, customerId);
            if ( valid_customerId() )
                break;
            cout << "Ma so khong hop le, vui long nhap lai: ";
        }


        cout << "Nhap ngay mo so (ngay thang nam): ";
        while (1) {
            cin>>OpeningDate.day>>OpeningDate.month>>OpeningDate.year;
            if(OpeningDate.valid_date())
                break;
            cout << "Ngay khong hop le, vui long nhap lai: ";
        }

        cout << "nhap so tien: ";
        while ( true ) {
            cin >> deposit;
            if ( deposit >= 0 )
                break;
            cout << "so tien khong hop le, nhap lai: ";
        }
        cin.ignore();
    }
};

// Ham xuat thong tin cua so tiet kiem
void display(const passbook& account) {
    cout << "Account ID: " << account.idbook << endl;
    cout << "Savings Type: " << account.savingType << endl;
    cout << "Customer Name: " << account.customerName << endl;
    cout << "ID Card: " << account.customerId << endl;
    cout << "Opening Date: " << account.OpeningDate.day << " " << account.OpeningDate.month << " " << account.OpeningDate.year<< endl;
    cout << "Deposit Amount: " << account.deposit << endl;
}

// Ham tinh tien lai cua 1 so tiet kiem sau 1 nam hoac 6 thang
void calculate_on_interest_rate(passbook account){
    cout << " nhap ti le lai suat: " ;
    double interestRatePerYear;
    cin >> interestRatePerYear;
    interestRatePerYear /= 100;
    // Kiem tra loai tiet kiem
    if (account.savingType == "ngan han" ) {
        cout << "lai suat sau 6 thang\n";
        cout << account.deposit * (interestRatePerYear-double(0.5)) / 2 ;
    } else if (account.savingType == "dai han") {
        cout << "lai suat sau 1 nam\n";
        cout << account.deposit * interestRatePerYear;
    } else {
        cout << "Loai tiet kiem khong hop le hoac ky han khong phu hop." << endl;
    }
}

// Tinh lai suat ke tu luc bat dau mo so tiet kiem
void calculate_on_opening_date(passbook account){
    time_t t = time(0);
    tm* now = localtime(&t);
    int cur_day = now->tm_mday;
    int cur_month = now->tm_mon + 1; // tm_mon is 0-based
    int cur_year = now->tm_year + 1900; // tm_year is years since 1900
    date today = date(cur_day, cur_month, cur_year);
    int numberOfYear = today.total_days_from_begining() - account.OpeningDate.total_days_from_begining();
    numberOfYear = numberOfYear / 365;

    double result = account.deposit;
    for ( int i =1; i<= numberOfYear; i++ )
        result = result + result * account.interestRate;
    cout << "Lai suat hien tai: ";
    cout << result << "\n";
}

// Ham rut tien trong so tiet kiem
void withdrawal_function(passbook account, long long amount){
    time_t t = time(0);
    tm* now = localtime(&t);
    int cur_day = now->tm_mday;
    int cur_month = now->tm_mon + 1; // tm_mon is 0-based
    int cur_year = now->tm_year + 1900; // tm_year is years since 1900
    date today = date(cur_day, cur_month, cur_year);
    int numberOfYear = today.total_days_from_begining() - account.OpeningDate.total_days_from_begining();
    numberOfYear = 2 * numberOfYear / 365;

    if ( (numberOfYear < 1 && account.savingType == "ngan han")
            || (numberOfYear < 2 && account.savingType == "dai han") ) {

        cout << "Rut truoc han bi tru 0.5\% lai suat, ban co chac chan khong";
        char confirm = 'Y';
        cin >> confirm;
        if ( confirm == 'N' ) return ;
    }

    calculate_on_interest_rate( account );

}
// Liet ke tat ca ca so tiet kiem trong 1 khoang thoi gian xac dinh
void list_saving_account(vector<passbook> accounts){
    int fromyear, frommonth, fromday, toyear, tomonth, today;
    cout << "nhap khoang thoi gian: ";
    date from_date = date(fromday, frommonth, fromyear);
    date to_date = date(today, tomonth, toyear);
    for ( passbook &account: accounts) {
        if ( from_date.total_days_from_begining() <= account.OpeningDate.total_days_from_begining()
            && account.OpeningDate.total_days_from_begining() < to_date.total_days_from_begining()
        )
        display(account);
    }
}
// Sap xep danh sach so tiet kiem theo so tien gui giam dan
void list_saving_account_deposit_decrease(vector<passbook>& accounts){

    sort( accounts.begin(), accounts.end(), []( const passbook& A, const passbook& B){
        return A.deposit < B.deposit;
    });
    for ( passbook &account: accounts)
        display(account);

}

int main() {
    cout<<"Nhap so luong so tiet kiem: ";
    int n;
    cin>>n;
    cin.ignore();
    vector<passbook> accounts;
    for(int i=1;i<=n;i++){
        passbook a;
        a.nhapdulieu();
        accounts.push_back(a);
    }
    list_saving_account_deposit_decrease(accounts);
    for(passbook i:accounts){
        display(i);
        calculate_on_opening_date(i);
    }
    list_saving_account(accounts);
    return 0 ;
}
