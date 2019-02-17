#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <string.h>
#include <time.h>
#include <vector>
#include <stdlib.h>
double mediana (int *m, int n);
struct mok
{
    std::string vard;
    std::string pav;
    std::string kuris;
    int nd[500];
    double vid=0; // vidurkiai
    double egz; // egzo rez
    double gal; // galutinis
    double media=0;
    double galm;
    int sum=0;
};
int main()
{
    int m=0;
    int n;

    int kazkas;
    char testas; // naudoju nuskaitymui pirmo elemento kad galeciau daug kartu nuskaityt mokinius
    std::string kurie; // kintamasis nuskaityti ar generuoti reiksmes ar ivesti ranka
    mok A[1000];
    
    int i=0;
    int z=0;
    int o=0;
    
    srand(time(NULL));
    std::cout<<"Jei norite ivesti nauja mokini spauskite bet koki simboli, jei norite baigti iveskite raide 'f' "<<std::endl;
    while(std::cin>>testas)
    {
        if(testas!='f')
        {
            std::cout<<"Jei norite, kad pazymiai butu sugeneruoti spauskite 1, jei norite juos ivesti rankiniu budu, spauskite 2"<<std::endl;
            while(std::cin>>kurie)
            {
                if(kurie=="1" or kurie=="2")
                {


                    std::cout<<"Jei galutinis pazymys skaiciuojamas su vidurkiu spauskite 1, jei su mediana 2 "<<std::endl;
                    std::cin>>A[i].kuris;
                    while(A[i].kuris!="1" && A[i].kuris!="2")
                    {
                        std::cout<<"Jei norite skaicuoti su mediana spauskite 1, jei su vidurkiu 2"<<std::endl;
                        std::cin>>A[i].kuris;
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
                    }

                    std::cout<<"Iveskite "<<i+1<<" -ojo mokinio varda"<<std::endl;
                    std::cin>>A[i].vard;
                    for(int o=0; o<A[i].vard.size(); o++)
                    {
                        while(A[i].vard[o]!=' ' && (A[i].vard[o]<'A'|| A[i].vard[o]>'Z' )&&(A[i].vard[o]<'a'||A[i].vard[o]>'z'))// tikrinu ar kiekvienas simbolis nera raide, jei nera raide reikia vesti is naujo
                        {
                            std::cout<<"Iveskite mokinio varda naudodami tik raides"<<std::endl;
                            std::cin>>A[i].vard;
                        }

                    }
                    std::cout<<"Iveskite "<<i+1<<" -ojo mokinio pavarde"<<std::endl;
                    std::cin>>A[i].pav;
                    for(int o=0; o<A[i].pav.size(); o++)
                    {
                        while(A[i].pav[o]!=' ' && (A[i].pav[o]<'A'|| A[i].pav[o]>'Z' )&&(A[i].pav[o]<'a'||A[i].pav[o]>'z'))
                        {
                            std::cout<<"Iveskite mokinio pavarde varda naudodami tik raides"<<std::endl;
                            std::cin>>A[i].pav;
                        }

                    }



                    if(kurie=="1")
                    {
                        for(int j=0; j<n; j++)
                        {
                            A[i].nd[j]=1+rand()%10; // generuoju nuo 1 iki 10
                            A[i].sum+=A[i].nd[j];

                        }


                    }
                    if(kurie=="2")
                    {
                        std::cout<<"Ivedus kiekviena skaiciu spauskite 'ENTER', norint baigti iveskite bet koki kita skaiciu"<<std::endl;
                        while(std::cin>>A[i].nd[z])
                        {

                            if(A[i].nd[z]>0&& A[i].nd[z]<=10)
                            {
                                A[i].sum+=A[i].nd[z];

                                z++;
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

                    A[i].media=mediana(A[i].nd,n);

                    A[i].vid=double(A[i].sum/n);

                    std::cout<<"Iveskite "<<i+1<<" -ojo mokinio egzamino pazymi"<<std::endl;
                    std::cin>>A[i].egz;
                    while(A[i].egz!=1 &&A[i].egz!=2 && A[i].egz!=3 && A[i].egz!=4 && A[i].egz!=5 && A[i].egz!=6 && A[i].egz!=7 && A[i].egz!=8 && A[i].egz!=9 && A[i].egz!=10)
                    {
                        std::cout<<"Iveskite mokinio egzamino pazymi naudodami tik skaicius nuo 1 iki 10 imtinai"<<std::endl;
                        std::cin>>A[i].egz;
                    }

                    A[i].gal=0.4*A[i].vid+0.6*A[i].egz;
                    A[i].galm=0.4*A[i].media+0.6*A[i].egz;

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
    for(int i=0; i<m; i++)
    {
        if(A[i].vard.size()>did_vard)
            did_vard=A[i].vard.size(); // ieskau ilgiausio vardo
    }
      for(int i=0; i<m; i++)
    {
        if(A[i].pav.size()>did_pav)
            did_pav=A[i].pav.size();// ieskau ilgiausios pavardes
    }

    std::cout<<std::left<<std::setw(did_vard+1)<<"Vardas ";
    std::cout<<std::left<<std::setw(did_pav+1)<<"Pavarde ";
    std::cout<<"Galutinis (Vid.)";
    std::cout<<(" Galutinis (Med.)\n ");
    char x='x';
    for (int i=0;i<did_vard+did_pav+36;i++)
                    printf("-");
    std::cout<<std::endl;
     for (int i=0;i<=m;i++)
        {
            if(A[i].kuris=="1")
            {
                  std::cout<<std::left<<std::setw(did_vard+1)<<A[i].vard;
                  std::cout<<std::left<<std::setw(did_pav+1)<<A[i].pav;
                  std::cout<<std::left<<std::setw(16)<<std::fixed<<std::setprecision(2)<<A[i].gal;
                  std::cout<<std::left<<std::setw(5)<<x;
                  std::cout<<std::endl;
            }
            if(A[i].kuris=="2")
            {
                  std::cout<<std::left<<std::setw(did_vard+1)<<A[i].vard;
                  std::cout<<std::left<<std::setw(did_pav+1)<<A[i].pav;
                  std::cout<<std::left<<std::setw(16)<<x;
                  std::cout<<std::left<<std::setw(5)<<std::fixed<<std::setprecision(2)<<A[i].galm;
                  std::cout<<std::left<<std::endl;
            }

        }




        return 0;
}
double mediana (int *m, int n)
{

    int *a=new int[n];
    for(int i=0; i<n; i++)
    {
        a[i]=m[i];
    }

    int  laik=0;
    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++)
            if (a[i]>a[j])
            {
                laik = a[i];
                a[i] = a[j];
                a[j] = laik;
            }
    int vidurkis=n/2;

    double media;
    if (n%2==1) // jei nelyginis
    {

        media=a[vidurkis];

    }
    else
    {
        media=(double)(a[vidurkis]+a[vidurkis-1])/2;
    }
    delete []a;
    return media;
}
