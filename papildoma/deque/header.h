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
#include <deque>

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
void pazymys (std::vector<int>&laikinas,int &sk);
void generuoju (std::vector<int>&laikinas,int k, int &sk);
void generuoju (std::vector<int>&laikinas,int l);
void arzodis (std::vector<mok>&temp, int i);
void arzodiss (std::vector<mok>&temp, int i);
int ger_egz (int temp);
double galutinis_vid (int temp, std::vector<int>temp_paz, int t);
double galutinis_med (int temp, std::vector<int>temp_paz, int t);
int ilg_vard(int n, std::vector<mok>temp);
int ilg_pav(int n, std::vector<mok>temp);
void sorting (int n, std::vector<mok>&temp);
void spausdinimas (int n, std::vector<char>t, std::vector<mok>temp, int vardas, int pavarde);
void spausdinimas2 (int n, std::vector<mok>temp);
void fail_generav();
void skaitymas2(std::deque<mok>&tem, std::string pava, int &l, int &n);
void atranka (std::vector<mok>&temp_lievi, std::vector<mok>&temp);
void spausdinimas2 (std::deque<mok>temp, std::deque<mok>temp_lievi);
void skaitymas3(std::vector<mok>&tem, int &n, int &l);
std::deque<mok> raskMinkstus(std::deque<mok>& studentai);

