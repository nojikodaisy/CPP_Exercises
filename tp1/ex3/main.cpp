#include "utils.hpp"

int main()
{
    print_hello();
    print_bye();
    return 0;
}


/**
 * Q2 : 
 * Préprocessing : regarde tous les #include et récupère le contenu de chaque
 * 
 * Compilation : créer l'arbre syntaxique (avec table de symbole) + code avec des trous (les fonctions pas encore recup)
 * 
 * Edition de liens : remplir les trous en faisant les liens 
 * 
 * 
 * inline : définir la fonction dans le header.
 * 
 * 
 * Q3 :
 * 
 * `error: 'qqchose' was not declared in this scope`
 * se produit lorsque 'qqchose' n'a pas été déclaré donc c'est 
 * pendant la phase de compilation
 * 
 * `error: 'qqchose' is not a member of 'std'` 
 * se produit lorsque l'élément n'existe pas dans cette classe, on a raté nos include
 * pendant la phase de compilation
 * 
 * Q4 :
 * 
 * On a oublié de link avec l'autre module donc la référence est indéfinie car elle est dans l'autre module.
 * 
 * Q5 :
 * Comme les deux include utils.hpp et que dans ce fichier la fonction est définie, 
 * il est donc compilé à deux endroit dans le main et dans le utils donc il y a une erreur
 * car défini plusieurs fois.
 * Pour la résoudre, on peut mettre inline.
 * 
 * 
 * 
 */