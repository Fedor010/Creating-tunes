 /*
CSCI 1300 Fall 2022
Author: Fedor Vlasov
Reatation: 104 - Lilac Intrater
Project 1 - Problem#6
*/
 /*
1.create 3 variables and assign them to simularitu scores of strings tune1, tune2 and tune3
2. compare thoser variables among eash other by macing an if statement for each possible scenario and print out the anwser depending on the outcome.
*/
 
 #include <iostream>
 #include <cassert>
 #include <iomanip>

#include <string>
 #include <iostream>
 using namespace std;

double tuneSimilarity(string tune1, string tune2) {
    int tune1Length = tune1.length();
    int tune2Length = tune2.length();
double total =0;
double sim =0;
double plus =0;
double minus =0;
double notes =0;


     if (tune1Length != tune2Length) { 
return 0;
     }


     

        for (int i = 0; i < tune1Length; i+=2){
if (tune1[i] == tune2[i]) {
sim++;
}
if(tune1[i] == tune2[i] && tune1[i+1] == tune2[i+1]) {
    plus++;
}
if (tune1[i] != tune2[i] && tune1[i+1] != tune2[i+1]){
    minus++;
}

notes++;
}
double simularity =0;
simularity = ((sim/notes) + plus - minus);
return simularity;
     }

//////////////////////////////////////////

 double bestSimilarity(string inputTune, string targetTune){
     if (inputTune.length() < targetTune.length()) { 
return 0;
     }
double simularity_score = -99999;       //so the input will be larger then simularity_score
 for (int i =0; i < 2*((inputTune.length() - targetTune.length())/2+1); i+=2){
if (simularity_score < tuneSimilarity(inputTune.substr(i,targetTune.length()), targetTune)) {
simularity_score = tuneSimilarity(inputTune.substr(i,targetTune.length()), targetTune);
}
 }
 return simularity_score;
 }



 ////////////////////////////////   #6 starsts here \/  \/  \/



 void printTuneRankings(string tune1, string tune2, string tune3, string targetTune) {      //use void because we are not returning anything, just printing

double final1 = bestSimilarity(tune1,targetTune);   //gets simularity score of 1st string and assignes it to a variable
double final2 = bestSimilarity(tune2,targetTune);   //gets simularity score of 2nd string and assignes it to a variable
double final3 = bestSimilarity(tune3,targetTune);   //gets simularity score of 3d string and assignes it to a variable



if (final1 >= final2 && final2 >= final3) {                 //compares simularity scores of those variables and prints out wich one is bigger depending on the outcome
    cout << "1) Tune 1, 2) Tune 2, 3) Tune 3" << endl;
}
else if (final1 >= final3 && final3 > final2) {
    cout << "1) Tune 1, 2) Tune 3, 3) Tune 2" << endl;
}
else if (final2 > final1 && final1 >= final3) {
    cout << "1) Tune 2, 2) Tune 1, 3) Tune 3" << endl;
}
else if (final2 >= final3 && final3 > final1) {
    cout << "1) Tune 2, 2) Tune 3, 3) Tune 1" << endl;
}
else if (final3 > final1 && final1 >= final2) {
    cout << "1) Tune 3, 2) Tune 1, 3) Tune 2" << endl;
}

else if (final3 > final2 && final2 > final1) {
    cout << "1) Tune 3, 2) Tune 2, 3) Tune 1" << endl;
}

 }

     int main(){
    assert(isValidNote("F7D8G1D3, A6B7D9G1E0, D6B1D9G4, D6B4D9") == "1) Tune 3, 2) Tune 2, 3) Tune 1");
       assert(isValidNote("F4E1D5G2, E7B8D0G1E9, A4B1C0G2, F4A1") == "1) Tune 1, 2) Tune 3, 3) Tune 2");
              assert(isValidNote("C4D6G1A8, C4D6G1 ,G9B7A0, C4D8A1") == "1) Tune 1, 2) Tune 2, 3) Tune 3");
                            assert(isValidNote("A0A0, B9D1, G0D1, G0D1") == "1) Tune 3, 2) Tune 2, 3) Tune 1");
                              assert(isValidNote("E0C1B6D2, A0C1B5F2, F1G4E8C3, F9G4") == "1) Tune 3, 2) Tune 1, 3) Tune 2");
                                           assert(isValidNote("A4A5D1E4G8, G4A5D9F4G7, A4G5B9G4G8, B4C5 ") == "1) Tune 1, 2) Tune 2, 3) Tune 3");
       assert(isValidNote("B6G8D9F1E1, F5C2D7C0C2E2, E9G1E7C2E2C2, B6G8D9F1") == "1) Tune 1, 2) Tune 2, 3) Tune 3");
              assert(isValidNote("F0E1, A2D4F4G4, G0E1, C2D4") == "1) Tune 2, 2) Tune 1, 3) Tune 3");
              assert(isValidNote("C5F2D9G0, A5A2D8, C5A2D9G4, E1B7F2") == "1) Tune 1, 2) Tune 2, 3) Tune 3");
                 assert(isValidNote("B5E6D2F8G7, G5E6C2F9, B5E6D3, B5E6") == "1) Tune 1, 2) Tune 3, 3) Tune 2");
                    assert(isValidNote("F4B2E6, A1, B6G2E4, B7G4") == "1) Tune 3, 2) Tune 2, 3) Tune 1");
}

