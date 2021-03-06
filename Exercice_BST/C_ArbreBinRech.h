#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cassert>


using namespace std;

typedef struct s_noeud {

	int n_donnee;
	struct s_noeud* fgauche;
	struct s_noeud* fdroite;

}s_noeud;

typedef struct s_arbre_bin {

	s_noeud* racine;

}s_arbre_bin;

class C_ArbreBinRech {

public :

	C_ArbreBinRech();
	~C_ArbreBinRech();
	
	void init(s_arbre_bin* pArbre);

	//Parcours de l'Arbre Binnaire
	//le noeud racine est trait? en premier, suivi de tous les noeuds du sous-arbre G, puis ceux du sous-arbre D
	void parcPrefixe(s_noeud* racine);
	//les noeuds du sous-arbre G sont trait? en premier, suivis de ceux du sous-arbre D, puis le noeud racine
	void parcPostfixe(s_noeud* racine);
	void traiter(s_noeud* n);

	//Instanciation d'un arbre binaire de recherches
	int inserArbreVide(s_arbre_bin* pArbre, int n_val);

	//Remplir l'arbre avec d'autres noeuds
	int ajoutNoeuds(s_arbre_bin* pArbre, int n_val);


	//Recherchcer
	s_noeud* recherche(s_arbre_bin* pArbre, int n_val);
	s_noeud** rechercheNoeud(s_noeud*& n, int n_val)const;
	//s_noeud* rechercheNoeud(s_noeud*& n, int n_val)const;

	//Supprimer des noeuds
	//int suppNoeud(s_arbre_bin* pArbre, int n_val); //V1
	s_noeud* suppNoeud(s_arbre_bin* pArbre, s_noeud* courant, int n_val);//V2
	void suppNoeudArbre(s_arbre_bin* pArbre, int n_val);
	s_noeud* plusGrand(s_noeud* elem);


	//Hauteur max de l'arbre
	int HautMaxArbre(s_noeud* n);


	//nombre de noeud total de l'arbre
	int TailleArbre(s_noeud* n);


	//Rotation simple
	s_noeud* rotation_droite(s_noeud* y);
	s_noeud* rotation_gauche(s_noeud* x);
	bool est_ce_ok(s_noeud *n);
	s_noeud* equilibrage(s_noeud* n_val);

	//Lib?rer
	void liberer(s_noeud** pRacine);
	
private :
	//s_noeud* racine;
	size_t taille;

};