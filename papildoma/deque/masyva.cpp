#include "header.h"
int main()
{
    int m=0;
    int n;


    char kazkas; // skaityt is failo ar ne

    std::string testas;
    char kurie; // generuoti skaicius ar vesti ranka
    std::deque <mok> A; // susikuriu vektoriu
   
    int skaic=0;
    int z=0;
    int egz; // egzamino pazymys
            int k=0;
            int nr=0;
            fail_generav();
            std::string pav;
           
            for(int i=10; i<100000; i*=10)
            {
                std::string temp = std::to_string(i);
                pav=temp +".txt";
                skaitymas2(A,pav,k,nr);
              
            }
             auto start = std::chrono::high_resolution_clock::now();
            std::deque<mok>lievi;
            lievi=raskMinkstus(A);
            int r=0;
            spausdinimas2(A,lievi);
            //===================================
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end-start;
            std::cout << "Failu generavimas ir nuskaitymas, paskirstymas uztruko: "
            << diff.count() << " s\n";
    return 0;
}
