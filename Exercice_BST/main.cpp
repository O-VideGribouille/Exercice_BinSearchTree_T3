#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cassert>

#include "C_ArbreBinRech.h"

using namespace std;


int main() {

	C_ArbreBinRech abr;

	s_arbre_bin* pArbre = nullptr;
	pArbre = (s_arbre_bin*)malloc(sizeof(s_arbre_bin));
	abr.init(pArbre);

	cout << "Creation d'un arbre binaire de recherche " << endl;
	//Instanciation d'un arbre binaire de recherches
	abr.inserArbreVide(pArbre, 11);

	cout << "Ajout de noeuds ... " << endl;
	abr.ajoutNoeuds(pArbre, 20);
	abr.ajoutNoeuds(pArbre, 15);
	abr.ajoutNoeuds(pArbre, 5);
	abr.ajoutNoeuds(pArbre, 4);
	abr.ajoutNoeuds(pArbre, 3);
	abr.ajoutNoeuds(pArbre, 23);

	cout << endl;
	cout << "Parcours Prefixe : " << endl;
	abr.parcPrefixe(pArbre->racine);
	cout << endl;
	cout << endl;

	cout << "Parcours Postfixe : " << endl;
	abr.parcPostfixe(pArbre->racine);
	cout << endl;
	cout << endl;


	cout << "L'abre a une hauteur de : " << abr.HautMaxArbre(pArbre->racine) << " rangs.";
	cout << endl;
	cout << "L'abre a une taille de : " << abr.TailleArbre(pArbre->racine) << " noeuds.";
	cout << endl;
	cout << endl;
	cout << endl;


	cout << "Ajout de deux nouveaux noeuds : 9 et 2 " << endl;
	abr.ajoutNoeuds(pArbre, 9);
	abr.ajoutNoeuds(pArbre, 2);
	cout << endl;

	cout << "Parcours Postfixe : " << endl;
	abr.parcPostfixe(pArbre->racine);
	cout << endl;
	cout << endl;
	cout << "L'abre a une hauteur de : " << abr.HautMaxArbre(pArbre->racine) << " rangs.";
	cout << endl;
	cout << "L'abre a une taille de : " << abr.TailleArbre(pArbre->racine) << " noeuds.";
	cout << endl;
	cout << endl;
	cout << endl;


	cout << "Suppression de quatre noeuds : 3, 4, 20 et 23 " << endl;
	abr.suppNoeudArbre(pArbre, 3);
	abr.suppNoeudArbre(pArbre, 23);
	cout << endl;

	cout << "Parcours Postfixe : " << endl;
	abr.parcPostfixe(pArbre->racine);
	cout << endl;
	cout << endl;
	cout << "L'abre a une hauteur de : " << abr.HautMaxArbre(pArbre->racine) << " rangs.";
	cout << endl;
	cout << "L'abre a une taille de : " << abr.TailleArbre(pArbre->racine) << " noeuds.";
	cout << endl;
	cout << endl;




	if (pArbre != nullptr) {
		abr.liberer(&pArbre->racine);
	}

	free(pArbre);

	return 0;
};