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


