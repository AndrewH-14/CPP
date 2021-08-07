#include <iostream>
#include <array>

using namespace std;

// define a constant to store the size of the array
const int len = 10;

// define the function
int calculate_total(const array<int, len>& scores) 
{
    int total = 0;
    for (int score : scores) {
        total += score;
    }
    return total;
}

int main() 
{
    // creates the array and initializes it to zero
    array<int, len> scores {0};

    cout << "The Test Scores program\n\n"
         << "Enter " << len << " scores or -1 to exit.\n\n";

    // get scores from user
    int score_count = 0;
    while (score_count < scores.size()) 
    {
        int score;
        cout << "Enter score: ";
        cin >> score;
        if (score == -1) 
        {
            break;
        }
        scores[score_count] = score;
        ++score_count;
    }
    cout << endl;

    int total = calculate_total(scores);    // call the function
    cout << "Score count: " << score_count << endl;
    cout << "Score total: " << total << endl;
}