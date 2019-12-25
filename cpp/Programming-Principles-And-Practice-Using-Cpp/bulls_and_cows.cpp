#include "./std_lib_facilities.h"

vector<int> generate_vector()
{
    srand(time(0));
    vector<int> numbers;

    for (int i = 0; i < 4; ) {
        int rand_num = rand() % 10;
        // add only unique numbers
        if (!count(numbers.begin(), numbers.end(), rand_num)) {
            numbers.push_back(rand_num);
            i++;
        }
    }

    return numbers;
}

int main()
{
    // generate vector of random nums
    vector<int> random_nums;

    random_nums = generate_vector();

    cout << "generated vector: " << random_nums[0] << ' '<< random_nums[1] << ' '<< random_nums[2] << ' '<< random_nums[3] << '\n';

    //*************************************************************
    // prompt user to guess nums
    cout << "enter nums to guess\n";

    string entered_str; // todo add validation only integers 0-9 and only four
    cin >> entered_str;
    cout << "entered string is " << entered_str << '\n';

    //*************************************************************
    // read user input to vector of ints
    vector<int> entered_nums;

    for (int i = 0; i < entered_str.size(); ++i) {
        entered_nums.push_back(entered_str[i] - '0');  // The digits will be in the same order as before
    }

    cout << "entered vector: " << entered_nums[0] << ' '<< entered_nums[1] << ' '<< entered_nums[2] << ' '<< entered_nums[3] << '\n';

    //*************************************************************
    // compare input
    int cows = 0;
    int bulls = 0;
    cout << "loop vector" << '\n';
    for (int i = 0; i < random_nums.size(); i++) {
        for (int k = 0; k < entered_nums.size(); k++) {
            if (entered_nums[k] == random_nums[i] && k == i) {
                bulls++;
            } else if (entered_nums[k] == random_nums[i]) {
                cows++;
            }
        }
    }

    // output result
    cout << "The result is:\nBulls: " << bulls << " Cows: " << cows << '\n';

    return 0;
}