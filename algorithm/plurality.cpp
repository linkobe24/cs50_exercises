#include <iostream>
#include <string>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct candidate
{
    std::string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(std::string name);
void print_winner(void);

int main(int argc, std::string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = 0;
    std::cout << "Number of voters: ";
    std::cin >> voter_count;

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        std::string name;
        std::cout << "Name: ";
        std::cin >> name;

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(std::string name)
{
    // TODO
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    return;
}
