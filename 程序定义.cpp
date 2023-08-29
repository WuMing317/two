#include<iostream>
#include<iomanip>
using namespace std;
class Keren {
private:
    string name;
    string sf_id;
    double pay;
public:
    Keren() {}
    Keren(string name, string sf_id, double pay) : name(name), sf_id(sf_id), pay(pay) {}

    string getname() {
        return name;
    }
    string getsf_id() {
        return sf_id;
    }
    double getpay() {
        return pay;
    }

    virtual void display() = 0;
    virtual void setpay() = 0;
};

class Puke : public Keren {
public:
    Puke() {}
    Puke(string name, string sf_id, double pay) : Keren(name, sf_id, pay) {}

    void display() {
        cout << "普通客人:";
    }
    void setpay() {
        double pay;
        pay = Keren::getpay();
    }
};

class Vip : public Keren {
private:
    int rank;
public:
    Vip() {}
    Vip(string name, string sf_id, double pay, int rank) : Keren(name, sf_id, pay), rank(rank) {}

    void display() {
        cout << "vip客人:";
    }
    void setpay() {
        double pay;
        pay = ((10 - rank) / 10) * Keren::getpay();
    }
};

class Svip : public Keren {
private:
    int rank;
    double zekou = 0.7;
public:
    Svip() {}
    Svip(string name, string sf_id, double pay, int rank, double zekou) : Keren(name, sf_id, pay), rank(rank), zekou(zekou) {}

    void display() {
        cout << "svip客人:";
    }
    void setpay() {
        double pay;
        pay = zekou * Keren::getpay();
    }
};

class Jiudian {
private:
    int room_id;
    double end_pay;
public:
    Jiudian() {}
    Jiudian(int room_id, double end_pay) : room_id(room_id), end_pay(end_pay) {}

    void display() {
        cout << Keren::getname() << endl << "c" << Keren::getsf_id() << endl << "房间号：" << room_id << endl;
    }
    void setpay() {
        end_pay = Keren::getpay();
        cout << fixed << setprecision(2) << end_pay;
    }
};

int main() {
    string name, sf_id;
    int sf_id_num, rank, room_id;
    double pay, end_pay, zekou;

    cout << "客人等级：";
    while (cin >> rank) {
        cout << endl;
        if (rank == 0) {
            cout << "客人名字：";
            cin >> name;
            cout << endl;
            cout << "客人身份证号：";
            cin >> sf_id;
            cout << endl;
            cout << "客人费用：";
            cin >> pay;
            cout << endl;

            Puke pu(name, sf_id, pay);
            pu.display();
            pu.setpay();

            Jiudian jiu(room_id, end_pay);
            jiu.display();
            jiu.setpay();
        }
        else if (rank >= 1 && rank <= 4) {
            cout << "客人名字：";
            cin >> name;
            cout << endl;
            cout << "客人身份证号：";
            cin >> sf_id;
            cout << endl;
            cout << "客人费用：";
            cin >> pay;
            cout << endl;
            cout << "客人等级：";
            cin >> rank;
            cout << endl;

            Vip vi(name, sf_id, pay, rank);
            vi.display();
            vi.setpay();

            Jiudian jiu(room_id, end_pay);
            jiu.display();
            jiu.setpay();
        }
        else if (rank > 5) {
            cout << "客人名字：";
            cin >> name;
            cout << endl;
            cout << "客人身份证号：";
            cin >> sf_id;
            cout << endl;
            cout << "客人费用：";
            cin >> pay;
            cout << endl;
            cout << "客人等级：";
            cin >> rank;
            cout << endl;
            cout << "客人折扣：";
            cin >> zekou;
            cout << endl;
            cout<<"房间号："；
			cin>>room_id;
			cout<<endl; 

            Svip sv(name, sf_id, pay, rank, zekou);
            sv.display();
            sv.setpay();

            Jiudian jiu(room_id, end_pay);
            jiu.display();
            jiu.setpay();
        }
    }

    return 0;
}
