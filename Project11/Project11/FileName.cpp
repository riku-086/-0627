#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<int> generateAnswer() {
    vector<int> digits = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    random_shuffle(digits.begin(), digits.end());
    digits.resize(4);
    return digits;
}


vector<int> getUserGuess() {
    vector<int> guess(4);
    int input;
    cout << "“ü—Í‚µ‚Ä‚­‚¾‚³‚¢: ";
    cin >> input;

    for (int i = 3; i >= 0; --i) {
        guess[i] = input % 10;
        input /= 10;
    }
    return guess;
}
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    vector<int> answer = generateAnswer();
    int attempts = 0;
    bool gameclear = false;
    while (!gameclear) {
        vector<int> guess = getUserGuess();
        attempts++;
        int hit = 0, blow = 0;
        for (int i = 0; i < 4; ++i) {
            if (guess[i] == answer[i]) {
                hit++;
            } else if (find(answer.begin(), answer.end(), guess[i]) != answer.end()) {
                blow++;
            }
        }
        cout << "hit: " << hit << ", blow: " << blow << endl;
        if (hit == 4) {
            gameclear = true;
            cout << "‚¨‚ß‚Å‚Æ‚¤‚²‚´‚¢‚Ü‚·I³‰ð‚Å‚·B" << endl;
        }
    }
    return 0;
}
