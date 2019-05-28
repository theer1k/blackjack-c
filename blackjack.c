#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_SUITS 4
#define NUM_RANKS 13
#define NUM_PLAYERS 2
#define DECK_SIZE 52

typedef struct {
    int suit;
    int rank;
} Card;

typedef struct {
    Card* cards[NUM_CARDS];
    int top;
} Deck;

typedef struct {
    Card* hand[NUM_CARDS];
    int num_cards;
} Player;

Deck* deck;
Player players[NUM_PLAYERS];

void init_deck() {
    deck = malloc(sizeof(Deck));
    deck->top = 0;
    for (int s = 0; s < NUM_SUITS; s++) {
        for (int r = 0; r < NUM_RANKS; r++) {
            Card* card = malloc(sizeof(Card));
            card->suit = s;
            card->rank = r;
            deck->cards[deck->top++] = card;
        }
    }
}

void shuffle_deck() {
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; i++) {
        int swap_index = rand() % NUM_CARDS;
        Card* tmp = deck->cards[i];
        deck->cards[i] = deck->cards[swap_index];
        deck->cards[swap_index] = tmp;
    }
}

Card* draw_card() {
    return deck->cards[--deck->top];
}

void init_players() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i].num_cards = 0;
    }
}

void draw_to_player(int player_num) {
    players[player_num].hand[players[player_num].num_cards++] = draw_card();
}

int score_player(int player_num) {
    int score = 0;
    int ace_count = 0;
    for (int i = 0; i < players[player_num].num_cards; i++) {
        int rank = players[player_num].hand[i]->rank;
        if (rank == 0) ace_count++; // if card is an Ace
        score += (rank < 9 ? rank + 1 : 10); // face cards are worth 10
    }
    while (ace_count > 0 && score <= 11) {
        score += 10;
        ace_count--;
    }
    return score;
}

int main() {
    char input[10];
    do {
        // Initialize deck
        init_deck();
        shuffle_deck();

        // Initialize players
        init_players();
        draw_to_player(0);
        draw_to_player(1);
        draw_to_player(0);
        draw_to_player(1);

        // Player's turn
        do {
            printf("Player's score: %d. Do you want another card? (y/n) ", score_player(0));
            scanf("%s", input);
            if(input[0] == 'y') {
                draw_to_player(0);
            }
        } while(input[0] == 'y' && score_player(0) < 21);

        // Dealer's turn
        while(score_player(1) < 17) {
            draw_to_player(1);
        }

        // Determine winner
        int playerScore = score_player(0);
        int dealerScore = score_player(1);

        printf("Dealer's score: %d\n", dealerScore);
        printf("Player's score: %d\n", playerScore);

        if(playerScore > 21) {
            printf("Dealer wins!\n");
        } else if(dealerScore > 21) {
            printf("Player wins!\n");
        } else if(playerScore > dealerScore) {
            printf("Player wins!\n");
        } else {
            printf("Dealer wins!\n");
        }

        printf("Play again? (y/n) ");
        scanf("%s", input);
    } while(input[0] == 'y');

    return 0;
}
