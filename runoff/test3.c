#include <cs50.h>
#include <string.h>
#include <stdio.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(void);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie();

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
    // Check if name is valid
    // Iterate over each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Check if candidate has been eliminated
        if (candidates[i].eliminated == false)
        {
        // Check if candidate's name matches given name
            if (strcmp(name, candidates[i].name) == 0)
            {
            // Query for each rank
                for (int j = 0; j < candidate_count; j++)
                {
                    preferences[voter][rank] = i;
                    return true;
                }
            }
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // calculate the number of votes for each candidate for each rank
    for (int i = 0; i < voter_count; i++)
        {
            int first_choice_candidate = preferences[i][0];
            if (!candidates[first_choice_candidate].eliminated)
            {
                candidates[first_choice_candidate].votes ++;
            }
            else
            {
                for (int j = 1; j < candidate_count; j++)
                    {
                        int next_preference = preferences[i][j];
                        if (!candidates[next_preference].eliminated)
                        {
                            candidates[next_preference].votes ++;
                            break;
                        }
                    }
            }

        }
        return;
}
// Print the winner of the election, if there is one
bool print_winner(void)
{
    // Find the maximum number of votes // Iterate over each candidate
    int highest_number_votes = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > highest_number_votes)
        {
            highest_number_votes = candidates[i].votes;
        }
    }
    int total_votes = 0;
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            {
                total_votes += candidates[i].votes;
                break;
            }
        }
    }
    // Print the candidate (or candidates) with maximum votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == highest_number_votes)
        {
            if (highest_number_votes >= total_votes*2)
            {
                printf("%s\n", candidates[i].name);
                return true;
            }
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min = candidates[0].votes;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes < min)
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(void)
{
    for (int i = 0; i < candidate_count - 1; i++)
    {
        if (candidates[i].votes != candidates[i + 1].votes)
        {
            return false;
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (min == candidates[i].votes)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
