#define pragma once
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
#include <stdlib.h>
#include <chrono>
#include <random>

struct mok
{
    
    
    double vid=0; // vidurkiai
    double gal; // galutinis
    double media=0;
    double galm;
    std::string vard;
    std::string pav;
    
    int sum=0;
};
struct moky
{
    std::string vard;
    std::string pav;
    int test;
};
double mediana (std::vector<int> temp_paz, int n);
double vidurkis (std::vector<int> temp_paz,int n);
bool skaicius(const std::string &str);
bool gavoSkolos( const mok & i );
bool negavoSkolos( const mok & i );
