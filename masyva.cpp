#include "header.h"

int main()
{
    int m=0;
    int n;
    
    std::string kuris[500]; // generuoti su vidurkiu ar mediana
    std::string kazkas; // skaityt is failo ar ne
    
    std::string testas;
    std::string kurie; // generuoti skaicius ar vesti ranka
    std::vector <mok> A; // susikuriu vektoriu
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1,10);
    
    
    int z=0;
    int o=0;
    int egz; // egzamino pazymys
    
    srand(time(NULL));
    
    std::cout<<"Jei norite skaityti is failo spauskite 1, jei norite duomenis rinktis pats spauskite 2, jei norite sugeneruoti failus spauskite 3 ?";
    std::cin>>kazkas;
    while(kazkas!="1" and kazkas!="2" and kazkas!="3")
    {
        std::cout<<"Jei norite skaityti is failo spauskite 1, jei norite duomenis rinktis pats spauskite 2, jei norite sugeneruoti failus spauskite 3 ?";
        std::cin>>kazkas;
    }
    if(kazkas=="2")
    {
        int i=0;
        int nr=0; // studentu skaic
        int temp=0; // laikinas kintamas
        std::cout<<"Jei norite ivesti nauja mokini spauskite bet koki simboli, jei norite baigti iveskite raide 'f' "<<std::endl;
        while(std::cin>>testas)
        {
            
            if(testas!="f")
            {
                A.push_back(mok());
                nr++;
                std::cout<<"Jei norite, kad pazymiai butu sugeneruoti spauskite 1, jei norite juos ivesti rankiniu budu, spauskite 2"<<std::endl;
                while(std::cin>>kurie)
                {
                    while(kurie!="1" and kurie!="2")
                    {
                        std::cout<<"Jei norite, kad pazymiai butu sugeneruoti spauskite 1, jei norite juos ivesti rankiniu budu, spauskite 2"<<std::endl;
                        std::cin>>kurie;
                    }
                    
                    if(kurie=="1" or kurie=="2")
                    {
                        
                        
                        std::cout<<"Jei galutinis pazymys skaiciuojamas su vidurkiu spauskite 1, jei su mediana 2 "<<std::endl;
                        
                        std::cin>>kuris[i];
                        
                        
                        
                        
                        
                        
                        std::vector<int>pazymiai;
                        int sk=0;
                        
                        if(kurie=="2")
                        {
                            std::cout<<"Ivedus kiekviena skaiciu spauskite 'ENTER', norint baigti iveskite bet koki kita simboli ar skaiciu"<<std::endl;
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
                            while(std::cin.fail() or n==0)
                            {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                                
                                std::cout << "Blogas bandymas.  Iveskite skaiciu nelygu 0: ";
                                std::cin >> n;
                            }
                            
                            
                            
                            
                            for(int j=0; j<n; j++)
                            {
                                pazymiai.push_back(int());
                                pazymiai[sk]=dist(mt); //generuoju skaicius pushinu ir didinu nd kieki
                                sk++;
                            }
                        }
                        
                        
                        std::cout<<"Iveskite "<<i+1<<" -ojo mokinio varda"<<std::endl;
                        std::cin>>A[i].vard;
                        for(int o=0; o<A[i].vard.size(); o++)
                        {
                            while(A[i].vard[o]!=' ' && (A[i].vard[o]<'A'|| A[i].vard[o]>'Z' )&&(A[i].vard[o]<'a'||A[i].vard[o]>'z')) // tikrinu ar nera skaiciaus ar kito simbolio kuris nera raide
                            {
                                std::cout<<"Iveskite mokinio varda naudodami tik raides"<<std::endl;
                                std::cin>>A[i].vard;
                            }
                            
                        }
                        std::cout<<"Iveskite "<<i+1<<" -ojo mokinio pavarde"<<std::endl;
                        std::cin>>A[i].pav;
                        for(int o=0; o<A[i].pav.size(); o++)
                        {
                            while(A[i].pav[o]!=' ' && (A[i].pav[o]<'A'||A[i].pav[o]>'Z' )&&(A[i].pav[o]<'a'||A[i].pav[o]>'z'))
                            {
                                std::cout<<"Iveskite mokinio pavarde naudodami tik raides"<<std::endl;
                                std::cin>>A[i].pav;
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
        
        int did_vard=6;
        int did_pav=7;
        for(int i=0; i<nr; i++)
        {
            if(A[i].vard.size()>did_vard) // ieskau ilgiausio vardo
                did_vard=A[i].vard.size();
        }
        for(int i=0; i<nr; i++)
        {
            if(A[i].pav.size()>did_pav) // ieskau ilgiausios pavardes
                did_pav=A[i].pav.size();
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
                std::cout<<std::left<<std::setw(did_vard+1)<<A[i].vard;
                std::cout<<std::left<<std::setw(did_pav+1)<<A[i].pav;
                std::cout<<std::left<<std::setw(16)<<std::fixed<<std::setprecision(2)<<A[i].gal;
                std::cout<<std::left<<std::setw(5)<<x;
                std::cout<<std::endl;
            }
            if(kuris[i]=="2")
            {
                std::cout<<std::left<<std::setw(did_vard+1)<<A[i].vard;
                std::cout<<std::left<<std::setw(did_pav+1)<<A[i].pav;
                std::cout<<std::left<<std::setw(16)<<x;
                std::cout<<std::left<<std::setw(5)<<std::fixed<<std::setprecision(2)<<A[i].galm;
                std::cout<<std::left<<std::endl;
            }
        }
    }
    
    else if (kazkas=="1")
    {
        
        int nr=0;
        
        int i=0;
        std::string temp;
        std::string eil,vard,pav;
        std::ifstream in_file ("kursiokai.txt");
        try{
            if(!in_file.good())
            {
                throw "Nera failo";
            }
        }
        catch(const char *msg){
            std::cout<<msg<<std::endl;
            // break;
        }
        
        while(std::getline(in_file,eil)){  // Nuskaito po visa eilute txt faile
            
            A.push_back(mok());
            std::istringstream in_line(eil); // Skaitymas is eilutes
            in_line >> vard >> pav;
            A[nr].vard=vard;
            A[nr].pav=pav;
            nr++;
            int sk=0;
            std::vector<int> pazymiai;
            while(in_line>>temp){
                if(skaicius(temp)){
                    int ivedu = std::stoi(temp);
                    if (ivedu>=0 and ivedu<=10){
                        pazymiai.push_back(int());
                        pazymiai[sk]=ivedu;
                        sk++;
                    }
                }
            }
            
            in_line.end;
            int egz = 0;
            egz = pazymiai[sk-1]; // Paskutinis ivestas skaicius egzamino pazimys
            std::cout<<egz<<std::endl;
            A[i].media=mediana(pazymiai,sk-1);
            A[i].vid=vidurkis(pazymiai,sk-1);
            A[i].gal=0.4*A[i].vid+0.6*egz;
            A[i].galm=0.4*A[i].media+0.6*egz;
            
            i++;
            
        }
        
        
        in_file.end;
        in_file.close();
        
        int did_vard=0;
        int did_pav=0;
        for(int i=0; i<nr; i++)
        {
            if(A[i].vard.size()>did_vard) // ieskau ilgiausio vardo
                did_vard=A[i].vard.size();
        }
        for(int i=0; i<nr; i++)
        {
            if(A[i].pav.size()>did_pav) // ieskau ilgiausios pavardes
                did_pav=A[i].pav.size();
        }
        for (int a=0; a<nr-1; a++)
            for (int i=a+1; i<nr; i++)
                if (A[i].vard<A[a].vard)
                {
                    std::swap(A[i],A[a]);
                }
        
        
        std::cout<<std::left<<std::setw(did_vard+1)<<"Vardas ";
        std::cout<<std::left<<std::setw(did_pav+1)<<"Pavarde ";
        std::cout<<"Galutinis (Vid.)";
        std::cout<<(" Galutinis (Med.)\n ");
        char x='x'; // nera vid arba med reiksmes nes jos nenorejo vartotojas
        for (int i=0; i<did_vard+did_pav+36; i++)
            printf("-");
        std::cout<<std::endl;
        for (int i=0; i<=nr-1; i++)
        {
            std::cout<<std::left<<std::setw(did_vard+1)<<A[i].vard;
            std::cout<<std::left<<std::setw(did_pav+1)<<A[i].pav;
            std::cout<<std::left<<std::setw(16)<<std::fixed<<std::setprecision(2)<<A[i].gal;
            std::cout<<std::left<<std::setw(5)<<std::fixed<<std::setprecision(2)<<A[i].galm;
            std::cout<<std::endl;
        }
    }
    else if (kazkas=="3")
    {
        
        
        
        
        //std::ofstream out("10.txt");
        for(int o=10; o<=100000; o*=10)
        {
            std::ofstream out;
            out.open(std::to_string(o)+".txt");
            
            for(int j=1; j<=o; j++)
            {
                std::vector<int>paz;
                std::string s = std::to_string(j);
                out<<"Vardas"+s<<" "<<"Pavarde"+s;
                int skaic=0;
                std::vector<int>::iterator IT;
                
                for(int k=0; k<10;k++)
                {
                    paz.push_back(int());
                    paz[k]=dist(mt); //generuoju skaicius pushinu ir didinu nd kiekk
                    
                }
                for(IT=paz.begin(); IT<paz.end();IT++)
                {
                    out<<" "<<*IT;
                }
                out<<std::endl;
                
            }
            out.close();
        }
        //==================================
        
        std::string temp;
        std::string eil,vard,pav;
        std::ifstream in_file ("10.txt");
        int k=0;
        int nr=0;
        if (in_file.good()){
            while(std::getline(in_file,eil)){  // Nuskaito po visa eilute txt faile
                A.push_back(mok());
                std::istringstream in_line(eil); // Skaitymas is eilutes
                in_line >> vard >> pav;
                
                A[nr].vard=vard;
                A[nr].pav=pav;
                
                nr++;
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
                //std::cout<<egz<<std::endl;
                A[k].media=mediana(pazymiai,sk-1);
                
                A[k].vid=vidurkis(pazymiai,sk-1);
                
                A[k].gal=0.4*A[k].vid+0.6*egz;
                A[k].galm=0.4*A[k].media+0.6*egz;
                in_line.clear();
                in_file.clear();
                // std::cout<<k<<std::endl;
                k++;
                
                
                
            }
            
            
        }
        
        in_file.end;
        in_file.close();
        
        //====================================================================================
        std::ifstream in_files ("100.txt");
        //k=0;
        if (in_files.good()){
            while(std::getline(in_files,eil)){  // Nuskaito po visa eilute txt faile
                
                A.push_back(mok());
                //std::cout<<eil<<std::endl;
                std::istringstream in_line(eil); // Skaitymas is eilutes
                in_line >> vard >> pav;
                A[nr].vard=vard;
                A[nr].pav=pav;
                
                nr++;
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
                //std::cout<<egz<<std::endl;
                //std::cout<<egz<<std::endl;
                A[k].media=mediana(pazymiai,sk-1);
                A[k].vid=vidurkis(pazymiai,sk-1);
                A[k].gal=0.4*A[k].vid+0.6*egz;
                A[k].galm=0.4*A[k].media+0.6*egz;
                in_line.clear();
                in_files.clear();
                
                //std::cout<<k<<std::endl;
                k++;
                
                
                
            }
            
            
        }
        
        in_files.end;
        in_files.close();
        
        //===========================================================================
        std::ifstream in_filea ("1000.txt");
        // k=0;
        if (in_filea.good()){
            while(std::getline(in_filea,eil)){  // Nuskaito po visa eilute txt faile
                
                A.push_back(mok());
                // std::cout<<eil<<std::endl;
                std::istringstream in_line(eil); // Skaitymas is eilutes
                in_line >> vard >> pav;
                // std::cout<<vard<<std::endl;
                A[nr].vard=vard;
                //std::cout<<B[nr].vard<<std::endl;
                A[nr].pav=pav;
                
                nr++;
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
                //std::cout<<B[nr].vard<<std::endl;
                // std::cout<<egz<<std::endl;
                //std::cout<<egz<<std::endl;
                A[k].media=mediana(pazymiai,sk-1);
                A[k].vid=vidurkis(pazymiai,sk-1);
                A[k].gal=0.4*A[k].vid+0.6*egz;
                A[k].galm=0.4*A[k].media+0.6*egz;
                in_line.clear();
                in_filea.clear();
                // std::cout<<k<<std::endl;
                
                k++;
                //std::cout<<A[k].gal<<std::endl;
                
                
            }
            
            
        }
        
        in_filea.end;
        in_filea.close();
        
        //==================================================
        std::ifstream in_fil ("10000.txt");
        //  k=0;
        if (in_fil.good()){
            while(std::getline(in_fil,eil)){  // Nuskaito po visa eilute txt faile
                
                A.push_back(mok());
                // std::cout<<eil<<std::endl;
                std::istringstream in_line(eil); // Skaitymas is eilutes
                in_line >> vard >> pav;
                // std::cout<<vard<<std::endl;
                A[nr].vard=vard;
                //std::cout<<B[nr].vard<<std::endl;
                A[nr].pav=pav;
                
                nr++;
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
                //std::cout<<B[nr].vard<<std::endl;
                // std::cout<<egz<<std::endl;
                //std::cout<<egz<<std::endl;
                A[k].media=mediana(pazymiai,sk-1);
                A[k].vid=vidurkis(pazymiai,sk-1);
                A[k].gal=0.4*A[k].vid+0.6*egz;
                A[k].galm=0.4*A[k].media+0.6*egz;
                in_line.clear();
                in_fil.clear();
                // std::cout<<k<<std::endl;
                
                k++;
                //std::cout<<A[k].gal<<std::endl;
                
                
            }
            
            
        }
        
        in_fil.end;
        in_fil.close();
        
        
        //======================================
        std::ifstream in_filz ("100000.txt");
        // k=0;
        if (in_filz.good()){
            while(std::getline(in_filz,eil)){  // Nuskaito po visa eilute txt faile
                
                A.push_back(mok());
                // std::cout<<eil<<std::endl;
                std::istringstream in_line(eil); // Skaitymas is eilutes
                in_line >> vard >> pav;
                // std::cout<<vard<<std::endl;
                A[nr].vard=vard;
                //std::cout<<B[nr].vard<<std::endl;
                A[nr].pav=pav;
                
                nr++;
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
                //std::cout<<B[nr].vard<<std::endl;
                // std::cout<<egz<<std::endl;
                //std::cout<<egz<<std::endl;
                A[k].media=mediana(pazymiai,sk-1);
                A[k].vid=vidurkis(pazymiai,sk-1);
                A[k].gal=0.4*A[k].vid+0.6*egz;
                A[k].galm=0.4*A[k].media+0.6*egz;
                
                
                
                in_line.clear();
                in_filz.clear();
                // std::cout<<k<<std::endl;
                
                k++;
                //std::cout<<A[k].gal<<std::endl;
                
                
            }
            
            
        }
        
        in_filz.end;
        in_filz.close();
        
        
        int did_vard=0;
        int did_pav=0;
        for(int i=0; i<nr; i++)
        {
            if(A[i].vard.size()>did_vard) // ieskau ilgiausio vardo
                did_vard=A[i].vard.size();
        }
        for(int i=0; i<nr; i++)
        {
            if(A[i].pav.size()>did_pav) // ieskau ilgiausios pavardes
                did_pav=A[i].pav.size();
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
        std::vector<mok>kieti;
        std::vector<mok>lievi;
        auto start = std::chrono::high_resolution_clock::now();
        
        for(k=0; k<nr; k++)
        {
            if(A[k].gal>=5 && A[k].galm>=5)
            {
                kieti.push_back(A[k]);
            }
            else if(A[k].gal<5 && A[k].galm<5)
            {
                lievi.push_back(A[k]);
            }
        }
        
        /*   for (int i=0; i<=nr-1; i++)
         {
         
         }*/
        for(int i=0; i<kieti.size(); i++)
        {
            kiet<<std::left<<std::setw(did_vard+1)<<kieti[i].vard;
            kiet<<std::left<<std::setw(did_pav+1)<<kieti[i].pav;
            kiet<<std::left<<std::setw(16)<<std::fixed<<std::setprecision(2)<<kieti[i].gal;
            kiet<<std::left<<std::setw(5)<<std::fixed<<std::setprecision(2)<<kieti[i].galm;
            kiet<<std::endl;
        }
        for(int i=0; i<lievi.size(); i++)
        {
            nus<<std::left<<std::setw(did_vard+1)<<lievi[i].vard;
            nus<<std::left<<std::setw(did_pav+1)<<lievi[i].pav;
            nus<<std::left<<std::setw(16)<<std::fixed<<std::setprecision(2)<<lievi[i].gal;
            nus<<std::left<<std::setw(5)<<std::fixed<<std::setprecision(2)<<lievi[i].galm;
            nus<<std::endl;
        }
        
        //===================================
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        std::cout << "Failu generavimas ir nuskaitymas, paskirstymas uztruko: "
        << diff.count() << " s\n";
    }
    
    return 0;
}
