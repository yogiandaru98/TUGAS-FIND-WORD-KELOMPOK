//ANGGOTA : 1. Yogi Andaru (2017051062)
        //  2. Fitriah Hardianti (2057051001)
       //   3. Muhammad Fakhri (2017051076)
// kelas : B
//github: https://github.com/yogiandaru98/TUGAS-FIND-WORD-KELOMPOK/tree/main
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
const int cols = 16, rows = 15;

 char words[rows][cols] = {
 				"tgbwwinterwsesn",
                                "aaunttmmhfoodnb",
                                "jlwcqldzmpmvdmr",
                                "asagmquwvvbsohi",
                                "bwplotanadtpgnc",
                                "rewngodjcpnatnk",
                                "eeotwosbqharrsa",
                                "azcgeswewnaknpb",
                                "dinnerqodlwdcar",
                                "onopkwmparktzcc",
                                "qbfrogmamwpweey",
                                "lqzqnnmrzjjsclg",
                                "mosgzczetdbooto",
                                "pdcrzmsngrdnrpz",
                                "ohnkzwaterjgtra"};
char *getWordVertical(int);
char *reverse(char *);
bool searchVertical(char *);
bool searchHorizontal(char *);

char *getWordVertical(int idx){
	char *CheckVertical = (char*)malloc(16 * sizeof(char));
	for(int i=0; i<rows; i++)
		CheckVertical[i] = words[i][idx];
	return CheckVertical;}
//fungsi reversal
char *reverse(char *charstring){
	char *check1, *check2;
      if (! charstring || ! *charstring)
            return charstring;
      for (check1 = charstring, check2 = charstring + strlen(charstring) - 1; check2 > check1; ++check1, --check2)
      {
        *check1 ^= *check2;
        *check2 ^= *check1;
        *check1 ^= *check2;}
      return charstring;}
//fungsi pencari kata vertikal
bool searchVertical(char *carikan){
	for(int i=0; i<=15; i++)
		if(strstr(getWordVertical(i), carikan) != NULL)
			return true;
	for(int i=0; i<=15; i++)
		if(strstr(reverse(getWordVertical(i)), carikan) != NULL)
			return true;
	return false;}
//fungsi pencari kata horizontal
bool searchHorizontal(char *carikan){
	for(int i=0; i<=15; i++)
		if(strstr(words[i], carikan) != NULL)
			return true;
	for(int i=0; i<=15; i++){
		if(strstr(reverse(words[i]), carikan) != NULL)
			return true;}
	return false;}
//fungsi utama program
int main(){
    char word[16];
    int n;
    cin>>n;
    cin.ignore();
	for (int i=0;i<n;i++){
        cin.getline(word,16,'\n');
        if (searchVertical(word) || searchHorizontal(word))
            cout << "Ada\n";
        else 
            cout << "Tidak Ada\n";
    }
    
    return 0;
}
