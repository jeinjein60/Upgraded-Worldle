#include <iostream>
// #include "wordle.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <random>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime> 
#include <cmath>

#define RESET "\033[0m"
#define GREEN_BOLD "\033[1;32m"
#define YELLOW_BOLD "\033[1;33m"
#define GRAY_BOLD "\033[1;90m"

using namespace std;

//git log --oneline
// git add .
// git commit -m ""

int wordleAttempts = 0;
int playCounter, streakCounter, attemptsCounter, gamesWon, hi, highestStreak, attemptsCounter2;
double winPercentage;
string random_word4, random_word5, random_word6, random_word7, random_word8;
string guess;
string r1, r2, r3, r4, r5, r6, r7, r8;
string g1, g2, g3, g4, g5, g6, g7, g8;

void Percentage(int hi){
    winPercentage = (gamesWon / playCounter) * 100.0;
    hi = round(winPercentage);
    ofstream hiFile;
    hiFile.open("win_percentage.txt", ios::out);
    if (hiFile.is_open()) {
        hiFile << hi << endl;
        }
    hiFile.close();
}

void success4(string random_word4){
    if (highestStreak > streakCounter){
        goto Continue;
    }
    else {
        highestStreak ++;  
        goto Continue;
    }
    Continue:
    streakCounter ++;
    gamesWon ++;
    ofstream streakFile;
    streakFile.open("c_streak.txt", ios::out);
    if (streakFile.is_open()) {
        streakFile << streakCounter << endl;
    }
    streakFile.close();
    ofstream sFile;
    sFile.open("const_streak.txt", ios::out);
    if (sFile.is_open()) {
        sFile << highestStreak << endl;
    }
    sFile.close();
    ofstream wonFile;
    wonFile.open("games_won.txt", ios::out);
    if (wonFile.is_open()) {
        wonFile << gamesWon << endl;
    }
    wonFile.close();
    Percentage(hi);
    ofstream hi2File;
    hi2File.open("win_percentage.txt", ios::out);
    if (hi2File.is_open()) {
        hi2File << hi << endl;
        }
    hi2File.close();

    ofstream statsWin;
    statsWin.open("yes_no.txt", ios::out);
    if (statsWin.is_open()) {
        statsWin << "yes" << endl;
        }
    statsWin.close();

    r1 = toupper(random_word4[0]);
    r2 = toupper(random_word4[1]);
    r3 = toupper(random_word4[2]);
    r4 = toupper(random_word4[3]); 
    cout << GREEN_BOLD << " ---  ---  ---  --- " << endl;
    cout << "| " << r1 <<  " || " << r2 << " || " << r3 << " || " << r4 << " |" << endl;
    cout << " ---  ---  ---  ---\n" << RESET << endl; 
}

void wordleFunction4(string guess){
    const int guessLength4 = 4;
    vector<string> notWords4;
    ifstream allowed_file4("4-allowed.txt");
    string line_allowed4;
    while (getline(allowed_file4, line_allowed4)) notWords4.push_back(line_allowed4);
    allowed_file4.close();
    vector<string> realWords4;
    ifstream real_file4("4-words.txt");
    string line_real4;
    while (getline(real_file4, line_real4)) realWords4.push_back(line_real4);
    real_file4.close();
    ofstream resetatFile;
    resetatFile.open("attempts2.txt", ios::out);
    if (resetatFile.is_open()) {
        resetatFile << 0 << endl;
        attemptsCounter2 = 0;
    }
    resetatFile.close();
    Sucks:
    cin >> guess;
    if (guess.length() == 4) {
        if (find(notWords4.begin(), notWords4.end(), guess) != notWords4.end() || find(realWords4.begin(), realWords4.end(), guess) != realWords4.end()) {
            goto Happy;
            }
        else {
            cout << "Invalid Word Choice, please try again 😞" << endl;
            goto Sucks;
            }
        }
    else {
        cout << "Invalid Word Choice, please try again 😞" << endl;
        goto Sucks;
        }

    Happy:
        g1 = toupper(guess[0]);
        g2 = toupper(guess[1]);
        g3 = toupper(guess[2]);
        g4 = toupper(guess[3]);
        r1 = toupper(random_word4[0]);
        r2 = toupper(random_word4[1]);
        r3 = toupper(random_word4[2]);
        r4 = toupper(random_word4[3]);
        string g1_colorcode;
        string g2_colorcode;            
        string g3_colorcode;
        string g4_colorcode;
        while (wordleAttempts < 5){ 
            wordleAttempts ++;
            attemptsCounter ++;
            attemptsCounter2 ++;
            ofstream attemptsFile;
            attemptsFile.open("c_attempts.txt", ios::out);
            if (attemptsFile.is_open()) {
                attemptsFile << attemptsCounter << endl;
                }
            attemptsFile.close();
            
            ofstream attempts2File;
            attempts2File.open("attempts2.txt", ios::out);
            if (attempts2File.is_open()) {
                attempts2File << attemptsCounter2 << endl;
                }
            attempts2File.close();
            if (guess == random_word4){
                success4(random_word4);
                cout << "Whoppi! You Win!" << endl;
                exit(0);
            }
            if (g1 == r2 || g1 == r3 || g1 == r4){
                g1_colorcode = YELLOW_BOLD;
                g1 = g1_colorcode + g1 + RESET;             
            }
            else if (g1 == r1){
                g1_colorcode = GREEN_BOLD;
                g1 = g1_colorcode + g1 + RESET;
            }
            else if (g1 != r1 || g1 != r2 || g1 != r3 || g1 != r4){
                g1_colorcode = GRAY_BOLD;
                g1 = g1_colorcode + g1 + RESET;
            }
            if (g2 == r1 || g2 == r3 || g2 == r4){
                g2_colorcode = YELLOW_BOLD;
                g2 = g2_colorcode + g2 + RESET; 
            }
            else if (g2 == r2){
                g2_colorcode = GREEN_BOLD;
                g2 = g2_colorcode + g2 + RESET;
            }
            else if (g2 != r1 || g2 != r2 || g2 != r3 || g2 != r4){
                g2_colorcode = GRAY_BOLD;
                g2 = g2_colorcode + g2 + RESET;
            }
            if (g3 == r1 || g3 == r2 || g3 == r4){
                g3_colorcode = YELLOW_BOLD;
                g3 = g3_colorcode + g3 + RESET; 
            }
            else if (g3 == r3){
                g3_colorcode = GREEN_BOLD;
                g3 = g3_colorcode + g3 + RESET;
            }
            else if (g3 != r1 || g3 != r2 || g3 != r3 || g3 != r4){
                g3_colorcode = GRAY_BOLD;
                g3 = g3_colorcode + g3 + RESET;
            }
            if (g4 == r1 || g4 == r2 || g4 == r3){
                g4_colorcode = YELLOW_BOLD;
                g4 = g4_colorcode + g4 + RESET; 
            }
            else if (g4 == r4){
                g4_colorcode = GREEN_BOLD;
                g4 = g4_colorcode + g4 + RESET;
            } 
            else if (g4 != r1 || g4 != r2 || g4 != r3 || g4 != r4){
                g4_colorcode = GRAY_BOLD;
                g4 = g4_colorcode + g4 + RESET;
            }           
            cout << " ---  ---  ---  --- " << endl;
            cout << "| " << g1 <<  " || " << g2 << " || " << g3 << " || " << g4 << " |" << endl;
            cout << " ---  ---  ---  ---\n" << endl; 
            
            cin >> guess;
            if (guess.length() == 4) {
                if (find(notWords4.begin(), notWords4.end(), guess) != notWords4.end() || find(realWords4.begin(), realWords4.end(), guess) != realWords4.end()) {
                    goto Happy;
                }
                else {
                    cout << "Invalid Word Choice, please try again 😞" << endl; 
                    wordleAttempts --;
                    goto Happy;
                }
            }
            else {
                cout << "Invalid Word Choice, please try again 😞" << endl;
                wordleAttempts --;
                goto Happy;
            }
        }
        if (guess == random_word4){
            success4(random_word4);
            cout << "Whoppi!" << endl;
            exit(0);
        }
        if (g1 == r2 || g1 == r3 || g1 == r4){
            g1_colorcode = YELLOW_BOLD;
            g1 = g1_colorcode + g1 + RESET;             
        }
        else if (g1 == r1){
            g1_colorcode = GREEN_BOLD;
            g1 = g1_colorcode + g1 + RESET;
        }
        else if (g1 != r1 || g1 != r2 || g1 != r3 || g1 != r4){
            g1_colorcode = GRAY_BOLD;
            g1 = g1_colorcode + g1 + RESET;
        }
        if (g2 == r1 || g2 == r3 || g2 == r4){
            g2_colorcode = YELLOW_BOLD;
            g2 = g2_colorcode + g2 + RESET; 
        }
        else if (g2 == r2){
            g2_colorcode = GREEN_BOLD;
            g2 = g2_colorcode + g2 + RESET;
        }
        else if (g2 != r1 || g2 != r2 || g2 != r3 || g2 != r4){
            g2_colorcode = GRAY_BOLD;
            g2 = g2_colorcode + g2 + RESET;
        }
        if (g3 == r1 || g3 == r2 || g3 == r4){
            g3_colorcode = YELLOW_BOLD;
            g3 = g3_colorcode + g3 + RESET; 
        }
        else if (g3 == r3){
            g3_colorcode = GREEN_BOLD;
            g3 = g3_colorcode + g3 + RESET;
        }
        else if (g3 != r1 || g3 != r2 || g3 != r3 || g3 != r4){
            g3_colorcode = GRAY_BOLD;
            g3 = g3_colorcode + g3 + RESET;
        }
        if (g4 == r1 || g4 == r2 || g4 == r3){
            g4_colorcode = YELLOW_BOLD;
            g4 = g4_colorcode + g4 + RESET; 
        }
        else if (g4 == r4){
            g4_colorcode = GREEN_BOLD;
            g4 = g4_colorcode + g4 + RESET;
        } 
        else if (g4 != r1 || g4 != r2 || g4 != r3 || g4 != r4){
            g4_colorcode = GRAY_BOLD;
            g4 = g4_colorcode + g4 + RESET;
        }           
        cout << " ---  ---  ---  --- " << endl;
        cout << "| " << g1 <<  " || " << g2 << " || " << g3 << " || " << g4 << " |" << endl;
        cout << " ---  ---  ---  ---\n" << endl;
        cout << "Uh oh, you lost." << endl;
        cout << "The word was: " << random_word4 << endl;
        ofstream statsLoses;
        statsLoses.open("yes_no.txt", ios::out);
        if (statsLoses.is_open()) {
            statsLoses << "no" << endl;
        }
        statsLoses.close();

        ofstream endstreakFile;
        endstreakFile.open("c_streak.txt", ios::out);
        if (endstreakFile.is_open()) {
            endstreakFile << 0 << endl;
            streakCounter = 0;
        }
        endstreakFile.close();
        exit(0);       
}

void success5(string random_word5){
    if (highestStreak > streakCounter){
        goto Continue2;
    }
    else {
        highestStreak ++;  
        goto Continue2;
    }
    Continue2:
    streakCounter ++;
    gamesWon ++;
    ofstream streakFile;
    streakFile.open("c_streak.txt", ios::out);
    if (streakFile.is_open()) {
        streakFile << streakCounter << endl;
    }
    streakFile.close();
    ofstream sFile2;
    sFile2.open("const_streak.txt", ios::out);
    if (sFile2.is_open()) {
        sFile2 << highestStreak << endl;
    }
    sFile2.close();
    ofstream wonFile;
    wonFile.open("games_won.txt", ios::out);
    if (wonFile.is_open()) {
        wonFile << gamesWon << endl;
    }
    wonFile.close();
    Percentage(hi);
    ofstream hi3File;
    hi3File.open("win_percentage.txt", ios::out);
    if (hi3File.is_open()) {
        hi3File << hi << endl;
        }
    hi3File.close();
    ofstream statsWin2;
    statsWin2.open("yes_no.txt", ios::out);
    if (statsWin2.is_open()) {
        statsWin2 << "yes" << endl;
        }
    statsWin2.close();
    r1 = toupper(random_word5[0]);
    r2 = toupper(random_word5[1]);
    r3 = toupper(random_word5[2]);
    r4 = toupper(random_word5[3]); 
    r5 = toupper(random_word5[4]);
    cout << GREEN_BOLD << " ---  ---  ---  ---  ---" << endl;
    cout << "| " << r1 <<  " || " << r2 << " || " << r3 << " || " << r4 << " || " << r5 << " |" << endl;
    cout << " ---  ---  ---  ---  ---\n" << RESET << endl; 
}

void wordleFunction5(string guess){
    const int guessLength5 = 5;
    vector<string> notWords5;
    ifstream allowed_file5("5-allowed.txt");
    string line_allowed5;
    while (getline(allowed_file5, line_allowed5)) notWords5.push_back(line_allowed5);
    allowed_file5.close();
    vector<string> realWords5;
    ifstream real_file5("5-words.txt");
    string line_real5;
    while (getline(real_file5, line_real5)) realWords5.push_back(line_real5);
    real_file5.close();
    ofstream resetatFile2;
    resetatFile2.open("attempts2.txt", ios::out);
    if (resetatFile2.is_open()) {
        resetatFile2 << 0 << endl;
        attemptsCounter2 = 0;
    }
    resetatFile2.close();
    Sucks2:
    cin >> guess;
    if (guess.length() == 5) {
        if (find(notWords5.begin(), notWords5.end(), guess) != notWords5.end() || find(realWords5.begin(), realWords5.end(), guess) != realWords5.end()) {
            goto Happy2;
            }
        else {
            cout << "Invalid Word Choice, please try again 😞" << endl;
            goto Sucks2;
            }
        }
    else {
        cout << "Invalid Word Choice, please try again 😞" << endl;
        goto Sucks2;
        }
    Happy2:
        g1 = toupper(guess[0]);
        g2 = toupper(guess[1]);
        g3 = toupper(guess[2]);
        g4 = toupper(guess[3]);
        g5 = toupper(guess[4]);
        r1 = toupper(random_word5[0]);
        r2 = toupper(random_word5[1]);
        r3 = toupper(random_word5[2]);
        r4 = toupper(random_word5[3]);
        r5 = toupper(random_word5[4]);
        string g1_colorcode2;
        string g2_colorcode2;            
        string g3_colorcode2;
        string g4_colorcode2;
        string g5_colorcode2;
        while (wordleAttempts < 5){ 
            wordleAttempts ++;
            attemptsCounter ++;
            attemptsCounter2 ++;
            ofstream attemptsFile;
            attemptsFile.open("c_attempts.txt", ios::out);
            if (attemptsFile.is_open()) {
                attemptsFile << attemptsCounter << endl;
                }
            attemptsFile.close();
            ofstream attempts2File2;
            attempts2File2.open("attempts2.txt", ios::out);
            if (attempts2File2.is_open()) {
                attempts2File2 << attemptsCounter2 << endl;
                }
            attempts2File2.close();
            if (guess == random_word5){
                success5(random_word5);
                cout << "Whoppi!" << endl;
                exit(0);
            }
            if (g1 == r2 || g1 == r3 || g1 == r4 || g1 == r5){
                g1_colorcode2 = YELLOW_BOLD;
                g1 = g1_colorcode2 + g1 + RESET; 
            }
            else if (g1 == r1){
                g1_colorcode2 = GREEN_BOLD;
                g1 = g1_colorcode2 + g1 + RESET;
            }
            else if (g1 != r1 || g1 != r2 || g1 != r3 || g1 != r4 || g1 != r5){
                g1_colorcode2 = GRAY_BOLD;
                g1 = g1_colorcode2 + g1 + RESET;
            }
            if (g2 == r1 || g2 == r3 || g2 == r4 || g2 == r5){
                g2_colorcode2 = YELLOW_BOLD;
                g2 = g2_colorcode2 + g2 + RESET; 
            }
            else if (g2 == r2){
                g2_colorcode2 = GREEN_BOLD;
                g2 = g2_colorcode2 + g2 + RESET;
            }
            else if (g2 != r1 || g2 != r2 || g2 != r3 || g2 != r4 || g2 != r5){
                g2_colorcode2 = GRAY_BOLD;
                g2 = g2_colorcode2 + g2 + RESET;
            }
            if (g3 == r1 || g3 == r2 || g3 == r4 || g3 == r5){
                g3_colorcode2 = YELLOW_BOLD;
                g3 = g3_colorcode2 + g3 + RESET; 
            }
            else if (g3 == r3){
                g3_colorcode2 = GREEN_BOLD;
                g3 = g3_colorcode2 + g3 + RESET;
            }
            else if (g3 != r1 || g3 != r2 || g3 != r3 || g3 != r4 || g3 != r5){
                g3_colorcode2 = GRAY_BOLD;
                g3 = g3_colorcode2 + g3 + RESET;
            }
            if (g4 == r1 || g4 == r2 || g4 == r3 || g4 == r5){
                g4_colorcode2 = YELLOW_BOLD;
                g4 = g4_colorcode2 + g4 + RESET; 
            }
            else if (g4 == r4){
                g4_colorcode2 = GREEN_BOLD;
                g4 = g4_colorcode2 + g4 + RESET;
            } 
            else if (g4 != r1 || g4 != r2 || g4 != r3 || g4 != r4 || g4 != r5){
                g4_colorcode2 = GRAY_BOLD;
                g4 = g4_colorcode2 + g4 + RESET;
            }
            if (g5 == r1 || g5 == r2 || g5 == r3 || g5 == r4){
                g5_colorcode2 = YELLOW_BOLD;
                g5 = g5_colorcode2 + g5 + RESET; 
            }
            else if (g5 == r5){
                g5_colorcode2 = GREEN_BOLD;
                g5 = g5_colorcode2 + g5 + RESET;
            }  
            else if (g5 != r1 || g5 != r2 || g5 != r3 || g5 != r4 || g5 != r5){
                g5_colorcode2 = GRAY_BOLD;
                g5 = g5_colorcode2 + g5 + RESET;
            }          
            cout << " ---  ---  ---  ---  --- " << endl;
            cout << "| " << g1 <<  " || " << g2 << " || " << g3 << " || " << g4 << " || " << g5 << " |" << endl;
            cout << " ---  ---  ---  ---  ---\n" << endl; 
            
            cin >> guess;
            if (guess.length() == 5) {
                if (find(notWords5.begin(), notWords5.end(), guess) != notWords5.end() || find(realWords5.begin(), realWords5.end(), guess) != realWords5.end()) {
                    goto Happy2;
                }
                else {
                    cout << "Invalid Word Choice, please try again 😞" << endl; 
                    wordleAttempts --;
                    goto Happy2;
                }
            }
            else {
                cout << "Invalid Word Choice, please try again 😞" << endl;
                wordleAttempts --;
                goto Happy2;
            }
        }
        if (g1 == r2 || g1 == r3 || g1 == r4 || g1 == r5){
            g1_colorcode2 = YELLOW_BOLD;
            g1 = g1_colorcode2 + g1 + RESET; 
        }
        else if (g1 == r1){
            g1_colorcode2 = GREEN_BOLD;
            g1 = g1_colorcode2 + g1 + RESET;
        }
        else if (g1 != r1 || g1 != r2 || g1 != r3 || g1 != r4 || g1 != r5){
            g1_colorcode2 = GRAY_BOLD;
            g1 = g1_colorcode2 + g1 + RESET;
        }
        if (g2 == r1 || g2 == r3 || g2 == r4 || g2 == r5){
            g2_colorcode2 = YELLOW_BOLD;
            g2 = g2_colorcode2 + g2 + RESET; 
        }
        else if (g2 == r2){
            g2_colorcode2 = GREEN_BOLD;
            g2 = g2_colorcode2 + g2 + RESET;
        }
        else if (g2 != r1 || g2 != r2 || g2 != r3 || g2 != r4 || g2 != r5){
            g2_colorcode2 = GRAY_BOLD;
            g2 = g2_colorcode2 + g2 + RESET;
        }
        if (g3 == r1 || g3 == r2 || g3 == r4 || g3 == r5){
            g3_colorcode2 = YELLOW_BOLD;
            g3 = g3_colorcode2 + g3 + RESET; 
        }
        else if (g3 == r3){
            g3_colorcode2 = GREEN_BOLD;
            g3 = g3_colorcode2 + g3 + RESET;
        }
        else if (g3 != r1 || g3 != r2 || g3 != r3 || g3 != r4 || g3 != r5){
            g3_colorcode2 = GRAY_BOLD;
            g3 = g3_colorcode2 + g3 + RESET;
        }
        if (g4 == r1 || g4 == r2 || g4 == r3 || g4 == r5){
            g4_colorcode2 = YELLOW_BOLD;
            g4 = g4_colorcode2 + g4 + RESET; 
        }
        else if (g4 == r4){
            g4_colorcode2 = GREEN_BOLD;
            g4 = g4_colorcode2 + g4 + RESET;
        } 
        else if (g4 != r1 || g4 != r2 || g4 != r3 || g4 != r4 || g4 != r5){
            g4_colorcode2 = GRAY_BOLD;
            g4 = g4_colorcode2 + g4 + RESET;
        }
        if (g5 == r1 || g5 == r2 || g5 == r3 || g5 == r4){
            g5_colorcode2 = YELLOW_BOLD;
            g5 = g5_colorcode2 + g5 + RESET; 
        }
        else if (g5 == r5){
            g5_colorcode2 = GREEN_BOLD;
            g5 = g5_colorcode2 + g5 + RESET;
        }  
        else if (g5 != r1 || g5 != r2 || g5 != r3 || g5 != r4 || g5 != r5){
            g5_colorcode2 = GRAY_BOLD;
            g5 = g5_colorcode2 + g5 + RESET;
        }          
        cout << " ---  ---  ---  ---  --- " << endl;
        cout << "| " << g1 <<  " || " << g2 << " || " << g3 << " || " << g4 << " || " << g5 << " |" << endl;
        cout << " ---  ---  ---  ---  ---\n" << endl;
        cout << "Uh oh, you lost." << endl;
        cout << "The word was: " << random_word5 << endl;
        ofstream statsLoses2;
        statsLoses2.open("yes_no.txt", ios::out);
        if (statsLoses2.is_open()) {
            statsLoses2 << "no" << endl;
        }
        statsLoses2.close();
        ofstream endstreakFile2;
        endstreakFile2.open("c_streak.txt", ios::out);
        if (endstreakFile2.is_open()) {
            endstreakFile2 << 0 << endl;
            streakCounter = 0;
        }
        endstreakFile2.close();
        exit(0); 
}

void success6(string random_word6){
    if (highestStreak > streakCounter){
        goto Continue3;
    }
    else {
        highestStreak ++;  
        goto Continue3;
    }
    Continue3:
    streakCounter ++;
    gamesWon ++;
    ofstream streakFile;
    streakFile.open("c_streak.txt", ios::out);
    if (streakFile.is_open()) {
        streakFile << streakCounter << endl;
    }
    streakFile.close();
    ofstream sFile3;
    sFile3.open("const_streak.txt", ios::out);
    if (sFile3.is_open()) {
        sFile3 << highestStreak << endl;
    }
    sFile3.close();
    ofstream wonFile;
    wonFile.open("games_won.txt", ios::out);
    if (wonFile.is_open()) {
        wonFile << gamesWon << endl;
    }
    wonFile.close();
    Percentage(hi);
    ofstream hi4File;
    hi4File.open("win_percentage.txt", ios::out);
    if (hi4File.is_open()) {
        hi4File << hi << endl;
        }
    hi4File.close();
    ofstream statsWin3;
    statsWin3.open("yes_no.txt", ios::out);
    if (statsWin3.is_open()) {
        statsWin3 << "yes" << endl;
        }
    statsWin3.close();
    r1 = toupper(random_word6[0]);
    r2 = toupper(random_word6[1]);
    r3 = toupper(random_word6[2]);
    r4 = toupper(random_word6[3]); 
    r5 = toupper(random_word6[4]);
    r6 = toupper(random_word6[5]);
    cout << GREEN_BOLD << " ---  ---  ---  ---  ---  ---" << endl;
    cout << "| " << r1 <<  " || " << r2 << " || " << r3 << " || " << r4 << " || " << r5 << " || " << r6 << " |" << endl;
    cout << " ---  ---  ---  ---  ---  ---\n" << RESET << endl; 
}

void wordleFunction6(string guess){
    const int guessLength6 = 6;
    vector<string> notWords6;
    ifstream allowed_file6("6-allowed.txt");
    string line_allowed6;
    while (getline(allowed_file6, line_allowed6)) notWords6.push_back(line_allowed6);
    allowed_file6.close();
    vector<string> realWords6;
    ifstream real_file6("6-words.txt");
    string line_real6;
    while (getline(real_file6, line_real6)) realWords6.push_back(line_real6);
    real_file6.close();
    ofstream resetatFile3;
    resetatFile3.open("attempts2.txt", ios::out);
    if (resetatFile3.is_open()) {
        resetatFile3 << 0 << endl;
        attemptsCounter2 = 0;
    }
    resetatFile3.close();
    Sucks3:
    cin >> guess;
    if (guess.length() == 6) {
        if (find(notWords6.begin(), notWords6.end(), guess) != notWords6.end() || find(realWords6.begin(), realWords6.end(), guess) != realWords6.end()) {
            goto Happy3;
            }
        else {
            cout << "Invalid Word Choice, please try again 😞" << endl;
            goto Sucks3;
            }
        }
    else {
        cout << "Invalid Word Choice, please try again 😞" << endl;
        goto Sucks3;
        }
    Happy3:
        g1 = toupper(guess[0]);
        g2 = toupper(guess[1]);
        g3 = toupper(guess[2]);
        g4 = toupper(guess[3]);
        g5 = toupper(guess[4]);
        g6 = toupper(guess[5]);
        r1 = toupper(random_word6[0]);
        r2 = toupper(random_word6[1]);
        r3 = toupper(random_word6[2]);
        r4 = toupper(random_word6[3]);
        r5 = toupper(random_word6[4]);
        r6 = toupper(random_word6[5]);
        string g1_colorcode3;
        string g2_colorcode3;            
        string g3_colorcode3;
        string g4_colorcode3;
        string g5_colorcode3;
        string g6_colorcode3;
        while (wordleAttempts < 5){ 
            wordleAttempts ++;
            attemptsCounter ++;
            attemptsCounter2 ++;
            ofstream attemptsFile;
            attemptsFile.open("c_attempts.txt", ios::out);
            if (attemptsFile.is_open()) {
                attemptsFile << attemptsCounter << endl;
                }
            attemptsFile.close();
            ofstream attempts2File3;
            attempts2File3.open("attempts2.txt", ios::out);
            if (attempts2File3.is_open()) {
                attempts2File3 << attemptsCounter2 << endl;
                }
            attempts2File3.close();
            if (guess == random_word6){
                success6(random_word6);
                cout << "Whoppi!" << endl;
                exit(0);
            }
            if (g1 == r2 || g1 == r3 || g1 == r4 || g1 == r5 || g1 == r6){
                g1_colorcode3 = YELLOW_BOLD;
                g1 = g1_colorcode3 + g1 + RESET; 
            }
            else if (g1 == r1){
                g1_colorcode3 = GREEN_BOLD;
                g1 = g1_colorcode3 + g1 + RESET;
            }
            else if (g1 != r1 || g1 != r2 || g1 != r3 || g1 != r4 || g1 != r5 || g1 != r6){
                g1_colorcode3 = GRAY_BOLD;
                g1 = g1_colorcode3 + g1 + RESET;
            }
            if (g2 == r1 || g2 == r3 || g2 == r4 || g2 == r5 || g2 == r6){
                g2_colorcode3 = YELLOW_BOLD;
                g2 = g2_colorcode3 + g2 + RESET; 
            }
            else if (g2 == r2){
                g2_colorcode3 = GREEN_BOLD;
                g2 = g2_colorcode3 + g2 + RESET;
            }
            else if (g2 != r1 || g2 != r2 || g2 != r3 || g2 != r4 || g2 != r5 || g2 != r6){
                g2_colorcode3 = GRAY_BOLD;
                g2 = g2_colorcode3 + g2 + RESET;
            }
            if (g3 == r1 || g3 == r2 || g3 == r4 || g3 == r5 || g3 == r6 ){
                g3_colorcode3 = YELLOW_BOLD;
                g3 = g3_colorcode3 + g3 + RESET; 
            }
            else if (g3 == r3){
                g3_colorcode3 = GREEN_BOLD;
                g3 = g3_colorcode3 + g3 + RESET;
            }
            else if (g3 != r1 || g3 != r2 || g3 != r3 || g3 != r4 || g3 != r5 || g3 != r6){
                g3_colorcode3 = GRAY_BOLD;
                g3 = g3_colorcode3 + g3 + RESET;
            }
            if (g4 == r1 || g4 == r2 || g4 == r3 || g4 == r5 || g4 == r6){
                g4_colorcode3 = YELLOW_BOLD;
                g4 = g4_colorcode3 + g4 + RESET; 
            }
            else if (g4 == r4){
                g4_colorcode3 = GREEN_BOLD;
                g4 = g4_colorcode3 + g4 + RESET;
            } 
            else if (g4 != r1 || g4 != r2 || g4 != r3 || g4 != r4 || g4 != r5 || g4 != r6){
                g4_colorcode3 = GRAY_BOLD;
                g4 = g4_colorcode3 + g4 + RESET;
            }
            if (g5 == r1 || g5 == r2 || g5 == r3 || g5 == r4 || g5 == r6){
                g5_colorcode3 = YELLOW_BOLD;
                g5 = g5_colorcode3 + g5 + RESET; 
            }
            else if (g5 == r5){
                g5_colorcode3 = GREEN_BOLD;
                g5 = g5_colorcode3 + g5 + RESET;
            } 
            else if (g5 != r1 || g5 != r2 || g5 != r3 || g5 != r4 || g5 != r5 || g5 != r6){
                g5_colorcode3 = GRAY_BOLD;
                g5 = g5_colorcode3 + g5 + RESET;
            }
            if (g6 == r1 || g6 == r2 || g6 == r3 || g6 == r4 || g6 == r5){
                g6_colorcode3 = YELLOW_BOLD;
                g6 = g6_colorcode3 + g6 + RESET; 
            }
            else if (g6 == r6){
                g6_colorcode3 = GREEN_BOLD;
                g6 = g6_colorcode3 + g6 + RESET;
            } 
            else if (g6 != r1 || g6 != r2 || g6 != r3 || g6 != r4 || g6 != r5 || g6 != r6){
                g6_colorcode3 = GRAY_BOLD;
                g6 = g6_colorcode3 + g6 + RESET;
            }
            cout << " ---  ---  ---  ---  ---  --- " << endl;
            cout << "| " << g1 <<  " || " << g2 << " || " << g3 << " || " << g4 << " || " << g5 << " || " << g6 << " |" << endl;
            cout << " ---  ---  ---  ---  ---  ---\n" << endl; 
            
            cin >> guess;
            if (guess.length() == 6) {
                if (find(notWords6.begin(), notWords6.end(), guess) != notWords6.end() || find(realWords6.begin(), realWords6.end(), guess) != realWords6.end()) {
                    goto Happy3;
                }
                else {
                    cout << "Invalid Word Choice, please try again 😞" << endl; 
                    wordleAttempts --;
                    goto Happy3;
                }
            }
            else {
                cout << "Invalid Word Choice, please try again 😞" << endl;
                wordleAttempts --;
                goto Happy3;
            }
        }
        if (g1 == r2 || g1 == r3 || g1 == r4 || g1 == r5 || g1 == r6){
            g1_colorcode3 = YELLOW_BOLD;
            g1 = g1_colorcode3 + g1 + RESET; 
        }
        else if (g1 == r1){
            g1_colorcode3 = GREEN_BOLD;
            g1 = g1_colorcode3 + g1 + RESET;
        }
        else if (g1 != r1 || g1 != r2 || g1 != r3 || g1 != r4 || g1 != r5 || g1 != r6){
            g1_colorcode3 = GRAY_BOLD;
            g1 = g1_colorcode3 + g1 + RESET;
        }
        if (g2 == r1 || g2 == r3 || g2 == r4 || g2 == r5 || g2 == r6){
            g2_colorcode3 = YELLOW_BOLD;
            g2 = g2_colorcode3 + g2 + RESET; 
        }
        else if (g2 == r2){
            g2_colorcode3 = GREEN_BOLD;
            g2 = g2_colorcode3 + g2 + RESET;
        }
        else if (g2 != r1 || g2 != r2 || g2 != r3 || g2 != r4 || g2 != r5 || g2 != r6){
            g2_colorcode3 = GRAY_BOLD;
            g2 = g2_colorcode3 + g2 + RESET;
        }
        if (g3 == r1 || g3 == r2 || g3 == r4 || g3 == r5 || g3 == r6 ){
            g3_colorcode3 = YELLOW_BOLD;
            g3 = g3_colorcode3 + g3 + RESET; 
        }
        else if (g3 == r3){
            g3_colorcode3 = GREEN_BOLD;
            g3 = g3_colorcode3 + g3 + RESET;
        }
        else if (g3 != r1 || g3 != r2 || g3 != r3 || g3 != r4 || g3 != r5 || g3 != r6){
            g3_colorcode3 = GRAY_BOLD;
            g3 = g3_colorcode3 + g3 + RESET;
        }
        if (g4 == r1 || g4 == r2 || g4 == r3 || g4 == r5 || g4 == r6){
            g4_colorcode3 = YELLOW_BOLD;
            g4 = g4_colorcode3 + g4 + RESET; 
        }
        else if (g4 == r4){
            g4_colorcode3 = GREEN_BOLD;
            g4 = g4_colorcode3 + g4 + RESET;
        } 
        else if (g4 != r1 || g4 != r2 || g4 != r3 || g4 != r4 || g4 != r5 || g4 != r6){
            g4_colorcode3 = GRAY_BOLD;
            g4 = g4_colorcode3 + g4 + RESET;
        }
        if (g5 == r1 || g5 == r2 || g5 == r3 || g5 == r4 || g5 == r6){
            g5_colorcode3 = YELLOW_BOLD;
            g5 = g5_colorcode3 + g5 + RESET; 
        }
        else if (g5 == r5){
            g5_colorcode3 = GREEN_BOLD;
            g5 = g5_colorcode3 + g5 + RESET;
        } 
        else if (g5 != r1 || g5 != r2 || g5 != r3 || g5 != r4 || g5 != r5 || g5 != r6){
            g5_colorcode3 = GRAY_BOLD;
            g5 = g5_colorcode3 + g5 + RESET;
        }
        if (g6 == r1 || g6 == r2 || g6 == r3 || g6 == r4 || g6 == r5){
            g6_colorcode3 = YELLOW_BOLD;
            g6 = g6_colorcode3 + g6 + RESET; 
        }
        else if (g6 == r6){
            g6_colorcode3 = GREEN_BOLD;
            g6 = g6_colorcode3 + g6 + RESET;
        } 
        else if (g6 != r1 || g6 != r2 || g6 != r3 || g6 != r4 || g6 != r5 || g6 != r6){
            g6_colorcode3 = GRAY_BOLD;
            g6 = g6_colorcode3 + g6 + RESET;
        }
        cout << " ---  ---  ---  ---  ---  --- " << endl;
        cout << "| " << g1 <<  " || " << g2 << " || " << g3 << " || " << g4 << " || " << g5 << " || " << g6 << " |" << endl;
        cout << " ---  ---  ---  ---  ---  ---\n" << endl; 
        cout << "Uh oh, you lost." << endl;
        cout << "The word was: " << random_word6 << endl;
        ofstream statsLoses3;
        statsLoses3.open("yes_no.txt", ios::out);
        if (statsLoses3.is_open()) {
            statsLoses3 << "no" << endl;
        }
        statsLoses3.close();
        ofstream endstreakFile3;
        endstreakFile3.open("c_streak.txt", ios::out);
        if (endstreakFile3.is_open()) {
            endstreakFile3 << 0 << endl;
            streakCounter = 0;
        }
        endstreakFile3.close();
        exit(0); 
}

void success7(string random_word7){
    if (highestStreak > streakCounter){
        goto Continue4;
    }
    else {
        highestStreak ++;  
        goto Continue4;
    }
    Continue4:
    streakCounter ++;
    gamesWon ++;
    ofstream streakFile;
    streakFile.open("c_streak.txt", ios::out);
    if (streakFile.is_open()) {
        streakFile << streakCounter << endl;
    }
    streakFile.close();
    ofstream sFile4;
    sFile4.open("const_streak.txt", ios::out);
    if (sFile4.is_open()) {
        sFile4 << highestStreak << endl;
    }
    sFile4.close();
    ofstream wonFile;
    wonFile.open("games_won.txt", ios::out);
    if (wonFile.is_open()) {
        wonFile << gamesWon << endl;
    }
    wonFile.close();
    Percentage(hi);
    ofstream hi5File;
    hi5File.open("win_percentage.txt", ios::out);
    if (hi5File.is_open()) {
        hi5File << hi << endl;
        }
    hi5File.close();
    ofstream statsWin4;
    statsWin4.open("yes_no.txt", ios::out);
    if (statsWin4.is_open()) {
        statsWin4 << "yes" << endl;
        }
    statsWin4.close();
    r1 = toupper(random_word7[0]);
    r2 = toupper(random_word7[1]);
    r3 = toupper(random_word7[2]);
    r4 = toupper(random_word7[3]); 
    r5 = toupper(random_word7[4]);
    r6 = toupper(random_word7[5]);
    r7 = toupper(random_word7[6]);
    cout << GREEN_BOLD << " ---  ---  ---  ---  ---  ---  ---" << endl;
    cout << "| " << r1 <<  " || " << r2 << " || " << r3 << " || " << r4 << " || " << r5 << " || " << r6 << " || " << r7 << " |" << endl;
    cout << " ---  ---  ---  ---  ---  ---  ---\n" << RESET << endl; 
}

void wordleFunction7(string guess){
    const int guessLength7 = 7;
    vector<string> notWords7;
    ifstream allowed_file7("7-allowed.txt");
    string line_allowed7;
    while (getline(allowed_file7, line_allowed7)) notWords7.push_back(line_allowed7);
    allowed_file7.close();
    vector<string> realWords7;
    ifstream real_file7("7-words.txt");
    string line_real7;
    while (getline(real_file7, line_real7)) realWords7.push_back(line_real7);
    real_file7.close();
    ofstream resetatFile4;
    resetatFile4.open("attempts2.txt", ios::out);
    if (resetatFile4.is_open()) {
        resetatFile4 << 0 << endl;
        attemptsCounter2 = 0;
    }
    resetatFile4.close();  
    Sucks4:
    cin >> guess;
    if (guess.length() == 7) {
        if (find(notWords7.begin(), notWords7.end(), guess) != notWords7.end() || find(realWords7.begin(), realWords7.end(), guess) != realWords7.end()) {
            goto Happy4;
            }
        else {
            cout << "Invalid Word Choice, please try again 😞" << endl;
            goto Sucks4;
            }
        }
    else {
        cout << "Invalid Word Choice, please try again 😞" << endl;
        goto Sucks4;
        }
    Happy4:
        g1 = toupper(guess[0]);
        g2 = toupper(guess[1]);
        g3 = toupper(guess[2]);
        g4 = toupper(guess[3]);
        g5 = toupper(guess[4]);
        g6 = toupper(guess[5]);
        g7 = toupper(guess[6]);
        r1 = toupper(random_word7[0]);
        r2 = toupper(random_word7[1]);
        r3 = toupper(random_word7[2]);
        r4 = toupper(random_word7[3]);
        r5 = toupper(random_word7[4]);
        r6 = toupper(random_word7[5]);
        r7 = toupper(random_word7[6]);
        string g1_colorcode4;
        string g2_colorcode4;            
        string g3_colorcode4;
        string g4_colorcode4;
        string g5_colorcode4;
        string g6_colorcode4;
        string g7_colorcode4;
        while (wordleAttempts < 5){ 
            wordleAttempts ++;
            attemptsCounter ++;
            attemptsCounter2 ++;
            ofstream attemptsFile;
            attemptsFile.open("c_attempts.txt", ios::out);
            if (attemptsFile.is_open()) {
                attemptsFile << attemptsCounter << endl;
                }
            attemptsFile.close();
            ofstream attempts2File4;
            attempts2File4.open("attempts2.txt", ios::out);
            if (attempts2File4.is_open()) {
                attempts2File4 << attemptsCounter2 << endl;
                }
            attempts2File4.close();
            if (guess == random_word7){
                success7(random_word7);
                cout << "Whoppi! You Win! 🎉" << endl;
                exit(0);
            }
            if (g1 == r2 || g1 == r3 || g1 == r4 || g1 == r5 || g1 == r6 || g1 == r7){
                g1_colorcode4 = YELLOW_BOLD;
                g1 = g1_colorcode4 + g1 + RESET; 
            }
            else if (g1 == r1){
                g1_colorcode4 = GREEN_BOLD;
                g1 = g1_colorcode4 + g1 + RESET;
            }
            else if (g1 != r1 || g1 != r2 || g1 != r3 || g1 != r4 || g1 != r5 || g1 != r6 || g1 != r7){
                g1_colorcode4 = GRAY_BOLD;
                g1 = g1_colorcode4 + g1 + RESET;
            }
            if (g2 == r1 || g2 == r3 || g2 == r4 || g2 == r5 || g2 == r6 || g2 == r7){
                g2_colorcode4 = YELLOW_BOLD;
                g2 = g2_colorcode4 + g2 + RESET; 
            }
            else if (g2 == r2){
                g2_colorcode4 = GREEN_BOLD;
                g2 = g2_colorcode4 + g2 + RESET;
            }
            else if (g2 != r1 || g2 != r2 || g2 != r3 || g2 != r4 || g2 != r5 || g2 != r6 || g2 != r7){
                g2_colorcode4 = GRAY_BOLD;
                g2 = g2_colorcode4 + g2 + RESET;
            }
            if (g3 == r1 || g3 == r2 || g3 == r4 || g3 == r5 || g3 == r6 || g3 == r7){
                g3_colorcode4 = YELLOW_BOLD;
                g3 = g3_colorcode4 + g3 + RESET; 
            }
            else if (g3 == r3){
                g3_colorcode4 = GREEN_BOLD;
                g3 = g3_colorcode4 + g3 + RESET;
            }
            else if (g3 != r1 || g3 != r2 || g3 != r3 || g3 != r4 || g3 != r5 || g3 != r6 || g3 != r7){
                g3_colorcode4 = GRAY_BOLD;
                g3 = g3_colorcode4 + g3 + RESET;
            }
            if (g4 == r1 || g4 == r2 || g4 == r3 || g4 == r5 || g4 == r6 || g4 == r7){
                g4_colorcode4 = YELLOW_BOLD;
                g4 = g4_colorcode4 + g4 + RESET; 
            }
            else if (g4 == r4){
                g4_colorcode4 = GREEN_BOLD;
                g4 = g4_colorcode4 + g4 + RESET;
            } 
            else if (g4 != r1 || g4 != r2 || g4 != r3 || g4 != r4 || g4 != r5 || g4 != r6 || g4 != r7){
                g4_colorcode4 = GRAY_BOLD;
                g4 = g4_colorcode4 + g4 + RESET;
            }
            if (g5 == r1 || g5 == r2 || g5 == r3 || g5 == r4 || g5 == r6 || g5 == r7){
                g5_colorcode4 = YELLOW_BOLD;
                g5 = g5_colorcode4 + g5 + RESET; 
            }
            else if (g5 == r5){
                g5_colorcode4 = GREEN_BOLD;
                g5 = g5_colorcode4 + g5 + RESET;
            } 
            else if (g5 != r1 || g5 != r2 || g5 != r3 || g5 != r4 || g5 != r5 || g5 != r6 || g5 != r7){
                g5_colorcode4 = GRAY_BOLD;
                g5 = g5_colorcode4 + g5 + RESET;
            }
            if (g6 == r1 || g6 == r2 || g6 == r3 || g6 == r4 || g6 == r5 || g6 == r7){
                g6_colorcode4 = YELLOW_BOLD;
                g6 = g6_colorcode4 + g6 + RESET; 
            }
            else if (g6 == r6){
                g6_colorcode4 = GREEN_BOLD;
                g6 = g6_colorcode4 + g6 + RESET;
            } 
            else if (g6 != r1 || g6 != r2 || g6 != r3 || g6 != r4 || g6 != r5 || g6 != r6 || g6 != r7){
                g6_colorcode4 = GRAY_BOLD;
                g6 = g6_colorcode4 + g6 + RESET;
            }
            if (g7 == r1 || g7 == r2 || g7 == r3 || g7 == r4 || g7 == r5 || g7 == r6){
                g7_colorcode4 = YELLOW_BOLD;
                g7 = g7_colorcode4 + g7 + RESET; 
            }
            else if (g7 == r7){
                g7_colorcode4 = GREEN_BOLD;
                g7 = g7_colorcode4 + g7 + RESET;
            } 
            else if (g7 != r1 || g7 != r2 || g7 != r3 || g7 != r4 || g7 != r5 || g7 != r6 || g7 != r7){
                g7_colorcode4 = GRAY_BOLD;
                g7 = g7_colorcode4 + g7 + RESET;
            }
            cout << " ---  ---  ---  ---  ---  ---  --- " << endl;
            cout << "| " << g1 <<  " || " << g2 << " || " << g3 << " || " << g4 << " || " << g5 << " || " << g6 << " || " << g7 << " |" << endl;
            cout << " ---  ---  ---  ---  ---  ---  ---\n" << endl; 
            cin >> guess;
            if (guess.length() == 7) {
                if (find(notWords7.begin(), notWords7.end(), guess) != notWords7.end() || find(realWords7.begin(), realWords7.end(), guess) != realWords7.end()) {
                    goto Happy4;
                }
                else {
                    cout << "Invalid Word Choice, please try again 😞" << endl; 
                    wordleAttempts --;
                    goto Happy4;
                }
            }
            else {
                cout << "Invalid Word Choice, please try again 😞" << endl;
                wordleAttempts --;
                goto Happy4;
            }
        }
        if (g1 == r2 || g1 == r3 || g1 == r4 || g1 == r5 || g1 == r6 || g1 == r7){
            g1_colorcode4 = YELLOW_BOLD;
            g1 = g1_colorcode4 + g1 + RESET; 
        }
        else if (g1 == r1){
            g1_colorcode4 = GREEN_BOLD;
            g1 = g1_colorcode4 + g1 + RESET;
        }
        else if (g1 != r1 || g1 != r2 || g1 != r3 || g1 != r4 || g1 != r5 || g1 != r6 || g1 != r7){
            g1_colorcode4 = GRAY_BOLD;
            g1 = g1_colorcode4 + g1 + RESET;
        }
        if (g2 == r1 || g2 == r3 || g2 == r4 || g2 == r5 || g2 == r6 || g2 == r7){
            g2_colorcode4 = YELLOW_BOLD;
            g2 = g2_colorcode4 + g2 + RESET; 
        }
        else if (g2 == r2){
            g2_colorcode4 = GREEN_BOLD;
            g2 = g2_colorcode4 + g2 + RESET;
        }
        else if (g2 != r1 || g2 != r2 || g2 != r3 || g2 != r4 || g2 != r5 || g2 != r6 || g2 != r7){
            g2_colorcode4 = GRAY_BOLD;
            g2 = g2_colorcode4 + g2 + RESET;
        }
        if (g3 == r1 || g3 == r2 || g3 == r4 || g3 == r5 || g3 == r6 || g3 == r7){
            g3_colorcode4 = YELLOW_BOLD;
            g3 = g3_colorcode4 + g3 + RESET; 
        }
        else if (g3 == r3){
            g3_colorcode4 = GREEN_BOLD;
            g3 = g3_colorcode4 + g3 + RESET;
        }
        else if (g3 != r1 || g3 != r2 || g3 != r3 || g3 != r4 || g3 != r5 || g3 != r6 || g3 != r7){
            g3_colorcode4 = GRAY_BOLD;
            g3 = g3_colorcode4 + g3 + RESET;
        }
        if (g4 == r1 || g4 == r2 || g4 == r3 || g4 == r5 || g4 == r6 || g4 == r7){
            g4_colorcode4 = YELLOW_BOLD;
            g4 = g4_colorcode4 + g4 + RESET; 
        }
        else if (g4 == r4){
            g4_colorcode4 = GREEN_BOLD;
            g4 = g4_colorcode4 + g4 + RESET;
        } 
        else if (g4 != r1 || g4 != r2 || g4 != r3 || g4 != r4 || g4 != r5 || g4 != r6 || g4 != r7){
            g4_colorcode4 = GRAY_BOLD;
            g4 = g4_colorcode4 + g4 + RESET;
        }
        if (g5 == r1 || g5 == r2 || g5 == r3 || g5 == r4 || g5 == r6 || g5 == r7){
            g5_colorcode4 = YELLOW_BOLD;
            g5 = g5_colorcode4 + g5 + RESET; 
        }
        else if (g5 == r5){
            g5_colorcode4 = GREEN_BOLD;
            g5 = g5_colorcode4 + g5 + RESET;
        } 
        else if (g5 != r1 || g5 != r2 || g5 != r3 || g5 != r4 || g5 != r5 || g5 != r6 || g5 != r7){
            g5_colorcode4 = GRAY_BOLD;
            g5 = g5_colorcode4 + g5 + RESET;
        }
        if (g6 == r1 || g6 == r2 || g6 == r3 || g6 == r4 || g6 == r5 || g6 == r7){
            g6_colorcode4 = YELLOW_BOLD;
            g6 = g6_colorcode4 + g6 + RESET; 
        }
        else if (g6 == r6){
            g6_colorcode4 = GREEN_BOLD;
            g6 = g6_colorcode4 + g6 + RESET;
        } 
        else if (g6 != r1 || g6 != r2 || g6 != r3 || g6 != r4 || g6 != r5 || g6 != r6 || g6 != r7){
            g6_colorcode4 = GRAY_BOLD;
            g6 = g6_colorcode4 + g6 + RESET;
        }
        if (g7 == r1 || g7 == r2 || g7 == r3 || g7 == r4 || g7 == r5 || g7 == r6){
            g7_colorcode4 = YELLOW_BOLD;
            g7 = g7_colorcode4 + g7 + RESET; 
        }
        else if (g7 == r7){
            g7_colorcode4 = GREEN_BOLD;
            g7 = g7_colorcode4 + g7 + RESET;
        } 
        else if (g7 != r1 || g7 != r2 || g7 != r3 || g7 != r4 || g7 != r5 || g7 != r6 || g7 != r7){
            g7_colorcode4 = GRAY_BOLD;
            g7 = g7_colorcode4 + g7 + RESET;
        }
        cout << " ---  ---  ---  ---  ---  ---  --- " << endl;
        cout << "| " << g1 <<  " || " << g2 << " || " << g3 << " || " << g4 << " || " << g5 << " || " << g6 << " || " << g7 << " |" << endl;
        cout << " ---  ---  ---  ---  ---  ---  ---\n" << endl; 
        cout << "Uh oh, you lost." << endl;
        cout << "The word was: " << random_word7 << endl;
        ofstream statsLoses4;
        statsLoses4.open("yes_no.txt", ios::out);
        if (statsLoses4.is_open()) {
            statsLoses4 << "no" << endl;
        }
        statsLoses4.close();
        ofstream endstreakFile4;
        endstreakFile4.open("c_streak.txt", ios::out);
        if (endstreakFile4.is_open()) {
            endstreakFile4 << 0 << endl;
            streakCounter = 0;
        }
        endstreakFile4.close();
        exit(0); 
}

void success8(string random_word8){
    if (highestStreak > streakCounter){
        goto Continue5;
    }
    else {
        highestStreak ++;  
        goto Continue5;
    }
    Continue5:
    streakCounter ++;
    gamesWon ++;
    ofstream streakFile;
    streakFile.open("c_streak.txt", ios::out);
    if (streakFile.is_open()) {
        streakFile << streakCounter << endl;
    }
    streakFile.close();
    ofstream sFile5;
    sFile5.open("const_streak.txt", ios::out);
    if (sFile5.is_open()) {
        sFile5 << highestStreak << endl;
    }
    sFile5.close();
    ofstream wonFile;
    wonFile.open("games_won.txt", ios::out);
    if (wonFile.is_open()) {
        wonFile << gamesWon << endl;
    }
    wonFile.close();
    Percentage(hi);
    ofstream hi6File;
    hi6File.open("win_percentage.txt", ios::out);
    if (hi6File.is_open()) {
        hi6File << hi << endl;
        }
    hi6File.close();
    ofstream statsWin5;
    statsWin5.open("yes_no.txt", ios::out);
    if (statsWin5.is_open()) {
        statsWin5 << "yes" << endl;
        }
    statsWin5.close();
    r1 = toupper(random_word8[0]);
    r2 = toupper(random_word8[1]);
    r3 = toupper(random_word8[2]);
    r4 = toupper(random_word8[3]); 
    r5 = toupper(random_word8[4]);
    r6 = toupper(random_word8[5]);
    r7 = toupper(random_word8[6]);
    r8 = toupper(random_word8[7]);
    cout << GREEN_BOLD << " ---  ---  ---  ---  ---  ---  ---  ---" << endl;
    cout << "| " << r1 <<  " || " << r2 << " || " << r3 << " || " << r4 << " || " << r5 << " || " << r6 << " || " << r7 << " || " << r8 << " |" << endl;
    cout << " ---  ---  ---  ---  ---  ---  ---  ---\n" << RESET << endl; 
}

void wordleFunction8(string guess){
    const int guessLength8 = 8;
    vector<string> notWords8;
    ifstream allowed_file8("8-allowed.txt");
    string line_allowed8;
    while (getline(allowed_file8, line_allowed8)) notWords8.push_back(line_allowed8);
    allowed_file8.close();
    vector<string> realWords8;
    ifstream real_file8("8-words.txt");
    string line_real8;
    while (getline(real_file8, line_real8)) realWords8.push_back(line_real8);
    real_file8.close();
    ofstream resetatFile5;
    resetatFile5.open("attempts2.txt", ios::out);
    if (resetatFile5.is_open()) {
        resetatFile5 << 0 << endl;
        attemptsCounter2 = 0;
    }
    resetatFile5.close();
    Sucks5:
    cin >> guess;
    if (guess.length() == 8) {
        if (find(notWords8.begin(), notWords8.end(), guess) != notWords8.end() || find(realWords8.begin(), realWords8.end(), guess) != realWords8.end()) {
            goto Happy5;
            }
        else {
            cout << "Invalid Word Choice, please try again 😞" << endl;
            goto Sucks5;
            }
        }
    else {
        cout << "Invalid Word Choice, please try again 😞" << endl;
        goto Sucks5;
        }
    Happy5:
        g1 = toupper(guess[0]);
        g2 = toupper(guess[1]);
        g3 = toupper(guess[2]);
        g4 = toupper(guess[3]);
        g5 = toupper(guess[4]);
        g6 = toupper(guess[5]);
        g7 = toupper(guess[6]);
        g8 = toupper(guess[7]);
        r1 = toupper(random_word8[0]);
        r2 = toupper(random_word8[1]);
        r3 = toupper(random_word8[2]);
        r4 = toupper(random_word8[3]);
        r5 = toupper(random_word8[4]);
        r6 = toupper(random_word8[5]);
        r7 = toupper(random_word8[6]);
        r8 = toupper(random_word8[7]);
        string g1_colorcode5;
        string g2_colorcode5;            
        string g3_colorcode5;
        string g4_colorcode5;
        string g5_colorcode5;
        string g6_colorcode5;
        string g7_colorcode5;
        string g8_colorcode5;
        while (wordleAttempts < 5){ 
            wordleAttempts ++;
            attemptsCounter ++;
            attemptsCounter2 ++;
            ofstream attemptsFile;
            attemptsFile.open("c_attempts.txt", ios::out);
            if (attemptsFile.is_open()) {
                attemptsFile << attemptsCounter << endl;
                }
            attemptsFile.close();
            ofstream attempts2File5;
            attempts2File5.open("attempts2.txt", ios::out);
            if (attempts2File5.is_open()) {
                attempts2File5 << attemptsCounter2 << endl;
                }
            attempts2File5.close();
            if (guess == random_word8){
                success8(random_word8);
                cout << "Whoppi! You Win! 🎉" << endl;
                exit(0);
            }
            if (g1 == r2 || g1 == r3 || g1 == r4 || g1 == r5 || g1 == r6 || g1 == r7 || g1 == r8){
                g1_colorcode5 = YELLOW_BOLD;
                g1 = g1_colorcode5 + g1 + RESET; 
            }
            else if (g1 == r1){
                g1_colorcode5 = GREEN_BOLD;
                g1 = g1_colorcode5 + g1 + RESET;
            }
            else if (g1 != r1 || g1 != r2 || g1 != r3 || g1 != r4 || g1 != r5 || g1 != r6 || g1 != r7 || g1 != r8){
                g1_colorcode5 = GRAY_BOLD;
                g1 = g1_colorcode5 + g1 + RESET;
            }
            if (g2 == r1 || g2 == r3 || g2 == r4 || g2 == r5 || g2 == r6 || g2 == r7 || g2 == r8){
                g2_colorcode5 = YELLOW_BOLD;
                g2 = g2_colorcode5 + g2 + RESET; 
            }
            else if (g2 == r2){
                g2_colorcode5 = GREEN_BOLD;
                g2 = g2_colorcode5 + g2 + RESET;
            }
            else if (g2 != r1 || g2 != r2 || g2 != r3 || g2 != r4 || g2 != r5 || g2 != r6 || g2 != r7 || g2 != r8){
                g2_colorcode5 = GRAY_BOLD;
                g2 = g2_colorcode5 + g2 + RESET;
            }
            if (g3 == r1 || g3 == r2 || g3 == r4 || g3 == r5 || g3 == r6 || g3 == r7 || g3 == r8){
                g3_colorcode5 = YELLOW_BOLD;
                g3 = g3_colorcode5 + g3 + RESET; 
            }
            else if (g3 == r3){
                g3_colorcode5 = GREEN_BOLD;
                g3 = g3_colorcode5 + g3 + RESET;
            }
            else if (g3 != r1 || g3 != r2 || g3 != r3 || g3 != r4 || g3 != r5 || g3 != r6 || g3 != r7 || g3 != r8){
                g3_colorcode5 = GRAY_BOLD;
                g3 = g3_colorcode5 + g3 + RESET;
            }
            if (g4 == r1 || g4 == r2 || g4 == r3 || g4 == r5 || g4 == r6 || g4 == r7 || g4 == r8){
                g4_colorcode5 = YELLOW_BOLD;
                g4 = g4_colorcode5 + g4 + RESET; 
            }
            else if (g4 == r4){
                g4_colorcode5 = GREEN_BOLD;
                g4 = g4_colorcode5 + g4 + RESET;
            } 
            else if (g4 != r1 || g4 != r2 || g4 != r3 || g4 != r4 || g4 != r5 || g4 != r6 || g4 != r7 || g4 != r8){
                g4_colorcode5 = GRAY_BOLD;
                g4 = g4_colorcode5 + g4 + RESET;
            }
            if (g5 == r1 || g5 == r2 || g5 == r3 || g5 == r4 || g5 == r6 || g5 == r7 || g5 == r8){
                g5_colorcode5 = YELLOW_BOLD;
                g5 = g5_colorcode5 + g5 + RESET; 
            }
            else if (g5 == r5){
                g5_colorcode5 = GREEN_BOLD;
                g5 = g5_colorcode5 + g5 + RESET;
            } 
            else if (g5 != r1 || g5 != r2 || g5 != r3 || g5 != r4 || g5 != r5 || g5 != r6 || g5 != r7 || g5 != r8){
                g5_colorcode5 = GRAY_BOLD;
                g5 = g5_colorcode5 + g5 + RESET;
            }
            if (g6 == r1 || g6 == r2 || g6 == r3 || g6 == r4 || g6 == r5 || g6 == r7 || g6 == r8){
                g6_colorcode5 = YELLOW_BOLD;
                g6 = g6_colorcode5 + g6 + RESET; 
            }
            else if (g6 == r6){
                g6_colorcode5 = GREEN_BOLD;
                g6 = g6_colorcode5 + g6 + RESET;
            } 
            else if (g6 != r1 || g6 != r2 || g6 != r3 || g6 != r4 || g6 != r5 || g6 != r6 || g6 != r7 || g6 != r8){
                g6_colorcode5 = GRAY_BOLD;
                g6 = g6_colorcode5 + g6 + RESET;
            }
            if (g7 == r1 || g7 == r2 || g7 == r3 || g7 == r4 || g7 == r5 || g7 == r6 || g7 == r8){
                g7_colorcode5 = YELLOW_BOLD;
                g7 = g7_colorcode5 + g7 + RESET; 
            }
            else if (g7 == r7){
                g7_colorcode5 = GREEN_BOLD;
                g7 = g7_colorcode5 + g7 + RESET;
            } 
            else if (g7 != r1 || g7 != r2 || g7 != r3 || g7 != r4 || g7 != r5 || g7 != r6 || g7 != r7 || g7 != r8){
                g7_colorcode5 = GRAY_BOLD;
                g7 = g7_colorcode5 + g7 + RESET;
            }
            if (g8 == r1 || g8 == r2 || g8 == r3 || g8 == r4 || g8 == r5 || g8 == r6 || g8 == r7){
                g8_colorcode5 = YELLOW_BOLD;
                g8 = g8_colorcode5 + g8 + RESET; 
            }
            else if (g8 == r8){
                g8_colorcode5 = GREEN_BOLD;
                g8 = g8_colorcode5 + g8 + RESET;
            } 
            else if (g8 != r1 || g8 != r2 || g8 != r3 || g8 != r4 || g8 != r5 || g8 != r6 || g8 != r7 || g8 != r8){
                g8_colorcode5 = GRAY_BOLD;
                g8 = g8_colorcode5 + g8 + RESET;
            }
            cout << " ---  ---  ---  ---  ---  ---  ---  --- " << endl;
            cout << "| " << g1 <<  " || " << g2 << " || " << g3 << " || " << g4 << " || " << g5 << " || " << g6 << " || " << g7 << " || " << g8 << " |" << endl;
            cout << " ---  ---  ---  ---  ---  ---  ---  ---\n" << endl; 
            
            cin >> guess;
            if (guess.length() == 8) {
                if (find(notWords8.begin(), notWords8.end(), guess) != notWords8.end() || find(realWords8.begin(), realWords8.end(), guess) != realWords8.end()) {
                    goto Happy5;
                }
                else {
                    cout << "Invalid Word Choice, please try again 😞" << endl; 
                    wordleAttempts --;
                    goto Happy5;
                }
            }
            else {
                cout << "Invalid Word Choice, please try again 😞" << endl;
                wordleAttempts --;
                goto Happy5;
            }
        }
        if (g1 == r2 || g1 == r3 || g1 == r4 || g1 == r5 || g1 == r6 || g1 == r7 || g1 == r8){
            g1_colorcode5 = YELLOW_BOLD;
            g1 = g1_colorcode5 + g1 + RESET; 
        }
        else if (g1 == r1){
            g1_colorcode5 = GREEN_BOLD;
            g1 = g1_colorcode5 + g1 + RESET;
        }
        if (g2 == r1 || g2 == r3 || g2 == r4 || g2 == r5 || g2 == r6 || g2 == r7 || g2 == r8){
            g2_colorcode5 = YELLOW_BOLD;
            g2 = g2_colorcode5 + g2 + RESET; 
        }
        else if (g2 == r2){
            g2_colorcode5 = GREEN_BOLD;
            g2 = g2_colorcode5 + g2 + RESET;
        }
        if (g3 == r1 || g3 == r2 || g3 == r4 || g3 == r5 || g3 == r6 || g3 == r7 || g3 == r8){
            g3_colorcode5 = YELLOW_BOLD;
            g3 = g3_colorcode5 + g3 + RESET; 
        }
        else if (g3 == r3){
            g3_colorcode5 = GREEN_BOLD;
            g3 = g3_colorcode5 + g3 + RESET;
        }
        if (g4 == r1 || g4 == r2 || g4 == r3 || g4 == r5 || g4 == r6 || g4 == r7 || g4 == r8){
            g4_colorcode5 = YELLOW_BOLD;
            g4 = g4_colorcode5 + g4 + RESET; 
        }
        else if (g4 == r4){
            g4_colorcode5 = GREEN_BOLD;
            g4 = g4_colorcode5 + g4 + RESET;
        } 
        if (g5 == r1 || g5 == r2 || g5 == r3 || g5 == r4 || g5 == r6 || g5 == r7 || g5 == r8){
            g5_colorcode5 = YELLOW_BOLD;
            g5 = g5_colorcode5 + g5 + RESET; 
        }
        else if (g5 == r5){
            g5_colorcode5 = GREEN_BOLD;
            g5 = g5_colorcode5 + g5 + RESET;
        } 
        if (g6 == r1 || g6 == r2 || g6 == r3 || g6 == r4 || g6 == r5 || g6 == r7 || g6 == r8){
            g6_colorcode5 = YELLOW_BOLD;
            g6 = g6_colorcode5 + g6 + RESET; 
        }
        else if (g6 == r6){
            g6_colorcode5 = GREEN_BOLD;
            g6 = g6_colorcode5 + g6 + RESET;
        } 
        if (g7 == r1 || g7 == r2 || g7 == r3 || g7 == r4 || g7 == r5 || g7 == r6 || g7 == r8){
            g7_colorcode5 = YELLOW_BOLD;
            g7 = g7_colorcode5 + g7 + RESET; 
        }
        else if (g7 == r7){
            g7_colorcode5 = GREEN_BOLD;
            g7 = g7_colorcode5 + g7 + RESET;
        } 
        if (g8 == r1 || g8 == r2 || g8 == r3 || g8 == r4 || g8 == r5 || g8 == r6 || g8 == r7){
            g8_colorcode5 = YELLOW_BOLD;
            g8 = g8_colorcode5 + g8 + RESET; 
        }
        else if (g8 == r8){
            g8_colorcode5 = GREEN_BOLD;
            g8 = g8_colorcode5 + g8 + RESET;
        } 
        cout << " ---  ---  ---  ---  ---  ---  ---  --- " << endl;
        cout << "| " << g1 <<  " || " << g2 << " || " << g3 << " || " << g4 << " || " << g5 << " || " << g6 << " || " << g7 << " || " << g8 << " |" << endl;
        cout << " ---  ---  ---  ---  ---  ---  ---  ---\n" << endl; 
        cout << "Uh oh, you lost." << endl;
        cout << "The word was: " << random_word8 << endl;
        ofstream statsLoses5;
        statsLoses5.open("yes_no.txt", ios::out);
        if (statsLoses5.is_open()) {
            statsLoses5 << "no" << endl;
        }
        statsLoses5.close();
        ofstream endstreakFile5;
        endstreakFile5.open("c_streak.txt", ios::out);
        if (endstreakFile5.is_open()) {
            endstreakFile5 << 0 << endl;
            streakCounter = 0;
        }
        endstreakFile5.close();
        exit(0); 
}

void startWordle4(){
    playCounter ++;
    ofstream playedFile4;
    playedFile4.open("timesplayed.txt", ios::out);
    if (playedFile4.is_open()) {
        playedFile4 << playCounter << endl;
        }
    playedFile4.close();
    Percentage(hi);
    ofstream hi3File;
    hi3File.open("win_percentage.txt", ios::out);
    if (hi3File.is_open()) {
        hi3File << hi << endl;
        }
    hi3File.close();
    cout << "Enter Your Guess:" << endl;
    vector<string> words4;
    ifstream random4file("4-words.txt"); // pick random word ; help me
    string line4;
    while (getline(random4file, line4)) words4.push_back(line4);
    srand(static_cast<unsigned int>(time(nullptr)));
    int random_index4 = rand() % words4.size();
    random_word4 = words4[random_index4];
    random4file.close();
    ofstream random_to_keyboard4;
    random_to_keyboard4.open("rando.txt", ios::out);
    if (random_to_keyboard4.is_open()) {
        random_to_keyboard4 << random_word4 << endl;
        }
    random_to_keyboard4.close();
    wordleFunction4(guess);
}

void startWordle5(){
    playCounter ++;
    ofstream playedFile5;
    playedFile5.open("timesplayed.txt", ios::out);
    if (playedFile5.is_open()) {
        playedFile5 << playCounter << endl;
        }
    playedFile5.close();
    cout << "Enter Your Guess:" << endl;
    vector<string> words5;
    ifstream random5file("5-words.txt"); // pick random word ; help me
    string line5;
    while (getline(random5file, line5)) words5.push_back(line5);
    srand(static_cast<unsigned int>(time(nullptr)));
    int random_index5 = rand() % words5.size();
    random_word5 = words5[random_index5];
    random5file.close(); 
    ofstream random_to_keyboard5;
    random_to_keyboard5.open("rando.txt", ios::out);
    if (random_to_keyboard5.is_open()) {
        random_to_keyboard5 << random_word5 << endl;
        }
    random_to_keyboard5.close();
    wordleFunction5(guess);
}

void startWordle6(){
    playCounter ++;
    ofstream playedFile6;
    playedFile6.open("timesplayed.txt", ios::out);
    if (playedFile6.is_open()) {
        playedFile6 << playCounter << endl;
        }
    playedFile6.close();
    cout << "Enter Your Guess:" << endl;
    vector<string> words6;
    ifstream random6file("6-words.txt");
    string line6;
    while (getline(random6file, line6)) words6.push_back(line6);
    srand(static_cast<unsigned int>(time(nullptr)));
    int random_index6 = rand() % words6.size();
    random_word6 = words6[random_index6];
    random6file.close(); 
    ofstream random_to_keyboard6;
    random_to_keyboard6.open("rando.txt", ios::out);
    if (random_to_keyboard6.is_open()) {
        random_to_keyboard6 << random_word6 << endl;
        }
    random_to_keyboard6.close();
    wordleFunction6(guess);
}

void startWordle7(){
    playCounter ++;
    ofstream playedFile7;
    playedFile7.open("timesplayed.txt", ios::out);
    if (playedFile7.is_open()) {
        playedFile7 << playCounter << endl;
        }
    playedFile7.close();
    cout << "Enter Your Guess:" << endl;
    vector<string> words7;
    ifstream random7file("7-words.txt");
    string line7;
    while (getline(random7file, line7)) words7.push_back(line7);
    srand(static_cast<unsigned int>(time(nullptr)));
    int random_index7 = rand() % words7.size();
    random_word7 = words7[random_index7];
    random7file.close(); 
    ofstream random_to_keyboard7;
    random_to_keyboard7.open("rando.txt", ios::out);
    if (random_to_keyboard7.is_open()) {
        random_to_keyboard7 << random_word7 << endl;
        }
    random_to_keyboard7.close();
    wordleFunction7(guess);   
}

void startWordle8(){
    playCounter ++;
    ofstream playedFile8;
    playedFile8.open("timesplayed.txt", ios::out);
    if (playedFile8.is_open()) {
        playedFile8 << playCounter << endl;
        }
    playedFile8.close();
    cout << "Enter Your Guess:" << endl;
    vector<string> words8;
    ifstream random8file("8-words.txt");
    string line8;
    while (getline(random8file, line8)) words8.push_back(line8);
    srand(static_cast<unsigned int>(time(nullptr)));
    int random_index8 = rand() % words8.size();
    random_word8 = words8[random_index8];
    random8file.close(); 
    ofstream random_to_keyboard8;
    random_to_keyboard8.open("rando.txt", ios::out);
    if (random_to_keyboard8.is_open()) {
        random_to_keyboard8 << random_word8 << endl;
        }
    random_to_keyboard8.close();
    wordleFunction8(guess);
}

void howToPlay(){
    cout <<"=============================================" << endl;
    cout <<"                 HOW TO PLAY" << endl;
    cout <<"=============================================" << endl;
    cout <<"Guess the Wordle in 6 tries." << endl;
    cout << " " << endl;
    cout << " " << endl; 
    cout << "HOW TO PLAY:" << endl;
    cout << "- Each guess must be a valid 5 letter word." << endl;
    cout << "- The color of the tiles will change to show" << endl;
    cout << "  you how close your guess was to the word." << endl;   
    cout << " " << endl;
    cout << " " << endl; 
    cout << GREEN_BOLD << " --- " << RESET << " ---  ---  ---  ---" << endl;
    cout << GREEN_BOLD << "| W |" << RESET << "| E || A || R || Y |"<< endl;
    cout << GREEN_BOLD << " --- " << RESET << " ---  ---  ---  ---" << endl;
    cout << "W is in the word and in the correct spot." << endl;
    cout << " " << endl;
    cout << " --- " << YELLOW_BOLD << " --- " << RESET << " ---  ---  ---" << endl;
    cout << "| P |" << YELLOW_BOLD << "| I |" << RESET << "| L || L || S |"<< endl;
    cout << " --- " << YELLOW_BOLD << " --- " << RESET << " ---  ---  ---" << endl;
    cout << "I is in the word but in the wrong spot." << endl;
    cout << " " << endl;
    cout << " ---  ---  --- " << GRAY_BOLD << " --- " << RESET << " ---" << endl;
    cout << "| V || A || G |" << GRAY_BOLD << "| U |" << RESET << "| E |"<< endl;
    cout << " ---  ---  --- " << GRAY_BOLD << " --- " << RESET << " ---" << endl;
    cout << "U is not in the word in any spot." << endl;
    cout << " " << endl;
    cout << " " << endl;

}

void readStats(){
    if (highestStreak < streakCounter){
        highestStreak = streakCounter;
    }
    ifstream timesPlayed("timesplayed.txt");
    int lastNumber;
    string line3;
    while(getline(timesPlayed, line3)) {
        int played_number = stoi(line3);
        lastNumber = played_number;
    }
    timesPlayed.close();

    ifstream timesWon("c_streak.txt");
    int lastNumber2;
    string line4;
    while(getline(timesWon, line4)) {
        int won_number = stoi(line4);
        lastNumber2 = won_number;
    }
    timesWon.close();

    ifstream timesWonconst("const_streak.txt");
    int lastNum;
    string lin;
    while(getline(timesWonconst, lin)) {
        int const_num = stoi(lin);
        lastNum = const_num;
    }
    timesWonconst.close();

    ifstream timesattempts("c_attempts.txt");
    int lastNumber3;
    string line5;
    while(getline(timesattempts, line5)) {
        int attempts_number = stoi(line5);
        lastNumber3 = attempts_number;
    }
    timesattempts.close();

    ifstream timesattempts2("attempts2.txt");
    int last;
    string lime;
    while(getline(timesattempts2, lime)) {
        int attempts2_number = stoi(lime);
        last = attempts2_number;
    }
    timesattempts.close();

    ifstream timeswon("games_won.txt");
    int lastNumber4;
    string line6;
    while(getline(timeswon, line6)) {
        int constwon_number = stoi(line6);
        lastNumber4 = constwon_number;
    }
    timesattempts.close();

    ifstream helpFile("rando.txt");
    string rando_stat;
    if (helpFile.is_open()){
        getline(helpFile, rando_stat);
        helpFile.close();
    }

    ifstream help2File("yes_no.txt");
    string yes_no;
    if (help2File.is_open()){
        getline(help2File, yes_no);
        help2File.close();
    }

    cout << "==========================" << endl; // width = 26
    cout << "    STATISTICS SUMMARY" << endl;
    cout << "==========================" << endl;
    cout << "Times Played:" << setw(13) << right << lastNumber << endl;
    cout << "Average Attempts:" << setw(9) << right << lastNumber3 << endl;
    cout << "Win Percentage:" << setw(10) << right << hi << "%" << endl;
    cout << "Current Streak:" << setw(11) << right << lastNumber2 << endl;
    cout << "Longest Streak:" << setw(11) << right << lastNum << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << "--------------------------" << endl; // width = 26
    cout << "WORD     ATTEMPTS      WIN" << endl;
    cout << "--------------------------" << endl; // width = 26
    cout << setw(10) << left << rando_stat;
    cout << setw(10) << left << last;
    cout << setw(10) << left << yes_no << endl;
}

void resetStats(){
    ofstream resetStatsFile;
    resetStatsFile.open("timesplayed.txt", ios::out);
    if (resetStatsFile.is_open()) {
            resetStatsFile << 0 << endl;
            playCounter = 0;
    }
    resetStatsFile.close();
    ofstream resetStats2File;
    resetStats2File.open("c_streak.txt", ios::out);
    if (resetStats2File.is_open()) {
            resetStats2File << 0 << endl;
            streakCounter = 0;
    }
    resetStats2File.close();
    ofstream resetFile;
    resetFile.open("const_streak.txt", ios::out);
    if (resetFile.is_open()) {
            resetFile << 0 << endl;
            highestStreak = 0;
    }
    resetFile.close();
    ofstream resetStats3File;
    resetStats3File.open("c_attempts.txt", ios::out);
    if (resetStats3File.is_open()) {
            resetStats3File << 0 << endl;
            attemptsCounter = 0;
    }
    resetStats3File.close();
    ofstream resetStats4File;
    resetStats4File.open("games_won.txt", ios::out);
    if (resetStats4File.is_open()) {
            resetStats4File << 0 << endl;
            gamesWon = 0;
    }
    resetStats4File.close();
    ofstream resetatFile2;
    resetatFile2.open("attempts2.txt", ios::out);
    if (resetatFile2.is_open()) {
            resetatFile2 << 0 << endl;
            attemptsCounter2 = 0;
    }
    resetatFile2.close();

    ofstream resetRando;
    resetRando.open("rando.txt", ios::out);
    if (resetRando.is_open()) {
        resetRando << " " << endl;
        }
    resetRando.close();

    ofstream resetyesno;
    resetyesno.open("yes_no.txt", ios::out);
    if (resetyesno.is_open()) {
        resetyesno << " " << endl;
        }
    resetyesno.close();

    cout << "Statistics Have Reset" << endl;
}

void byeExit(){
    exit(0);
}

int main(int argc, char *argv[]) {
    int numberArgc;
    int numar;
    if (argc > 1) {
        int numberArgc = atoi(argv[1]);
        numar = numberArgc;
    }
    if (numar >= 4 && numar <= 8){
            Start: 
            ofstream key1File;
            key1File.open("programming-project-2/exercise-1/key.txt", ios::out);
            if (key1File.is_open()) {
                key1File << 1 << endl;
            }
            key1File.close();

            ifstream read_timesPlayed("timesplayed.txt");

            string line_counter;
            while(getline(read_timesPlayed, line_counter)) {
                int number = stoi(line_counter);
                playCounter = number;
                }
            read_timesPlayed.close();

            // current streak
            ifstream read_currentstreak("c_streak.txt");
            string line_counter2;
            while(getline(read_currentstreak, line_counter2)) {
                int streak_number = stoi(line_counter2);
                streakCounter = streak_number;
                }
            read_currentstreak.close();

            ifstream read_conststreak("const_streak.txt");
            string line_count;
            while(getline(read_conststreak, line_count)) {
                int const_num = stoi(line_count);
                highestStreak = const_num;
                }
            read_conststreak.close();

            //attempts
            ifstream read_currentattempts("c_attempts.txt");
            string line_counter3;
            while(getline(read_currentattempts, line_counter3)) {
                int attempts_number = stoi(line_counter3);
                attemptsCounter = attempts_number;
                }
            read_currentattempts.close();

            // const games won
            ifstream read_currentwon("games_won.txt");
            string line_counter4;
            while(getline(read_currentwon, line_counter4)) {
                int won_number = stoi(line_counter4);
                gamesWon = won_number;
                }
            read_currentattempts.close(); 

            // win percent
            ifstream read_percentage("win_percentage.txt");
            string line_counter5;
            while(getline(read_percentage, line_counter5)) {
                double percent_number = stoi(line_counter5);
                winPercentage = percent_number;
                }
            read_currentattempts.close();         
            int option;
            cout << "=========================" << endl;
            cout <<"    WELCOME TO WORDLE" << endl;;
            cout << "=========================" << endl;;
            cout << " " << endl;;
            cout << " " << endl;;
            cout << "1. Play Wordle" << endl;;
            cout << "2. How to Play" << endl;;
            cout << "3. Statistics Summary" << endl;;
            cout << "4. Reset Statistics" << endl;;
            cout << "5. Exit" << endl;;
            cout << " " << endl;;
            cout << " " << endl;;
            cout << "Select an option:";

            cin >> option;
            switch (option){
                case 1:
                    if (numar == 4){
                        startWordle4();
                        break;
                    }
                    else if (numar== 5){
                        startWordle5();
                        break;
                    }
                    else if (numar == 6){
                        startWordle6();
                        break;
                    }
                    else if (numar == 7){
                        startWordle7();
                        break;
                    }
                    else if (numar == 8){
                        startWordle8();
                        break;
                    }
                    break;
                    
                case 2:
                    howToPlay();
                    break;
                case 3:
                    readStats();
                    break;
                case 4:
                    resetStats();
                    break;
                case 5:
                    byeExit();
                    break;
                default:
                    cout << "Invalid number choice, please choose number from 1 through 5" << endl;
                    exit(0);
            }
            cout << "Press [enter] to continue" << endl;
            cin.get();
            cin.ignore();
            goto Start;        
    }
    else {
        cout << "Invalid number choice, please choose number from 4 through 8" << endl;
        exit(0);
    }

    return 0;
}
