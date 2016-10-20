#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct gato {
	char tablero[3][3];
	char player1;
	char player2;
	char cpu;
};
 
void inicializa_tablero (char tablero[3][3]) {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			tablero[i][j] = '.';
		}
	}
}

void imprime_tablero(char tablero[3][3]) {

	for (int i = 0; i < 3; i++) {
		cout << endl;
		for (int j = 0; j < 3; j++) {
			cout << "  ";
			cout << tablero[i][j];
		}
	}
	cout << endl << endl;
}

char checa_ganador(char tablero[3][3]) {
	
	if (tablero[0][0] != '.' && (tablero[0][0] == tablero[0][1] && tablero[0][0] == tablero[0][2] ||
		tablero[0][0] == tablero[1][0] && tablero[0][0] == tablero[2][0] ||
		tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2])) 
	
		return tablero[0][0];
	
	if (tablero[1][1] != '.' && (tablero[1][1] == tablero[1][0] && tablero[1][1] == tablero[1][2] ||
		tablero[1][1] == tablero[0][1] && tablero[1][1] == tablero[2][1] ||
		tablero[1][1] == tablero[2][0] && tablero[1][1] == tablero[0][2])) 
	
		return tablero[1][1];
	
	if (tablero[2][2] != '.' && (tablero[2][2] == tablero[0][2] &&tablero[2][2] == tablero[1][2] ||
		tablero[2][2] == tablero[2][0] && tablero[2][2] == tablero[2][1]))
	
		return tablero[2][2];
	
	return 0;
}

int negamax(char tablero[3][3], char player1, char player2);

int pick_best_move(char tablero[3][3], char player1, char player2) {

	int best_move_score = -9999;
	int best_move_row = -9999;
	int best_move_col = -9999;
	int score_for_this_move = 0;

	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			if (tablero[r][c] == '.') {
				tablero[r][c] = player1; 
				score_for_this_move = -(negamax(tablero, player2, player1));
				tablero[r][c] = '.'; 
				if (score_for_this_move >= best_move_score) {
					best_move_score = score_for_this_move;
					best_move_row = r;
					best_move_col = c;
				} 
			}
		}
	}
	return (10*best_move_row + best_move_col);
}

int negamax(char tablero[3][3], char player1, char player2) {

	int best_move_score = -9999;
	int score_for_this_move = 0;
	
	if (checa_ganador(tablero) == player1)
		return 1000;

	else if (checa_ganador(tablero) == player2)
		return -1000;

	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			if (tablero[r][c] == '.') {
				tablero[r][c] = player1; 
				score_for_this_move = -(negamax(tablero, player2, player1));
				tablero[r][c] = '.';
				if (score_for_this_move >= best_move_score) {
					best_move_score = score_for_this_move;
				}
			}
		}
	}
	
	if (best_move_score == -9999 || best_move_score == 0)
		return 0;
	
	else if (best_move_score < 0)
		return best_move_score + 1;

	else if (best_move_score > 0)
		return best_move_score - 1; 
}

void player_placement(char tablero[3][3], char player) {
	
	while (1) {
		string string_row, string_col;
		int row = 0, col = 0;
		while (1) {
			cout << "Introduzca la fila:";
			cin >> string_row;
			row = atoi(string_row.c_str());

			if (row >= 1 && row <= 3)
				break;
			cout << "Solo puede elegir entre 1 y 3" << endl;
		}

		while (1) {
			cout << "Introduzca la columna:";
			cin >> string_col;
			col = atoi(string_col.c_str());

			if (col >= 1 && col <= 3)
				break;
			cout << "Solo puede elegir entre 1 y 3" << endl;	
		}
		if (tablero[row-1][col-1] == '.') {
			tablero[row-1][col-1] = player;
			break;
		}
		else
			cout << "Ese lugar ya esta ocupado, elija otro" << endl << endl;
	}
}

char determine_cpu_choice (char player1) {

	char cpu_char;
	
	if (player1 == 'x' || player1 == 'X') 
		cpu_char = 'o';

	else 
		cpu_char = 'x';

	return cpu_char;
}

char determine_player_choice (string s) {	
	
	while (1) {
		string choice;
		cout <<  " Elija su ficha ";
		cin >> choice;
		if (choice.size() > 1) {
			cout << "Solo puede ser un caracter, por favor intentelo de nuevo" << endl;
			continue;
		}
		cout << endl;
		return choice[0];
	}
}

void play_game_1_player (char tablero[3][3], char player1, char cpu) {
	
	int moves = 0;
	while (moves < 9) {
		player_placement(tablero, player1);
		moves++;
		imprime_tablero(tablero);
		if (checa_ganador(tablero)) {
			cout << player1 << " Ganaste!" <<endl;
			exit(1);
		}
		if (moves == 9)
			break;
		int where_to_move = pick_best_move(tablero, cpu, player1);
		int row = where_to_move / 10;
		int col = where_to_move % 10;
		tablero[row][col] = cpu;
		moves++;
		imprime_tablero(tablero);
		if (checa_ganador(tablero)) {
			cout << cpu << " Ganaste!" <<endl;
			cout << "If I were you, I would've played at: " << "(row " << where_to_move/10 + 1 << ", col " << where_to_move % 10 + 1 << ")" << endl;
			exit(2);
		}
	}
	cout << "Empate!" << endl;
}

void play_game_2_player (char tablero[3][3], char player1, char player2) {
	
	for (int move_num = 0; move_num < 9; ++move_num) {
		player_placement(tablero,(move_num & 1) ? player1 : player2);
		imprime_tablero(tablero);
		char winner = checa_ganador(tablero);
		if (winner) {
			cout << winner << " won!" << endl;
			exit(0);
		}
	}
	cout << "Cat's game!" << endl;
}

bool question_two_player() {
	
	while (1) {
		while (1) {
			string choice;
			int players = 0;
			cout << "Presiona 1 para empezar el juego ";
			cin >> choice;
			cout << endl;
			players = atoi(choice.c_str());
			if (players != 1 && players != 2) {
				cout << "Please enter either a 1 or a 2." << endl << endl;
			}
			else if (players == 1)
				return false;
			break;
		}
	}
}

int main() {
	
	gato game;
	inicializa_tablero(game.tablero);

	bool two_player = question_two_player();

	if (two_player == false) {
		game.player1 = determine_player_choice("Player 1");
		game.cpu = determine_cpu_choice(game.player1);
		imprime_tablero(game.tablero);
		play_game_1_player(game.tablero, game.player1, game.cpu);
	}
	
	return 0;
}
