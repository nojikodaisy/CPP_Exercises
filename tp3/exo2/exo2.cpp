#include <iostream>
#include <vector>

// Return the number of occurrences of 'a' found in string 's'.
int count_a_occurrences(const std::string& s);

/* Ajoute const et une & car on ne le modifie pas? */

// Update function of a rendering program.
// - dt (delta time) is read by the function to know the time elapsed since the last frame.
// - errors is a string filled by the function to indicate what errors have occured.
void update_loop(const float& dt, std::string& errors_out);

/* Autant juste mettre float car plus couteux de faire constante d'un float que juste une copie */


// Return whether all numbers in 'values' are positive.
// If there are negative values in it, fill the array 'negative_indices_out' with the indices
// of these values and set its size in 'negative_count_out'.
// ex: auto res = are_all_positive({ 1, -2, 3, -4 }, negative_indices, negative_count);
//    -> res is false, since not all values are positive
//    -> negative_indices contains { 1, 3 } because values[1] = -2 and values[3] = -4
//    -> negative_count is 2
bool are_all_positives(const std::vector<int> values, int negative_indices_out[], size_t& negative_count_out);

/* 
Ajoute const et & au vector car on ne le modifie pas ? 
Mettre std::vector<int>& pour le negative_indices_out[] car c'est pour le C les array comme ça
Et comme le vector connait sa taille on supprime le size.
*/


// Concatenate 'str1' and 'str2' and return the result.
// The input parameters are not modified by the function.
std::string concatenate(char* str1, char* str2);

/*
Comme en C les char* donc on met const std::string& pour les deux
*/


/* 
On met juste int en paramètre car faire des copie de int est moins couteux que mettre des constantes dans la mémoire.
*/
int add(int a, int b)
{
    return a + b;
}

void add_to(int& a, int b)
{
    a += b;
}

int main()
{
    int x = 10;
    int y = add(x, x);
    add_to(y, 22);
    std::cout << x << " " << y << std::endl;
    return 0;
}