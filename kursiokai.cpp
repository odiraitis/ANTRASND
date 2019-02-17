#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <time.h>
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <iomanip>

double mediana (std::vector<int> temp_paz, int n);
double vidurkis (std::vector<int> temp_paz,int n);

struct mok
{


    double vid=0; // vidurkiai
    double gal; // galutinis
    double media=0;
    double galm;
    int sum=0;
};
struct moky
{
    std::string vard;
    std::string pav;
    int test;
};
int main()
{
    int m=0;
    int n;

    std::string kuris[500]; // generuoti su vidurkiu ar mediana
    std::string kazkas; // skaityt is failo ar ne

    char testas;
    std::string kurie; // generuoti skaicius ar vesti ranka
    std::vector <mok> A; // susikuriu vektoriu
    moky B[500]; // struktura kurioje saugoju tik vardus ir pavardes


    int z=0;
    int o=0;
    int egz; // egzamino pazymys

    srand(time(NULL));

    std::cout<<"Jei norite skaityti is failo spauskite 1, jei nenorite spauskite 2 ?";
    std::cin>>kazkas;
    if(kazkas=="2")
    {
        int i=0;
        int nr=0; // studentu skaic
        int temp=0; // laikinas kintamas
        std::cout<<"Jei norite ivesti nauja mokini spauskite bet koki simboli, jei norite baigti iveskite raide 'f' "<<std::endl;
        while(std::cin>>testas)
        {

            if(testas!='f')
            {
                A.push_back(mok());
                nr++;
                std::cout<<"Jei norite, kad pazymiai butu sugeneruoti spauskite 1, jei norite juos ivesti rankiniu budu, spauskite 2"<<std::endl;
                while(std::cin>>kurie)
                {

                    if(kurie=="1" or kurie=="2")
                    {


                        std::cout<<"Jei galutinis pazymys skaiciuojamas su vidurkiu spauskite 1, jei su mediana 2 "<<std::endl;

                        std::cin>>kuris[i];






                        std::vector<int>pazymiai;
                        int sk=0;

                        if(kurie=="2")
                        {
                            std::cout<<"Ivedus kiekviena skaiciu spauskite 'ENTER', norint baigti iveskite bet koki kita skaiciu"<<std::endl;
                            while(true)
                            {
                                std::cin>>temp;
                                int ivedu=temp;

                                if(ivedu>0 && ivedu<=10)
                                {
                                    pazymiai.push_back(int()); // ivedinejant pazymi pushinu
                                    pazymiai[sk]=ivedu;

                                    sk++; // didinu nd pazymiu skaiciu

                                    n++;
                                }
                                else
                                {
                                    std::cin.clear();
                                    std::cin.ignore();
                                    break;
                                }


                            }
                        }
                        if(kurie=="1")
                        {
                            std::cout<<"Iveskite, kiek norite sugeneruoti skaiciu "<<std::endl;
                            std::cin>>n;
                            while(std::cin.fail())
                            {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

                                std::cout << "Blogas bandymas.  Iveskite skaiciu: ";
                                std::cin >> n;
                            }


                            for(int j=0; j<n; j++)
                            {
                                pazymiai.push_back(int());
                                pazymiai[sk]=1+rand()%10; //generuoju skaicius pushinu ir didinu nd kieki
                                sk++;

                            }
                        }


                        std::cout<<"Iveskite "<<i+1<<" -ojo mokinio varda"<<std::endl;
                        std::cin>>B[i].vard;
                        for(int o=0; o<B[i].vard.size(); o++)
                        {
                            while(B[i].vard[o]!=' ' && (B[i].vard[o]<'A'|| B[i].vard[o]>'Z' )&&(B[i].vard[o]<'a'||B[i].vard[o]>'z')) // tikrinu ar nera skaiciaus ar kito simbolio kuris nera raide
                            {
                                std::cout<<"Iveskite mokinio varda naudodami tik raides"<<std::endl;
                                std::cin>>B[i].vard;
                            }

                        }
                        std::cout<<"Iveskite "<<i+1<<" -ojo mokinio pavarde"<<std::endl;
                        std::cin>>B[i].pav;
                        for(int o=0; o<B[i].pav.size(); o++)
                        {
                            while(B[i].pav[o]!=' ' && (B[i].pav[o]<'A'||B[i].pav[o]>'Z' )&&(B[i].pav[o]<'a'||B[i].pav[o]>'z'))
                            {
                                std::cout<<"Iveskite mokinio pavarde naudodami tik raides"<<std::endl;
                                std::cin>>B[i].pav;
                            }

                        }

                        while(kuris[i]!="1" && kuris[i]!="2")
                        {
                            std::cout<<"Jei norite skaicuoti su mediana spauskite 1, jei su vidurkiu 2"<<std::endl;
                            std::cin>>kuris[i];

                        }
                        std::cout<<"Iveskite "<<i+1<<" -ojo mokinio egzamino pazymi"<<std::endl;
                        std::cin>>egz;
                        while(std::cin.fail() or egz<1 or egz>10)
                        {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                            
                            std::cout << "Blogas bandymas.  Iveskite egzamino rezultata: ";
                            std::cin>>egz;
                        }

                        A[i].media=mediana(pazymiai,sk);

                        A[i].vid=vidurkis(pazymiai,sk);




                        A[i].gal=0.4*A[i].vid+0.6*egz;
                        A[i].galm=0.4*A[i].media+0.6*egz;

                        i++;
                        m++;

                        break;

                    }
                    else
                    {
                        std::cout<<"Iveskite 1 jei norite generuoti arba 2 jei norite vesti pats"<<std::endl;


                    }






                }


            }
            else break;

            std::cout<<"Jei norite ivesti "<<i+1 <<" -aji mokini spauskite bet koki skaiciu, tik ne 0, norint baigti ivedinejima ivesti 'f'"<<std::endl;
        }

        int did_vard=0;
        int did_pav=0;
        for(int i=0; i<nr; i++)
        {
            if(B[i].vard.size()>did_vard) // ieskau ilgiausio vardo
                did_vard=B[i].vard.size();
        }
        for(int i=0; i<nr; i++)
        {
            if(B[i].pav.size()>did_pav) // ieskau ilgiausios pavardes
                did_pav=B[i].pav.size();
        }

        std::cout<<std::left<<std::setw(did_vard+1)<<"Vardas ";
        std::cout<<std::left<<std::setw(did_pav+1)<<"Pavarde ";
        std::cout<<"Galutinis (Vid.)";
        std::cout<<(" Galutinis (Med.)\n ");
        char x='x'; // nera vid arba med reiksmes nes jos nenorejo vartotojas
        for (int i=0; i<did_vard+did_pav+36; i++)
            printf("-");
        std::cout<<std::endl;
        for (int i=0; i<=nr; i++)
        {
            if(kuris[i]=="1")
            {
                std::cout<<std::left<<std::setw(did_vard+1)<<B[i].vard;
                std::cout<<std::left<<std::setw(did_pav+1)<<B[i].pav;
                std::cout<<std::left<<std::setw(16)<<std::fixed<<std::setprecision(2)<<A[i].gal;
                std::cout<<std::left<<std::setw(5)<<x;
                std::cout<<std::endl;
            }
            if(kuris[i]=="2")
            {
                std::cout<<std::left<<std::setw(did_vard+1)<<B[i].vard;
                std::cout<<std::left<<std::setw(did_pav+1)<<B[i].pav;
                std::cout<<std::left<<std::setw(16)<<x;
                std::cout<<std::left<<std::setw(5)<<std::fixed<<std::setprecision(2)<<A[i].galm;
                std::cout<<std::left<<std::endl;
            }
        }
    }

    else if (kazkas=="1")
    {

        int nr=0;
        int temp;

        int i=0;
        std::ifstream in ("kursiokai.txt");
        while(in>>B[i].test) // kol galiu skaityt ir kol lygu nuliui didinu indeksa ir vykdau skaiciavimus
        {
            if(B[i].test==0)
            {
                int sk=0;
                A.push_back(mok());
               in>>B[i].vard>>B[i].pav;
               std::vector<int>pazymiai;
               while(true)
                {
                    in>>temp;
                    int ivedu=temp;
                    if(ivedu>0 && ivedu<=10)
                    {
                        pazymiai.push_back(int()); // ivedinejant pazymi pushinu
                        pazymiai[sk]=ivedu;

                        sk++; // didinu nd pazymiu skaiciu
                        
                    }
                    else
                    {
                       std::cin.clear();
                       std::cin.ignore();

                        break;
                    }
                }
                A[i].media=mediana(pazymiai,sk-1);
                A[i].vid=vidurkis(pazymiai,sk-1);
                egz=pazymiai[sk-1];
                A[i].gal=0.4*A[i].vid+0.6*egz;
                A[i].galm=0.4*A[i].media+0.6*egz;
                  nr++;
                i++;
               // break;
            }
            else break;

        }
        in.close();

        int did_vard=0;
        int did_pav=0;
        for(int i=0; i<nr; i++)
        {
            if(B[i].vard.size()>did_vard) // ieskau ilgiausio vardo
                did_vard=B[i].vard.size();
        }
        for(int i=0; i<nr; i++)
        {
            if(B[i].pav.size()>did_pav) // ieskau ilgiausios pavardes
                did_pav=B[i].pav.size();
        }
        for (int a=0; a<nr-1; a++)
            for (int i=a+1; i<nr; i++)
                if (B[i].vard>B[a].vard)
                {
                      std::swap(a,i);
                }
        
        
        std::cout<<std::left<<std::setw(did_vard+1)<<"Vardas ";
        std::cout<<std::left<<std::setw(did_pav+1)<<"Pavarde ";
        std::cout<<"Galutinis (Vid.)";
        std::cout<<(" Galutinis (Med.)\n ");
        char x='x'; // nera vid arba med reiksmes nes jos nenorejo vartotojas
        for (int i=0; i<did_vard+did_pav+36; i++)
            printf("-");
        std::cout<<std::endl;
        for (int i=0; i<=nr; i++)
        {
            std::cout<<std::left<<std::setw(did_vard+1)<<B[i].vard;
            std::cout<<std::left<<std::setw(did_pav+1)<<B[i].pav;
            std::cout<<std::left<<std::setw(16)<<std::fixed<<std::setprecision(2)<<A[i].gal;
            std::cout<<std::left<<std::setw(5)<<std::fixed<<std::setprecision(2)<<A[i].galm;
            std::cout<<std::endl;
        }
    }

    return 0;
}
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
};
