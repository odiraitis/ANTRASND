#include "header.h"

double mediana (std::vector<int> temp_paz, int n)
{
    std::string kuris;
    for (int a=0; a<n-1; a++)
        for (int i=a+1; i<n; i++)
            if (temp_paz[i]<temp_paz[a])
                std::swap(temp_paz[i],temp_paz[a]);
    if (n%2==0)
        return 1.0*(temp_paz[n/2]+temp_paz[n/2-1])/2;
    else
        return 1.0*(temp_paz[n/2]);
}
double vidurkis (std::vector<int> temp_paz,int n)
{
    int sum=0;
    for (int i=0; i<n; i++)
        sum+=temp_paz[i];
    return 1.0*sum/n;
}
bool skaicius(const std::string &str) // Tikrinimas ar vien tik skaiciai
{
    return std::all_of(str.begin(), str.end(), ::isdigit);
}
bool gavoSkolos( const mok & i )
{
    return (i.galm<5 && i.gal<5);
}
bool negavoSkolos( const mok & i )
{
    return (i.galm>=5 && i.gal>=5);
}
void pazymys (std::vector<int>&laikinas, int &sk)
{
    std::string temp; // laikinas kintamas
    while(  std::cin>>temp)
    {
        if(skaicius(temp)==true)
        {
            
            int ivedu=std::stoi(temp);
            if(ivedu>0 && ivedu<11)
            {
                laikinas.push_back(int()); // ivedinejant pazymi pushinu
                laikinas[sk]=ivedu;
                sk++; // didinu nd pazymiu skaiciu
                
            }
            else
            {
                if(laikinas.size()!=0)
                    break;
                else std::cout<<"Ivesk pazymi, kadangi ivestas skaicius nera pazymys, noredami baigti iveskite bet koki kita skaiciu nuo 1 iki 10 "<<std::endl;
            }
            
        }
        else std::cout<<"Ivedete blogus duomenis, veskite dar karta"<<std::endl;
    }
}
void generuoju (std::vector<int>&laikinas,int k, int &sk)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1,10);
    for(int j=0; j<k; j++)
    {
        laikinas.push_back(int());
        laikinas[sk]=dist(mt); //generuoju skaicius pushinu ir didinu nd kieki
        sk++;
    }
}
void generuoju (std::vector<int>&laikinas,int l)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1,10);
    
    for(int l=0; l<10; l++)
    {
        laikinas.push_back(int());
        laikinas[l]=dist(mt); //generuoju skaicius pushinu ir didinu nd kieki
    }
    
}
double galutinis_vid (int temp, std::vector<int>temp_paz, int t)
{
    double vid=vidurkis(temp_paz,t-1);
    double gal=0.4*vid+0.6*temp;
    return gal;
}
double galutinis_med (int temp, std::vector<int>temp_paz, int t)
{
    double med=mediana(temp_paz,t-1);
    double gal=0.4*med+0.6*temp;
    return gal;
}
void fail_generav()
{
    for(int i=10; i<=100000; i*=10)
    {
        std::ofstream out;
        out.open(std::to_string(i)+".txt");
        
        for(int j=1; j<=i; j++)
        {
            std::vector<int>paz;
            std::string s = std::to_string(j);
            out<<"Vardas"+s<<" "<<"Pavarde"+s;
            int skaic=0;
            std::vector<int>::iterator IT;
            generuoju(paz,10);
            for(IT=paz.begin(); IT<paz.end();IT++)
            {
                out<<" "<<*IT;
            }
            out<<std::endl;
            
        }
        out.close();
    }
}
void skaitymas2(std::deque<mok>&tem, std::string pava, int &l, int &n)
{
    std::string temp;
    std::string eil,vard,pav;
    std::ifstream in_file (pava);
    if (in_file.good()){
        while(std::getline(in_file,eil)){  // Nuskaito po visa eilute txt faile
            tem.push_back(mok());
            std::istringstream in_line(eil); // Skaitymas is eilutes
            in_line >> vard >> pav;
            tem[n].vard=vard;
            tem[n].pav=pav;
            n++;
            int sk=0;
            std::vector<int> pazymiai;
            while(in_line>>temp){
                
                if(skaicius(temp)){
                    int ivedu = stoi(temp);
                    if (ivedu>=0 and ivedu<=10){
                        pazymiai.push_back(int());
                        pazymiai[sk]=ivedu;
                        // std::cout<<pazymiai[sk]<<std::endl;
                        sk++;
                    }
                }
            }
            in_line.end;
            int egz = 0;
            egz = pazymiai[sk-1]; // Paskutinis ivestas skaicius egzamino pazimys
            tem[l].gal=galutinis_vid(egz,pazymiai,sk);
            tem[l].galm=galutinis_med(egz,pazymiai,sk);
            in_line.clear();
            in_file.clear();
            l++;
        }
    }
}
void spausdinimas2 (std::deque<mok>temp, std::deque<mok>temp_lievi)
{
    int did_vard=6;
    for(int i=0; i<temp.size(); i++)
    {
        if(temp[i].vard.size()>did_vard) // ieskau ilgiausio vardo
            did_vard=temp[i].vard.size();
    }
    int did_pav=7;
    for(int i=0; i<temp.size(); i++)
    {
        if(temp[i].pav.size()>did_pav) // ieskau ilgiausio vardo
            did_pav=temp[i].vard.size();
    }

    std::ofstream kiet ("kieciukai.txt");
    std::ofstream nus ("nuskriaustukai.txt");
    kiet<<std::left<<std::setw(did_vard+1)<<"Vardas ";
    kiet<<std::left<<std::setw(did_pav+1)<<"Pavarde ";
    kiet<<"Galutinis (Vid.)";
    kiet<<(" Galutinis (Med.)\n ");
    nus<<std::left<<std::setw(did_vard+1)<<"Vardas ";
    nus<<std::left<<std::setw(did_pav+1)<<"Pavarde ";
    nus<<"Galutinis (Vid.)";
    nus<<(" Galutinis (Med.)\n ");
    char x='x'; // nera vid arba med reiksmes nes jos nenorejo vartotojas
    for (int i=0; i<did_vard+did_pav+36; i++)
    {
        kiet<<"-";
        nus<<"-";
    }
    
    kiet<<std::endl;
    nus<<std::endl;
    for(int i=0; i<temp.size(); i++)
    {
        kiet<<std::left<<std::setw(did_vard+1)<<temp[i].vard;
        kiet<<std::left<<std::setw(did_pav+1)<<temp[i].pav;
        kiet<<std::left<<std::setw(16)<<std::fixed<<std::setprecision(2)<<temp[i].gal;
        kiet<<std::left<<std::setw(5)<<std::fixed<<std::setprecision(2)<<temp[i].galm;
        kiet<<std::endl;
    }
    for(int i=0; i<temp_lievi.size(); i++)
    {
        nus<<std::left<<std::setw(did_vard+1)<<temp_lievi[i].vard;
        nus<<std::left<<std::setw(did_pav+1)<<temp_lievi[i].pav;
        nus<<std::left<<std::setw(16)<<std::fixed<<std::setprecision(2)<<temp_lievi[i].gal;
        nus<<std::left<<std::setw(5)<<std::fixed<<std::setprecision(2)<<temp_lievi[i].galm;
        nus<<std::endl;
    }
}
std::deque<mok> raskMinkstus(std::deque<mok>&studentai) {
    std::deque<mok>templievi;
    int kiek=0;
    std::deque<mok>::size_type r = 0;
    for ( r=0; r<studentai.size(); r++)
    {
        if (studentai[r].gal<5 && studentai[r].galm<5)
        {
            templievi.push_back(studentai[r]);
        }
        else
        {
            kiek++;
            studentai.push_front(studentai[r]);
            r++;
        }
    }
    studentai.resize(kiek);
    studentai.shrink_to_fit();
    return templievi;  // grąžina studentus gavusius skolą
}

