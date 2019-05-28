# Blackjack Game - Player Vs. Dealer

This is a simple command-line implementation of the classic casino game Blackjack, written in C. The game allows a player to play against the dealer.


<img width="400px" height="250px" src="https://user-images.githubusercontent.com/27955793/244960710-cd07d349-c926-4d80-b5dc-e86cdd7ee735.png">
## How to Play

1. The game begins by dealing two cards to the player and two cards to the dealer. The player's cards are visible, while only one of the dealer's cards is visible.

2. The player can choose to "hit" (receive another card) or "stand" (stop receiving cards). The goal is to get as close to 21 as possible without going over.

3. The player can continue to hit until they either decide to stand or exceed 21 (bust). If the player busts, the game is over, and the dealer wins.

4. After the player stands, the dealer reveals their second card. The dealer must hit until their hand value reaches 17 or higher. If the dealer busts, the player wins.

5. Once the dealer stands, the hands are compared, and the player with a higher hand value (but not exceeding 21) wins. If both the player and dealer have the same hand value, it's a tie (push).

6. The player can choose to play again or quit the game.

## How to Run

To run the game, follow these steps:

1. Compile the source code using a C compiler. For example, using GCC:

   ```bash
   gcc blackjack.c -o blackjack
   ```

2. Execute the compiled binary:

   ```bash
   ./blackjack
   ```

## Game Features

- **Player Input Validation**: The game validates user input to ensure only valid choices are accepted (e.g., hitting or standing).

- **Score Tracking**: The game keeps track of the player's and dealer's scores, updating them after each round.

- **Multiple Rounds**: The player can play multiple rounds until they decide to quit.

- **Randomized Card Deck**: The game uses a random number generator to simulate shuffling and dealing of cards.

## Code Structure

The code for this game is structured as follows:

- `blackjack.c`: Contains the main game logic, including functions for initializing the game, dealing cards, calculating hand values, and determining the winner.

## Dependencies

This game is written in C and does not have any external dependencies. It should work on any system with a C compiler.
