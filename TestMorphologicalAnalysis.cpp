//
// Created by Olcay Taner Yıldız on 2.03.2019.
//

#include <iostream>
#include <fstream>
#include "FsmMorphologicalAnalyzer.h"

void testWord(FsmMorphologicalAnalyzer fsm, string word){
    FsmParseList fsmParses = fsm.morphologicalAnalysis(move(word));
    for (int i = 0; i < fsmParses.size(); i++){
        cout << fsmParses.getFsmParse(i).getTransitionList() << "\n";
    }
}

void checkSpeed(){
    int k = 0;
    FsmMorphologicalAnalyzer fsm = FsmMorphologicalAnalyzer("turkish_finite_state_machine.xml", TxtDictionary(), 1000000);
    string line;
    ifstream inputFile;
    inputFile.open("gazete.txt", ifstream :: in);
    while (inputFile.good()) {
        getline(inputFile, line);
        Sentence sentence = Sentence(line);
        for (int j = 0; j < sentence.wordCount(); j++){
            fsm.morphologicalAnalysis(sentence.getWord(j)->getName());
            k++;
            if (k % 1000 == 0){
                cout << k << "\n";
            }
        }
    }
    inputFile.close();
}

void analyze(){
    FsmMorphologicalAnalyzer fsm = FsmMorphologicalAnalyzer();
    string word = "Kerem topu Aysu'ya at";
    while (Word::size(word) > 1){
        cout << "->";
        cin >> word;
        testWord(fsm, word);
    }
}

int main(){
    //analyze();
    checkSpeed();
}