#ifndef PROCESS_HH
#define PROCESS_HH

#include"srt_scalenie.hh"
#include"quick_srt.hh"
#include"heap_srt.hh"
#include<ctime>
#include<fstream>
#include<iostream>

using namespace std;

template<class T>
void reverse(T **tab, int size_x, int size_y)
{
    T **New=new T *[size_x];
    for (int i=0; i<size_x; i++)
    {
        int k=size_y-1;
        New[i]=new T[size_y];
        for (int j=0; j<size_y; j++)
        {
            New[i][j]=tab[i][k--];   //Wpisanie odwrotnie wartości do tymczasowej tablicy
        }
    }
    // Zamiana
    
    for (int i=0; i<size_x; i++)
    {
        for (int j=0; j<size_y; j++)
        {
            tab[i][j]=New[i][j];   
        }
    }

    for (int i=0; i<size_x; i++)
        delete[] New[i];
    delete[] New;
}

template<class T>
void print_tab(T **tab, int x, int y)
{
    for (int i=0; i<x; i++)
    {
        for (int j=0; j<y; j++)
        {
            if (j>=y-1)
            {
                cout<<tab[i][j]<<endl;
                
            }
            else
                cout<<tab[i][j]<<" ";
        }
    }
}

template<class T>
bool to_file(T **tab, int rozmiar_x, int rozmiar_y, string name)
{
    ofstream file;
    file.open(name);
    if(file.good())
    {
        for (int i=0; i<rozmiar_x; i++)
        {
            int k=i+1;
            file<<"tablica: "<< k <<"\n";
            for (int j=0; j<rozmiar_y; j++)
            {
                file<<tab[i][j]<<" ";
            }
            file<<"\n";
        }    
        file.close();
        return true;
    }
    else
    {
        cout<<"Błąd otwierania pliku"<<endl;
        return false;
    }
}

// Przeciążenie funkcji zapisu do pliku. Zapisywany jest czas sortowania
template<class T>
bool to_file(T **tab, int rozmiar_x, int rozmiar_y, string name, double time)
{
    ofstream file;
    file.open(name);
    if(file.good())
    {
        file<<"Czas sortowania: "<<time<<" s\n";
        for (int i=0; i<rozmiar_x; i++)
        {
            int k=i+1;
            file<<"tablica: "<< k <<"\n";
            for (int j=0; j<rozmiar_y; j++)
            {
                file<<tab[i][j]<<" ";
            }
            file<<"\n";
        }    
        file.close();
        return true;
    }
    else
    {
        cout<<"Błąd otwierania pliku"<<endl;
        return false;
    }
}

template<class T>
bool from_file(T **tab, int rozmiar_x, int rozmiar_y, string name)
{
    char tmp;
    string to_remove;
    ifstream infile;
    infile.open(name);
    if(infile.good())
    {
        for (int i=0; i<rozmiar_x; i++)
        {
            infile>>tmp;
            if(true!=isdigit(tmp))
                getline(infile, to_remove);
            for (int j=0; j<rozmiar_y; j++)
            {   
                infile>>tab[i][j];
            }
        }    
        infile.close();
        return true;
    }
    else
    {
        cout<<"Błąd otwierania pliku"<<endl;
        return false;
    }
}

int ** random_table(int rozmiar_x, int rozmiar_y)
{
    int **table=new int *[rozmiar_x];
    for(int j=0; j<rozmiar_x; j++)
        table[j]=new int [rozmiar_y];

    for (int i=0; i<rozmiar_x; i++)
    {
        for (int j=0; j<rozmiar_y; j++)
        {
            table[i][j]=rand()%(rozmiar_y/10);
        }
    }
    return table;
}

void sort_all(int ROZMIAR_X, int ROZMIAR_Y, float PERCENT, string outfile)
{
    // DEKKLARACJE
    ofstream file;
    file.open(outfile);
    if(!file.good())
        return;
    file<<"scalanie\t"<<"quick\t"<<"heap\n";

    int **table=new int *[ROZMIAR_X];
    for(int j=0; j<ROZMIAR_X; j++)
        table[j]=new int[ROZMIAR_Y];

    

    int **table_to_sort=new int *[ROZMIAR_X];
    for(int j=0; j<ROZMIAR_X; j++)
        table_to_sort[j]=new int[ROZMIAR_Y];

    // SORTOWANIE
    for (int i=0; i<5; i++)
    {
            for (int i=0; i<ROZMIAR_X; i++)
            {
            for (int j=0; j<ROZMIAR_Y; j++)
                {
                table[i][j]=rand()%ROZMIAR_Y/100;
                }
            }

        for (int i=0; i<ROZMIAR_X; i++)
        {
            quick_srt(table[i], 0, ROZMIAR_Y, PERCENT);
        }
        
        ////// SCALANIE
        for (int i=0; i<ROZMIAR_X; i++)
        {
            for (int j=0; j<ROZMIAR_Y; j++)
            {
                table_to_sort[i][j]=table[i][j];
            }
        }

        clock_t Start=clock();
        for (int i=0; i<ROZMIAR_X; i++)
        {
            merge_sort(table_to_sort[i], 0, ROZMIAR_Y, 100);    
        }
        clock_t Stop=clock();
        
        file<<static_cast<double>(Stop-Start)/CLOCKS_PER_SEC<<"\t\t";
        ////// QUICK
        for (int i=0; i<ROZMIAR_X; i++)
        {
            for (int j=0; j<ROZMIAR_Y; j++)
            {
                table_to_sort[i][j]=table[i][j];
            }
        }

        Start=clock();
        for (int i=0; i<ROZMIAR_X; i++)
        {
            quick_srt(table_to_sort[i],0, ROZMIAR_Y,100);    
        }
        Stop=clock();
        
        file<<static_cast<double>(Stop-Start)/CLOCKS_PER_SEC<<"\t";
        ////// HEAP
        for (int i=0; i<ROZMIAR_X; i++)
        {
            for (int j=0; j<ROZMIAR_Y; j++)
            {
                table_to_sort[i][j]=table[i][j];
            }
        }

        Start=clock();
        for (int i=0; i<ROZMIAR_X; i++)
        {
            heap_srt(table_to_sort[i],ROZMIAR_Y,100);
        }
        Stop=clock();
        
        file<<static_cast<double>(Stop-Start)/CLOCKS_PER_SEC<<"\n";
        //////KONIEC
    }
        file.close();
        for(int j=0; j<ROZMIAR_X; j++)
        {
            delete[] table[j];
            delete[] table_to_sort[j];
        }
        delete[] table;
        delete[] table_to_sort;

}

void rev_sort_all(int ROZMIAR_X, int ROZMIAR_Y, float PERCENT, string outfile)
{
    // DEKKLARACJE
    ofstream file;
    file.open(outfile);
    if(!file.good())
        return;
    file<<"scalanie\t"<<"quick\t"<<"heap\n";

    int **table=new int *[ROZMIAR_X];
    for(int j=0; j<ROZMIAR_X; j++)
        table[j]=new int[ROZMIAR_Y];

    for (int i=0; i<ROZMIAR_X; i++)
    {
        for (int j=0; j<ROZMIAR_Y; j++)
        {
            table[i][j]=rand()%ROZMIAR_Y/100;
        }
    }
    for (int i=0; i<ROZMIAR_X; i++)
    {
        quick_srt(table[i], 0, ROZMIAR_Y, PERCENT);
    }
    reverse(table, 0, ROZMIAR_Y);

    int **table_to_sort=new int *[ROZMIAR_X];
    for(int j=0; j<ROZMIAR_X; j++)
        table_to_sort[j]=new int[ROZMIAR_Y];

    // SORTOWANIE
    for (int i=0; i<5; i++)
    {
            for (int i=0; i<ROZMIAR_X; i++)
            {
                for (int j=0; j<ROZMIAR_Y; j++)
                {
                    table[i][j]=rand()%ROZMIAR_Y/100;
                }
            }

        for (int i=0; i<ROZMIAR_X; i++)
        {
            quick_srt(table[i], 0, ROZMIAR_Y, PERCENT);
        }
        
        ////// SCALANIE
        for (int i=0; i<ROZMIAR_X; i++)
        {
            for (int j=0; j<ROZMIAR_Y; j++)
            {
                table_to_sort[i][j]=table[i][j];
            }
        }

        clock_t Start=clock();
        for (int i=0; i<ROZMIAR_X; i++)
        {
            merge_sort(table_to_sort[i], 0, ROZMIAR_Y, 100);    
        }
        clock_t Stop=clock();
        
        file<<static_cast<double>(Stop-Start)/CLOCKS_PER_SEC<<"\t";
        ////// QUICK
        for (int i=0; i<ROZMIAR_X; i++)
        {
            for (int j=0; j<ROZMIAR_Y; j++)
            {
                table_to_sort[i][j]=table[i][j];
            }
        }

        Start=clock();
        for (int i=0; i<ROZMIAR_X; i++)
        {
            quick_srt(table_to_sort[i],0, ROZMIAR_Y,100);
        }
        Stop=clock();
        
        file<<static_cast<double>(Stop-Start)/CLOCKS_PER_SEC<<"\t";
        ////// HEAP
        for (int i=0; i<ROZMIAR_X; i++)
        {
            for (int j=0; j<ROZMIAR_Y; j++)
            {
                table_to_sort[i][j]=table[i][j];
            }
        }

        Start=clock();
        for (int i=0; i<ROZMIAR_X; i++)
        {
            heap_srt(table_to_sort[i],ROZMIAR_Y,100);        
        }
        Stop=clock();
        
        file<<static_cast<double>(Stop-Start)/CLOCKS_PER_SEC<<"\n";
        
    }
    //////KONIEC
    file.close();
    for(int j=0; j<ROZMIAR_X; j++)
    {
        delete[] table[j];
        delete[] table_to_sort[j];
    }
    delete[] table;
    delete[] table_to_sort;
    
}

#endif