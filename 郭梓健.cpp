#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
class Keren{
	private:
		int rank;
		string name;
		string sf_id;
		double pay;
	public:
		Keren(){
		}
		Keren(int rank,string name,string sf_id,double pay){
			this->rank=rank;
			this->name=name;
			this->sf_id=sf_id;
			this->pay=pay;
		}
		int getrank(){
			return rank;
		}
		string getname(){
			return name;
		}
		string getsf_id(){
			return sf_id;
		}
		double getpay(){
			return pay;
		}
		virtual void display()=0;
		virtual void setplay()=0;
};
class Puke:public virtual Keren{
	public:
		Puke(){
		}
		Puke(int rank,string name,string sf_id,double pay):Keren(rank,name,sf_id,pay){
		}
		void display(){
			cout<<"普通客人:"; 
		}
		void setplay(){
			double pupay;
			pupay=getpay();
		}
};
class Vip:public virtual Keren{
	private:
		double vzekou;
	public:
		Vip(){
		}
		Vip(int rank,string name,string sf_id,double pay,double vzekou):Keren(rank,name,sf_id,pay){
			this->vzekou=vzekou;
		}
		double getvzekou(){
			return vzekou;
		}
		void display(){
			cout<<"vip客人:";
		}
		void setplay(){
			double vipay;
			vipay=vzekou*getpay(); 	
		}
};
class Svip:public virtual Keren{
	private:
		double szekou;
	public:
		Svip(){
		}
		Svip(int rank,string name,string sf_id,double pay,double szekou):Keren(rank,name,sf_id,pay){
			this->szekou=szekou;
		}
		double getszekou(){
			return szekou;
		}
		void display(){
			cout<<"svip客人:";
		}
		void setplay(){
			double svpay;
			svpay=szekou*getpay(); 	
		}
};
class Jiudian:public Puke,Vip,Svip{
	private:
		int room_id;
	public:
		Jiudian(){
		}
		Jiudian(int rank,string name,string sf_id,double pay,double vzekou,double szekou,int room_id)
		:Keren(rank, name, sf_id, pay),Puke(rank,name,sf_id,pay),Vip(rank,name,sf_id,pay,vzekou),Svip(rank,name,sf_id,pay,szekou){
			this->room_id=room_id;
		}
		void display(){
			cout<<getname()<<endl<<"客人身份照号"<<getsf_id()<<endl<<"房间号："<<room_id<<endl;
		}
		void setplay(){
			double end_pay;
			if(getrank()==0){
				end_pay=Puke::getpay();
				cout<<"客人需支付："<<end_pay<<"元"<<endl;
			}
			else if(getrank()>=1&&getrank()<=5){
				end_pay=Vip::getvzekou() * getpay();
				cout<<"客人需支付："<<end_pay<<"元"<<endl;
			}
			else if(getrank()>5){
				end_pay=Svip::getszekou() * getpay();
				cout<<"客人需支付："<<end_pay<<"元"<<endl;
			}	
		}
};
int main(){
	string name,sf_id;
	int rank,room_id;
	double pay,vzekou,szekou;
	cout<<"客人等级：";
	while(cin>>rank){
			cout<<"客人名字：";
			cin>>name;
			cout<<"客人身份证号：";
			cin>>sf_id;
			cout<<"客人费用：";
			cin>>pay;
			cout<<"vip折扣：";
            cin>>vzekou;
			cout<<"svip折扣：";
            cin>>szekou;
			cout<<"房间号："; 
			cin>>room_id;
			Jiudian ji(rank,name,sf_id,pay,vzekou,szekou,room_id);
			ji.display();
			ji.setplay();
		}
}
