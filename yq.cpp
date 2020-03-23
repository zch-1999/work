#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<algorithm>
using namespace std;

struct city
{
    string name;
    int sum;
};

struct province
{
    string name;
    city c[50];
    int city_sum=0;
    int total=0;
};
province pro[50];
int pro_sum=0;

void Find(string p,city t)
{
    for(int i=0; i<pro_sum; i++)
    {
        if(pro[i].name==p)
        {
            pro[i].c[pro[i].city_sum]=t;
            pro[i].city_sum++;
            pro[i].total+=t.sum;
            return ;
        }
    }
    pro[pro_sum].c[pro[pro_sum].city_sum]=t;
    pro[pro_sum].city_sum++;
    pro[pro_sum].name=p;
    pro[pro_sum].total+=t.sum;
    pro_sum++;
}

void getData()
{
    ifstream fin("yq_in_04.txt",ios::in);
    if(fin.fail())
    {
        cout<<"yq_in_04.txt 文件打开失败 请将该文件移至当前目录!";
        exit(0);
    }
    string p,c;
    int s;
    while(fin>>p>>c>>s)
    {
        city temp;
        temp.name=c;
        temp.sum=s;
        Find(p,temp);
    }
    fin.close();
}

void show(){
    for(int i=0;i<pro_sum;i++){
        cout<<pro[i].name<<endl;
        for(int j=0;j<pro[i].city_sum;j++){
            cout<<pro[i].c[j].name<<" "<<pro[i].c[j].sum<<endl;
        }
        cout<<"总数:"<<pro[i].total<<"\n\n";
    }
}

bool cmp(city p1,city p2){
    if(p1.sum==p2.sum){          //总数一样 按名称排序
        return p1.name>p2.name;
     }
     else{
        return p1.sum>p2.sum;
     }
}

bool cmp1(province p1,province p2){
     if(p1.total==p2.total){
        return p1.name>p2.name;  //总数一样 按名称排序
     }
     else{
        return p1.total>p2.total;
     }
}

void sortCity(){
    for(int i=0;i<pro_sum;i++){
        sort(pro[i].c,pro[i].c+pro[i].city_sum,cmp);
    }
    //show();
}

void sortProvince(){
    sort(pro,pro+pro_sum,cmp1);
}

void sortData(){
    sortCity();
    sortProvince();
}

void putData(){
    ofstream fout("yq_out_04.txt",ios::out);
    for(int i=0;i<pro_sum;i++){
        fout<<pro[i].name<<endl;
        for(int j=0;j<pro[i].city_sum;j++){
            fout<<pro[i].c[j].name<<" "<<pro[i].c[j].sum<<endl;
        }
        fout<<"总数:"<<pro[i].total<<"\n\n";
    }
    fout.close();
    cout<<"文件排序完成!已保存到yq_out_04.txt"<<endl;
}

int main()
{
    getData();//获取数据
    sortData();//排序
    putData();//输出数据
}
