#include"process_all.hh"

#define ROZMIAR_X 100
#define ROZMIAR_Y_1 10000
#define ROZMIAR_Y_2 50000
#define ROZMIAR_Y_3 100000
#define ROZMIAR_Y_4 500000
#define ROZMIAR_Y_5 1000000

int main()
{
    // for (int i=0; i<5; i++)
    // {
        cout<<"here"<<endl;
        sort_all(ROZMIAR_X,ROZMIAR_Y_1,0,"nieposortowane/10k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_2,0,"nieposortowane/50k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_3,0,"nieposortowane/100k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_4,0,"nieposortowane/500k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_5,0,"nieposortowane/1Mk.txt");
        cout<<"here2"<<endl;
    // }

    // for (int i=0; i<5; i++)
    // {
        sort_all(ROZMIAR_X,ROZMIAR_Y_1,25,"25/10k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_2,25,"25/50k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_3,25,"25/100k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_4,25,"25/500k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_5,25,"25/1Mk.txt");
    // }

    // for (int i=0; i<5; i++)
    // {
        sort_all(ROZMIAR_X,ROZMIAR_Y_1,50,"50/10k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_2,50,"50/50k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_3,50,"50/100k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_4,50,"50/500k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_5,50,"50/1Mk.txt");
    // }
    
    // for (int i=0; i<5; i++)
    // {
        sort_all(ROZMIAR_X,ROZMIAR_Y_1,75,"75/10k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_2,75,"75/50k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_3,75,"75/100k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_4,75,"75/500k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_5,75,"75/1Mk.txt");
    // }

    // for (int i=0; i<5; i++)
    // {
        sort_all(ROZMIAR_X,ROZMIAR_Y_1,95,"95/10k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_2,95,"95/50k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_3,95,"95/100k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_4,95,"95/500k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_5,95,"95/1Mk.txt");
    // }

    // for (int i=0; i<5; i++)
    // {
        sort_all(ROZMIAR_X,ROZMIAR_Y_1,99,"99/10k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_2,99,"99/50k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_3,99,"99/100k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_4,99,"99/500k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_5,99,"99/1Mk.txt");
    // }

    // for (int i=0; i<5; i++)
    // {
        sort_all(ROZMIAR_X,ROZMIAR_Y_1,99.7,"99_7/10k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_2,99.7,"99_7/50k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_3,99.7,"99_7/100k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_4,99.7,"99_7/500k.txt");
        sort_all(ROZMIAR_X,ROZMIAR_Y_5,99.7,"99_7/1Mk.txt");
    // }

    // for (int i=0; i<5; i++)
    // {
        rev_sort_all(ROZMIAR_X,ROZMIAR_Y_1,100,"reversed/10k.txt");
        rev_sort_all(ROZMIAR_X,ROZMIAR_Y_2,100,"reversed/50k.txt");
        rev_sort_all(ROZMIAR_X,ROZMIAR_Y_3,100,"reversed/100k.txt");
        rev_sort_all(ROZMIAR_X,ROZMIAR_Y_4,100,"reversed/500k.txt");
        rev_sort_all(ROZMIAR_X,ROZMIAR_Y_5,100,"reversed/1Mk.txt");
    // }
}
