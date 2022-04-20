#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
int test_cycle(int start, int end);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
            //Checks the validity of the vote
        {
            ranks[rank] = i; //updates the ranks array at the index passed into the function to the candidate the vote is placed on
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++; //Updates the 2d array at index [i][j] so that each instance of a candidate being preferred to another is recorded in the matrix
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
        //Nested loop that goes through the instances of a candidate winning and records the victories and losses in and array pairs
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            int prefij = preferences[i][j];
            int prefji = preferences[j][i];

            if (prefij > prefji)
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (prefij < prefji)
            {
                pairs[pair_count].loser = i;
                pairs[pair_count].winner = j;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = (pair_count - 1); i >= 0; i--)
        //Loop from hight to low as the search method will be a bubble sort that needs to sort into descending order
    {
        for (int j = 0 ; j < i; j++)
        {
            int first_winner = pairs[j].winner;
            int first_loser = pairs[j].loser;
            int second_winner = pairs[j + 1].winner;
            int second_loser = pairs[j + 1].loser;

            int first_pair = preferences[first_winner][first_loser];
            int second_pair = preferences[second_winner][second_loser];

            if (first_pair < second_pair)
            {
                pair extra = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = extra;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    //Cycles through the paids and if the test_cycle function says that it is a cycle then locks the paid
    for (int i = 0; i < pair_count; i++)
    {
        if (test_cycle(pairs[i].winner, pairs[i].loser) == 0)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    //for every candidate, if they have no arrows pointing at them then they are a winner
    for (int i = 0; i < candidate_count; i++)
    {
        int number_false = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            number_false++;

            if (number_false == candidate_count)
            {
                printf("%s\n", candidates[i]);
            }
        }
    }
    return;
}

//Recursive function that tests if there is a cycles by checking if the candidate has an arrow coming in to them
int test_cycle(int start, int end)
{
    if (start == end)
    {
        return 1;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[end][i])
        {
            if (test_cycle(start, i) == 1)
            {
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
