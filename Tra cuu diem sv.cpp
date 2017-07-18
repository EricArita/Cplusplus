#include<bits/stdc++.h>
using namespace std;

class info_student{ //nhap cac thong tin ve sinh vien
	  public:
	  	string name[6];
	  	int mssv[6],diem_toan[6],diem_van[6];
	  	
	  	void get_info(){
	  		for(int i=1;i<=3;i++){
	  			cout<<"_Sinh vien "<<i<<endl;
	  			cout<<"+ Nhap mssv: "; //msssv la ma so sinh vien
	  			cin>>mssv[i];
	  			cout<<"+ Nhap ten sv: ";
	  			cin.ignore();
	  			getline(cin,name[i]);
	  			cout<<"+ Nhap diem toan: ";
	  			cin>>diem_toan[i];
	  			cout<<"+ Nhap diem van: ";
	  			cin>>diem_van[i];
	  		  }
	  		cout<<"Da nhap thong tin thanh cong!"<<endl;
	  		cout<<"====================================="<<endl;
		 }	
};

class print: public info_student{
	public:
	  void print_info(int i){ // xuat ket qua tra cuu ra man hinh
	  	  cout<<"_Thong tin cua sv "<<i<<":"<<endl;
	  	  cout<<"  mssv: "<<mssv[i]<<"     ";
	  	  cout<<"ten: "<<name[i]<<endl;
	  	  cout<<"   toan: "<<diem_toan[i]<<"     ";
	  	  cout<<"   van: "<<diem_van[i]<<"     ";
	  	  cout<<"diem TB:"<<(diem_toan[i]+diem_van[i])/2;
	  	  cout<<endl;
	  	  cout<<"-------------------------------"<<endl;
	  }	
};

class solve_data: public print{
	  	int dem,num,ma_so;
	  	
	  	
	  public:
	  	string data;
	  	
	  	void change_data_type(){
	  		dem=data.size()-1;
	  		ma_so=0;
	  		for(int i=0;i<data.size();i++){
	  			num=data[i]-48;
	  			ma_so+=num*pow(10,dem);
	  			dem--;
	  		}
	  	}
	  	
	  	
	  	void solve(){ 
	  		if ('1'<=data[0] && data[0]<='9'){ //neu la data nhap la mssv
	  			change_data_type();
	  			
	  			for(int i=1;i<=3;i++)
	  			   if (ma_so==mssv[i]){
	  			   		print_info(i);
	  			   		break;
	  			   }
	  		}
	  		else{ //neu data nhap la ten cua sv
	  			for(int i=1;i<=3;i++)
	  			  if (data==name[i]){
	  			  	 print_info(i);
	  			  	 break;
	  			  }
	  		}
	  	}	
};

class tra_cuu: public solve_data{
	
		public:
			
			void conduct(){
				getline(cin,data); //ten hoac mssv do nguoi tra cuu nhap
				solve(); //tim kiem ket qua
			}
			
};

main(){
		tra_cuu sv;
		sv.get_info();
		cout<<"      Tra cuu thong tin sinh vien!  "<<endl;
		cin.ignore();
		for(int i=1;i<=3;i++){ //tra cuu 3 lan
			cout<<"_ Nhap mssv hoac ten sv can tra cuu: ";
			sv.conduct();
		}
}




