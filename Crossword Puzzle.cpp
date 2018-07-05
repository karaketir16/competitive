#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf	1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 100005
#define LN 20
#define MOD 1000000007
#define orta ((a+b)/2)
using namespace std;
typedef long long int lint;
typedef pair<int,int> ii;

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}
struct Bosluk
{
    int bas;
    int son;
    int uzunluk;
    int satir_mi;
    int no;
};
void print_area(vector<string> area)
{
    for(auto s:area)
    {
        cout<<s<<"\n";
    }
}
void yerlestir(vector<string> area, vector<string> words, vector<Bosluk> bosluklar )
{
    //print_area(area);
    //cout<<endl;
    //cout<<bosluklar.size()<<endl;
    for(int b=0;b<bosluklar.size();b++)
    {
        //cout<<b<<endl;
        Bosluk bosluk=bosluklar[b];
        for(int w=0;w<words.size();w++)
        {
            string word=words[w];
            //cout<<"denenen bosluk uzunlugu: "<<bosluk.uzunluk<<" denenen word uzunlugu: "<<word.size
            if(bosluk.uzunluk!=word.size()) continue;
            //cout<<"Uygun boyutta bosluk:"<<b<<endl;
            if(bosluk.satir_mi)
            {
                
                int satir=bosluk.no;
                bool uydu_mu=1;
                for(int i=0;i<word.size();i++)
                {
                    if(area[satir][bosluk.bas+i]!='-')
                    {
                        if(area[satir][bosluk.bas+i]!=word[i])
                        {
                            uydu_mu=0;
                            break;

                        }
                    }
                }
                if(uydu_mu)
                {
                    vector<string> kalan_kelimeler = words;
                    //kalan_kelimeler.erase(find(kalan_kelimeler.begin(),kalan_kelimeler.end(),word));
                    kalan_kelimeler.erase(kalan_kelimeler.begin()+w);
                    vector<string> kalan_area= area;
                    for(int i=0;i<bosluk.uzunluk;i++)
                    {
                        kalan_area[satir][bosluk.bas+i]=word[i];
                    }
                    if(kalan_kelimeler.size()==0)
                    {
                        print_area(kalan_area);
                        exit(0);
                    }
                    vector<Bosluk> kalan_bosluklar = bosluklar;
                    kalan_bosluklar.erase(kalan_bosluklar.begin()+b);
                    yerlestir(kalan_area,kalan_kelimeler,kalan_bosluklar);

                }

            }
            
            else
            {
                int sutun=bosluk.no;
                bool uydu_mu=1;
                for(int i=0;i<word.size();i++)
                {
                    if(area[bosluk.bas+i][sutun]!='-')
                    {
                        if(area[bosluk.bas+i][sutun]!=word[i])
                        {
                            uydu_mu=0;
                            break;

                        }
                    }
                }
                if(uydu_mu)
                {
                    vector<string> kalan_kelimeler = words;
                    //kalan_kelimeler.erase(find(kalan_kelimeler.begin(),kalan_kelimeler.end(),word));
                    kalan_kelimeler.erase(kalan_kelimeler.begin()+w);
                    vector<string> kalan_area= area;
                    for(int i=0;i<bosluk.uzunluk;i++)
                    {
                        kalan_area[bosluk.bas+i][sutun]=word[i];
                    }
                    if(kalan_kelimeler.size()==0)
                    {
                        print_area(kalan_area);
                        exit(0);
                    }
                    vector<Bosluk> kalan_bosluklar = bosluklar;
                    kalan_bosluklar.erase(kalan_bosluklar.begin()+b);
                    yerlestir(kalan_area,kalan_kelimeler,kalan_bosluklar);

                }
            }
            
        }
        
    }

}
vector<string> crosswordPuzzle(vector<string> crossword, string words) {
    vector<string> all_words= split(words,';') ;

    /*
    for(auto w:all_words)
    {
        cout<<w.size()<<endl;
    }
    */
    
    
    vector<Bosluk> bosluklar;
    for(int sat=0;sat<10;sat++)//satir
    {
        string s=crossword[sat];
        for(int i=0;i<10;i++)
        {
            if(s[i]=='-')
            {
                int bas=i;
                for(;i<10&&s[i]=='-';i++)
                {

                }
                int son=i-1;
                Bosluk b;
                b.bas=bas;
                b.son=son;
                b.uzunluk=son-bas+1;
                b.satir_mi=1;
                b.no=sat;
                bosluklar.pb(b);


            }
        }   
    }
    vector<string> trans(10,"          ");
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            trans[i][j]=crossword[j][i];
        }
    }


    for(int sut=0;sut<10;sut++)//sutun
    {
        string s=trans[sut];
        for(int i=0;i<10;i++)
        {
            if(s[i]=='-')
            {
                int bas=i;
                for(;i<10&&s[i]=='-';i++)
                {

                }
                int son=i-1;
                Bosluk b;
                b.bas=bas;
                b.son=son;
                b.uzunluk=son-bas+1;
                b.satir_mi=0;
                b.no=sut;
                bosluklar.pb(b);


            }
        }   
    }
    /*
    for(auto a: bosluklar)
    {
        cout<<a.bas<<" "<<a.son<<" "<<a.uzunluk<<endl;
    }
    */
    

    yerlestir(crossword,all_words,bosluklar);
    vector<string> a;
    return a;
}

int main()
{
   // ofstream fout(getenv("OUTPUT_PATH"));

    vector<string> crossword(10);

    for (int i = 0; i < 10; i++) {
        string crossword_item;
        getline(cin, crossword_item);

        crossword[i] = crossword_item;
    }

    string words;
    getline(cin, words);

    vector<string> result = crosswordPuzzle(crossword, words);
    /*
    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }
    */

    //fout << "\n";

    //fout.close();

    return 0;
}